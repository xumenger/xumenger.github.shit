#include"TimeStamp.h"
void dumpTS(const TimeStamp& );

int main(){
	TimeStamp ts;
	time_t now = time(0);
	ts.set();
	dumpTS(ts);
	ts.set(now+200000);
	dumpTS(ts);
	ts.set(now-200000);
	dumpTS(ts);
	ts.set(-999);
	dumpTS(ts);

	return 0;
}
void dumpTS(const TimeStamp& ts){
	cout<<"\nTesting method:\n";
	cout<<'\t'<<ts.get()<<'\n';
	cout<<'\t'<<ts.getAsString()<<'\n';
	cout<<'\t'<<ts.getYear()<<'\n';
	cout<<'\t'<<ts.getMonth()<<'\n';
	cout<<'\t'<<ts.getDay()<<'\n';
	cout<<'\t'<<ts.getHour()<<'\n';
	cout<<'\t'<<ts.getMinute()<<'\n';
	cout<<'\t'<<ts.getSecond()<<'\n';
}
