#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

char A[20], P[20], S[20];
int S1[20], top = -1, top1 = -1;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

void push(char op) { S[++top] = op; }
char pop() { return (top == -1) ? '\0' : S[top--]; }

void infixtopostfix() {
    int i = 0, j = 0;
    while (A[i]) {
        if (isdigit(A[i])) P[j++] = A[i];
        else if (A[i] == '(') push(A[i]);
        else if (A[i] == ')') {
            while (top != -1 && S[top] != '(') P[j++] = pop();
            top--;
        } else {
            while (top != -1 && precedence(S[top]) >= precedence(A[i])) P[j++] = pop();
            push(A[i]);
        }
        i++;
    }
    while (top != -1) P[j++] = pop();
    P[j] = '\0';
    printf("Postfix: %s\n", P);
}

void push1(int val) { S1[++top1] = val; }
int pop1() { return (top1 == -1) ? 0 : S1[top1--]; }

void postfix_eval() {
    for (int i = 0; P[i]; i++) {
        if (isdigit(P[i])) push1(P[i] - '0');
        else {
            int x2 = pop1(), x1 = pop1();
            switch (P[i]) {
                case '+': push1(x1 + x2); break;
                case '-': push1(x1 - x2); break;
                case '*': push1(x1 * x2); break;
                case '/': push1(x1 / x2); break;
            }
        }
    }
    printf("Result = %d\n", S1[top1]);
}
int main() {
    printf("Enter expression: ");
    fgets(A, 20, stdin);
    A[strcspn(A, "\n")] = '\0'; 
    infixtopostfix();
    postfix_eval();
    return 0;
}
