#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
//#include <random>
#include "transaction.h"
#include "userPool.h"

using namespace std;

const int TRANSACTION_AMOUNT = 10000;

class TransactionPool {
private:
	vector<Transaction> Transactions;

public:
	void generateTransactionPool(UserPool UserPool);
	void printTransactionPool();
	vector<Transaction> getTransactionPool();
	void clearPool();

};