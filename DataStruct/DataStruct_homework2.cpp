#include<iostream>

using namespace std;

typedef int DataType;
typedef struct DuLNode
{
	DataType data;
	DuLNode* prior;
	DuLNode* next;
};

DuLNode* creatList(DuLNode*& dl, int num)
{
	dl = new DuLNode;
	DuLNode* p = dl;
	dl->prior = NULL;
	dl->data = -1;	//头指针的数值
	DataType input;
	for (int i = 0; i < num; i++)
	{
		cin >> input;
		p->next = new DuLNode;
		DuLNode* t = p;
		p = p->next;
		p->data = input;
		p->next = NULL;
		p->prior = t;
	}
	return dl;
}

void printList(DuLNode*& dl)
{
	dl = dl->next;
	while (dl)
	{
		if (dl->next == NULL)
		{
			cout << dl->data << endl;
		}
		else
		{
			cout << dl->data << " ";
		}
		dl = dl->next;
	}
}

int main()
{
	DuLNode* dl, * h;

	int inp, inp2;
	while (cin >> inp)
	{
		if (inp == 0)
		{
			return 0;
		}
		creatList(dl, inp);
		h = dl;
		cin >> inp2;
		
		for (int i = 0; i < inp2; i++)
		{
			dl = dl->next;
		}
		if (inp == inp2)
		{
			dl->prior = dl->prior->prior;
			dl->prior->next->next = dl->next;
			//dl->next->prior = dl->prior->next;
			dl->next = dl->prior->next;
			dl->prior->next->prior = dl;
			dl->prior->next = dl;
		}
		else if(inp2 == 1)
		{

		}
		else
		{ 
			dl->prior = dl->prior->prior;
			dl->prior->next->next = dl->next;
			dl->next->prior = dl->prior->next;
			dl->next = dl->prior->next;
			dl->prior->next->prior = dl;
			dl->prior->next = dl;
		}

		printList(h);
	}
	system("pause");

	return 0;
}