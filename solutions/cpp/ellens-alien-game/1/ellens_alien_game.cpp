namespace targets
{

    class Alien
    {
    public:
        int x_coordinate;
        int y_coordinate;

    private:
        int health = 3;

    public:
        Alien(int x, int y) : x_coordinate(x),
                              y_coordinate(y)
        {
        }

        int get_health()
        {
            return health;
        }

        bool hit()
        {
            if (health > 0)
            {
                health -= 1;
            }
            return true;
        }

        bool is_alive()
        {
            return health > 0;
        }

        bool teleport(int x, int y)
        {
            x_coordinate = x;
            y_coordinate = y;
            return true;
        }

        bool collision_detection(Alien other)
        {
            return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;
        }
    };

} // namespace targets
