// #include<iostream>
// #define M 100000

// using namespace std;

// int getlen(char *s)
// {
//     int i = 0;
//     while (s[i] != '\0')
//     {
//         i++;
//     }
//     return i;       
// }

// void print(char *s)
// {
//     int i;
//     for(i = 0; i < getlen(s); i++)
//     {
//         cout<<s[i];
//     }
//     cout<<s[i]<<endl;
// }

// void insert(char s[], char t[], int pos)
// {
//     int slen = getlen(s);
//     int tlen = getlen(t);

//     char temp[M] = { 0 };
//     pos--;
//     for(int i = 0; i < pos; i++)
//     { 
//         temp[i] = s[i];
//     }
//     for(int i = pos,j = 0; j < tlen; i++,j++)
//     { 
//         temp[i] = t[j];
//     }
//     for(int i = pos + tlen, j = pos; i < slen + tlen; i++,j++)
//     {
//         temp[i] = s[j];
//     }
//     int i;
//     for(i = 0; i < slen+tlen; i++)
//     {
//         s[i] = temp[i];
//     }
//     s[i] = '\0';
//     s[i+1] = '\0';
//     s[i+2] = '\0';
// }

// int main()
// {
//     int pos;
//     while(cin>>pos && pos != 0)
//     {
//         char s[M],t[M];
//         scanf("%s", s);
//         scanf("%s", t);
//         insert(s, t, pos);
//         print(s);
//     }
//     return 0;
// }


#include<iostream>
#include<cstring>
#define MAX 1000

using namespace std;

void insert(char *a, char *b, int pos)
{
	int i,j,m = 0,f = 0;
	int length = strlen(a) + strlen(b);
	for(j = 0; j < strlen(a); j++)
	{
		f++;
		m++;
		if(m == pos)
		{
			for(i = 0; i < strlen(b); i++)
			{
				f++;
				cout<<b[i];
			}
		}
		cout<<a[j];
		if(f == length)
        {
            cout<<endl;
        }
	}
}
int main()
{
	int pos;
	while(cin>>pos && pos!=0)
	{
		char *a = new char[2*MAX];
		char *b = new char[MAX];
		cin>>a>>b;
		insert(a, b, pos);
	}
	return 0;
}