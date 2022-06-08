// WordTreeTrie.h	
// Author: Aidan Din
// Stores words as a trie

#ifndef WORD_TREE_TRIE_H
#define WORD_TREE_TRIE_H

#include <string>
using namespace std;

class WordNode {
	private:
		WordNode* children[26];
		bool endOfWord;

	public:
		// constructor
		WordNode() {
			endOfWord = false;
			for (int i = 0; i < 26; i++) children[i] = nullptr;
		}
		WordNode(bool e) {
			endOfWord = e;
			for (int i = 0; i < 26; i++) children[i] = nullptr;
		}
		WordNode* buildTree(ifstream &file, int &count);
		void insert(WordNode* w, string s);
		void traverse(string prefix, WordNode* w, ofstream &file);
		int countNodes(WordNode* w);
};

WordNode* WordNode::buildTree(ifstream &file, int &count) {
	WordNode* root = new WordNode();
	string s;
	while (file >> s) {
		insert(root, s);
		count += s.size();
	}
	return root;
}

void WordNode::insert(WordNode* w, string s) {
	for (int i = 0; i < (int)s.size(); i++) {
		char ins = s.at((unsigned long)i);
		bool end = i == (int)s.size() - 1;
		if (w->children[ins - 'a'] == nullptr) {
			w->children[ins - 'a'] = new WordNode(end);
		} else if (end) {
			w->children[ins - 'a']->endOfWord = true;
		}
		w = w->children[ins - 'a'];
	}
}

void WordNode::traverse(string prefix, WordNode* w, ofstream &file) {
	if (w == nullptr) return;
	if (w->endOfWord) file << prefix << "\n";
	for (int i = 0; i < 26; i++) {
		traverse(prefix + (char)('a' + i), w->children[i], file);
	}
}

int WordNode::countNodes(WordNode* w) {
	if (w == nullptr) return 0;
	int cnt = 1;
	for (int i = 0; i < 26; i++) cnt += countNodes(w->children[i]);
	return cnt;
}

#endif
