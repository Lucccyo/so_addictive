let add x y = x + y
let dooble x = x * 2

let _ = Callback.register "ocaml_add" add
let _ = Callback.register "ocaml_dooble" dooble

