#include<iostream>
using namespace std;
class A{
	public:
		virtual void m(double d){
			cout<< d <<endl;
		}
};
class Z : public A{
	public:
		virtual void m(){
			cout<<"foo"<<endl;
		}
};

int main(){
	Z* p = new Z;
	p->m();
	p->m(3.14);
	return 0;
}
