template<class T, int S>
class Array{
	public:
		T& operator[](int);
		const T& operator[](int) const;
		Array();
		~Array();
		int get_size()const{
			return size;
		}
	private:
		T* a;
		int size;
		T dummy_val;
};
template<class T, int S>
T& Array<T, S>::operator[](int i){
	if(i<0 || i>=size){
		cerr<<"index "<<i<<" out of bounds:";
		return dummy_val;
	}
	return a[i];
}
template<class T, int S>
const T& Array<T, S>::operator[](int i)const{
	if(i<0 || i>=size){
		cerr<<"index "<<i<<" out of bounds:";
		return dummy_val;
	}
	return a[i];
}
template<class T, int S>
Array<T, S>::Array(){
	a = new T[size = S];
}
template<class T, int S>
Array<T, S>::~Array(){
	delete[] a;
}
