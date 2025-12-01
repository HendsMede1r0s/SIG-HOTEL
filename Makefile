all:
	gcc -c -Wall include/*.h
	gcc -c -Wall *.c -I include object/*.c
	gcc -o SIG-HOTEL *.o
#compila o código
clean:
	rm  *.o *.gch SIG-HOTEL ./include/*.gch || del *.o *.gch SIG-HOTEL ./include/*.gch
#limpa os residuos aṕos ser usado *só funciona em linux*
run:
	./SIG-HOTEL
#executa o código