
#include <stdio.h>
#include <string.h>
#include "book.h"

void inputBook(Book book[], int *n)
{
    printf("Nhap so luong sach muon them: \n");
    scanf("%d", n);
    getchar();
    for (int i = 0; i < *n; i++)
    {
        book[i].id = i + 1;
        printf("Moi ban nhap vao ten sach: \n");
        fgets(book[i].bookName, 100, stdin);
        book[i].bookName[strcspn(book[i].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(book[i].author, 50, stdin);
        book[i].author[strcspn(book[i].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%lld", &book[i].price);
        getchar();
        printf("Moi ban nhap vao the loai: \n");
        fgets(book[i].category, 50, stdin);
        book[i].category[strcspn(book[i].category, "\n")] = '\0';
    }
}

void printBook(Book book[], int n) { printf("In toan bo cac sach:\n"); printf("%-10s %-30s %-15s %-20s %-20s\n", "Ma sach", "Ten sach", "Gia tien", "Tac gia", "The loai"); printf("--------------------------------------------------------------------------------------------\n"); for (int i = 0; i < n; i++) { printf("%-10d %-30s %-15lld %-20s %-20s\n", book[i].id, book[i].bookName, book[i].price, book[i].author, book[i].category); } printf("\n"); }

void addBook(Book book[], int *n)
{
    getchar();
    book[*n].id = *n + 1;
    printf("Moi ban nhap vao ten sach: \n");
    fgets(book[*n].bookName, 100, stdin);
    book[*n].bookName[strcspn(book[*n].bookName, "\n")] = '\0';
    printf("Moi ban nhap vao ten tac gia: \n");
    fgets(book[*n].author, 50, stdin);
    book[*n].author[strcspn(book[*n].author, "\n")] = '\0';
    printf("Moi ban nhap vao gia tien: \n");
    scanf("%lld", &book[*n].price);
    getchar();
    printf("Moi ban nhap vao the loai: \n");
    fgets(book[*n].category, 50, stdin);
    book[*n].category[strcspn(book[*n].category, "\n")] = '\0';
    (*n)++;
}

void deleteBook(Book book[], int *n)
{
    int position;
    printf("Moi ban nhap vao vi tri muon xoa:");
    scanf("%d", &position);
    int findIndex = -1;
    for (int i = 0; i < *n; i++)
    {
        if (book[i].id == position)
        {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1)
    {
        printf("Khong tim thay sach de xoa\n");
    }
    else
    {
        for (int i = findIndex; i < *n - 1; i++)
        {
            book[i] = book[i + 1];
        }
        (*n)--;
    }
}

void updateBook(Book book[], int n)
{
    int position;
    printf("Moi ban nhap vao vi tri muon update:");
    scanf("%d", &position);
    int findIndex = -1;
    for (int i = 0; i < n; i++)
    {
        if (book[i].id == position)
        {
            findIndex = i;
            break;
        }
    }
    if (findIndex == -1)
    {
        printf("Khong tim thay sach de update\n");
    }
    else
    {
        getchar();
        printf("Moi ban nhap vao ten sach: \n");
        fgets(book[findIndex].bookName, 100, stdin);
        book[findIndex].bookName[strcspn(book[findIndex].bookName, "\n")] = '\0';
        printf("Moi ban nhap vao ten tac gia: \n");
        fgets(book[findIndex].author, 50, stdin);
        book[findIndex].author[strcspn(book[findIndex].author, "\n")] = '\0';
        printf("Moi ban nhap vao gia tien: \n");
        scanf("%lld", &book[findIndex].price);
        getchar();
        printf("Moi ban nhap vao the loai: \n");
        fgets(book[findIndex].category, 50, stdin);
        book[findIndex].category[strcspn(book[findIndex].category, "\n")] = '\0';
    }
}

void findBook(Book book[], int n)
{
    printf("Chuc nang tim kiem chua hoan thien.\n");
}

void saveBooksToFile(Book book[], int n)
{
    FILE *file = fopen("books.bin", "wb");
    if (file)
    {
        fwrite(&n, sizeof(int), 1, file);
        fwrite(book, sizeof(Book), n, file);
        fclose(file);
        printf("Da luu thong tin sach vao file.\n");
    }
    else
    {
        printf("Khong the mo file de luu.\n");
    }
}

void loadBooksFromFile(Book books[], int *n)
{
    FILE *file = fopen("books.bin", "rb");
    if (file)
    {
        fread(n, sizeof(int), 1, file);
        fread(books, sizeof(Book), *n, file);
        fclose(file);
        printf("Da tai thong tin sach tu file.\n");
    }
    else
    {
        printf("Khong the mo file de doc.\n");
        *n = 0;
    }
}
