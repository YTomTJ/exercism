public class Orm : IDisposable
{
    private Database database;

    public Orm(Database database)
    {
        this.database = database;
    }

    public void Write(string data)
    {
        try {
            this.database.BeginTransaction();
            this.database.Write(data);
            this.database.EndTransaction();
        }
        finally {
            this.database.Dispose();
        }
    }

    public bool WriteSafely(string data)
    {
        try {
            this.database.BeginTransaction();
            this.database.Write(data);
            this.database.EndTransaction();
            return true;
        }
        catch (InvalidOperationException) {
            return false;
        }
        finally {
            this.database.Dispose();
        }
    }

    public void Dispose()
    {
        this.database.Dispose();
    }
}
