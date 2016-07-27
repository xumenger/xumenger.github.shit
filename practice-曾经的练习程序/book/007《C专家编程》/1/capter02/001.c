network code(){
	switch(line){
		case THING1:
			doit1();

		break;
		case THING2:
			if(x == STUFF){
				do_first_stuff();

				if(y == OTHER_STUFF)
					break;
				do_later_stuff();
			}
			initialize_modes_pointer();
			break;
		default:
			processing();
	}
	use_modes_pointer();
}
