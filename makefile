run: exec
		./exec file.log
exec: main.cpp AiBot.cpp Game.cpp		
	g++ -g AiBot.cpp Game.cpp main.cpp -std=c++11 -lpthread -D_REENTRANT -o exec

