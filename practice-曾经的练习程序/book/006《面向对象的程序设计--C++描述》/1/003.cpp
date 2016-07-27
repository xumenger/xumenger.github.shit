#include<iostream>
#include<string>
using namespace std;

struct Elephant{
	string name;
	Elephant* next;
};
void print_elephants(const Elephant* ptr);
Elephant* get_elephants();
void free_list(const Elephant* ptr);

int main(){
	Elephant* start;
	start = get_elephants();
	print_elephants(start);
	free_list(start);

	return 0;
}

Elephant* get_elephants(){
	Elephant* current, *first;
	int response;
	current = first = new Elephant;
	cout<<"\n NAME:";
	cin>>current->name;

	cout<<"\n Add another?(1==yes, 0==no):";
	cin>>response;
	while(response == 1){
		current = current->next = new Elephant;
		cout<<"\n NAME:";
		cin>>current->name;

		cout<<"\n Add another?(1==yes, 0==no):";
		cin>>response;
	}
	current->next = 0;
	return first;
}

void print_elephants(const Elephant* ptr){
	int count = 1;
	cout<<"\n\n\n";
	while(ptr != 0){
		cout<<"Elephant number "<<count++<<" is "<<ptr->name<<"\n";
		ptr = ptr->next;
	}
}

void free_list(const Elephant* ptr){
	const Elephant* temp_ptr;
	while(ptr != 0 ){
		temp_ptr = ptr->next;
		delete ptr;
		ptr = temp_ptr;
	}
}
