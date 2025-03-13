#include <stdio.h>
#include <stdlib.h>

// Ð?nh nghia m?t nút trong danh sách liên k?t
struct Node {
    int data;
    struct Node* next;
};

// Hàm thêm m?t ph?n t? vào d?u danh sách liên k?t
void addNodeToFront(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));  // C?p phát b? nh? cho nút m?i
    newNode->data = value;  // Gán giá tr? cho nút m?i
    newNode->next = *head;  // N?i nút m?i v?i d?u danh sách
    *head = newNode;  // C?p nh?t l?i d?u danh sách
}

// Hàm tìm ph?n t? l?n nh?t trong danh sách liên k?t
int findMax(struct Node* head) {
    if (head == NULL) {
        return -1;  // Tr? v? -1 n?u danh sách tr?ng
    }

    int max = head->data;  // Kh?i t?o giá tr? l?n nh?t b?ng ph?n t? d?u tiên
    struct Node* current = head;

    while (current != NULL) {
        if (current->data > max) {
            max = current->data;  // C?p nh?t giá tr? l?n nh?t n?u c?n
        }
        current = current->next;
    }

    return max;  // Tr? v? ph?n t? l?n nh?t
}

// Hàm in danh sách liên k?t
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Hàm chính
int main() {
    struct Node* head = NULL;  // Kh?i t?o danh sách liên k?t r?ng
    int value;

    // Nh?p các ph?n t? vào danh sách
    printf("Nh?p các s? nguyên vào danh sách liên k?t (nh?p 0 d? d?ng):\n");
    while (1) {
        printf("Nh?p m?t s? nguyên: ");
        scanf("%d", &value);

        if (value == 0) {
            break;  // D?ng quá trình nh?p n?u giá tr? là 0
        }

        addNodeToFront(&head, value);  // Thêm ph?n t? vào d?u danh sách
    }

    // In danh sách liên k?t
    printf("Danh sách liên k?t: ");
    printList(head);

    // Tìm ph?n t? l?n nh?t
    int max = findMax(head);
    if (max == -1) {
        printf("Danh sách liên k?t r?ng!\n");
    } else {
        printf("Ph?n t? l?n nh?t trong danh sách là: %d\n", max);
    }

    return 0;
}

