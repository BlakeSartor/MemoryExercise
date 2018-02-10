// INET 3102
// lab2.c
// created by Blake Sartor - sarto019

#include "lab2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int numRecs = 0;

struct book *headPtr;

void printAllRecord() {
  if (numRecs == 0 ) {
    printf("%s\n", "Database is empty!");
  }
  else {
  struct book *counter = headPtr;
  for (int i = 0; i < numRecs; i++) {
    printf("%s\n", "=====");
    printf("%s%s\n", "Title: ", counter->title);
    printf("%s%s\n", "Author: ", counter->author);
    printf("%s%f\n", "Price: ", counter->price);
    counter++;
    }
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

void addRecord(char title[MAXTITLE], char author[MAXAUTHOR], float price) {
  numRecs += 1;

  if (numRecs == 1) {

    headPtr = malloc (sizeof(struct book)*numRecs);
    strcpy(headPtr->title, title);
    strcpy(headPtr->author, author);
    headPtr->price = price;
  }

  else {
    printf("%d\n",numRecs );
    struct book *tmp =  realloc (headPtr, sizeof(struct book)*numRecs);
    //memcpy(tmp, headPtr, sizeof(struct book) * numRecs);
    //free(headPtr);
    headPtr = tmp;
    tmp = tmp + (numRecs - 1);
    strcpy(tmp->title, title);
    strcpy(tmp->author, author);
    tmp->price = price;
  }
}

void deleteRecord() {
  if (numRecs == 0) {
    printf("%s\n", "Database is empty, no record to delete");
  }
  else {
    printf("%s%d\n", "Removing record number : ", numRecs);
    numRecs = numRecs - 1;
    struct book *tmp = realloc (headPtr, sizeof(struct book)*numRecs);
    headPtr = tmp;
  }
}

void accessNumber() {

}

int main(int argc, char * argv[] ){
  addRecord(book1_title,book1_author,book1_price);
  addRecord(book2_title,book2_author,book2_price);
  addRecord(book3_title,book3_author,book3_price);
  addRecord(book4_title,book4_author,book4_price);

  while (1) {
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
    input[strcspn(input, "\n\r")] = 0;
    if (strlen(input) <= 1) {
      switch(input[0]) {
        case '1' :
          printAllRecord();
          printf("%s\n", "=====");
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
          titleInput[strcspn(titleInput, "\n\r")] = 0;
          printf("%s", "Enter Author : ");
          fgets(authorInput,sizeof(authorInput), stdin);
          authorInput[strcspn(authorInput, "\n\r")] = 0;
          printf("%s", "Enter Price : ");
          fgets(priceInput,sizeof(priceInput), stdin);
          priceInput[strcspn(priceInput, "\n\r")] = 0;
          price = atof(priceInput);
          addRecord(titleInput,authorInput,price);
          break;
        case '5' :
          deleteRecord();
          break;
        case '6' :
          break;
        case '7' :
          free(headPtr);
          return 0;
        default  :
          printf("%s\n", "Incorrect input, please try again...");
          break;
        }
    }
    else {
      printf("%s\n", "Incorrect input, please try again...");
    }
  }
}
