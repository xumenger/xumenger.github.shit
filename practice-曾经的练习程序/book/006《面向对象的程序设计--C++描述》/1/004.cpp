#include<iostream>
using namespace std;
class Person{
	public:
		void setAge(unsigned n){
			age = n;
		}
		unsigned getAge(){
			return age;
		}
	private:
		unsigned age;
};

int main(){
	Person p;
	Person stooges[3];

	p.setAge(12);
	for(int i=0; i<3; i++){
		stooges[i].setAge(i+45);
	}

	cout<<p.getAge()<<endl;
	for(int i=0; i<3; i++){
		cout<<stooges[i].getAge()<<endl;
	}

	return 0;
}
