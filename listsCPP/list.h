#pragma once
typedef long BT;
struct Item
{
	BT Inf;
	Item *Next;
};

Item *addToHead(Item *First, BT X);

Item *removeFromHead(Item *First);

Item *addToList(Item *Pred, BT X);

BT removeFromList(Item *Pred);

void printList(Item *First);

int isEmpty(Item *First);

Item *clearList(Item *First);