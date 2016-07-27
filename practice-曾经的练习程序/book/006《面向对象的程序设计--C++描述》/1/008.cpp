#include<iostream>
#include<string>
using namespace std;

class NameList{
	public:
		NameList(){
			size = 0;
			p = 0;
		}
		NameList(const string[], int);
		void set(const string&, int);
		void set(const char*, int);
		void dump()const;
	private:
		int size;
		string* p;
};

NameList::NameList(const string s[], int si){
	p = new string[size = si];
	for(int i=0; i<size; i++)
		p[i] = s[i];
}
void NameList::set(const string& s, int i){
	p[i] = s;
}
void NameList::set(const char* s, int i){
	p[i] = s;
}
void NameList::dump()const{
	for(int i=0; i<size; i++)
		cout<<p[i]<<endl;
	cout<<endl;
}

int main(){
	string list[] = {"Lab", "Husky", "Collie"};
	NameList d1(list, 3);
	d1.dump();
	NameList d2(d1);
	d2.dump();

	d2.set("Great Dane", 1);
	d2.dump();
	d1.dump();

	return 0;
}
