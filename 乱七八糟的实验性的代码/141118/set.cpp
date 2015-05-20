#include<iostream>
#include<set>

using namespace std;

int main(){
	set<char> s;
	s.insert('a');
	s.insert('3');
	s.insert('d');
	s.insert('0');
	s.insert('3');

	set<char>::const_iterator it;
	it = s.begin();
	while(it != s.end()){
		cout<<*it++<<endl;
	}

	return 0;
}
