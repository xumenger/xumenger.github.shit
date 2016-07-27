#include<iostream>
#include<ctime>
#include<string>
using namespace std;
class TimeStamp{
	public:
		void set(long s=0){
			if(s<=0)
				stamp = time(0);
			else
				stamp = s;
		}
		time_t get() const{
			return stamp;
		}
		string getAsString()const{
			return extract(0, 24);
		}
		string getYear()const{
			return extract(20, 4);
		}
		string getMonth()const{
			return extract(4, 3);
		}
		string getDay()const{
			return extract(0, 3);
		}
		string getHour()const{
			return extract(11, 2);
		}
		string getMinute()const{
			return extract(14, 2);
		}
		string getSecond()const{
			return extract(17, 2);
		}
	private:
		string extract(int offset, int count)const{
			string timeString = ctime(&stamp);
			return timeString.substr(offset, count);
		}
		time_t stamp;
};
