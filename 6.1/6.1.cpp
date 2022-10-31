#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int* t, const int size, const int Low, const int High)
{
	for (int i = 0; i < size; i++)
		t[i] = Low + rand() % (High - Low + 1);
}
void Create1(int* t, const int size, const int Low, const int High, int i)
{
	t[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create1(t, size, Low, High, i + 1);
}

void Print(int* t, const int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << t[i];
	cout << endl;
}
void Print1(int* t, const int size, int i)
{
	cout << setw(4) << t[i];
	if (i < size - 1)
		Print1(t, size, i + 1);
	else
		cout << endl;
}
int Sum(int* t, const int size)
{
	int S = 0;
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i>0 and (i % 2) == 0)
			S += t[i], k++;
	cout << "kilkist elementiv = " << k << endl;
	cout << "syma = " << S << endl;
	return S;
	
}
int Sum1(int* t, const int size, int i, int S, int k)
{
	if (i > 0 and (i % 2) == 0)
		S += t[i], k++;
	if (i < size - 1)
		return Sum1(t, size, i + 1, S, k);
	else
		cout << "syma = " << S << endl;
		return k;
}

int main()
{
	srand((unsigned)time(NULL));
	const int n = 25;
	int t[n];
	int Low = -5;
	int High = 12;
	
    Create(t, n, Low, High);
	Create1(t, n, Low, High, 0);
	Print(t, n);
	Print1(t, n, 0);
	cout << "rekyrsiya" << endl;
	Sum(t, n);
	cout << "iteratsiya" << endl;
	cout << "kilkist elementiv = " << Sum1(t, n, 0, 0, 0) << endl;
	return 0;
}