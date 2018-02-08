// INET 3102
// lab2.h
// created by Blake Sartor - sarto019

#define MAXTITLE 100
#define MAXAUTHOR 100

struct book {
  char title[MAXTITLE];
  char author[MAXAUTHOR];
  float price;
};
