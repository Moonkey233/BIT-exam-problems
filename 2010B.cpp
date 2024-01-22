#include "stdio.h"
#include "string.h"

#define MAX_STACK_SIZE 101
#define MAX_ARRAY_SIZE 101

const char divide = ' ';
const char negative = '#';

typedef int bool;
enum {
	false = 0, true = 1
};

typedef struct Stack {
	char chData[MAX_STACK_SIZE]/*[MAX_ARRAY_SIZE]*/;
	int numData[MAX_STACK_SIZE];
	int top;
} Stack;

//bool strCopy(char *dest, const char *src);

//bool strConnect(char *str, const char *sub1, const char *sub2);
//
//bool subStr(const char *str, char *sub, int begin, int length);

int length(const char *str);

bool initStack(Stack *S);

bool isEmpty(Stack *S);

bool isFull(Stack *S);

bool push(Stack *S, char data/*[MAX_ARRAY_SIZE]*/, int num);

bool pop(Stack *S, char *data/*[MAX_ARRAY_SIZE]*/, int *num);

bool getTop(Stack *S, char *data/*[MAX_ARRAY_SIZE]*/, int *num);

bool bracketCheck(const char *str, int length);

bool infixToSuffix(char *suffix, char *infix, int length);

int getOperatorLevel(char ch);

int getOperatorNum(char ch);

bool isSignNumber(char ch);

bool isNumber(char ch);

bool calculateSuffix(char *suffix, int *ans, int length);

int calculate(int a, int b, char op);

int fact(int n);

void replace(char *s, char *p, char *r) {
	int i, j, k, slen = strlen(s), plen = strlen(p), rlen = strlen(r), count = 0, a[10] = {0};
	for (i = 0; i <= slen - plen; ++i) {
		for (j = 0; j < plen; ++j) {
			if (s[i + j] == p[j]) continue;
			else break;
		}
		if (j == plen) a[count++] = i;
	}
	if (count) {
		count = 0;
		for (i = 0; i < slen; ++i) {
			if (a[count] == i) {
				printf("%s", r);
				i += plen - 1;
				++count;
			} else printf("%c", s[i]);
		}
	} else printf("NotFound");
}

int main() {
	char ary[MAX_ARRAY_SIZE] = {0};
	scanf("%s", ary);
	while (ary[0] != '#') {
		if (bracketCheck(ary, length(ary))) {
			printf("Match Succeed!\n");
			char suffix[MAX_ARRAY_SIZE] = {0};
			infixToSuffix(suffix, ary, length(ary));
			printf("Suffix: %s\n", suffix);
			int ans = 0;
			if (calculateSuffix(suffix, &ans, length(suffix))) {
				printf("Answer: %d\n", ans);
			} else {
				printf("This is not a NUMBER calculate!\n");
			}
		} else
			printf("Match Failed!\n");
		scanf("%s", ary);
	}

	return 0;
}

//bool strCopy(char *dest, const char *src) {
//	int i = 0;
//	while (src[i] != '\0' && i++ < MAX_ARRAY_SIZE)
//		dest[i] = src[i];
//	dest[i] = '\0';
//	return true;
//}

//bool strConnect(char *str, const char *sub1, const char *sub2) {
//	if (length <= 0) return false;
//	int i = 0, j = 0;
//	while (sub1[j] != '\0') str[i++] = sub1[j++];
//	j = 0;
//	while (sub2[j] != '\0') str[i++] = sub2[j++];
//	str[i] = '\0';
//	return true;
//}
//
//bool subStr(const char *str, char *sub, int begin, int length) {
//	if (length <= 0) return false;
//	int i;
//	for (i = 0; i < length; i++)
//		sub[i] = str[begin + i];
//	sub[length] = '\0';
//	return true;
//}

int length(const char *str) {
	int i = -1;
	while (str[++i] != '\0');
//	printf("\n%d\n", i);
	return i;
}

bool initStack(Stack *S) {
	S->top = -1;
	return true;
}

bool isEmpty(Stack *S) {
	return S->top == -1;
}

bool isFull(Stack *S) {
	return S->top == MAX_STACK_SIZE - 1;
}

bool push(Stack *S, char data/*[MAX_ARRAY_SIZE]*/, int num) {
	if (isFull(S)) return false;
	S->chData[++S->top] = data;
	S->numData[S->top] = num;
//	strConnect(S->data[++S->top], data);
	return true;
}

bool pop(Stack *S, char *data/*[MAX_ARRAY_SIZE]*/, int *num) {
	if (isEmpty(S)) return false;
	*data = S->chData[S->top];
	*num = S->numData[S->top--];
//	strConnect(data, S->data[S->top--]);
	return true;
}

bool getTop(Stack *S, char *data/*[MAX_ARRAY_SIZE]*/, int *num) {
	if (isEmpty(S)) return false;
	*data = S->chData[S->top];
	*num = S->numData[S->top];
//	strConnect(data, S->data[S->top]);
	return true;
}

