template<class T>
class Array{
	public:
		T& operator[](int );
		const T& operator[](int)const;
		Array(int);
		~Array();
		inr get_size()const{
			return size;
		}
	private:
		T* a;
		int size;
		Array();
		T dummy_val;
};
template<class T>
T& Array<T>::operator[](int i){
	if(i<0 || i>size){
		cerr<<"index "<<i<<" out of bounds: ";
		return dummy_val;
	}
	return a[i];
}
template<class T>
const T& Array<T>::operator[](int i)const{
	if(i<0 || i>size){
		cerr<<"index "<<i<<" out of bounds:";
		return dummy_val;
	}
	return a[i];
}
template<class T>
Array<T>:Array(int s){
	a = new T[size = s];
}
template<class T>
Array<T>::~Array(){
	delete[] a;
}
template<class T>
osream& operator<<(ostream& os, const Array<T>& ar){
	for(int i=0; i<ar.get_size(); i++)
		os<<ar[i]<<endl;
	return os;
}
