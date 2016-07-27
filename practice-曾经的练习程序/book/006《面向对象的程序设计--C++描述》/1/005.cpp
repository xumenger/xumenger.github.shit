#include"stack.h"

int main(){
	Stack s1;
	s1.init();
	s1.push(9);
	s1.push(4);
	s1.dump();
	cout<<"Poping "<<s1.pop()<<endl;
	s1.dump();
	s1.push(8);
	s1.dump();
	s1.pop();
	s1.dump();
	s1.pop();
	s1.dump();
	s1.push(3);
	s1.push(5);
	s1.dump();
	for(unsigned i=0; i<Stack::MaxStack; i++){
		s1.push(1);
	}
	s1.dump();

	return 0;
}
