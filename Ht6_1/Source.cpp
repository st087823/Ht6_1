#include <iostream>
#include <cstdlib> // system("pause");
#include"ArrayList.h"
#define N 10
using namespace std;

void meny() {
	cout << "0 - Выйти из программы" << endl;
	cout << "1 - Добавить элемент, введенный с клавиатуры" << endl;
	cout << "2 - Вывести массив" << endl;
	cout << "3 - Проверить, является ли массив симметричным" << endl;
	cout << "4 - Циклический сдвинуть массив на n элементов. n>0 - сдвиг вправо, n<0 - сдвиг влево." << endl;
	cout << "5 - Проверить, может ли массив стать симметричным, если из него удалить один элемент." << endl;
}

void check(ArrayList& a, int x) {
	if (x == 1) {
		int element = 0;
		cout << "Ввелите эл-т, который необходимо добавить" << endl;
		cin >> element;
		a.add(x);
	}

	if (x == 2) {
		cout << a.toString() << endl;
	}
	if (x == 3) {
		int check = 0;
		for (int i = 0; i <= (a.length() - 1 )/ 2; i++)
		{
			if (a.get(i) != a.get(a.length() - 1 - i)) {
				check++;
			}
		}
		if (check==0) cout << "Массив симметричен" << endl;
		else cout << "Массив не симметричен" << endl;
	}
	if (x == 4) {
		int n = 0;
		cout << "Введите сдвиг" << endl;
		cin >> n;
		if (n < 0) 
		{
			n *= -1;
			n = n % a.length();
			for (int j = 0; j = n; j++) {
				int i = 0;
				int temp = a.get(0);
				for (int i = 0; i < a.length() - 1; i++) {
					a.set(i, a.get(i + 1));
				}
				a.set(a.length() - 1, temp);
			}
		}
		if (n >= 0) 
		{
			n = n % a.length();
			for (int j = 0; j = n; j++) {
				int i = 0;
				int temp = a.get(a.length() - 1);
				for (int i = a.length() - 1; i > 0; i--) {
					a.set(i, a.get(i - 1));
				}
				a.set(0, temp);
			}
		}
	}
	if (x == 5) {
		ArrayList b(a);
		for (int i = 0; i < a.length(); i++)
		{
			int check = 0;
			b.remove(i);
			for (int i = 0; i < b.length() / 2; i++)
			{
				if (b.get(i) != b.get(b.length() - 1 - i)) check++;
			}
			if (check == 0)
			{
				cout << "При удалении эл-та "<< b.get(i) <<" массив симметричен " << endl;
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	ArrayList a;
	int x = 1;
	int n = 0;

	while (x != 0) {
		system("cls");
		meny();
		cin >> x;
		check(a, x);
		system("pause");
	}
	return 0;
}