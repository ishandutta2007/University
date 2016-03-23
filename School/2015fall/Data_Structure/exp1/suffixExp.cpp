// 实验内容： 算术表达式求值，能够完成整数、实数等的四则运算及求模运算。

// 实验要求：输入中缀表达式，先转换成后缀表达式，输出后缀表达式，然后对后缀表达式求值。

// 要写出实验报告，按科研论文形式写，具体格式自行查询。注意表达式的特殊情况的处理。

#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <string>
using namespace std;


struct Node
{
	int tp;
	double di;
	char dc;
	Node *nex;
	Node():nex(NULL){}
	Node(int tp, double di, int dc):tp(tp),di(di),dc(dc),nex(NULL){}
	void show()
	{
		if(tp == 1) printf("%.2f ", di);
		else printf("%c ", dc);
	}
};


Node *head;
char stk[1000];
int stkk[1000];
double stkf[1000];
int top = 0;


void inop(char ch, Node *&now)
{
	int nowrank;
	if(ch == '+' || ch == '-') nowrank = 1;
	else nowrank = 2;
	while(top && stkk[top] >= nowrank && stkk[top] < 10)
	{
		now->nex = new Node(0,0,stk[top]);
		now = now->nex;
		top--;
	}
	stk[++top] = ch;
	stkk[top] = nowrank;
}
void inbr(char ch, Node *&now)
{
	int nowrank = 10;
	if(ch == '(')
	{
		stk[++top] = ch;
		stkk[top] = nowrank;
	}
	else
	{
		while(top && stkk[top] < nowrank)
		{
			now->nex = new Node(0,0,stk[top]);
			now = now->nex;
			top--;
		}
		top--;
	}
}
void stkout(Node *&now)
{
	cout << top << endl;
	while(top)
	{
		now->nex = new Node(0,0,stk[top--]);
		now = now->nex;
	}
}

double cal(double a, double b, char ch)
{
	if(ch == '+') return a + b;
	else if(ch == '-') return a - b;
	else if(ch == '*') return a * b;
	else if(ch == '/') return a / b;
	else return (int)a % (int)b;
}


int main()
{

	printf("input the nifix expression , seperate integers , brackets and operators by a blank space,\ninput shold be end with a # in a single line\n");
	char s[20];
	int len;

	head = new Node();
	Node *now = head;
	//输入的括号， 数字， 符号用 =空格隔开， 所以以字符串的方式读入数据
	while(scanf("%s", s))
	{
		// for(int i = 0; i <= top; i++)
		// {
		// 	printf("%c ", stk[i]);
		// }
		// printf("\n");

		if(s[0] == '#') break; // 输入以单独的一行 # 结束

		len = strlen(s); 
		if(len == 1)// 如果字符串的长度为1， 那么可能是符号 也可能是数字
		{
			//分别判断是否是括号 或者 运算符
			if(s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/' || s[0] == '%') {inop(s[0], now);continue;}
			else if(s[0] == '(' || s[0] == ')') {inbr(s[0], now);continue;}
		}


		//如果是数字， 就在保存的后缀表达式最后加上这个数字
		now->nex = new Node(1,atof(s),0);
		now = now->nex;
	}
	// cout << "!!!!!!" <<endl;


	stkout(now);// 处理完整个表达式， 将未出栈的符号 依次 出栈


	now = head->nex;


	top = 0;

	while(now != NULL)// 打印后缀表达式， 顺便求出 后缀表达式的值
	{
		now->show();
		// 求后缀表达式的值  用栈来实现
		if(now->tp == 1) stkf[++top] = now->di;
		else
		{
			double tmp = cal(stkf[top-1], stkf[top], now->dc);
			top -= 2;
			stkf[++top] = tmp;
		}
		now = now->nex;
	}


	printf("\nans = %.4f\n", stkf[1]); //最后的栈顶元素就是后缀表达式的值
	return 0;
}