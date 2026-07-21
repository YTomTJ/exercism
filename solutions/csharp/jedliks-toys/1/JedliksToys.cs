class RemoteControlCar
{
    public static RemoteControlCar Buy()
    {
        return new RemoteControlCar();
    }

    public string DistanceDisplay()
    {
        return $"Driven {this.Distance} meters";
    }

    public string BatteryDisplay()
    {
        if (this.Battery > 0) {
            return $"Battery at {this.Battery}%";
        }
        return "Battery empty";
    }

    public void Drive()
    {
        if (this.Battery > 0) {
            this.Distance += 20;
            this.Battery -= 1;
        }
    }

    private int Battery = 100;
    private int Distance = 0;
}
