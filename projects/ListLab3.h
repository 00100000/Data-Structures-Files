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
		ListNode* add(ListNode* h, string s);
		ListNode* add(ListNode* h, string s, int pos);
		ListNode* remove(ListNode* h);
		ListNode* remove(ListNode* h, int pos);
		friend ostream& operator << (ostream& stream, ListNode* n);
};
// adds a node to the start of a list
ListNode* ListNode::add(ListNode* h, string s) {
	ListNode* newHead = new ListNode(s, h, nullptr);
	if (h != nullptr) {
		h->prev = newHead;
	}
	return newHead;
}
// adds a node in the middle of a list
ListNode* ListNode::add(ListNode* h, string s, int pos) {
	ListNode* tempH = new ListNode(h->value, h->next, h->prev);
	for (int i = 0; tempH != nullptr; i++) {
		if (i == pos - 1) {
			ListNode* ins = new ListNode(s, tempH->next, tempH);
			tempH->next = ins;
			if (ins->next != nullptr) {
				ins->next->prev = ins;
			}
			break;
		}
		tempH = tempH->next;
	}
	return h;
}
// removes a node from the start of a list
ListNode* ListNode::remove(ListNode* h) {
	if (h->next != nullptr) {
		h->prev = nullptr;
	}
	return h->next;
}
// removes a node from a specific position in a list
ListNode* ListNode::remove(ListNode* h, int pos) {
	ListNode* tempH = new ListNode(h->value, h->next, h->prev);
	for (int i = 0; tempH != nullptr; i++) {
		if (i == pos) {
			if (tempH->next != nullptr) {
				tempH->next->prev = tempH->prev;
			}
			if (tempH->prev != nullptr) {
				tempH->prev->next = tempH->next;
			}
			break;
		}
		tempH = tempH->next;
	}
	return h;
}
// outputs list to output stream
ostream& operator << (ostream& stream, ListNode* n) {
	stream << "[";
	while (n != nullptr) {
		stream << n->value;
		if (n->next != nullptr) {
			stream << ", ";
		}
		n = n->next;
	}
	stream << "]" << endl;
	return stream;
}

#endif