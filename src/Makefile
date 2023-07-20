libaddition.so: addition.ml
	ocamlopt -output-complete-obj -runtime-variant=_pic  addition.ml -o libaddition.so

test.exe: main.c libaddition.so
	gcc -o test.exe -I/home/cha/.opam/default/lib/ocaml -L. -laddition  main.c

run: test.exe
	LD_LIBRARY_PATH=. ./test.exe

clean:
	rm *.cm* *.o libaddition.so test.exe
