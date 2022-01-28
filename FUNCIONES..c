#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estructuras.c"
/////////////////LEMAS////////////////////////
void cargar();
void archlemas (struct lemas *);
struct lemas* insertar( struct lemas *, struct lemas *);
void mostrar(struct lemas*);
struct lemas* borrarLES(struct lemas *);
void crearsub(struct sublemas *,struct lemas *);
void asignapuntero();
void mostrarpuntd(struct diputados *);
void asignadiputados();
void recargardiputados ( struct lemas *);
///////////////SUBLEMAS////////////////////////
void archsublemas(struct sublemas *);
void crearlistasub();
struct sublemas * insertarsub(struct sublemas *,struct sublemas *);
void cargarsub();
void mostrarsub(struct sublemas *);
struct sublemas* borrarLES2(struct sublemas *);
/////////////DIPUTADOS/////////////////////////
void archdip( struct diputados *);
struct diputados * piladiput( struct diputados *,int);
int buscardni (char * ,struct diputados *);
void apilar( struct diputados **, struct diputados **);
void cargarpuntdip(int lema, struct diputados *, struct lemas *);
void mostrarpila (struct lemas *);
void desapilar(struct diputados **, struct diputados **);
 void mostrararchdip ();
void guardardip();
///////////CONCEJALES////////////////////////
void recargarconcejales ( struct sublemas *);
void archcon( struct concejales *);
void asignaconcejales();
struct concejales* pilaconce( struct concejales *, int  );
void guardarconce();
void apilarc( struct concejales **, struct concejales**);
void mostrarpuntc(struct concejales *);
void desapilarc(struct concejales **, struct concejales **);
void mostrarpilac ( struct sublemas *);
///////////////////////// VOTOS ///////////////////////////
void votos();
void mostrarlemas(struct lemas * );
void mostrardiputados(struct diputados *);
void mostrarconcejales(struct concejales *);
void imprime ();
void actualizavoto( int , int ,int );
void recorreysuma(int,int);
int buscasuble(int );
void recuento ();
void archvotos(struct votos *);
void crearlistavotos ();
void reiniciarvotos ();
struct votos* borrarlde( struct votos *);

////////////////////sitema//////////////////////////////////
struct totales* insertartot( struct totales *, struct totales *);
struct totales * cargarTotal( int , float, struct totales * );
struct totales* insertartot2( struct totales *, struct totales *);
struct totales * cargarTotal2( struct totales * , struct totales *);
struct totales *recortarlista(struct totales *, struct totales *);
void Dhondt();
struct totales *recortarlista2(struct totales*, struct totales * );
struct gana * insertagana( struct gana *, struct gana *);
struct gana* borrarnodo(int, struct gana *);
struct totales * cargatotalsublema( int, float , struct totales * );
int determinapuestos(int  , struct gana * );
//////////////////////arbol////////////////////////////////
void arbol();
void copiar(struct concejales *, int );
struct arbol *eliminar (struct arbol *);
struct arbol* borrar(struct arbol *);
struct arbol * insert(struct arbol *,struct arbol *);
void imprimir(struct arbol *);
int busquedaml(struct lemas *);
int busquedams(struct sublemas *, int );
void sacarpila();

struct lemas *l=NULL,*nuev=NULL;
struct diputados  *punt=NULL ,*tp=NULL;
struct sublemas *s=NULL;
struct concejales  *puntt=NULL ,*tpp=NULL;

struct votos *primer=NULL, *ult=NULL;
struct gana *in=NULL, *in2=NULL;
struct totales *vt=NULL, *vconce=NULL;
struct arbol *raiz=NULL;


int main(){
 //struct diputados *tpa=NULL;
	struct archlemas lem;
	FILE *arch;
	if((arch=fopen("lemas.b","rb"))!=NULL){
		fread (&lem,sizeof(lem),1,arch);
 		while (!feof(arch)){
 			nuev=(struct lemas*)malloc(sizeof(struct lemas));
 			if(nuev!=NULL){ 
			 nuev->num_lema=lem.num_lema;
			 nuev->num_exp=lem.num_exp;
			strcpy(nuev->nom_lema,lem.nom_lema);
			nuev->cant_dip=lem.cant_dip;
			nuev->cont=lem.cont;
			nuev->dip=NULL;
			nuev->siguiente=NULL;
			l=insertar(nuev,l);
			 }
			 else{
			 	printf("ERROR EN MEMORIA \n");
			 }
 			fread (&lem,sizeof(lem),1,arch);
		 }
		 	 fclose(arch);		 	 

	}
	
	crearlistasub();	
	crearlistavotos ();
	recargardiputados(l);	////// aca se recargan las pilas correspondientes a cada lema
	recargarconcejales ( s);

int a,op,m=1,op1,op2,op3,op4;
	
///////////////////////////////////MENU///////////////////////////////////////////////////////////////////////////////////////////////
	while(m == 1 ){
		system("cls");
		printf("\t\t*********************** ELECCIONES 2021 MISIONES *********************\n");
		printf("\n");
			printf("\t\t\t               1 - SISTEMA DE CARGA \n");
			printf("\t\t\t               2 - LEMAS Y SUBLEMAS  \n");
			printf("\t\t\t               3 - INGRESO DE VOTOS  \n");
			printf("\t\t\t               4 - DEFINICION DE LAS BANCAS  \n");
			printf("\t\t\t               5 - SALIR  \n");
	printf("\t\nIngrese una opcion: ");
	scanf("%d",&op);
	 system("cls");
	switch (op){
		case 1:
			printf("\t\t\t     1 - CARGAR LEMA \n");
			printf("\t\t\t     2 - CARGAR SUBLEMAS  \n");
			printf("\t\t\t     3 - CARGAR DIPUTADOS   \n");
			printf("\t\t\t     4 - CARGAR CONCEJALES  \n");
			
			
				printf("\t\nIngrese una opcion: ");
				scanf("%d",&op1);
				
				switch(op1){
					
					case 1 : cargar();
					break;
					
					case 2: cargarsub();
					break;
					
					case 3 :asignadiputados();
					break;
					
						case 4 :asignaconcejales();
					break;
				
					
				}	
		break;
		case 2:
			printf("\t\t\t     1 - LISTA DE LEMAS \n");
			printf("\t\t\t     2 - LISTA DE SUBLEMAS  \n");
			printf("\t\t\t     3 - LISTAR DIPUTADOS POR LEMA   \n");
			printf("\t\t\t     4 - LISTAR CONCEJALES POR SUBLEMAS \n");
			
				printf("\t\nIngrese una opcion: ");
				scanf("%d",&op2);
				
				switch(op2){
					
					case 1 :	printf("\tLISTA LEMAS\n");
									mostrar(l); 
					break;
					
					case 2:		printf("\tLISTA SUBLEMAS\n");
								mostrarsub(s);
					break;
					
					case 3 : mostrarpila(l);
					break;
					
						case 4 :mostrarpilac(s);
					break;
					
				}	
				
	
			break;
		case 3:
			printf("\t\t\t     1 - VOTAR \n");
			printf("\t\t\t     2 - LISTA DE VOTOS  \n");
			printf("\t\t\t     3 - RESET DE VOTOS  \n");
			printf("\t\nIngrese una opcion: ");
				scanf("%d",&op3);
				
				switch(op3){
					case 1 :	votos() ;
		break;
		case 2 : imprime()
		;
		break;
		case 3 : reiniciarvotos();
		
		break;
			
		}
			break;
			
		case 4:
				printf("\t\t\t     1 - ESCRUTINIO \n");
			printf("\t\t\t     2 - SISTEMA D´HONDT  \n");
				printf("\t\t\t     3 - ARBOL  \n");
			printf("\t\nIngrese una opcion: ");
				scanf("%d",&op4);
				
		switch(op4){
			
		case 1 :	
			recuento() ;
		break;
		case 2 : 
		Dhondt();
		break;
		case  3: 
		arbol();
		break;
	}
	break;
		case 5:
			m=0;
		
		//sacarpila();
			
			break;
			
}
	system("pause");
}
archlemas(l);
archsublemas(s);
archvotos (primer);
l=borrarLES(l);
s=borrarLES2(s);

}

