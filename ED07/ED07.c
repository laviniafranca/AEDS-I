#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

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


//Metodo 0711
void gravarMultiplos3Impares ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        int valor = 3;
        for ( int i = 0; i < n; i = i + 1 )
        {
            fprintf ( arquivo, "%d\n", valor );
            valor = valor + 6; // Proximo multiplo impar de 3
        }
        fclose ( arquivo );
    }
}

void method_0711 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores: " );

    gravarMultiplos3Impares ( "DADOS0711.TXT", n );
    printf ( "Gravados com sucesso em DADOS0711.TXT\n" );
    
// Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS0711.TXT", "rt" );
    int valor = 0;
    printf ( "Dados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%d", &valor ) == 1 )
        {
            printf ( "%d\n", valor );
        }
        fclose ( arquivo );
    }
    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0712

void gravarMultiplos4ParesDecrescente ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        int valor = 4 * n;
        for ( int i = 0; i < n; i = i + 1 )
        {
            fprintf ( arquivo, "%d\n", valor );
            valor = valor - 4;
        }
        fclose ( arquivo );
    }
}

void method_0712 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores: " );

    gravarMultiplos4ParesDecrescente ( "DADOS0712.TXT", n );
    printf ( "Gravados com sucesso em DADOS0712.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS0712.TXT", "rt" );
    int valor = 0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%d", &valor ) == 1 )
        {
            printf ( "%d\n", valor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0713

void gravarSequenciaPotencias4 ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        int valor = 1;
        for ( int i = 0; i < n; i = i + 1 )
        {
            fprintf ( arquivo, "%d\n", valor );
            valor = valor * 4;
        }
        fclose ( arquivo );
    }
}

void method_0713 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores: " );

    gravarSequenciaPotencias4 ( "DADOS0713.TXT", n );
    printf ( "Gravados com sucesso em DADOS0713.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS0713.TXT", "rt" );
    int valor = 0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%d", &valor ) == 1 )
        {
            printf ( "%d\n", valor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0714

void gravarSequenciaInversaPotencias4 ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        for ( int i = n - 1; i >= 0; i = i - 1 )
        {
            double denominador = pow ( 4.0, i );
            double valor = 1.0 / denominador;
            fprintf ( arquivo, "%lf\n", valor );
        }
        fclose ( arquivo );
    }
}

void method_0714 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores: " );

    gravarSequenciaInversaPotencias4 ( "DADOS0714.TXT", n );
    printf ( "Gravados com sucesso em DADOS0714.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS0714.TXT", "rt" );
    double valor = 0.0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%lf", &valor ) == 1 )
        {
            printf ( "%lf\n", valor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0715

void gravarSequenciaInversaX ( const char *fileName, int n, double x )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        for ( int i = 0; i < n; i = i + 1 )
        {
            double expoente = 2.0 * i;
            double valor = 1.0 / pow ( x, expoente );
            fprintf ( arquivo, "%lf\n", valor );
        }
        fclose ( arquivo );
    }
}

void method_0715 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores (n): " );
    double x = 0.0;
    printf ( "Entrar com o valor real de x: " );
    scanf ( "%lf", &x );
    getchar ( );

    gravarSequenciaInversaX ( "DADOS0715.TXT", n, x );
    printf ( "Gravados com sucesso em DADOS0715.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS0715.TXT", "rt" );
    double valor = 0.0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%lf", &valor ) == 1 )
        {
            printf ( "%lf\n", valor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0716

double somarValoresArquivo ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "rt" );
    double soma = 0.0;
    double valor = 0.0;

    if ( arquivo != NULL )
    {
        for ( int i = 0; i < n && !feof ( arquivo ); i = i + 1 )
        {
            if ( fscanf ( arquivo, "%lf", &valor ) == 1 )
            {
                soma = soma + valor;
            }
        }
        fclose ( arquivo );
    }
    return ( soma );
}

