namespace Darts

def score (x : Float) (y : Float) : Int :=
  let r2 := x * x + y * y
  if r2 > 10 * 10 then 0
  else if r2 > 5 * 5 then 1
  else if r2 > 1 * 1 then 5
  else 10

end Darts
