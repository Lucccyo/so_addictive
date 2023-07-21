#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>



int sum(int x, int y){
  static const value * closure_sum = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_sum);
  if (closure_sum == NULL) {
    closure_sum = caml_named_value("ocaml_sum");
  }
  ocaml_res_sum = caml_callback2(*closure_sum, Val_int(x), Val_int(y));
  CAMLreturn(ocaml_res_sum);
}

int main(int argc, char **argv) {
  caml_startup(argv);
  int x = 3;
  int y = 7;
  printf("x = %d\ty = %d\n", x, y);
  int z = sum(x, y);
  printf("x + y by OCaml = %d\n", z);
  return 0;
}
