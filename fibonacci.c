#include <stdio.h>
int main(){

	int f0=0;
	int f1=1;
	int a,b;
	int sum=0;
	printf("enter a number:");
	scanf("%d",&b);
	for(a=0;a<b;a++){
		if(a==0){
			printf("%d\n",a);
		}
		else if(a==1){
			printf("%d\n",a);
		}
		else{
			sum=f0+f1;
			f0=f1;
			f1=sum;
			printf("%d\n",sum);
		}
	}
}

