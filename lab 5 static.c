#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

#include<stdlib.h>
# define size 100

	
	int ID[size];
    int pat_tre[size];
    
    int labratory[size];
    int finance[size];
    int drag[size];
    
int id=10;
int rear1=-1,front1=0;
int rear2=-1,front2=0;
int rear3=-1,front3=0;
int rear4=-1,front4=0;

int rear5=-1,front5=0;
void Id_Card_queue();
    
    void patient_Treatment_queue();
    void Patient_lab_queue();
    void Finanace_queue();
    void Drag_store();
    void display();
    void search();
int main(){
	int choice;
	int num,n;
while(1){
	
		printf("\n\t\t\n");
		printf("\n\t\t----------------------------\n");
		printf("\n\t\t Main menu \n");
		printf("\n\t\t----------------------------\n");
		printf("\n\t\t 1,Patient record department\n");
		printf("\n\t\t 2,Patient treatment department\n");
		printf("\n\t\t 3,Patient labaratory department\n");
		printf("\n\t\t 4,Finance department\n");
		printf("\n\t\t 5,Drag store Department\n");
		printf("\n\t\t 6,Display the patients in each departments\n");
		printf("\n\t\t 7,Search for specific patient\n");
		printf("\n\t\t 8,Exit\n");
		printf("\n\t\tEnter your choice\t");
		scanf("%d",&choice);
		
		switch(choice){
			case 1:
				Id_Card_queue();
				break;
			case 2:
				patient_Treatment_queue();
				break;
			case 3:
			 Patient_lab_queue();
	
				break;
			case 4:
				Finanace_queue();
					break;
			case 5:
				Drag_store();
				break;
			case 6:
				display();
				break;
			case 7:
				search();
				break;
			case 8:
			    	exit(0);
					break;
			default:
				printf("No more option\n");
		}	
	}
}
void display(){
	
	int i;
	printf("\n\t\tTHE PATIENTSIN THE FIVE DEPARTMENTS\n");
if (front1 > rear1)
{
printf ("\n\t\tThere is no Patient wating for the card\n");
return;
}
else
{
printf("\n\t\tPatients in the card queue :\n");
for(i=front1;i<= rear1;i++)
printf("\n\t\t%d\n",ID[i]);
printf("\n");
}

if ( front2 > rear2)
{
printf ("\n\t\tNo Patient in patient treatment department\n");
return;
}
else
{
printf("\n\t\tpatients in patient treatment department :\n");
for(i=front2;i<= rear2;i++)
printf("\n\t\t%d\n ",ID[i]);
printf("\n");
}
if ( front3 > rear3)
{
printf ("\n\t\tno Patient in labaratory department\n");
return;
}
else
{
printf("\n\t\tpatients in labaratory department are  :\n");
for(i=front3;i<= rear3;i++)
printf("\n\t\t%d\n ",ID[i]);
printf("\n");
}
if ( front4 > rear4)
{
printf ("\n\t\tno Patient in finance department\n");
return;
}
else
{
printf("\n\t\tpatients finance department are  :\n");
for(i=front4;i<= rear4;i++)
printf("\n\t\t%d\n ",ID[i]);
printf("\n");
}
if ( front5 > rear5)
{
printf ("\n\t\tno Patient in drug department\n");
return;
}
else
{
printf("\n\t\tpatients in drug department are  :\n");
for(i=front5;i<= rear5;i++)
printf("\n\t\t%d\n ",ID[i]);
printf("\n");
}
}
	void Id_Card_queue(){
		int num,n,i;
			int choice;
	         printf("\n\t\t WELL COME TO PATIENT RECORD AND RECEPTION DEPARTMENT\n");
	         printf("\n\t\t-------------------------------------------------------\n");
	          while(1){
	         printf("\n\t\t 1,Add new patient to card queue \n");
	         printf("\n\t\t 2,Delete patient from card queue\n");
	         printf("\n\t\t 3,Exit\n");
	        printf("\n\t\t  Enter the choice\t");
	        scanf("%d",&choice);
	        switch(choice){
	    case 1:
		   printf("\n\t\t Enter the number of new arrival patients:\t");
	       scanf("%d",&num);
	      for( i=1;i<=num;i++){
	    	if(rear1>=size){
	    		printf("\t\n\n Queue overflow\n");
	    		exit(0);
	    	}
	    	else{
	    		
	    		rear1=rear1+1;
	    		ID[rear1]=id;
	    		id=id+1;
	    	}
	    }
	    break;
	case 2:
		printf("\n\t\tDelete pateints from card queue\n");
		  if(rear1<front1){
		  	printf("\n\t\tThere is no space\n");
		  	exit(0);
		  }
		  else{
		if(rear2>size){
			printf("\n\t\tThere is no space\n");
		  	exit(0);
		}
		else{
			rear2=rear2+1;
		   pat_tre[rear2]=ID[front1];
		  	front1=front1+1;
		  	printf("\n\t\tThe patient with Id=%d is going to patient queue ",pat_tre[rear2]);
		  }
	      printf("\n\n\t\t Do you want to continue? press 1 to add or 0 to quit:\t");
		    	while(scanf("%d",&n)==1&& n==1){
		    	rear2=rear2+1;
		       pat_tre[rear2]=ID[front1];
		    	front1=front1+1;
		     	printf("\n\t\tThe patient with Id=%d is going to patient queue ",pat_tre[rear2]);
			   printf("\n\n\tDo you want to continue? press 1 to add or 0 to quit:\t");
            }
        }
	break;
	case 3:
		main();
		break;
	
}
display();
}
}
   void patient_Treatment_queue(){
   	  int n;
   	  int i;
   	  printf("\n\t\t Patients in the patient treatment queue\n");
   	  for(i=0;i<=rear2;i++){
		printf("\n\t\t%d\n",pat_tre[i]);
	}
   if(rear2<front2){
		  	printf("\n\t\tThere is no space\n");
		  	exit(0);
		  }
		  else{
		if(rear3>size){
			printf("\n\t\tThere is no space\n");
		  	exit(0);
		}
		else{
			 printf("\n\n\tDO you want to delete a patient to labaratory department ?\n press 1 to continue or 0 to quit:\t");
	        while(scanf("%d",&n)==1&& n==1){
		    		rear3=rear3+1;
		      labratory[rear3]=pat_tre[front2];
		    	front2=front2+1;
		    		printf("\n\t\tThe patient with Id=%d is going to labaratory queue ",labratory[rear3]);
			     printf("\n\n\tDO you want to delete a patient to labaratory department ?\n press 1 to continue or 0 to quit:\t");
            }
        }
   	display();
    }
}
    void Patient_lab_queue(){
    	int n;
    	int i;
   	  printf("\n\t\t Patients in the patient treatment queue\n");
   	  for(i=0;i<=rear3;i++){
		printf("\n\t\t%d\n",labratory[i]);
	}
	 if(rear3<front3){
		  	printf("\n\t\tThere is no space\n");
		  	exit(0);
		  }
		  else{
		if(rear4>size){
			printf("\n\t\tThere is no space\n");
		  	exit(0);
		}
		else{
	      printf("\n\n\tDo you want to delete a patient to finance department ?\n press 1 to continue or 0 to quit:\t");
		    	while(scanf("%d",&n)==1&& n==1){
		    		rear4=rear4+1;
		      finance[rear4]=labratory[front3];
		    	front3=front3+1;
		    		printf("\n\t\tThe patient with Id=%d is going to finance queue ",finance[rear4]);
			   printf("\n\n\tDo you want to delete a patient to finance department ?\n press 1 to continue or 0 to quit:\t");
            }
        }
	display();
	}
}
    void Finanace_queue(){
    	int n;
    	int i;
    	 printf("\n\t\t Patients in the patient treatment queue\n");
   	  for(i=0;i<=rear4;i++){
		printf("\n\t\t%d\n",finance[i]);
	}
	 if(rear4<front4){
		  	printf("\n\t\tThere is no space\n");
		  	exit(0);
		  }
		  else{
		if(rear5>size){
			printf("\n\t\tThere is no space\n");
		  	exit(0);
		}
		else{
	      printf("\n\n\t\tDo you want another patient to drag ?\n press 1 to continue or 0 to quit:\t");
		    	while(scanf("%d",&n)==1&& n==1){
		    		rear5=rear5+1;
		      drag[rear5]=finance[front4];
		    	front4=front4+1;
		    	printf("\n\t\tThe patient with Id=%d is going to labaratory queue ",drag[rear5]);
			    printf("\n\n\t\tDo you want another patient to drag ?\n press 1 to continue or 0 to quit:\t");
            }
        }
	display();
	}
}
    void Drag_store(){
    	int data;
    	int i;
    	 printf("\n\t\t Patients in the patient treatment queue\n");
   	  for(i=0;i<=rear5;i++){
		printf("\n\t\t%d\n",drag[i]);
	}
	 if(rear5<front5){
		  	printf("\n\t\tThere is no space\n");
		  	exit(0);
		  }
		  else{
		
	   data=drag[front5];
	   front5=front5+1;
		
	}
	display();
	}
	void search(){
		int n,i;
		printf("\n\t\tEnter the id of the patient you want to search \n");
		scanf("%d",&n);
		if(rear1>front1){
			for(i=0;i<=rear1;i++){
				if(ID[i]==n){
					printf("\n\t\t The patient is in the card department");
					break;
				}	
			}
		}
		else if(rear2>front2){
			for(i=0;i<=rear2;i++){
				if(pat_tre[i]==n){
					printf("\n\t\t The patient is in the patient treatment department");
					break;
				}
			}
		}
		else if(rear3>front3){
			for(i=0;i<=rear3;i++){
				if(labratory[i]==n){
					printf("\n\t\t The patient is in the labratory department");
					break;
				}	
			}	
		}
			else if(rear4>front4){
			for(i=0;i<=rear4;i++){
				if(finance[i]==n){
					printf("\n\t\t The patient is in the finance department");
					break;
				}	
			}	
		}
			else if(rear5>front5){
			for(i=0;i<=rear5;i++){
				if(drag[i]==n){
					printf("\n\t\t The patient is in the drug department ");
					break;
				}	
			}	
		}
		else{
			printf("\n\t\t No patient with this id");
		}
	}
