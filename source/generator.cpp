#include "generator.h"

int Generator::generateInt(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(mt);
}

std::vector <int> Generator::generateRandomNumbers(int n) {
    std::vector <int> numbers;

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    std::shuffle(begin(numbers), end(numbers), e);

    return numbers;
};