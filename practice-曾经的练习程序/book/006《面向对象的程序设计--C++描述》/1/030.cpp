#include<iostream>
#include<stack>
#include<cctype>
using namespace std;

int main(){
	const string prompt = "Enter an algebraic expression:";
	const char lParen = '(';
	const char rParen = ')';
	stack<char> s;
	string buf;

	cout<<prompt<<endl;
	getline(cin, buf);

	for(int i=0; i<buf.length(); i++)
		if(!isspace(buf[i]))
			s.push(buf[i]);
	cout<<"Original expression: "<<buf<<endl;
	cout<<"Expression in reverse: ";

	while(!s.empty()){
		char t = s.top();
		s.pop();
		if(t == lParen)
			t=rParen;
		else if(t == rParen)
			t=lParen;
		cout<<t;
	}
	cout<<endl;
	return 0;
}
