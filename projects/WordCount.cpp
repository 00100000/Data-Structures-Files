// WordCount.cpp
// Author: Aidan Din
// Prints out each unique word and the number of times it is seen in a file

#include <fstream>
#include <iostream>
using namespace std;

class ListNode {
	private:
		ListNode* next;
		int count;
		string value;

	public:
		//constructors
		ListNode() {}
		ListNode(string s, int c, ListNode* n) {
			value = s;
			count = c;
			next = n;
		}
		// methods
		ListNode* insert(ListNode* h, string s);
		string getValue();
		int getCount();
		ListNode* getNext();
};
// inserts a new word into the list
ListNode* ListNode::insert(ListNode* h, string s) {
	if (h->value.compare("") == 0) {
		h = new ListNode(s, 1, nullptr);
	// if s is lexicographically first
	} else if (h->value.compare(s) > 0) {
		return new ListNode(s, 1, h);
	} else {
		ListNode* tempH = new ListNode(h->value, h->count, h->next);
		ListNode* last = new ListNode("", 0, h);
		bool found = false;
		while (tempH != nullptr) {
			// if s is duplicate
			if (tempH->value.compare(s) == 0) {
				tempH->count++;
				found = true;
				break;
			// if s belongs in the middle of the list
			} else if (tempH->value.compare(s) > 0) {
				ListNode* newWord = new ListNode(s, 1, tempH);
				last->next = newWord;
				found = true;
				break;
			}
			last = last->next;
			tempH = tempH->next;
		}
		// if s belongs at the end
		if (!found) {
			ListNode* end = new ListNode(s, 1, nullptr);
			last->next = end;
		}
	}
	return h;
}
// returns value of a node
string ListNode::getValue() {
	return value;
}
int ListNode::getCount() {
	return count;
}
// returns the node this node points to
ListNode* ListNode::getNext() {
	return next;
}

int main() {
	string name;
	cout << "Enter the name of a file:" << endl;
	cin >> name;
	ifstream infile(name);
	ofstream outfile("result.txt");

	ListNode* h = new ListNode("", 0, nullptr);
	string word;
	while (infile >> word) {
		h = h->insert(h, word);
	}

	outfile << "List of words in " << name << " alphabetically, and the number of times they appear:\n";
	while (h != nullptr) {
		if (h->getCount() > 0) {
			outfile << h->getValue() << " - " << h->getCount() << "\n";
		}
		h = h->getNext();
	}
	outfile << flush;

	outfile.close();
	infile.close();
	return 0;
}
