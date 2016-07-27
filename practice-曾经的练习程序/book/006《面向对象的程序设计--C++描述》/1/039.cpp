#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

const int header_size = 256;
const char Taken = 'T';
const char Free = 'F';
const char Deleted = 'D';

class frandom : public fstream{
	public:
		frandom();
		frandom(const char*);	//open existing file
		frandom(const char*, int, int, int);	//open new file
		~frandom();
		void open(const char*);	//open existing file;
		void open(const char*, int, int, int);	//open new file
		void close();
		long get_slots()cosnt{
			return slots;
		}
		long get_record_size()const{
			return record_size;
		}
		long get_key_size()const{
			return key_size;
		}
		long get_total_bytes()const{
			return total_bytes;
		}
		long get_no_records()const{
			return no_records;
		}
		bool add_record(const char*);
		bool find_record(char*);
		bool remove_record(const char*);
	private:
		long slots;
		long record_size;
		long key_size;
		long total_bytes;
		long no_records;
		long loc_address;
		char* buffer;
		char* stored_key;
		long get_address(const char*)const;
		bool locate(const char*);
};
frandom::~frandom(){
	if(is_open()){
		delete[] stored_key;
		delete[] buffer;
		char buff[header_size];
		for(int i=0; i<header_size; i++)
			buff[i] = ' ';
		sprintf(buffm "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		seekp(0, ios_base::beg);
		write(buff, header_size);
	}
}
frandom::frandom():fstream(){
	buffer = stored_key = 0;
	slots = record_size = key_size = 0;
	total_bytes = no_records = 0;
}
frandom::frandom(const char* filename):fstream(){
	buffer = stored_key = 0;
	open(filename);
}
frandom::frandom(const char* filename,
		int sl,
		int actual_record_size,
		int ks):fstream(){
	buffer = stored_key = 0;
	open(filename, s1, actual_record_size, ks);
}
//open an existing file
void frandom::open(const char* filename){
	fstream::open(filename, 
			ios_base::in|iosbase::out|ios_base::binary);
	if(is_open()){
		char buff[header_size];
		read(buff, header_size);
		sscanf(buff, "%ld%ld%ld%ld",&slots, &record_size, &key_size, &no_records);
		total_byte = slots*record_size+header_size;
		//get_address needs\0
		stored_key = new char[key_size+1];
		buffer = new char[record_size];
	}
}
//open new file
void frandom::open(const char* filename,
		int s1,
		int actual_record_size,
		int ks){
	fstream::open(filename,
			ios_base::in|ios_base::out|ios_base::binary);
	//if open succeeds, file already exist
	if(is_open()){
		setstate(ios_base::failbit);
		fstream::close();
		return;
	}
	//file does not exist; create it
	fstream::open(filename, ios_base::out|ios_base::binary);
	if(is_open())
		fstream::close();
	//file created; now open if for input and output
	fstream::open(filename, ios_base::in|ios_base::out|ios_base::binary);
	if(is_open()){
		clear();//clear failbit flag set by open failure
		char buff[header_size];
		slots = s1;
		record_size = actual_record_size+1;
		key_size = ks;
		total_bytes = slots*record_size+header_size;
		no_records = 0;
		//get_address needs\0
		stored_key = new char[key_size+1];
		for(int i=0; i<header_size; i++)
			buff[i] = ' ';
		sprintf(buff, "%ld %ld %ld %ld", slots, record_size, key_size, no_records);
		write(buff, header_size);
		buffer = new char[record_size];
		for(i=1; i<record_size; i++)
			buffer[i] = ' ';
		buffer[0] = Free;
		for(i=0; i<slots; i++)
			write(buffer, record_size);
	}
}
//hash function
long frandom::get_address(const char* key)const{
	memcpy(stored_key, key, key_size);
	stored_key[key_size] = '\0';
	return(atol(stored_key)%slots)*record_size+header_size;
}
//locate searches for a record with the specified key
//If successful, locate return true
//If unseccessful, locate return flase.
//locate sets data member loc_address to the address
//of the record if the record is found. This
//address can be the used by find_record
//or remove_record
//
//If the record is not found, locate sets loc_address
//to the first
bool frandom::locate(const char* key){
	long address, state_address, unocc_address;
	int delete_flag = false;
	address = get_address(key);
	unocc_address = state_address = address;
	do{
		seekg(address, ios_base::beg);
		switch(get()){
			case Deleted:
				if(!deleted_falg){
					unocc_address = address;
					delete_flag = true;
				}
				break;
			case Free:
				loc_address = delete_flag ? unocc_address : address;
		return false;
			case Taken:
				seekg(address+1, ios_base::beg);
				read(stored_key, key_size);
				if(memcmp(key, stored_key, key_size) == 0){
					loc_address = address;
					return true;
				}
				break;
		}

	}
}
