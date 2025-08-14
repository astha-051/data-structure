#include <stdio.h>
#include <string.h>
#define size 100

char stack[size];
int top = -1;

void push(char ch) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = ch;
    }
}

char pop() {
    if (top < 0) {
        return '\0'; 
    } else {
        return stack[top--];
    }
}