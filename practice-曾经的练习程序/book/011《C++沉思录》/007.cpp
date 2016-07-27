class Vehicle{
	public:
		virtual double weight() const = 0;
		virtual void start() = 0;
		virtual Vehicle *copy() const = 0;
		virtual ~Vehicle(){}
};

class VehicleSurrogate{
	public:
		VehicleSurrogate();
		VehicleSurrogate(const Vehicle&);
		~VehicleSurrogate();
		VehicleSurrogate(const VehicleSurrogate&);
		VehicleSurrogate& operator=(const VehicleSurrogate&);

	private:
		Vehicle *vp;
};

VehicleSurrogate::VehicleSurrogate():vp(0){

}
VehicleSurrogate::VehicleSurrogate(const Vehicle &v):vp(v.copy()){

}
VehicleSurrogate::~VehicleSurrogate(){
	delete vp;
}
VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate& v):vp(v.vp? v.vp->copy() : 0){

}
VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate& v){
	if(this != &v){
		delete vp;
		vp = (v.vp? v.vp->copy() : 0);
	}
	return *this;
}
