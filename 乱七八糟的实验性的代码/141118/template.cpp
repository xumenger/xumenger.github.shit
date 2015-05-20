template<class T> class Array{
	public:
		T& operator[](int);
		const T& operator[](int) const;
		Array(int);
		~Array();
		int get_size()cvonst{
			return size;
		}
	private:
		T* a;
		int size;
		Array();
		T dummy_val;
};
template<class T> T& Array<T>::operator[](int i){
	if(i<0||i>size){
		cerr<<"index "<<i<<" is out of bounds;";
		return dummy_val;
	}
	return a[i];
}
template<class T> Array<T>::Array(int s){
	a = new T[s]
}
