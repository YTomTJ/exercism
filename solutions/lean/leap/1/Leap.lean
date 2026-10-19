namespace Leap

def leapYear (year : UInt16) : Bool :=
  (year % 100 == 0 ∧ year % 400 == 0) ∨ (year % 4 == 0)

end Leap
