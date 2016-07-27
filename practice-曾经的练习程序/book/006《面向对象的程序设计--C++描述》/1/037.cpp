#include<iostream>
using namespace std;

class Test{
	public:
		bool operator()(unsigned n)const{
			return n%2 == 0;
		}
	private:
		int x;
};

int main(){
	Test t;
	cout<<t(3)<<endl;
	//cout<<Test(3);

	return 0;
}
