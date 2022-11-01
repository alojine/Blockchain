#include "transaction.h"
#include "hash.h"

void Transaction::createTransaction(string sender, string receiver, double amount) {

	Hash hash;

	this->TransactionId = hash.makeHash(sender + receiver + to_string(amount));
	this->Sender = sender;
	this->Receiver = receiver;
	this->Amount = amount;
}

void Transaction::printTransaction() {

	cout << "TransactionId: " << this->TransactionId << endl;
	cout << "Sender: " << this->Sender << endl;
	cout << "Receiver: " << this->Receiver << endl;
	cout << "Amount: " << this->Amount << endl;
}

string Transaction::getTransactionId(){
	return this->TransactionId;
}

string Transaction::getSender() {
	return this->Sender;
}

string Transaction::getReceiver() {
	return this->Receiver;
}

double Transaction::getAmount() {
	return this->Amount;
}


