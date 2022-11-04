#include "block.h"

void Block::printBlock() {
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Block number: " << this->block_number << endl;
	cout << left << setw(19) << "PreviousBlockHash: " << this->PrevBlockHash << endl;
	cout << left << setw(20) << "Timestamp: " << this->Timestamp << endl;
	cout << left << setw(20) << "Version: " << this->Version << endl;
	cout << left << setw(19) << "MerkelRootHash: " << this->MerkelRootHash << endl;
	cout << left << setw(19) << "Hash:" << this->HashBlock << endl;
	cout << left << setw(20) << "DifficultyTarget: " << this->DifficultyTarget << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
}

void Block::printBlockTransactions() {
	for (auto a : this->Transactions) {
		cout << a.getTransactionId() << endl;
	}
}

void Block::createBlock(string previous, int difficulty, vector<Transaction> T, int nr) {
	this->Transactions = T;
	this->PrevBlockHash = previous;
	this->Timestamp = time(nullptr);
	this->Version = "1";
	this->DifficultyTarget = difficulty;
	this->MerkelRootHash = makeMerkelTreeHash(Transactions);
	this->HashBlock = makeBlockHash();
	this->block_number = nr + 1;
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
	this->block_number = 1;
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

string Block::getBlockHash() {
	return this->HashBlock;
}

int Block::getBlockNumber() {
	return this->block_number;
}

