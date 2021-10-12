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
			return this;
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
			ret += hour + ':';
			if (min < 10) ret += '0';
			ret += min + ':';
			if (sec < 10) ret += '0';
			ret += sec;
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
		cout << "Do you want to re-run this program? Enter 1 for yes and 0 for no.\n";
		cin >> repeat;
	}
	cout << endl;
	return 0;
}