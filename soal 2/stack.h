
#ifndef STACK_H
#define STACK_H

struct ElmStack {
    int info;
    ElmStack *next;
};

typedef ElmStack* address;

struct Stack {
    address Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);

address alokasi(int x);
void dealokasi(address &P);

bool push(Stack &S, int x);
bool pop(Stack &S, int &x);

void printInfo(Stack S);
bool pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif
