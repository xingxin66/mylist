main.o:main.c
	gcc main.c -c
fun.o:fun.c
	gcc fun.c -c
fun1.o:fun1.c
	gcc fun1.c -c
proj1:main.o fun.o fun1.o
	gcc main.o fun.o fun1.o
clean:
	rm -f *.o
