#include "../vector.hpp"
#include "../matrix.hpp"

using namespace std;

int main() {

	Matrix<double> uno({{1, 2, 3, 4}, {1, 2, 3, 4}, {1, 2, 3, 4}});
	cout << uno << endl;

	Vector<double> tmp({1, 2, 3});

	Matrix<double> bloup = tmp;

	cout << bloup << endl;

	// Vector<double> doss({1, 2, 3, 4});
	// cout << doss << endl;




}