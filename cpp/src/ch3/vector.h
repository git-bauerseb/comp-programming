class Vector {
	public:
		Vector(int s);
		double& operator[](int i);
		int size();

	private:
		double* m_elem;
		int m_size;
};
