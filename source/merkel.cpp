#include "merkel.h"

Merkel::Merkel(vector <Transaction> Transactions) {

	vector<Node> NodeTree;

	if (Transactions.size() % 2 != 0) {
		Transactions.push_back(Transactions[Transactions.size() - 1]);
	}

	for (auto t : Transactions) {
		Node node = makeNode(NULL, NULL, t.getTransactionId());
		NodeTree.push_back(node);
	}

	for (size_t i = 0; i < Transactions.size() / 2; i++) {
		vector<Node> atNode;

		if (NodeTree.size() % 2 != 0)
			NodeTree.push_back(NodeTree[NodeTree.size() - 1]);

		for (size_t j = 0; j < NodeTree.size(); j += 2) {
			Node node = makeNode(&NodeTree[j], &NodeTree[j + 1], "");
			atNode.push_back(node);
		}
		NodeTree = atNode;
	}
	this->Tree = NodeTree;
}

Node Merkel::makeNode(Node* left, Node* right, string hash) {
	Node node;
	Hash h;

	if (left == NULL && right == NULL)
		node.nodeHash = hash;
	else
		node.nodeHash = h.makeHash(left->nodeHash + right->nodeHash);

	node.left = left;
	node.right = right;

	return node;
}

string Merkel::getMerkelHash() {
	return this->Tree.at(0).nodeHash;
}