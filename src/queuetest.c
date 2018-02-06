#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
void ax1(){
	queue *q=queue_empty(free);	//initiera våran kö, samtidigt som vi skapar kö
	int* val1 = malloc(sizeof(int*));	//dynamisk minnesallokering

	queue_enqueue(q, val1);	//Stoppar in värde i kö

	if(queue_is_empty(q)) {	//Kollar om kö är tom eller inte
	printf("Axiom 1 misslyckades.\n");
	queue_kill(q);
	exit(1);	//avslutar hela programmet
	}
	else{
		printf("Axiom 1 fungerade.\n");
	}

	queue_kill(q);	//Avallokerar allt.

}
void ax2(){
	queue *q=queue_empty(free);	//initiera våran kö, samtidigt som vi skapar kö
	int* val1 = malloc(sizeof(int*));	//dynamisk minnesallokering
	queue_enqueue(q, val1);	//Stoppar in värde i kö

	if((int*)queue_front(q)==val1){
		printf("Axiom 2 fungerade.\n");
		queue_kill(q);
	}
	else{
		printf("Axiom 2 misslyckades.\n");
		queue_kill(q);
	}
}
void ax3(){
	queue *q=queue_empty(free);	//initiera våran kö, samtidigt som vi skapar kö
	int* val1 = malloc(sizeof(int*));	//dynamisk minnesallokering
	queue_enqueue(q, val1);	//Stoppar in värde i kö
}



int main(void){

	ax1();
	ax2();
	return 0;
}
