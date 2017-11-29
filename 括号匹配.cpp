#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
int main()
{
	int l;
	char str[1000];
	cin >> str;
	l = sizeof(str);
	stack<char> s;
	int judge = 1;
	for (int i = 0; i<l; i++)
	{
		if (str[i] == '(')
			s.push(str[i]);
		else if (str[i] == ')')
		{
			if (s.empty())
			{
				s.push(str[i]);
				break;
			}
			else if (s.top() == '(')
				s.pop();
			else
			{
				judge = 0;
				break;
			}
		}
	}
	if (!s.empty())
		judge = 0;
	if (judge == 1)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct _stack
{
	char *base;
	char *top;
	int num;
}Sqstack;

void InitStack(Sqstack &s)
{
	s.base=(char *)malloc(100*sizeof(char));
	if(s.base==NULL)
	{
		printf("栈创建失败!\n");
		return;
	}
	s.top=s.base;
	*s.top=0;
	s.num=100;
}
void push(Sqstack &s,char k)
{
	if((s.top-s.base)>=s.num)
	{
		printf("栈已满!\n");
		return;
	}
	*s.top++=k;
}

void pop(Sqstack &s)
{
	if(s.base==s.top)
	{
		printf("该栈是空栈!\n");
		return;
	}
	s.top--;
}

bool Isempty(Sqstack &s)
{
	if(s.base==s.top)
		return true;
	return false;
}

bool Match(Sqstack &s)
{
	char str[100];
	int i;
	scanf("%s",str);
	for(i=0;i<strlen(str);i++)
	{
		switch(str[i])
		{
		case '(':
			push(s,'(');
			break;
		case ')':
			if(*(s.top-1)=='(')
				pop(s);
			else
				return false;
			break;
		}
	}
	if(Isempty(s))
		return true;
	return false;
}

int main()
{
	Sqstack s;
	InitStack(s);
	if(Match(s))
		printf("YES\n");
	else
		printf("NO\n");
	free(s.base);
	return 0;	
}
*/


