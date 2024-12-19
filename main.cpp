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

template<typename TValueL, typename TValueR>
int _compare(bool value, TValueL a, TValueR b)
{
	if (value) { return a < b; }
	else { return a > b; }
}

template<typename TValue>
void sorting(TValue* arr, int start, int end, bool value)
{
	for (int i = start + 1; i < end; i++)
	{
		TValue key = arr[i];
		int j = i - 1;

		while (j >= start && _compare<int, int>(value, key, arr[j]))
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = key;
	}
}

template<typename TValue>
void algorithm(TValue* arr, int* size)
{
	int new_size = *size / 2;

	sorting(arr, 0, new_size, true);
	sorting(arr, new_size, *size, false);
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr<int>(arr, size);
	print_arr<int, const char>(arr, size, "Array: ");
	
	algorithm<int>(arr, size);
	print_arr<int, const char>(arr, size, "Result: ");

	delete_value<int>(arr, false);
	delete_value<int>(size, ' ');

	char ch = _getch();
	return 0;
}