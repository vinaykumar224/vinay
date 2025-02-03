#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[100];
    char author[50];
    int id;
};

void addbook() {
    struct book b;
    FILE *file = fopen("library.dat", "ab"); // Changed to .dat for consistency
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter book ID: ");
    scanf("%d", &b.id);
    printf("Enter title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter author: ");
    scanf(" %[^\n]", b.author);
    fwrite(&b, sizeof(b), 1, file);
    fclose(file);
    printf("Book added successfully!\n");
}

void displaybook() {
    struct book b;
    FILE *file = fopen("library.dat", "rb"); // Changed to read mode
    if (!file) {
        printf("Error opening file!\n");
        return;
    }
    printf("\nid\ttitle\tauthor\n");
    while (fread(&b, sizeof(b), 1, file)) {
        printf("%d\t %s\t %s\n", b.id, b.title, b.author);
    }
    fclose(file);
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add\n2. View\n3. Exit\n: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: addbook(); break;
            case 2: displaybook(); break;
            case 3: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0; // This return statement is now correctly placed
}
