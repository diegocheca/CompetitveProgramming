#include <cstdlib>
#include <iostream>
#include <stdio.h>


using namespace std;

void mostrar(int tabla [101][101],int f, int c)
{
    for(int i=0; i<=f;i++)
    {
        printf("\n");
        for(int j=0; j<=c;j++)
            printf("%d", tabla[i][j]);    
    }
}
void sumar(int tabla [101][101],int f, int c)
{
    if(tabla [f-1][c-1]!=9)
       tabla[f-1][c-1]++;
    if(tabla [f-1][c] !=9)
        tabla [f-1][c]++;    
    if(tabla [f-1][c+1] !=9)
        tabla[f-1][c+1]++;
    if(tabla [f][c-1]!=9)
        tabla [f][c-1]++;
    if(tabla [f][c+1]!=9)
        tabla [f][c+1]++;
    if(tabla [f+1][c-1]!=9)
        tabla [f+1][c-1]++;
    if(tabla [f+1][c]!=9)
        tabla [f+1][c]++;
    if(tabla [f+1][c+1]!=9)
        tabla [f+1][c+1]++;
}


int tabla [101] [101];
int main(int argc, char *argv[])
{
    int f,c,l;
    scanf("%d %d",&f,&c);
    char aux;
    fflush(stdin);
    for(int i=1; i<=f;i++)
        for(int j=1; j<=c;j++)
        {
           scanf ("%c", &aux);
           if(aux == '\n')
                j--;
           //if((i==3)&&(j==3))
           if(aux == '*') //sumar unos
           {
              tabla[i][j]=9;
              sumar(tabla,i,j);
//              mostrar(tabla,f,c);
           }
         }           
    //mostrar
    // mostrar(tabla,f,c);
    for(int i=1; i<=f;i++)
        for(int j=1; j<=c;j++)
        {
            if(tabla [i][j]!=9)
            {
                printf("%d",tabla[i][j]);
            }
            else printf("*");
            if(j==c)
            printf("\n");
            
        }
        l++;
}
