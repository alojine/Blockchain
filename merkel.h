#pragma once
#include <vector>
#include <iterator>

#include "transaction.h"
#include "hash.h"

class Node {
public:
	string nodeHash;
	struct Node* left;
	struct Node* right;
	Node() { this->left = NULL; this->right = NULL; this->nodeHash = ""; }
};

class Merkel {
private:
	vector <Node> Tree;

public:
	Merkel(vector <Transaction> Transactions);
	Node makeNode(Node* left, Node* right, string hash);
	string getMerkelHash();

};