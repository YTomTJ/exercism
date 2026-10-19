namespace ArmstrongNumbers

def isArmstrongNumber (number : Nat) : Bool :=
  let digits := (Nat.toDigits 10 number).map (fun c => c.toNat - '0'.toNat)
  (List.map (fun d => Nat.pow d digits.length) digits).sum == number

end ArmstrongNumbers
