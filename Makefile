all:
	gcc -c -Wall include/*.h
	gcc -c -Wall *.c -I include
	gcc -o SIG-HOTEL *.o
clean:
	rm -rf *.gch *.o SIG-HOTEL 
run:
	./SIG-HOTEL