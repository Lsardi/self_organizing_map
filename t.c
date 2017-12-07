
#include "t.h"
// Compte le nombre de ligne 
int cmp_ligne(FILE * data)
{
	char * line=NULL;
	size_t len=0;
	int cmp=0;
	ssize_t read;
	while((read =getline(&line,&len,data))!= -1)
	{
		cmp++;
	}
	//printf(" le nombre de ligne %d\n",cmp);
	return cmp;
}

int count_el(FILE * data)
{
	char * line=NULL;
	size_t len=0;
	int cmp=0;
	ssize_t read;
	read=getline(&line,&len,data);
	
	strtok(line,",");
	while( line != NULL )
	{
		cmp++;
		line = strtok(NULL, ",");

	}
	read= read/read;
	return cmp;
}

void lec_ligne(FILE * f, node* data)
{
	char * line = NULL;
	size_t len=0;
	ssize_t read;
	double norme =0.0;
	data->vec= malloc(sizeof(double)*4);
	read=getline(&line,&len,f);
	for(int i=0; i<4;i++)
		{	if (i==0)
			{
				data->vec[i]= atof(strtok(line,","));
				//printf("%lf ",data->vec[i]);
			}
			else
			{
				data->vec[i]= atof(strtok(NULL,","));
				//printf("%lf ",data->vec[i]);
			}

		}
		data->etiq=strtok(NULL,"\n");
		norme = pow(data->vec[0],2)+pow(data->vec[1],2)+pow(data->vec[2],2)+pow(data->vec[3],2);
		norme = sqrt(norme);
		for (int i = 0; i < 4; i++)
		{
			data->vec[i] = data->vec[i]/norme;
		}
	//printf("vec 1 = %f vec 2 = %f vec 3 = %f vec 4 = %f etiquete = %s\n ",data->vec[0],data->vec[1],data->vec[2],data->vec[3],data->etiq );
		//
		read = read/read;
	}

	void affiche(node * data)
	{
		printf("vec 1 = %f vec 2 = %f vec 3 = %f vec 4 = %f etiquete = %s\n ",data->vec[0],data->vec[1],data->vec[2],data->vec[3],data->etiq );
	}

	double * sum_tab(node * data, double * a)
	{
		
		for (int i = 0; i < 4; ++i)
		{
			a[i] +=data->vec[i];
		}
		return a;
	}

	double * div_tab(double * a, float div, int nb_case)
	{
		for (int i = 0; i < nb_case; ++i)
		{
			a[i] = a[i]/div;
		}
		return a;
	}

	int nb_neur(int nb_ligne)
	{
		int res= 0;
		res = sqrt(nb_ligne);
		res = res * 5;
		return res;
	}

	double Fale(double min, double max)
	{
		return(rand()/(double)RAND_MAX) * (max-min)+min;
	}

	int Iale(int min, int max)
	{
		return rand()%(max-min)+min;

	}
	int * tab_al(int * t,int nb)
	{
		int tmp = 0;
		int al = 0;
		for (int i = 0; i < nb; i++)
		{
			t[i]=i;
		}
		for (int i = 0; i < nb; i++)
		{
			al = Iale(0,nb);
			tmp = t[al];	
			t[al]= t[i];
			t[i] = tmp;
			
			
		}
		return t;
	}

	void print_map(neurone ** carte_neuronal,int ligne , int colone)
	{
		int cmp = 0;
		for (int i = 0; i <ligne ;i++)
		{
			for (int j = 0; j < colone; j++)
			{
				printf("ligne  %d vec 1 = %f vec 2 = %f vec 3 = %f vec 4 = %f\n",cmp,carte_neuronal[i][j].vecteur[0],carte_neuronal[i][j].vecteur[1],carte_neuronal[i][j].vecteur[2],carte_neuronal[i][j].vecteur[3]);
				cmp++;
			}
		}
	}
	
	double euclidien(double * tab, double * tab1, int taille)
	{
		double res1, res = 0.;
		for (int i = 0; i < taille;i++)
		{
			res -= tab[i];
		}
		pow(res,2);
		for (int i = 0; i < taille; i++)
		{
			res1 -= tab1[i];
		}
		pow(res1,2);

		return sqrt(res - res1);
	}

	BMU ajouter(BMU liste,int x, int y)
	{
		bmu * nouvelElement = malloc(sizeof(bmu));
		nouvelElement->x = x ;
		nouvelElement->y = y ;
		nouvelElement->next = liste;
		return nouvelElement;
	} 

	
	
	int main ()
	{

		srand(getpid());
		double * moy_vec = NULL;
		neurone ** carte_neuronal;
		moy_vec = malloc(sizeof(double)*4);
		FILE * f;
		FILE * i;
		FILE * j;
		int *t;
		i = fopen("iris.txt","r");
		f = fopen("iris.txt","r");
		j = fopen("iris.txt","r");
		if(i == NULL)
			return -1;
		if (f == NULL)
			return -1;
		if (j == NULL)
			return -1;
		int nb_ligne=0;
		nb_ligne =cmp_ligne(i);

		node * data = malloc(sizeof(node)*nb_ligne);


		for (int i = 0; i < nb_ligne; i++)
		{
			lec_ligne(j,&data[i]);	
		}

		//calcule du vecteur moyen 
		for (int i = 0; i < nb_ligne; ++i)
		{
			moy_vec=sum_tab(&data[i],moy_vec);
		}
		moy_vec=div_tab(moy_vec,nb_ligne,4);
		int nb_n = nb_neur(nb_ligne);
		int colone;
		if(nb_n%10==0)
			colone = nb_n/10;
		int ligne = nb_n/colone;
		carte_neuronal = malloc(sizeof(neurone*)*ligne);
		for (int i = 0; i < ligne; i++)
		{
			carte_neuronal[i]= malloc(sizeof(neurone)*colone);
		}
		//carte_neuronal[1][1].vecteur[0]= 0.0;
		for (int i = 0; i < ligne;i++)
		{
			for (int j = 0; j < colone; j++)
			{
				carte_neuronal[i][j].vecteur = malloc(sizeof(double)*4);
				for (int k = 0; k < 4; k++)
				{
					carte_neuronal[i][j].vecteur[k]= moy_vec[k]+Fale(-0.002,0.005);
				}
				
			}
		}
		// allocation et initialisation aleatoir du tab de 0 jusqu'a nb_ligne
		t= malloc(sizeof(int)*nb_ligne);
		t = tab_al(t,nb_ligne);

	//printf("distance = %f\n",euclidien(data[0].vec,carte_neuronal[0][0].vecteur,4));
	//carte_neuronal[0][0].vecteur[1] = moy_vec[1]+Fale(-0.002,0.005);
	//	printf("vec 1 = %f vec 2 = %f vec 3 = %f vec 4 = %f\n",carte_neuronal[0][0].vecteur[1],carte_neuronal[0][1].vecteur[1],carte_neuronal[0][2].vecteur[1],carte_neuronal[0][3].vecteur[1]);
	//	printf("vec 1 = %f vec 2 = %f vec 3 = %f vec 4 = %f\n",moy_vec[0],moy_vec[1],moy_vec[2],moy_vec[3]);
	//	printf("%f\n",Fale(-0.002,0.005));
	//print_map(carte_neuronal,ligne,colone);
		free(t);
		free(i);
		free(f);
		free(j);
		return 0;
	}
