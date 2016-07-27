class Point{
	public:
		Point():xval(0), yval(0){

		}
		Point(int x, int y):xval(x), yval(y){
		
		}
		int x()const{
			return xval;
		}
		int y()const{
			return yval;
		}
		Point& x(int xv){
			xval = xv;
			return *this;
		}
		Point& y(int yv){
			yval = yv;
			return *this;
		}

	private:
		int xval, yval;
};

class Handle{
	public:
		Handle():up(new UPoint){

		}
		Handle(int x, int y):up(new UPoint(x, y)){

		}
		Handle(const Point& p):up(new UPoint(p)){

		}
		Handle(const Handle&);
		Handle& operator=(const Handle&);
		~Handle(){
			if(--up->u == 0)
				delete up;
		}

		int x()const;
		Handle& x(int);
		int y()const;
		Handle& y(int);

	private:
		UPoint * up;
};

class UPoint{
	friend class Handle;
	Point p;
	int u;
	UPoint():u(1){
	
	}
	UPoint(int x, int y):P(x, y), u(1){

	}
	UPoint(const Point& p0):p(p0), u(1){

	}
};


