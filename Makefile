filename := app
builddir := build

all: build-dir compile link run

compile:
	 g++ -IC:\sfml\include -c main.cpp -o $(builddir)\$(filename).o
link:
	 g++ -IC:\sfml\lib .\$(builddir)\$(filename).o -o $(builddir)\$(filename).exe -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -lsfml-audio -mwindows
run:
	.\$(builddir)\$(filename).exe

clean: clean-exe clean-o

clean-exe:
	rm -f main *.exe

clean-o:
	rm -f main *.o

build-dir:
	[ -d $(builddir) ] ||mkdir -p $(builddir) 