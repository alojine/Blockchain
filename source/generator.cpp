#include "generator.h"

int Generator::generateInt(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(mt);
}