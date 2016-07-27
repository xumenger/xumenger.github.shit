int hash_filename(char* s){
	int length = strlen(s);
	return(length+4*(s[0]+4*s[length/2]))%FILE_HASH;
}

file find_filename(char* s){
	int hash_value = hash_filename(s);
	file f;

	for(f=file_hash_table[hash_value]; f!=NIL; f=f->flink){
		if(strcmp(f->fname, s) == SAME)
			return f;
	}

	f = allocate_file(s);
	f->flink = file_hash_table[hash_value];
	file_hash_table[hash_value] = f;

	return f;
}
