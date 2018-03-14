// Lab.work-3.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "windows.h"
using namespace std;

struct Node
{
	char point[20];
	int reis;
	char name[12];
	char surname[12];
	char patr[12];
	char date[12];

	Node * next;
};

void Menu();
Node *addNode(Node *first);
Node *deleteNode(Node *first);
void outNode(Node *first);
void outNodeNum(Node *first);

int main()
{
	setlocale(LC_ALL, "Russian");

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Node *first = new Node;
	first->reis = 1021;
	strcpy_s(first->name, 20, "Воробьева");
	strcpy_s(first->surname, 20, "Татьяна");
	strcpy_s(first->patr, 20, "Юрьевна");
	strcpy_s(first->point, 20, "Москва");
	strcpy_s(first->date, 20, "12.02.2018");
	Node *f1 = new Node;
	f1->reis = 20;
	strcpy_s(f1->name, 20, "Ишмуратов");
	strcpy_s(f1->surname, 20, "Мурат");
	strcpy_s(f1->patr, 20, "Ринатович");
	strcpy_s(f1->point, 20, "Уфа");
	strcpy_s(f1->date, 20, "12.03.2018");
	Node *f2 = new Node;
	f2->reis = 3010;
	strcpy_s(f2->name, 20, "Луннова");
	strcpy_s(f2->surname, 20, "Алина");
	strcpy_s(f2->patr, 20, "Ринатовна");
	strcpy_s(f2->point, 20, "Казань");
	strcpy_s(f2->date, 20, "02.03.2018");
	Node *f3 = new Node;
	f3->reis = 4201;
	strcpy_s(f3->name, 20, "Яхина");
	strcpy_s(f3->surname, 20, "Альбина");
	strcpy_s(f3->patr, 20, "Маратовна");
	strcpy_s(f3->point, 20, "Рязань");
	strcpy_s(f3->date, 20, "15.03.2018");

	first->next = f1;
	f1->next = f2;
	f2->next = f3;
	f3->next = NULL;

	int k = 5;
	while (k != 6)
	{
		switch (k)
		{
		case 1: first = addNode(first); break;
		case 2: outNode(first); break;
		case 3:	outNodeNum(first); break;
		case 4: first = deleteNode(first); break;
		case 5: Menu(); break;
		case 6: break;
		default: cout << "  ОШИБКА! Числа от 1 до 6.\n";
		}
		cout << "\nВведите нужный пункт: ";
		cin >> k;
	}
	getchar();
	return 0;
}


void Menu()
{
	system("cls");
	cout << "\n";
	cout << "1 - Добавить заявку\n";
	cout << "2 - Вывести все заявки\n";
	cout << "3 - Вывести заявку по номеру рейса и дате вылета\n";
	cout << "4 - Удалить заявку\n";
	cout << "5 - Очистить экран\n";
	cout << "6 - Выход\n";
}

Node *addNode(Node *first)
{
	cout << "______________________________________________\n";
	Node *pv = new Node;
	cout << "Данные о заявке: \n";
	cout << "Введите пункт назначения > ";
	cin >> pv->point;
	cout << "Введите номер рейса > ";
	cin >> pv->reis;
	cout << "Введите фамилию пассажира > ";
	cin >> pv->name;
	cout << "Введите имя пассажира > ";
	cin >> pv->surname;
	cout << "Введите отчество пассажира > ";
	cin >> pv->patr;
	cout << "Введите дату вылета > ";
	cin >> pv->date;
	cout << "\n";
	pv->next = NULL;
	cout << "______________________________________________\n";
	if (first == NULL)
	{
		first = pv;
	}
	else
	{
		Node *p = first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = pv;
	}
	return first;
}

void outNode(Node *first)
{	cout << setiosflags(ios::right);
	cout << "_________________________________________________________________\n";
	cout << "Данные по заявкам:\n";
	cout << "       Пункт  Номер    Фамилия      Имя      Отчество        Дата\n";
	cout << "  назначения  рейса  --------- ДАННЫЕ ПАССАЖИРА -----      вылета\n";

	Node *pv = first;
	while (pv)
	{
		cout << setw(12) << pv->point << setw(7) << pv->reis << setw(11) << pv->name;
		cout << setw(10) << pv->surname << setw(13) << pv->patr << setw(12) << pv->date << endl;
		pv = pv->next;
	}
	cout << "_________________________________________________________________\n";
}

void outNodeNum(Node *first)
{
	int num;
	string dat;
	Node *pv = first;
	cout << "Введите номер рейса: ";
	cin >> num;
	cout << "Введите дату: ";
	cin >> dat;
	int n = 1, fl = 0;
	while (pv)
	{
		if (pv->reis == num && pv->date == dat)
		{
			outNode(pv);
			break;
		}
		pv = pv->next;
	}
}

Node *deleteNode(Node *first)
{
	cout << "______________________________________________\n";
	cout << "Номер рейса, заявку по которому удалить: ";
	int num;
	cin >> num;

	Node *temp = first;
	int k = -1;
	int N = 0;
	while (temp)
	{
		if (temp->reis == num)
		{
			k = N;
		}
		temp = temp->next;
		N++;
	}
	N--;
	if (k != -1)
	{
		temp = first;
		if (k == 0 && N == 0)
		{
			delete first;
			cout << "  Удаление прошло успешно!\n";
			cout << "______________________________________________\n";
			return NULL;
		}
		if (k == 0 && N > 0)
		{
			temp = temp->next;
			delete first;
			cout << "  Удаление прошло успешно!\n";
			cout << "______________________________________________\n";
			return temp;
		}
		Node *el = first;
		temp = first->next;
		while (temp->next)
		{
			if (temp->reis == num)
			{
				el->next = temp->next;
				delete temp;
				cout << "  Удаление прошло успешно!\n";
				cout << "______________________________________________\n";
				return first;
			}
			el = el->next;
			temp = temp->next;
		}

		el->next = NULL;
		delete temp;
		cout << "  Удаление прошло успешно!\n";
		cout << "______________________________________________\n";
		return first;
	}
	else
	{
		cout << "  Такого рейса нет или список пуст!\n";
		cout << "______________________________________________\n";
		return first;
	}
}
