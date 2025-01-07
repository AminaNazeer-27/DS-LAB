#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],b[20],c[30],i,j,k,m,n;
clrscr();
printf("Enter the size of the first set:");
scanf("%d",&m);
printf("enter the elements of first set:");
for(i=0;i<m;i++)
{
scanf("%d",&a[i]);
}
printf("Enter the size of the second set:");
scanf("%d",&n);
printf("enter the elements of second set:");
for(j=0;j<n;j++)
{
scanf("%d",&b[j]);
}
i=j=k=0;
for(k=0;k<m+n;k++)
{
if(i<m && j<n)
{
if(a[i]<b[j])
{
c[k]=a[i];
i++;
}
else
{
c[k]=b[j];
j++;
}
}
else if(i<n)
{
c[k]=a[i];
i++;
}
else
{
c[k]=b[j];
j++;
}
}
printf("merged array:");
for(k=0;k<m+n;k++)
{
printf("%d",c[k]);
}
getch();
}
