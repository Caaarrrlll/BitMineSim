ofiles = main.o Transaction.o Block.o
gpp_o = g++ -c -std=c++11 -static -Wall -Werror=pedantic

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main

main.o: main.cpp Transaction.h Block.h
	$(gpp_o) main.cpp

Transaction.o: Transaction.cpp Transaction.h
	$(gpp_o) Transaction.cpp

Block.o: Block.cpp Block.h
	$(gpp_o) Block.cpp

run: main
	./main

clean:
	rm *.o main