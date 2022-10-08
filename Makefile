filename := app
builddir := build

all: build-dir compile link run

compile:
	 g++ -I"C:/sfml/include" -c "./src/main.cpp" -o "./build/$(filename).o"
link:
	 g++ -I"C:/sfml/lib" "./$(builddir)/$(filename).o" -o "./$(builddir)/$(filename).exe" -lmingw32 -lsfml-graphics -lsfml-window -lsfml-system -lsfml-main -lsfml-audio -mwindows
run:
	"./$(builddir)/$(filename).exe"

clean: clean-exe clean-o

clean-exe:
	rm -f main ./$(builddir)/*.exe

clean-o:
	rm -f main  ./$(builddir)/*.o

build-dir:
	[ -d $(builddir) ] ||mkdir -p $(builddir) 