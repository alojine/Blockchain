#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "transaction.h"
using namespace std;


class Block{
private: 
	string PrevBlockHash;
	string Timestamp;
	string Version;
	string MerkelRootHash;
	string Hash;
	string DifficultyTarget;
	vector<Transaction> Transactions;

public:
	Block() { this->Timestamp = ""; }
	void printBlock();
	void createBlock(string p, string t, string v, string m, string h, string d, vector<Transaction> T);

};
