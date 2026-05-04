/*
    Nama: Moch. Dimas Ristanto
    NIM : 13224083
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kereta{
    int data;
    struct kereta* next;
};

struct kereta* createKereta(int data) {
    struct kereta* newKereta = (struct kereta*)malloc(sizeof(struct kereta));
    newKereta->data = data;
    newKereta->next = NULL;
    return newKereta;
}

// Menambahkan node di akhir
void addKereta(struct kereta** head, int data) {
    struct kereta* newKereta = createKereta(data);
    if (*head == NULL) {
        *head = newKereta;
        return;
    }

    struct kereta* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newKereta;
}

// Menggabungkan dua list terurut
struct kereta* mergeList(struct kereta* a, struct kereta* b) {
    if (a == NULL) {
        return a;
    }
    if (b == NULL) {
        return b;
    }

    struct kereta* head = NULL;

    if (a->data <= b->data) {
        head = a;
        a = a->next;
    } else {
        head = b;
        b = b->next;
    }

    struct kereta* current = head;

    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            current->next = a;
            a = a->next;
        } else {
            current->next = b;
            b = b->next;
        }
        
        current = current->next;
    }

    if (a != NULL) {
        current->next = a;
    } else {
        current->next = b;
    }

    return head;
}

// Menampilkan output
void printList(struct kereta* head) {
    if (head == NULL) {
        printf("MERGE EMPTY\n");
        return;
    }

    printf("MERGED");
    struct kereta* temp;
    while (head != NULL) {
        printf(" %d", head->data);
        temp = head;
        head = head->next;

        free(temp);
    }
    printf("\n");
}

// Fungsi utama
int main(void) {
    int N, M, val;
    struct kereta *a = NULL, *b = NULL;

    if (scanf(" %d", &N) != 1) {
        return 0;
    }
    for (int i = 0; i < N; i++) {
        scanf(" %d", &val);
        addKereta(&a, val);
    }

    if (scanf(" %d", &M) != 1) {
        return 0;
    }
    for (int i = 0; i < M; i++) {

        scanf(" %d", &val);
        addKereta(&b, val);
    }

    struct kereta* gabunganList = mergeList(a, b);

    printList(gabunganList);

    return 0;
}