/////////////////////////////////////// ASIGNACION DE PILAS /////////////////////////////
void recargardiputados ( struct lemas *lem){
	struct archdiputados dipu;
	struct diputados *m=NULL;
	int cont=0;
	FILE*arch;
	while(lem!=NULL){
		arch=fopen("diputados.b","rb");
		if(arch!=NULL){
			fread (&dipu,sizeof(dipu),1,arch);
 			while (!feof(arch)){
			if(lem->num_lema == dipu.numlema ){
			m=(struct diputados*)malloc(sizeof(struct diputados));
 			if(m!=NULL){ 
 			strcpy(m->dni,dipu.dni);
 			strcpy(m->nombre,dipu.nombre);
 			strcpy(m->apellido,dipu.apellido);
 			m->num_orden=dipu.num_orden;
 			m->cargo=dipu.cargo;
 			m->numlema=dipu.numlema;
 			m->siguiente=NULL;
 			apilar(&m,&lem->dip);
			}
		}
		fread (&dipu,sizeof(dipu),1,arch);
	}
		fclose(arch);
	}
	lem=lem->siguiente;
}

}

void recargarconcejales ( struct sublemas *sl){
	struct archconcejales conce;
	struct concejales *d=NULL;
	int cont=0;
	FILE*arch;
	while(sl!=NULL){
		arch=fopen("concejales.b","rb");
		if(arch!=NULL){
			fread (&conce,sizeof(conce),1,arch);
 			while (!feof(arch)){
			if(sl->num_sublema == conce.numsub ){
			d=(struct concejales*)malloc(sizeof(struct concejales));
 			if(d!=NULL){ 
 			strcpy(d->dni,conce.dni);
 			strcpy(d->nombre,conce.nombre);
 			strcpy(d->apellido,conce.apellido);
 			d->num_orden=conce.num_orden;
 			d->cargo=conce.cargo;
 			d->siguiente=NULL;
 			apilarc(&d,&sl->concej);
			}
		}
		fread (&conce,sizeof(conce),1,arch);
	}
		fclose(arch);
	}
	sl=sl->siguiente;
}

}




//////////////////////////////////////////////////LEMAS//////////////////////////////////////////////////////////////////

int vacia( struct diputados *tp){
int  band=0;
	if (tp == NULL) {
		band=1;
}
		if (tp != NULL) {
		band=0;
}	
	printf("%d\n",band);
	return band;
	
}



void archlemas(struct lemas *rc){
	FILE*arch;
	struct lemas *p=NULL;
	struct archlemas archlem;
	p=rc;
	if((arch=fopen("lemas.b","wb"))!=NULL){
	while(p!=NULL){
				archlem.num_lema=p->num_lema;
				archlem.num_exp=p->num_exp;
				archlem.cant_dip=p->cant_dip;
				strcpy(archlem.nom_lema,p->nom_lema);
				archlem.cont=p->cont;
				fwrite(&archlem,sizeof(archlem),1,arch);
		p=p->siguiente;	
		}
		fclose(arch);		
	}
}

void cargar(){
system("cls");
int op,num,exis;
struct lemas *p=NULL,*inaux=NULL;
printf("\nquiere cargar lemas ? 1SI 0NO: ");
scanf("%d",&op);
while(op ==1){
		printf("ingrese el num de lema\n");
		scanf("%d",&num);
		exis=busqueda(num,l);
		if(exis==0){
		p = (struct lemas *) malloc(sizeof(struct lemas));
		if(p != NULL){
			printf("Ingrese el numero de expediente\n");
				scanf("%d",&p->num_exp);
				p->num_lema=num;
				printf("Ingrese la denominacion \n");
				getchar();
				gets(p->nom_lema);
				p->cant_dip=0; //cantidad de votos
				p->cont=0;
				p->dip=NULL;
				p->siguiente=NULL;
				l = insertar(p,l);
	
	}else{
		printf("No hay espacio disponible \n");
	}
		}else	{
		printf("El numero de lema existe \n");
	}
	
	printf("\nQuiere seguir cargando ? 1)SI  0)NO \n");
	scanf("%d",&op);
}

}

struct lemas* insertar( struct lemas *nd, struct lemas *in){

	if(in != NULL){
		if(nd->num_lema < in->num_lema){
			nd->siguiente = in;
			in = nd;
		}else{
			in->siguiente = insertar(nd,in->siguiente);		
		}
	}else{
		in = nd;
	}
	
	return in;
} 

int busqueda(int nlema,struct lemas *l){
	int band=0;
	while(l!=NULL){
		if(nlema==l->num_lema){
			band=1;
			l=NULL;
		}else{
			l=l->siguiente;
		}
	}
	return (band);
} 
void mostrar(struct lemas *in){
//	struct diputados *c=NULL;
	while(in != NULL){
			printf("\n");
			 printf("\n");
			printf("N lema %d\n",in->num_lema);
			printf("N exp %d \n",in->num_exp);
			 printf("Denominacion:%s\n",in->nom_lema);
			  printf("\n");
			 if(in->dip != NULL){ 
			 	printf("***********DIPUTADOS***********\n");
			 mostrarpuntd(in->dip);	
			 printf("\n");
			 }else{
				printf("NO TIENE DIPUTADOS EN LA LISTA \n");
			 }
			 printf("CANTIDAD DE VOTOS: %d \n",in->cant_dip);
			 printf("\n");
			 printf("------------------------/////////--------------------------");
			 printf("\n");
	    in=in->siguiente;
	}	
}


