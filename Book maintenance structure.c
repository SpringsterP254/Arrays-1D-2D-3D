//A Book maintainance structure program 

#include <stdio.h>
#include <string.h>

struct Book {
    char title[30];// Title has maximum of 30 characters 
    char author[30];// Author name has maximum of 40 characters 
    int publication_year;
    char ISBN[13]; // ISBN is typically 13 digits
    float price;
};
// Declaration and initialization
int main() {
    struct Book book1;

    strcpy(book1.title, "Introduction to Programming");
    strcpy(book1.author, "John Smith");
    book1.publication_year = 2023;
    strcpy(book1.ISBN, "9780131103627");
    book1.price = 49.99;

     // Displaying the required fields
    printf("Book Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Publication Year: %d\n", book1.publication_year);
    printf("ISBN: %s\n", book1.ISBN);
    printf("Price: %.2f\n", book1.price);

    return 0;
}
