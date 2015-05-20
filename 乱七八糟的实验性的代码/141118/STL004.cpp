#include<iostream>
#include<set>
using namespace std;
int main(){
	set<int> s;
	s.insert(-999);
	s.insert(18);
	s.insert(321);
	s.insert(-999);
	set<int>::const_iterator it;
	it = s.begin();
	while(it != s.end())
		cout<<*it++<<endl;
	int key;
	cout<<"Enter an integer:";
	cin>>key;
	it = s.find(key);
	if(it == s.end())
		cout<<key<<" is not in set"<<endl;
	else
		cout<<key<<" is in set"<<endl;
	return 0;
}
