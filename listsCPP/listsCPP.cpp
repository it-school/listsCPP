#include "pch.h"
#include <iostream>
#include <locale.h>

using namespace std;

typedef long BT;
struct Item
{
	BT Inf;
	Item *Next;
};

Item *addToHead(Item *First, BT X)
{
	Item *Vsp;
	Vsp = (Item *)malloc(sizeof(Item));
	Vsp->Inf = X;
	Vsp->Next = First;
	First = Vsp;
	return First;
}

Item *removeFromHead(Item *First)
{
	Item *Vsp;
	Vsp = First->Next;
	free(First);
	return Vsp;
}

Item *addToList(Item *Pred, BT X)
{
	Item *Vsp;
	Vsp = (Item *)malloc(sizeof(Item));
	Vsp->Inf = X;
	Vsp->Next = Pred->Next;
	Pred->Next = Vsp;
	return Vsp;
}

BT removeFromList(Item *Pred)
{
	BT X;
	Item *Vsp;
	Vsp = Pred->Next;
	Pred->Next = Pred->Next->Next;
	X = Vsp->Inf;
	free(Vsp);
	return X;
}

void printList(Item *First)  // печать списка с начала
{
	Item *Vsp;
	Vsp = First;
	while (Vsp)
	{
		std::cout << Vsp->Inf << " (" << Vsp->Next << ") ";
		Vsp = Vsp->Next;
	}
	std::cout << "\n";
}

BT printListElement(Item *First, int n) 
{
	Item *Vsp;
	Vsp = First;
	int k = 0;
	while (Vsp && k < n)
	{
		Vsp = Vsp->Next;
		k++;
	}
	return Vsp->Inf;
}

int isEmpty(Item *First)  // проверка, пуст ли список
{
	return !First;
}

Item *clearList(Item *First)
{
	while (!isEmpty(First)) First = removeFromHead(First);
	return First;
}

int main() 
{
	setlocale(0, "ru");

	Item *S1, *S2, *S3, *S4, *V1, *V2 = nullptr, *V3 = nullptr, *V4 = nullptr;
	BT a;
	int i, n;

	S1 = nullptr;

	// создаём первый элемент
	a = -100 + rand() % 201;
	S1 = addToHead(S1, a);

	n = 3;
	// формируем список произвольной длины и выводим на печать
	V1 = S1;
	for (i = 2; i <= n; i++) {
		a = -100 + rand() % 201;
		V1 = addToList(V1, a);
	}
	printList(S1);

	V1 = S1;
	S2 = nullptr;
	S3 = nullptr;
	S4 = nullptr;
	while (V1)
	{
		if (V1->Inf > 0)
			if (S2) {
				addToList(V2, V1->Inf);
				V2 = V2->Next;
			}
			else 
			{
				S2 = addToHead(S2, V1->Inf);
				V2 = S2;
			};
		if (V1->Inf < 0)
			if (S3) 
			{
				addToList(V3, V1->Inf);
				V3 = V3->Next;
			}
			else {
				S3 = addToHead(S3, V1->Inf);
				V3 = S3;
			};

		if (V1->Inf == 0)
			if (S4)
			{
				addToList(V4, V1->Inf);
				V4 = V4->Next;
			}
			else {
				S4 = addToHead(S4, V1->Inf);
				V4 = S4;
			};

		V1 = V1->Next;
	}

	cout << "Результирующий список из положительных элементов: \n";
	printList(S2);
	cout << "Результирующий список из отрицательных элементов: \n";
	printList(S3);
	cout << "Результирующий список из 0: \n";
	printList(S4);

	cout << "\nElement at position 1: " << printListElement(S1, 1);

	S1 = clearList(S1);
	S2 = clearList(S2);
	S3 = clearList(S3);
	S4 = clearList(S4);


	return 0;
}