bool bracketCheck(const char *str, int length) {
	if (length <= 0) return false;
	char bracketStr[MAX_ARRAY_SIZE];
	int j = 0;
	int i;
	for (i = 0; i < length; i++)
		if (str[i] == '(' || str[i] == ')' || str[i] == '[' || str[i] == ']' || str[i] == '{' || str[i] == '}')
			bracketStr[j++] = str[i];
	Stack S;
	initStack(&S);
	int num = 0;
	for (i = 0; i < j; i++) {
		if (bracketStr[i] == '(' || bracketStr[i] == '[' || bracketStr[i] == '{') {
//			char ch[2] = {bracketStr[i], '\0'};
			push(&S, bracketStr[i], num);
			continue;
		}
		if (isEmpty(&S)) return false; //Right bracket single
		char ch[2] = {0};
		pop(&S, ch, &num);
		if ((ch[0] == ')' && bracketStr[i] == '(') || (ch[0] == ']' && bracketStr[i] == '[') ||
		    (ch[0] == '}' && bracketStr[i] == '{'))
			return false; //Left and right not match;
	}
	if (!isEmpty(&S)) return false; //Left and right not match;
	return true;
}

bool infixToSuffix(char *suffix, char *infix, int length) {
	if (length <= 0) return false;
	int i;
	for (i = 0; i < length; i++) {
//		if (infix[i] == '!') {
//			char sub1[MAX_ARRAY_SIZE], sub2[MAX_ARRAY_SIZE];
//			subStr(infix, sub1, 0, i + 1);
//			strConnect(sub1, sub1, "1\0");
//			subStr(infix, sub2, i + 1, length - i - 1);
//			strConnect(infix, sub1, sub2);
//			length++;
//			i++;
//		}
		if (infix[i] == '-' && (i == 0 || getOperatorNum(infix[i - 1]) > 1 || infix[i - 1] == '('))
			infix[i] = negative;
		else if (infix[i] == '+' && (i == 0 || getOperatorNum(infix[i - 1]) > 1 || infix[i - 1] == '('))
			infix[i] = divide;
	}
	int cnt = 0;
	Stack S;
	initStack(&S);
	int num = 0;
	for (i = 0; i < length; i++) {
		if (getOperatorLevel(infix[i]) != 0) { //Operator
			char ch = '\0';
			getTop(&S, &ch, &num);
			while (ch != '(' && !isEmpty(&S) && getOperatorLevel(ch) >= getOperatorLevel(infix[i])) {
				pop(&S, &ch, &num);
				suffix[cnt++] = ch;
				suffix[cnt++] = divide;
				getTop(&S, &ch, &num);
			}
			push(&S, infix[i], num);
		} else if (infix[i] == '(') {
			push(&S, '(', num);
		} else if (infix[i] == ')') {
			char ch = '\0';
			getTop(&S, &ch, &num);
			while (ch != '(' && !isEmpty(&S)) {
				pop(&S, &ch, &num);
				suffix[cnt++] = ch;
				suffix[cnt++] = divide;
				getTop(&S, &ch, &num);
			}
			pop(&S, &ch, &num);
		} else {
			suffix[cnt++] = infix[i];
			while (i + 1 < length && isSignNumber(infix[i + 1]))
				suffix[cnt++] = infix[++i];
			suffix[cnt++] = divide;
//			suffix[cnt++] = infix[i];
		} //Numbers
	}
	char ch = '\0';
	while (!isEmpty(&S)) {
		pop(&S, &ch, &num);
		suffix[cnt++] = ch;
		suffix[cnt++] = divide;
	}
	return true;
}

int getOperatorLevel(char ch) {
	if (ch == '+' || ch == '-') return 1;
	else if (ch == '*' || ch == '/' || ch == '%') return 2;
	else if (ch == '^') return 3;
	else if (ch == negative) return 4;
	else if (ch == '!') return 5;
	return 0;
}

int getOperatorNum(char ch) {
	if (getOperatorLevel(ch) == 0) return 0;
	return ch == '!' || ch == negative ? 1 : 2;
}

bool isNumber(char ch) {
	return ch >= '0' && ch <= '9';
}

bool isSignNumber(char ch) {
	return getOperatorLevel(ch) == 0 && ch != '(' && ch != ')';
}

bool calculateSuffix(char *suffix, int *ans, int length) {
	if (length <= 0) return false;
	char ch = '\0';
	int i;
	for (i = 0; i < length; i++) {
		ch = suffix[i];
		if (ch == divide || isNumber(ch) || getOperatorLevel(ch)) continue;
		else return false;
	}
	Stack NS;
	for (i = 0; i < length; i++) {
		ch = suffix[i];
		if (ch == divide) continue;
		if (!isNumber(ch)) {
			int a, b;
			char c;
			if (getOperatorNum(ch) == 2) {
				pop(&NS, &c, &b);
				pop(&NS, &c, &a);
				push(&NS, c, calculate(a, b, ch));
			} else if (getOperatorNum(ch) == 1) {
				pop(&NS, &c, &a);
				push(&NS, c, calculate(a, 0, ch));
			}
		} else {
			int num = ch - '0';
			while (i + 1 < length && isNumber(suffix[i + 1]))
				num = num * 10 + suffix[++i] - '0';
			push(&NS, ch, num);
		}
	}
	pop(&NS, &ch, ans);
	return true;
}

int calculate(int a, int b, char op) {
	int i;
	if (op == '+') return a + b;
	else if (op == '-') return a - b;
	else if (op == '*') return a * b;
	else if (op == '/') return a / b;
	else if (op == '%') return a % b;
	else if (op == '^') {
		int ans = a;
		for (i = 1; i < b; i++)
			ans *= a;
		return ans;
	} else if (op == negative) return -a;
	else if (op == '!') return fact(a);
	else return 0;
}

int fact(int n) {
	if (n < 1) return 0;
	else if (n == 1) return 1;
	else return n * fact(n - 1);
}

