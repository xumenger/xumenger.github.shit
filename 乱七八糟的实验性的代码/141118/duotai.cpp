#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
class TradesPerson{
	public:
		virtual void sayHi(){
			cout<< "Just Hi" <<endl;
		}
};
class Tinker : public TradesPerson{
	public:
		virtual void sayHi(){
			cout<< "Hi, I Tinker!" <<endl;
		}
};
class Tailor : public TradesPerson{
	public:
		virtual void sayHi(){
			cout<< "Hi, I Tailor!" <<endl;
		}
};
int main(){
	srand(time(0));
	TradesPerson* ptrs[10];
	unsigned which, i;
	for(i=0; i<10; i++){
		which = 1 + rand()%3;
		switch(which){
			case 1:
				ptrs[i] = new TradesPerson;
				break;
			case 2:
				ptrs[i] = new Tinker;
				break;
			case 3:
				ptrs[i] = new Tailor;
				break;
		}
	}
	for(i=0; i<10; i++){
		ptrs[i]->sayHi();
		delete ptrs[i];
	}
	return 0;
}
