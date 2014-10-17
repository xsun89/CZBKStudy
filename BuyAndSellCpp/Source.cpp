#include <iostream>

using namespace std;

class Goods{
public:
	Goods(int weight) :weight_(weight)
	{
		totalWeight_ += weight;
	}
	~Goods(){
		totalWeight_ -= weight_;
	}
	static int GetTotalWeight()
	{
		return totalWeight_;
	}
public:
	Goods *next;
private:
	int weight_;
	static int totalWeight_;
};

int Goods::totalWeight_ = 0;

void purchase(Goods* &head, int weight)
{
	Goods* nw = new Goods(weight);
	nw->next = NULL;
	if (head == NULL)
	{
		head = new Goods(0);
		head->next = nw;
		return;
	}
	
	nw->next = head->next;
	head->next = nw;
	return;
}

void sale(Goods * &head)
{
	Goods *frontTmp = head;
	Goods *rearTmp = head->next;
	if (frontTmp == NULL)
	{
		cout << "head is null " << endl;
		return;
	}
	if (rearTmp == NULL)
	{
		cout << "no goods for sell " << endl;
		return;
	}
	while (rearTmp->next != NULL)
	{
		frontTmp = frontTmp->next;
		rearTmp = rearTmp->next;
	}

	if (rearTmp != NULL)
	{
		frontTmp->next = rearTmp->next;
		delete rearTmp;
		rearTmp = NULL;
	}
	return;
}

void main()
{
	Goods *head = NULL;
	int  w;  int  choice;
	do
	{
		cout << "Please choice:\n";
		cout << "Key in 1 is purchase,\nKey in 2 is sale,\nKey in 0 is over.\n";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Input weight: ";
			cin >> w;
			purchase(head, w);
			break;
		}
		case 2:
		{
			sale(head);
			break;
		}
		case 0:
			break;
		}
		cout << "Now total weight is:" << Goods::GetTotalWeight() << endl;
	} while (choice);
}