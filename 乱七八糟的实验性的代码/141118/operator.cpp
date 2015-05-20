class Complex{
	public:
		Complex();
		Complex(double);
		Complex(double, double);

		void write()const;
		Complex operator+(const Complex&)const;
		Complex operator-(const Complex&)const;
		Complex operator*(const Complex&)const;
		Complex operator/(const Complex&)const;

	private:
		double real;
		double imag;
};

Complex::Complex(){
	real = imag = 0.0;
}
Complex::Complex(double re){
	real = re;
	imag = 0.0;
}
Complex::Complex(double re, double im){
	real = re;
	imag = im;
}
void Complex::write()const{
	cout<<real<<"+"<<imag<<'i'<<endl;
}

Complex Complex::operator+(const Complex& u)const{
	Complex v(real+u.real, imag+u.imag);
	return v;
}
Complex Complex::operator-(const Complex& u)const{
	Complex v(real-u.real, imag-u.imag);
	return v;
}
Complex Complex::operator*(const Complex& u)const{
	Complex v(real*u.real-imag*u.imag, imag*u.real+real*u.imag);
	return v;
}
Complex Complex::operator/(const Complex& u)const{
	double ads_sq = u.real*u.real+u.imag*u.imag;
	Complex((real*u.real+imag*u.imag)/abs_sq, (imag*u.real-real*u.imag)/abs_sq);
	return v;
}
