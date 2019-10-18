#include <stdio.h>
struct inf {
	int credit;
	char id[5],name[10];

}data;
struct subject{
	char datastructure;
	char computernetworks;
}mark;
int value(char r){
	int i;
	switch(r) {
		case 'a':
			i=4;
			return i;
			break;
		case 'b':
			i=3;
			return i;
			break;
		case 'c':
			i=2;
			return i;
			break;
		case 'd':
			i=1;
			return i;
			break;
		default:
			printf('invalid grade');
	}
}
int main(){
	int x;
	data.credit=4;
	for(x=0;x<2;x++){
		printf("enter an id\n");
		scanf("%s",data.id);
		printf("enter a name\n");
		scanf("%s",data.name);
		scanf("%c",&mark.datastructure);
		printf("enter grade of datastructure\n");
		scanf("%c",&mark.datastructure);
		float valueD=value(mark.datastructure);
		scanf("%c",&mark.computernetworks);
		printf("enter grade of computernetworks\n");
		scanf("%c",&mark.computernetworks);
		float valueC=value(mark.computernetworks);
		float result=((valueD*data.credit)+(valueC*data.credit))/8;
		printf("the result is = %f\n",result);
	}

}
