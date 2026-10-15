/* Autora: Lavinia Franca da Silva */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_PALAVRAS 20
#define MAX_TAM 100

int readint (const char *text)
{
   //definir dado local
   int x = 0;
   //mostrar a mensagem
   printf ( "%s", text );
   //ler o valor do teclado e limpar a entrada
   scanf ( "%d", &x ); getchar ( );
   return ( x );
}

double readdouble (const char *text)
{
   //definir dado local
   double x = 0.0;
   //mostrar a mensagem
   printf ( "%s", text );
   //ler o valor do teclado e limpar a entrada
   scanf ( "%lf", &x ); getchar ( );
   return ( x );
}

char readchar (const char *text)
{
   //definir dado local
   char x = 0;
   //mostrar a mensagem
   printf ( "%s", text );
   //ler o valor do teclado e limpar a entrada
   scanf ( "%c", &x ); getchar ( );
   return ( x );
}

bool readbool (const char *text)
{
   //definir dado local
   int x = 0;
   //mostrar a mensagem
   printf ( "%s", text );
   //ler o valor do teclado e limpar a entrada
   scanf ( "%d", &x ); getchar ( );
   //finalizar
   return ( x != 0 );
}

char* boolalpha ( bool x )
{
   if ( x )
      return "true";
   else 
      return "false";
}
