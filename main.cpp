#include <iostream>
#include <conio.h>
#include <random>
#include <Windows.h>

using std::cout;
using std::endl;
using std::cin;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

template<typename TValueL>
void delete_value(TValueL*& value)
{
	delete value;
	value = nullptr;
}

template<typename TValue>
bool leap_year(TValue year)
{
	if (year % 4 != 0) { return false; }
	else if (year % 100 != 0) { return true; }
	else if (year % 400 == 0) { return true; }
	else { return false; }
}

template<typename TReturn, typename TValueR>
TReturn* get_value(TValueR message, bool is_month, bool is_year = false, int month = 0, int year = 0)
{
	TReturn result;
	short data[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (leap_year(year))
	{
		data[1] = 29;
	}

	do {
		cout << message;
		cin >> result;

		if (is_year && result < 0)
		{
			cout << "|=== Error: Invalid year!" << endl;
			continue;
		}

		if ((!is_year && !is_month && result < 0) || (is_month && (result > 12 || result < 1)))
		{
			cout << "|=== Error: Invalid month!" << endl;
			continue;
		}
		if (!is_year && !is_month && (result < 1 || result > data[month - 1]))
		{
			cout << "|=== Error: Invalid day for the given month!" << endl;
			continue;
		}

		break;
	} while (true);

	return new TReturn(result);
}

template<typename TReturn, typename TValue>
TReturn recalculation(TValue year, TValue month, bool is_month)
{
	TReturn result{};
	short data[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (leap_year(year))
	{
		data[1] = 29;
	}

	if (is_month)
	{
		for (int i = 1; i < month; i++)
		{
			result += data[i - 1];
		}
	}
	else
	{
		for (int i = 1; i < year; i++)
		{
			if (leap_year(i))
			{
				result += 366;
			}
			else
			{
				result += 365;
			}
		}
	}

	return TReturn(result);
}

int main()
{
	cout << "|- The first date" << endl;
	unsigned long long* first_year = get_value<unsigned long long, const char[]>("|  Enter the year: ", false, true);
	unsigned long long* first_month = get_value<unsigned long long, const char[]>("|  Enter the month: ", true);
	long long* first_day = get_value<long long, const char[]>("|  Enter the day: ", false, false, *first_month, *first_year);
	cout << endl;

	cout << "|- The second date" << endl;
	unsigned long long* second_year = get_value<unsigned long long, const char[]>("|  Enter the year: ", false, true);
	unsigned long long* second_month = get_value<unsigned long long, const char[]>("|  Enter the month: ", true);
	unsigned long long* second_day = get_value<unsigned long long, const char[]>("|  Enter the day: ", false, false, *second_month, *second_year);
	cout << endl;
	

	cout << "First year: " << (leap_year(*first_year) ? "leap" : "not leap") << endl;
	cout << "Second year: " << (leap_year(*second_year) ? "leap" : "not leap") << endl;


	*first_month = recalculation<int, int>(*first_year, *first_month, true);
	*first_year = recalculation<int, int>(*first_year, *first_month, false);

	*second_month = recalculation<int, int>(*second_year, *second_month, true);
	*second_year = recalculation<int, int>(*second_year, *second_month, false);

	*first_day += *first_month + *first_year - *second_day + *second_month + *second_year;

	if (*first_day < 0)
	{
		*first_day = -(*first_day);
	}

	
	cout << "The difference between the dates is " << *first_day << " days" << endl;

	delete_value(first_year);
	delete_value(first_month);
	delete_value(first_day);
	delete_value(second_year);
	delete_value(second_month);
	delete_value(second_day);

	char ch = _getch();
	return 0;
}
