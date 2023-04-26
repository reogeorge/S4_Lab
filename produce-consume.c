#include<stdio.h>

int m = 1, f = 0, e = 5;

int wait(int x){

	while(x<=0);
	x--;
	return x;
	
} 

int signal(int x){
	
	x++;
	return x;

}


void consume(){
	
	if (e == 5){
		
		printf("empty , try producing \n");
		return;
	}
	
	else{
		m = wait(m);
		printf("being consumed\n");
		f = wait(f);
		e = signal(e);
		m = signal(m);
	}
}


void produce(){
	
	if (f == 5){
	
		printf("full , try consuming \n");	
		return;
	}
	
	else{
		m = wait(m);
		printf("being produced\n");
		f = signal(f);
		e = wait(e);
		m = signal(m);
	}
}

void main(){

	int y;
	
	do{	

		printf("1 to consume \n2 to produce\n3 to exit\n");
		scanf("%d",&y);
		if(y==1)
			consume();
		else if(y==2) 
			produce();
	}while(y!=3);
	
}
