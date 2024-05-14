#include "eratosthenes.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    int* a = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        a[i] = i;
    for (int p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            if (a[p] == 2) primes.push_back(2);
            else primes.push_back(a[p]);
            for (int j = p * p; j < n + 1; j += p)
                a[j] = 0;
        }
    }
    return primes;
}
