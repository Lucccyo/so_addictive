let addition x y = x + y 

let id x = x 
(*x + y

let rec sum_two_list la lb =
  match la with
  | [] -> lb
  | hda :: tla ->
    match lb with
    | [] -> la
    | hdb :: tlb -> (hda + hdb) :: sum_two_list tla tlb

let rec add_to_list l n =
  match l with
  | [] -> []
  | hd :: tl -> hd + n :: add_to_list tl n

let rec sum_list l =
  match l with
  | [] -> 0
  | hd :: tl -> hd + sum_list tl*)

let _ = Callback.register "ocaml_addition" addition
let _ = Callback.register "ocaml_identity" id
(*let _ = Callback.register "ocaml_sum_two_list" sum_two_list
let _ = Callback.register "ocaml_add_to_list" add_to_list
let _ = Callback.register "ocaml_sum_list" sum_list*)

