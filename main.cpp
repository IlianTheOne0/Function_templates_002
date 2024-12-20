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

template<typename TReturn, typename TValue>
TReturn _mean(TValue* arr, int* size)
{
	TReturn result{};

	for (int* ptr = arr; ptr < arr + *size; ptr++)
	{
		result += *ptr;
	}

	return TReturn(result / *size);
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr<int>(arr, size);
	print_arr<int, const char>(arr, size, "Array: ");

	cout << "Arithmetic mean: " << _mean<double, int>(arr, size) << endl;

	delete_value<int>(arr, false);
	delete_value<int>(size, ' ');

	char ch = _getch();
	return 0;
}