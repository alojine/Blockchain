#pragma once
#include <iostream>
#include <random>

static std::random_device rd;
static std::mt19937 mt(rd());

class Generator {
public:
	int generateInt(int low, int high);
};