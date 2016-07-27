#include<iostream>
#include<string>
#include"Sequence.h"
using namespace std;
int main(){
	string inbuff, where;
	int wh;
	Sequence items("test.dat");
	while(true){
		cout<<"\nSequence output; \n";
		items.output();
		cout<<"\n1 -- add\n"
			<<"2 -- delete\n"
			<<"3 -- quit\n";
		getline(cin, inbuff);
		if(inbuff == '1'){
			cout<<"\n item to add:";
			getline(cin, inbuff);
			cout<<" add where?";
			getline(cin, where);
			wh = aoti(where.c_str());
			if(items.addS(wh, inbuff))
				cout<<"item added\n";
			else
				cout<<"item not added\n";
		}else if(inbuff == '2'){
			cout<<"\nwhere to delete:";
			getline(cin, where);
			wh = atoi(where.c_str());
			if(items.del(wh))
				cout<<"item deleted\n";
			else
				cout<<"item not deleted\n";
		}else if(inbuff == '3'){
			break;
		}
	}
	return 0;
}
