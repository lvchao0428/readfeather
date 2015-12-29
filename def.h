#ifndef DEF_H_
#define DEF_H_

#include<stdio.h>
#include<stdlib.h>
#include"uthash.h"

typedef struct Rule
{
   char* d_name;
   char* d_id;
   char* d_class;
   int eq_num;

   UT_hash_handle hh;
}Rule;

typedef struct WebData
{
   unsigned long int id;
   char* domain;
   char* url;
   char* name;
   //char* cssFeather;
   char* filename;
   int isDownload;
   Rule* rule;

   UT_hash_handle hh;
}WebData;

typedef struct Feather
{
   char* listname;
   char* listurl;
   char* listrule;
   int eq_num;

   struct Feather* next;
}Feather;




#endif