void mostrarpuntd(struct diputados *in){
	while(in != NULL){
			 printf("\n");
			 printf("DNI: %s\n",in->dni);
			 printf("NOMBRE: %s\n",in->nombre);
			 printf("APELLIDO: %s\n",in->apellido);
			 printf("ORDEN %d",in->num_orden);
			 if(in->cargo==1){
			 	 printf("\nTITULAR\n ");
			 }
			 if(in->cargo==2){
			 	 printf("\nSUPLENTE\n ");
			 }
			 	 printf("\n");
			 in=in->siguiente;
			 }
			
	}
	

struct lemas* borrarLES(struct lemas *ini){
struct lemas *ndoaux=NULL;
if(ini != NULL){
 ndoaux = ini;
 ini->siguiente = borrarLES(ini->siguiente);
 ndoaux->siguiente = NULL;
 free(ndoaux);
}
return(ini);
}



/////////////////////////////////////////////DIPUTADOS//////////////////////////////////////////////////////////////////////

void asignadiputados(){
	struct lemas *auxl=NULL;
	struct diputados *auxd=NULL, *pdip=NULL;
	int num, band=0;
	auxd=tp;
	auxl=l;
printf("Ingrese el numero de lema\n");
scanf("%d",&num);
		while(auxl!=NULL && band ==0){
			if(num== auxl->num_lema){
				if(auxl->cont<27){
				 auxl->dip = piladiput(auxl->dip,num);
					auxl->cont++;	
					printf("%d",auxl->cont);
				archdip(auxl->dip);
				}else{
					printf("No se puede cargar mas , limite de diputados \n");
				}
				auxl=NULL;
				band=1;	
			}else{
				auxl=auxl->siguiente;
			}
			
		}	
		if(band == 0 ){
			printf("No existe el numero de lema\n");
		}
	
}

void archdip( struct diputados *tpe){
	FILE*arch;
	struct archdiputados archdip;
	if((arch=fopen("diputados.b","a+b"))!=NULL){
				strcpy(archdip.dni,tpe->dni);
				strcpy(archdip.nombre,tpe->nombre);
				strcpy(archdip.apellido,tpe->apellido);
				archdip.num_orden=tpe->num_orden;
				archdip.cargo=tpe->cargo;
				archdip.numlema=tpe->numlema;
				fwrite(&archdip,sizeof(archdip),1,arch);

			fclose(arch);	
	}
}

struct diputados* piladiput( struct diputados *lema, int numlema ){
struct diputados *p=NULL,*tpaux=NULL;
char dni[30];
int op=1,num,band=0,lem=0,nlem;
printf("CARGAR DIPUTADOS: \n"); 
           	p = (struct diputados *) malloc(sizeof(struct diputados));  
               if(p!=NULL){ 
              printf("\n");
               		printf("Ingrese el DNI del diputado \n");
               		fflush(stdin);
                   gets(dni);
                   band=buscardni(dni,lema);
                   if(band==0){
                   	strcpy(p->dni,dni);
                   	 printf("Ingrese el Nombre del diputado\n");
            	   	fflush(stdin);
                   gets(p->nombre);
                   printf("Ingrese el Apellido del diputado\n");
               		fflush(stdin);
                   gets(p->apellido);
                   printf("Ingrese el Numero de orden del diputado\n");
                  scanf("%d",&p->num_orden);
                  printf("Ingrese el cargo del diputado: 1) TITULAR  2) SUPLENTE \n");
                  scanf("%d",&p->cargo);
                  p->numlema=numlema;
         	  	 	p->siguiente=NULL;
                 	 apilar(&p,&lema);
				  }
				   else{
				   	printf("El DNI ya existe\n");
				   }
                   
                  
             } else{
           printf("No hay espacio en memoria");
 		}	
		 
return(lema);
}


int buscardni (char *dni ,struct diputados *tp1){
	int band=0;
	while(tp1!=NULL){
		if(strcmp(dni,tp1->dni)==0){
			band=1;
			tp1=NULL;
		}else
		tp1=tp1->siguiente;
	}
	return band;
}

int busquedalema (int nlem, struct lemas * le){
	int band=0;
	while((le!=NULL) && (band==0)){
		if(nlem == le->num_lema){
			band=1;
		//	l=NULL;
		}else
		le=le->siguiente;
	}
	return band;
}
 void apilar( struct diputados **p1, struct diputados **tp1){
		    	(*p1)->siguiente=(*tp1);
				*tp1=*p1;
				*p1= NULL;
							

}

void mostrarpila (struct lemas *i){
struct diputados *tp1=NULL;
	int nm;
	printf("Ingrese el numero de lema que desee listar los diputados\n");
	scanf("%d",&nm);
	while(i!=NULL){	
	if(i->num_lema == nm ){
		tp1=i->dip;
	while(tp1!=NULL){
		if( nm == tp1->numlema ){
		printf("DNI %s \n",tp1->dni);
 			printf("NOMBRE %s \n",tp1->nombre);
			 printf("APELLIDO %s\n",tp1->apellido);
			 printf("N ORDEN %d\n",tp1->num_orden);
			 if(tp1->cargo==1){
			 	 printf("TITULAR\n ");
			 }
			 if(tp1->cargo==2){
			 	 printf("SUPLENTE ");
			 }
			 printf("\n");
			 		 printf("\n");
			 	}
		tp1=tp1->siguiente;
	}
}
	i=i->siguiente;
}

}



//////////////////////////////////////////////SUBLEMAS///////////////////////////////////////////////////////////////////////
void archsublemas(struct sublemas *rc){
	FILE*arch;
	struct sublemas *p=NULL;
	struct archsublemas archsub;
	p=rc;
	if((arch=fopen("sublemas.b","wb"))!=NULL){
	while(p!=NULL){
				archsub.num_lema=p->num_lema;
				archsub.num_sublema=p->num_sublema;
				archsub.num_exp=p->num_exp;
				archsub.cant_sublema=p->cant_sublema;
				archsub.alcance=p->alcance;
				strcpy(archsub.nom_sublema,p->nom_sublema);
				archsub.cont=p->cont;
				fwrite(&archsub,sizeof(archsub),1,arch);
		
	
		p=p->siguiente;	
		}
		
		fclose(arch);		
	}
}