void method_0716 ( void )
{
    int n = readint ( "Entrar com a quantidade de valores a somar: " );

    double resultado = somarValoresArquivo ( "DADOS0715.TXT", n );

    FILE *saida = fopen ( "RESULTADO06.TXT", "wt" );
    if ( saida != NULL )
    {
        fprintf ( saida, "Quantidade: %d\n", n );
        fprintf ( saida, "Soma: %lf\n", resultado );
        fclose ( saida );
    }

    printf ( "Soma dos %d primeiros valores = %lf (gravado em RESULTADO06.TXT)\n", n, resultado );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "RESULTADO06.TXT", "rt" );
    char linha[STR_SIZE];
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fgets ( linha, STR_SIZE, arquivo ) != NULL )
        {
            printf ( "%s", linha );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0717

double somarInversosPotencias4 ( int n )
{
    double soma = 0.0;
    for ( int i = n - 1; i >= 0; i = i - 1 )
    {
        soma = soma + ( 1.0 / pow ( 4.0, i ) );
    }
    return ( soma );
}

void method_0717 ( void )
{
    int n = readint ( "Entrar com a quantidade de termos: " );

    double soma = somarInversosPotencias4 ( n );

    FILE *arquivo = fopen ( "RESULTADO07.TXT", "wt" );
    if ( arquivo != NULL )
    {
        fprintf ( arquivo, "Termos: %d\n", n );
        fprintf ( arquivo, "Soma: %lf\n", soma );
        fclose ( arquivo );
    }

    printf ( "Soma calculada = %lf (gravado em RESULTADO07.TXT)\n", soma );

    // Mostrar dados gravados
    FILE *arq = fopen ( "RESULTADO07.TXT", "rt" );
    char linha[STR_SIZE];
    printf ( "\nDados gravados:\n" );
    if ( arq != NULL )
    {
        while ( fgets ( linha, STR_SIZE, arq ) != NULL )
        {
            printf ( "%s", linha );
        }
        fclose ( arq );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0718

void gravarFibonacciPares ( const char *fileName, int n )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        int contPares = 0;
        int a = 1;
        int b = 1;
        int proximo = 0;

        while ( contPares < n )
        {
            proximo = a + b;
            a = b;
            b = proximo;

            if ( a % 2 == 0 )
            {
                fprintf ( arquivo, "%d\n", a );
                contPares = contPares + 1;
            }
        }
        fclose ( arquivo );
    }
}

void method_0718 ( void )
{
    int n = readint ( "Entrar com a quantidade de termos pares: " );

    gravarFibonacciPares ( "RESULTADO08.TXT", n );
    printf ( "Gravados com sucesso em RESULTADO08.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "RESULTADO08.TXT", "rt" );
    int valor = 0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%d", &valor ) == 1 )
        {
            printf ( "%d\n", valor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0719

int contarMinusculas ( const char *cadeia )
{
    int cont = 0;
    for ( int i = 0; cadeia[i] != '\0'; i = i + 1 )
    {
        if ( cadeia[i] >= 'a' && cadeia[i] <= 'z' )
        {
            cont = cont + 1;
        }
    }
    return ( cont );
}

void method_0719 ( void )
{
    char cadeia[STR_SIZE];
    printf ( "Entrar com uma cadeia de caracteres: " );
    fgets ( cadeia, STR_SIZE, stdin );
    cadeia[strcspn ( cadeia, "\r\n" )] = '\0';

    int resultado = contarMinusculas ( cadeia );

    FILE *arquivo = fopen ( "RESULTADO09.TXT", "wt" );
    if ( arquivo != NULL )
    {
        fprintf ( arquivo, "Cadeia: %s\n", cadeia );
        fprintf ( arquivo, "Quantidade de minusculas: %d\n", resultado );
        fclose ( arquivo );
    }

    printf ( "Total de minusculas = %d (gravado em RESULTADO09.TXT)\n", resultado );

    // Mostrar dados gravados
    FILE *arq = fopen ( "RESULTADO09.TXT", "rt" );
    char linha[STR_SIZE];
    printf ( "\nDados gravados:\n" );
    if ( arq != NULL )
    {
        while ( fgets ( linha, STR_SIZE, arq ) != NULL )
        {
            printf ( "%s", linha );
        }
        fclose ( arq );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 0720

int contarDigitosMenoresOuIguais6 ( const char *cadeia )
{
    int cont = 0;
    for ( int i = 0; cadeia[i] != '\0'; i = i + 1 )
    {
        if ( cadeia[i] >= '0' && cadeia[i] <= '6' )
        {
            cont = cont + 1;
        }
    }
    return ( cont );
}

void method_0720 ( void )
{
    char cadeia[STR_SIZE];
    printf ( "Entrar com uma cadeia de caracteres: " );
    fgets ( cadeia, STR_SIZE, stdin );
    cadeia[strcspn ( cadeia, "\r\n" )] = '\0';

    int resultado = contarDigitosMenoresOuIguais6 ( cadeia );

    FILE *arquivo = fopen ( "RESULTADO10.TXT", "wt" );
    if ( arquivo != NULL )
    {
        fprintf ( arquivo, "Cadeia: %s\n", cadeia );
        fprintf ( arquivo, "Digitos <= 6: %d\n", resultado );
        fclose ( arquivo );
    }

    printf ( "Total de digitos <= 6 = %d (gravado em RESULTADO10.TXT)\n", resultado );

    // Mostrar dados gravados
    FILE *arq = fopen ( "RESULTADO10.TXT", "rt" );
    char linha[STR_SIZE];
    printf ( "\nDados gravados:\n" );
    if ( arq != NULL )
    {
        while ( fgets ( linha, STR_SIZE, arq ) != NULL )
        {
            printf ( "%s", linha );
        }
        fclose ( arq );
    }

    pause ( "Aperte ENTER para continuar." );
}

//Metodo 07E1

void gravarDivisoresImparesDecrescente ( const char *fileName, int valor )
{
    FILE *arquivo = fopen ( fileName, "wt" );
    if ( arquivo != NULL )
    {
        for ( int divisor = valor; divisor >= 1; divisor = divisor - 1 )
        {
            if ( valor % divisor == 0 && divisor % 2 != 0 )
            {
                fprintf ( arquivo, "%d\n", divisor );
            }
        }
        fclose ( arquivo );
    }
}

void method_07E1 ( void )
{
    int valor = readint ( "Entrar com um valor inteiro: " );

    gravarDivisoresImparesDecrescente ( "DADOS07E1.TXT", valor );
    printf ( "Divisores impares gravados em DADOS07E1.TXT\n" );

    // Mostrar dados gravados
    FILE *arquivo = fopen ( "DADOS07E1.TXT", "rt" );
    int divisor = 0;
    printf ( "\nDados gravados:\n" );
    if ( arquivo != NULL )
    {
        while ( fscanf ( arquivo, "%d", &divisor ) == 1 )
        {
            printf ( "%d\n", divisor );
        }
        fclose ( arquivo );
    }

    pause ( "Aperte ENTER para continuar." );
}


int main ( void ) {
    int opcao = 0;
    printf ( "%s\n", "935146 - AED1" );
    printf ( "\n" );
    do {
        opcao = readint ( "Qual a opcao? " );
        printf ( "%s%d\n", "opcao=", opcao );
        switch ( opcao ) {
            case 0:
            printf ( "\nPrograma finalizado.\n" ); break;
            case 1:  method_0711 ( ); break;
            case 2:  method_0712 ( ); break;
            case 3:  method_0713 ( ); break;
            case 4:  method_0714 ( ); break;
            case 5:  method_0715 ( ); break;
            case 6:  method_0716 ( ); break;
            case 7:  method_0717 ( ); break;
            case 8:  method_0718 ( ); break;
            case 9:  method_0719 ( ); break;
            case 10: method_0720 ( ); break;
            case 11: method_07E1 ( ); break;
            default:
            printf ( "\nOpcao invalida!\n" );
            pause ( "Aperte ENTER para continuar." );
            break;
        }
    }
    while ( opcao != 0 );

    return ( 0 );
}
