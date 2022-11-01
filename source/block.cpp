#include "block.h"

void Block::printBlock() {
	cout << "PreviousBlockHash: " << this->PrevBlockHash << endl;
	cout << "Timestamp: " << this->Timestamp << endl;
	cout << "Version: " << this->Version << endl;
	cout << "MerkelRootHash: " << this->MerkelRootHash << endl;
	cout << "Hash: " << this->HashBlock << endl;
	cout << "DifficultyTarget: " << this->DifficultyTarget << endl;
	cout << endl;
}

void Block::createBlock(string previous, int difficulty, vector<Transaction> T) {
	this->Transactions = T;
	this->PrevBlockHash = previous;
	this->Timestamp = time(nullptr);
	this->Version = "1";
	this->DifficultyTarget = difficulty;
	this->MerkelRootHash = makeMerkelTreeHash(Transactions);
	this->HashBlock = makeBlockHash();
}

void Block::createGenesis(vector<Transaction> T) {
	Hash hash;
	this->Transactions = T;
	this->PrevBlockHash = hash.makeHash("genesisBlock");
	this->Timestamp = time(nullptr);
	this->Version = "1";
	this->DifficultyTarget = 0;
	this->MerkelRootHash = makeMerkelTreeHash(Transactions);
	this->HashBlock = makeBlockHash();
}

string Block::makeMerkelTreeHash(vector<Transaction> T) {
	stringstream stream;
	Hash hash;
	for (auto s : T) {
		stream << s.getTransactionId();
	}
	return hash.makeHash(stream.str());
}

string Block::makeBlockHash() {
	stringstream stream;
	Hash hash;
	stream << this->PrevBlockHash << this->Timestamp << this->Version << this->MerkelRootHash << this->Version << this->DifficultyTarget;
	return hash.makeHash(stream.str());
}

string Block::getLastBlockHash() {
	return this->HashBlock;
}