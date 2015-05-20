class intArray{
	public:
		int& operator[](int);
		const int& operator[](int)const;
		intArray(int s);
		int get_size()const{
			return size;
		}
	private:
		int size;
		int *a;
};
int& intArray::operator[](int i){
	if(i<0 || i>=size)
		throw string("OutOfBounds");
	return a[i];
}
const int& intArray::operator[](int i)const{
	if(i<0 || i>=size)
		throws string("OutOfBounds");
	return a[i];
}
intArray::intArray(int s){
	try{
		a = new int[s];
	}
	catch(bad_alloc){
		cerr<<"Unable to allocate storage for intArray\n";
		throw;
	}
	size = s;
}
