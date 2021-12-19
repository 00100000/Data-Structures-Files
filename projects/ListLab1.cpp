#include <iostream>
#include "ListLab1.h"
using namespace std;

void printMe(ListNode* head)
{
	cout << "[";
	while(head != NULL)
	{
		 cout << head->getValue();
		 head = head->getNext();
		 if(head != NULL)
			 cout << ", ";
	}
	cout << "]" << endl;
}

int main()
{
	ListNode* head = new ListNode("hello", NULL);
	head = new ListNode("foo", head);
	head = new ListNode("boo", head);
	head = new ListNode("nonsense", head);
	head = new ListNode("computer", new ListNode("science", new ListNode("c++", new ListNode("coffee", head))));
	printMe(head);
	printMe(head);

	ListNode* a = head->copyNode(head);
	cout << "The head has a value \"" << head->getValue() << "\" at " << head << endl;
	cout << "The copy of head has a value of \"" << a->getValue() << "\" at " << a << endl;

	cout << "Copy the list: " << endl;
	ListNode* copy = head->copyList(head);
	printMe(copy);

	cout << "The rest of the list: " << endl;
	ListNode* theRest = head->rest(copy);
	printMe(theRest);

	cout << "First of the rest = " << head->first(theRest) << endl;
	cout << "Second of the rest = " << head->second(theRest) << endl;
	ListNode* p = head->pointerToLast(theRest);
	cout << "Pointer to Last = " << p->getValue()+ " at " << p << endl;
	ListNode* c = head->copyOfLast(theRest);
	cout << "Copy of Last =    " << c->getValue()+ " at " << c << endl;

	cout << "Insert what? " << endl;
	string x;
	getline(cin, x);
	theRest = head->insertFirst(theRest, x);
	theRest = head->insertLast(theRest, x);
	printMe(theRest);

	return 0;
}