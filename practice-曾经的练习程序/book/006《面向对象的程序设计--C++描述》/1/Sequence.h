#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class Sequence{
	public:
		bool addS(int, const string&);
		bool del(int);
		void output()const;
		Sequence():last(-1){

		}
		Sequence(const char*);
		~Sequence();
	protected:
		enum{MaxStr = 50};
		string s[MaxStr];
		int last;
	private:
		string filename;
		ifstream in;
		ofstream out;
};
bool Sequence::addS(int pos, const string& entry){
	if(last==MaxStr-1 || pos<0 ||pos>last+1)
		return false;
	for(int i=last; i>=pos; i--)
		s[i+1] = s[i];
	s[pos] = entry;
	last++;
	return true;
}
bool Sequence::del(int pos){
	if(pos<0 || pos>last)
		return false;
	for(int i=pos; i<last; i--)
		s[i] = s[i+1];
	last--;
	return true;
}
void Sequence::output()const{
	for(int i=0; i<=last; i++)
		cout<<i<<" "<<s[i]<<endl;
}
Sequence::Sequence(const char* fname){
	last = -1;
	filename = fname;
	in.open(fname);
	if(!in)
		return ;
	while(last<MaxStr-1 && getline(in, s[last+1]))
		last++;
	in.close();
}
Sequence::~Sequence(){
	if(filename == "")
		return ;
	out.open(filename.c_str());
	for(int i=0; i<=last; i++)
		out<<s[i]<<'\n';
	out.close();
}

class SortedSeq : public Sequence{
	public:
		bool addSS(const string&);
		SortedSeq(){

		}
		SortedSeq(const char*);
	protected:
		void sort();
	private:
		using Sequence::addS;
};
void SortedSeq::sort(){
	string temp;
	int i, j;
	for(i=0; i<=last-1; i++){
		temp = s[i+1];
		for(j=i; j>=0; j--){
			if(temp<s[j])
				s[j+1] = s[j];
			else
				break;
		}
		s[j+1] = temp;
	}
}
bool SortedSeq::addSS(const string& entry){
	int i;
	for(i=0; i<=last; i++)
		if(entry<s[i])
			break;
	return addS(i, entry);
}
SortedSeq::SortedSeq(const char* fname):Sequence(fname){
	sort();
}
