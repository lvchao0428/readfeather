#ifndef MYFILEDDEAL_H_
#define MYFILEDDEAL_H_

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<malloc.h>
#include<sys/types.h>
#include<sys/stat.h>


int file_read_full(char** dest, char* filename);

#endif
