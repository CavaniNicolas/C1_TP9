#include <stdio.h>
#include <string.h>
#include <math.h>

#include "calculator.h"
#include "fic2LC.h"

/*
const char * p;
char const * p;
	-> le contenu pointé ne change pas

char * const p;
	-> le pointeur ne change pas

-> le const rend constant ce qui est a gauche de lui
*/


int main(){
	char * filename = "resultats";

	int i=0;
	printf("liste des fonctions :\n");
	while (OPER_NAMES[i]!=NULL){
		printf(" %s ",OPER_NAMES[i]);
		i++;
	}

	char ope[50];
	double a,b,delta;
	
	printf("\nChoisissez une fonction à tracer\n :");
	saisir_operation(ope);
	saisir_interval(&a,&b,&delta);
	OP op=identification(ope);
	calcul(a,b,delta,op,filename);


	int yes=0;
	printf("\nAfficher sa courbe ? Y:1 N:0 ?\n :");
	scanf("%d",&yes);
	if (yes==1){
		liste_2pointeurs liste;
		liste = creer_liste();
		fichier_dans_la_liste(&liste,filename);
		afficher_listeTF(liste);
		liberer_liste(&liste);
	}

	return 0;
}
