all: a.out
a.out: main.o product.o address.o person.o transaction.o store.o credit_card.o
	g++ main.o product.o address.o person.o transaction.o store.o credit_card.o -o a.out
main.o: main.cpp product.h
	g++ -c main.cpp
product.o: product.cpp product.h
	g++ -c product.cpp				
address.o: address.cpp address.h
	g++ -c address.cpp
person.o: person.cpp person.h
	g++ -c person.cpp
transaction.o: transaction.cpp transaction.h
	g++ -c transaction.cpp
store.o: store.cpp store.h
	g++ -c store.cpp
credit_card.o: credit_card.cpp credit_card.h
	g++ -c credit_card.cpp