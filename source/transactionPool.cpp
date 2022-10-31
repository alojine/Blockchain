#include "transactionPool.h"
#include "userPool.h"
#include "hash.h"
#include "generator.h"

vector<Transaction> TransactionPool::getTransactionPool() {
	return this->Transactions;
}

void TransactionPool::generateTransactionPool(UserPool UserPool) {

	Transaction Transaction;
	vector<User> Users = UserPool.getUserPool();

	for (size_t i = 0; i < TRANSACTION_AMOUNT; i++) {
		Generator g;

		int sender_index = g.generateInt(1, USERS);
		int receiver_index = g.generateInt(1, USERS);
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