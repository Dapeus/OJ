#include<iostream>
#include<stack>

using namespace std;

int jud[7][7] = {   //1：大于； 0：等于； 2：小于 3：不存在；
    {1,1,0,0,0,1,1},
	{1,1,0,0,0,1,1},
	{1,1,1,1,0,1,1},
	{1,1,1,1,0,1,1},
	{0,0,0,0,0,2,3},
	{1,1,1,1,3,1,1},
	{0,0,0,0,0,3,2}
};

typedef char DataType;
struct BiTNode
{
    DataType data;
    BiTNode *lchild;
    BiTNode *rchild;
};

bool isAlphebat(char ch)
{
    if('a' <= ch && ch <= 'z')
    {
        return true;
    }
    else if('A' <= ch && ch <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

char getPriorier(char top, char ch)
{
int jud1,jud2;
	if(top == '+')
	{
		jud1 = 0;
	}
	else if(top == '-')
	{
		jud1 = 1;
	}
	else if(top == '*')
	{
		jud1 = 2;
	}
	else if(top == '/')
	{
		jud1 = 3;
	}
	else if(top == '(')
	{
		jud1 = 4;
	}
	else if(top == ')')
	{
		jud1 = 5;
	}
	else if(top == '=')
	{
		jud1 = 6;
	}

	if(ch == '+')
	{
		jud2 = 0;
	}
	else if(ch == '-')
	{
		jud2 = 1;
	}
	else if(ch == '*')
	{
		jud2 = 2;
	}
	else if(ch == '/')
	{
		jud2 = 3;
	}
	else if(ch == '(')
	{
		jud2 = 4;
	}
	else if(ch == ')')
	{
		jud2 = 5;
	}
	else if(ch == '=')
	{
		jud2 = 6;
	}

	
	if(jud[jud1][jud2] == 1)
    {
        return '>';
    }
    else if(jud[jud1][jud2] == 0)
    {
        return '<';
    }
    else if(jud[jud1][jud2] == 2)
    {
        return '=';
    }
    else
    {
        return '=';
    }
    
}


void createTree(BiTNode *&T, BiTNode *lchild, BiTNode *rchild, char ch)
{
    T = new BiTNode;
    T->data = ch;
    T->lchild = lchild;
    T->rchild = rchild;
}

void initExpTree(int &a, stack<char> &OPTR, stack<BiTNode> &EXPT)
{
    char ch;
    OPTR.push('#');
    cin>>ch;
    if(ch == '=')
    {
        a = 1;
    }
    while (ch != '=' || OPTR.top() != '#')
    {
        if(isdigit(ch))
        {
            BiTNode *T;
            createTree(T, NULL, NULL, ch);
            EXPT.push(*T);
            cin>>ch;
        }
        else
        {
            if(OPTR.top() == '#' || getPriorier(OPTR.top(), ch) == '<')
            {
                OPTR.push(ch);
                cin>>ch;
            }
            else if(getPriorier(OPTR.top(), ch) == '>')
            {
                char theta = OPTR.top(); OPTR.pop();
                BiTNode *c = new BiTNode;
                BiTNode *b = new BiTNode;
                *c = EXPT.top(); EXPT.pop();
                *b = EXPT.top(); EXPT.pop();
                BiTNode *T;
                createTree(T, c, b, theta);
                EXPT.push(*T);
            }
            else
            {
                OPTR.pop();
                cin>>ch;
            }
        }
    }
    while(OPTR.top() != '#')
    {
        if(getPriorier(OPTR.top(), ch) == '<')
        {
            OPTR.push(ch);
            cin>>ch;
        }
        else if(getPriorier(OPTR.top(), ch) == '>')
        {
           char theta = OPTR.top(); OPTR.pop();
            BiTNode *c = new BiTNode;
            BiTNode *b = new BiTNode;
            *c = EXPT.top(); EXPT.pop();
            *b = EXPT.top(); EXPT.pop();
            BiTNode *T;
            createTree(T, c, b, theta);
            EXPT.push(*T);
        }
        else
        {
            OPTR.pop();
            cin>>ch;
            break;
        }
    }
}

int value(BiTNode *T, int lchild, int rchild)
{
    if(T->data == '+')
    {
        return lchild + rchild;
    }
    else if (T->data == '-')
    {
        return rchild - lchild;
    }
    else if (T->data == '*')
    {
        return lchild * rchild;
    }
    else if(T->data == '/')
    {
         return rchild/lchild;
    }
}

int getValue(BiTNode *T)
{
    int lvalue = 0, rvalue = 0;
    if(T->lchild == NULL && T->rchild == NULL)
    {
        return T->data - '0';
    }
    else
    {
        lvalue = getValue(T->lchild);
        rvalue = getValue(T->rchild);
        int ret = value(T, lvalue, rvalue);
        return ret;
    }
}

int main()
{
    while(1)
    {
        int a = 0;
        stack<char> OPTR;
        stack<BiTNode> EXPT;
        initExpTree(a, OPTR, EXPT);
        if(a == 1)
        {
            break;
        }
        cout<<getValue(&EXPT.top())<<endl;
    }
    return 0;
}