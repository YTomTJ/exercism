public class Player
{
    public int RollDie()
    {
        return (int)(Random.Shared.NextInt64() % 18 + 1);
    }

    public double GenerateSpellStrength()
    {
        return Random.Shared.NextDouble() * 100;
    }
}
