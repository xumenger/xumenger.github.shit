#include<iostream>
using namespace std;

class A{
	public:
		virtual void test() = 0;
};
class B : public A{
	public:
		virtual void test(){
			cout<<"success!!!!!!!!!!!!!!!!!"<<endl;
		}
};

int main(){
	A* a;
	a = new B();
	a->test();

	return 0;
}
