#include<iostream>
using namespace std;

class car0{
	public: 
		int carname;
		void setnum();
		void printnum();
	protected:
		int carno;
	private:
		int carnum;
};
void car0::setnum(){
	carnum = 77;
}
void car0::printnum(){
	cout<<carnum<<endl;
}

class car1 : public car0{
	public:
		void set();
		void print();
};
void car1::set(){
	carname = 0;
	carno = 0;
	//carnum = 0;
}
void car1::print(){
	cout<<carname<<' '<<carno<<' '<</*carnum<<*/endl;
}

int main(){
	car0 c0;
	car1 c1;
	c1.set();
	c1.print();

	c1.setnum();
	c1.printnum();

	return 0;
}
