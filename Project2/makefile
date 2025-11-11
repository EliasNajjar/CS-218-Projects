Project2 : PA2.o card.o deck.o rank.o pokerhand.o
	g++ PA2.o card.o deck.o rank.o pokerhand.o -o Project2
testPA2 : testPA2.o card.o deck.o rank.o pokerhand.o
	g++ testPA2.o card.o deck.o rank.o pokerhand.o -o testPA2
PA2.o : PA2.cpp
	g++ -c PA2.cpp
testPA2.o : testPA2.cpp
	g++ -c testPA2.cpp
card.o : card.cpp
	g++ -c card.cpp
deck.o : deck.cpp
	g++ -c deck.cpp
rank.o : rank.cpp
	g++ -c rank.cpp
pokerhand.o : pokerhand.cpp
	g++ -c pokerhand.cpp
clean :
	rm -i *.o testPA2 Project2
