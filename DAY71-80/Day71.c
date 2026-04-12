// Problem Statement
// Implement a hash table using quadratic probing with formula:

// h(k, i) = (h(k) + i*i) % m

// Input Format
// Same as previous.

// Output Format
// Result of SEARCH operations.

// Sample Input
// 7
// 4
// INSERT 49
// INSERT 56
// SEARCH 49
// SEARCH 15

// Sample Output
// FOUND
// NOT FOUND

// Explanation
// Collisions resolved using i² jumps.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 10007

int hash_table[MAX_SIZE];
int table_size;

int hash(int key) {
    return key % table_size;
}

void insert(int key) {
    int h = hash(key);
    int i = 0;
    
    while (i < table_size) {
        int index = (h + i * i) % table_size;
        if (hash_table[index] == -1) {
            hash_table[index] = key;
            return;
        }
        i++;
    }
}

int search(int key) {
    int h = hash(key);
    int i = 0;
    
    while (i < table_size) {
        int index = (h + i * i) % table_size;
        if (hash_table[index] == key) {
            return 1;
        }
        if (hash_table[index] == -1) {
            return 0;
        }
        i++;
    }
    return 0;
}

int main() {
    int n;
    scanf("%d", &table_size);
    
    memset(hash_table, -1, sizeof(hash_table));
    
    char op[10];
    int key;
    
    while (scanf("%s", op) == 1) {
        if (strcmp(op, "INSERT") == 0) {
            scanf("%d", &key);
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            scanf("%d", &key);
            if (search(key)) {
                printf("FOUND\n");
            } else {
                printf("NOT FOUND\n");
            }
        }
    }
    
    return 0;
}
