/* Autora: Lavinia Franca da Silva*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void metodo_0111 ( void )
{
    //Definir dados
    int quadrado;
    int area;

    //Ler o valor do teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &quadrado);
    getchar( );

    //Calcular a area
    quadrado/=2;
    area=quadrado*quadrado;
    
    //Mostrar os resultados
    printf("A area do novo quadrado e igual a %d", area);

    //Encerrar
    printf ( "\n\nApertar ENTER para terminar.\n" );
    getchar( );

    return (0);
}

void metodo_0112 ( void )
{
    //Definir dados
    int lado_original;
    int novo_lado.
    int area;
    int perimetro;

    
    //Ler o valor do teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &lado_original);
    getchar( );

    //Calcular
    novo_lado = lado_original*4;
    area=novo_lado*novo_lado;
    perimetro=4*novo_lado;

    //Resultados
    printf("Novo lado: %d\n", novo_lado);
    printf("Area: %d\n", area);
    printf("Perimetro: %d\n", perimetro);

    //Encerrar
    printf ( "\n\nApertar ENTER para terminar.\n" );
    getchar( );

    return (0);
}

void metodo_0113 ( void )
{
    //Definir dados
    int altura;
    int largura;
    int area;

    //Ler os valores do teclado
    printf("Entrar com um valor inteiro para altura:");
    scanf("%d", &altura);
    getchar( );

    printf("Entrar com um valor inteiro para largura:");
    scanf("%d",&largura);
    getchar( );

    //Calcular a area
    area=(altura+1)*(largura+2);

    //Resultados
    printf("Area do retangulo com uma unidade a mais na altura e duas a mais na largura: %d\n", area);

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );
    
    return (0);
}

void metodo_0114 ( void )
{
    //Definir dados
    int area;
    int perimetro;
    int altura;
    int largura;

    //Ler os valores do teclado
    printf("Entrar com um valor inteiro para altura:");
    scanf("%d", &altura);
    getchar( );

    printf("Entrar com um valor inteiro para largura:");
    scanf("%d", &largura);
    getchar( );

    //Calcular
    area=(altura*largura)/5;
    perimetro=(altura*2+largura*2)/5;

    //Resultados
    printf("A area e: %d\n", area);
    printf("O perimetro e: %d\n", perimetro);

    //Encerrar:
    printf ( "\n\nApertar ENTER para terminar." );
    getchar( );
    
    return ( 0 );
}

void metodo_0115 ( void )
{
    //Definir dados
    int base;
    int altura;
    int area;

    //Ler os valores do teclado
    printf("Entrar com um valor inteiro para base:");
    scanf("%d", &base);
    getchar( );

    printf("Entrar com um valor inteiro para altura:");
    scanf("%d", &altura);
    getchar( );

    //Calcular a area
    area=(base*altura/2)/3;

    //Resultados
    printf("A area e: %d\n", area);

    //Encerrar
    printf("\n\nApertar ENTER para terminar");
    getchar( );

    return(0);
}
double potencia(double x)
{
    return(x*x);
}

void metodo_0116 ( void )
{
    //Definir dados
    double altura;
    double area;
    double perimetro;
    double lado;

    //Ler o valor do teclado
    printf("Entrar com um valor real para o lado do triangulo equilatero:");
    scanf("%lf", &lado);
    getchar( );
    lado=3*lado/4;

    //Calcular a altura, area e perimetro
    altura=(lado)*sqrt(3)/2;
    area=potencia(lado)*sqrt(3)/4;
    perimetro=3*lado;

    //Resultados
    printf("A altura e: %lf\n", altura);
    printf("A area e: %lf\n", area);
    printf("O perimetro e: %lf\n", perimetro);

    //Encerrar
    printf("\n\nApertar ENTER apra terminar.");
    getchar ( );

    return(0);
}

double potencia(double x)
{
    return(x*x*x);
}

void metodo_0117 ( void )
{
    //Definir dados
    double lado;
    double volume;

    //Ler o valor do teclado
    printf("Entrar com um valor real para os lados do cubo:");
    scanf("%lf", &lado);
    getchar( );
    lado=5*lado;

    //Calcular o volume
    volume=potencia(lado);

    //Resultados
    printf("O volume do cubo e: %lf\n", volume);

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );

    return(0);
}

void metodo_0118 ( void )
{
    //Definir dados
    double comprimento;
    double largura;
    double altura;
    double volume;

    //Ler os valores do teclado
    printf("Entrar com um valor real para comprimento:");
    scanf("%lf", &comprimento);
    getchar ( );
    comprimento=comprimento/6;

    printf("Entrar com um valor real para largura:");
    scanf("%lf", &largura);
    getchar ( );
    largura=largura/6;

    printf("Entrar com um valor real para altura:");
    scanf("%lf", &altura);
    getchar ( );
    altura=altura/6;

    //Calcular o volume
    volume=comprimento*largura*altura;

    //Resultados
    printf("O volume do paralelepipedo e: %lf\n", volume);

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );

    return(0);  
}

void metodo_0119 ( void )
{
    //Definir dados
    double raio;
    double area;

    //Ler valor do teclado
    printf("Entrar com um valor real para raio:");
    scanf("%lf", &raio);
    getchar ( );
    raio=3*raio;

    //Calcular a area
    area=(M_PI)*potencia(raio)/2;

    //Resultados
    printf("A area do semicirulo e: %lf\n", area);

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );

    return(0);
}

void metodo_0120 ( void )
{
    //Definir dados
    double raio;
    double volume;

    //Ler o valor do teclado
    printf("Entrar com um valor real para o raio da esfera:");
    scanf("%lf", &raio);
    getchar ( );
    raio=4*raio/7;

    //Calcular o volume
    volume=4*(M_PI)*potencia(raio)/3;

    //Resultados
    printf("O volume da esfera e: %lf\n", volume);

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );

    return(0);
}

int main(void) {
    int opcao = 0;
   printf ( "%s\n", "935146 - AED1" );
   printf ( "\n" );
   do
   {
       printf ( "%s", "Qual a opcao? " );
       scanf ( "%d", &opcao ); getchar ( );
       printf ( "%s%d\n", "opcao=", opcao );
       switch ( opcao )
       {
          case 0:
           break;
          case 1: 
          metodo_0111 ( );
           break;
           case 2:
           metodo_1212 ( );
           case 3:
           metodo_0113 ( );
           break;
           case 4:
           metodo_0114 ( );
           break;
           case 5:
           metodo_0115 ( );
           break;
           case 6:
           metodo_0116 ( );
           break;
           case 7:
           metodo_0117 ( );
           break;
           case 8:
           metodo_0118 ( );
           break;
           case 9:
           metodo_0119 ( );
           break;
           case 10:
           metodo_0120 ( );
           break;

           default:
           printf ( "%s\n", "ERRO: Opcao invalida." );
           break;
        }
    }
    while ( opcao != 0 );
    printf ( "%s\n", "Fim do programa" );
    printf ( "\n" );
    return (0);

    return 0;
}
