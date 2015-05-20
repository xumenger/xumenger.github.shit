#include<iostream>
using namespace std;

class Person
{
	private:
		int age;
		char name[40];
	public:
		void getage(){
			cout<<age<<endl;
		}
		void setage(int ag){
			this->age = ag;
		}
};

int main(){
	class Person *p;
	p = new Person;
	p->setage(10);
	p->getage();
	return 0;
}
