// Lesson12.cpp
// Author: Aidan Din
// Updates the date class properly, and creates a unique date conversion operator

#include <iostream>
using namespace std;

int maxDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Date {
	private:
		int day, month, year;

	public:
		Date(int inMonth, int inDay, int inYear)
			: month(inMonth), day(inDay), year(inYear) {
				adjust();
			};

		Date& operator ++ () {
			++day;
			this->adjust();
			return *this;
		}

		Date& operator -- () {
			--day;
			this->adjust();
			return *this;
		}

		Date operator ++ (int) {
			Date copy(month, day, year);
			++day;
			copy.adjust();
			return copy;
		}

		Date operator -- (int) {
			Date copy(month, day, year);
			--day;
			copy.adjust();
			return copy;
		}

		operator int() const {
			int ret = year * 365 + day;
			for (int i = 0; i < month; i++) {
				ret += maxDays[i];
			}
			return ret;
		}

		void adjust() {
			month += day / (maxDays[month] + 1);
			day %= (maxDays[month] + 1);
			year += month / 13;
			month %= 13;
		}

		void DisplayDate() {
			cout << month << " / " << day << " / " << year << endl;
		}
};

int main() {
	Date holiday(12, 25, 2016);
	Date fourHundred(1, 4, 1);

	cout << "The date object is initialized to: ";
	holiday.DisplayDate();

	++holiday;
	cout << "Date after prefix-increment is: ";
	holiday.DisplayDate();

	--holiday;
	cout << "Date after a prefix-decrement is: ";
	holiday.DisplayDate();

	float toDays = fourHundred;
	cout << toDays << endl;
	return 0;
}