/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 100 //asumsikan jumlah playlist tidak lebih dari 100

typedef struct {
    int front;
    int rear;
    char data[MAX_QUEUE_SIZE][50];
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isQueueEmpty(Queue *q) {
    return (q->front == q->rear);
}

void enqueue(Queue *q, char *value) {
    strcpy(q->data[q->rear], value);
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}

char *dequeue(Queue *q) {
    char *value;
    value = q->data[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return value;
}

void printQueue(Queue *q) {
    printf("Daftar lagu dalam playlist:\n");
    if (isQueueEmpty(q)) {
        printf("Playlist kosong\n");
    } else {
        int i = q->front;
        int count = 1;
        while (i != q->rear) {
            printf("%d. %s\n", count, q->data[i]);
            i = (i + 1) % MAX_QUEUE_SIZE;
            count++;
        }
    }
}

int main() {
    Queue q;
    initQueue(&q);

    int choice = 0;
    char title[100];

    printf("Menu:\n");
    printf("1. Tambahkan lagu ke dalam playlist\n");
    printf("2. Putar lagu selanjutnya\n");
    printf("3. Tampilkan daftar lagu dalam playlist\n");

    do {
        printf("\nPilihan Anda: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan judul lagu: ");
                scanf(" %[^\n]%*c", title); //Gunakan ini untuk input string dengan spasi
                for (int i = 0; i < 100; i++)
                {
                    if (title[i] == '\n')
                    {
                        title[i] = 0;
                        break;
                    }
                }
                enqueue(&q, title);
                printf("Lagu %s berhasil ditambahkan ke dalam playlist\n", title);
                break;
            case 2:
                if (isQueueEmpty(&q)) {
                    printf("Tidak ada lagu yang dapat diputar\n");
                } else {
                    char *nextSong = dequeue(&q);
                    for (int i = 0; i < 100; i++)
                    {
                        if (title[i] == '\n')
                        {
                            title[i] = 0;
                            break;
                        }
                    }
                    printf("Lagu %s sedang diputar\n", nextSong);
                }
                break;
            case 3:
                printQueue(&q);
                break;
            default:
                printf("Pilihan tidak valid!\n");
                break;
        }

    } while (choice != 3);

    return 0;
}
