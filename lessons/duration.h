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
		Duration operator + (Duration d);
		Duration operator - (Duration d);
		Duration operator * (double d);
		Duration operator / (double d);
		double operator / (Duration d);
		friend ostream& operator << (ostream& stream, Duration const& d);
		void randomize();
		int toSecs();
		void adjust();
		void setHour(int h);
		void setMin(int m);
		void setSec(int s);
		int getHour();
		int getMin();
		int getSec();
};
// adds two Durations
Duration Duration::operator + (Duration d) {
	Duration ret(hour + d.hour, min + d.min, sec + d.sec);
	ret.adjust();
	return ret;
}
// subtracts two Durations
Duration Duration::operator - (Duration d) {
	Duration ret(hour - d.hour, min - d.min, sec - d.sec);
	ret.adjust();
	return ret;
}
// multiplies a Duration by a constant
Duration Duration::operator * (double d) {
	Duration ret(0, 0, toSecs() * d);
	ret.adjust();
	return ret;
}
// divides a Duration by a constant
Duration Duration::operator / (double d) {
	Duration ret(0, 0, toSecs() / d);
	ret.adjust();
	return ret;
}
// divides two Durations
double Duration::operator / (Duration d) {
	return (double)toSecs() / (double)d.toSecs();
}
// converts the Duration in HH:MM:SS format
ostream& operator << (ostream& stream, Duration const& d) {
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
void Duration::randomize() {
	hour = 0;
	min = 0;
	sec = rand() % 86401;
	adjust();
}
// get the duration in seconds
int Duration::toSecs() {
	return hour * 3600 + min * 60 + sec;
}
// properly re-formats the Duration
void Duration::adjust() {
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
void Duration::setHour(int h) {
	hour = h;
}
void Duration::setMin(int m) {
	min = m;
	adjust();
}
void Duration::setSec(int s) {
	sec = s;
	adjust();
}
// getters
int Duration::getHour() {
	return hour;
}
int Duration::getMin() {
	return min;
}
int Duration::getSec() {
	return sec;
}

#endif