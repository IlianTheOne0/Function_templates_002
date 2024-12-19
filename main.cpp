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

template<typename TValue>
void finder(TValue* arr, int* size, int* new_size, int*& minL, int*& minR)
{
	for (int i = 1; i < *new_size; i++)
	{
		if (arr[i] < arr[*minL])
		{
			*minL = i;
		}
	}
	for (int i = *new_size + 1; i < *size; i++)
	{
		if (arr[i] < arr[*minR])
		{
			*minR = i;
		}
	}
}

template<typename TValue>
void _delete(TValue*& v1, TValue*& v2, TValue*& v3, TValue*& v4, TValue*& v5)
{
	delete_value<int>(v1, false);
	delete_value<int>(v2, ' ');
	delete_value<int>(v3, ' ');
	delete_value<int>(v4, ' ');
	delete_value<int>(v5, ' ');
}

template<typename TValue>
void sorting(TValue* arr, int* size, int* start, int* end)
{
    for (int i = *start; i <= *end; i++)
    {
        for (int j = *start; j < *end - (i - *start) - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                TValue temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

	print_arr<int, const char>(arr, size, "Result (in ascending order): ");
}

int main()
{
	int* size = new int{ 10 };
	int* arr = new int[*size];
	init_arr<int>(arr, size);
	print_arr<int, const char>(arr, size, "Array: ");


	int* new_size = new int{ *size / 2 };
	int* minL = new int{};
	int* minR = new int{ *new_size + 1 };

	finder<int>(arr, size, new_size, minL, minR);
	cout << endl
		<< "Minimal element on the left part of array: " << arr[*minL] << endl
		<< "Minimal element on the right part of array: " << arr[*minR] << endl;
	if (arr[*minL] >= 0 || arr[*minR] >= 0)
	{
		cout << endl << endl << "Sorting between negative elements is not possible" << endl;

		_delete<int>(arr, size, new_size, minL, minR);
		char ch = _getch();
		return 0;
	}

	cout << endl;
	sorting<int>(arr, size, minL, minR);


	_delete<int>(arr, size, new_size, minL, minR);
	char ch = _getch();
	return 0;
}