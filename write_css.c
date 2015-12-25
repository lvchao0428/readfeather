/*************************************************************************
    > File Name: write_css.c
    > Author: lvchao0428
    > Mail: 410148119@qq.com 
    > Created Time: Fri Dec 25 11:37:55 2015
 ************************************************************************/

#include<stdio.h>
#include<gumbo.h>


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

int de_space_beg_end(char* line)
{
   if(!line)
   {
	  return 0;
   }

   char* p = line;
   char* beg = NULL;
   while(*p)
   {
	  if(beg && *p != ' ')
	  {
		 beg = p;
		 break;
	  }
	  p++;
   }

   char* q = line;
   while(*p = '\0')
   {
	  *q = *p;
	  p++;
   }
   *p = '\0';

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
