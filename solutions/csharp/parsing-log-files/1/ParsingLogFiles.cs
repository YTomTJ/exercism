using System.Text.RegularExpressions;

public class LogParser
{
    static HashSet<string> LevelCodes = [
        "TRC",
        "DBG",
        "INF",
        "WRN",
        "ERR",
        "FTL",
    ];

    public bool IsValidLine(string text)
    {
        var m = Regex.Match(text, @"^\[([A-Z]+)\]");
        return m.Success && LevelCodes.Contains(m.Groups[1].Value);
    }

    public string[] SplitLogLine(string text)
    {
        var matches = Regex.Matches(text, @"(<[\^*=-]+>)");
        List<string> items = new();
        int start = 0;
        if (matches is not null) {
            for (int i = 0; i < matches.Count; ++i) {
                items.Add(text.Substring(start, matches[i].Index - start));
                start = matches[i].Index + matches[i].Length;
            }
        }
        if (start <= text.Length) {
            items.Add(text.Substring(start));
        }
        return items.ToArray();
    }

    public int CountQuotedPasswords(string lines)
    {
        return lines.Split(Environment.NewLine).Where(IsValidLine).Select(line => Regex.Count(line, @"password", RegexOptions.IgnoreCase)).Sum();
    }

    public string RemoveEndOfLineText(string line)
    {
        return Regex.Replace(line, @"end-of-line\d+", string.Empty);
    }

    public string[] ListLinesWithPasswords(string[] lines)
    {
        return lines.Select(line => {
            if (IsValidLine(line)) {
                var m = Regex.Match(line, @"password\S+", RegexOptions.IgnoreCase);
                if (m.Success) {
                    return $"{m.Value}: {line}";
                }
            }
            return $"--------: {line}";
        }).ToArray();
    }
}
