#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stk[50];
int stk1[50];
int top = -1;
int top1 = -1;
void push(char ch) {
 top = top + 1;
 stk[top] = ch;
}
void push1(int item) {
 top1 = top1 + 1;
 stk1[top1] = item;
}
int pop1() {
 if (top1 != -1) {
 int item = stk1[top1];
 top1 = top1 - 1;
 return item;
 }
 return -1;
}
char pop() {
 if (top == -1) {
 return '\0';
 } else {
 return stk[top--];
 }
}
int per(char ch) {
 if (ch == '(') {
 return 0;
 } else if (ch == '+' || ch == '-') {
 return 1;
 } else if (ch == '*' || ch == '/') {
 return 2;
 }
 return -1;
}
int result(char op, int a, int b) {
 switch (op) {
 case '+':
 return b + a;
 case '-':
 return b - a;
 case '*':
 return b * a;
 case '/':
 return b / a;
 
 default:
 return 0;
 }
}
void eval(char p[]) {
 top1 = -1;
 for (int i = 0; i < (int)strlen(p); i++) {
 char ch = p[i];
 if (isalnum(ch)) {
 int y;
 printf("Enter value of %c: ", ch);
 scanf("%d", &y);
 push1(y);
 } else {
 int a = pop1();
 int b = pop1();
 int res = result(ch, a, b);
 push1(res);
 }
 }
 int val = stk1[top1];
 printf("Result is %d\n", val);
}
void main() {
 char infix[50], postfx[50], ch;
 int i = 0, k = 0;
 printf("Enter the expression:\n");
 scanf("%s", infix);
 while ((ch = infix[i++]) != '\0') {
 if(ch=='(')
 {
 push(ch);
 }
 else if(isalnum(ch))
 {
 postfx[k++]=ch;
 }
 else if(ch==')')
 {
 while(stk[top]!='(')
 {
 postfx[k++]=pop();
 }
 pop();
 }
 else
 {
 while((per(stk[top]))>=per(ch))
 {
 postfx[k++]=pop();
 }
 push(ch);
 }
 }
 while (top != -1) {
 postfx[k++] = pop();
 }
 postfx[k] = '\0';
 printf("The postfix conversion is: %s\n", postfx);
 printf("Evaluation of the expression is....\n");
 eval(postfx);
 }
