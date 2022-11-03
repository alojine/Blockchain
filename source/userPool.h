#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "user.h"
#include "transaction.h"

using namespace std;

const int USERS = 1000;
const int MIN_BALANCE = 100;
const int MAX_BALANCE = 1000000;

class UserPool {
private:
	vector<User> Users;

public:
	vector<User> getUserPool();
	void generateUserPool();
	void printUserPool();
	void clearPool();
	int getUserIndex(string name, vector<User> U);
	void updateUsers(vector<Transaction> BlockTransactions);
};