// duration.h
// Author: Aidan Din
// duration header file

#ifndef DURATION
#define DURATION

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
		Duration operator + (Duration d) {
			Duration ret(hour + d.hour, min + d.min, sec + d.sec);
			ret.adjust();
			return ret;
		}
		// subtracts two Durations
		Duration operator - (Duration d) {
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
		double operator / (Duration d) {
			return (double)toSecs() / (double)d.toSecs();
		}
		// converts the Duration in HH:MM:SS format
		friend ostream& operator << (ostream& stream, Duration const& d) {
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

#endif