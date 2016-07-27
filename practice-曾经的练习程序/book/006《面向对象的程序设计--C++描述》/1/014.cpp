#include<iostream>
using namespace std;

class BC{
	public:
		BC(){
			sBC = new char[3];
			cout<<"BC allocates 3 bytes\n";
		}
		~BC(){
			delete[] sBC;
			cout<<"BC frees 3 bytes\n";
		}
	private:
		char* sBC;
};
class DC : public BC{
	public:
		DC():BC(){
			sDC = new char[5];
			cout<<"DC allocates 5 bytes\n";
		}
		~DC(){
			delete[] sDC;
			cout<<"DC frees 5 bytes\n";
		}
	private:
		char* sDC;
};

int main(){
	DC d1;
	return 0;
}
