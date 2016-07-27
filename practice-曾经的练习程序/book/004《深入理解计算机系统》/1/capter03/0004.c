int switch_eg_impl(int x, int n){
	static void *jt[7] = {
		&&loc_A, &&loc_def, &&loc_B, &&loc_C, &&loc_D, &&loc_def, &&loc_D
	};

	unsigned index = n-100;
	int result;

	if(index > 6)
		goto loc_def;

	goto *jt[index];

	loc_def:
		result = 0;
		goto done;

	loc_C:
		result = x;
		goto rest;
	
	loc_A:
		result = x * 13;
		goto done;

	loc_B:
		result = x + 10;
	
	rest:
		result += 11;
		goto done;

	loc_C:
		result = x * x;

	done:
		return result;
}
