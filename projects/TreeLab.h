// TreeLab.h
// Author: Aidan Din
// Implements a binary search tree with a variety of methods

#ifndef TREELAB_H
#define TREELAB_H

#include <string>
using namespace std;

class TreeNode {
	char letter;
	TreeNode* left;
	TreeNode* right;

	public:
		// constructor
		TreeNode() {
			letter = '.';
			left = nullptr;
			right = nullptr;
		}
		TreeNode(char c) {
			letter = c;
			left = nullptr;
			right = nullptr;
		}
		// takes a string parameter and builds a BST where each letter is a node
		TreeNode* buildTree(string s);
		// inserts a node containing the character into the tree
		TreeNode* insert(TreeNode* t, char s);
		string display(TreeNode* t, int level);
		string preorderTraverse(TreeNode* t);
		string inorderTraverse(TreeNode* t);
		string postorderTraverse(TreeNode* t);
		int countNodes(TreeNode* t);
		int countLeaves(TreeNode* t);
		int countGrandParents(TreeNode* t);
		int countOnlyChildren(TreeNode* t);
		// returns the max of the heights to the left and the heights to the right
		int height(TreeNode* t);
		// return the max of the sum of the heights to the left and the heights to the right
		int longestPath(TreeNode* t);
		char min(TreeNode* t);
		char max(TreeNode* t);
		string displayCurrentLevel(TreeNode* t, int level);
		string displayLevelOrder(TreeNode* t);
		// setters/getters
		void setLetter(char c);
		void setLeft(TreeNode* l);
		void setRight(TreeNode* r);
		char getLetter();
		TreeNode* getLeft();
		TreeNode* getRight();
};

TreeNode* TreeNode::insert(TreeNode* t, char s) {
	TreeNode* head = t;
	bool found = false;
	while (!found) {
		if (s < head->getLetter()) {
			if (head->getLeft() == nullptr) {
				head->setLeft(new TreeNode(s));
				found = true;
			} else {
				head = head->getLeft();
			}
		// duplicate characters on the right
		} else if (s >= head->getLetter()) {
			if (head->getRight() == nullptr) {
				head->setRight(new TreeNode(s));
				found = true;
			} else {
				head = head->getRight();
			}
		}
	}
	return t;
}

TreeNode* TreeNode::buildTree(string s) {
	TreeNode* root = new TreeNode(s.at(0));
	for (int i = 1; i < (int)s.size(); i++) {
		root = root->insert(root, s.at((unsigned long)i));
	}
	return root;
}

string TreeNode::display(TreeNode* t, int level) {
	if (t == nullptr) return "";
	string str = "";
	// left pad
	for (int i = 0; i < level - 1; i++) str += "  ";
	if (level > 0) str += "->";
	str += t->getLetter();
	// left on top, right on bottom
	if (t->getLeft() == nullptr && t->getRight() == nullptr) return str;
	if (t->getLeft() == nullptr) {
		str = "\n" + str;
	} else {
		str = display(t->getLeft(), level + 1) + "\n" + str;
	}
	if (t->getRight() == nullptr) {
	} else {
		str = str + "\n" + display(t->getRight(), level + 1);
	}
	return str;
}

string TreeNode::preorderTraverse(TreeNode* t) {
	if (t == nullptr) return "";
	string str = "";
	str += t->getLetter();
	str += " ";
	str += preorderTraverse(t->getLeft());
	str += preorderTraverse(t->getRight());
	return str;
}

string TreeNode::inorderTraverse(TreeNode* t) {
	if (t == nullptr) return "";
	string str = "";
	str += inorderTraverse(t->getLeft());
	str += t->getLetter();
	str += " ";
	str += inorderTraverse(t->getRight());
	return str;
}

string TreeNode::postorderTraverse(TreeNode* t) {
	if (t == nullptr) return "";
	string str = "";
	str += postorderTraverse(t->getLeft());
	str += postorderTraverse(t->getRight());
	str += t->getLetter();
	str += " ";
	return str;
}

