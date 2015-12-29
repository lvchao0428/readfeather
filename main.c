/*************************************************************************
    > File Name: main.c
    > Author: lvchao0428
    > Mail: 410148119@qq.com 
    > Created Time: Tue Dec 29 17:15:34 2015
 ************************************************************************/

#include<stdio.h>
#include"readDatabase.h"
#include"downloadhtml.h"
#include"def.h"

int main(int argc, char* argv[])
{
   WebData* wb = NULL;

   read_url(&wb);

   download_all_htmls(wb);

   return 0;
}
