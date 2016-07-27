#include"TimeStamp.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include<string>
using namespace std;

class Task{
	public:
		Task(const string& ID){
			setID(ID);
			logFile = "log.dat";
			setST();
			ft = st;
		}
		Task(const char* ID){
			setID(ID);
			logFile = "log.dat";
			setST();
			ft = st;
		}
		~Task(){
			logToFile();
		}
		void setST(time_t ST = 0){
			st.set(ST);
		}
		time_t getST()const{
			return st.get();
		}
		string getStrST()const{
			return st.getAsString();
		}
		void setFT(time_t FT = 0){
			ft.set(FT);
		}
		time_t getFT()const{
			return ft.get();
		}
		string getStrFT()const{
			return ft.getAsString();
		}
		void setID(const string& ID){
			id = ID;
		}
		void setID(const char* ID){
			id = ID;
		}
		string getID()const{
			return id;
		}
		double getDU()const{
			return difftime(getFT(),getST());
		}
		void logToFile(){
			if(getFT() == getST())
				setFT();
			ofstream outfile(logFile.c_str(), ios::app);
			outfile<<"\nID: "<<id<<'\n';
			outfile<<" ST: "<<getStrST();
			outfile<<" FT: "<<getStrFT();
			outfile<<" DU: "<<getDU();
			outfile<<"\n";
			outfile.close();
		}
	private:
		Task();
		TimeStamp st;
		TimeStamp ft;
		string id;
		string logFile;
};
