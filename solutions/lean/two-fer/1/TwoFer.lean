namespace TwoFer

def twoFer (name : Option String) : String :=
  match name with
  | some Person => s!"One for {Person}, one for me."
  | none => "One for you, one for me."

end TwoFer
