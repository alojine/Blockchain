#include "userPool.h"
#include "user.h"
#include "hash.h"
#include "generator.h"


vector<User> UserPool::getUserPool() {

	return this->Users;
}

void UserPool::generateUserPool() {

	srand((unsigned)time(NULL));

	for (int i = 1; i <= USERS; i++) {
		Generator g;
		int current_user = i;
		string UserName = to_string(current_user) + "User" + to_string(current_user);
		int Amount = g.generateInt(MIN_BALANCE, MAX_BALANCE);

		User User(UserName, Amount);
		Users.push_back(User);
	}
	
}

void UserPool::printUserPool() {

	for (auto a : this->Users) {
		cout << "UserName: " << a.getUserName() << endl;
		cout << "PublicKey: " << a.getPublicKey() << endl;
		cout << "Balance: " << a.getBalance() << endl;
		cout << endl;
	}
}

void UserPool::clearPool() {
	this->Users.clear();
}

int UserPool::getUserIndex(string name, vector<User> U) {
	int userIndex = 0;
	for (int i = 1; i <= U.size(); i++) {
		if (U.at(i).getUserName() == name) {
			userIndex = i;
			break;
		}
			
	}

	return userIndex;
}

void UserPool::updateUsers(vector<Transaction> BlockTransactions) {
	
	for (int i = 1; i <= BlockTransactions.size(); i++) {

		User sender;
		User receiver;

		for (int j = 1; j < this->Users.size(); j++) {

			if (BlockTransactions.at(i).getSender() == this->Users.at(j).getUserName()) {
				this->Users.at(j).setBalance(this->Users.at(j).getBalance() - BlockTransactions.at(i).getAmount());
			}

			if (BlockTransactions.at(i).getReceiver() == this->Users.at(j).getUserName()) {
				this->Users.at(j).setBalance(this->Users.at(j).getBalance() + BlockTransactions.at(i).getAmount());
			}
		}

	}
}