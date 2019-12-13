// ConsoleApplication11.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include "pch.h"
#include <iostream>

using namespace std;

const int maxn = 100;

int a[maxn];

int mas[maxn];

int n;

void msort(int l, int r) {

	if (r == l)
		return;

	if (r - l == 1) {

		if (a[r] < a[l])

		{

			int var = a[r];
			a[r] = a[l];
			a[l] = var;

		}

		return;

	}

	int m = (r + l) / 2;

	msort(l, m);
	msort(m + 1, r);

	int xl = l;
	int xr = m + 1;
	int cur = 0;

	while (r - l + 1 != cur) {

		if (xl > m)
			mas[cur++] = a[xr++];
		else if (xr > r)
			mas[cur++] = a[xl++];
		else if (a[xl] > a[xr])
			mas[cur++] = a[xr++];
		else mas[cur++] = a[xl++];

	}

	for (int i = 0; i < cur; i++)
		a[i + l] = mas[i];
}

int main() {

	setlocale(LC_ALL, "Russian");
	cout << "Введите кол-во элементов: ";
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	msort(0, n - 1);

	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

	system("pause");

}
