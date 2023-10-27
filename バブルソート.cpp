#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void InitRand()
{
	srand((unsigned int)time(NULL));
}

void InitRand(int* array, int arraysize)
{
	for (int i = 0; i < arraysize; ++i)
	{
		*(array + i) = rand() % 99 + 1;
	}
}

void Show(const int* const array, const int const arraysize)
{
	for (int i = 0; i < arraysize; ++i)
	{
		cout << *(array + i) << " " << flush;
	}
}

void BubbleSort(int* array, int arraysize)
{
	for (int i = 0; i < arraysize; ++i)
	{
		int keep = 0;
		for (int j = arraysize - 1; 0 < j; --j)
		{
			if (*(array + j) < *(array + j - 1))
			{
				keep = *(array + j);
				*(array + j) = *(array + j - 1);
				*(array + j - 1) = keep;
			}
		}
	}
}

int main()
{
	int arraysize;
	cout << "配列の大きさを決めてください > " << flush;
	cin >> arraysize;

	int* array = new int[arraysize];

	if (array == NULL)
	{
		*array = 0;

		cout << *array << endl;
		delete[] array;
	}

	InitRand();
	InitRand(array, arraysize);

	cout << "バブルソートをする前 " << flush;
	Show(array, arraysize);
	cout << endl;

	BubbleSort(array, arraysize);

	cout << "バブルソートをした後 " << flush;
	Show(array, arraysize);	
	cout << endl;
}