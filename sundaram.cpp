#include "sundaram.h"

std::vector<int> sieve(int n) {
    std::vector<int> primes;
    int size = (n - 1) / 2;
    vector<bool> marked(size + 1, false);

    for (int i = 1; i <= (size - 1) / 2; ++i) {
        for (int j = (i * (i + 1)) << 1; j <= size; j += 2 * i + 1) {
            marked[j] = true;
        }
    }

    if (n >= 2)
        primes.push_back(2);
    
    for (int i = 1; i <= size; ++i) {
        if (!marked[i])
            primes.push_back(2 * i + 1);
    }
    return primes;
}