struct sublemas* borrarLES2(struct sublemas *ini){
struct sublemas *ndoaux=NULL;
if(ini != NULL){
 ndoaux = ini;
 ini->siguiente = borrarLES2(ini->siguiente);
 ndoaux->siguiente = NULL;
 free(ndoaux);
}
return(ini);
}


void crearlistasub (){
	FILE *arch_sublemas;
	struct archsublemas sub;
	struct sublemas *nueva=NULL;	
	if((arch_sublemas=fopen("sublemas.b","rb"))!=NULL){
		fread(&sub,sizeof(sub),1,arch_sublemas);
		while(!feof(arch_sublemas)){
			nueva=(struct sublemas *)malloc(sizeof(struct sublemas));
				if(nueva!=NULL){
					nueva->num_lema=sub.num_lema;
					nueva->num_sublema=sub.num_sublema;
					nueva->num_exp=sub.num_exp;
					nueva->cant_sublema=sub.cant_sublema;
					strcpy(nueva->nom_sublema,sub.nom_sublema);
					nueva->alcance=sub.alcance;
					nueva->cont=sub.cont;
					nueva->concej=NULL;
					nueva->siguiente=NULL;
					s=insertarsub(nueva,s);
				}else{
					printf("no hay espacio de memoria");
				}
            		fread(&sub,sizeof(sub),1,arch_sublemas);
            }
			fclose(arch_sublemas);
	}else{
		printf("no se pudo abrir el archivo ");
	}
    
    
}


void cargarsub(){
	system("cls");
	struct sublemas *nueva=NULL, *p=NULL;
//	struct lemas *pp=NULL;
	struct archsublemas sub;
	FILE *arch_sublemas;
	int a=1,b,c,num;
	
	while(a==1){
		nueva=(struct sublemas *)malloc(sizeof(struct sublemas));
		if(nueva!=NULL){
		
		system("cls");
        printf("\t------CARGA DE SUBLEMAS------\n\n");
        printf("Ingrese numero de lema\n");
        scanf("%d",&nueva->num_lema);
        //pp=(*l);
        b=recorrerlema(l,nueva);
        if(b==2){
        	printf("Ingrese numero sublemas\n");
        	scanf("%d",&nueva->num_sublema);
        	c=recorrersub(s,nueva);
        	if(c!=2){
			printf("Ingrese numero expediente\n");
        	scanf("%d",&nueva->num_exp);
        	printf("Ingrese denominacion\n");
        	getchar();
        	gets(nueva->nom_sublema);
        	printf("Ingrese alcance\n1-MUNICIPAL\t2-PROVINCIAL\n");
        	scanf("%d",&nueva->alcance);
        	if(nueva->alcance==1 ||nueva->alcance==2){
		   	nueva->cant_sublema=0;
		   	nueva->cont=0;
        	nueva->concej=NULL;
        	nueva->siguiente=NULL;
        	
        	s=insertarsub(nueva,s);
        	 printf("\n SUBLEMA creado con exito\n");
        	
	}else{printf("El alcance ingresado es incorrecto\n");
	}
	}else{printf("SUBLEMA YA EXISTE\n");
	}
	}else {printf("EL LEMA NO EXISTE\n");
	}
	
}else{
	printf("no hay espacio\n");
	}
	printf("\nQuiere cargar mas sublemas 1-SI o 2-NO\n");
            scanf("%d",&a);
}	

}

int recorrerlema(struct lemas *s,struct sublemas *nueva){
int band;
    
        while(s!=NULL){
            if(s->num_lema==nueva->num_lema){
                band=2;
                s=NULL;
            }else{
                band=1;
                s=s->siguiente;
            }
        }
        return(band);
}

struct sublemas* insertarsub( struct sublemas *ndo, struct sublemas *ini){

	if(ini != NULL){
		if(ndo->num_sublema < ini->num_sublema){
			ndo->siguiente = ini;
			ini = ndo;
		}else{
			ini->siguiente = insertarsub(ndo,ini->siguiente);		
		}
	}else{
		ini = ndo;
	}
	
	return ini;
} 

int recorrersub(struct sublemas *s, struct sublemas *nueva){


    int band=0;
        while(s!=NULL){
            if(s->num_sublema==nueva->num_sublema){
                band=2;
                s=NULL;
            }else{
                band=1;
                s=s->siguiente;
            }
        }
       // printf("bandera%d",band);
		return(band);
}

void mostrarsub(struct sublemas *s){
  
   while(s!=NULL){
    	printf("\n");
    	printf("NUM SUBLEMA: %d\n",s->num_sublema);
        printf("NUM LEMA: %d\n",s->num_lema);
        printf("NUM EXPEDIENTE: %d\n",s->num_exp);
        printf("DENOMINACION: %s\n",s->nom_sublema);
        if(s->alcance==1){
        	printf("ALCANCE: MUNICIPAL\n");
		}else{
			printf("ALCANCE: PROVINCIAL\n");
		}
        printf("CANTIDAD VOTOS: %d\n",s->cant_sublema);
        if(s->concej==NULL){
        	printf("NO HAY CONCEJALES EN EL SUBLEMA \n");
		}else
		{
				printf("\n");
			printf("***********CONCEJALES***********\n");
			mostrarpuntc(s->concej);
			printf("\n");
		}
         s=s->siguiente;
	}
	
}

void mostrarpuntc(struct concejales *rc){
	while(rc != NULL){
			printf("\n");
			 printf("\n");
			 printf("DNI: %s\n",rc->dni);
			 printf("NOMBRE: %s\n",rc->nombre);
			 printf("APELLIDO: %s\n",rc->apellido);
			 printf("ORDEN %d",rc->num_orden);
			 rc=rc->siguiente;
			 }
			
	}

///////////////////////////////////CONCEJALES//////////////////////////////////////////////////////////////////

void archcon( struct concejales *tpee){
	FILE*arch;
	struct archconcejales archcon;
	if((arch=fopen("concejales.b","a+b"))!=NULL){
				strcpy(archcon.dni,tpee->dni);
				strcpy(archcon.nombre,tpee->nombre);
				strcpy(archcon.apellido,tpee->apellido);
				archcon.num_orden=tpee->num_orden;
				archcon.cargo=tpee->cargo;
				archcon.numsub=tpee->numsub;
				fwrite(&archcon,sizeof(archcon),1,arch);
				
		
			fclose(arch);	
	}
}


