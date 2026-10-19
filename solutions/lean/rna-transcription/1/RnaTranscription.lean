namespace RnaTranscription

def complement (c : Char) : Char :=
  match c with
  | 'C' => 'G'
  | 'G' => 'C'
  | 'T' => 'A'
  | 'A' => 'U'
  | _ => '₀'

def toRna (dna : String) : String :=
  dna.map complement

end RnaTranscription
