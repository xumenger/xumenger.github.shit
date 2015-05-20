#include<iostream>
using namespace std;
class TradesPerson{
	public:
		virtual void sayHi(){
			cout<<"Just Hi."<<endl;
		}
};
class Tinker : public TradesPerson{
	public:
		virtual void sayHi(){
			cout<<"Hi, I Tinker."<<endl;
		}
};
class Tailor : public TradesPerson{
	public:
		virtual void sayHi(){
			cout<<"Hi, I Tailor."<<endl;
		}
};

int main(){
	TradesPerson* p;
	int which;
	do{
		cout<<"1 == TradesPerson, 2 == Tinker, 3 == Tailor\n";
		cin>>which;
	}while(which<1 || which>3);
	switch(which){
		case 1:
			p = new TradesPerson;
			break;
		case 2:
			p = new Tinker;
			break;
		case 3:
			p = new Tailor;
			break;
	}
	p->sayHi();
	delete p;
	return 0;
}