void asignaconcejales(){
	struct sublemas *auxs=NULL;
	struct concejales *auxc=NULL, *pcon=NULL;
	int num, band=0;
	auxc=tpp;
	auxs=s;
printf("Ingrese el numero de sublema\n");
scanf("%d",&num);
		while(auxs!=NULL && band ==0){
			if(num== auxs->num_sublema){
				if(auxs->cont<14){//// no debe cargar mas de 14 
				auxs->concej= pilaconce(auxs->concej,num);
					auxs->cont++;	
					archcon(auxs->concej);
				}else{
					printf("No se puede cargar mas , limite de concejales \n");
				}
				auxs=NULL;
				band=1;	
			}else{
				auxs=auxs->siguiente;
			}
			
		}	
		if(band == 0 ){
			printf("No existe el numero de sublema\n");
		}
	
}


struct concejales* pilaconce( struct concejales *subl , int nume ){
struct concejales *c=NULL;
char dni[30];
int op,num,band=0,sub=0,nsub;
     printf("CARGA DE CONCEJALES: \n");
           	c = (struct concejales *) malloc(sizeof(struct concejales));  
               if(c!=NULL){
               		printf("Ingrese el DNI del concejal\n");
               		fflush(stdin);
                   gets(dni);
                   band=buscardnic(dni,subl);
                   if(band==0){
                   	strcpy(c->dni,dni);
                   	 printf("Ingrese el Nombre del diputado\n");
            	   	fflush(stdin);
                   gets(c->nombre);
                   printf("Ingrese el Apellido del diputado\n");
               		fflush(stdin);
                   gets(c->apellido);
                   printf("Ingrese el Numero de orden del diputado\n");
                  scanf("%d",&c->num_orden);
                  printf("Ingrese el cargo del diputado: 1) TITULAR  2) SUPLENTE \n");
                  scanf("%d",&c->cargo);
                  c->numsub=nume;
                  	c->siguiente=NULL;
                 	 apilarc(&c,&subl);
				  	
				   }
				   else{
				   	printf("El DNI ya existe\n");
				   }
                  
             } else{
           printf("No hay espacio en memoria");
			op=0;
 		}	
		 


return (subl);
}

int buscardnic (char *dni ,struct concejales *tp1){
	int band=0;
	while(tp1!=NULL){
		if(strcmp(dni,tp1->dni)==0){
			band=1;
			tp1=NULL;
		}else
		tp1=tp1->siguiente;
	}
	return band;
}
int busquedasublema (int n, struct sublemas * sb){
	int band=0;
	while((sb!=NULL) && (band==0)){
		if(n == sb->num_sublema){
			band=1;
		
		}else
		sb=sb->siguiente;
	}
	return band;
}

 void apilarc( struct concejales **p1, struct concejales**tp1){
		    	(*p1)->siguiente=(*tp1);
				*tp1=*p1;
				*p1= NULL;
							
}


void mostrarpilac (struct sublemas *sl){
struct concejales *tp1=NULL;
	int numero;
	printf("Ingrese el numero de sublema para ver los concejales\n");
	scanf("%d",&numero);
	while(sl!=NULL){
		if(sl->num_sublema == numero){
			tp1=sl->concej;
	while(tp1!=NULL ){
	if(tp1->numsub == numero){

		printf("DNI %s \n",tp1->dni);
 			printf("NOMBRE %s \n",tp1->nombre);
			 printf("APELLIDO %s\n",tp1->apellido);
			 printf("N ORDEN %d\n",tp1->num_orden);
			  if(tp1->cargo==1){
			 	 printf("TITULAR\n ");
			 }
			 if(tp1->cargo==2){
			 	 printf("SUPLENTE ");
			 }
			 printf("\n");
			 		 printf("\n");
			 	}
		tp1=tp1->siguiente;
	}

}
	sl=sl->siguiente;
}
}

//////////////////////////////////////////////////VOTOS//////////////////////////////////////////////////



void archvotos(struct votos *rc){
	FILE*arch;
	struct votos *p=NULL;
	struct archvotos archv;
	p=rc;
	if((arch=fopen("votos.b","wb"))!=NULL){
	while(p!=NULL){
				archv.num_lema= p->num_lema;
				archv.num_sub= p->num_sub;
				archv.num_blanco=p->num_blanco;
				fwrite(&archv,sizeof(archv),1,arch);
		p=p->siguiente;	
		}
		fclose(arch);		
	}
}



void insertarVoto(struct votos *v ){
    if(primer ==NULL){
    	primer = v;
    	ult=primer;
	}else
	{
		ult->siguiente=v;
		v->anterior=ult;
		ult=v;
	}
    
}


void crearlistavotos (){
	FILE *arch;
	struct archvotos vot;
	struct votos *nuev=NULL;	
	if((arch=fopen("votos.b","rb"))!=NULL){
		fread(&vot,sizeof(vot),1,arch);
		while(!feof(arch)){
			nuev=(struct votos *)malloc(sizeof(struct votos));
				if(nuev!=NULL){
					nuev->num_lema=vot.num_lema;
					nuev->num_sub=vot.num_sub;
					nuev->num_blanco=vot.num_blanco;
					nuev->anterior=NULL;
					nuev->siguiente=NULL;
					insertarVoto(nuev);
				}else{
					printf("no hay espacio de memoria");
				}
            		fread(&vot,sizeof(vot),1,arch);
            }
			fclose(arch);
	}else{
		printf("no se pudo abrir el archivo ");
	}
    
    
}



void imprime(){
	struct votos *vaux=NULL;
	vaux=primer;
	while(vaux!=NULL){
		printf("VOTOS:\n");
		
		if(vaux->num_blanco == 1){
			printf (" Voto en blanco \n");
		}else {
			printf("Lema n: %d ///// Sublema n:  %d \n",vaux->num_lema,vaux->num_sub);
		}
		vaux=vaux->siguiente;
	}
}




void mostrardiputados(struct diputados *in){
	while(in != NULL){
			 printf("\n");
			 if(in->cargo==1){
			 	 printf("TITULAR\n ");
			 }
			 if(in->cargo==2){
			 	 printf("SUPLENTE ");
			 }
			 printf("\n");
			 printf("NOMBRE: %s\n",in->nombre);
			 printf("APELLIDO: %s\n",in->apellido);
			 in=in->siguiente;
			 }
			
	}
	

