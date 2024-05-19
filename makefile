
all:
	make objects lib223 cs223
objects:
	gcc -c SignUp.c -o SignUp.o
	gcc -c CreateGame.c -o CreateGame.o
	gcc -c login.c -o login.o
	gcc -c MainMenu.c -o MainMenu.o
	gcc -c list.c -o list.o
	gcc -c JoinGame.c -o JoinGame.o
	gcc -c LoginAfterReg.c -o LoginAfterReg.o
	gcc -c scorefun.c -o scorefun.o
	gcc -c changscore.c -o changscore.o
	gcc -c timep.c -o timep.o

lib223: objects
	ar rs lib223.a SignUp.o CreateGame.o login.o MainMenu.o list.o JoinGame.o LoginAfterReg.o scorefun.o changscore.o timep.o

cs223: objects lib223
	gcc FrontPage.c lib223.a -o cs223

clean:
	rm -f *.o lib223.a cs223
	


