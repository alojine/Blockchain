#include "app.h"

void App::Args(int argc, char** argv)
{
    this->argc = argc;
    this->argv = argv;
    this->argument = argv[1];
};

void App::run() {
    
    UserPool UserPool;
    UserPool.generateUserPool();
    

    TransactionPool TransactionPool;
    TransactionPool.generateTransactionPool(UserPool);
    TransactionPool.printTransactionPool();
    UserPool.clearPool();
    TransactionPool.clearPool();
    

    /*
    Generator Generator;

    UserPool UserPool;
    UserPool.generateUserPool();
    vector<User> Users(UserPool.getUserPool());
    

    TransactionPool TransactionPool;
    TransactionPool.generateTransactionPool(UserPool);
    vector<Transaction> Transactions(TransactionPool.getTransactionPool());

    UserPool.clearPool();
    TransactionPool.clearPool();


    Block SingleBlock;
    vector<Block> BlockChain;
    vector<Transaction> BlockTransactions;
    */


    /*
    while (Transactions.size() > 1) {

        for (int j = 0; j < 100; j++) {
            // Random transaction from transaction pool
            int random_transaction = Generator.generateInt(1, Transactions.size());

            // Transaction validation
            bool validated = false;

            for (int i = 0; i < Users.size(); i++) {

                User sender;
                User receiver;

                if (Users.at(i).getUserName() == Transactions.at(random_transaction).getReceiver()) {
                    
                }

                // check if transaction is avalible  ~sender has enough balance
                if (Users.at(i).getUserName() == Transactions.at(random_transaction).getSender()) {
                    if (Users.at(i).getBalance() > Transactions.at(random_transaction).getAmount()) {

                        // decreasing sender amount and 
                        sender.setBalance(Users.at(i).getBalance() - Transactions.at(random_transaction).getAmount());
                        sender.setPublicKey(Users.at(i).getPublicKey());
                        sender.setUserName(Users.at(i).getUserName());
                        Users.at(i) = sender;

                        validated = true;
                    }
                }
            }

            while (validated) {
                // resizing TransactionPool
                Transactions.shrink_to_fit();

                // pushing trannaction to user
                BlockTransactions.push_back(Transactions.at(random_transaction));
            }
            
            
            
        }


    }

    for (auto a : BlockTransactions) {
        cout << a.getAmount() << endl;
    }
    */

};