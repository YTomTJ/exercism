abstract class Character
{
    readonly string CharacterType;

    protected Character(string characterType)
    {
        this.CharacterType = characterType;
    }

    public abstract int DamagePoints(Character target);

    public virtual bool Vulnerable()
    {
        return false;
    }

    public override string ToString()
    {
        return $"Character is a {CharacterType}";
    }
}

class Warrior : Character
{
    public Warrior() : base("Warrior")
    {
    }

    public override int DamagePoints(Character target)
    {
        return target.Vulnerable() ? 10 : 6;
    }
}

class Wizard : Character
{
    private bool Spelled = false;

    public Wizard() : base("Wizard")
    {
    }

    public override int DamagePoints(Character target)
    {
        return target.Vulnerable() ? 3 : 12;
    }

    public void PrepareSpell()
    {
        this.Spelled = true;
    }

    public override bool Vulnerable()
    {
        return !this.Spelled;
    }
}
