// ListLab1.h
// Author: Aidan Din
// ListLab1 header file

#ifndef LISTLAB1_H
#define LISTLAB1_H

#include <iostream>
using namespace std;

class ListNode {
	private:
		ListNode* next;
		string value;

	public:
		//constructors
		ListNode() {}
		ListNode(string s, ListNode* n) {
			value = s;
			next = n;
		}
		// methods
		string first(ListNode* head);
		string second(ListNode* head);
		ListNode* pointerToLast(ListNode* head);
		ListNode* copyOfLast(ListNode* head);
		ListNode* insertFirst(ListNode* head, string arg);
		ListNode* insertLast(ListNode* head, string arg);
		ListNode* copyNode(ListNode* arg);
		ListNode* copyList(ListNode* arg);
		ListNode* rest(ListNode* h);
		string getValue();
		ListNode* getNext();
};
// returns value of first node
string ListNode::first(ListNode* head) {
	return head->value;
}
// returns value of last node
string ListNode::second(ListNode* head) {
	return head->next->value;
}
// returns reference to last node
ListNode* ListNode::pointerToLast(ListNode* head) {
	while (head->next != nullptr) {
		head = head->next;
	}
	return head;
}
// returns copy of last node
ListNode* ListNode::copyOfLast(ListNode* head) {
	while (head->next != nullptr) {
		head = head->next;
	}
	return new ListNode(head->value, nullptr);
}
// inserts node at the start of a list
ListNode* ListNode::insertFirst(ListNode* head, string arg) {
	return new ListNode(arg, head);
}
// inserts node at the end of a list
ListNode* ListNode::insertLast(ListNode* head, string arg) {
	ListNode* last = new ListNode(head->value, head->next);
	while (last->next != nullptr) {
		last = last->next;
	}
	ListNode* newTail = new ListNode(arg, nullptr);
	last->next = newTail;
	return head;
}
// returns a copy of a node
ListNode* ListNode::copyNode(ListNode* arg) {
	return new ListNode(arg->value, arg->next);
}
// returns a copy of a list
ListNode* ListNode::copyList(ListNode* arg) {
	if (arg == nullptr)	return nullptr;
	return new ListNode(arg->value, copyList(arg->next));
}
// returns the rest of a list
ListNode* ListNode::rest(ListNode* h) {
	if (h == nullptr) return nullptr;
	h = h->next;
	return new ListNode(h->value, copyList(h->next));
}
// returns value of a node
string ListNode::getValue() {
	return value;
}
// returns the node this node points to
ListNode* ListNode::getNext() {
	return next;
}

#endif