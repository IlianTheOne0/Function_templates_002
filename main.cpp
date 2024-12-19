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

void delete_value(int*& value, char indicator)
{
	delete value;
	value = nullptr;
}
void delete_value(int*& arr, bool indicator)
{
	delete[] arr;
	arr = nullptr;
}

void init_arr(int* arr, int size)
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 99);

	for (int i = 0; i < size; i++)
	{
		arr[i] = dist(gen);
	}
}

void print_arr(int* arr, int* size)
{
	cout << "Array: ";
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

	delete_value(value, ' ');
	return result;
}

int _compare(bool value, int a, int b)
{
	if (value) { return a < b; }
	else { return a > b; }
}

void sorting(int* arr, int* size, bool value)
{
	for (int i = 1; i < *size; i++)
	{
		int temp_value = 0;
		while (_compare(value, arr[i - 1], arr[i]))
		{
			temp_value = arr[i];
			arr[i] = arr[i - 1];
			arr[i - 1] = temp_value;

			i = 1;
		}
	}

	print_arr(arr, size);
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr(arr, *size);
	print_arr(arr, size);

	sorting(arr, size, selection());

	delete_value(arr, false);
	delete_value(size, ' ');

	char ch = _getch();
	return 0;
}