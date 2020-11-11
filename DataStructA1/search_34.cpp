#include<iostream>

using namespace std;

typedef char DataType;
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

void search(LNode *l1, LNode *l2, int inp1, int inp2)
{
    if(inp1 > inp2)
        {
            for(int i = 0; i < inp1-inp2; i++)
            {
                l1 = l1->next;
            }
        }
        else if(inp1 < inp2)
        {
            for(int i = 0; i < inp2-inp1; i++)
            {
                l2 = l2->next;
            }
        }
        //cout<<l1->data<<endl;
        while (l1)
        {
           if(l1->data == l2->data)
           {
               cout<<l1->data<<endl;
               break;
           }
           l1 = l1->next;
           l2 = l2->next;
        }
        
}


int main()
{
	LNode* l1, * l2,*h;
	int inp1,inp2;
	while(cin>>inp1>>inp2)
	{
		if (inp1 == 0 && inp2 == 0)
		{
			return 0;
		}
		creatList(l1, inp1);
		creatList(l2, inp2);
        l1 = l1->next;
        l2 = l2->next;

        search(l1, l2, inp1, inp2);

	}

	return 0;
}