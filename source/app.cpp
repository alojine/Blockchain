#include "app.h"

void App::Args(int argc, char** argv)
{
    this->argc = argc;
    this->argv = argv;
    this->argument = argv[1];
};

void App::run() {
    
    Generator Generator;

    UserPool UserPool;
    UserPool.generateUserPool();
    vector<User> Users(UserPool.getUserPool());
    vector<User> copyOfUsers = Users;
    

    TransactionPool TransactionPool;
    TransactionPool.generateTransactionPool(UserPool);
    vector<Transaction> Transactions(TransactionPool.getTransactionPool());
    vector<Transaction> copyOfTransactions = Transactions;
    vector<Transaction> BlockTransactions;

    Block SingleBlock;
    vector<Block> BlockChain;

    // Wealthiest User
    // Poorest User
    // Biggest Transaction By Amount

    cout << "UserPool of 1.000[users] has been generated." << endl;
    cout << "TransactionPool 10.000[transactions] has been generated." << endl;
    cout << "--------------------------------------------------------------" << endl;

    int amount;
    cout << "number - amount of blocks to be mined." << endl;
    cout << "0 - all blocks to be mined" << endl;
    cout << "Number of block to be mined: "; cin >> amount;

    if (amount == 0) {
        

            int FullBlockTransactions = Transactions.size() / 100;
            int LeftTransactions = Transactions.size() - FullBlockTransactions;

            int gen = 0;
            for (int s = 0; s < FullBlockTransactions; s++) {

                // Sugeneruojamos transakcijos ir idedamos i nauja vektoriu
                for (int i = 0; i < 100; i++) {
                    int random_transaction = Generator.generateInt(1, Transactions.size() - 1);
                    BlockTransactions.push_back(Transactions.at(random_transaction));

                    // Deleting transactions
                    swap(Transactions.at(random_transaction), Transactions.back());
                    Transactions.pop_back();

                }
                cout << Transactions.size() << endl;


                // Genesis block
                if (gen == 0)
                    SingleBlock.createGenesis(BlockTransactions);

                // Regular block
                if (gen > 0)
                    SingleBlock.createBlock(BlockChain.back().getLastBlockHash(), BlockChain.size(), BlockTransactions, gen);

                // updating users
                Users.clear();
                UserPool.updateUsers(BlockTransactions);
                Users = UserPool.getUserPool();

                // Adding block to chain  
                BlockChain.push_back(SingleBlock);

                gen++;
                BlockTransactions.clear();
                SingleBlock.printBlock();
            }

            // Sugeneruojamos transakcijos ir idedamos i nauja vektoriu
            for (int i = 0; i < LeftTransactions; i++) {
                int random_transaction = Generator.generateInt(1, Transactions.size() - 1);
                BlockTransactions.push_back(Transactions.at(random_transaction));

                // Deleting transactions
                if (Transactions.size() > 1) {
                    swap(Transactions.at(random_transaction), Transactions.back());
                    Transactions.pop_back();
                }
                else {
                    Transactions.clear();
                }
                

            }
            cout << Transactions.size() << endl;


            // Genesis block
            if (gen == 0)
                SingleBlock.createGenesis(BlockTransactions);

            // Regular block
            if (gen > 0)
                SingleBlock.createBlock(BlockChain.back().getLastBlockHash(), BlockChain.size(), BlockTransactions, gen);

            // updating users
            Users.clear();
            //UserPool.updateUsers(BlockTransactions);
            //Users = UserPool.getUserPool();

            // Adding block to chain  
            BlockChain.push_back(SingleBlock);

            gen++;
            BlockTransactions.clear();
            SingleBlock.printBlock();


    }

    if (amount != 0) {

        int gen = 0;
        for (int s = 0; s < amount; s++) {

            // Sugeneruojamos transakcijos ir idedamos i nauja vektoriu
            for (int i = 0; i < 100; i++) {
                int random_transaction = Generator.generateInt(1, Transactions.size() - 1);
                BlockTransactions.push_back(Transactions.at(random_transaction));

                // Deleting transactions
                swap(Transactions.at(random_transaction), Transactions.back());
                Transactions.pop_back();

            }
            cout << Transactions.size() << endl;


            // Genesis block
            if (gen == 0)
                SingleBlock.createGenesis(BlockTransactions);

            // Regular block
            if (gen > 0)
                SingleBlock.createBlock(BlockChain.back().getLastBlockHash(), BlockChain.size(), BlockTransactions, gen);

            // updating users
            Users.clear();
            UserPool.updateUsers(BlockTransactions);
            Users = UserPool.getUserPool();

            // Adding block to chain  
            BlockChain.push_back(SingleBlock);

            gen++;
            BlockTransactions.clear();
            SingleBlock.printBlock();
        }
    }


    // commands
    string com;
    cout << endl;
    
    com = "0";
    while (com != "--ed") {
        cout << "Command line: ";
        cin >> com;

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

};

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
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Wealthiest" << endl;
    cout << copyOfUsers.at(wBefore).getUserName() << " " << copyOfUsers.at(wBefore).getBalance() << "$" << endl;
    cout << "Poorest" << endl;
    cout << copyOfUsers.at(pBefore).getUserName() << " " << copyOfUsers.at(pBefore).getBalance() << "$" << endl;
    cout << "Money in circulation: " << cBefore << "$" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
    cout << "Transactions were made!" << endl;
    cout << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Wealthiest" << endl;
    cout << Users.at(wAfter).getUserName() << " " << Users.at(wAfter).getBalance() << "$" << endl;
    cout << "Poorest" << endl;
    cout << Users.at(pAfter).getUserName() << " " << Users.at(pAfter).getBalance() << "$" << endl;
    cout << "Money in circulation: " << cAfter << "$" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------" << endl;
    cout << endl;
}

void mineAmount() {

};

void mineAll() {

};