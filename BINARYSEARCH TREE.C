#include<stdio.h>
#include<stdlib.h>
struct Node
{
   int data;
   struct Node*left;
   struct Node*right;
};
struct Node* createNode(int data)
{
  struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
  newNode->data=data;
  newNode->left=newNode->right=NULL;
  return newNode;
}
struct Node* insert(struct Node* root,int data)
{
  if(root==NULL)
  {
     return createNode(data);
  }
  if(data<root->data)
  {
      root->left=insert(root->left,data);
  }
  else
  {
     root->right=insert(root->right,data);
  }
     return root;
}

struct Node* search(struct Node* root,int data)
{
  if(root==NULL)
  {
     return 0;
  }

 else if(data==root->data)
 {
     return 1;
 }
 else if(data<root->data)
 {
     return search(root->left,data);
 }
 else
 {
   return search(root->right,data);
 }
}
struct Node* findMin(struct Node* root)
    {
       while(root->left!=NULL)
       {
	  root=root->left;
       }
	 return root;
    }

void displayTree(struct Node* root,int space)
{
   int i;
   if(root==NULL)
   {
     return;
   }
    space+=10;
    displayTree(root->right,space);
    printf("\n");
    for(i=10;i<space;i++)
    {
	 printf(" ");
    }
     printf("%d\n",root->data);
     displayTree(root->left,space);
}



void main()
{
     struct Node* root=NULL;
     int choice,data;
     clrscr();
     while(1)
     {
	printf("\n1.insert\n2.delete\n3.display Tree\n4.search\n5.exit");
	printf("\n enter your choice");
	scanf("%d",&choice);
	switch(choice)
	{

	case 1:printf("enter data to insert:");
	       scanf("%d",&data);
	       root=insert(root,data);
	       printf("%d inserted \n",data);
	       break;

	case 2:printf("enter data to delete");
	       scanf("%d",&data);
	       root=deleteNode(root,data);
	       break;

	case 3:displayTree(root,0);
	       break;

	case 4:printf("enter data to search");
	       scanf("%d",&data);
	       if(search(root,data))
	       {
		  printf("%d found in tree",data);
	       }
	       else
	       {
		printf("%d no found in tree",data);
	       }

	       break;
	case 5:exit(0);
	       break;
	default:printf("invalid choice");
	}
	  getch();
	 }
       }



