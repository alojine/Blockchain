#include "userPool.h"
#include "user.h"
#include "hash.h"
#include "generator.h"


vector<User> UserPool::getUserPool() {

	return this->Users;
}

void UserPool::generateUserPool() {

	srand((unsigned)time(NULL));

	for (int i = 0; i < USERS; i++) {
		Generator g;
		int current_user = i + 1;
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

void::UserPool::clearPool() {
	this->Users.clear();
}