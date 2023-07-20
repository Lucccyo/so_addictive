#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>



int add(int x, int y){
  static const value * closure_add = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_add);
  if (closure_add == NULL) {
    closure_add = caml_named_value("ocaml_add");
  }
  ocaml_res_add = caml_callback2(*closure_add, Val_int(x), Val_int(y));
  CAMLreturn(ocaml_res_add);
}

int main(int argc, char **argv) {
  caml_startup(argv);
  int x = 3;
  int y = 7;
  printf("x = %d\ty = %d\n", x, y);
  int z = add(x, y);
  printf("x + y by OCaml = %d\n", z);
  return 0;
}
