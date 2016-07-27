#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){
	//Open input and output streams
	const int dInd = 7;	//index for insertion
	ifstream in;
	ofstream out;
	string buffer;
	in.open("bets.dat");
	out.open("y2k.dat");

	//Convert 2-field dates such as "98" to 4-field dates such as "1998"
	while(getline(in, buffer)){
		buffer.insert(dInd, "19");
		out<<buffer<<'\n';
	}
	in.close();
	out.close();

	return 0;
}
