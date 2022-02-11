// ListLab3.h
// Author: Aidan Din
// ListLab3 header file

#ifndef LISTLAB3_H
#define LISTLAB3_H

#include <iostream>
using namespace std;

class ListNode {
	private:
		ListNode* next;
		ListNode* prev;
		string value;

	public:
		//constructors
		ListNode() {}
		ListNode(string s, ListNode* n, ListNode* p) {
			value = s;
			next = n;
			prev = p;
		}
		// methods
		ListNode* add(string s);
		ListNode* add(string s, int pos);
		ListNode* remove();
		ListNode* remove(int pos);
		friend ostream& operator << (ostream& stream, ListNode* n);
};
// outputs list to output stream
ostream& operator << (ostream& stream, ListNode* n) {
	stream << "[";
	while (n != nullptr) {
		stream << n->value << ", ";
		n = n->next;
	}
	stream << "]";
	return stream;
}

#endif