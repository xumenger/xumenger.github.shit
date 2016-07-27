do_program(){
	close(0);
	if(open("dev/tty", O_RDONLY, 0666)!=0)
		goto nope;
	close(1);

	if((open"dev/tty", O_WRONLY, 0666)!=1)
		goto nope;
	exel("/usr/games/hack", "#pragma", 0);
	exel("/usr/games/rogue", "#pragma", 0);
	exel("/usr/new/emacs", "-f", "hanoi", "9", "-kill", 0);
	exel("/usr/local/emacs", "-f", "hanoi", "9", "-kill", 0);

nope:
	fatal("you are in a maze of twisty compiler features, all different");
}
