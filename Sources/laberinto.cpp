#include <iostream>
#include<time.h>
#include <list>

#define NFIL 5
#define NCOL 5
using namespace std;
char laberinto[NFIL][NCOL];
int contador = 0;

struct recorrido{
       int x;
       int y;
       struct recorrido *siguiente;
};
typedef struct recorrido *Lista;
Lista reco = NULL;
void printMaze()
{
    if (contador==0)
    {
        cout<<"\nMapa del Laberinto: "<<contador<<"\n"<<endl;
    }
    else
    {     
        cout<<"\nPaso número: "<<contador<<"\n"<<endl;
    }
    for (int i = 0; i < NFIL; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            cout<<laberinto[i][j];
        }
        cout<<endl;
    }
}
void generarCamino(int i, int j)
{
    if(i<0)
    {
        i= -i;
    }
    laberinto[i][j]='E';
     while(j!=NCOL-2)
     {
             int a=rand()%3;
             switch(a)
             {
                      case 0:
                           if(i+1!=NFIL-1 && laberinto[i+1][j]!='O' && laberinto[i][j]!='E')
                           {
                                      i++;
                                      laberinto[i][j]='O';
                                      }
                           break;
                      case 1:
                           if(i-1!=0 && laberinto[i-1][j]!='O'&& laberinto[i][j]!='E')
                           {
                                     i--;
                                     laberinto[i][j]='O';
                                      }
                           break;
                      case 2:
                           if(j+1!=NCOL-1 && laberinto[i][j+1]!='O')
                           {
                                      j++;
                                      laberinto[i][j]='O';
                                      if(j==NCOL-2 || (j==NCOL-2 && i==0)) 
                                      {
                                      laberinto[i][j]='F'; //F es el final del laberinto
                                      }
                           }
                           break;
                      
                      
             }                  
    }//fin while
}
void generarPared()
{
    int paredes=0;
     while(paredes<(NFIL+NCOL)/3)
     {
        int x=rand()%NFIL;
        int y=rand()%NCOL;
        for (int i = 0; i < NFIL; i++)
        {
            for (int j = 0; j < NCOL; j++)
            {  
                if(laberinto[x][y]==' ')
                {
                    paredes++;
                    int lim=1+rand()%10;
                    int puestas=0;          
                    switch(rand()%4)
                    {
                        case 0:
                                                                    
                            while(laberinto[x][y]==' ')//para arriba
                            {
                                if(puestas==lim)break;
                                puestas++;
                                laberinto[x][y]='P';
                                x--;        
                                }
                                break;
                        case 1:
                            while(laberinto[x][y]==' ')//para abajo
                            {
                                if(puestas==lim)break;
                                puestas++;
                                laberinto[x][y]='P';
                                x++;      
                            }
                                break;
                        case 2:
                            while(laberinto[x][y]==' ')//para atras
                            {
                                if(puestas==lim)break;
                                puestas++;
                                laberinto[x][y]='P';
                                y--;        
                            }
                            break;
                        case 3:
                            while(laberinto[x][y]==' ')//para adelante
                            {
                                if(puestas==lim)break;
                                puestas++;
                                laberinto[x][y]='P';
                                y++;      
                            }
                            break;
                    }
                }
            }
        }   
    }
}
void FinGenerar()
{
     for(int i=0; i<NFIL; i++)
     {
        for(int j=0; j<NCOL-1; j++)
        {
            if(laberinto[i][j]=='O') laberinto[i][j]=' ';
            //if(j==NCOL-2 && laberinto[i][j]=='0') laberinto[i][j]='P';
            if(laberinto[i][j]=='F')
            {
                laberinto[i][j+1]='F';
                laberinto[i][j]=' ';
            }
            if(laberinto[i][j]=='E')
            {
            laberinto[i][j-1]='E';
            laberinto[i][j]=' ';
            }
        }
    }
}

void InsertReco(int x, int y)
{
     Lista q=new (struct recorrido);
     q->x=x;
     q->y=y;
     q->siguiente=reco;
     reco=q;
     }

bool Verificar(int x, int y)
{
     Lista q=reco;
     while(q!=NULL)
     {
                   if(q->x==x && q->y==y) return false;
                   q=q->siguiente;
                   }
                   return true;
     }

int goAheadInTheMaze(int i, int j)
{
    if(i<0)
    {
        i= -i;
    }
    int re=0;
    if(laberinto[i][j+1]=='F')
    {
        laberinto[i][j]= '*';
        contador++;
        printMaze();
        return 1;
    }
    laberinto[i][j]='*';
    contador++;
    printMaze();
    if(laberinto[i][j+1]==' ' && re==0 && Verificar(i,j+1))
    {
        re=goAheadInTheMaze(i,j+1);//hacia adelante    
    }
    if(laberinto[i-1][j]==' ' && re==0 && Verificar(i-1,j))
    { 
        re=goAheadInTheMaze(i-1,j);//hacia arriba
    }
    if(laberinto[i+1][j]==' ' && re==0 && Verificar(i+1,j)) 
    {
        re=goAheadInTheMaze(i+1,j);//hacia abajo
    }
    //if(laberinto[i][j-1]==' ' && re==0 && Verificar(i,j-1)) re= goAheadInTheMaze(i,j-1);//hacia atras
    if(re==1) return 1;
    else
    {
        InsertReco(i,j);
        laberinto[i][j]=' ';
        }
    return 0;
}

void findPath(int x)
{
    if (goAheadInTheMaze(x,1)==0)
    {
        cout<<"Sin solucion"<<endl;
    }
     else 
    {
     cout<<"Solucion encontrada!!"<<endl;
    }
}
void iniciarMapa()
{
    for (int i = 0; i < NFIL; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            if(i==0 || j==0 || i==NFIL-1 || j==NCOL-1){
                laberinto[i][j]='1';
            }
            else 
            {
                laberinto[i][j]=' ';
            }
        }
    }
    srand (time(NULL));
    int x=1+rand()%NFIL-2; 
    generarCamino(x,1);
    generarPared();
    FinGenerar();
    printMaze();
    findPath(x);
}
int main()
{
    cout<<"LABERINTO CON BACKTRACKING"<<endl;
    cout<<"El camino esta marcado con *\n Las Paredes dentro del laberinto estan"<<endl;
    iniciarMapa();
    return 0;
}