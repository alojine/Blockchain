#pragma once
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <chrono>

static std::random_device rd;
static std::mt19937 mt(rd());

class Generator {
public:
	int generateInt(int low, int high);
	std::vector <int> generateRandomNumbers(int n);
};