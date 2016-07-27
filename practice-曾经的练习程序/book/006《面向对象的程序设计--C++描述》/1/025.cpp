#include<iostream>
#include<string>
#define NDEBUG
#include<cassert>
using namespace std;

template<class T>
class Stack{
	public:
		enum{DefaultStack = 50, EmptyStack=-1};
		Stack();
		Stack(int);
		~Stack();
		void push(const T&);
		T pop();
		T topNoPop()const;
		bool empty()const;
		bool full()const;
	private:
		T* elements;
		int top;
		int size;
		void allocate(){
			elements = new T[size];
			top = EmptyStack;
		}
		void msg(const char* m)const{
			cout<<"***"<<m<<"***"<<endl;
		}
		friend ostream& operator<<(ostream&, const STack<T>&);
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
	else if(0==s)
		s = DefaultStack;
	size = s;
	allocate();
}
template<class T>
Stack<T>::~Stack(){
	delete[] elements;
}
template<class T>
void Stack<T>::push(const T& s){
	assert(!full());
	if(!full())
		elements[++top] = e;
	else
		msg("Stack full");
}
template<class T>
T Stack<T>::pop(){
	assert(!empty());
	if(!empty())
		return elements[top--];
	else{
		msg("Stack empty");
		T dummy_value;
		return dummy_value;
	}
}
template<class T>
T Stack<T>::topNoPop()const{
	assert(top > EmptyStack);
	if(!empty())
		return elements[top];
	else{
		msg("Stack empty");
		T dummy_vlaue;
		return dummy_value;
	}
}
template<class T>
bool Stack<T>::empty()const{
	return top<=EmptyStack;
}
template<class T>
bool Stack<T>::full()const{
	return top+1>=size;
}
template<class T>
ostream& operator<<(ostream& os, const Stack<T>& s){
	s.msg("Stack contents:");
	int t = s.top;
	while(t>s.EmptyStack)
		cout<<s.elemnets[t--]<<endl;
	return os;
}
