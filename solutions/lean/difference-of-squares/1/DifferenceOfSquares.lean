namespace DifferenceOfSquares

def squareOfSum (number : Nat) : Nat :=
  (List.range' 1 number).sum ^ 2

def sumOfSquares (number : Nat) : Nat :=
  ((List.range' 1 number).map (fun x => x ^ 2)).sum

def differenceOfSquares (number : Nat) : Nat :=
  (squareOfSum number) - (sumOfSquares number)

end DifferenceOfSquares
