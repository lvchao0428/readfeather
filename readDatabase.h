#ifndef READDATABASE_H_
#define READDATABASE_H_

#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include"def.h"
#include"xxhash.h"
#include<malloc.h>

int connect_database(MYSQL* con);

void add_WebData(char* domain, char* url, WebData** webdataes);


int read_AllData_to_WebData(MYSQL* con, WebData** webdataes);

int read_url(WebData** wd);

#endif
