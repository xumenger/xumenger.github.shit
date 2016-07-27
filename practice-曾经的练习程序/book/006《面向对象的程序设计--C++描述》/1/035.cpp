#include<iostream>
#include<bitset>
using namespace std;
const int featureCount = 8;
const unsigned Framed = 1;
const unsigned Bordered = 2;
const unsigned StdMenu = 4;
const unsigned ToolBar = 8;
const unsigned StatusBar = 16;

class Window{
	public:
		Window(const string& n, unsigned f){
			name = n;
			features = bitset<featureCount>(f);
			createWindow();
		}
		Window(const char* n, unsigned f){
			name = n;
			features = bitset<featureCount>(f);
			createWindow();
		}
	private:
		void createWindow(){
			cout<<"\n***Window feature for "<<name
				<<" given bit mask "<<features<<" : "<<endl;
			if(features[0])
				cout<<"\t"<<"framed"<<endl;
			if(features[1])
				cout<<"\t"<<"bordered"<<endl;
			if(features[2])
				cout<<"\t"<<"with standard menu"<<endl;
			if(features[3])
				cout<<"\t"<<"with tool bar"<<endl;
			if(features[4])
				cout<<"\t"<<"with status bar"<<endl;
		}
		string name;
		bitset<featureCount> features;
};

int main(){
	Window w1("w1", Framed|ToolBar|StatusBar);
	Window w2("w2", ToolBar|Framed|StatusBar);
	Window w3("w3", Framed|StdMenu|StatusBar|ToolBar|Bordered);

	return 0;
}
