#Transaction.o Block.o
ofiles = main.o Crypto.o Wallet.o sha1.o
gpp_o = g++ -c -std=c++11 -static -Wall -Werror=pedantic

main: $(ofiles)
	g++ -std=c++11 -static $(ofiles) -o main

main.o: main.cpp Crypto.h Wallet.h sha1.hpp
	$(gpp_o) main.cpp

#Transaction.o: Transaction.cpp Transaction.h
#	$(gpp_o) Transaction.cpp

#Block.o: Block.cpp Block.h
#	$(gpp_o) Block.cpp

sha1.o: sha1.cpp sha1.hpp
	$(gpp_o) sha1.cpp

Crypto.o: Crypto.cpp Crypto.h
	$(gpp_o) Crypto.cpp

Wallet.o: Wallet.cpp Wallet.h
	$(gpp_o) Wallet.cpp

run: main
	./main

clean:
	rm *.o main