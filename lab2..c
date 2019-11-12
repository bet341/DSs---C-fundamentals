#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
struct Node{
	int Data;
	struct Node *next;
};
typedef struct Node *node;
         node start;
         node newnode;
       	node tmp;
void create_link(int info){//  to create a linked list
	newnode = (node)malloc(sizeof(node));
	newnode->Data=info;
	newnode->next=NULL;
      if(start==NULL){
      	start=newnode;
      }
	else{
		tmp=start;
		while(tmp->next!=NULL){
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}

void AddBegin(int info){// function to add a linked list at the beginning

	newnode=(node*)malloc(sizeof(node));
	newnode->Data=info;
	if(start==NULL){
		newnode->next=NULL;
	}
	else
   newnode->next=start;
   start=newnode;
 printf("Element is added at the beginning successfully\n\n");
}
void AddEnd(int info){
 newnode=(node*)malloc(sizeof(node));
 newnode->Data=info;
 newnode->next=NULL;
 if(start==NULL){
 	start=newnode;
 }
 else{
 	tmp=start;
 	while(tmp->next!=NULL)
 		tmp=tmp->next;
 	}
 	tmp->next=newnode;
 	printf("node is added at the end successfully\n\n");

}
void anyPosition(int info,int c){
	int k=1;
	 newnode=(node*)malloc(sizeof(node));
     newnode->Data=info;
     newnode->next=NULL;
     tmp=start;
     while(tmp->next!=NULL){
     	if(k==c-1)
     	break;
     	else{

     	tmp=tmp->next;
     	k=k+1;
     }
     }
     newnode->next=tmp->next;
     tmp->next=newnode;
     printf("The element inserted\n\n");
}

void search(int info){
	int k=1;
	if(start==NULL){
		printf("There is no linked list\n");
	}
	else{
		tmp=start;
		while(tmp!=NULL){
			if(tmp->Data==info){
			printf("found in location %d\n",k);
			}
			tmp=tmp->next;
			k=k+1;
		}
	}
}
void display(){
	printf("\t The linked list\n");
	if(start==NULL)
		printf("\n list is empty\n");
		else{
			tmp=start;
			while(tmp!=NULL){
				printf("%d\n",tmp->Data);
				tmp=tmp->next;
			}
		}
	}
void Delete(int info){
	  node hold;
if (start->Data ==info)
{
tmp=start;
start=start->next; // first element deleted
free(tmp);
return;
}
hold=start;
while(hold->next->next != NULL)
{
if(hold->next->Data == info) // element deleted in between
{
tmp=hold->next;
hold->next=tmp->next;
free(tmp);
return;
}
hold=hold->next;
}//the end of while loop
if(hold->next->Data==info) // the end element deleted
{
tmp=hold->next;
free(tmp);
hold->next=NULL;
return;
}
printf ("\n\nElement %d not found",info);
getch();
}

int main(){
	int choice,pos,i,num,element;
	while(1){

		printf("\n\t\tChoose operation\n");
		printf("\t\t1.Create a linked list\n");
		printf("\t\t2.Add at beginning\n");
		printf("\t\t3.Add at end\n");
		printf("\t\t4.Add at any position\n");
		printf("\t\t5.Delete\n");
		printf("\t\t6.Search\n");
		printf("\t\t7.Display\n");
		printf("\t\t8.Exit\n");
		scanf("%d",&choice);
		switch(choice){
		case 1:
				printf("How many nodes do you want to create\n");
				scanf("%d",&num);
				printf("Enter the elements\n");
				for(i=0;i<num;i++){
					scanf("%d",&element);
					create_link(element);

				}
				display();
				printf("Linked list successfully created\n\n");
				break;
		   case 2:
					printf("Enter an element to insert at the beginning\n");
					scanf("%d",&element);
					AddBegin(element);
					display();
					break;
		   case 3:
			         printf("Enter an element to insert at the end\n");
					scanf("%d",&element);
					AddEnd(element);
					display();
					break;
	    case 4:
	    	printf("the position you want to insert\n");
	    	scanf("%d",&pos);
	    	printf("Enter an element to insert at any position\n");
	    	scanf("%d",&element);
	    	anyPosition(element,pos);
	    	display();
	    	break;
		case 5:
			printf("Enter the element to delete\n");
			scanf("%d",&num);
			Delete(num);
			display();
			break;
		case 6:
	     	printf("Enter an element to search at any position\n");
	    	scanf("%d",&element);
	    	search(element);
	    	display();
	    	break;
	    case 7:
	  	    display();
	  	    break;

	    case 8:
		    exit(0);
		    break;
        default:
		    printf("No more option\n");
	    }
	}
}
