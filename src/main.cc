// 
// Calculates primes between 1 and x using the Sieve of Eratosthenes algorithm.
//

#include <iostream>
#include <vector>
#include <chrono>

// #define PRINT

int main() {
    int x;
    std::cout << "Enter a number: ";
    std::cin >> x;

    auto start = std::chrono::high_resolution_clock::now();

    std::vector<bool> primes(x + 1, true);
    primes[0] = primes[1] = false;

    for (int i = 2; i * i <= x; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= x; j += (i > 2 ? 2 * i : i)) {
                primes[j] = false;
            }
        }
    }

    std::vector<int> prime_numbers;
    for (int i = 2; i <= x; i++) {
        if (primes[i]) {
            prime_numbers.push_back(i);
        }
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time: " << duration.count() << "s" << std::endl;

    #ifdef PRINT
    for (const auto &prime: prime_numbers) {
        std::cout << prime << " ";
    }
    std::cout << std::endl;
    #endif

    return 0;
}