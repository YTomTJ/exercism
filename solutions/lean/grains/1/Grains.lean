namespace Grains

def grains (square : Int) : Option Nat :=
  if square < 1 || square > 64 then
    none
  else
    some (Nat.shiftLeft 1 (square - 1).toNat)

def totalGrains : Nat :=
  (Nat.shiftLeft 1 64) - 1

end Grains
