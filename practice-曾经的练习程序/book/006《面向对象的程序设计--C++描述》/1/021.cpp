#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class intTwoArray{
	public:
		int& operator()(int, int);
		const int& operator()(int, int)const;
		intTwoArray(int, int);
		int get_size1()const{
			return size1;
		}
		int get_size2()const{
			return size2;
		}
	private:
		int size1;
		int size2;
		int* a;
};
int& intTwoArray::operator()(int i, int j){
	if(i<0 || i>=size1)
		throw string("FirstOutOfBounds");
	if(j<0 || j>=size2)
		throw string("SecondOutOfBounds");
	return a[i*size2 + j];
}
const int& intTwoArray::operator()(int i, int j)const{
	if(i<0 || i>=size1)
		throw string("FirstOutOfBounds");
	if(j<0 || j>=size2)
		throw string("SecondOutOfBounds");
	return a[i*size2 + j];
}
intTwoArray::intTwoArray(int s1, int s2){
	int size = s1*s2;
	try{
		a = new int[size];
	}catch(bad_alloc){
		cerr<<"Can't allocate storage for intTwoArray\n";
		throw;
	}
	size1 = s1;
	size2 = s2;
}

int main(){
	intTwoArray b(3, 4);
	int i, j;
	for(i=0; i<b.get_size1(); i++)
		for(j=0; j<b.get_size2(); j++)
			b(i, j) = 2*i+j;
	for(i=0; i<b.get_size1(); i++){
		for(j=0; j<b.get_size2(); j++)
			cout<<setw(2)<<b(i, j);
		cout<<endl;
	}
	try{
		cout<<b(4 ,2)<<endl;
		cout<<b(2, 8)<<endl;
	}
	catch(string s){
		cerr<< s <<endl;
	}
	return 0;
}
