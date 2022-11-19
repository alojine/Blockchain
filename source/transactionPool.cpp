#include "transactionPool.h"
#include "userPool.h"
#include "hash.h"
#include "generator.h"

vector<Transaction> TransactionPool::getTransactionPool() {
	return this->Transactions;
}

void TransactionPool::generateTransactionPool(UserPool UserPool) {

	this->Transactions.reserve(10000);
	Transaction Transaction;
	vector<User> Users = UserPool.getUserPool();

	for (size_t i = 1; i <= TRANSACTION_AMOUNT; i++) {
		Generator g;

		int sender_index = g.generateInt(1, USERS - 1);
		int receiver_index = g.generateInt(1, USERS - 1);
		int amount_balance = g.generateInt(1, 10000);

		// Validate transaction
		if (Users.at(sender_index).getBalance() > amount_balance) {

			Transaction.createTransaction(Users.at(sender_index).getUserName(),
				Users.at(receiver_index).getUserName(),
				amount_balance);

			Transactions.push_back(Transaction);
		}
	}

}

void TransactionPool::printTransactionPool() {

	for (auto a : this->Transactions) {
		cout << "TransactionId: " << a.getTransactionId() << endl;
		cout << "Sender: " << a.getSender() << endl;
		cout << "Receiver: " << a.getReceiver() << endl;
		cout << "Amount: " << a.getAmount() << endl;
		cout << endl;
	}

}

void TransactionPool::clearPool() {
	this->Transactions.clear();
}

vector<Transaction> TransactionPool::useTransactions(vector<Transaction> BlockTransactions) {
	
	for (int i = 0; i < this->Transactions.size(); i++){
		for (auto b : BlockTransactions) {

			if (Transactions.at(i).getTransactionId() == b.getTransactionId()) {
				swap(Transactions.at(i), Transactions.back());
				Transactions.pop_back();
			}
		}
	}
	
}

void TransactionPool::deleteTransactions(vector<Transaction> BlockTransactions) {


	for (int i = 1; i <= BlockTransactions.size(); i++) {

		for (int j = 1; j <= this->Transactions.size(); j++) {

			if (BlockTransactions.at(i).getTransactionId() == this->Transactions.at(j).getTransactionId()) {
				swap(this->Transactions.at(j), this->Transactions.back());
				this->Transactions.pop_back();
			}

		}
	}
}

void TransactionPool::validate(vector<Transaction> BlockTransactions) {
	
	int check = 1;
	SHA256 sha256;
	for (auto t : BlockTransactions) {

		Hash h;
		if (sha256(t.getSender() + t.getReceiver() + to_string(t.getAmount())) == t.getTransactionId()) {
			check++;
		}
		/*
		for (int i = 1; i <= Transactions.size(); i++) {
			if (t.getTransactionId() == Transactions.at(i).getTransactionId()) {
				swap(Transactions.at(i), Transactions.back());
				Transactions.pop_back();
			}
		}
		*/

	}

	
	if (!(check == BlockTransactions.size()))
		cout << "Transactions validated!" << endl;
	
}