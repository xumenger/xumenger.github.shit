class Singleton{
	public:
		Singleton *Instance();
	protected:
		Singleton();
	private:
		Singleton* _instance;
};

Singleton* Singleton::_instance = 0;

Singleton* Singleton::Instance(){
	if(_instance == 0)
		_instance = new Singleton;
	return _instance;
}
