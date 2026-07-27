#include "sieve.h"

namespace sieve
{
    std::vector<int> primes(int n)
    {
        std::vector<int> p;
        std::vector<bool> composite(n + 1, false);

        for (int i = 2; i <= n; i++)
        {
            if (!composite[i])
            {
                p.push_back(i);
                int k = i;
                while (k <= n)
                {
                    composite[k] = true;
                    k += i;
                }
            }
        }
        return p;
    }

} // namespace sieve
