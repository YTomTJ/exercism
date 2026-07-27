#include <algorithm>
#include <cmath>
#include "prime_factors.h"

namespace prime_factors
{
    void __of(std::vector<long long> &factors, long long number)
    {
        if (PrimeHelper::IsPrime(number))
        {
            factors.push_back(number);
            return;
        }
        PrimeHelper::ExtendPrimesTo(number);
        for (auto p : PrimeHelper::Primes())
        {
            if (number % p == 0)
            {
                factors.push_back(p);
                __of(factors, number / p);
                return;
            }
        }
    }

    std::vector<long long> of(long long number)
    {
        std::vector<long long> factors;
        __of(factors, number);
        return factors;
    }
    
    int PrimeHelper::PrimeLimit = 100;
    
    std::vector<int> PrimeHelper::_Primes{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    
    int PrimeHelper::GetPrimeLimit()
    {
        return PrimeLimit;
    }
    
    const std::vector<int> &PrimeHelper::Primes()
    {
        return _Primes;
    }
    
    int PrimeHelper::EulerPhi(int n)
    {
        if (n < 0)
        {
            return 1;
        }
        if (n <= 2)
        {
            return 1;
        }
        IsPrime(n); // update prime list at least to n
        int res = n;
        for (auto p : Primes())
        {
            if (p > n)
            {
                break;
            }
            if (n % p == 0)
            {
                res = res / p * (p - 1);
            }
        }
        return res;
    }
    
    bool PrimeHelper::IsPrime(int n)
    {
        if (n < 2)
        {
            return false;
        }
        if (n > PrimeLimit)
        {
            ExtendPrimesTo(n);
        }
        return std::find(_Primes.begin(), _Primes.end(), n) != _Primes.end();
    }
    
    void PrimeHelper::ExtendPrimesTo(int limit)
    {
        auto pm = PrimeLimit;
        if (limit <= pm)
        {
            return;
        }
        // keep limit the n*2
        if (limit % 2 == 1)
            limit += 1;
        // from pm+1, pm+3, to limit
        std::vector<bool> isComposite((limit - pm) / 2);
        // mark composite by existing prime
        for (auto p : _Primes)
        {
            auto start = p * p; // primes p*(1~p) already marked
            if (start > limit)
            {
                break;
            }
            if (start <= pm)
            {
                start = ((pm / p) + 1) * p;
            }
            for (int j = start; j <= limit; j += p)
            {
                if (j % 2 == 0)
                    continue;
                isComposite[(j - pm - 1) / 2] = true;
            }
        }
        // find next prime
        int sqrtLimit = (int)std::sqrt(limit);
        for (size_t i = 0 /*pm+1*/; i < isComposite.size() /*limit*/; i++)
        {
            if (!isComposite[i])
            {
                auto p = i * 2 + pm + 1;
                _Primes.push_back(p);
                if ((int)p <= sqrtLimit)
                {
                    long start = p * p;
                    int start2 = (int)(start - pm - 1) / 2;
                    for (size_t j = start2; j < isComposite.size(); j += p)
                    {
                        isComposite[j] = true;
                    }
                }
            }
        }
        PrimeLimit = limit;
    }

    
} // namespace prime_factors