void mostrarlemas(struct lemas *in){
	struct diputados *c=NULL;
	while(in != NULL){
			printf("\n");
			 printf("\n");
			printf("N lema %d\n",in->num_lema);
			printf("N exp %d \n",in->num_exp);
			 printf("Denominacion:%s\n",in->nom_lema);
			 if(in->dip != NULL){ 
			 	printf("////////////////DIPUTADOS////////////////\n");
			 mostrardiputados(in->dip);	
			 }
			 if(in->dip == NULL){
			 	printf("NO TIENE DIPUTADOS EN LA LISTA \n");
			 }
			 printf("\n");
			 printf("------------------------/////////--------------------------");
			 printf("\n");
	    in=in->siguiente;
	}	
}

void mostrarconcejales(struct concejales *rc){
	while(rc != NULL){
			 printf("\n");
			 if(rc->cargo==1){
			 	 printf("TITULAR\n ");
			 }
			 if(rc->cargo==2){
			 	 printf("SUPLENTE ");
			 }
			 printf("NOMBRE: %s\n",rc->nombre);
			 printf("APELLIDO: %s\n",rc->apellido);
			 rc=rc->siguiente;
			 }
			
	}



void mostrarsublemas(struct sublemas *s){
  if(s==NULL){
  	printf("NULL");
  }
   while(s!=NULL){
    	printf("\n");
    	printf("NUM SUBLEMA: %d\n",s->num_sublema);
        printf("NUM LEMA: %d\n",s->num_lema);
        printf("NUM EXPEDIENTE: %d\n",s->num_exp);
        printf("DENOMINACION: %s\n",s->nom_sublema);
        if(s->alcance==1){
        	printf("ALCANCE: MUNICIPAL\n");
		}else{
			printf("ALCANCE: PROVINCIAL\n");
		}
        if(s->concej==NULL){
        	printf("NO HAY CONCEJALES EN EL SUBLEMA \n");
		}else
		{
			printf("\n");
			printf("////////////CONCEJALES/////////\n");
			mostrarconcejales(s->concej);
			printf("\n");
		}
		printf("-------------------------------------------------------------");
        
    s=s->siguiente;
	}
}



int buscasuble(int numero){
struct sublemas *sub=NULL;
sub=s;
    int band=0;
        while(sub!=NULL){
            if(numero == sub->num_sublema){
                band=1;
  		      }
			sub=sub->siguiente;
        }
        if(numero == 0 ){
        	band=1;
		}
        
		return(band);
}



void votos (){
		int op, existe;
		struct votos *v=NULL;
		printf("******************    ELECCIONES 2021    ***********************\n");
		printf("Ingrese 1 si quiere realizar un voto \n");
		scanf("%d",&op);
		while(op==1){
		v=(struct votos*)malloc(sizeof(struct votos));
		if (v!=NULL){
		printf("-------------LISTA DE LEMAS -----------\n");
		printf("\n");
		mostrarlemas(l);
			printf("\n");
		printf("Ingrese el numero del lema correspondiente que desea votar o en blanco (0):\n");
		printf("VOTO:");
		scanf("%d",&v->num_lema);
			while(v->num_lema < 0 || v->num_lema > 7 ){
				printf("Numero incorrecto , ingrese nuevamente \n");
					scanf("%d",&v->num_lema);
			}
		 system("cls");
		 	printf("-------------LISTA DE SUBLEMAS -----------\n");
		printf("\n");
		mostrarsublemas(s);
			printf("\n");
		printf("Ingrese el numero del sublema correspondiente que desea votar o en blanco (0)\n");
		printf("VOTO:");
		scanf("%d",&v->num_sub);
		existe = buscasuble(v->num_sub);
		while(existe ==0 ){
				printf("Numero incorrecto , ingrese nuevamente \n");
					scanf("%d",&v->num_sub);
					existe = buscasuble(v->num_sub);
			}
		if(v->num_lema==0 && v->num_sub==0){
			v->num_blanco=1;
		}else{
			v->num_blanco=0;
		}
		if(v->num_lema == 0 || v->num_sub == 0){
		 	v->num_blanco =1;
		 }
		v->anterior=NULL;
		v->siguiente=NULL;
		 system("cls");
		 
		 insertarVoto(v);
		actualizavoto( v->num_lema,v->num_sub,v->num_blanco);
		 
		 	}else
		 	{printf("No hay espacio en memoria \n");
			 }
			 printf("Presione 1 si quiere cargar otro voto , 0 de lo contrario \n");
			 scanf("%d",&op);
		}	
		//imprime();
}

void actualizavoto( int lem , int sub, int blan){
	
	if(blan == 1){
		printf("Voto realizado con exito! \n");
	}else{
	
struct lemas *auxl=NULL;
	struct sublemas *auxs=NULL;
	
	auxl=l;

	while(auxl!=NULL){
		if(lem== auxl->num_lema){
			auxl->cant_dip=auxl->cant_dip+1;
		}
		auxl= auxl->siguiente;
	}
		auxs=s;
	while(auxs!=NULL){
		if(sub== auxs->num_sublema){
			auxs->cant_sublema=auxs->cant_sublema+1;
		}
		auxs=auxs->siguiente;
	}
	printf("Voto realizado con exito!\n");
}
}



int sumatot( ){
	struct lemas *ls=NULL;
	struct votos *t=NULL;
	int total=0;
	ls=l;
	
	t= primer;
	
	while(t!=NULL){
		if(t->num_lema && t->num_sub != 0){
				total++;
		}
	t=t->siguiente;
	}
	
return total;
}


 int sumatodo(int le){
	struct sublemas *suble=NULL;
	suble=s;
	int cantidad=0;
	while(suble!=NULL){
		if(le == suble->num_lema){
			cantidad = cantidad + suble->cant_sublema;
		}
		suble=suble->siguiente;
	}
	return cantidad ;
}




void porcentajexlema(int tot){
	struct lemas *in=NULL;
	float porcen, cant, cien=100 , porcdip;
	in=l;
	while (in!=NULL){
		cant=in->cant_dip;
		porcen = (cant / tot) *cien ;
	//	porcdip= in->cant_dip / tot * cien;
	printf("***************************************************************************************************");
		 printf("\n");
		printf("\n El porcentaje obtenido del lema Nro. %d Denominacion: %s es de : %% %.2f \n",in->num_lema,in->nom_lema,porcen);
			 printf("\n");
		//printf("Porcentaje por diputados : %2.f \n", porcdip);
		in=in->siguiente;
	}
}


