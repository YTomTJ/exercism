namespace HighScores

def latestList (scores : List Nat) : Nat :=
  scores.getLast!

def latestArray (scores : Array Nat) : Nat :=
  scores[scores.size - 1]!

def personalBestList (scores : List Nat) : Nat :=
  scores.max?.get!

def personalBestArray (scores : Array Nat) : Nat :=
  scores.max?.get!

def personalTopThreeList (scores : List Nat) : List Nat :=
  (scores.mergeSort (· > ·)).take 3

def personalTopThreeArray (scores : Array Nat) : Array Nat :=
  (scores.qsort (· > ·)).take 3

end HighScores
