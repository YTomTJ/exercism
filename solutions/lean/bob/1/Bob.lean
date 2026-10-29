namespace Bob

def response (heyBob : String) : String :=
  let heyBob := heyBob.trimAscii.toString
  let silent := heyBob.toList.all (fun c => c.isWhitespace)
  let quest := heyBob.endsWith "?"
  let shout1 := (heyBob.toList.filter (fun c => c.isAlpha))
  let shout := shout1.length > 0 && shout1.all (fun c=> c.isUpper)

  if quest then
    if shout then
      "Calm down, I know what I'm doing!"
    else
      "Sure."
  else if shout then
      "Whoa, chill out!"
  else if silent then
    "Fine. Be that way!"
  else
    "Whatever."

end Bob
