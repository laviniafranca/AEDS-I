/* Autora: Lavinia Franca da Silva

#include <stdio.h>

void metodo_0211 ( void )
{
    //Definir dados
    int valor;

    //Ler valor no teclado
    scanf("%d", &valor);
    printf("Entrar com um valor inteiro:");

    //Definir condicoes e resultados
    if(valor%2 == 0 && valor>=0){
        printf("O valor %d e par e positivo", valor);
        getchar( );
    
    } else if(valor%2 != 0 && valor<0){
        printf("O valor %d e impar e negativo", valor);
        getchar( );
    }
     else {
        printf("O valor %d nao se aplica as condicoes", valor);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );
    
    return(0);
}

void metodo_0212 ( void )
{
    //Definir dados
    int valor;

    //Ler valor no teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &valor);

    //Definir condicoes e resultado
    if(valor%2 == 0 && valor<24){
        printf("o valor %d e par e menor que 24", valor);
        getchar( );
    
    } else if (valor%2 != 0 && valor>-15){
        printf("o valor %d e impar e maior que -15", valor);
        getchar( );
    }

     else {
        printf("o valor %d nao se aplica as condicoes", valor);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );

    return(0);
}

void metodo_0213 ( void )
{
    //Definir dados
    int valor;

    //Ler valor no teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &valor);

    //Definir condicoes e resultado
    if(valor>12 && valor<45){
        printf("valor %d se encaixa ao intervalo aberto entre (12:45)", valor);
        getchar( );
    
    } else if(valor<12 && valor>45){
        printf("valor %d nao se encaixa ao intervalo aberto entre (12:45)", valor);
        getchar( );
    }
     else {
        printf("o valor %d nao se aplica as condicoes", valor);
        getchar( );
    }
    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );

    return(0);
}

void metodo_0214 ( void )
{
    //Definir dados
    int valor;

    //Ler valor no teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &valor);

    //Definir condicoes e resultado
    if(valor>=12 && valor<=45){
        printf("valor %d se encaixa ao intervalo fechado entre [12:45]", valor);
        getchar( );

    } 
    else {
        (valor<12 && valor>45);
        printf("valor %d nao se encaixa ao intervalo fechado entre [12:45]", valor);
        getchar ( );
    }
    
    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );

    return(0);
}

void metodo_0215 ( void )
{
    //Definir dados
    int valor;

    //Ler valor no teclado
    printf("Entrar com um valor inteiro:");
    scanf("%d", &valor);

    //Definir condicoes e resultado
    if(valor>18 && valor<=25){
    printf("valor %d esta na interseccao de [11:25] e (18:48)", valor);
    getchar( );
    }

    else if (valor>=11 && valor<=25){
        printf("valor %d se encaixa ao intervalo fechado entre [11:25]", valor);
        getchar( );
    } 
    
    else {
        (valor<18 && valor>48);
        printf("valor %d se encaixa ao intervalo aberto entre (18:48)", valor);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar( );

    return(0);
}

void metodo_0216 ( void )
{
    //Definir dados
    int valor;
    int valor_dois;

    //Ler os valores no teclado
    printf("Entrar com dois valores inteiros:");
    scanf("%d", &valor);
    scanf("%d", &valor_dois);

    //Definir condicoes e resultados
    if(valor%2 == 0 && valor_dois%2 !=0){
        printf("\nO valor %d e par e o valor %d e impar", valor, valor_dois);
        getchar( );
     } 
     else if(valor%2 != 0 && valor_dois%2 ==0){
        printf("\nO valor %d nao e par e o valor %d nao e impar", valor, valor_dois);
        getchar( );
    }

    else if(valor&2 != 0 && valor_dois%2 !=0){
        printf("\nOs dois valores sao impares", valor, valor_dois);
        getchar( );
    }
    else if(valor%2 == 0 && valor_dois%2 == 0){
        printf("\nOs dois valores sao pares", valor, valor_dois);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );
    
    return(0);
}

void metodo_0217 ( void )
{
    //Definir dados
    int valor;
    int valor_dois;

    //Ler os valores no teclado
    printf("Entrar com dois valores inteiros:");
    scanf("%d", &valor);
    scanf("%d", &valor_dois);

    //Definir condicoes e resultados
    if(valor%2 == 0 && valor>=0 && valor_dois%2 !=0 && valor_dois<0){
        printf("\nO valor %d e par e positivo e o valor %d e impar e negativo", valor, valor_dois);
        getchar( );
     } 
        
     else if(valor%2 !=0 && valor>=0 && valor_dois%2 == 0 && valor_dois<0){
        printf("\nO valor %d nao e par, mas e positivo e o valor %d nao e impar, mas e negativo", valor, valor_dois);
        getchar( );
    }

        else if(valor%2 == 0 && valor<0 && valor_dois%2 !=0 && valor_dois>=0){
        printf("\nO valor %d e par, mas nao e positivo e o valor %d e impar, mas nao e negativo", valor, valor_dois);
        getchar( );
    }

     else if(valor%2 !=0 && valor<0 && valor_dois%2 ==0 && valor_dois>=0){
        printf("\nO valor %d nao e par e nem positivo e o valor %d nao e impar e nem negativo", valor, valor_dois);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );
    
    return(0);
}

void metodo_0218 ( void )
{
    //Definir dados
    double valor;
    double valor_dois;

    //Ler os valores no teclado
    printf("Entrar com dois valores reais:");
    scanf("%lf", &valor);
    scanf("%lf", &valor_dois);

    //Definir condicoes e resultados
    if(valor<2*valor_dois/3){
        printf("\nO valor %lf e menor que dois tercos do valor %lf", valor, valor_dois);
        getchar( );
     } 
        
     else if(valor==2*valor_dois/3){
        printf("\nO valor %lf e igual a dois tercos do valor %lf", valor, valor_dois);
        getchar( );
    }

     else if(valor>2*valor_dois/3){
        printf("\nO valor %lf e maior que dois tercos do valor %lf", valor, valor_dois);
        getchar( );
    }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );
    
    return(0);
}

void metodo_0219 ( void )
{
    //Definir dados
    double valor;
    double valor_dois;
    double valor_tres;

    //Ler os valores no teclado
    printf("Entrar com tres valores reais:");
    scanf("%lf", &valor);
    scanf("%lf", &valor_dois);
    scanf("%lf", &valor_tres);

    //Definir condicoes e resultados
    if(valor==valor_tres){
        printf("\nO primeiro %lf e o ultimo valor %lf sao iguais", valor, valor_tres);
        getchar( );
     } 
     else if((valor<valor_dois && valor_dois<valor_tres)||
            (valor_tres<valor_dois && valor_dois<valor))
     {
        printf("\nO segundo valor %lf esta entre o primeiro %lf e o ultimo %lf", valor_dois, valor, valor_tres);
        getchar( );
     }

     else{
        printf("\nO segundo valor %lf nao esta entre o primeiro %lf e o ultimo %lf", valor_dois, valor, valor_tres);
        getchar( );
     }

    //Encerrar
    printf("\n\nApertar ENTER para terminar.");
    getchar ( );
    
    return(0);
}

void metodo_0220 ( void )
{
    //Definir dados
    double valor;
    double valor_dois;
    double valor_tres;

    //Ler os valores no teclado
    printf("Entrar com tres valores reais:");
    scanf("%lf", &valor);
    scanf("%lf", &valor_dois);
    scanf("%lf", &valor_tres);

    //Definir condicoes e resultados
    if(valor==valor_dois || valor==valor_tres || valor_dois==valor_tres){
        printf("\nO primeiro %lf, segundo %lf e o ultimo valor %lf sao iguais", valor, valor_dois, valor_tres);
        getchar( );
     } 
     else if((valor<valor_dois && valor_dois<valor_tres)||
            (valor_tres<valor_dois && valor_dois<valor))
     {
        printf("\nO segundo valor %lf esta entre o primeiro %lf e o ultimo %lf", valor_dois, valor, valor_tres);
        getchar( );
     }

     else{
        printf("\nO segundo valor %lf nao esta entre o primeiro %lf e o ultimo %lf", valor_dois, valor, valor_tres);
        getchar( );
     }

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
          metodo_0211 ( );
           break;
           case 2:
           metodo_0212 ( );
           case 3:
           metodo_0213 ( );
           break;
           case 4:
           metodo_0214 ( );
           break;
           case 5:
           metodo_0215 ( );
           break;
           case 6:
           metodo_0216 ( );
           break;
           case 7:
           metodo_0217 ( );
           break;
           case 8:
           metodo_0218 ( );
           break;
           case 9:
           metodo_0219 ( );
           break;
           case 10:
           metodo_0220 ( );
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
