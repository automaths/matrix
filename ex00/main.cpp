#include "../vector.hpp"

using namespace std;

int main() {

	Vector<double> one({1, 2, 3, 4, 5});
	Vector<double> two({0, 1, 2, 3, 4});

	// Vector<double> three = one + two;

	two += one;

	cout << two << endl;

	Vector<double> four = two - one;

	cout << four << endl;

	Vector<double> five = four * 2.0;

	cout << five << endl;

}