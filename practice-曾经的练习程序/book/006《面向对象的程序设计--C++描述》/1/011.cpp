#include<iostream>
#include<string>
using namespace std;
class C{
	public:
		C(){
			name = "anoymous";
			cout<<name<<" constructing \n";
		}
		C(const char* n){
			name = n;
			cout<<name<<" constructing \n";
		}
		~C(){
			cout<<name<<" destructing \n";
		}
	private:
		string name;
};
int main(){
	C c0("hortense");
	{
		C c1;
		C c2("foo");
		cout<<'\n';
	}

	C* ptr = new C();
	delete ptr;
	return 0;
}
