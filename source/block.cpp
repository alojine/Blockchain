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

void Block::createBlock(int nr, int difficulty, vector<Transaction> T, vector<Block> bc) {
	if (bc.size() == 0) {
		Hash hash;
		SHA256 sha256;
		this->Transactions = T;
		this->PrevBlockHash = sha256("genesisblock1");
		this->Timestamp = time(nullptr);
		this->Version = "1";
		this->DifficultyTarget = difficulty;
		this->MerkelRootHash = makeMerkelTreeHash(Transactions);
		this->HashBlock = makeBlockHash();
		this->block_number = 1;
		this->transactionAmount = this->Transactions.size();
		this->Nonce = 1;
	}
	else {
		this->Transactions = T;
		this->PrevBlockHash = bc.back().getLastBlockHash();
		this->Timestamp = time(nullptr);
		this->Version = "1";
		this->DifficultyTarget = difficulty;
		this->MerkelRootHash = makeMerkelTreeHash(Transactions);
		this->HashBlock = makeBlockHash();
		this->block_number = nr + 1;
		this->transactionAmount = this->Transactions.size();
	}
	
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

	string refactoredHash;
	refactoredHash.append(this->DifficultyTarget, '0');
	
	
	int attempts = 200000000;
	for (int i = 0; i < attempts; i++) {

		// increasing nonce
		nonce++;

		// guessing hash
		stringstream stream; SHA256 sha256;
		stream << this->PrevBlockHash << this->Timestamp << this->Version << this->MerkelRootHash << this->Version << this->DifficultyTarget << nonce;
		guess = sha256(stream.str());

		if (guess.substr(0, this->DifficultyTarget) == refactoredHash) {

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

	Merkel Merkel(T);
	return Merkel.getMerkelHash();

}

string Block::makeBlockHash() {
	stringstream stream;
	Hash hash;
	SHA256 sha256;
	stream << this->PrevBlockHash << this->Timestamp << this->Version << this->MerkelRootHash << this->Version << this->DifficultyTarget;
	return sha256(stream.str());
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