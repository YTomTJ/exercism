public static class HighSchoolSweethearts
{
    public static string DisplaySingleLine(string studentA, string studentB)
    {
        var s = $"{studentA} ♡ {studentB}";
        var a = (61 - s.Length) / 2 - 1;
        return s.PadLeft(a + s.Length).PadRight(61);
    }

    public static string DisplayBanner(string studentA, string studentB)
    {
        var s = $"{studentA} +  {studentB}";
        var a = (25 - s.Length) / 2 + 1;
        var A = s.PadLeft(a + s.Length).PadRight(25);
        return
$@"     ******       ******
   **      **   **      **
 **         ** **         **
**            *            **
**                         **
**{A}**
 **                       **
   **                   **
     **               **
       **           **
         **       **
           **   **
             ***
              *";
    }

    public static string DisplayGermanExchangeStudents(string studentA
        , string studentB, DateTime start, float hours)
    {
        var culture = new System.Globalization.CultureInfo("de-DE");
        return $"{studentA} and {studentB} have been dating since {start.ToString("dd.MM.yyyy")} - that's {hours.ToString("#,##0.00", culture)} hours";
    }
}
