#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
struct Node{
	int ID;
	char title[20];
	struct Node *prev;
	struct Node *next;
};
typedef struct Node node;
node *newnode;
node *temp;
node *start;
node *hold;
void create_list(int id,char* tit){
 newnode=(node*)malloc(sizeof(node));
	newnode->ID=id;
	strcpy(newnode->title,tit);
if(start==NULL){
	start=newnode;
	newnode->prev=start;
	newnode->next=start;
}
else{
	temp=start;
	while(temp->next!=start){
		temp=temp->next;
	}
	   temp->next=newnode;
		newnode->prev=temp;
		start->prev=newnode;
		newnode->next=start;
}
}
void Delete(int id){
	if(start==NULL){
		printf("\n\t\tNo more music\n");
	}
	else if(start->ID==id){
			temp=start;
		while(temp->next!=start){
			temp=temp->next;
		}
		temp->next=start->next;
     	start->next=temp->next;
		free(start);
		start=temp->next;
		return;
	}
	hold=start;
	while(hold->next->next!=start){
		if(hold->next->ID==id){
			temp=hold->next;
			hold->next=temp->next;
			temp->next->prev=hold;
			free(temp);
			return;
		}
		
		hold=hold->next;
	}
	printf("\n\t\tSucessfully deleted\n");
}
void display(){
	if(start==NULL){
		printf("\n\t\tno more music\n");
	}
	else{
		printf("\n\t\tThe musics in the list are:\n");
		temp=start;
		while(temp->next!=start){
			printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
			temp=temp->next;
		}
		printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
	}
}
void update(int id,char* ti){
	int flag=0;
		if(start==NULL){
		printf("\n\t\tThere is no music\n");
	}
	temp=start;
	while(temp->next!=start){
		if(temp->ID==id){
					strcpy(temp->title,ti);
			printf("\n\t\tThe updated music\n");
			printf("\n\t\t%d\t %s",temp->ID,temp->title);
		 flag=0;
		}
		 temp=temp->next;
	}
		if(temp->ID==id){
	  strcpy(temp->title,ti);
		printf("\n\t\tThe updated music\n");
	printf("\n\t\t%d\t %s",temp->ID,temp->title);
	flag=0;
	}
	if(flag!=0){
		printf("\n\t\tMusic with this id not found\n");
	}
   	
}
void play(int id){
	int flag=0;
		 temp=start;
	if(temp==NULL){
		printf("\n\t\tThere is no music\n");
	}
    while(temp->next!=start){
		if(temp->ID==id){
			printf("\n\t\t%d\t %s",temp->ID,temp->title);
		    flag=0;
		    break;
	    	}
		else{
			flag=1;
		    }
		 temp=temp->next;
	}
	if(temp->next==start&&temp->ID==id){
			printf("\n\t\t%d\t %s",temp->ID,temp->title);
			flag=0;
    
         }
	if(flag!=0){
		printf("\n\t\tMusic with this id not found\n");
	}
   
}
void forward(){
	int co;
	if(start==NULL){
		printf("\n\t\tNo more music\n");
	}
	else{
		temp=start;
		printf("\n\t\t%d\t%s\n",temp->ID,temp->title);
		printf("\n\tWould you like to continue to the next music? Type 0 to stop or 1 to continue:\n");
		while(scanf("%d",&co)==1 &&co==1){
	  {
		printf("\n\t\t%d\t%s\n",temp->next->ID,temp->next->title);
	    printf("\n\tWould you like to continue to the next music? Type 0 to stop or 1 to continue:\n");
		temp=temp->next;
	}
}
}
}
void backward(){
	int co;
	if(start==NULL){
		printf("\n\t\tNo more music\n");
	}
	else{
		temp=start->prev;
		printf("\n\t\t%d\t%s\n",temp->ID,temp->title);
		printf("\n\tWould you like to continue to the next music? Type 0 to stop or 1 to continue:\n");
		while(scanf("%d",&co)==1 &&co==1){
	  {
		printf("\n\t\t%d\t%s\n",temp->prev->ID,temp->prev->title);
	    printf("\n\tWould you like to continue to the next music? Type 0 to stop or 1 to continue:\n");
		temp=temp->prev;
	}
}
}
}
void RepeatAll(){
	int re;
	if(start==NULL){
		printf("\n\t\tno more music\n");
	}
	else{
		temp=start;
		while(temp->next!=start){
			printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
			temp=temp->next;
		}
		printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
	}
		printf("\n\t\tWould you like to repeat all music ? Type 0 to stop or 1 to repeat all:\n");
		while(scanf("%d",&re)==1 &&re==1){
			temp=start;
		while(temp->next!=start){
			printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
			temp=temp->next;
			
		}
		printf("\n\t\t%d\t %s\n",temp->ID,temp->title);
		printf("Would you like to repeat all music ? Type 0 to stop or 1 to repeat all:\n");
	}
	  
}
void RepeatOne( int id){
	int re;
      	int flag=0;
		 temp=start;
	if(temp==NULL){
		printf("\n\t\tThere is no music\n");
	}
    while(temp->next!=start){
		if(temp->ID==id){
			printf("\n\t\t%d\t %s",temp->ID,temp->title);
		    flag=0;
		    break;
	    	}
		else{
			flag=1;
		    }
		 temp=temp->next;
	}
	if(temp->next==start&&temp->ID==id){
			printf("\n\t\t%d\t %s",temp->ID,temp->title);
			flag=0;
    
         }
	if(flag!=0){
		printf("\n\t\tMusic with this id not found\n");
	}
   
   		printf("\n\t\tWould you like to repeat the music ? Type 0 to stop or 1 to repeat all:\n");
		while(scanf("%d",&re)==1 &&re==1){
		printf("\n\t\t%d\t%s\n",temp->ID,temp->title);
		printf("\n\t\tWould you like to repeat the music ? Type 0 to stop or 1 to repeat all:\n");
		
	}
}
int main(){
	int choice,n,pos,id,i;
	char tit[20];
	while(1){
	
	    printf("\n\t\t..........................\n");  
	    printf("\t\t\tMain Menu\n");
	    printf("\n\t\t..........................\n");
		printf("\n");
        printf("\n");
		printf("\n");
        printf("\n");  
	   	printf("\n\t\tChoose Your operation you want\n");
	    printf("\t\t----------------------------\n");
		printf("\t\t1,  Upload new music\n");
		printf("\t\t2,  Delete upload music\n");
		printf("\t\t3,  Update exisiting music\n");
		printf("\t\t4,  Play music\n");
		printf("\t\t5,  Forward  play music\n");
		printf("\t\t6,  Backward play music\n");
		printf("\t\t7,  Repeat all the musics to play\n");
		printf("\t\t8,  play  music and repeat it \n");
		printf("\t\t9,  Shuffle\n");
		printf("\t\t10, Display all\n");
		printf("\t\t11, Exit\n");
		scanf("%d",&choice);
		system("cls");
		switch(choice){
	case 1:
			printf("\n\t\tHow many musics you want:\t");
            scanf("%d",&n);
           for(i=0;i<n;i++)
            {
           printf("\n\t\tEnter the Id of the music:\t");
           scanf("%d",&id);
           printf("\n\t\tEnter the title of the music with Id %d:\t",id);
           scanf("%s",&tit);
           create_list(id,tit);
           
           }
           printf("\n\t\tsucessfully added  the music\n");
        break;
  case 2:
    	printf("\n\tEnter the id of the music you want to delete:\t");
   		scanf("%d",&id);
   		Delete(id);
   		 printf("\n\t\t sucessfully deleted  the music\n");
   		break;
   	case 3:
   		printf("\n\t\tEnter the id of the music you want to update:\t");
   		scanf("%d",&id); 
   		play(id);
   		printf("\n\t\tEnter the new title you want to update:\t ");
     	scanf("%s",&tit);
   		update(id,tit);
   	     break;
   	case 4:
   		printf("\n\t\tEnter the id of the music you want to play:\t");
   		scanf("%d",&id); 
   		play(id);
   	     break;
   	case 5:
   		forward();
   		break;
   	case 6:
   		backward();
   		break;
   	case 7:
   		RepeatAll();
   		break;
   	case 8:
   		printf("\t\nEnter the id of the music you want to repeat:\t");
   		scanf("%d",&id); 
   		RepeatOne(id);
   	     break;
 case 9:
   		break;
   	case 10:
   		display();
   		break;
   	case 11:
   		exit(0);
   		break;
   	default:
   		printf("No more opretions\n");
	}
}
	
}

