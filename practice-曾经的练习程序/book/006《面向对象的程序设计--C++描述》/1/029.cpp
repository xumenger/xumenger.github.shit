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

	cout<<m["three"]<<endl
		<<m["zero"]<<endl;

	return 0;
}
