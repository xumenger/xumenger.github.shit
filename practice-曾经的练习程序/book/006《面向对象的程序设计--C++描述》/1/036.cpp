#include<iostream>
#include<fstream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;
const string inFile = "stockData.dat";
const string Unknown = "????";

class Stock{
	public:
		Stock(){
			symbol = Unknown;
			open = close = gainLoss = volume = 0;
		}
		Stock(const string& s, 			//symbol
				double o, 				//opening price
				double c, 				//closing price;
				unsigned long v){		//volume traded
			symbol = s;
			open = o;
			close = c;
			volume = v;
			gainLoss = (close - open)/open;
		}
		const string& getSymbol()const{
			return symbol;
		}
		double getOpen()const{
			return open;
		}
		double getClose()const{
			return close;
		}
		unsigned long getVolume()const{
			return volume;
		}
		double getGainLoss()const{
			return gainLoss;
		}
	private:
		string symbol;
		double open;
		double close;
		double gainLoss;
		unsigned long volume;
};

struct winCmp{
	bool operator()(const Stock& s1, const Stock& s2)const{
		return s1.getGainLoss() > s2.getGainLoss();
	}
};
struct volCmp{
	bool operator()(const Stock& s1, const Stock& s2)const{
		return s1.getVolume() > s2.getGainVolume();
	}
};

void output(bool volFlag, 
		const string& name, 
		const char* openLabel, double open, 
		const char* closeLabel, double close, 
		const char* gainLabel, double gain, 
		const char* volLabel, unsigned long vol){
	cout<<"*** "<<name<<endl;
	if(volFlag)
		cout<<"\t"<<volLabel<<vol<<endl;
	cout<<"\t"<<gainLabel<<gain<<endl
		<<"\t"<<openLabel<<open<<endl
		<<"\t"<<closeLabel<<close<<endl;
	if(!volFlag)
		cout<<"\t"<<volLabel<<vol<<endl;
}

struct winPr{
	void operator()(const Stock& s)const{
		output(false,
				s.getSymbol(),
				"Opening Price: ", s.getOpen(),
				"Closing Price: ", s.getClose(),
				"% Changed:     ", s.getGainLoss()*100, 
				"Volume:        ", s.getVolume());
	}
};

struct volPr{
	void operator()(const Stock& s)const{
		output(true,
				s.getSymbol(),
				"Opening Price: ", s.getOpen(), 
				"Closing Price: ", s.getClose(),
				"% Changed:     ", s.getGainLoss()*100, 
				"Volume:        ", s.getVolume());
	}
};

void herald(const char*);
void input(deque<Stock>&);

int main(){
	deque<Stock> stocks;

	input(stocks);

	herald("Gainers in descending order: ");
	sort(stocks.begin(), stocks.end, winCmp());

	for_each(stocks.begin(), stocks.end(), winPr());

	herald("Losers in ascending order: ");
	for_each(stocks.rbegin(), stocks.rend(), winPr());

	herald("Volume in descending order: ");
	sort(stocks.begin(), stocks.end(), volCmp());
	for_each(stocks.begin(), stocks.end(), volPr());

	return 0;
}

void input(deque<Stock>& d){
	string s;
	double o, c, v;
	ifstream input(inFile.c_str());

	while(input>>s>>o>>c>>v)
		d.insert(d.end(), Stock(s, o, c, v));
	input.close();
}

void herald(const char* s){
	cout<<endl<<"****** "<<s<<endl;
}
