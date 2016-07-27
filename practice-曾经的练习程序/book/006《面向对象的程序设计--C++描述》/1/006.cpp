#include<iostream>
using namespace std;
class C{
	public:
		void set(int n){
			num = n;
		}
		int get(){
			return num;
		}
	private:
		int num;
};
void f(C&);
C& g();

int main(){
	C c1, c2;
	f(c1);
	c2 = g();
	cout<<c2.get()<<endl;
	return 0;
}

void f(C& c){
	c.set(999);
	cout<<c.get()<<endl;
}
C& g(){
	static C c3;
	c3.set(123);
	return c3;
}
