using System.Reflection;

public enum AccountType
{
    Guest,
    User,
    Moderator,
}

public enum Permission
{
    None = 0,
    Read = 1,
    Write = 2,
    Delete = 4,
    ReadWrite = Read | Write,
    All = Read | Write | Delete,
}

static class Permissions
{
    public static Permission Default(AccountType accountType)
    {
        return accountType switch {
            AccountType.Guest => Permission.Read,
            AccountType.User => Permission.Read | Permission.Write,
            AccountType.Moderator => Permission.All,
            _ => default,
        };
    }

    public static Permission Grant(Permission current, Permission grant)
    {
        var a = current;
        a |= grant;
        return a;
    }

    public static Permission Revoke(Permission current, Permission revoke)
    {
        var a = current;
        a &= ~revoke;
        return a;
    }

    public static bool Check(Permission current, Permission check) => (current & check) == check;
}
