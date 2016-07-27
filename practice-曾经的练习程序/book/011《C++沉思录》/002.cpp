#include<stdio.h>

class Trace{
	public:
		Trace(){
			noisy = 0;
		}
		void print(char *s){
			if(noisy){
				printf("%s", s);
			}
		}
		void on(){
			noisy = 1;
		}
		void off(){
			noisy = 0;
		}
	private:
		int noisy;
};

int main(void){
	Trace t;
	t.off();
	t.print("fuck\n");
	t.on();
	t.print("fuck\n");

	return 0;
}
