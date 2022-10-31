#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Transaction {
	private:
		string TransactionId;
		string Sender;
		string Receiver;
		double Amount;

	public: 
		Transaction() { this->TransactionId = ""; }
		void createTransaction(string sender, string receiver, double amount);
		void printTransaction();

		string getTransactionId();
		string getSender();
		string getReceiver();
		double getAmount();


};