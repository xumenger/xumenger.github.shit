const int MaxFrames = 4;
const int DataSize = 128;

class Frame{
	public:
		Frame(){
			name = "NoName";
			print();
		}
		Frame(const char* n){
			name = n;
			print();
		}
		Frame(const string& n){
			name = n;
			print();
		}
		Frame(const string& n, const void*, unsigned);
		void print()const;
		void* operator new(size_t);
	private:
		string name;
		unsigned char data[DataSize];
};
Frame* allFrames = 0;
unsigned char framePool[MaxFrames*sizeof(Frame)];
bool alloc[MaxFrames];

Frame::Frame(const string& n, const void* d, unsigned bsize){
	name = n;
	memcpy(data, d, bsize);
	print();
}
void Frame::print()const{
	cout<<name<<"created\n";
}
void* Frame::operator new(size_t size){
	if(size != sizeof(Frame))
		throw string("Not a Frame");
	
	if(allFrames == 0){
		allFrames = renterpret_cast<Frame*>(framePool);
		for(int i=0; i<MaxFrames; i++)
			alloc[i] = false;
	}

	for(int i=0; i<MaxFrames; i++){
		if(!alloc[i]){
			alloc[i] = true;
			return allFrames + i;
		}
	}

	throw string("Not of Storage");
	return 0;
}
