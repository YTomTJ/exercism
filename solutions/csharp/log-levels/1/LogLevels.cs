using System.Text.RegularExpressions;

static class LogLine
{
    public static string Message(string logLine)
    {
        return Regex.Match(logLine, @"\[\S+\]: +(.*)").Groups[1].Value.Trim();
    }

    public static string LogLevel(string logLine)
    {
        return Regex.Match(logLine, @"\[(\S+)\]").Groups[1].Value.ToLower();
    }

    public static string Reformat(string logLine)
    {
        var m = Regex.Match(logLine, @"\[(\S+)\]: +(.*)");
        return $"{m.Groups[2].Value.Trim()} ({m.Groups[1].Value.ToLower()})";
    }
}
