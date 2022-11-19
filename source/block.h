#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.h"
#include "hash.h"
#include "merkel.h"
#include "sha256.h"

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
	int transactionAmount;
	vector<Transaction> Transactions;
	int Nonce;
	bool Mined = false;

public:
	Block() { this->PrevBlockHash = ""; }
	void printBlock();
	void printBlockTransactions();

	void createBlock(int nr, int difficulty, vector<Transaction> T, vector<Block> bc);
	void createGenesis(vector<Transaction> T, int difficulty);
	void mine();

	string makeMerkelTreeHash(vector<Transaction> T);
	string makeBlockHash();
	
	string getLastBlockHash();
	string getBlockHash();
	int getBlockNumber();
	bool mined();
};
