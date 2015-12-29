/*************************************************************************
    > File Name: downloadhtml.c
    > Author: lvchao0428
    > Mail: 410148119@qq.com 
    > Created Time: Tue Dec 29 16:21:34 2015
 ************************************************************************/

#include"downloadhtml.h"

size_t write_data(void* ptr, size_t size, size_t nmemb, void* stream)
{
   size_t written = fwrite(ptr, size, nmemb, (FILE*)stream);

   return written;
}

void download_all_htmls(WebData* wb)
{
   WebData* p;
   int num = 0;
   for(p = wb; p != NULL; p = p->hh.next)
   {
	  int readret = url2file(p);
	  
	  printf("num:%d complete...\n", num++);

	  if(!readret)
	  {//set database hashtml to 0
		 
	  }
	  else
	  {//set database hashtml to 1

	  }
   }
}

//single url to file
int url2file(WebData* wb)
{
   CURL* curl_handle;

   FILE* fp;


   curl_global_init(CURL_GLOBAL_ALL);

   curl_handle = curl_easy_init();

   printf("wb->url:%s\n", wb->url);
   curl_easy_setopt(curl_handle, CURLOPT_URL, wb->url);
   
   curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 0L);//不显示详细信息 

   curl_easy_setopt(curl_handle, CURLOPT_NOPROGRESS, 0L);

   curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
   
   //curl_easy_setopt(curl_handle, CURLOPT_TIMEOUT_MS, 200);
   
   //allow jump once
   curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);

   //set cookie
   //init cookie engine
   curl_easy_setopt(curl_handle, CURLOPT_COOKIEFILE, "");
   char cookiename[50];
   bzero(cookiename, sizeof(cookiename));
   sprintf(cookiename, "./cookie/%s_cookie.ck", wb->domain);
   if(access(cookiename, F_OK) == -1)
   {//不存在此网站的cookie
	  curl_easy_setopt(curl_handle, CURLOPT_COOKIEJAR, cookiename);//write cookie
   }
   else
   {
	  curl_easy_setopt(curl_handle, CURLOPT_COOKIEFILE, cookiename);//read cookie
   }
   

   char tempwritefile[50];
   bzero(tempwritefile, sizeof(tempwritefile));
   sprintf(tempwritefile, "./data/%s", wb->filename);

   fp = fopen(tempwritefile, "w");		//write html to a file

   if(fp)
   {

	  curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, fp);
	  curl_easy_perform(curl_handle);
	  fclose(fp);
   }

   curl_easy_cleanup(curl_handle);
   
   //read the file if has </html> then return 1
   
   char* checkstr = NULL;
   file_read_full(&checkstr, tempwritefile);
   if(!strstr(checkstr, "</html>"))
   {
	  return 0;
   }
   else
   {//write the complete html file;
	  return 1;
   }



}

int file_read_full(char** dest, char* filename)
{//把整个文件读成一个字符串
   FILE* fp;
   struct stat file_stats;
   int nItems, nBytesRead;

   *dest = NULL;
   if((fp = fopen(filename, "r")) == NULL)
   {
	  fprintf(stderr, "failed to open %s - %s\n", filename, strerror(errno));
	  return(-1);
   }
   fstat(fileno(fp), &file_stats);

   if((*dest = (char*)malloc(file_stats.st_size+1)) == NULL)
   {
	  fclose(fp);
	  fprintf(stderr, "failed to allocate memory for reading file%s\n", filename);

	  return(-2);
   }
   nBytesRead = 0;
   while((nItems = fread(*dest + nBytesRead, 1, BUFSIZ,fp)) > 0)
   {
	  nBytesRead += nItems;
   }
   fclose(fp);
   *(*dest + nBytesRead) = '\0';
   
   return (nBytesRead);
}
