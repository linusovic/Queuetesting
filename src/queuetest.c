#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

void print_ints(const void *data)
{
	printf("[%d]", *(int*)data);
}

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
	queue *q=queue_empty(free);
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
	queue *q=queue_empty(free);
	int* val1 = malloc(sizeof(int*));	//dynamisk minnesallokering
	if(queue_is_empty(queue_dequeue(queue_enqueue(q, val1)))){
		printf("Axiom 3 fungerade.\n");
	}
	else{
		printf("Axiom 2 misslyckades.\n");
		exit(1);
	}
	queue_kill(q);	//Avallokerar allt.
}

void ax4(){
	int *compare1 = malloc(sizeof(*compare1));
	int *compare2 = malloc(sizeof(*compare1));

	// Create the queue.
	queue *q = queue_empty(free);
	for (int i=1; i<=2; i++) {
		// Allocate memory for one int.
		int *v = malloc(sizeof(*v));
		// Set value.
		*v=i;
		// Push value on stack.
		q=queue_enqueue(q,v);
	}

	int *v = malloc(sizeof(*v));
	*v = 2;

	// Create the queue.
	queue *q2 = queue_empty(free);
	for (int i=1; i<=2; i++) {
		// Allocate memory for one int.
		int *v = malloc(sizeof(*v));
		// Set value.
		*v=i;
		// Push value on stack.
		q2=queue_enqueue(q2,v);
	}

	int *v2 = malloc(sizeof(*v2));
	*v2 = 2;

	compare1 = queue_front(queue_enqueue(queue_dequeue(q),v));
	compare2 = queue_front(queue_dequeue(queue_enqueue(q2,v2)));


	if(*compare1 == *compare2){
		printf("Axiom 4 fungerade.\n");
	}
	else{
		printf("Axiom 4 misslyckades.\n");
		exit(1);
	}
	queue_kill(q2);
	queue_kill(q);

}

void ax5(){
	queue *q=queue_empty(free);
	int* val1 = malloc(sizeof(int*));


	queue_enqueue(q, val1);	//Kö är inte tom
	if(queue_front(q) == val1){
		printf("Axiom 5 fungerade.\n");
	}
	else{
		printf("Axiom 5 misslyckades.\n");
		exit(1);
	}
	queue_kill(q);	//Avallokerar allt.
}
void ax6(){
	queue *q=queue_empty(free);
	int* val1 = malloc(sizeof(int*));
	int* val2 = malloc(sizeof(int*));

	queue_enqueue(q, val1);	//Kö är inte tom
	queue_enqueue(q, val2);	//Kö är inte tom

	if(queue_front(q) == val1){
		printf("Axiom 6 fungerade.\n");
	}
	else{
		printf("Axiom 6 misslyckades.\n");
		exit(1);
	}
	queue_kill(q);	//Avallokerar allt.
}


int main(void){

	ax1();
	ax2();
	ax3();
	ax4();
	ax5();
	ax6();
	printf("Alla test lyckades.\n");

	return 0;
}
