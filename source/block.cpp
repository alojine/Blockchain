#include "block.h"

void Block::printBlock() {
	cout << "PreviousBlockHash: " << this->PrevBlockHash << endl;
	cout << "Timestamp: " << this->Timestamp << endl;
	cout << "Version: " << this->Version << endl;
	cout << "MerkelRootHash: " << this->MerkelRootHash << endl;
	cout << "Hash: " << this->Hash << endl;
	cout << "DifficultyTarget: " << this->DifficultyTarget << endl;
	cout << endl;
}

void Block::createBlock(string p, string t, string v, string m, string h, string d, vector<Transaction> T) {
	this->PrevBlockHash = p;
	this->Timestamp = t;
	this->Version = v;
	this->MerkelRootHash = m;
	this->Hash = h;
	this->DifficultyTarget = d;
	this->Transactions = T;
}