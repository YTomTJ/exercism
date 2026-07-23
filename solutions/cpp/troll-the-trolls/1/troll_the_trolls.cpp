namespace hellmath
{
    enum AccountStatus
    {
        troll,
        guest,
        user,
        mod,
    };

    enum Action
    {
        read,
        write,
        remove,
    };

    bool display_post(AccountStatus poster, AccountStatus reader)
    {
        if (poster == AccountStatus::troll)
            return reader == AccountStatus::troll;
        return true;
    }

    bool permission_check(Action a, AccountStatus as)
    {
        switch (a)
        {
        case Action::remove:
            return as == mod;
        case Action::write:
            return as != guest;
        case Action::read:
            return true;
        }
        return false;
    }

    bool valid_player_combination(AccountStatus user1, AccountStatus user2)
    {
        if (user1 == AccountStatus::guest || user2 == AccountStatus::guest)
            return false;

        switch (user1)
        {
        case AccountStatus::troll:
            return user2 == AccountStatus::troll;
        case AccountStatus::user:
        case AccountStatus::mod:
            return user2 != AccountStatus::troll;
        }
        return false;
    }

    bool has_priority(AccountStatus user1, AccountStatus user2)
    {
        return user1 > user2;
    }

} // namespace hellmath
