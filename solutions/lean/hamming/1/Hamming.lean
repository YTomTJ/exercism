namespace Hamming

def distance (strand1 : String) (strand2 : String) : Option Nat :=
  if strand1.length == strand2.length then
    some ((strand1.toList.zip strand2.toList).countP (fun (a, b) => a != b))
  else
    none

end Hamming
