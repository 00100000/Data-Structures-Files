// Duration.cpp
// Author: Aidan Din

#include <iostream>
#include <random>
using namespace std;

class Duration {
	int hour, min, sec;

	public:
		Duration() {
			hour = 0;
			min = 0;
			sec = 0;
		}
		Duration(int h) {
			hour = h;
			min = 0;
			sec = 0;
		}
		Duration(int h, int m) {
			hour = h;
			min = m;
			sec = 0;
		}
		Duration(int h, int m, int s) {
			hour = h;
			min = m;
			sec = s;
		}
		// adds two Durations
		Duration operator + (Duration& d) {
			Duration ret(hour + d.hour, min + d.min, sec + d.sec);
			ret.adjust();
			return ret;
		}
		// subtracts two Durations
		Duration operator - (Duration& d) {
			Duration ret(hour - d.hour, min - d.min, sec - d.sec);
			ret.adjust();
			return ret;
		}
		// multiplies a Duration by a constant
		Duration operator * (double d) {
			Duration ret(0, 0, toSecs() * d);
			ret.adjust();
			return ret;
		}
		// divides a Duration by a constant
		Duration operator / (double d) {
			Duration ret(0, 0, toSecs() / d);
			ret.adjust();
			return ret;
		}
		// divides two Durations
		double operator / (Duration& d) {
			return (double)toSecs() / (double)d.toSecs();
		}
		// converts the Duration in HH:MM:SS format
		friend ostream& operator << (ostream &stream, Duration const& d) {
			string s = "";
			if (d.hour < 10) s += '0';
			s += to_string(d.hour) + ':';
			if (d.min < 10) s += '0';
			s += to_string(d.min) + ':';
			if (d.sec < 10) s += '0';
			s += to_string(d.sec);
			stream << s << endl;
			return stream;
		}
		// randomizes this Duration
		void randomize() {
			hour = 0;
			min = 0;
			sec = rand() % 86401;
			adjust();
		}
		// get the duration in seconds
		int toSecs() {
			return hour * 3600 + min * 60 + sec;
		}
		// properly re-formats the Duration
		void adjust() {
			if (toSecs() < 0) {
				hour = 0;
				min = 0;
				sec = 0;
			} else {
				min += sec / 60;
				sec %= 60;
				hour += min / 60;
				min %= 60;
			}
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
	bool repeat = false;
	do {
		// input
		int choice;
		cout << "What would you like to do?\n1. Add two durations\n2. Subtract two durations\n3. Divide two durations\n4. Generate a duration under 24 hours\n5. Multiply a duration by a constant\n6. Divide a duration by a constant\n";
		cin >> choice;

		Duration one, two;
		int a, b, c;
		double constant;
		if (choice != 4) {
			cout << "Enter a duration in hours, minutes, and seconds (Space separated):\n";
			cin >> a >> b >> c;
			one = Duration(a, b, c);
		}
		if (choice < 4) {
			cout << "Enter second a duration in hours, minutes, and seconds (Space separated):\n";
			cin >> a >> b >> c;
			two = Duration(a, b, c);
		} else if (choice > 4) {
			cout << "Enter a constant:\n";
			cin >> constant;
		}
		// output
		switch (choice) {
			case 1: {
				Duration sum = one + two;
				cout << sum;
				break;
			}
			case 2: {
				Duration diff = one - two;
				cout << diff;
				break;
			}
			case 3: {
				double quot = one / two;
				cout << quot;
				break;
			}
			case 4: {
				Duration randDur;
				randDur.randomize();
				cout << randDur;
				break;
			}
			case 5: {
				Duration prod = one * constant;
				cout << prod;
				break;
			}
			case 6: {
				Duration quot = one / constant;
				cout << quot;
				break;
			}
		}
		// re-run
		cout << "\nWould you like to run this program again?\n1 for yes, 0 for no\n";
		cin >> repeat;
	} while (repeat);
	cout << flush;
	return 0;
}