example:sort.o compute.o main.o
	gcc sort.o compute.o main.o -o example
sort.o:sort.c lib1.h
	gcc -c sort.c -o sort.o
compute.o:compute.c
	gcc -c compute.c -o compute.o
main.o:main.c lib2.h
	gcc -c main.c -o main.o
