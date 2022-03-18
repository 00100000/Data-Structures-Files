// ListLab4.h
// Author: Aidan Din
// ListLab4 header file

#ifndef LISTLAB4_H
#define LISTLAB4_H

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
		ListNode* add(ListNode* h, string s, int pos);
		ListNode* remove(ListNode* h, int pos);
		string printForward(ListNode* h);
		string printBackward(ListNode* h);
		string getValue();
		ListNode* getNext();
		ListNode* getPrev();
		void setValue(string s);
		void setNext(ListNode* n);
		void setPrev(ListNode* n);
		friend ostream& operator << (ostream& stream, ListNode* h);
};
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
// removes a node from a specific position in a list
ListNode* ListNode::remove(ListNode* h, int pos) {
	ListNode* tempH = new ListNode(h->value, h->next, h->prev);
	for (int i = 0; tempH != nullptr; i++) {
		if (i == pos) {
			tempH->next->prev = tempH->prev;
			tempH->prev->next = tempH->next;
			break;
		}
		tempH = tempH->next;
	}
	return h;
}
// prints a list forward from a node
string ListNode::printForward(ListNode* h) {
	string ret = "[";
	ListNode* last = h->prev;
	while (h != last) {
		ret += h->value + ", ";
		h = h->next;
	}
	ret += last->value + "]";
	return ret;
}
// prints a list backwards from a node
string ListNode::printBackward(ListNode* h) {
	string ret = "[";
	ListNode* last = h->next;
	while (h != last) {
		ret += h->value + ", ";
		h = h->prev;
	}
	ret += last->value + "]";
	return ret;
}
// setters/getters
string ListNode::getValue() {
	return value;
}
ListNode* ListNode::getNext() {
	return next;
}
ListNode* ListNode::getPrev() {
	return prev;
}
void ListNode::setValue(string s) {
	value = s;
}
void ListNode::setNext(ListNode* n) {
	next = n;
}
void ListNode::setPrev(ListNode* n) {
	prev = n;
}
// outputs list to output stream
ostream& operator << (ostream& stream, ListNode* h) {
	stream << "[";
	ListNode* last = h->prev;
	while (h != last) {
		stream << h->value << ", ";
		h = h->next;
	}
	stream << last->value;
	stream << "]" << endl;
	return stream;
}

#endif
