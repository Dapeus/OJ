#include<iostream>

using namespace std;

typedef int DataType;
typedef struct LNode
{
	DataType data;
	LNode *next;
}node;

LNode* creatList(LNode*& l, int num)
{
	l = new LNode;
	LNode* p = l;
	DataType d;
	for(int i = 0; i < num; i++)
	{
		cin>>d;
		p->next = new LNode;
		p = p->next;
		p->data = d;
		p->next = NULL;
	}
	return l;
}

LNode* intergrate(LNode* l1, LNode* l2)
{
	LNode *l1h = l1, *l2h = l2;
	l1 = l1->next;
	l2 = l2->next;
	LNode *l11 = l1, *l22 = l2;
	
	while(l1 && l2)
	{
		if(l1->data < l2->data)
		{
			l11 = l1;
			l1 = l1->next;
			l11->next = l1h->next;
			l1h->next = l11;
		}
		else
		{
			l22 = l2;
			l2 = l2->next;
			l22->next = l1h->next;
			l1h->next = l22;
		}

	}
	if (l1 == NULL)
	{
		l22 = l2;
		l2 = l2->next;
		l22->next = l11;
		l1h->next = l22;
		while (l2)
		{
			l22 = l2;
			l2 = l2->next;
			l22->next = l1h->next;
			l1h->next = l22;
		}
	}
	else
	{
		l11 = l1;
		l1 = l1->next;
		l11->next = l22;
		l1h->next = l11;
		while (l1)
		{
			l11 = l1;
			l1 = l1->next;
			l11->next = l1h->next;
			l1h->next = l11;
		}
	}

	//l1h = l1h->next;
	return l1h;
}

LNode* reverse(LNode *l, int num)
{
    LNode* p = l->next;

	LNode* t = p;
	LNode* h = p;
	p = p->next;

	for (int i = 0; i < num - 1; i++)
	{
		h->next = p->next;
		p->next = t;

		t = p;
		p = h->next;
	}
	//printList(t, 10);
	return t;

}

void deduplication(LNode *l, int len, int &cnt)
{
    LNode *pi = l->next,*pj = l->next,*pjj;

    for(int i = 0; i < len-cnt; i++,pi = pi->next)
    {
        if(pi == NULL)
        {
            break;
        }
        pj = l->next;
        pjj = l;
        for(int j = 0; j < len-cnt; j++, pj = pj->next, pjj = pjj->next)
        {
            if(pi == NULL || pj == NULL)
            {
                break;
            }
            if(pi->data == pj->data && i != j)
            {
                pjj->next = pj->next;
                cnt++;
            }
        }
    }
    //cout<<cnt<<endl;
}

int main()
{
	LNode* l1, * l2,*h;
	int inp1;
	while(cin>>inp1)
	{
		if (inp1 == 0)
		{
			return 0;
		}
		creatList(l1, inp1);
        h = l1;
		creatList(l2, inp1);
		//cout<<"l1:"<<l1->data<<endl;
		l1 = intergrate(l1, l2);

        h->next = reverse(l1, inp1+inp1);

        int cnt = 0;
        deduplication(h, inp1+inp1, cnt);

        l1 = l1->next;
        for(int i = 0; i < inp1+inp1-cnt; i++)
		{	
			if(i == inp1 - 1)
            {
                cout<<l1->data<<endl;
            }
            l1 = l1->next;
		}
	}

	return 0;
}