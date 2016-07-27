#include<iostream>
#include<string>
#include"Sequence.h"
using namespace std;

int main(){
	string inbuff, where;
	int wh;
	SortedSeq sortitems("test.dat");
	while(true){
		cout<<"\nSortedSeq output:\n";
		sortitems.output();
		cout<<"\n1 -- add\n"
			<<"2 -- delete\n"
			<<"3 -- quit\n";
		getline(cin, inbuff);
		if(inbuff == '1'){
			cout<<"\nitem to add:";
			getline(cin, inbuff);
			if(sortitems.assSS(inbuff))
				cout<<"item added\n";
			else
				cout<<"item not added\n";
		}else if(inbuff == '2'){
			cout<<"\nwhere to delete:";
			getline(cin, where);
			wh = atoi(where.c_str());
			if(sortitems.del(wh))
				cout<<"item deleted\n";
			else
				cout<<"item not deleted\n";
		}else if(inbuff == '3')
			break;
	}
	return 0;
}
