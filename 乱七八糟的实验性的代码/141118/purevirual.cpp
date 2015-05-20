#include<iostream>
using namespace std;
class A{
	public:
		A(){
			cout<<endl<<"A() firing"<<endl;
			p = new char[5];
		}
	   	virtual ~A(){
			cout<<"~A() firing"<<endl;
			delete[] p;
		}
	private:
		char *p;
};
class Z : public A{
	public:
		Z(){
			cout<<"Z() firing"<<endl;
			q = new char[5000];
		}
		~Z(){
			cout<<"~Z() firing"<<endl;
			delete[] q;
		}
	private:
		char* q;
};
void f();
int main(){
	for(unsigned i=0; i<3; i++)
		f();
	return 0;
}
void f(){
	A* ptr;
	ptr = new Z();
	delete ptr;
}
