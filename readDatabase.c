/*************************************************************************
    > File Name: readDatabase.c
    > Author: lvchao0428
    > Mail: 410148119@qq.com 
    > Created Time: Tue Dec 29 11:36:35 2015
 ************************************************************************/

//#include"xxhash.h"
//#include"uthash.h"
#include<stdio.h>
#include<stdlib.h>
#include<mysql/mysql.h>
#include"def.h"
#include"xxhash.h"
#include<malloc.h>

#include"readDatabase.h"

int connect_database(MYSQL* con)
{
   mysql_init(con);

   if(!mysql_real_connect(con, "localhost", "root", "", "wzty", 0, NULL, 0))
   {
	  fprintf(stderr, "conect error!%s\n", mysql_error(con));
	  return 0;
   }
   else
   {
	  printf("connection suc!\n");
	  return 1;
   }

}


//init webdata
void add_WebData(char* domain, char* url, WebData** webdataes)
{
   WebData* wd;

   unsigned long int tempid;
   tempid = XXH64(url, strlen(url), 0);
   //printf("hashid:%lx\n", wd->id);
   char* filename;
   asprintf(&filename, "%Lx", XXH64(url, strlen(url), 0));
   printf("filename:::::::::%s\n", filename);
   HASH_FIND_INT(*webdataes, &tempid, wd);
   //printf("******domain:%s, url:%s\n", domain, url);
   if(wd == NULL)
   {
	  wd = (WebData*)malloc(sizeof(WebData));
	//  printf("wb suc\n");
	  wd->id = tempid;
	  wd->domain = (char*)malloc(sizeof(char)*(strlen(domain) + 1));
	  bzero(wd->domain, strlen(domain) + 1);
	 // printf("domain suc\n");
	  strcpy(wd->domain, domain);
	  wd->url = (char*)malloc(sizeof(char)*(strlen(url) + 1));
	  bzero(wd->url, strlen(url) + 1);
	  //printf("url suc\n");
	  strcpy(wd->url, url);
	  wd->filename = (char*)malloc(sizeof(char)*17);
	  bzero(wd->filename, 17);
	  sprintf(wd->filename, "%Lx", wd->id);

	  HASH_ADD_INT(*webdataes, id, wd);
   }
   else
   {
	  printf("crashed!!!!!!!!!!!!!!!!!!!!!!\n");
   }
}

void test_adddata(WebData** wd)
{
   add_WebData("www.baidu.com", "www.baidu.com/1/2", wd);
   add_WebData("www.sina.com", "www.sina.com/a", wd);
}

int read_AllData_to_WebData(MYSQL* con, WebData** webdataes)
{
   MYSQL_RES* ls;
   MYSQL_ROW hs;

   int qRet;
   char* query = "select * from webdb";

   qRet = mysql_real_query(con, query, (unsigned int)strlen(query));
   if(qRet)
   {
	  fprintf(stderr, "query error!%s\n", mysql_error(con));
   }
   else
   {
	  printf("query succ!%ld\n", mysql_affected_rows(con));
   }

   ls = mysql_use_result(con);
   int num = 0;
   while(hs = mysql_fetch_row(ls))
   {
	  add_WebData(hs[1], hs[2], webdataes);
	  printf("num:%d\n", num++);
   }
}


void print_webdata(WebData* wd)
{
   WebData* p;
   for(p = wd; p != NULL; p = p->hh.next)
   {
	  printf("id:%Lx, domain:%s, url:%s, filename:%s\n", p->id, p->domain, p->url, p->filename);
   }
}

/*warning! need to put *wd to NULL*/
int read_url(WebData** wd)
{	
   MYSQL con;
   int ret = connect_database(&con);


   if(!ret)
   {
	  return 0;
   }

//   WebData* wd = NULL;
   read_AllData_to_WebData(&con, wd);
  // test_adddata(&wd);
  // print_webdata(wd);
   
   return 1;
}
