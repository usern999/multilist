#include <stdlib.h>
#include <conio.h>
#include <random>
#include <time.h>

#define NumberOfStudents 10
#define AmountOfCourses 5

struct COURSE
{
	int NumberOfCourse;
	COURSE *next;
};

struct LIST0
{
	COURSE* next;
	LIST0* lnext;
};


struct LIST
{
	int a;
	LIST0 *cnext;
	LIST *next;
};





void CreateList(LIST *Cur,int i)
{
	Cur->a=i;
	Cur->next=NULL;
}	


void CreateList(COURSE *Cur,int i)
{
	Cur->NumberOfCourse=i;
	Cur->next=NULL;
}


COURSE* GetCount(COURSE *Cur,int n)
{
	for(int i=0;i<n;++i)
	{
		Cur=Cur->next;
		if(!Cur)
		{
			printf("error\n");
			return 0;
		}
	}
	return Cur;
}



void PrintList(LIST *Cur)
{
	Cur=Cur->next;
	LIST0* list0;
	while(Cur)
	{
		list0=Cur->cnext;
		printf("Student %d ",Cur->a);
		Cur=Cur->next;
		printf("Courses ");
		while(list0->lnext)
		{
			printf("%d ",list0->next->NumberOfCourse);
			list0=list0->lnext;
		}
		printf("\n");
	}
	printf("\n");
}

void PrintList(COURSE *Cur)
{
	Cur=Cur->next;
	while(Cur)
	{
		printf("%d ",Cur->NumberOfCourse);
		Cur=Cur->next;
	}
	printf("\n");
}

void PrintList0(LIST *Cur,COURSE *Cur0,LIST *First)
{
	Cur0=Cur0->next;
	
	
	while(Cur0)
	{
		Cur=First;
		Cur=Cur->next;
		printf("Course %d ",Cur0->NumberOfCourse);
		printf("Students ");
		while(Cur)
		{
			LIST0 *list0;
			list0=Cur->cnext;
			while(list0->lnext)
			{
				if(list0->next->NumberOfCourse==Cur0->NumberOfCourse)
				{
					printf("%d ",Cur->a);
					break;
				}
				list0=list0->lnext;
			}
			Cur=Cur->next;
		}
		Cur0=Cur0->next;
		printf("\n");
		
	}
}

void main()
{
	LIST *Cur,*First=new LIST;
	COURSE *cCur,*cFirst=new COURSE;
	First->next=NULL;
	First->cnext=NULL;
	cFirst->next=NULL;
	srand(time(NULL));
	for(int i=0;i<NumberOfStudents;++i)
	{
		if(!First->next)
		{
			Cur=new LIST;
			First->next=Cur;
		}
		else
		{
			Cur->next=new LIST;
			Cur=Cur->next;
		}
		CreateList(Cur,i);
		Cur->cnext=new LIST0;
	}
	Cur=First;
	

	for(int i=0;i<AmountOfCourses;++i)
	{
		if(!cFirst->next)
		{
			cCur=new COURSE;
			cFirst->next=cCur;
		}
		else
		{
			cCur->next=new COURSE;
			cCur=cCur->next;
		}
		CreateList(cCur,i);
	}
	cCur=cFirst;
	

	LIST0* Cur0;
	Cur=Cur->next;
	while(Cur)
	{
		Cur0=Cur->cnext;
		int k1=rand()%4;
		int k=k1+rand()%(AmountOfCourses-k1)+1;
		for(int i=k1;i<k;++i)
		{
			Cur0->next=GetCount(cCur,i+1);
			Cur0->lnext=new LIST0;
			Cur0=Cur0->lnext;
			Cur0->lnext=NULL;
		}
		Cur0->lnext=NULL;
		Cur=Cur->next;
	}
	cCur=cFirst;
	Cur=First;
	PrintList(Cur);
	printf("\n");
	cCur=cFirst;
	Cur=First;
	PrintList0(Cur,cCur,First);

	getch();
}