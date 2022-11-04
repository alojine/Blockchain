#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "transaction.h"
#include "userPool.h"
#include "user.h"

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
	vector<Transaction> useTransactions(vector<Transaction> Tp, vector<Transaction> BlockTransactions, vector<User>& Users);
	void deleteTransactions(vector<Transaction> BlockTransactions);

};