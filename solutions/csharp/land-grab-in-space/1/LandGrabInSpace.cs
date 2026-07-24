public struct Coord
{
    public Coord(ushort x, ushort y)
    {
        X = x;
        Y = y;
    }

    public ushort X { get; }
    public ushort Y { get; }

    public override string ToString()
    {
        return $"{X}, {Y}";
    }
}

public struct Plot
{
    public Coord[] Coords { get; }

    public Plot(Coord a, Coord b, Coord c, Coord d)
    {
        this.Coords = [a, b, c, d];
    }

    public override string ToString()
    {
        return string.Join(", ", Coords.Select(c => c.ToString()));
    }

    public double Side
    {
        get {
            double side = 0;
            for (int i = 0; i < Coords.Length; i++) {
                var a = Coords[i];
                var b = Coords[(i + 1) % Coords.Length];
                var x = b.X - a.X;
                var y = b.Y - a.Y;
                side += double.Sqrt(x * x + y * y);
            }
            return side;
        }
    }

    public static bool operator ==(Plot a, Plot b)
    {
        for (int i = 0; i < a.Coords.Length; ++i) {
            if (a.Coords[i].X != b.Coords[i].X || a.Coords[i].Y != b.Coords[i].Y) {
                return false;
            }
        }
        return true;
    }

    public static bool operator !=(Plot a, Plot b)
    {
        return !(a == b);
    }
}


public class ClaimsHandler
{
    public List<Plot> ClaimedPlots = new();

    public void StakeClaim(Plot plot)
    {
        ClaimedPlots.Add(plot);
    }

    public bool IsClaimStaked(Plot plot)
    {
        return ClaimedPlots.Any(x => x == plot);
    }

    public bool IsLastClaim(Plot plot)
    {
        return ClaimedPlots.Count > 0 && ClaimedPlots.Last() == plot;
    }

    public Plot GetClaimWithLongestSide()
    {
        return ClaimedPlots.MaxBy(x => x.Side);
    }
}
