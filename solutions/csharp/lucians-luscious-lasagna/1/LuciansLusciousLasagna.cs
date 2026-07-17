class Lasagna
{
    private int Expected = 40;
    
    public int ExpectedMinutesInOven()
    {
        return this.Expected;
    }

    public int RemainingMinutesInOven(int take)
    {
        return this.Expected - take;
    }

    public int PreparationTimeInMinutes(int layers)
    {
        return layers * 2;
    }

    public int ElapsedTimeInMinutes(int layers , int minutes)
    {
        return minutes + PreparationTimeInMinutes(layers);
    }
}
