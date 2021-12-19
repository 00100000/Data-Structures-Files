#ifndef LISTNODE
#define LISTNODE
#define ListNode* ListNode::copyNode(ListNode* arg)
#define ListNode* ListNode::copyList(ListNode* arg)
#define ListNode* ListNode::rest(ListNode* h)
#define string first(ListNode* head)
#define string second(ListNode* head)
#define ListNode* pointerToLast(ListNode* head)
#define ListNode* copyOfLast(ListNode* head)
#define ListNode* insertFirst(ListNode* head, string arg)
#define ListNode* insertLast(ListNode* head, string arg)

#include <iostream>
using namespace std;

string first(ListNode* head) {
	return head->value;
}
string second(ListNode* head) {
	return head->next->value;
}
ListNode* pointerToLast(ListNode* head) {
	while (head->next != nullptr) {
		head = head->next;
	}
	return head;
}
ListNode* copyOfLast(ListNode* head) {
	while (head->next != nullptr) {
		head = head->next;
	}
	return head;
}
ListNode* insertFirst(ListNode* head, string arg) {
}
ListNode* insertLast(ListNode* head, string arg) {
}

class ListNode {
	public:
		string value;
		ListNode* next;

		ListNode* copyNode(ListNode* arg) {
		}
		ListNode* copyList(ListNode* arg) {
		}
		ListNode* rest(ListNode* h) {
		}
};

#endif