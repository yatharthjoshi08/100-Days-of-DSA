// Problem: Deque (Double-Ended Queue)

// A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

// Common Operations:
// 1. push_front(value): Insert an element at the front of the deque.
// 2. push_back(value): Insert an element at the rear of the deque.
// 3. pop_front(): Remove an element from the front of the deque.
// 4. pop_back(): Remove an element from the rear of the deque.
// 5. front(): Return the front element of the deque.
// 6. back(): Return the rear element of the deque.
// 7. empty(): Check whether the deque is empty.
// 8. size(): Return the number of elements in the deque.

// Additional Operations:
// - clear(): Remove all elements from the deque.
// - erase(): Remove one or more elements from the deque.
// - swap(): Swap contents of two deques.
// - emplace_front(): Insert an element at the front without copying.
// - emplace_back(): Insert an element at the rear without copying.
// - resize(): Change the size of the deque.
// - assign(): Replace elements with new values.
// - reverse(): Reverse the order of elements.
// - sort(): Sort the elements in ascending order.

// Time Complexity:
// - push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
// - clear, erase, resize, assign, reverse: O(n)
// - sort: O(n log n)

// Input:
// - Sequence of deque operations with values (if applicable)

// Output:
// - Results of operations such as front, back, size, or the final state of the deque after all operations

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
    int size;
} Deque;

Deque* createDeque() {
    Deque* dq = (Deque*)malloc(sizeof(Deque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

void push_front(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = dq->front;
    newNode->prev = NULL;
    
    if (dq->front == NULL) {
        dq->rear = newNode;
    } else {
        dq->front->prev = newNode;
    }
    dq->front = newNode;
    dq->size++;
}

void push_back(Deque* dq, int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = dq->rear;
    
    if (dq->rear == NULL) {
        dq->front = newNode;
    } else {
        dq->rear->next = newNode;
    }
    dq->rear = newNode;
    dq->size++;
}

int pop_front(Deque* dq) {
    if (dq->size == 0) return -1;
    
    Node* temp = dq->front;
    int val = temp->data;
    
    dq->front = dq->front->next;
    if (dq->front == NULL) {
        dq->rear = NULL;
    } else {
        dq->front->prev = NULL;
    }
    free(temp);
    dq->size--;
    return val;
}

int pop_back(Deque* dq) {
    if (dq->size == 0) return -1;
    
    Node* temp = dq->rear;
    int val = temp->data;
    
    dq->rear = dq->rear->prev;
    if (dq->rear == NULL) {
        dq->front = NULL;
    } else {
        dq->rear->next = NULL;
    }
    free(temp);
    dq->size--;
    return val;
}

int front(Deque* dq) { return dq->size ? dq->front->data : -1; }
int back(Deque* dq) { return dq->size ? dq->rear->data : -1; }
int empty(Deque* dq) { return dq->size == 0; }
int size(Deque* dq) { return dq->size; }

void printDeque(Deque* dq) {
    Node* current = dq->front;
    printf("Deque: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void clear(Deque* dq) {
    while (!empty(dq)) {
        pop_front(dq);
    }
}

void freeDeque(Deque* dq) {
    clear(dq);
    free(dq);
}

int main() {
    Deque* dq = createDeque();
    
    push_back(dq, 10); printDeque(dq);
    push_front(dq, 5); printDeque(dq);
    push_back(dq, 15); printDeque(dq);
    
    printf("Front: %d, Back: %d, Size: %d\n", front(dq), back(dq), size(dq));
    
    pop_front(dq); printDeque(dq); 
    pop_back(dq); printDeque(dq); 
    
    freeDeque(dq);
    return 0;
}
