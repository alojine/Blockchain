#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "transaction.h"
#include "userPool.h"
#include "user.h"
#include "sha256.h"

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
	vector<Transaction> useTransactions(vector<Transaction> BlockTransactions);
	void deleteTransactions(vector<Transaction> BlockTransactions);
	void validate(vector<Transaction> BlockTransactions);

};