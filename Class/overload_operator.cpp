#include <iostream>
using namespace std;

class Time
{
private:
	// (0, 59)
	int second;
	// (0, 59)
	int minute;
	// (0, 23)
	int hour;
public:
	// construct function
	Time(int h = 0, int m = 0, int s = 0): hour(h), minute(m), second(s) {}
	// set function
	void setHour(int h);
	// set function
	void setMinute(int m);
	// set function
	void setSecond(int s);
	// make time regular
	void regular();
	// display function
	void show();

	// operator overload
	Time operator++();
	Time operator++(int);
	void operator=(const Time &t);
	bool operator<(const Time &t);
	bool operator>(const Time &t);
	bool operator==(const Time &t);
	Time operator+(const Time &t);
	friend ostream &operator<<(ostream &output, const Time &t);
	friend istream &operator>>(istream &input, Time &t);
};

// set function
void Time::setHour(int h)
{
	if (0 <= h && h <= 23)
		hour = h;
	else
		cout << "hour : over range" << endl;
}
// set function
void Time::setMinute(int m)
{
	if (0 <= m && m <= 59)
		minute = m;
	else
		cout << "minute : over range" << endl;
}
// set function
void Time::setSecond(int s)
{
	if (0 <= s && s <= 59)
		second = s;
	else
		cout << "second : over range" << endl;
}
// make time regular
void Time::regular()
{
	int sec_carry = second / 60;
	second = second % 60;
	minute += sec_carry;
	int min_carry = minute / 60;
	minute = minute % 60;
	hour = (hour + min_carry) % 24;
}
// display function
void Time::show()
{
	cout << hour << " : " << minute << " : " << second << endl;
}
// overload ++
Time Time::operator++()
{
	++second;
	regular();
	return Time(hour, minute, second);
}
Time Time::operator++(int)
{
	Time T(hour, minute, second);
	++second;
	regular();
	return T;
}
// overload =
void Time::operator=(const Time &t)
{
	hour = t.hour;
	minute = t.minute;
	second = t.second;
}
// overload ==
bool Time::operator==(const Time &t)
{
	if (hour == t.hour && minute == t.minute && second == t.second)
		return true;
	else
		return false;
}
// overload <
bool Time::operator<(const Time &t)
{
	if (hour < t.hour)
		return true;
	else if (hour == t.hour && minute < t.minute)
		return true;
	else if (hour == t.hour && minute == t.minute && second < t.second)
		return true;
	return false;
}
// overload >
bool Time::operator>(const Time &t)
{
	if (hour > t.hour)
		return true;
	else if (hour == t.hour && minute > t.minute)
		return true;
	else if (hour == t.hour && minute == t.minute && second > t.second)
		return true;
	return false;
}
// overload +
Time Time::operator+(const Time &t)
{
	Time t_result(hour + t.hour, minute + t.minute, second + t.second);
	t_result.regular();
	return t_result;
}
ostream &operator<<(ostream &output, const Time &t)
{
	output << t.hour << " : " << t.minute << " : " << t.second << endl;
	return output;
}
istream &operator>>(istream &input, Time &t)
{
	cout << "Please input time(hour, minute, second) : " <<endl;
	input >> t.hour >> t.minute >> t.second;
	t.regular();
	return input;
}

int main()
{
	Time t1(13, 47, 16), t2;

	cout << t1;
	cin >> t2;

	t2.show();

	return 0;
}