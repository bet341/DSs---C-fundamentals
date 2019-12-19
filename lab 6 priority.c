 #include<stdio.h>
 #define MAX 5; 
    void insert_by_priority();
    void delete_by_priority();
    void search();
    void display();
 
int queue[MAX];
int prority[MAX];
int front=-1;
int rear=-1;
 
int main()
{
	int choice;
	while(1){
		
	    printf("\n\t\t.................\n");
		printf("\n\t\tChoose Your operation\n");
	    printf("\n\t\t...................\n");
	    printf("\n\t\t...................\n");
	    printf("\n\t\t\n");
	    printf("\n\t\t\n");
		printf("\t\t1,Insert an element to queue\n");
		printf("\t\t2,Delete an element from the queue\n");
		printf("\t\t3,Search an element from the queue\n");
		printf("\t\t4,Exit\n");
		printf("\t\t Enter your choice\t");
		scanf("%d",&choice);
		switch(choice){
		case 1:
	     insert_by_priority()
			  display();
				break;
	    case 2:
	     void delete_by_priority();
	    	display();
	    	break;
		case 3:
			Search();
			break;
	case 4:
		exit(0);
		break;
    default:
		printf("No more option\n");	
	    }
	}
}




void insert_by_priority()
{
	int item;
	int pro;
	
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow no more elements can be inserted");
        return;
    }
    else{
    	printf("\n\t\tEnter The Element To Be Inserted =\t");
    scanf("%d",&item);
    	printf("\n\t\tEnter The priority of the Element =\t");
    scanf("%d",&pro);
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        queue[rear] = item;
       prority[rear]=pro;
    }    
    else
        {
        	int i,j,k;
        	for(i=0;i<rear;i++){
        		if(prority[i]<=pro)
        		 {
        		 	j=queue[i];
        		 	k=prority[i];
        		 	queue[i]=item;
        		 	prority[i]=pro;
        		 	queue[i+1]=j;
        		 	prority[i+1]=k;
        		 }
        		 else{
        		 	
        		 }
        	}
        	rear++;
        }
  
}
}
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}






 
/* Function to delete an element from queue */
void delete_by_priority(int data)
{
    int i;
 
    if ((front==-1) && (rear==-1))
    {
        printf("\nQueue is empty no elements to delete");
        return;
    }
 
    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }
 
        pri_que[i] = -99;
        rear--;
 
        if (rear == -1) 
            front = -1;
        return;
        }
    }
    printf("\n%d not found in queue to delete", data);
}
 
 
 
 
/* Function to display queue elements */
void display_pqueue()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        return;
    }
 
    for (; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }
 
    front = 0;
}
