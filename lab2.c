// INET 3102
// lab2.c
// created by Blake Sartor - sarto019

#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numRecs = 0;

struct book *headPtr;
struct book *mover = null;

void printAllRecord() {
  struct book *incrementer = headPtr;
  for (int i = 0; i < numRecs; i++) {
    printf("%lu\n",sizeof(*headPtr) );
    printf("%s%s", "Title: ", headPtr->title);
    printf("%s%s", "Author: ", headPtr->author);
    printf("%s%f\n", "Price: ", headPtr->price);
    incrementer = incrementer+(sizeof(struct book)*numRecs);
  }
}

void printNumberRecord() {
  printf("%s%d\n", "Number of Records : ", numRecs);
}

void printSizeOfDatabase() {
  if (numRecs == 0) {
    printf("%s\n", "Database is empty!");
  }
  else {
    printf("%s%lu%s\n", "Size of Databse : ", sizeof(struct book)*numRecs, " bytes");
  }
}

void * addRecord(char title[MAXTITLE], char author[MAXAUTHOR], float price) {
  numRecs += 1;

  if (numRecs == 1) {
    headPtr = (struct book*) malloc (sizeof(struct book)*numRecs);
    strcpy(headPtr->title, title);
    strcpy(headPtr->author, author);
    headPtr->price = price;
    return headPtr;
  }
  else {
    printf("%d\n",numRecs );
    mover = malloc (sizeof(struct book)*numRecs);
    printf("%lu\n", sizeof(&mover));
    memcpy(mover, headPtr, sizeof(struct book) * numRecs);
    printf("%s\n", "MEMCPY COmplete");
    free(headPtr);
    mover = mover + sizeof(struct book);
    printf("%lu\n", sizeof(&mover));
    strcpy(mover->title, title);
    strcpy(mover->author, author);
    mover->price = price;
    //free(mover);
    return mover;
  }
}

void deleteRecord() {

}

int main(int argc, char * argv[] ){
  while (1) {
    char book1_title[] = "Harry Potter";
    char book1_author[] = "JK Rowling";
    float book1_price = 42.00;

    //struct book *book1 = (struct book*) malloc (sizeof(struct book));

    char input[100] = {0};
    char titleInput[MAXTITLE] = {0};
    char authorInput[MAXAUTHOR] = {0};
    char priceInput[100] = {0};
    float price;
    printf("%s\n", "MENU");
    printf("%s\n", "=====");
    printf("%s\n", "1. Print all records");
    printf("%s\n", "2. Print number of records");
    printf("%s\n", "3. Print size of database");
    printf("%s\n", "4. Add record");
    printf("%s\n", "5. Delete record");
    printf("%s\n", "6. Print number of accesses to database");
    printf("%s\n", "7. Exit");
    printf("Enter selection : ");
    fgets(input, sizeof(input), stdin);
      if (strlen(input) <= 2) {
        switch(input[0]) {
            case '1' :
              printAllRecord();
              break;
            case '2' :
              printNumberRecord();
              break;
            case '3' :
              printSizeOfDatabase();
              break;
            case '4' :
              printf("%s", "Enter Title : ");
              fgets(titleInput,sizeof(titleInput), stdin);
              printf("%s", "Enter Author : ");
              fgets(authorInput,sizeof(authorInput), stdin);
              printf("%s", "Enter Price : ");
              fgets(priceInput,sizeof(priceInput), stdin);
              price = atof(priceInput);
              headPtr = addRecord(titleInput,authorInput,price);
              printf("%lu\n", sizeof(*headPtr));
              break;
            case '7' :
              free(headPtr);
              return 0;
            default  :
              printf("%s\n", "Incorrect input, please try again...");
              break;
        }
      }
    }
}
