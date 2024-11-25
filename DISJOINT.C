#include<stdio.h>
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
   printf("\nParent Array: ");
   for(i=0;i<dis.n;i++)
   {
      printf("%d",dis.parent[i]);
   }
   printf("\nRank Array: ");
   for(i=0;i<dis.n;i++)
   {
      printf("%d",dis.rank[i]);
   }
   printf("\n");
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
   {
      return;
   }
   if(dis.rank[xset]<dis.rank[yset])
   {
      dis.parent[xset]=yset;
      dis.rank[xset]=-1;
   }
   else if(dis.rank[xset]>dis.rank[yset])
   {
      dis.parent[yset]=xset;
      dis.rank[yset]=-1;
   }
   else
   {
      dis.parent[yset]=xset;
      dis.rank[xset]=dis.rank[xset]+1;
      dis.rank[yset]=-1;
   }
}

int main()
{
   int n,x,y;
   int ch,wish;
   clrscr();
   printf("How many elements: ");
   scanf("%d",&dis.n);
   makeSet();

   while(1)
   {

      printf("1.Union \n2.Find \n3.Display\n4.Exit\n");
      printf("Enter Choice:");
      scanf("%d",&ch);

      switch(ch)
      {
	 case 1: printf("Enter elements to perform union: ");
		 scanf("%d %d",&x,&y);
		 Union(x,y);
		 break;
	 case 2: printf("Enter elemenets to check if connected componenets:");
		 scanf("%d%d",&x,&y);
		 if(find(x)==find(y))
		 {
		    printf("Connected Components\n");
		 }
		 else
		 {
		    printf("Not connected components\n");
		 }
		 break;

	 case 3: displaySet();
		 break;

	 case 4: exit(0);
		 break;
      }
   }


}