void recuento (){
	system("cls");
	struct lemas * lemas=NULL;
	struct sublemas *sublem=NULL;
	struct votos  *vo=NULL;
	lemas=l;
	sublem=s;
	vo =primer;
	float  cant, cien=100 , porcdip=0;
int votostotal=0 , votenblanco=0;

	votostotal=sumatot();
	while(lemas!=NULL){	/////primero recorro lista lemas
	cant=lemas->cant_dip;
		porcdip= cant / votostotal * cien;
	printf("\n");
	printf("--------------------------NUMERO LEMA %d --------------------------\n",lemas->num_lema);
	printf("--------------------------DENOMINACION %s --------------------------\n",lemas->nom_lema);
	printf("\n");
		printf("...................Porcentaje por Diputados :  %% %2.f................\n", porcdip);
		lemas->cant_dip=	lemas->cant_dip + sumatodo(lemas->num_lema);
		printf("...............CANTIDAD DE VOTOS ACUMULADOS: %d....................\n",lemas->cant_dip );
		
		printf("***********************************************************************\n");
		lemas=lemas->siguiente;
	}
	
	
	while (vo!= NULL){
		if(vo->num_blanco == 1 ){
			votenblanco++;
		}
		vo=vo->siguiente;
	}

		

	printf("\n");
	printf("----------------------------TOTAL VOTOS---------------------------------------");
		printf ("\n           Cantidad total de votos afirmativos : %d\n ", votostotal);
	// printf("---------------------------------------------------");
	 	printf("                       Votos en blanco %d \n", votenblanco);
	 printf("\n");
	porcentajexlema(votostotal);
	
	
	
	
}

struct votos * borrarlde( struct votos *in){
	struct votos *aux=NULL;
	
	
	while(in!=NULL){
		
			aux=in;
			in->anterior=NULL;
			aux->siguiente=NULL;	
			in=in->siguiente;
				free(aux);
	}

	return (NULL);
}

void reiniciarvotos (){
	struct votos *v=NULL;
	struct lemas *lem=NULL;
	struct sublemas *su=NULL;
	
	v=primer;
	lem=l;
	su=s;
		while(lem!=NULL){
			if( lem->cant_dip!=0){
				lem->cant_dip=0;
			}
		lem=lem->siguiente;
	}
	
		while(su!=NULL){
			if(su->cant_sublema !=0){
					su->cant_sublema=0;
			}
		
			su=su->siguiente;
		}
		
	
	
	primer=borrarlde(primer);
	printf("Votos reiniciados con exito!\n");
	

}


void Dhondt(){
	struct lemas *lema=NULL;
    struct totales *tot = NULL, *tot2=NULL , *tot3=NULL, *st1=NULL, *st2=NULL;
	float cont=1, cont2=1;
	int cant=0;
	float total=0;
	
	lema=l;
	
	while(lema!=NULL){
		cont = 1;
		while(cont <= 20){
			
			cant = lema->cant_dip;
			total = (cant/cont);
			
			vt= cargarTotal(lema->num_lema, total, vt);
		 //aca inserta la lista de totales pero en orden de mayor a menor;	tot2 = cargarTotal2(tot, tot2);
			cant=0;
			total=0;
			cont++;
		}
		lema = lema->siguiente; 
	
	}
	
//tot2 = cargarTotal2(tot, tot2);


tot2 = cargarTotal2(vt, tot2);
tot3 = recortarlista(tot2, tot3);

	printf("--------------------------CUADRO DE SISTEMA DHONDT DE LEMAS-------------------------------------\n");
	
	while(vt!=NULL){
		
		    printf("     LEMA: %d", vt->num_lema);
			printf("              TOTAL: %.2f\n",vt->total);
    
		 vt = vt->sgte;	
	}
	
	struct gana *pun=NULL;
	pun =in;
	
	
	printf("---------------------LISTAS GANADORAS------------------\n");
	while(pun!=NULL){
		    printf("LEMA: %d", pun->num_lema);
			printf("         TOTAL: %.2f",pun->total);
			printf("            PUESTO : %d\n", pun->cont);
			pun= pun->sgte;	
	}


 struct sublemas *su=NULL;
su=s;
	while(su!=NULL){
		cont = 1;
		while(cont <= 7){
			cant = su->cant_sublema;
			total = (cant/cont);	
			vconce= cargatotalsublema(su->num_sublema, total, vconce);
			cant=0;
			total=0;
			cont++;
		}
		su = su->siguiente; 
	}
struct totales *suble=NULL;	
suble=vconce;
	printf("--------------------------CUADRO DE SISTEMA DHONDT DE SUBLEMAS-------------------------------------\n");
	
	while(suble!=NULL){
		
		    printf("SUBLEMA: %d", suble->num_lema);
			printf("           TOTAL: %.2f\n",suble->total);
    
		 suble= suble->sgte;	
	}
	
st1 = cargarTotal2(vconce, st1);
st2 = recortarlista2(st1, st2);

	struct gana *pun2=NULL;
	pun2 =in2;
	
	
	printf("---------------------SUBLEMAS GANADORES------------------\n");
	while(pun2!=NULL){
		    printf("SUBLEMA: %d", pun2->num_lema);
			printf("         TOTAL: %.2f",pun2->total);
			printf("            PUESTO : %d\n", pun2->cont);
			pun2= pun2->sgte;	
	}
	
	
	

}

struct gana * insertagana( struct gana *n, struct gana *in){
	
	if(in != NULL){
			in->sgte = insertagana(n,in->sgte);
					
	}else{ 
		in = n;
	}
	return in;
} 
 
struct totales* insertartot( struct totales *nd, struct totales *in){
	if(in != NULL){
			in->sgte = insertartot(nd,in->sgte);
					
	}else{ 
		in = nd;
	}
	return in;
} 

struct totales * cargarTotal( int numlema, float Total, struct totales * tot){
	struct totales *ndo=NULL, *t1=NULL, *tot2 = NULL;
	int cont=1;
	

	ndo = (struct totales *) malloc(sizeof(struct totales));
	if(ndo != NULL){
		ndo->num_lema = numlema;
		ndo->total = Total;	
		ndo->sgte=NULL;
		tot = insertartot2(ndo,tot);	

	}else{
		printf("No hay espacio disponible \n");
	}
   
t1=tot;
	return (t1);
}


struct totales* insertartot2( struct totales *nd, struct totales *in){
	
	if(in != NULL){
		if(nd->total > in->total){
			nd->sgte = in;
			in = nd;
		}else{
			in->sgte = insertartot2(nd,in->sgte);		
		}
	}else{
		in = nd;
	}
	
	return in;
} 

struct totales * cargarTotal2( struct totales * tot, struct totales * tot2){
	struct totales *ndo=NULL, *t=NULL, *t2= NULL;
	int cont=1;
	
	t = tot;
    t2= tot2;

