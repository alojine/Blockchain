#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.h"
#include "hash.h"
#include "merkel.h"

using namespace std;


class Block{
private: 
	string PrevBlockHash;
	time_t Timestamp;
	string Version;
	string MerkelRootHash;
	string HashBlock;
	int DifficultyTarget;
	int block_number;
	vector<Transaction> Transactions;

public:
	Block() { this->PrevBlockHash = ""; }
	void printBlock();
	void printBlockTransactions();

	void createBlock(string previous, int difficulty, vector<Transaction> T, int nr);
	void createGenesis(vector<Transaction> T);

	string makeMerkelTreeHash(vector<Transaction> T);
	string makeBlockHash();
	
	string getLastBlockHash();
	string getBlockHash();
	int getBlockNumber();
};
