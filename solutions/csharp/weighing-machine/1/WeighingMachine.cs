class WeighingMachine
{
    public int Precision { get; }

    public double Weight
    {
        get => _Weight;
        set {
            if(value < 0) {
                throw new ArgumentOutOfRangeException();
            }
            _Weight = value;
        }
    }
    private double _Weight;

    public double TareAdjustment { get; set; }

    public string DisplayWeight => $"{(Weight - TareAdjustment).ToString($"N{Precision}")} kg";

    public WeighingMachine(int precision)
    {
        this.Precision = precision;
        this.TareAdjustment = 5;
    }
}
