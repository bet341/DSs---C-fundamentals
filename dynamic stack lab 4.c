#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include<stdlib.h>


struct Node{
	int ID;
	char title[50];
	struct Node *next;
};


typedef struct Node node;
node *Top;
node *newnode;
node *peek;
void PushBook(int id,char *tit){
	
	
	newnode=(node*)malloc(sizeof(node));
      newnode->ID=id;
	   strcpy(newnode->title,tit);
	if(Top==NULL){
		newnode->next=NULL;
	}
	else{
		newnode->next=Top;
	}
		Top=newnode;
}
void PopBook(){
	peek=Top;
	Top=Top->next;
	free(peek);
}
void Display(){
	if(Top==NULL){
		printf("There is no book\n\n");
	}
	else{
    	peek=Top;
		printf("\t\tBook ID   \t     Book Name\n\n");
		printf("\t\t------     \t    -----------\n\n");
	while(peek!=NULL){
	
		printf("\t\t%d        \t     %s\n\n",peek->ID,peek->title);
		peek=peek->next;
	}
}
}



int main(){
	int choice,num,n;
	char tb[30];
	while(1){
		printf("\n\t\t.................\n");
		printf("\n\n\t\t Main Menu");
		printf("\n\t\t.................");
		printf("\n\t\t.................\n");
		printf("\n\n\t\t1,Add Book");
		printf("\n\n\t\t2,Delete Book");
		printf("\n\n\t\t3,Display total book and detail of the books");
	    printf("\n\n\t\t4,Exit");
		printf("\n\n\t\tEnter your choice:\t");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("\n\n\tEnter Id of the book:\t");
				scanf("%d",&num);
				printf("\n\n\tEnter the title of the book:\t");
				scanf("%s",&tb);
				PushBook(num,tb);
				printf("\n\n\twould you want to add another book ? press 1 to add or 0 to quit:\t");
		    	while(scanf("%d",&n)==1&& n==1){
		    	printf("\n\n\tEnter Id of the book:\t");
				scanf("%d",&num);
				printf("\n\n\t Enter the title of the book:\t");
				scanf("%s",&tb);
				PushBook(num,tb);
				printf("\n\n\twould you want to add another book ? press 1 to add or 0 to quit:\t");
			}
				break;
		case 2:
			PopBook();
			break;
		case 3:
			Display();
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("No more option\n");
		}
	
			}
}
