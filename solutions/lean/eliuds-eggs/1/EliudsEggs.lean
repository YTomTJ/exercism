namespace EliudsEggs

def eggCount (number : Nat) : Nat :=
  Nat.toDigits 2 number |> List.map (fun c => if c == '1' then 1 else 0) |> List.sum

end EliudsEggs
