#include <iostream>
#include <time.h> 
using namespace std;

//define el tamaño de nuestro tablero
#define N 3
int contador = 0;
int px= 0,py = 0;

//selecciona 
void seleccionCasilla(char tablerogato[N][N])
{
    int flag = 0;
    int cont=0;
    int x = 0;
    int y = 0;
    //checar en filas
    for (int i = 0; i < N; i++)
    {
        if (tablerogato[i][0]== tablerogato[i][1] && tablerogato[i][0]!=' ' && tablerogato[i][2]==' ')
        {
            px=i;
            py = 2;
            flag = 1;
            break;
        }
        else if (tablerogato[i][1]== tablerogato[i][2]&& tablerogato[i][1]!=' '&& tablerogato[i][0]==' ')
        {
            px=i;
            py = 0;
            flag = 1;
            break;
        }
        
        
    }
    //checar columnas
    for (int i = 0; i < N; i++)
    {
        if (tablerogato[0][i]== tablerogato[1][i] && flag == 0 && tablerogato[1][i]!=' ' && tablerogato[2][i]==' ')
        {
            px=2;
            py=i;
            flag =1;
            break;
        }
        else if (tablerogato[2][i]== tablerogato[1][i] && flag == 0 && tablerogato[1][i]!=' '&& tablerogato[0][i]==' ')
        {
            
            px=0;
            py=i;
            flag=1;
            break;
        }
    }
    //checar diagonales


    //necesita revision URGENTE
    if (flag ==0)
    {
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
            {
                if (tablerogato[i][j]!='O' && tablerogato[i][j]!='X'&& cont==0)
                {
                    px=i;
                    py=j;
                    cont=1;
                    break;
                }
                
            }
        }
    }
}

bool revisarJuego(char final[N][N])
{
    //revisa si esta en filas
    for (int i=0; i<N; i++) 
    { 

        if (final[i][0] == final[i][1] &&  final[i][1] == final[i][2] &&   final[i][0] != ' ') 
        {
            return (true); 
        }
    } 
    //revisa si esta en columnas
    for (int i=0; i<N; i++) 

    { 

        if (final[0][i] == final[1][i] && final[1][i] == final[2][i] &&   final[0][i] != ' ') 
        {
            return (true); 
        }
    } 
    //revisa si esta en cruzado
     if (final[0][0] == final[1][1] && final[1][1] == final[2][2] &&  final[0][0] != ' ') 
    {
        return(true); 
    }
    if (final[0][2] == final[1][1] && final[1][1] == final[2][0] && final[0][2] != ' ') 
    {
       return(true); 
    }

    return false;
}

void printGame(char gato[N][N], int conteo)
{
    cout<<"juego numero: "<< conteo<<endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout<<gato[i][j];
            
            if (j!=2)
            {
                cout<<"|";
            } 
        }
        cout<<endl;
        cout<<"------"<<endl;
    }
    
}
void setwinner(char winner)
{   
    if (winner==' ')
    {
        cout<< "Hay empate wuuu"<<endl;
    }
    else
        cout<< "El ganador es: "<< winner<<endl;
}
bool jugarGatohasta(char tab[N][N], int movimientos)
{
    int posicion = 0;
    //base
    if(movimientos<1 || revisarJuego(tab)==1)
    {   
        if (movimientos<1)
        {
            setwinner(' ');
        }
        return false;
    }
    
    if(movimientos%2 == 0 )
    {
        seleccionCasilla(tab);
        if (tab[px][py]!='X'&& tab[px][py]!='O')
        {
            tab[px][py]= 'O'; 
            printGame(tab,++contador);
            
        }

        if (revisarJuego(tab) == 1)
        {
            setwinner('O');
        }
        
    }
    else if (movimientos%2 != 0 )
    {
        seleccionCasilla(tab);
        if (movimientos == 9)
        {
            px=1;
            py=1;
        }
    
        if(tab[px][py]!='X'&& tab[px][py]!='O')
        {
        
            tab[px][py]= 'X'; 
            printGame(tab, ++contador);
            if (revisarJuego(tab) == 1)
            {
                setwinner('X');
            }
        }

    }
    
    else
    {
        printGame(tab, ++contador);
    }
    jugarGatohasta(tab, --movimientos);

    return true;
}

void playgato()
{
    char tablero[N][N]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    jugarGatohasta(tablero, 9);

}

int main ()
{
    char tablero[N][N] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    printGame(tablero, 0);
    cout<<"El tablero esta hecho para que inicie X en el centro"<<endl;
    playgato();
    return 0;
}