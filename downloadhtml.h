#ifndef DOWNLOADHTML_H_
#define DOWNLOADHTML_H_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
#include<errno.h>
#include<curl/curl.h>
#include"def.h"


int url2file(WebData* wb);

void download_all_htmls(WebData* wb);

int file_read_full(char** dest, char* filename);

#endif
