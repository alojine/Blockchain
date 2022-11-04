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

vector<Transaction> TransactionPool::useTransactions(vector<Transaction> Tp, vector<Transaction> BlockTransactions, vector<User>& Users) {
	
	for (int i = 0; i < BlockTransactions.size(); i++) {
		cout << "ilindo i pirma cikla" << endl;
		bool t = 0;
		User sender;
		User receiver;

		for (int j = 1; j <= Tp.size(); j++) {
			
		}
		/*
		for (int j = 1; j <= Tp.size(); j++) {
			cout << "ilindo i antra cikla" << endl;

			if (Tp.at(j).getTransactionId() == BlockTransactions.at(i).getTransactionId()) {

				int transactionToDelete = j;
				t = 1;



				for (int k = 1; k <= Users.size(); k++) {
					cout << "ilindo i trecia cikla" << endl;
					if (Users.at(k).getUserName() == BlockTransactions.at(i).getSender()) {
						sender = Users.at(k);
						s = 1;

						// Balance
						sender.setBalance(Users.at(k).getBalance() - BlockTransactions.at(i).getAmount());
						// Username
						sender.setUserName(Users.at(k).getUserName());
						// Public Key
						sender.setPublicKey(Users.at(k).getPublicKey());

						Users.at(k) = sender;
						cout << "--------------------sender found" << endl;
					}

					if (Users.at(k).getUserName() == BlockTransactions.at(i).getReceiver()) {
						receiver = Users.at(k);


						// Balance
						receiver.setBalance(Users.at(k).getBalance() + BlockTransactions.at(i).getAmount());
						// Username
						receiver.setUserName(Users.at(k).getUserName());
						// Public Key
						receiver.setPublicKey(Users.at(k).getPublicKey());

						Users.at(k) = receiver;
						cout << "--------------------receiver found" << endl;

					}


				}



				/*
				if (t) {
					std::swap(Tp.at(transactionToDelete), Tp.back());
					Tp.pop_back();
					Tp.shrink_to_fit();
				}
				*/



	}


	return Tp;
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