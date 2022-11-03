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
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
	cout << left << setw(20) << "TransactionId: " << this->TransactionId << endl;
	cout << left << setw(20) << "Sender: " << this->Sender << endl;
	cout << left << setw(20) << "Receiver: " << this->Receiver << endl;
	cout << left << setw(20) << "Amount: " << this->Amount << endl;
	cout << "---------------------------------------------------------------------------------------------------------------" << endl;
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


