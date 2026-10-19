namespace Acronym

def convert (c: Char) : Char :=
  if c.isAlpha then c
  else if c == '\'' then '₀'
  else ' '

def abbreviate (phrase : String) : String :=
  let words := String.splitOn (phrase.map convert) " "
  String.join (words.map (fun s => (s.take 1).toString.toUpper))

end Acronym
