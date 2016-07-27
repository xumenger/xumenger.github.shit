#include<iostream>
#include<string>
#include<list>
using namespace std;

void dump(list<string>&);

int main(){
	list<string> names;
	names.insert(names.begin(), "000");
	names.insert(names.end(), "001");
	names.insert(names.begin(), "002");
	names.insert(names.begin(), "003");
	dump(names);

	cout<<endl;

	names.reverse();
	dump(names);

	return 0;
}

void dump(list<string>& l){
	list<string>::const_iterator it;
	it = l.begin();
	while(it != l.end()){
		cout<<*it<<endl;
		it++;
	}
}
