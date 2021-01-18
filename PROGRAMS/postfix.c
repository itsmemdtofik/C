/**   write c program to evaluate to a postfix expression using stack operation  **/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#define MAXSIZE 100
struct stack
{
	int top;
	int items[MAXSIZE];
};
void push(struct stack*,int);
int pop(struct stack*);
int eval(char*);
int oper(char,int,int);
void main()
{

	char expr[MAXSIZE];
	printf("\n enter the valid postfix expression\n");
	scanf("%s",expr);
	printf("\n The value of the Expression is=%d",eval(expr));

}
int eval(char expr[])
{
	int position;
	char c;
	int opnd1,opnd2,value;
	struct stack s;
	s.top=-1;
	for(position=0; ((c=expr[position]))!='\0'; position++)
	{
		if(isdigit(c))

			push(&s,(int)(c-'0'));
		else{
			opnd2=pop(&s);

		opnd1=pop(&s);
		value=oper(c,opnd1,opnd2);
		push(&s,value);
	}
}
return(pop(&s));
}
int oper(char symb,int opnd1,int opnd2)
{
	switch(symb)
	{

		case '+':return(opnd1+opnd2);
		case '-':return(opnd1-opnd2);
		case '*':return(opnd1*opnd2);
		case '/':return(opnd1/opnd2);
		case '$':return pow(opnd2,opnd1);

		default : printf("\n Error operator");
		getch();
		exit(0);
	}
}
void push(struct stack *ps,int num)
{
	if(ps->top==MAXSIZE -1)
	{
		printf("\n Over flow");
		getch();
	}
	else
	{
		(ps->top)++;
		ps->items[ps->top]=num;
	}
}
int pop(struct stack *ps)
{
	int num;
	num=ps->items[ps->top];
	(ps->top)--;
	return num;
}
