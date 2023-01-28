#include <iostream>

using namespace std;

namespace structs {

    struct Vector {
    	int m_size;
    	double* m_elements;
    };
    
    void vector_init(Vector& v, int s) {
    	v.m_elements = new double[s];
    	v.m_size = s;
    }
    
    double read_and_sum(int s) {
    	Vector v;
    	vector_init(v,s);
    
    	for (int i = 0; i != s; ++i)
    		cin >> v.m_elements[i];
    
    	double sum = 0;
    	for (int i = 0; i != s; ++i)
    		sum += v.m_elements[i];
    	return sum;
    }
}

class Vector {
	public:
		Vector(int s) : m_elem{new double[s]}, m_sz{s} {}
	   	double& operator[](int i) {return m_elem[i];}
		int size() {return m_sz;}	

	private:
		double* m_elem;
		int m_sz;

};

union Value {
	void* p;
	int i;
};

struct Entry {
	string name;
	int t;
	Value v;
};

// Little Endian
// int x = 1;
// 
// Higher addresses
// ----->
// | 0x01 | 0x00 | 0x00 | 0x00 |
//
// Big Endian
// int x = 1;
//
// Higher adresses
// | 0x00 | 0x00 | 0x00 | 0x01 | 
union Endianess {
	int i;
	char bytes[4];
};

int main() {

	//	double s{read_and_sum(5)};
	//	cout << s << "\n";
	
	Entry e;
	e.v.i = 10;

	Endianess en;
	en.i = 1;

	if (en.bytes[3])
		cout << "Big Endian\n";
	else
		cout << "Little Endian\n";

	return 0;
}
