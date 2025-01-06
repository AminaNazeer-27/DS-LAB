#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct Disjoint
{
  int parent[10];
  int rank[10];
  int n;
}dis;

void makeSet()
{
 int i;
 for(i=0;i<dis.n;i++)
  {
    dis.parent[i]=i;
    dis.rank[i]=0;
  }
}
void displaySet()
{
 int i;
 printf("Parent array: ");
 for(i=0;i<dis.n;i++)
  {
    printf("%d",dis.parent[i]);
  }
 printf("\nRank array: ");
 for(i=0;i<dis.n;i++)
  {
    printf("%d",dis.rank[i]);
  }
}
int find(int x)
{
  if(dis.parent[x]!=x)
   {
     dis.parent[x]=find(dis.parent[x]);
   }
    return dis.parent[x];
}
void Union(int x,int y)
{
  int xset=find(x);
  int yset=find(y);
  if(xset==yset)
   return;
  if(dis.rank[xset]>dis.rank[yset])
   {
     dis.parent[yset]=xset;
     dis.rank[yset]=-1;
   }
  else if(dis.rank[xset]<dis.rank[yset])
   {
     dis.parent[xset]=yset;
     dis.rank[xset]=-1;
    }
  else
   {
     dis.parent[yset]=xset;
     dis.rank[xset]+=1;
     dis.rank[yset]=-1;
   }
}
void main()
{
 int choice,x,y,n;

 clrscr();
 while(1)
  {
    printf("\n1.Makeset\n2.Find\n3.Union\n4.Display\n5.Exit");
    printf("\nEnter your choice:");
    scanf("%d",&choice);
    switch(choice)
     {
       case 1:printf("Enter the no.of elements in the set:");
	      scanf("%d",&dis.n);
	      makeSet();
	      break;
       case 2:printf("Enter two elements to find they are connected");
	      scanf("%d%d",&x,&y);
	      if(find(x)==find(y))
	       {
		 printf("%d and %d are connected",x,y);
	       }
	      else
	       {
		 printf("%d and %d are not connected");
	       }
	       break;
       case 3:printf("Enter the elements to perform union:");
	      scanf("%d%d",&x,&y);
	      Union(x,y);
	      break;
       case 4:displaySet();
	      break;
       case 5:exit(1);
	      break;
       default:printf("Wrong choice");
    }
 }
}