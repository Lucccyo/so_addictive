ASAN_F = -O1 -g -fsanitize=address -fno-omit-frame-pointer 
export OCAMLRUNPARAM=c=1,v=4095
export ASAN_OPTIONS=detect_leaks=1 

FLAGS = -Wall -Werror

switchA:
	echo "switching"
	eval $(shell opam env --switch=/home/cha/Documents/github/ocaml --set-switch)
	opam switch list

libaddition.so: addition.ml
	ocamlopt -output-complete-obj -runtime-variant=_pic  addition.ml -o $@

bla:
	echo $(shell date)

test.exe: main.c libaddition.so
	gcc ${FLAGS} -o test.exe -I $(shell ocamlopt -where) -L. -laddition main.c

run: test.exe
	LD_LIBRARY_PATH=. ./test.exe

clean:
	rm *.cm* *.o *.a libaddition.so test.exe

