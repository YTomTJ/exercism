public static class LogAnalysis
{
    public static string SubstringAfter(this string str, string after)
    {
        return str.Substring(str.IndexOf(after) + after.Length);
    }

    public static string SubstringBetween(this string str, string a, string b)
    {
        var x = str.IndexOf(a) + a.Length;
        var y = str.IndexOf(b);
        return str.Substring(x, y - x).Trim();
    }

    public static string Message(this string str)
    {
        return str.SubstringAfter("]:").Trim();
    }

    public static string LogLevel(this string str)
    {
        return str.SubstringBetween("[", "]");
    }
}