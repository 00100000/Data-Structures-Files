#include <iostream>
#include "ListLab4.h"
using namespace std;

int main() {
	ListNode* head = new ListNode("test", nullptr, nullptr);
	ListNode* second = new ListNode("a", nullptr, head);
	ListNode* third = new ListNode("b", head, second);
	second->setNext(third);
	head->setNext(second);
	head->setPrev(third);
	// test, a, b
	cout << head;
	head = head->add(head, "c", 2);
	// test, a, c, b
	cout << head;
	second = head->remove(second, 1);
	// test, a, b
	cout << head;
	// test, a, b
	cout << head->printForward(head) << "\n";
	// test, b, a
	cout << head->printBackward(head) << "\n";
	// b, a, test
	cout << head->printBackward(third) << endl;
	return 0;
}