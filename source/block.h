#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include "transaction.h"
#include "hash.h"
using namespace std;


class Block{
private: 
	string PrevBlockHash;
	time_t Timestamp;
	string Version;
	string MerkelRootHash;
	string HashBlock;
	int DifficultyTarget;
	vector<Transaction> Transactions;

public:
	Block() { this->PrevBlockHash = ""; }
	void printBlock();
	void createBlock(string previous, int difficulty, vector<Transaction> T);
	string makeMerkelTreeHash(vector<Transaction> T);
	string makeBlockHash();
	void createGenesis(vector<Transaction> T);
	string getLastBlockHash();

};
