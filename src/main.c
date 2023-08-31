#include <stdio.h>
#include <caml/mlvalues.h>
#include <caml/alloc.h>
#include <caml/memory.h>
#include <caml/callback.h>
#include<unistd.h>
value para (int x){
  static const value * closure_p = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_p);
  if (closure_p == NULL) {
    closure_p = caml_named_value("ocaml_para");
  }
  ocaml_res_p = caml_callback(*closure_p, Val_int(x));
  CAMLreturn(ocaml_res_p);
}







value sum_square (int x, int y){
  static const value * closure_ssquare = NULL;
  CAMLparam0();
  CAMLlocal1(ocaml_res_ssquare);
  if (closure_ssquare == NULL) {
    closure_ssquare = caml_named_value("ocaml_sum_square");
  }
  ocaml_res_ssquare = caml_callback2(*closure_ssquare, Val_int(x), Val_int(y));
  CAMLreturn(ocaml_res_ssquare);
}


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
  //int array[5];
  //array[5] = 55;
  //printf("%d\n", array[5]);
  
  //int y = 3;
  int x = 8;
  int res = Int_val(para(x));
  printf("from C : %d\n", res);
  caml_shutdown();
  fprintf (stderr, "après shutdown\n");
  sleep(2);
  return 0;
}
