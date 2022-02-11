#include <iostream>
#include "ListLab3.h"
using namespace std;

int main() {
	ListNode* head = new ListNode("test", nullptr, nullptr);
	head = new ListNode("thing", head, nullptr);

	head = head->add(head, "a");
	// a, thing, test
	cout << head;
	head = head->add(head, "b", 2);
	// a, thing, b, test
	cout << head;
	head = head->remove(head, 2);
	// a, thing, test
	cout << head;
	head = head->remove(head);
	// thing, test
	cout << head;
	return 0;
}