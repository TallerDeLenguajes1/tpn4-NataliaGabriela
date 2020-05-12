#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 100

typedef struct  {
int TareaID; //Numerado en ciclo iterativo
char *Descripcion; //
int Duracion; // entre 10 – 100
} Tarea;

Tarea **cargartareas(int cant_tareas,Tarea **p);
void mostrartareas(Tarea **p,int cant_tareas);

int main(void){
setvbuf(stdout,NULL,_IONBF,0);
srand(time(NULL));
    Tarea **p_tareas;
    int cant_tareas;
   
    printf("Ingrese la cantidad de tareas a  realizar\n");
    scanf("%d",&cant_tareas);
    p_tareas=(Tarea**)malloc(cant_tareas * sizeof(Tarea*));
    
    p_tareas=cargartareas(cant_tareas,p_tareas);
    mostrartareas(p_tareas,cant_tareas);
    scanf("%c");
    return 0;
}

Tarea **cargartareas(int cant_tareas,Tarea **p)
{
    
    int i,tam_des;
    char descripcion[MAX];
    
        for ( i = 0; i < cant_tareas; i++)
        {
            p[i]=(Tarea*)malloc(sizeof(Tarea));
            p[i]->TareaID=i;
            p[i]->Duracion=rand()%100+10;
            printf("Ingrese la descripcion de la tarea\n");
            scanf("%s",&descripcion);
            tam_des=strlen(descripcion);
            p[i]->Descripcion=(char*)malloc(tam_des);
            p[i]->Descripcion=strcpy(p[i]->Descripcion,descripcion);
        }
        
    return p;
}
void mostrartareas(Tarea **p,int cant_tareas)
{
    int i,j,h,resp,aux=0;
    Tarea **t_realizadas;
    t_realizadas=(Tarea**)malloc(cant_tareas * sizeof(Tarea*));
    printf("\nMostrando las tareas\n\n");
    for ( i = 0; i < cant_tareas; i++)
    {
        
        printf("Tarea numero: %d\n", p[i]->TareaID);
        printf("Descripcion: %s\n",p[i]->Descripcion);
        printf("Duracion: %d\n\n",p[i]->Duracion);
        printf("Realizo esta tarea? responda con 1 para si o 0 para no\n");
        scanf("%d",&resp);
             
        if (resp==1)
        {
            t_realizadas [aux] = (Tarea *) malloc ( sizeof(Tarea));
            t_realizadas[aux]=p[i];
            p[i]=NULL;
            aux++;

        }
        
    }
    printf("\nTareas Realizadas\n\n");
    for ( h = 0; h < aux; h++)
    {
        printf("Tarea numero: %d\n", t_realizadas[h]->TareaID);
        printf("Descripcion: %s\n",t_realizadas[h]->Descripcion);
        printf("Duracion: %d\n\n",t_realizadas[h]->Duracion);
          
    }
    printf("------------------------------------------------------\n");
    printf("\nTareas Pendientes\n\n");
    for ( j = 0; j < cant_tareas; j++)
    {
        if (p[j]!=NULL)
        {
            printf("Tarea numero: %d\n", p[j]->TareaID);
            printf("Descripcion: %s\n",p[j]->Descripcion);
            printf("Duracion: %d\n\n",p[j]->Duracion);
            
        }
    }
    printf("-------------------------------------------------------\n");
    
}    

