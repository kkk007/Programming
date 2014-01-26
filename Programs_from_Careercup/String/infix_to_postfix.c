#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAX 20

void convertip(char infix[],char postfix[]);

char stack[MAX];
int top=-1;

int main()
{
	char infix[20],postfix[20];
	printf("Enter the valid infix string:\n");
	gets(infix);
	convertip(infix,postfix);
	printf("The corresponding postfix string is:\n");
	puts(postfix);
	return 0;
}
void push(char item)
{
	top++;
	stack[top]=item;
}
char pop()
{
	char a;
	a=stack[top];
	top--;
	return a;
}

int prcd(char symbol)
{
	switch(symbol)
	{
	case '+':
	case '-':return 2;
	break;
	case '*':
	case '/':return 4;
	break;
	case '^':
	case '$':return 6;
	break;
	case '(':
	case ')':
	case '#':return 1;
	break;
	}
}
int isoperator(char symbol)
{
	switch(symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '$':
	case '(':
	case ')':return 1;
	break;
	default:return 0;
	}
}

void convertip(char infix[],char postfix[])
{
	int i,symbol,j=0;
	stack[++top]='#';
	for(i=0;i<strlen(infix);i++)
	{
		symbol=infix[i];
		if(isoperator(symbol)==0)
		{
			postfix[j]=symbol;
			j++;
		}
		else{
			if(symbol=='(')push(symbol);
			else if(symbol==')')
			{
				while(stack[top]!='(')
				{
					postfix[j]=pop();
					j++;
				}
				pop();//pop out (.
			}
			else{
				if(prcd(symbol)>prcd(stack[top]))
					push(symbol);
				else{
					while(prcd(symbol)<=prcd(stack[top]))
					{
						postfix[j]=pop();
						j++;
					}
					push(symbol);
				}//end of else.
			}//end of else.
		}//end of else.
	}//end of for.
	while(stack[top]!='#')
	{
		postfix[j]=pop();
		j++;
	}
	postfix[j]='\0';//null terminate string.
}