	while(t!=NULL){

		ndo = (struct totales *) malloc(sizeof(struct totales));
		if(ndo != NULL){
			ndo->num_lema = t->num_lema;
			ndo->total = t->total;	
			ndo->cont = 1; //cont;
			ndo->sgte=NULL;
			t2 = insertartot2(ndo,t2);	
		}else{
			printf("No hay espacio disponible \n");
		}
		t = t->sgte;
				//cont++;
		}
	 return t2;	
	}

		
struct totales *recortarlista(struct totales *tot2 ,struct totales * tot3){
	struct totales *to2=NULL, *to3=NULL, *ndo=NULL;
	struct gana *win=NULL,*i=NULL;
	to2 = tot2;
	to3 =tot3;
	int cont=1;
		while(to2!=NULL){
			if(cont <=20){
				win = (struct gana *) malloc(sizeof(struct gana));
				if(win != NULL){
					win->num_lema = to2->num_lema;
					win->total= to2->total;	
					win->cont= cont;
					win->sgte=NULL;
					in = insertagana(win,in);
					
				}
			}
			to2 = to2->sgte;
				cont++;
			}
							
	
		return (to3);
	
}
	
			
struct totales *recortarlista2(struct totales *t2 ,struct totales * tot3){
	struct totales *to2=NULL, *to3=NULL, *ndo=NULL;
	struct gana *win=NULL;
	to2 = t2;
	int cont=1;
		while(to2!=NULL){
			if(cont <=7){
				win = (struct gana *) malloc(sizeof(struct gana));
				if(win != NULL){
					win->num_lema = to2->num_lema;
					win->total= to2->total;	
					win->cont= cont;
					win->sgte=NULL;
					in2= insertagana(win,in2);
					
				}
			}
			to2 = to2->sgte;
				cont++;
			}
	
		return (tot3);
	
}





struct totales * cargatotalsublema( int num, float Total, struct totales * tot){
	struct totales *ndo=NULL, *t1=NULL, *tot2 = NULL;
	int cont=1;
	

	ndo = (struct totales *) malloc(sizeof(struct totales));
	if(ndo != NULL){
		ndo->num_lema = num;
		ndo->total = Total;	
		ndo->sgte=NULL;
		tot = insertartot2(ndo,tot);	

	}else{
		printf("No hay espacio disponible \n");
	}

t1=tot;
	return (t1);
}



/////////////////////////////////////////////////////////////ARBOL///////////////////////////////////////////////////////


void arbol(){
struct concejales *t=NULL;

	if(in2!=NULL){
		while(s!=NULL){
			if(s->num_sublema == in2->num_lema){
				t=s->concej;
				copiar(t,in2->num_lema);
				in2=in2;		
			}
			s=s->siguiente;
		}
			in2=in2->sgte;
					
	}
	
}
void copiar(struct concejales *c, int b){
	struct arbol *nuevo=NULL;
	int cont;
	while(c!=NULL){
		nuevo = (struct arbol *) malloc(sizeof(struct arbol));
		if(nuevo!=NULL){
		strcpy(nuevo->apellido,c->apellido);
		strcpy(nuevo->nombre,c->nombre);
		strcpy(nuevo->dni,c->dni);
		nuevo->num_orden=c->num_orden;
	//	nuevo->numsub=c->numsub;
		nuevo->derecha=NULL;
		nuevo->izquierda=NULL;
		//cont=cont+1;
		//printf("cont%d",cont);
		raiz=insert(raiz,nuevo);
	}else{printf("No hay espacio\n");
	}

	c=c->siguiente;	
}
	printf("Arbol ordenado Alfabeticamente\n");
	imprimir(raiz);
//	raiz=borrar(raiz); con esto se borra el arbol
}	

struct arbol *eliminar (struct arbol *raiz){
     if(raiz != NULL) {
               raiz->izquierda= eliminar(raiz->izquierda);
               raiz->derecha = eliminar(raiz->derecha);
               if(raiz->apellido>0) {
                       raiz = borrar(raiz);
				  }
     }
     return (raiz);
}


struct arbol* borrar(struct arbol *borrar){
	struct arbol *ant, *r;
       ant = NULL;
       r = borrar->izquierda;
       if (r != NULL){
           while (r->derecha != NULL){
                 ant = r;
                 r = r->derecha;
           }
           r->derecha = borrar->derecha;
           if ( ant != NULL){
              ant->derecha = r->izquierda;
              r->izquierda = borrar->izquierda;
           }
       } else {
              r = borrar->derecha;

       }
       free(borrar);
       return(r);
}

struct arbol * insert(struct arbol *r,struct arbol *nueva){
    if(r!=NULL){
        if(strcmp(r->apellido,nueva->apellido)==0){
               // printf("el apellido ya existe %s", r->apellido);
               if(strcmp(r->nombre,nueva->nombre)>0){
               			r->izquierda=insert(r->izquierda,nueva);
               	  }else{
               	  	
               	  		 r->derecha=insert(r->derecha,nueva);
					 }
               	
             
        }else{
             if(strcmp(r->apellido,nueva->apellido)>0){
               	r->izquierda=insert(r->izquierda,nueva);
            }else{
               r->derecha=insert(r->derecha,nueva);
                 
                 
            }
        }
    }else{
        r=nueva;
          }
    return (r);
}

void imprimir(struct arbol *r){
	int cont=0;
	if(r!=NULL){
		printf("\n");
		
		imprimir(r->izquierda);
		printf("APELLIDO %s\n",r->apellido);
		printf("NOMBRE %s\n",r->nombre);
		printf("DNI %s\n",r->dni);
		printf("NUMERO ORDEN %d\n",r->num_orden);
			printf("\n");
		imprimir(r->derecha);
	}
}
//////////////////////////////////////////DESAPILAR/////////////////////////////////////////////////////
void sacarpila(struct concejales *tpp){
	struct concejales *cj=NULL,*c=NULL;
	cj=tpp;
	
	while(vacia2(cj)!=1){
		desapilarc(&c,&cj);
		printf("%s\n",c->nombre);
		free(c);
		
	}
	while(c!=NULL){
			printf("entreo while");
		printf("%s\n",c->nombre);
	
		c=c->siguiente;
	}
}
int vacia2( struct concejales *tp){
int  band=0;
	if (tp == NULL) {
		band=1;
}
		if (tp != NULL) {
		band=0;
}	
	printf("%d\n",band);
	return band;
	
}

void desapilarc(struct concejales **p1, struct concejales **tp1){
			printf("entor desapilar");
			*p1=*tp1;
			*tp1=(*tp1)->siguiente;
			(*p1)->siguiente =NULL;
			printf("salio desapilar");
			
			
}

