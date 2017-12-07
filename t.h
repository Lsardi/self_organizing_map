#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

struct  node{
double * vec;
char * etiq;
};
typedef struct  node node;

struct neurone
{
	double * vecteur;
	char etiquette;
	double activation;
};
typedef struct neurone neurone;


typedef struct bmu bmu;

struct bmu
{
	int x;
	int y;
	bmu * next;
};

typedef bmu* BMU;

int cmp(FILE *);
void lec_ligne(FILE *,node *);
int count_el(FILE *);
void affiche(node *);
double * sum_tab(node *, double * );
double * div_tab(double * , float , int );
int nb_neur(int);

