#include<iostream>
#include<string>
using namespace std;

class Namelist{
	public:
		Namelist(){
			size = 0;
			p = 0;
		}
		Namelist(const string[], int);
		Namelist(const Namelist&);
		void set(const string&, int);
		void set(const char*, int);
		void dump()const;
	private:
		int size;
		string* p;
		void copyIntoP(const Namelist&);
};
Namelist::Namelist(const string s[], int si){
	p = new string[size = si];
	for(int i=0; i<size; i++)
		p[i] = s[i];
}
Namelist::Namelist(const Namelist& d){
	p = 0;
	copyIntoP(d);
}
void Namelist::copyIntoP(const Namelist& d){
	delete[] p;
	if(d.p != 0){
		p = new string[size = d.size];
		for(int i=0; i<size; i++)
			p[i] = d.p[i];
	}
	else{
		p=0;
		size = 0;
	}
}
void Namelist::set(const string&s, int i){
	p[i] = s;
}
void Namelist::set(const char* s, int i){
	p[i] = s;
}
void Namelist::dump()const{
	for(int i=0; i<size; i++)
		cout<<p[i]<<endl;
	cout<<endl;
}

int main(){
	string list[] = {"Lab", "Husky", "Collie"};
	Namelist d1(list, 3);
	d1.dump();
	Namelist d2(d1);
	d2.dump();
	d2.set("Great Dane", 1);
	d2.dump();
	d1.dump();

	return 0;
}
