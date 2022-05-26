// SortedFileBST.h
// Author: Aidan Din
// Catches the imposter when he's sus

#ifndef SORTED_FILE_BST_H
#define SORTED_FILE_BST_H

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
#define umap unordered_map 

class TreeNode {
	string word;
	TreeNode* left;
	TreeNode* right;

	public:
		// constructor
		TreeNode() {
			word = "Empty";
			left = nullptr;
			right = nullptr;
		}
		TreeNode(string w) {
			word = w;
			left = nullptr;
			right = nullptr;
		}
		TreeNode* insert(TreeNode* t, string w);
		umap<string, int> mapWord(TreeNode* t, umap<string, int> m);
		// setters/getters
		void setWord(string w);
		void setLeft(TreeNode* l);
		void setRight(TreeNode* r);
		string getWord();
		TreeNode* getLeft();
		TreeNode* getRight();
};

TreeNode* TreeNode::insert(TreeNode* t, string w) {
	TreeNode* head = t;
	bool found = false;
	while (!found) {
		if (w.compare(head->getWord()) < 0) {
			if (head->getLeft() == nullptr) {
				head->setLeft(new TreeNode(w));
				found = true;
			} else {
				head = head->getLeft();
			}
		// duplicate characters on the right
		} else if (w.compare(head->getWord()) >= 0) {
			if (head->getRight() == nullptr) {
				head->setRight(new TreeNode(w));
				found = true;
			} else {
				head = head->getRight();
			}
		}
	}
	return t;
}
// this is probably not the intended solution but... I used a BST and
// am taking the words from the BST, so it's fair game!
umap<string, int> TreeNode::mapWord(TreeNode* t, umap<string, int> m) {
	if (t == nullptr) return m;
	m[t->getWord()]++;
	m = mapWord(t->getLeft(), m);
	m = mapWord(t->getRight(), m);
	return m;
}

void TreeNode::setWord(string w) {
	word = w;
}

void TreeNode::setLeft(TreeNode* l) {
	left = l;
}

void TreeNode::setRight(TreeNode* r) {
	right = r;
}

string TreeNode::getWord() {
	return word;
}

TreeNode* TreeNode::getLeft() {
	return left;
}

TreeNode* TreeNode::getRight() {
	return right;
}

#endif
