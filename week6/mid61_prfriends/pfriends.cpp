#include <iostream>
#include <vector>
#include <cmath>

int checkPrime(int n);

int main(void)
{
    int L{}, R{};
    std::cin >> L >> R;
    std::vector<int> primes{};
    for (int i = L; i <= R; ++i)
    {
        if (checkPrime(i))
        {
            primes.push_back(i);
        }
    }
    int count = 0;
    for (int i = 0; i < primes.size() - 1; ++i)
    {
        if (abs(primes.at(i) - primes.at(i + 1)) == 2)
        {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

int checkPrime(int n)
{
    int status = 1;
    if (n <= 1)
    {
        return 0;
    }
    if (n <= 3)
    {
        return 1;
    }
    if (n % 2 == 0 || n % 3 == 0)
    {
        return 0;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return 0;
        }
    }
    return 1;
}