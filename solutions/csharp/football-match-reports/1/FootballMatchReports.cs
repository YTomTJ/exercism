public static class PlayAnalyzer
{
    public static string AnalyzeOnField(int shirtNum)
    {
        return shirtNum switch {
            1 => "goalie",
            2 => "left back",
            3 => "center back",
            4 => "center back",
            5 => "right back",
            6 => "midfielder",
            7 => "midfielder",
            8 => "midfielder",
            9 => "left wing",
            10 => "striker",
            11 => "right wing",
            _ => "UNKNOWN",
        };
    }

    public static string AnalyzeOffField(object report)
    {
        if (report is int k) {
            return $"There are {k} supporters at the match.";
        }
        else if (report is string s) {
            return s;
        }
        else if (report is Incident i) {
            if (i is Injury ij) return $"Oh no! {ij.GetDescription()} Medics are on the field.";
            return i.GetDescription();
        }
        else if (report is Manager m) {
            return m.Club is null ? m.Name : $"{m.Name} ({m.Club})";
        }
        return string.Empty;
    }
}
