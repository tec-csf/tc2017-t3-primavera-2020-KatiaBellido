#include <iostream>
#include<time.h>
#include <list>

#define NFIL 5
#define NCOL 5
using namespace std;

char laberinto[NFIL][NCOL];

struct recorrido{
       int x;
       int y;
       struct recorrido *siguiente;
};

void printMaze()
{
    for (int i = 0; i < NFIL; i++)
    {
        for (int j = 0; j < NCOL; j++)
        {
            cout<<laberinto[i][j];
        }
        cout<<endl;
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
                                      if(j==NCOL-2) laberinto[i][j]='F'; //F es el final del laberinto
                                      }
                           break;
                      
                      
             }                  
    }//fin while
}

int main()
{
    srand (time(NULL));
    iniciarMapa();
    printMaze();
    int x=1+rand()%NFIL-2; 
    //x es el inicio, 1 es obligatorio para que encuentre un final
    generarCamino(x,1);
    printMaze();
    return 0;
}