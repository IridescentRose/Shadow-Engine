.PHONY: all build_libs build_game clean_game clean_all clean

all: build_game
clean_all: clean_game
clean: clean_game

build_lib:
	make -f MakefileLib
	
build_game:
	make -f MakefileLib all
	
clean_game:
	make -f MakefileLib clean
