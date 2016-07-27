int get_next(int x){
	int a, b, n;
	char s[10];
	sprintf(s, "%d", x);	//转化成字符串

	n = strlen(s);
	int i, j;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(s[i]>s[j]){
				char t = s[i];
				s[i] = s[j];
				s[j] = t;
			}
		}
	}
	sscanf(s, "%d", &b);
	for(i=0; i<n/2; i++){
		char t=s[i];
		s[i]=s[n-1-i];
		s[n-1-i]=t;
	}
	sscanf(s, "%d", &a);
	return a-b;
}
