#include <iostream>
#include <stdexcept>
#include "vector.h"

using namespace std;

Vector::Vector(int s) {
	if (s < 0) {
		throw std::length_error{"Vector construction: negative size"};
	}
	
	m_elem = new double[s];
	m_size = s;
}


double& Vector::operator[](int i) {return m_elem[i];}
int Vector::size() {return m_size;}

double read_and_sum(int s) {
	Vector v{s};

	for (int i = 0; i != s; ++i)
		cin >> v[i];

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v[i];

	return sum;
}

int main() {
	//	cout << read_and_sum(7) << "\n";
	
	try {
		Vector v(-10);
	} catch (std::length_error& ex) {
		std::cout << ex.what() << "\n";
	}


	return 0;
}
