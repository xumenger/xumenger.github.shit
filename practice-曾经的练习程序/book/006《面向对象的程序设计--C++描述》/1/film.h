#include<iostream>
#include<string>
#include<fstream>
#include<cctype>
using namespace std;

class Film{
	public:
		Film(){
			store_title();
			store_director();
			store_time();
			store_quality();
		}
		void store_title(const string& t){
			title = t;
		}
		void store_title(const char* t=""){
			title = t;
		}
		void store_director(const string& d){
			director = d;
		}
		void store_director(const char* d=""){
			director = d;
		}
		void store_time(int t=0){
			time = t;
		}
		void store_quality(int q=0){
			quality = q;
		}
		virtual void output();
		virtual void input(ifstream&);
		static bool read_input(const char*, Film*[], int);
	private:
		string title;
		string director;
		int time;
		int quality;
};
void Film::input(ifstream& fin){
	string inbuff;
	getline(fin, inbuff);
	store_title(inbuff);
	getline(fin, inbuff);
	store_director(inbuff);
	getline(fin, inbuff);
	store_time(atoi(inbuff.c_str()));
	getline(fin, inbuff);
	store_quality(atoi(inbuff.c_str()));
}
void File::output(){
	cout<<"Title: "<<title<<endl;
	cout<<"Director: "<<director<<endl;
	cout<<"Time: "<<time<<" mins"<<endl;
	cout<<"Quality: ";
	for(int i=0; i<quality; i++)
		cout<<"*";
	cout<<endl;
}

class DirectorCut : public File{
	public:
		DirectorCut(){
			store_rev_time();
			store_changes();
		}
		void store_rev_time(int t = 0){
			rev_time = t;
		}
		void store_changes(const string& c){
			changes = c;
		}
		void store_changes(const char* c){
			changes = c;
		}
		virtual void output();
		virtual void input(ifstream&);
	private:
		int rev_time;
		string changes;
};
void DirectorCut::intput(ifstream& fin){
	File::input(fin);
	string inbuff;
	getline(fin, inbuff);
	store_rev_time(atoi(inbuff.c_str()));
	getline(fin, inbuff);
	store_changes(inbuff);
}
void DirectorCut::output(){
	Film::output();
	cout<<"Revised time: "<<rev_time<<endl;
	cout<<"Changes: "<<changes<<endl;
}

class ForeignFilm : public Film{
	public:
		ForeignFilm(){
			store_language();
		}
		void store_language(const string& l){
			language = l;
		}
		void store_language(const char* l=""){
			language = l;
		}
		virtual void output();
		virtual void inout(ifstream&);
	private:
		string language;
};	
void ForeignFilm::input(ifstream& fin){
	Film::input(fin);
	string inbuff;
	getline(fin, inbuff);
	store_language(inbuff);
}
void ForeignFilm::output(){
	Film::output();
	cout<<"Language: "<<language<<endl;
}

bool Film::read_input(const char* file, Film* film[], int n){
	string inbuff;
	ifstream fin(file);
	if(!fin)
		return false;
	int next = 0;
	while(getline(fin, inbuff) && next<n){
		if(inbuff == "Film")
			films[next] = new Film();
		else if(inbuff == "ForeignFilm")
			films[next] = new ForeignFilm();
		else if(inbuff == "DirectorCut")
			files[next] == new DirectorCut();
		else
			continue;
		films[next++]->input(fin);
	}
	fin.close();
	return true;
}
