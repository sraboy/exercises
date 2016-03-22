#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct student
{
  char fname[100];
  char lname[100];
  int  year;
  int  age;
};

struct student class[]={
  "Sean","Penn",2,21,
  "Sean","Connery",4,25,
  "Angelina","Jolie",3,22,
  "Meryl","Streep",4,29,
  "Robin","Williams",3,32,
  "Bill","Gates",3,17,
  "Jodie","Foster",4,25,
  "John","Travolta",1,17,
  "Isaac","Newton",2,19,
  "Sarah","Palin",2,19
};


/*
  TODO
  @function compare_first_name
  @desc     compares first name of two records.
*/
int compare_first_name(const void* a,const void* b)
{
    // 0: a = b
    //-1: a < b
    // 1: a > b
    int alen = strlen(a);
    int blen = strlen(b);
    struct student * as = (struct student*) a;
    struct student * bs = (struct student*) b;
    
    for(int i = 0; i < alen; i++)
    {
        for(int x = 0; x < blen; x++)
        {
            if(as[i].fname == bs[x].fname)
                continue;
            else if (as->fname[i] < bs->fname[x])
                return -1;
            else
                return 1;
        }
    }
    
    //return 1; /*place holder for now*/
    return 0;
}

/*
  TODO
  @function compare_last_name
  @desc     compares last name of two records.
*/
int compare_last_name(const void* a,const void* b)
{
  
      // 0: a = b
    //-1: a < b
    // 1: a > b
    int alen = strlen(a);
    int blen = strlen(b);
    struct student * as = (struct student*) a;
    struct student * bs = (struct student*) b;
    
    for(int i = 0; i < alen; i++)
    {
        for(int x = 0; x < blen; x++)
        {
            if(as[i].lname == bs[x].lname)
                continue;
            else if (as->lname[i] < bs->lname[x])
                return -1;
            else
                return 1;
        }
    }
    
    //return 1; /*place holder for now*/
    return 0;

}

/*!
  @function apply
  @desc     applies 
 */
void apply(struct student* sarr,int nrec,void (*fp)(void* prec,void* arg),void* arg)
{
  int i=0;
  for(i=0;i<nrec;i++)
    {
      /*callback*/
      fp(&sarr[i],arg);
    }
}

/* 
  @function printrec
  @desc     prints student record
*/
void printrec(void* prec,void* arg)
{
  struct student* pstud=(struct student*)prec;
  printf("%-20s %-20s %2d %2d\n",pstud->fname,pstud->lname,pstud->year,pstud->age);
}


/* 
  @function isolder
  @desc     prints student record only if the student is older than *((int*)arg)
  NOTE: use the same format as 
*/
void isolder(void* prec,void* arg)
{
    int * age = (int *) arg;
    struct student * pst = (struct student *) prec;
    
    if(pst->age < *age)
        return;
    else
        printrec(prec, NULL);
}

int main()
{
  int nstudents=sizeof(class)/sizeof(struct student);
  int age;

  puts("Raw records:");
  puts("-------------------------------");  
  apply(class,nstudents,printrec,NULL);

  /*sort based on first name*/
  puts("Sorted by first name:");
  puts("-------------------------------");  
  qsort(class,nstudents,sizeof(struct student),compare_first_name);
  apply(class,nstudents,printrec,NULL);

  /*sort based on last name*/
  puts("Sorted by last name:");
  puts("-------------------------------");  
  qsort(class,nstudents,sizeof(struct student),compare_last_name);
  apply(class,nstudents,printrec,NULL);

  /*print people older than 20*/
  puts("People older than 20:");
  puts("-------------------------------");  
  age=20;
  apply(class,nstudents,isolder,&age);
  return 0;
}

