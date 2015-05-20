#include<iostream>
#include<string>
#include<map>
using namespace std;
int main(){
	map<string, int> m;
	m["zero"] = 0;
	m["one"] = 1;
	m["two"] = 2;
	m["three"] = 3;
	m["four"] = 4;
	m["five"] = 5;
	m["six"] = 6;
	m["seven"] = 7;
	m["eight"] = 8;
	m["nine"] = 9;

	cout<<m["three"]<<endl
		<<m["one"]<<endl;

	return 0;
}
