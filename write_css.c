/*************************************************************************
    > File Name: write_css.c
    > Author: lvchao0428
    > Mail: 410148119@qq.com 
    > Created Time: Fri Dec 25 11:37:55 2015
 ************************************************************************/

#include<stdio.h>
#include<gumbo.h>
#include"myfiledeal.h"

void add_WebData(char* name, char* url, Rule* rule)
{
   

}

void read_feather(char* filename, WebData** wd)
{
   FILE* fp;
   char* line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(filename, "r");
   if(!fp)
   {
	  exit(EXIT_FAILURE);
   }


   while((read = getline(&line, &len, fp)) != -1)
   {

	  char tempname[200];
	  bzero(tempname, sizeof(tempname));
	  char tempurl[200];
	  bzero(tempurl, sizeof(tempurl));
	  char tempcss[200];
	  bzero(tempcss, sizeof(tempcss));
	  char *end = NULL;
	  end = line;
	  //find name
	  int i = 0;
	  while(*end && *end != ' ' && *end != '\t')
	  {
		 tempname[i++] = *end++;
	  } 
	  tempname[i] = '\0';
	  //find url
	  i = 0;
	  while(*end && *end != ' ' && *end != '\t')
	  {
		 tempurl[i++] = *end++;
	  }
	  tempurl[i] = '\0';
	  //find css
	  i = 0;
	  while(*end)
	  {
		 tempcss[i++] = *end++;
	  }
	  tempcss[i] = '\0';

	  
	  


   }
}

void tran_css_to_Rule(char* strrule, Rule** rule)
{
   //去掉括号
   de_space(strrule);

   char part1[100];
   bzero(part1, sizeof(part1));
   char part2[100];
   bzero(part2, sizeof(part2));

   int index1 = 0, index2 = 0;
   char* p = strrule;
   while(*p && *p != '>')
   {
	  part1[index1++] = *p++;
   }
   part1[index1] = '\0';
   //if(part2 exist)
   p++;
   if(*p)
   {
	  while(*p)
	  {
		 part2[index2++] = *p++;
	  }
   }
   part2[index2] = '\0';
   //put part1 to rule
   p = &part1[0];
   char tempcssname[50];
   bzero(tempcssname, sizeof(tempcssname));
   int index = 0;
   //put name to part1
   while(*p && *p != '.' && *p != '#' && *p != ':')
   {
	  tempcssname[index++] ;  
	  p++;
   }
   tempcssname[index] = '\0';
   //fill part1's id & cls
   char tempcls[50];
   bzero(tempcls, sizeof(tempcls));
   char tempid[50];
   bzero(tempid, sizeof(tempid));
   char tempeq[50];
   bzero(tempeq, sizeof(tempeq));
   switch(*p)
   {
	  case '.':
		 //id一定在前,此项无id
		 index = 0;
		 p++;
		 while(*p && *p != ':')
		 {
			tempcls[index++] = *p++;
		 }
		 tempcls[index] = '\0';
		 index = 0;
		 if(*p)
		 {//肯定为eq值
			index = 0;
			while(*p)
			{
			   tempeq[index++] = *p++;
			}
			tempeq[index] = '\0';
			
		 }
		 break; 
	  case '#':
		 //后面都是 id 接着可能出现 cls
		 index = 0;
		 p++;
		 while(*p && *p != '.' && *p != ':')
		 {
			tempid[index++] = *p++;
		 }
		 tempid[index] = '\0';
		 if(*p == '.')
		 {//后面有cls
			index = 0;
			while(*p && *p != ':')
			{
			   tempcls[index++] = *p++;
			}
			tempcls[index] = '\0';

		 }
		 if(*p)
		 {//肯定为eq
			index = 0;
			while(*p)
			{
			   tempeq[index++] = *p++;
			}
			tempcls[index] = '\0';
				
		 }
		 break;
	  case ':':
		 //读完序号之后去读eq 序号
		 index = 0;
		 //不含 id cls 只含 eq的情况
		 while(*p)
		 {
			tempeq[index++] = *p++;
		 }
		 tempeq[index] = '\0';
		 break;
	  case '\0';
		 //只含有 name
		 break;
   }
   *rule = NULL;
   *rule = (Rule*)malloc(sizeof(Rule));
   bzero(*rule, sizeof(Rule));
   

   //put part2 to rule
   

}

void add_rule(char* name, char* id, char* cls, int eq, Rule** rule)
{
   Rule* s;	  

}

void searh_for_links(GumboNode* node, char** hrefArr)
{
   GumboAttribute* href;
   if(!node)
   {
	  return;
   }
   else if(node-v.elemnt.tag == GUMBO_TAG_A &&
		 (href == gumbo_get_attribute(&node->v.element.attributes, "href")))
   {
	  if(*hrefArr == NULL)
	  {
		 *hrefArr = (char*)malloc(sizeof(char)*(strlen(href->value) + 1));
		 strcpy(*hrefArr, href->value);
	  }

   }

   GumboVector* children = &node->v.element.children;

   int i;
   for(i = 0; i < children->length; ++i)
   {
	  searh_for_links(node, hrefArr);
   }
}

int de_space(char* line)
{
   if(!line)
   {
	  return 0;
   }

   char* p = line;
   char* beg = line;
   while(*p)
   {
	  if(*p == ' ')
	  {
		 p++;
		 continue;
	  }
	  else
	  {
		 *beg = *p;
	  }
   }
   *beg = '\0';

}

void read_rule(char* filename, char** rule)
{
   FILE* fp;

   char* line = NULL;
   size_t len = 0;
   ssize_t read;

   fp = fopen(filename, "r");
   if(!fp)
   {
	  perror("cannot open listurl file\n");
	  exit(EXIT_FAILURE);
   }
   int lineno = 0;
   while((read = getline(&line, &len, fp)) = -1)
   {
	  //deal line to Rule

	  //initial deal to line

	  break;
   }
}

void find_node_by_css(GumboNode* node, char* path)
{
   if(!node)
   {
	  return;
   }
   else if()
}

void output_href(char* htmls)
{

}

int test_write_end(char* str)
{
   FILE* fp;
   fp = fopen("testfile", "w");

   if(!fp)
   {
	  perror("cannot open write file\n");
	  return;
   }

   int ret = fseek(fp, 0, SEEK_END);

   fprintf(fp, "%s\n", str);
   printf("ret:%d\n", ret);
   fclose(fp);

   return 1;
}

int main(int argc, char* argv[])
{
   test_write_end(argv[1]);

   return 0;
}
