// TimeTracker.cpp
// Author: Aidan Din
// Creates a class that manages and modifies times.

#include <iostream>
using namespace std;

class Time {
	int hour, min, sec;

	public:
		// constructors
		Time(int s) {
			sec = s;
			min = 0;
			hour = 0;
		}
		Time(int h, int m, int s) {
			hour = h;
			min = m;
			sec = s;
		}
		// returns the sum of two times
		Time add(Time other) {
			Time newTime(hour, min, sec);
			newTime.setHour(newTime.getHour() + other.getHour());
			newTime.setMin(newTime.getMin() + other.getMin());
			newTime.setSec(newTime.getSec() + other.getSec());
			newTime.adjust();
			return newTime;
		}
		// returns the difference of two times
		Time subtract(Time other) {
			other.setHour(- other.getHour());
			other.setMin(- other.getMin());
			other.setSec(- other.getSec());
			return add(other);
		}
		// increases current time by given secs
		Time increaseBy(int s) {
			return increaseBy(0, 0, s);
		}
		// increases current time by given args
		Time increaseBy(int h, int m, int s) {
			hour += h;
			min += m;
			sec += s;
			adjust();
			return *this;
		}
		// properly re-formats the time
		void adjust() {
			min += sec / 60;
			sec %= 60;
			hour += min / 60;
			min %= 60;
		}
		// returns the time in HH:MM:SS format
		string toString() {
			string ret = "";
			if (hour < 10) ret += '0';
			ret += to_string(hour) + ':';
			if (min < 10) ret += '0';
			ret += to_string(min) + ':';
			if (sec < 10) ret += '0';
			ret += to_string(sec);
			return ret;
		}
		// setters
		void setHour(int h) {
			hour = h;
		}
		void setMin(int m) {
			min = m;
			adjust();
		}
		void setSec(int s) {
			sec = s;
			adjust();
		}
		// getters
		int getHour() {
			return hour;
		}
		int getMin() {
			return min;
		}
		int getSec() {
			return sec;
		}
};

int main() {
	bool repeat = true;
	while (repeat) {
		int choice;
		cout << "What would you like to do?\n1. Add 2 times\n2. Subtract 2 times\n3. Increase a time by hours, seconds, and minutes\n4. Increase a time by seconds\n";
		cin >> choice;
		// times
		int h, m, s;
		cout << "Enter a time in hours, minutes, and seconds (Space separated):\n";
		cin >> h >> m >> s;
		Time first(h, m, s);
		Time second(0);
		// add/subtract methods
		if (choice == 1 || choice == 2) {
			cout << "Enter a second time in the same format:\n";
			cin >> h >> m >> s;
			second.setHour(h);
			second.setMin(m);
			second.setSec(s);
		// increase methods
		// re-use ints h, m, and s for time increases since times are already constructed
		} else if (choice == 3) {
			cout << "Enter how many hours, minutes, and seconds you would like to increase the time by (Space separated):\n";
			cin >> h >> m >> s;
		} else if (choice == 4) {
			cout << "Enter how many seconds you would like to increase the time by:\n";
			cin >> s;
		} else {
			cout << "Invalid choice!" << endl;
			return 1;
		}
		// Invoke methods
		switch (choice) {
			case 1:
				cout << "The sum of both times: " + first.add(second).toString();
				break;
			case 2:
				cout << "The difference of both times: " + first.subtract(second).toString();
				break;
			case 3:
				first.increaseBy(h, m, s);
				cout << "The time increased by given H/M/S: " + first.toString();
				break;
			case 4:
				first.increaseBy(s);
				cout << "The time increased by given seconds: " + first.toString();
				break;
		}
		cout << "\n";
		cout << "Do you want to re-run this program? Enter 1 for yes and 0 for no.\n";
		cin >> repeat;
	}
	cout << flush;
	return 0;
}
