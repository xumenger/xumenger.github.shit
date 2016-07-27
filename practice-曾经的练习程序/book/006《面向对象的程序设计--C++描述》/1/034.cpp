#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void printChar(char c){
	cout<<c;
}

int main(){
	string s = "pele, the greatest ever";

	cout<<"s:		"<<s<<endl;
	cout<<"s in reverse:	";
	for_each(s.rbegin(), s.rend(), printChar);
	cout<<endl;

	char* where = find(s.begin(), s.end(), 'a');
	cout<<"'a'. is the "<<where-s.begin()+1<<"th char in: "<<s<<endl;

	random_shuffle(s.begin(), s.end());
	cout<<"'a' is the "<<where-s.begin()+1<<"th char in: "<<s<<endl;

	sort(s.begin(), s.end());
	cout<<"s sorted in ascending order: "<<s<<endl;

	return 0;
}
