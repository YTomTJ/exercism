import Std.Data.HashMap

namespace Etl

def transform (legacy : Std.HashMap Nat (List Char)) : Std.HashMap Char Nat :=
  legacy.toList.foldl (fun map (n, chars) =>
    chars.foldl (fun map char => map.insert char.toLower n) map
  ) {}

end Etl
