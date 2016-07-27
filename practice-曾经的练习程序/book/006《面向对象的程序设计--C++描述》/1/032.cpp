#include<iostream>
#include<functional>
#include<queue>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
	const int howMany = 9;
	int i;
	priority_queue<int> nums;
	srand(time(0));

	for(i=0; i<howMany; i++){
		int next = rand();
		cout<<next<<endl;
		nums.push(next);
	}
	cout<<"\n***Priority by value:"<<endl;
	for(i=0; i<howMany; i++){
		cout<<nums.top()<<endl;
		nums.pop();
	}

	return 0;
}
