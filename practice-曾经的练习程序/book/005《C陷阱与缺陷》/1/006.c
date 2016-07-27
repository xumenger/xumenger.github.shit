void flush(){
	int row;
	int k = bufptr - buffer;
	if(k > NROWS)
		k = NROWS;
	for(row=0; row<k; row++){
		int *p;
		for(p=buffer+row; p<bufptr; p+=NROWS)
			printnum(*p);
		printnl();
	}
	if(k > 0)
		printpage();
}