int TreeNode::countNodes(TreeNode* t) {
	if (t == nullptr) return 0;
	int ret = 1;
	ret += t->countNodes(t->getLeft());
	ret += t->countNodes(t->getRight());
	return ret;
}

int TreeNode::countLeaves(TreeNode* t) {
	if (t == nullptr) return 0;
	if (t->getLeft() == nullptr && t->getRight() == nullptr) return 1;
	int cnt = 0;
	cnt += t->countLeaves(t->getLeft());
	cnt += t->countLeaves(t->getRight());
	return cnt;
}

int TreeNode::countGrandParents(TreeNode* t) {
	if (t == nullptr) return 0;
	bool isGP = false;
	if (t->getLeft() != nullptr) {
		if (t->getLeft()->getLeft() != nullptr) isGP = true;
		if (t->getLeft()->getRight() != nullptr) isGP = true;
	}
	if (t->getRight()) {
		if (t->getRight()->getLeft() != nullptr) isGP = true;
		if (t->getRight()->getRight() != nullptr) isGP = true;
	}
	int cnt = 0;
	if (isGP) cnt++;
	cnt += t->countGrandParents(t->getLeft());
	cnt += t->countGrandParents(t->getRight());
	return cnt;
}

int TreeNode::countOnlyChildren(TreeNode* t) {
	if (t == nullptr) return 0;
	int children = 0;
	if (t->getLeft() != nullptr && t->getRight() == nullptr) children++;
	if (t->getLeft() == nullptr && t->getRight() != nullptr) children++;
	int cnt = 0;
	if (children == 1) cnt++;
	cnt += t->countOnlyChildren(t->getLeft());
	cnt += t->countOnlyChildren(t->getRight());
	return cnt;
}

int TreeNode::height(TreeNode* t) {
	if (t == nullptr) return 0;
	return std::max(1 + height(t->getLeft()), 1 + height(t->getRight()));
}

int TreeNode::longestPath(TreeNode* t) {
	if (t == nullptr) return 0;
	// the longest path passing through t is the sum of the height of the left and right subtrees
	// return the max of the longest path through t and the longest path through subtrees of t
	return std::max(height(t->getLeft()) + height(t->getRight()), std::max(longestPath(t->getLeft()), longestPath(t->getRight())));
}

char TreeNode::min(TreeNode* t) {
	if (t == nullptr) return (char)127;
	char minSeen = t->getLetter();
	minSeen = std::min(minSeen, min(t->getLeft()));
	minSeen = std::min(minSeen, min(t->getRight()));
	return minSeen;
}

char TreeNode::max(TreeNode* t) {
	if (t == nullptr) return (char)0;
	char maxSeen = t->getLetter();
	maxSeen = std::max(maxSeen, max(t->getLeft()));
	maxSeen = std::max(maxSeen, max(t->getRight()));
	return maxSeen;
}

string TreeNode::displayCurrentLevel(TreeNode* t, int level) {
	if (t == nullptr) return "";
	if (level == 0) {
		string temp(1, t->getLetter());
		return temp + " ";
	}
	string str = "";
	str += displayCurrentLevel(t->getLeft(), level - 1);
	str += displayCurrentLevel(t->getRight(), level - 1);
	return str;
}

string TreeNode::displayLevelOrder(TreeNode* t) {
	int h = t->height(t);
	string str = "";
	for (int i = 0; i < h; i++) {
		str += displayCurrentLevel(t, i);
	}
	return str;
}

void TreeNode::setLetter(char c) {
	letter = c;
}

void TreeNode::setLeft(TreeNode* l) {
	left = l;
}

void TreeNode::setRight(TreeNode* r) {
	right = r;
}

char TreeNode::getLetter() {
	return letter;
}

TreeNode* TreeNode::getLeft() {
	return left;
}

TreeNode* TreeNode::getRight() {
	return right;
}

#endif
