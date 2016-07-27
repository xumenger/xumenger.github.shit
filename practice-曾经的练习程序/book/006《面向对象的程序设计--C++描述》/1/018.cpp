#include"film.h"
using namespace std;

int main(){
	const unsigned  n = 5;
	Film* films[n];
	//attempt to read input file and create objects
	if(!File::read_input("films.dat", films, m)){
		cerr<<"Unable to read file films.dat:exiting."<<endl;
		exit(EXIT_FAILURE);
	}
	//output to standard output
	for(unsigned i=0; i<n; i++)
		films[i]->output();

	return 0;
}
