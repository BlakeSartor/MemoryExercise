// INET 3102
// lab2.h
// created by Blake Sartor - sarto019

#define MAXTITLE 100
#define MAXAUTHOR 100

char book1_title[] = "Harry Potter";
char book1_author[] = "JK Rowlinn";
float book1_price = 42.00;
char book2_title[] = "David Longhorn and his big red shoes";
char book2_author[] = "Jimmy Johnga";
float book2_price = 99.00;
char book3_title[] = "Vuluptuous Vixens";
char book3_author[] = "Mike Hunt";
float book3_price = 128.00;
char book4_title[] = "C Primer Plus";
char book4_author[] = "Some guy";
float book4_price = 108.00;

struct book {
  char title[MAXTITLE];
  char author[MAXAUTHOR];
  float price;
};
