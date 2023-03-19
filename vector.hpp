#pragma once

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;

template <typename K>
class Vector {

	public:

	vector<K> _vect;

	Vector<K>(){};

	Vector<K>(vector<K> other){
		_vect = other;
	}

	~Vector<K>(){}

	Vector<K>& operator=(Vector<K> &other) {
		_vect = other._vect;
	}

	size_t getSize(){
		return _vect.size();
	}

	friend ostream& operator<<(ostream& out, const Vector& vect){
		for (auto i : vect._vect)
			out << " " << i ;
		return out;
	}

	operator Matrix<K>() {
		Matrix<K> coucou({this->_vect});
		return coucou;
	}

	Vector<K>& operator +=(Vector<K> &rhs){
		if (_vect.size() != rhs._vect.size())
			throw std::invalid_argument( "adding two vectors of different size" );
		for (unsigned int i = 0; i < rhs._vect.size(); ++i)
		{
			_vect[i] += rhs._vect[i];
		}		
		return *this;
	}

	Vector<K>& operator -=(Vector<K> &rhs){
		if (_vect.size() != rhs._vect.size())
			throw std::invalid_argument( "substracting two vectors of different size" );
		for (unsigned int i = 0; i < rhs._vect.size(); ++i)
		{
			_vect[i] -= rhs._vect[i];
		}
		return *this;
	}

	Vector<K>& operator *=(K scalar){
		for (unsigned int i = 0; i < rhs._vect.size(); ++i)
		{
			_vect[i] *= scalar;
		}
		return *this;
	}
};

template <typename K>
Vector<K> operator+(Vector<K> &lhs, Vector<K> &rhs){
	if (lhs._vect.size() != rhs._vect.size())
		throw std::invalid_argument( "adding two vectors of different size" );
	Vector<K> res;
	size_t count = lhs._vect.size();
	for (size_t i = 0; i < count; ++i)
		res._vect.push_back(lhs._vect[i] + rhs._vect[i]);
	return res;
}
template <typename K>
Vector<K> operator-(Vector<K> &lhs, Vector<K> &rhs){
	if (lhs._vect.size() != rhs._vect.size())
		throw std::invalid_argument( "substracting two vectors of different size" );
	Vector<K> res;
	size_t count = lhs._vect.size();
	for (size_t i = 0; i < count; ++i)
		res._vect.push_back(lhs._vect[i] - rhs._vect[i]);
	return res;
}
template <typename K>
Vector<K> operator*(Vector<K> &lhs, K scalar){
	Vector<K> res;
	for (auto i : lhs._vect)
	{
		res._vect.push_back(i * scalar);
	}
	return res;
}
