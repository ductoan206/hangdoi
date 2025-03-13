#include <stdio.h>
#include <stdlib.h>

// �?nh nghia m?t n�t trong danh s�ch li�n k?t
struct Node {
    int data;
    struct Node* next;
};

// H�m th�m m?t ph?n t? v�o d?u danh s�ch li�n k?t
void addNodeToFront(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // C?p ph�t b? nh? cho n�t m?i
    newNode->data = value;  // G�n gi� tr? cho n�t m?i
    newNode->next = *head;  // N?i n�t m?i v?i d?u danh s�ch
    *head = newNode;  // C?p nh?t l?i d?u danh s�ch
}

// H�m t�m ph?n t? l?n nh?t trong danh s�ch li�n k?t
int findMax(struct Node* head) {
    if (head == NULL) {
        return -1;  // Tr? v? -1 n?u danh s�ch tr?ng
    }

    int max = head->data;  // Kh?i t?o gi� tr? l?n nh?t b?ng ph?n t? d?u ti�n
    struct Node* current = head;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;  // C?p nh?t gi� tr? l?n nh?t n?u c?n
        }
        current = current->next;
    }

    return max;  // Tr? v? ph?n t? l?n nh?t
}

// H�m in danh s�ch li�n k?t
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// H�m ch�nh
int main() {
    struct Node* head = NULL;  // Kh?i t?o danh s�ch li�n k?t r?ng
    int value;

    // Nh?p c�c ph?n t? v�o danh s�ch
    printf("Nh?p c�c s? nguy�n v�o danh s�ch li�n k?t (nh?p 0 d? d?ng):\n");
    while (1) {
        printf("Nh?p m?t s? nguy�n: ");
        scanf("%d", &value);

        if (value == 0) {
            break;  // D?ng qu� tr�nh nh?p n?u gi� tr? l� 0
        }

        addNodeToFront(&head, value);  // Th�m ph?n t? v�o d?u danh s�ch
    }

    // In danh s�ch li�n k?t
    printf("Danh s�ch li�n k?t: ");
    printList(head);

    // T�m ph?n t? l?n nh?t
    int max = findMax(head);
    if (max == -1) {
        printf("Danh s�ch li�n k?t r?ng!\n");
    } else {
        printf("Ph?n t? l?n nh?t trong danh s�ch l�: %d\n", max);
    }

    return 0;
}

