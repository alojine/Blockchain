#include "block.h"

void Block::printBlock() {
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(20) << "Block number: " << this->block_number << endl;
	cout << left << setw(20) << "PreviousBlockHash: " << this->PrevBlockHash << endl;
	cout << left << setw(20) << "Timestamp: " << this->Timestamp << endl;
	cout << left << setw(20) << "Version: " << this->Version << endl;
	cout << left << setw(20) << "MerkelRootHash: " << this->MerkelRootHash << endl;
	cout << left << setw(20) << "Hash: " << this->HashBlock << endl;
	cout << left << setw(20) << "DifficultyTarget: " << this->DifficultyTarget << endl;
	cout << left << setw(20) << "TransactionAmount: " << this->transactionAmount << endl;
	cout << left << setw(20) << "Nonce: " << long(this->Nonce) << endl;
	cout << "------------------------------------------------------------------------------------------------------------------" << endl;
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
	this->transactionAmount = this->Transactions.size();
}

void Block::createGenesis(vector<Transaction> T, int difficulty) {
	Hash hash;
	this->Transactions = T;
	this->PrevBlockHash = hash.makeHash("genesisBlock");
	this->Timestamp = time(nullptr);
	this->Version = "1";
	this->DifficultyTarget = difficulty;
	this->MerkelRootHash = makeMerkelTreeHash(Transactions);
	this->HashBlock = makeBlockHash();
	this->block_number = 1;
	this->transactionAmount = this->Transactions.size();
	this->Nonce = 1;
}

void Block::mine() {


	int nonce = 0;
	bool Mined = false;
	string guess = makeBlockHash();
	string hashCopy = this->getBlockHash();

	string refactoredHash = this->HashBlock;
	for (int i = 0; i < this->DifficultyTarget; i++) {
		refactoredHash.at(i) = '0';
	}
	
	// kasamas tol kol iskasamas
	/*
	while (!Mined) {
		if (guess != refactoredHash) {
			nonce++;

			stringstream stream;
			stream << this->PrevBlockHash << this->Timestamp << this->Version <<  this->MerkelRootHash << this->Version << this->DifficultyTarget << nonce;
			
			// Using my own hash
			// Hash h;
			//guess = h.makeHash(stream.str());
			
			// using sha256
			SHA256 h;
			guess = h(stream.str());

			for (int i = 0; i < this->DifficultyTarget; i++) {
				guess.at(i) = '0';
			}
		}
		else {
			Mined = true;
			this->Nonce = nonce;
			this->HashBlock = guess;
			cout << "Block mined!" << endl;
		}
	}
	*/
	int attempts = 2000000;
	for (int i = 0; i < attempts; i++) {
		nonce++;
		stringstream stream;
		stream << this->PrevBlockHash << this->Timestamp << this->Version << this->MerkelRootHash << this->Version << this->DifficultyTarget << nonce;
		SHA256 h;
		guess = h(stream.str());

		for (int i = 0; i < this->DifficultyTarget; i++) {
			guess.at(i) = '0';
		}

		if (guess == refactoredHash) {

			this->Nonce = nonce;
			this->HashBlock = guess;
			this->Mined = true;
			cout << "Block mined!" << endl;
			break;
		}
	}

	if (nonce == attempts)
		cout << "Isandyti visi hashai" << endl;

}

string Block::makeMerkelTreeHash(vector<Transaction> T) {
	/*
	stringstream stream;
	Hash hash;
	for (auto s : T) {
		stream << s.getTransactionId();
	}
	return hash.makeHash(stream.str());
	*/

	Merkel Merkel(T);
	return Merkel.getMerkelHash();

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

bool Block::mined() {
	return this->Mined;
}
