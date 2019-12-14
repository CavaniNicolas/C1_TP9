#include <string.h>
#include <stdio.h>
#include <math.h>

#include "calculator.h"

const char * OPER_NAMES[]={"x","sin(x)","cos(x)","log(x)","exp(x)",NULL};

OP identification(char * op){
	int i=0;
	while (OPER_NAMES[i]!=NULL){
		if (0==strcmp(op,OPER_NAMES[i]))
			return i;
		i++;
	}
	return -1;
}

double evalf(double x, OP op){
	double val;
	switch (op){
		case 0:
			val=x;
			break;
		case 1:
			val=sin(x);
			break;
		case 2:
			val=cos(x);
			break;
		case 3:
			val=log(x);
			break;
		case 4:
			val=exp(x);
			break;
		case -1:
			return -1;
	}

	return val;
}

void calcul(double a, double b, double delta, OP op, char * filename){
	if (op==NONE){
		printf("\nMauvaise opération\n");
	}
	else{
		if (delta==0){
			printf("erreur : delta = 0\n");
		}
		else{
			FILE * file = NULL;
			file = fopen(filename,"w+");
			if (file==NULL){
				printf("can't open file : %s\n",filename);
			}
			else{
				while (a<=b){
					fprintf(file,"%f\n",evalf(a,op));
					a+=delta;
				}
			}
			fclose(file);
		}
	}
}

void saisir_interval(double * a, double * b, double * delta){
	printf("\nChoisissez un interval [a,b] et delta\n");
	printf("a    : ");
	saisir_chiffre(a);
	// printf("%f\n",*a);

	printf("b    : ");
	saisir_chiffre(b);
	// printf("%f\n",*b);

	printf("delta: ");
	saisir_chiffre(delta);
	// printf("%f\n",*delta);
}

void saisir_chiffre(double * a){
	char ligne[50];
	fgets(ligne,50,stdin);

	*a = strtod(ligne,NULL);
}

void saisir_operation(char * chaine){
	fgets(chaine,50,stdin);
	int l = strlen(chaine);
	chaine[l-1]='\0';
}
