#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template<class T>
class Stack{
	public:
		enum{DefaultStack = 50, EmptyStack = -1};
		Stack();
		Stack(int);
		~Stack();
		void push();
		T pop();
		T topNoPop() const;
		bool empty() const;
		bool full() const;
	private:
		T* elements;
		int top;
		int size;
		void allocate(){
			elements = new T[size];
			top = EmptyStack;
		}
		void msg(const char* m)const{
			cout<<"***"<< m <<"***"<<endl;
		}
		friend ostream& operator<<(ostream&, const Stack<T>&);
};
template<class T>
Stack<T>::Stack(){
	size = DefaultStack;
	allocate();
}
template<class T>
Stack<T>::Stack(int s){
	if(s<0)
		s*=-1;
	else if(s == 0)
		s = DefaultStack;
	size = s;
	allocate();
}
template<class T>
Stack<T>::~Stack(){
	delete[] elements;
}
template<class T>
void Satck<T>::push(const T& e){
	assert(!full());
	if(!full())
		elements[++top]=e;
	else
		msg("Stack Full");
}
template<class T>
T Stack<T>::pop(){
	assert(!empty());
	if(!empty())
		return elements[top--];
	else{
		msg("Stack Empty");
		T dummy_value;
		return dummy_value;
	}
}
template<class T>
T Stack<T>::topNoPop() const{
	assert(top>EmptyStack);
	if(!empty())
		return elements[top];
	else{
		msg("Stack Empty");
		T dummy_value;
		return dummy_value;
	}
}
template<class T>
bool Stack<T>::empty() const{
	return top<=EmptyStack;
}
template<class T>
bool Stack<T>::full() const{
	return top+1>=size;
}
template<class T>
ostream& operator<<(ostream& os, const Stack<T>& s){
	s.msg("Stack:contents:");
	int t = s.top;
	while(t>s.EmptyStack)
		cout<<s.elements[t--]<<endl;
	return os;
}
