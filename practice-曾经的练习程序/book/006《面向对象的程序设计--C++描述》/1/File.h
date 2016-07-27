#include<iostream>
#include<string>
using namespace std;

class File{
	public:
		void store_title(const string& t){
			title = t;
		}
		void store_title(const char*t){
			title = t;
		}
		void store_director(const string& d){
			director = d;
		}
		void store_director(const char* d){
			director = d;
		}
		void store_time(int t){
			time = t;
		}
		void store_quality(int q){
			quality = q;
		}
		void output()const;
	private:
		string title;
		string director;
		int time;
		int quality;
};
void File::output()const{
	cout<<"Title: "<< title <<endl;
	cout<<"Director: "<< director <<endl;
	cout<<"Time: "<< time <<" mins"<<endl;
	cout<<"Quality: ";
	for(int i=0; i<quality; i++)
		cout<<'*';
	cout<<endl;
}

class DirectorCut : public File{
	public:
		void store_rev_time(int t){
			rev_time = t;
		}
		void store_changes(const string& s){
			changes = s;
		}
		void store_changes(const char* s){
			changes =s;
		}
		void output()const;
	private:
		int rev_time;
		string changes;
};
void DirectorCut::output()const{
	File::output();
	cout<<"Revised time: "<< rev_time <<" mins\n";
	cout<<"Changes: "<< changes <<endl;
}

class ForeignFile : public File{
	public:
		void store_language(const string& s){
			language = s;
		}
		void store_language(const char* s){
			language = s;
		}
		void output()const;
	private:
		string language;
};
void ForeignFile::output()const{
	File::output();
	cout<<"Language: "<< language <<endl;
}
