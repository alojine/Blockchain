run: main.o hash.o app.o time.o generator.o transaction.o block.o user.o 
	g++ -o run main.o -O3

main.o: main.cpp
	g++ -c main.cpp

hash.o: source/hash.cpp
	g++ -c source/hash.cpp

user.o: source/user.cpp
	g++ -c source/user.cpp

app.o: source/app.cpp
	g++ -c source/app.cpp

time.o: source/time.cpp
	g++ -c source/time.cpp

generator.o: source/generator.cpp
	g++ -c source/generator.cpp

transaction.o: source/transaction.cpp
	g++ -c source/transaction.cpp

block.o: source/block.cpp
	g++ -c source/block.cpp



clean: del *.o run.exe