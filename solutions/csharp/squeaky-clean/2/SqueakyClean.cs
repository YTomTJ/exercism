public static class Identifier
{
    public static string Clean(string identifier)
    {
        bool upper = false;
        return string.Concat(identifier.Select(x => {
            if (x == ' ') return "_";
            if (char.IsControl(x)) return "CTRL";
            if (x == '-') {
                upper = true;
                return string.Empty;
            }
            if (!char.IsLetter(x)) return string.Empty;
            if (x >= 'α' && x <= 'ω') return string.Empty;
            if (upper) {
                Console.WriteLine($"UPPER: {x}");
                x = char.ToUpper(x);
                upper = false;
            }
            return x.ToString();
        }));
    }
}
