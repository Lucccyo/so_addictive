#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>


value id (int x){
  static const value * closure_id = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_id);
  if (closure_id == NULL) {
    closure_id = caml_named_value("ocaml_identity");
  }
  ocaml_res_id = caml_callback(*closure_id, Val_int(x));
  CAMLreturn(ocaml_res_id);
}

value sum(int x, int y){
  static const value * closure_sum = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_sum);
  if (closure_sum == NULL) {
    closure_sum = caml_named_value("ocaml_addition");
  }
  ocaml_res_sum = caml_callback2(*closure_sum, Val_int(x), Val_int(y));
  CAMLreturn(ocaml_res_sum);
}

int main(int argc, char **argv) {
caml_startup(argv);
  int y = 3;
  int x = 8;
 //  printf("x = %d\ty = %d\n", x, y);
  // int z = sum(x, y);
  printf("%d\n", Int_val(sum(y, x)));
  // printf("x + y by OCaml = %d\n", z);
  caml_shutdown();
  return 0;
}
