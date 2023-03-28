/** EL2208 Praktikum Pemecahan Masalah dengan C 2022/2023
 *   Modul               : 
 *   Hari dan Tanggal    :
 *   Nama (NIM)          :
 *   Nama File           : main.c
 *   Deskripsi           :
 */

#define MAX_QUEUE_SIZE 100 //asumsikan jumlah playlist tidak lebih dari 100

typedef struct {
    int front;
    int rear;
    char data[MAX_QUEUE_SIZE][100];
} Queue;

void initQueue(...) {
    ...
}

int isQueueEmpty(...) {
    ...
}

void enqueue(...) {
    ...
}

char *dequeue(...) {
    ...
}

void printQueue(...) {
    ...
}

int main() {
    ...
    char judul[100];

    printf("Menu:\n");
    printf("1. Tambahkan lagu ke dalam playlist\n");
    printf("2. Putar lagu selanjutnya\n");
    printf("3. Tampilkan daftar lagu dalam playlist\n");

    printf("\nPilihan Anda: ");
    scanf("%d", ...);

    printf("Masukkan judul lagu: ");
    scanf(" %[^\n]", judul); //Gunakan ini untuk input string dengan spasi
    printf("Lagu %s berhasil ditambahkan ke dalam playlist\n", ...);

    printf("Tidak ada lagu yang dapat diputar\n");
    printf("Lagu %s sedang diputar\n", ...);
    printf("Pilihan tidak valid!\n");

    return 0;
}
