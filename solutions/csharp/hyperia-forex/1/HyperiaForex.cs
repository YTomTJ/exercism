public struct CurrencyAmount
{
    private decimal amount;
    private string currency;

    public CurrencyAmount(decimal amount, string currency)
    {
        this.amount = amount;
        this.currency = currency;
    }

    public static bool operator ==(CurrencyAmount a, CurrencyAmount b)
    {
        if(a.currency != b.currency) {
            throw new ArgumentException();
        }
        return a.amount == b.amount;
    }

    public static bool operator !=(CurrencyAmount a, CurrencyAmount b) => !(a == b);

    public static bool operator >(CurrencyAmount a, CurrencyAmount b)
    {
        if(a.currency != b.currency) {
            throw new ArgumentException();
        }
        return a.amount > b.amount;
    }

    public static bool operator <(CurrencyAmount a, CurrencyAmount b)
    {
        if(a.currency != b.currency) {
            throw new ArgumentException();
        }
        return a.amount < b.amount;
    }

    public static CurrencyAmount operator +(CurrencyAmount a, CurrencyAmount b)
    {
        if(a.currency != b.currency) {
            throw new ArgumentException();
        }
        return new(a.amount + b.amount, a.currency);
    }

    public static CurrencyAmount operator -(CurrencyAmount a)
    {
        return new(- a.amount, a.currency);
    }

    public static CurrencyAmount operator -(CurrencyAmount a, CurrencyAmount b) => a + (-b);

    public static CurrencyAmount operator *(CurrencyAmount a, decimal k)
    {
        return new(a.amount * k, a.currency);
    }

    public static CurrencyAmount operator /(CurrencyAmount a, decimal k)
    {
        return new(a.amount / k, a.currency);
    }

    public static implicit operator double(CurrencyAmount a) => decimal.ToDouble(a.amount);

    public static implicit operator decimal(CurrencyAmount a) => a.amount;
}
