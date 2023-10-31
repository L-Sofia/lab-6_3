#include <iostream>
#include <iomanip>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) // Генерація
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i) // Виведення
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int CalcNegative(int* a, const int size, int i, int &count) //Звичайна функція (рекурсія)
{
	if (a[i] < 0)
		count++;
	if (i < size - 1)
		return CalcNegative(a, size, i + 1, count);
	else
		return count;
}

template <typename T> // Шаблон обчислення к-сті від'ємних елементів масиву
T Negative(T* a, T size, T i, T &count)
{
	if (a[i] < 0)
		count++;
	if (i < size - 1)
		return Negative(a, size, i + 1, count);
	else
		return count;
}



int main()
{
	const int n = 25;
	int a[n];
	int Low = -18;
	int High = 38;
	int c = 0;
	int d = 0;

	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "Negative elements (by standart function): " << CalcNegative(a, n, 0, c) << endl;
	cout << "Negative elements (by template): " << Negative(a, n, 0, d) << endl;

	return 0;
}
