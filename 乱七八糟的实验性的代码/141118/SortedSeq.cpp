class SortedSeq : public Sequence{
	public:
		bool addSS(const string&);
		SortedSeq(){}
		SortedSeq(const char*);
	protected:
		void sort();
	private:
		using Sequence:addS;
};

void SortedSeq::sort(){
	string temp;
	int i, j;
	for(i=0; i<=last-1; i++){
		temp = s[i+1];
		for(j=i; j>=0; j--){
			if(temp<s[j])
				s[j+1]=s[j];
			else
				break;
		}
		s[j+1]=temp;
	}
}
bool SortedSeq::addSS(const string& entry){
	int i;
	for(i=0; i<=last; i++)
		if(entry<=s[i])
			break;
	return addS(i, entry);
}
SortedSeq::SortSeq(const char *fname):Sequence(fname){
	sort();
}
