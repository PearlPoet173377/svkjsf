#include<iostream>
using namespace std;

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int* arr, const int n);
void Print(int arr[], const int n);

void FillRand(int** arr, const int m, const int n);
void Print(int** arr, const int m, const int n);

//добавление элементов
int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);

//удаление элементов
int* pop_back(int arr[], int& n);

int** push_row_back(int** arr, int& m, const int n);

//#define DYNAMIC_MEMORY1
#define DYNAMIC_MEMORY2

void main()
{
#ifdef DYNAMIC_MEMORY1
	int n;
	cout << "Write size of array: "; cin >> n;
	/*int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);

	int brr[5];
	cout << brr << endl;
	FillRand(brr, 5);
	Print(brr, 5);

	delete[] arr;*/
	int* arr = new int[n];
	/*int s_arr[5];
	cout << sizeof(arr) << endl << sizeof(s_arr) << endl;*/
	int value;
	FillRand(arr, n);
	cout << "Write value: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	cout << "Delete part of array: "; cin >> n; cout << endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	delete[] arr;
#endif

	int m; //stroki
	int n; //stolbci
	cout << "Stroki: "; cin >> m;
	cout << "Stolbci: "; cin >> n;

	//1) Создаем массив указателей
	int** arr = new int* [m];
	for (int i = 0; i < m; i++)
	{
		arr[i] = new int[n]{};
	}

	/// Using array

	FillRand(arr, m, n);
	Print(arr, m, n);
	cout << endl;
	arr = push_row_back(arr, m, n);
	Print(arr, m, n);

	/// Delete array


	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

void FillRand(int* arr, const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; // первый вариант обращения к динам массиву(по адресу)
	}
}

void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t"; //обращение по индексу
	}
	cout << endl;
}

int* push_back(int arr[], int& n, int value)
{
	//добавление значения в конец массива
	//1)создаем буф массив нужного размера(+1 элемент)
	int* buffer = new int[n + 1];
	//2)копируем значения из исходника в буф
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	//3)удаляем массив исходник
	delete[] arr;
	//4)подменяем адрес старого массива адресом нового
	arr = buffer;
	//после этого в массиве arr появился еще один элемент который можно положить еще одно значение
	//5)помещаем добавляемое значение в конец массива:
	arr[n] = value;
	//6)после того как в массив добавился элемент, кол-во его элементов увеличилось на 1
	n++;
	//7)mission complete - значение добавлено
	return arr;
}

int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	return buffer;
}


void FillRand(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = rand() % 100; 
		}
	}
}

void Print(int** arr, const int m, const int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
}

int** push_row_back(int** arr, int& m, const int n)
{
	int** buffer = new int* [m + 1];
	for (int i = 0; i < m + 1; i++)
	{
		buffer[i] = new int[n] {};
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	m++;
	return buffer;
}