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
    

    TransactionPool TransactionPool;
    TransactionPool.generateTransactionPool(UserPool);
    vector<Transaction> Transactions(TransactionPool.getTransactionPool());


    Block SingleBlock;
    vector<Block> BlockChain;
    vector<Transaction> BlockTransactions;

    int gen = 0;
    while (gen < 5) {
        for (int j = 0; j < 100; j++) {

            // generating random transaction from Transaction pool
            int random_transaction = Generator.generateInt(1, Transactions.size() - 1);
            
            bool validated = false;
            for (int i = 0; i < Users.size(); i++) {

                User sender;
                User receiver;
                int receiver_index;
                if (Users.at(i).getUserName() == Transactions.at(random_transaction).getReceiver()) {
                    receiver_index = i;
                }

                // validating again in mining process if user has enough balance to transit
                if (Users.at(i).getUserName() == Transactions.at(random_transaction).getSender()) {
                    if (Users.at(i).getBalance() > Transactions.at(random_transaction).getAmount()) {

                        // 
                        sender.setBalance(Users.at(i).getBalance() - Transactions.at(random_transaction).getAmount());
                        sender.setPublicKey(Users.at(i).getPublicKey());
                        sender.setUserName(Users.at(i).getUserName());
                        Users.at(i) = sender;

                        validated = true;
                    }
                }

                if (validated) {
                    receiver.setBalance(Users.at(receiver_index).getBalance() + Transactions.at(random_transaction).getAmount());
                    receiver.setPublicKey(Users.at(receiver_index).getPublicKey());
                    receiver.setUserName(Users.at(receiver_index).getUserName());
                    Users.at(receiver_index) = receiver;
                }

            }

            // final push
            BlockTransactions.push_back(Transactions.at(random_transaction));

            // removing transaction from pool
            
           
            Transactions.shrink_to_fit();
        }

        if (gen == 0) {
            SingleBlock.createGenesis(BlockTransactions);
        }
        else {
            SingleBlock.createBlock(BlockChain.back().getLastBlockHash(), BlockChain.size(), BlockTransactions);
        }
        BlockChain.push_back(SingleBlock);

        gen++;
        BlockTransactions.clear();
        SingleBlock.printBlock();
    }

    // commands
    string com;
    cout << endl;
    
    com = "0";
    while (com != "--ed") {
        cout << "Command line";
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

    }


};