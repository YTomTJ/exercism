using System.Runtime.InteropServices;

public enum Location
{
    NewYork,
    London,
    Paris
}

public enum AlertLevel
{
    Early,
    Standard,
    Late
}

public static class Appointment
{
    static readonly Dictionary<Location, string> TimeZoneIds_Win = new()
    {
        { Location.NewYork, "Eastern Standard Time" },
        { Location.London, "GMT Standard Time" },
        { Location.Paris, "Romance Standard Time" },
    };

    static readonly Dictionary<Location, string> TimeZoneIds_Mac = new()
    {
        { Location.NewYork, "America/New_York" },
        { Location.London, "Europe/London" },
        { Location.Paris, "Europe/Paris" },
    };

    static readonly Dictionary<Location, string> TimeFormats = new()
    {
        { Location.NewYork, "MM/dd/yyyy HH:mm:ss"   },
        { Location.London, "dd/MM/yyyy HH:mm:ss"    },
        { Location.Paris, "dd/MM/yyyy HH:mm:ss"     },
    };

    static TimeZoneInfo GetTimeZoneInfo(Location location)
    {
        TimeZoneInfo timeZone;
        if (RuntimeInformation.IsOSPlatform(OSPlatform.Windows)) {
            timeZone = TimeZoneInfo.FindSystemTimeZoneById(TimeZoneIds_Win[location]);
        }
        else {
            timeZone = TimeZoneInfo.FindSystemTimeZoneById(TimeZoneIds_Mac[location]);
        }
        return timeZone;
    }

    public static DateTime ShowLocalTime(DateTime dtUtc)
    {
        return dtUtc.ToLocalTime();
    }

    public static DateTime Schedule(string appointmentDateDescription, Location location)
    {
        var dateTime = DateTime.Parse(appointmentDateDescription);
        return TimeZoneInfo.ConvertTimeToUtc(dateTime, GetTimeZoneInfo(location));

    }

    public static DateTime GetAlertTime(DateTime appointment, AlertLevel alertLevel)
    {
        TimeSpan dt = alertLevel switch {
            AlertLevel.Early => TimeSpan.FromDays(1),
            AlertLevel.Standard => TimeSpan.FromHours(1) + TimeSpan.FromMinutes(45),
            AlertLevel.Late => TimeSpan.FromMinutes(30),
            _ => new()
        };
        return appointment - dt;
    }

    public static bool HasDaylightSavingChanged(DateTime dt, Location location)
    {
        var timeZone = GetTimeZoneInfo(location);
        DateTime t1 = dt - TimeSpan.FromDays(7);
        return timeZone.IsDaylightSavingTime(t1) != timeZone.IsDaylightSavingTime(dt);
    }

    public static DateTime NormalizeDateTime(string dtStr, Location location)
    {
        if (!DateTime.TryParseExact(dtStr, TimeFormats[location], null, default, out var dateTime)) {
            return DateTime.MinValue;
        }
        return dateTime;
    }
}
