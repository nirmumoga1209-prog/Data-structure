#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer for the stack
struct Node* top = NULL;

// 1. PUSH Operation: Add an element to the top
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (newNode == NULL) {
        printf("Stack Overflow (Memory allocation failed)\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top; // Point new node to the current top
    top = newNode;       // Update top to the new node
    printf("%d pushed to stack\n", value);
}

// 2. POP Operation: Remove the top element
void pop() {
    if (top == NULL) {
        printf("Stack Underflow (Stack is empty)\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Popped element: %d\n", top->data);
    top = top->next; // Move top to the next node
    free(temp);      // Free memory of the removed node
}

// 3. DISPLAY Operation: Print all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Testing the operations
    push(10);
    push(20);
    push(30);
    display();
    
    pop();
    display();
    
    return 0;
}