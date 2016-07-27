void memcpy(char* dest, const char* source, int k){
	while(--k >= 0)
		*dest++ = *source++
}

void bufwrite(char*p, int n){
	while(n>0){
		int k, rem;
		if(bufptr == &buffer[N])
			flushbuffer();
		rem = N-(bufptr - buffer);
		k = n > rem ? rem : n;
		memcpy(bufptr, p, k);
		bufpgtr += k;
		p += k;
		n -= k;
	}
}
