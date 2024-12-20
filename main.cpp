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
void delete_value(TValueL*& value, char indicator)
{
	delete value;
	value = nullptr;
}
template<typename TValueL>
void delete_value(TValueL*& arr, bool indicator)
{
	delete[] arr;
	arr = nullptr;
}

template<typename TValue>
void init_arr(TValue* arr, int* size)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(-20, 20);

	for (int i = 0; i < *size; i++)
	{
		arr[i] = dist(gen);
	}
}

template<typename TValueL, typename TValueR>
void print_arr(TValueL* arr, int* size, TValueR* message)
{
	cout << message;
	for (int i = 0; i < *size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

template<typename TReturn, typename TValue>
TReturn _compare(TValue value, int indicator)
{
	if (indicator == 1) { return TReturn(value > 0); }
	else if (indicator == 0) { return TReturn(value < 0); }
	else { return TReturn(value = 0); }
}

template<typename TReturn, typename TValue>
TReturn finder(TValue* arr, int* size, int value)
{
	TReturn result{};

	for (int* ptr = arr; ptr < arr + *size; ptr++)
	{
		if (_compare<bool>(*ptr, value))
		{
			result += 1;
		}
	}

	return TReturn(result);
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr<int>(arr, size);
	print_arr<int, const char>(arr, size, "Array: ");

	cout << "Number of positive elements: " << finder<int, int>(arr, size, 1) << endl;
	cout << "Number of negative elements: " << finder<int, int>(arr, size, 0) << endl;
	cout << "Number of elements equal zero: " << finder<int, int>(arr, size, -1) << endl;

	delete_value<int>(arr, false);
	delete_value<int>(size, ' ');

	char ch = _getch();
	return 0;
}