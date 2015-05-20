#include<iostream>
#include<string>
#include<list>
using namespace std;
void dump(list<string>&);
int main(){
	list<string> names;
	names.insert(names.begin(), "Kamiko");
	names.insert(names.end(), "Andre");
	names.insert(names.begin(), "Chengwen");
	names.insert(names.begin(),"Maria");
	dump(names);
	names.reverse();
	cout<<endl;
	dump(names);
	return 0;
}

void dump(list<string>& l){
	list<const string>::const_iterator it;
	//list<string>::const_iterator it;
	it = l.begin();
	while(it != l.end()){
		cout<<*it<<endl;
		it++;
	}
}
