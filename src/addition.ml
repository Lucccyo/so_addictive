let addition x y = x + y 

let d = ref None

let join _ = 
  (match !d with
  | None -> assert false
  | Some d -> Domain.join d); 2 


let sum_square x y = 
  let square n = n * n in
  (*let d = Domain.spawn (fun _ -> print_endline "bonjour") in
  let sy = square y in
  let sx = Domain.join d in
  let sx = 4 in
  Printf.printf "from OCaml : sx = %d, sy = %d\n%!" sx sy;*)
  y + x


let pascal l =
  Format.printf "bla\n%!";
  match l with
  | [] -> [1]
  | _  -> List.map2 (+) (List.append [0] l) (List.append l [0])

let rec infinit_pascal l = infinit_pascal (pascal l)

let spawn _ =
  d := Some (Domain.spawn (fun _ -> Unix.sleep(5)));
  (*sleep*) 
  1
  







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
let _ = Callback.register "ocaml_join" join
let _ = Callback.register "ocaml_spawn" spawn
let _ = Callback.register "ocaml_sum_square" sum_square
(*let _ = Callback.register "ocaml_sum_two_list" sum_two_list
let _ = Callback.register "ocaml_add_to_list" add_to_list
let _ = Callback.register "ocaml_sum_list" sum_list*)

