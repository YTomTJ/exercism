public static class CentralBank
{
    public static string DisplayDenomination(long @base, long multiplier)
    {
        if (long.MaxValue / multiplier < @base) {
            return "*** Too Big ***";
        }
        return (@base * multiplier).ToString();
    }

    public static string DisplayGDP(float @base, float multiplier)
    {
        if (float.MaxValue / multiplier < @base) {
            return "*** Too Big ***";
        }
        return (@base * multiplier).ToString();
    }

    public static string DisplayChiefEconomistSalary(decimal salaryBase, decimal multiplier)
    {
        if (decimal.MaxValue / multiplier < salaryBase) {
            return "*** Much Too Big ***";
        }
        return (salaryBase * multiplier).ToString();
    }
}
