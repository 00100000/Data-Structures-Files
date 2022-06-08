// WordTree.cpp
// Author: Aidan Din
// Stores a list of words in a trie, prints them alphabetically, and calculates the amount of space
// saved by storing the words in a trie

#include <fstream>
#include <iostream>
#include "WordTreeTrie.h"
using namespace std;

int main() {
	ifstream infile("input.txt");
	ofstream outfile("result.txt");

	int listCount = 0;
	WordNode* root = (new WordNode())->buildTree(infile, listCount);
	int trieCount = 0;
	trieCount = root->countNodes(root);
	// output
	root->traverse("", root, outfile);
	outfile << "\n";
	outfile << "| List Total: " << listCount << "\n";
	outfile << "| Trie Total: " << trieCount << "\n";
	outfile << "| Savings: " << (double)(listCount - trieCount) / listCount * 100 << "%\n";

	return 0;
}
