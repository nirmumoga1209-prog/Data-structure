#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 100

from uuid import MAX

from numpy import stack


char stack[MAX];
int top = -1;
void push(char C){
    if (top == MAX-1){
        printf("Stack overflow\n");
        return;
    }
    stack[++top]=c;
}
char pop(){
    if (top<0){
        return'0';
    }
    return stack[top--];
}

char peek(){
    if (top<0){
        return '0';
    }
    return stack[top];
}

int percedence(char op){
    switch(op){
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
    }
}
int isOperator(char c){
    return (c=='+' || c=='-' || c=='*' || c=='/' || c=='^');
}
void infixToPostfix(char* infix, char* postfix){
    int i=0,j=0;
    char c;
    while(infix[i]!='\0'){
        c=infix[i];
        if (isalnum(c)){
            postfix[j++]=c;
        }
        else if (c=='('){
            push(c);
        }
        else if (c==')'){
            while(peek()!='('){
                postfix[j++]=pop();
            }
            pop();
        }
        else if (isOperator(c)){
            while(top!=-1 && percedence(peek())>=percedence(c)){
                postfix[j++]=pop();
            }
            push(c);
        }
        i++;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    //if operates are ad to output
    if (isalnum(c)){
        postfix[j++]=c;
    }
    //if('.push to stack
    else if (c=='('){
        push(c);
    }
    // if ')' pop until '('is found  
    else if (c==')'){
        while(peek()!='('){
            postfix[j++]=pop();
        }
        pop();
    }
}
// if ")",pop until'('is found

// if operator
else if (isOperator(c)){
 // handle half associativity of '^'
    if (c=='^'){
        while(top>==0 && percedence(peek())>percedence(c)){
            postfix[j++]=pop();
        }
    }
    else{
        while(top>==0 && percedence(peek())>=percedence(c)){
            postfix[j++]=pop();
        }
    }
    push(c);
}
// pop remaining operation
while(top>==0){
    postfix[j++]=pop();
}
postfix[j]='\0';
int main(){
    char infix[MAX],postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s",infix);
    infixToPostfix(infix,postfix);
    printf("Postfix expression: %s\n",postfix);
    return 0;
}