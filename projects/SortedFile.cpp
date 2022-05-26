// SortedFile.cpp
// Author: Aidan Din
// Uses a binary search tree to output the amount of times each word appears in a passage

#include <fstream>
#include <iostream>
#include "SortedFileBST.h"
using namespace std;
#define umap unordered_map

int main() {
	ifstream infile("input.txt");
	ofstream outfile("result.txt");

	string word = "Empty";
	infile >> word;
	TreeNode* root = new TreeNode(word);
	while (infile >> word) root->insert(root, word);
	umap<string, int> m;
	m = root->mapWord(root, m);
	for (auto i : m) {
		outfile << i.first << ": " << i.second << "\n";
	}

	return 0;
}
