class Entry{
	public:
		Entry(){
			flag = false;
		}
		void add(const string&, const string&);
		bool match(const string&)const;
		void operator=(const string&);
		void operator=(const char*);
		friend ostream& operator<<(ostream&, const Entry&);
		bool valid()const{
			return flag;
		}
	private:
		string word;
		string def;
		bool flag;
};
void Entry::operator=(const string& str){
	def = str;
	flag = true;
}
void Entry::operator=(const char* str){
	def = str;
	flag = true;
}
ostream& operator<<(ostream& out, const Entry& e){
	out<<e.word<<" defined as: "<<e.def;
	return out;
}
void Entry::add(const string& w, const string& d){
	word = w;
	def = d;
}
bool Entry::add(const string& w, const string& d){
	word = w;
	def = d;
}
bool Entry::match(const string& key)const{
	return key==word;
}

class Dict{
	public:
		enum{MaxEntries = 100};
		friend ostream& operator<<(ostream&, const Dict&);
		Entry& operator[](const string&);
		Entry& operator[](const char*);
	private:
		Entry entries[MaxEntries+1];
};
ostream& operator<<(ostream& out, const Dict& d){
	for(int i=0; i<MaxEntries; i++)
		if(d.entries[i].valid)
			out<<d.entries[i]<<'\n';
	return out;
}
Entry& Dict::operator[](const string& k){
	for(int i=0; i<MAxEntries && entries[i].valid(); i++)
		if(entries[i].match(k))
			return entries[i];
	string not_found = "*** not in directionary";
	entries[i].add(k, not_found);
	return entries[i];
}
Entry& Dict::operator[](const char* k){
	string s = k;
	return operator[](s);
}
}
