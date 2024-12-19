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
	uniform_int_distribution<int> dist(0, 99);

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

bool selection()
{
	int* value = new int{};
	
	do {
		cout << endl
			<< "How to sort a function?" << endl
			<< "1. In ascending order" << endl
			<< "2. In descending order" << endl
			<< "3. By default (ascending)" << endl
			<< "Option: ";
		cin >> *value;
		cout << endl;
	} while (*value > 3 || *value < 1);

	bool result;
	switch (*value)
	{
		case 1: { result = false; } break;
		case 2: { result = true; } break;
		case 3: { result = false; } break;
	}

	delete_value<int>(value, ' ');
	return result;
}

template<typename TValueL, typename TValueR>
int _compare(bool value, TValueL a, TValueR b)
{
	if (value) { return a < b; }
	else { return a > b; }
}

template<typename TValue>
void sorting(TValue* arr, int* size, bool value)
{
	for (int i = 1; i < *size; i++)
	{
		int temp_value = 0;
		while (_compare<int, int>(value, arr[i - 1], arr[i]))
		{
			temp_value = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp_value;

			i = 1;
		}
	}

	print_arr<int, const char>(arr, size, "Result: ");
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr<int>(arr, size);
	print_arr<int, const char>(arr, size, "Array: ");

	sorting<int>(arr, size, selection());

	delete_value<int>(arr, false);
	delete_value<int>(size, ' ');

	char ch = _getch();
	return 0;
}