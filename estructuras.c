#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct totales{
	int num_lema;
	float total;
	int cont;
	struct totales *sgte;
};
struct gana{
	int num_lema;
	float total;
	int cont;
	struct gana *sgte;
};


struct lemas{  //LES
	int num_lema;
	int num_exp;
	char nom_lema[30];
	int cant_dip;
	int cont ;
	struct lemas *siguiente;
	struct diputados *dip;
};


struct archlemas{  //ARCHIVO LES
	int num_lema;
	int num_exp;
		int cont ;
	char nom_lema[30];
	int cant_dip;
};

struct diputados{ //(TAD PILA)
	char dni[11];
	char apellido [30];
	char nombre [30];
	int num_orden;
	int cargo; // 1 titular 2 suplente 
	int numlema;
	struct diputados *siguiente;
};

struct archdiputados{ //ARCHIVO (TAD PILA)
	char dni[11];
	char apellido [30];
	char nombre [30];
	int num_orden;
	int numlema;
	int cargo;
};

struct sublemas{ //(LES)
	int num_sublema;
	int num_exp;
	char nom_sublema[30];
	int alcance ;
	int cant_sublema;
	int num_lema;
	int cont ;
	struct sublemas *siguiente;
	struct concejales *concej;
};

struct archsublemas{ //ARCHIVO (LES)
	int num_sublema;
	int num_exp;
	char nom_sublema[30];
	int alcance ;
	int cant_sublema;
	int num_lema;
	int cont ;
};

struct concejales{ //(PILA)
	char dni[11];
	char nombre [30];
	char apellido [30];
	int num_orden;
	int cargo;
	int numsub;
	struct concejales *siguiente;
};
struct archconcejales{ //ARCHIVO (PILA)
	char dni[11];
	char nombre [30];
	char apellido [30];
	int num_orden;
	int cargo;
	int numsub;
};

struct votos{ //(LDE)
	int num_lema;
	int num_sub;
	int num_blanco;
	struct votos *anterior;
	struct votos *siguiente;
};
struct archvotos{ //ARCHIVO (LDE)
	int num_lema;
	int num_sub;
	int num_blanco;
};

struct arbol{ //(binario)
	char dni[11];
	char nombre [30];
	char apellido [30];
	int num_orden;
	char cargo[15];
	struct arbol *izquierda;
	struct arbol *derecha;
};
