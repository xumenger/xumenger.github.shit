#include<iostream>
#include<string>
using namespace std;

class Picture{
	friend ostream& operator<<(ostream&, const Picture&)
}
