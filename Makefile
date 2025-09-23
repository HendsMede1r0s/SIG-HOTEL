all:
	gcc -c -Wall include/*.h
	gcc -c -Wall *.c -I include
	gcc -o SIG-HOTEL *.o
#compila o código
clean:
	rm -rf *.gch *.o SIG-HOTEL
#limpa os residuos aṕos ser usado *só funciona em linux*
run:
	./SIG-HOTEL
#executa o código