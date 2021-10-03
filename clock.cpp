#include <iostream>
using namespace std;

class Clock
{
private:
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;

public:
	Clock(unsigned int h,
	      unsigned int m,
	      unsigned int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}

	~Clock()
	{
		std::cout << "hours : " << hours << "\n";
		std::cout << "minutes : " << minutes << "\n";
		std::cout << "seconds : " << seconds << "\n";
		std::cout << "\n";
	}

	Clock operator ++()
	{
		seconds++;
		if (seconds > 60)
		{
			seconds = 0;
			minutes++;
		}
		if (minutes > 60)
		{
			minutes = 0;
			hours++;
		}
		if (hours > 24)
		{
			hours = 0;
		}
		
		return *this;
	}

	Clock operator --()
	{
		if (seconds == 0)
		{
			seconds = 0;
			if (minutes == 0)
			{
				if (hours == 0)
				{
					hours = 0;
				}
				else
					hours--;
			}
			else
				minutes--;
		}
		else
			seconds--;

		return *this;
	}

	Clock& operator -(const Clock& deductThis)
	{
		if (this != &deductThis)
		{
			hours = deductThis.hours;
			minutes = deductThis.minutes;
			seconds = deductThis.seconds;
		}
		return *this;
	}

	bool operator !=(const Clock& checkEquality) const
	{
		return hours != checkEquality.hours && minutes != checkEquality.minutes && seconds != checkEquality.seconds;
	}

	Clock& operator =(const Clock& copyFrom)
	{
		if (this != &copyFrom)
		{
			hours = copyFrom.hours;
			minutes = copyFrom.minutes;
			seconds = copyFrom.seconds;
		}
		return *this;
	}

	friend void print(const Clock& toPrint);
};

void print(const Clock& toPrint)
{
	std::cout << "hours : " << toPrint.hours << "\n";
	std::cout << "minutes : " << toPrint.minutes << "\n";
	std::cout << "seconds : " << toPrint.seconds << "\n";
	std::cout << "\n";
}

int main()
{
	Clock c1(20, 15, 57);
	Clock* c2 = new Clock(18, 24, 55);

	c2++;
	c2--;

	cout << "Are unequal : " << (c1 != *c2) << "\n";;
	
	return 0;
}
