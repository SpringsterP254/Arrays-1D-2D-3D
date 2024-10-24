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
    
     // Prompt the user to insert values
    printf("Enter book title:%s");
    scanf("%s",book1.title);
    
    printf("Enter author name:%s");
    scanf("%s",book1.author);
    
    printf("Enter year of publication:%d");
    scanf("%d",book1.publication_year);

     printf("Enterbook ISBN:%s");
     scanf("%s",book1.ISBN);
     
     printf("Enter book price:%f");
     scanf("%f",book1.price);
     
     // Displaying the required fields
    printf("Book Title: %s\n", book1.title);
    printf("Author: %s\n", book1.author);
    printf("Publication Year: %d\n", book1.publication_year);
    printf("ISBN: %s\n", book1.ISBN);
    printf("Price: %.2f\n", book1.price);
   

    return 0;
}
