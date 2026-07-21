class RemoteControlCar
{
    private readonly int Speed;
    private readonly int BatteryDrain;

    private int Distance = 0;
    private int Battery = 100;

    public RemoteControlCar(int speed, int batteryDrain)
    {
        this.Speed = speed;
        this.BatteryDrain = batteryDrain;
    }

    public bool BatteryDrained()
    {
        return this.Battery < this.BatteryDrain;
    }

    public int DistanceDriven()
    {
        return Distance;
    }

    public void Drive()
    {
        if (this.Battery >= this.BatteryDrain) {
            this.Distance += this.Speed;
            this.Battery -= this.BatteryDrain;
        }
    }

    public static RemoteControlCar Nitro()
    {
        return new RemoteControlCar(50, 4);
    }
}

class RaceTrack
{
    private readonly int Distance;

    public RaceTrack(int distance)
    {
        this.Distance = distance;
    }

    public bool TryFinishTrack(RemoteControlCar car)
    {
        while (!car.BatteryDrained()) {
            car.Drive();
        }
        return car.DistanceDriven() >= this.Distance;
    }
}
