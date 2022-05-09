// AssemblyLine.cpp
// Author: Aidan Din
// Simulates the assembly of pyramids made of stacks of disks

#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class Disk {
	int radius;
	Disk* next;

	public:
		Disk() {
			radius = -1;
			next = nullptr;
		}
		Disk(int r, Disk* n) {
			radius = r;
			next = n;
		}
		void setNext(Disk* n);
		void setRadius(int r);
		Disk* getNext();
		int getRadius();
};
void Disk::setNext(Disk* n) {
	next = n;
}
void Disk::setRadius(int r) {
	radius = r;
}
Disk* Disk::getNext() {
	return next;
}
int Disk::getRadius() {
	return radius;
}

class Pyramid {
	Disk* head;
	Pyramid* next;

	public:
		Pyramid() {
			head = nullptr;
			next = nullptr;
		}
		Pyramid(Disk* d, Pyramid* n) {
			head = d;
			next = n;
		}
		// Disk stack methods
		bool empty();
		void push(int radius);
		void pop();
		Disk* peek();
		// Pyramid setters/getters
		void setNext(Pyramid* n);
		Pyramid* getNext();
};
bool Pyramid::empty() {
	return head == nullptr;
}
void Pyramid::push(int radius) {
	Disk* temp = new Disk(radius, head);
	head = temp;
}
void Pyramid::pop() {
	head = head->getNext();
}
Disk* Pyramid::peek() {
	return head;
}
void Pyramid::setNext(Pyramid* n) {
	next = n;
}
Pyramid* Pyramid::getNext() {
	return next;
}

class AssemblyLine {
	Disk* assemblyLineIn;
	Disk* assemblyLineInBack;
	Pyramid* assemblyLineOut;
	Pyramid* assemblyLineOutBack;
	Pyramid* robotArm;

	public:
		AssemblyLine(int n) {
			// initialize objects
			assemblyLineIn = new Disk(-1, nullptr);
			assemblyLineOut = new Pyramid(nullptr, nullptr);
			robotArm = new Pyramid(nullptr, nullptr);
			// link backs of queues
			assemblyLineInBack = assemblyLineIn;
			assemblyLineOutBack = assemblyLineOut;
			// randomly generate Disks
			for (;n > 0; n--) {
				Disk* temp = new Disk(rand() % 10 + 1, nullptr);
				assemblyLineInBack->setNext(temp);
				assemblyLineInBack = temp;
			}
			// skip over empty starting Disk
			assemblyLineIn = assemblyLineIn->getNext();
		}
		void unloadRobot();
		void process();
		string printALOut();
};
void AssemblyLine::unloadRobot() {
	assemblyLineOutBack->setNext(robotArm);
	assemblyLineOutBack = robotArm;
	robotArm = new Pyramid(nullptr, nullptr);
}
void AssemblyLine::process() {
	int last = -1;
	// process all Disk queue elements
	while (assemblyLineIn != nullptr) {
		if (assemblyLineIn->getRadius() >= last) {
			robotArm->push(assemblyLineIn->getRadius());
			last = assemblyLineIn->getRadius();
			assemblyLineIn = assemblyLineIn->getNext();
		} else {
			unloadRobot();
			// reset last, so a new robotArm can be created
			last = -1;
		}
	}
	// skip over empty starting Pyramid
	assemblyLineOut = assemblyLineOut->getNext();
	// unload any remaining elements left after Disk queue was emptied
	unloadRobot();
}
string AssemblyLine::printALOut() {
	string ret = "";
	ret += "[";
	while (assemblyLineOut != nullptr) {
		ret += "[";
		while (!assemblyLineOut->empty()) {
			ret += to_string(assemblyLineOut->peek()->getRadius());
			assemblyLineOut->pop();
			// if next element to list exists
			if (!assemblyLineOut->empty()) {
				ret += ", ";
			}
		}
		ret += "]";
		assemblyLineOut = assemblyLineOut->getNext();
		// if next Pyramid to list exists
		if (assemblyLineOut != nullptr) {
			ret += ", ";
		}
	}
	ret += "]";
	return ret;
}

int main() {
	string name;
	cout << "Enter the name of the file you'd like to read from:\n";
	cin >> name;

	srand((unsigned int)time(0));

	ifstream infile(name);
	ofstream outfile("result.txt");

	int n;
	while (infile >> n) {
		AssemblyLine line(n);
		line.process();
		outfile << line.printALOut() << "\n";
	}

	return 0;
}
