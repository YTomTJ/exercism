import Std.Data.HashSet

namespace Isogram

def isIsogram (phrase : String) : Bool :=
  let arr1 := (phrase.toList.filter (fun c => c.isAlpha)).map Char.toLower
  arr1.length == (List.eraseDups arr1).length

end Isogram
