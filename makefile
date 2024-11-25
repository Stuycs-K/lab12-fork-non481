.PHONY: run clean compile
run: prog
	@./prog
clean:
	rm -f *.o prog
compile prog: main.o
	@gcc -o prog main.o
main.o: main.c
	@gcc -c main.c
