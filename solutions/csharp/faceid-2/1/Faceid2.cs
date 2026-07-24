public class FacialFeatures
{
    public string EyeColor { get; }
    public decimal PhiltrumWidth { get; }

    public FacialFeatures(string eyeColor, decimal philtrumWidth)
    {
        EyeColor = eyeColor;
        PhiltrumWidth = philtrumWidth;
    }

    public override bool Equals(object? obj)
    {
        return obj is FacialFeatures other && this.EyeColor.Equals(other.EyeColor) && this.PhiltrumWidth.Equals(other.PhiltrumWidth);
    }

    public override int GetHashCode()
    {
        return HashCode.Combine(this.EyeColor.GetHashCode(), this.PhiltrumWidth.GetHashCode());
    }
}

public class Identity
{
    public string Email { get; }
    public FacialFeatures FacialFeatures { get; }

    public Identity(string email, FacialFeatures facialFeatures)
    {
        Email = email;
        FacialFeatures = facialFeatures;
    }

    public override bool Equals(object? obj)
    {
        return obj is Identity other && this.Email.Equals(other.Email) && this.FacialFeatures.Equals(other.FacialFeatures);
    }
}

public class Authenticator
{
    private Dictionary<FacialFeatures, Identity> RegisteredIdentity = new();

    private Identity Admin = new("admin@exerc.ism", new("green", 0.9m));

    public static bool AreSameFace(FacialFeatures faceA, FacialFeatures faceB) => faceA.Equals(faceB);

    public bool IsAdmin(Identity identity) => identity.Equals(Admin);

    public bool Register(Identity identity) => this.RegisteredIdentity.TryAdd(identity.FacialFeatures, identity);

    public bool IsRegistered(Identity identity) => this.RegisteredIdentity.ContainsKey(identity.FacialFeatures);

    public static bool AreSameObject(Identity identityA, Identity identityB) => identityA.GetHashCode() == identityB.GetHashCode();
}
