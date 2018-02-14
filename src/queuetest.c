#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

/*
 * Den här funktionen testar Axiom 1.
 * lsempty(Empty).
 * Kön ska vara tom om den nyss har skapats. *
 */
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
/*
 * Den här funktionen testar Axiom 2.
 * not(lsempty(Enqueue(v,q))
 * Om du lägger in ett värde i en kö ska den inte vara tom.
 */
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
/*
 * Den här funktionen testar Axiom 3.
 * lsempty(q) --> Dequeue(Enqueue(v,q) = q
 * Kön ska vara tom om du har skapat den, lagt till ett värde och därefter
 * tagit bort ett värde.
 */
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
/*
 * not(lsempty) --> Dequeue(Enqueue(v,q)) = Enqueue(v,Dequeue)
 * Skapa en icketom kö. Att lägga till ett värde och därefter ta bort ett värde
 * = Att ta bort ett värde och därefter lägga till ett värde.
 */
void ax4(){
	int *compare1;
	int *compare2;

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
/*
 * lsempty(q) --> Front(Enqueue,v,q)) = v
 * Skapa en tom kö. Om du lägger till ett värde ska fronten av kön ha det
 * värdet.
 */
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
/*
 * not(lsempty(q)) --> Front(Enqueue(v,q)) = Front(q)
 * Skapa en icketom kö. Lägg in ett värde i kön. Fronten av kön ska vara
 * första värdet som lades in i kön (FIFO). *
 */
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

/*
 * Kallar på alla test i tur och ordning, ett test inte lyckas skrivs det
 * ut ett felmeddelande och programmet avslutar.
 */
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
