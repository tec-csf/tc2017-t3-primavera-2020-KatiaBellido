#include <iostream>
#include <time.h> 
using namespace std;

//board size since it's always the same :D
#define N 3
int contador = 0;
int px= 0,py = 0;

/*
* seleccionCasilla finds where to place the players move
* @param char matrix that is read  
* @return void
*/ 
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
        int cat= 0;
        if (tablerogato[cat][i]== tablerogato[cat+1][i] && flag == 0 && tablerogato[cat+1][i]!=' ' && tablerogato[cat+2][i]==' ')
        {
            px=2;
            py=i;
            flag =1;
            break;
        }
        else if (tablerogato[cat+2][i]== tablerogato[cat+1][i] && flag == 0 && tablerogato[cat+1][i]!=' '&& tablerogato[cat][i]==' ')
        {
            
            px=0;
            py=i;
            flag=1;
            break;
        }
    }
    //checar diagonales casi no tendría oportunidades de ganar

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
/*
* revisarJuego checks if a possible winning is set
* @param char matrix that is read 
* @return bool that returns if its a winning move 
*/
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
/*
* printGame prints how the game is going per steps
* @param char matrix that prints and int variable to keep track of steps
* @return void 
*/
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
/*
* setwinner set who player won the game and print it 
* @param char variable that declares the winner of the game
* @return void 
*/
void setwinner(char winner)
{   
    if (winner==' ')
    {
        cout<< "Hay empate wuuu"<<endl;
    }
    else
        cout<< "El ganador es: "<< winner<<endl;
}
/*
* jugarGatohasta set the two players pieces when its their turn, also 
calls seleccion casilla to find the best option to set the pieces
* @param char matrix and int variable that are read and modified
* @return bool to end the game or continue
*/
bool jugarGatohasta(char tab[N][N], int movimientos)
{
    int i = movimientos;
    while (i>=0|| revisarJuego(tab)==1 )
    {
        i--;
        int posicion = 0;
        //base stops the game :D
        if(movimientos<1 || revisarJuego(tab)==1)
        {   
            if (contador==9) //if it is less than 1 it means it's a tie
            {
                setwinner(' ');
            }
            
            return false;
        }
        
        if(movimientos%2 == 0 ) //the second player movement decision
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
        else if (movimientos%2 != 0 ) //the first player movement decision
        {
            seleccionCasilla(tab);
            if (movimientos == 9)
            {
                //first move selection <3;
                srand (time(NULL));
                px=rand()%3;
                py=rand()%3;
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
        
        else //if it breaks
        {
            printGame(tab, ++contador);
        }
        
        --movimientos;
    }
    return true;
}

/*
* Playgato starts the board and calls the function jugarGatohasta
* @param none
* @return void
*/
void playgato()
{
    char tablero[N][N]={{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    jugarGatohasta(tablero, 9);

}

int main ()
{
    char tablero[N][N] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    printGame(tablero, 0);
    cout<<"LET'S PLAY!"<<endl;
    playgato();
    return 0;
}