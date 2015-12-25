#ifndef DEF_H_
#define DEF_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct Feather
{
   char* listname;
   char* listurl;
   char* listrule;
}Feather

typedef struct Rule
{
   char* d_name;
   char* d_id;
   char* d_class;

   struct Rule* next;
}Rule;



#endif
