/* Autora: Lavinia Franca da Silva*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define STR_SIZE 80

void pause ( const char *mensagem )
{
    printf ( "\n%s\n", mensagem );
    getchar ( );
}

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

char* readstring ( const char *text, char *x, int tamanho )
{
   // mostrar a mensagem
   printf ( "%s", text );

   // ler o valor do teclado
   fgets ( x, tamanho, stdin );

   // remover o '\n' do final se presente
   x[strcspn(x, "\n")] = '\0';

   // retornar resultado
   return ( x );
}

char* boolalpha ( bool x )
{
   if ( x )
      return "true";
   else 
      return "false";
}
