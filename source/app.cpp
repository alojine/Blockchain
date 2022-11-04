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
    vector<Transaction> copyOfTransactions = Transactions;
    vector<Transaction> BlockTransactions;

    Block SingleBlock;
    vector<Block> BlockChain;

    cout << "UserPool of 1.000[users] has been generated." << endl;
    cout << "TransactionPool 10.000[transactions] has been generated." << endl;
    cout << endl;

    int gen = 0;
    for (int s = 0; s < 6; s++) {
        
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
        if(gen > 0)
            SingleBlock.createBlock(BlockChain.back().getLastBlockHash(), BlockChain.size(), BlockTransactions, gen);
        
        // updating users
        UserPool.updateUsers(BlockTransactions);

        // Adding block to chain  
        BlockChain.push_back(SingleBlock);
        SingleBlock.printBlock();

        gen++;
        BlockTransactions.clear();
        SingleBlock.printBlock();
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
            int nr; bool marker = 0;
            cout << "Iveskite bloko nr: "; cin >> nr;
            
            for (auto a : BlockChain) {
                if (a.getBlockNumber() == nr) {
                    a.printBlock();
                    a.printBlockTransactions();
                    marker = 1;
                }
            }
            if (!marker)
                cout << "Blokas neegzisutoja!" << endl;

        }

        if (com == "--tr") {
            string id; bool marker = 0;
            string crId;
            cout << "Iveskite transakcijos id: "; cin >> id;
            for (auto a : copyOfTransactions) {
                if (a.getTransactionId() == id) {
                    a.printTransaction();
                    marker = 1;
                }
            }
            if (!marker)
                cout << "Transakcija neegzistuoja!" << endl;
        }


    }

};