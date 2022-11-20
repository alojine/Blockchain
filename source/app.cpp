#include "app.h"

void App::Args(int argc, char** argv)
{
    this->argc = argc;
    this->argv = argv;
    this->argument = argv[1];
};



void App::run() {

    Generator Generator;

    // Users
    UserPool UserPool;
    UserPool.generateUserPool();
    vector<User> Users(UserPool.getUserPool());

    // Transactions
    TransactionPool TransactionPool;
    TransactionPool.generateTransactionPool(UserPool);
    vector<Transaction> Transactions(TransactionPool.getTransactionPool());

    // Copies of users and transactions
    vector<User> copyOfUsers = Users;
    vector<Transaction> copyOfTransactions = Transactions;

    // Block transactions
    vector<Transaction> BlockTransactions;

    // Block
    Block SingleBlock;
    vector<Block> BlockChain;


    cout << "UserPool of 1.000[users] has been generated." << endl;
    cout << "TransactionPool 10.000[transactions] has been generated." << endl;
    cout << "--------------------------------------------------------------" << endl;

    int number_of_candidates = 5;
    vector<int> cand = Generator.generateRandomNumbers(number_of_candidates);

    for (int s = 0; s < 5; s++) {

        // Sugeneruojamos transakcijos ir idedamos i nauja vektoriu
        for (int i = 0; i < 100; i++) {
            int random_transaction = Generator.generateInt(1, Transactions.size() - 1);
            BlockTransactions.push_back(Transactions.at(random_transaction));
        }

        cout << "Transakciju poole liko: " << Transactions.size() << endl;
        TransactionPool.validate(BlockTransactions);

        // Formatting a block
        SingleBlock.createBlock(s+1, d, BlockTransactions, BlockChain);

        //mining blocks
        SingleBlock.mine();

        if (SingleBlock.mined()) {

            // updating transactions
            Transactions.clear();
            TransactionPool.useTransactions(BlockTransactions);
            Transactions = TransactionPool.getTransactionPool();

            // updating users
            Users.clear();
            UserPool.updateUsers(BlockTransactions);
            Users = UserPool.getUserPool();

            // Adding block to chain
            BlockChain.push_back(SingleBlock);

            // Clearing objects
            BlockTransactions.clear();
            SingleBlock.printBlock();
        }

        
    }

    // end of program

    // commands
    string com;
    cout << endl;

    com = "0";
    while (com != "--ed") {
        cout << "Command line: ";
        cin >> com;

        // help
        if (com == "--help") {
            help();
        }

        // print blockchain
        if (com == "--bc") {
            for (auto a : BlockChain) {
                a.printBlock();
            }
        }

        // print user pool
        if (com == "--up") {
            UserPool.printUserPool();
        }

        // print transaction pool
        if (com == "--tp") {
            TransactionPool.printTransactionPool();
        }

        // print single block with transactions
        if (com == "--sb") {
            string nr; bool marker = 0;
            cout << "Type in block hash: "; cin >> nr;

            for (auto a : BlockChain) {
                if (a.getBlockHash() == nr) {
                    a.printBlock();
                    a.printBlockTransactions();
                    marker = 1;
                }
            }
            if (!marker)
                cout << "Block doesn't exist!" << endl;

        }

        if (com == "--tr") {
            string id; bool marker = 0;
            string crId;
            cout << "Type in transaction ID: "; cin >> id;
            for (auto a : copyOfTransactions) {
                if (a.getTransactionId() == id) {
                    a.printTransaction();
                    marker = 1;
                }
            }
            if (!marker)
                cout << "Transaction doesn't exist!" << endl;
        }

        if (com == "--st") {
            stats(Users, copyOfUsers);
        }


    }
}

void App::help() {
    cout << endl;
    cout << "--ed  to kill terinal" << endl;
    cout << "--bc  to print out BlockChain" << endl;
    cout << "--up  to print out UserPool" << endl;
    cout << "--tp  to print out TransactionPool" << endl;
    cout << "--sb  to print out single block by it's hash with transactions" << endl;
    cout << "--tr  to print out single transaction by it's ID" << endl;
    cout << endl;
}

void App::stats(vector<User> Users, vector<User> copyOfUsers) {
    int wBefore = 0, wAfter = 0;
    int pBefore = 0, pAfter = 0;
    int cBefore = 0, cAfter = 0;
    cout << "Information about the blockchain and statistics" << endl;
    for (size_t i = 1; i < Users.size(); i++) {

        if (copyOfUsers.at(i).getBalance() > copyOfUsers.at(wBefore).getBalance())
            wBefore = i;

        if (Users.at(i).getBalance() > Users.at(wAfter).getBalance())
            wAfter = i;

        if (copyOfUsers.at(i).getBalance() < copyOfUsers.at(wBefore).getBalance())
            pBefore = i;

        if (Users.at(i).getBalance() < Users.at(wAfter).getBalance())
            pAfter = i;

        cBefore += copyOfUsers.at(i).getBalance();
        cAfter += Users.at(i).getBalance();
    }
    cout << endl;
    cout << "---------------------------------------------Before transactions and updates--------------------------------------" << endl;
    cout << "Wealthiest: " << copyOfUsers.at(wBefore).getUserName() << " " << long(copyOfUsers.at(wBefore).getBalance()) << "$" << endl;
    cout << "Poorest: " << copyOfUsers.at(pBefore).getUserName() << " " << copyOfUsers.at(pBefore).getBalance() << "$" << endl;
    cout << "Money in circulation: " << cBefore << "$" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;

    cout << "---------------------------------------------After transactions and updates---------------------------------------" << endl;
    cout << "Wealthiest: " << Users.at(wAfter).getUserName() << " " << long(Users.at(wAfter).getBalance()) << "$" << endl;
    cout << "Poorest: " << Users.at(pAfter).getUserName() << " " << Users.at(pAfter).getBalance() << "$" << endl;
    cout << "Money in circulation: " << cAfter << "$" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}