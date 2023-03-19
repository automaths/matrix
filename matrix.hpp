#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename K>
class Vector;

template <typename K>
class Matrix {

	public:

	vector<K> _matrix;
	size_t _rows;
	size_t _cols;

	Matrix<K>(vector<vector<K> > other){

		unsigned int tmp = other[0].size();
		for (unsigned int i = 0; i < other.size(); ++i)
		{
			if (tmp != other[i].size())
				throw std::invalid_argument( "wrong matrix format" );
			tmp = other[i].size();
			_matrix.insert(_matrix.end(), other[i].begin(), other[i].end());
		}
		_rows = other.size();
		_cols = other[0].size();

	}

	~Matrix<K>(){}

	Matrix<K>& operator=(Matrix<K> &other) {
		
		_rows = other.getRows();
		_cols = other.getCols();
		_matrix = other._matrix();

	}

	size_t getCols(){
		return _cols;
	}

	size_t getRows(){
		return _rows;
	}

	bool isSquare(){
		if (_rows == _cols)
			return true;
		return false;
	}

	friend ostream& operator<<(ostream& out, const Matrix& matrix)
	{
		for (unsigned int i = 0; i < matrix._rows; ++i)
		{
			for (unsigned int j = 0; j < matrix._cols; ++j)
			{
				out << " " << matrix._matrix[i * matrix._cols + j] << " ";
			}
			out << std::endl;
		}
		return out;
	}

	operator Vector<K>() {
		if (this->_rows > 1)
			throw std::invalid_argument( "can't convert matrix with more than one row" );
		Vector<K> coucou(this->_matrix);
		return coucou;
	}



};

