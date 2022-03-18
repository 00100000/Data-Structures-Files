// Aidan Din
// DuckDuckGoose.cpp
// Simulates DuckDuckGoose with linked lists

#include <fstream>
#include <iostream>
using namespace std;

class ListNode {
	private:
		int pos;
		ListNode* next;
		ListNode* prev;

	public:
		ListNode(int p, ListNode* n, ListNode* pr) {
			pos = p;
			next = n;
			prev = pr;
		}
		// getters/setters
		int getPos() {
			return pos;
		}
		ListNode* getNext() {
			return next;
		}
		ListNode* getPrev() {
			return prev;
		}
		void setPos(int p) {
			pos = p;
		}
		void setNext(ListNode* n) {
			next = n;
		}
		void setPrev(ListNode* pr) {
			prev = pr;
		}
};

int main() {
	string name;
	cout << "Enter the name of the file you'd like to read from:\n";
	cin >> name;

	ifstream infile(name);
	ofstream outfile("result.txt");

	int cycle, participants;
	for (int i = 0; infile >> participants >> cycle; i++) {
		ListNode* head = new ListNode(1, nullptr, nullptr);
		ListNode* last = head;
		for (int j = 1; j < participants; j++) {
			ListNode* temp = new ListNode(j + 1, nullptr, last);
			last->setNext(temp);
			last = temp;
		}
		last->setNext(head);
		head->setPrev(last);

		head = head->getPrev();
		for (int j = 0; j < participants - 1; j++) {
			for (int k = 0; k < cycle; k++) {
				head = head->getNext();
			}
			// not clearing the memory, but whatever
			head->getNext()->setPrev(head->getPrev());
			head->getPrev()->setNext(head->getNext());
		}
		outfile << "Trial " << i + 1 << ": " << head->getNext()->getPos() << "\n";
	}

	cout << flush;
	return 0;
}
