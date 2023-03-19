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

	friend ostream& operator<<(ostream& out, const Vector& vect)
	{
		for (auto i : vect._vect)
			out << " " << i ;
		return out;
	}

	operator Matrix<K>() {

		



		Matrix<K> coucou({{1, 2, 3, 4}, {5, 6, 7, 8}});
		return coucou;
	}

};

