String& String::operator=(const String &s){
	delete[] data;
	data = new char[strlen(s.data)+1];
	strcpy(data, s.data);
	return *this;
}

String& String::operator=(const String &s){
	if(&S != this){
		delete[] data;
		data = new char[strlen(s.data)+1];
		strcpy(data, s.data);
	}
	return *this;
}

String& String::operator=(const String &s){
	char *newdata = new char[strlen(s.data)+1];
	strcpy(newdata, s.data);
	delete[] data;
	data = newdata;
	return *this;
}
