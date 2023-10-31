#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High) //Генерування
{
	for (int i = 0; i < size; i++)
		a[i] = Low + rand() % (High - Low + 1);
}

void Print(int* a, const int size) // Виведення
{
	for (int i = 0; i < size; i++)
		cout << a[i] << setw(4);
	cout << endl;
}

template <typename T> // Шаблон обчислення к-сті від'ємних елементів масиву
T Negative(T *a, T size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (a[i] < 0)
			count++;
	}
	return count;
}

int CalcNegative(int* a, int size) //Звичайна функція (ітерація)
{
	int count = 0;
	for (int i = 0; i < size; i++)
		if (a[i] < 0)
			count++;
	return count;
}

int main()
{
	const int n = 25;
	int a[n];
	int Low = -20;
	int High = 20;

	Create(a, n, Low, High);
	Print(a, n);
	cout << "Negative elements(by typename) : " << Negative(a, n) << endl;
	cout << "Negative elements(by standart function) : " << CalcNegative(a, n);

	return 0;
}