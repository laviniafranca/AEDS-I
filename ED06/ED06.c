#include "io.h"


// procedimento recursivo para mostrar multiplos de 4 crescentes.
void method_0611a ( int x )
{
    if ( x > 0 )
    {
        method_0611a ( x - 1 ); 
        printf ( "%d ", x * 4 );
    } 
} 

// Method_0611
void method_0611 ( void )
{
    // definir dado
    int quantidade = 0;

    // ler dado do teclado
    quantidade = readint ( "Entrar com a quantidade: " );

    // executar o metodo auxiliar
    printf ( "Resultado: { " );
    method_0611a ( quantidade );
    printf ( "}\n" );
} 

// procedimento recursivo para mostrar multiplos de 3 decrescentes.
void method_0612a ( int x )
{
    if ( x > 0 )
    {
        printf ( "%d ", x * 3 );
        method_0612a ( x - 1 ); 
    } 
} 

// Method_0612
void method_0612 ( void )
{
    int quantidade = 0;

    quantidade = readint ( "Entrar com a quantidade: " );

    printf ( "Resultado: { " );
    method_0612a ( quantidade );
    printf ( "}\n" );
}

// procedimento recursivo para mostrar sequencia de inversos.
void method_0613a ( int x, int n )
{
    // testar se contador valido
    if ( x <= n )
    {
        // tratar primeiro termo de forma particular
        if ( x == 1 )
        {
            printf ( "1/1 " );
        }
        else
        {
            printf ( "1/%d ", 4 * ( x - 1 ) );
        }
        method_0613a ( x + 1, n );
    } 
}

// Method_0613
void method_0613 ( void )
{
    int quantidade = 0;

    quantidade = readint ( "Entrar com a quantidade: " );

    printf ( "Resultado: { " );
    method_0613a ( 1, quantidade );
    printf ( "}\n" );
}

// Procedimento recursivo para mostrar inversos terminando em 1/1.
void method_0614a ( int x )
{
    if ( x > 1 )
    {
        // mostrar fracao atual
        printf ( "1/%d ", 3 * ( x - 1 ) );
        // passar ao proximo
        method_0614a ( x - 1 );
    }
    else
    {
        if ( x == 1 )
        {
            printf ( "1/1 " );
        } 
    } 
}

//Method_0614
void method_0614 ( void )
{
    int quantidade = 0;

    quantidade = readint ( "Entrar com a quantidade: " );

    printf ( "Resultado: { " );
    method_0614a ( quantidade );
    printf ( "}\n" );
}

// Gerar termo recursivamente a partir da soma dos impares.
int termo_0615 ( int k )
{
    int resposta = 5;
    if ( k > 1 )
    {
        // termo k = termo (k-1) + (2*(k-1) - 1)
        resposta = termo_0615 ( k - 1 ) + ( 2 * ( k - 1 ) - 1 );
    } 
    return ( resposta );
}

// Somar os termos gerados recursivamente.
int somarImpares0615 ( int n )
{
    int soma = 0;
    if ( n > 0 )
    {
        soma = termo_0615 ( n ) + somarImpares0615 ( n - 1 ); // motor da recursividade
    }
    return ( soma );
}

// Method_0615
void method_0615 ( void )
{
    int quantidade = 0;
    int soma = 0;

    quantidade = readint ( "Entrar com a quantidade: " );

    // calcular soma
    soma = somarImpares0615 ( quantidade );

    printf ( "soma (%d termos) = %d\n", quantidade, soma );
} 

// Somar recursivamente os inversos dos multiplos de 3.
double somarInversos3 ( int x )
{
    double soma = 0.0;
    if ( x > 0 )
    {
        // somar termo atual e passar ao proximo
        soma = ( 1.0 / ( 3.0 * x ) ) + somarInversos3 ( x - 1 );
    } 
    return ( soma );
}

// Method_ 0616
void method_0616 ( void )
{
    int quantidade = 0;
    double soma = 0.0;

    quantidade = readint ( "Entrar com a quantidade: " );

    soma = somarInversos3 ( quantidade );

    printf ( "soma (%d termos) = %lf\n", quantidade, soma );
} 

// Procedimento recursivo para mostrar string invertida.
void mostrarInverso ( const char *cadeia, int x )
{
    if ( x >= 0 )
    {
        // mostrar caractere atual
        printf ( "%c\n", cadeia[x] );

        mostrarInverso ( cadeia, x - 1 );
    }
}

// Method_0617
void method_0617 ( void )
{
    char cadeia [ STR_SIZE ];

    readstring ( "Entrar com uma sequencia: ", cadeia, STR_SIZE );

    printf ( "Resultado:\n" );
    mostrarInverso ( cadeia, strlen ( cadeia ) - 1 );
}

// Contar recursivamente digitos impares
int contarDigitosImpares ( const char *cadeia, int x )
{
    int resposta = 0;

    if ( 0 <= x && x < strlen ( cadeia ) )
    {
        // testar se e caractere digito
        if ( cadeia[x] >= '0' && cadeia[x] <= '9' )
        {
            // testar se digito tem valor impar
            if ( ( cadeia[x] - '0' ) % 2 != 0 )
            {
                resposta = 1;
            } 
        } 
        // somar acumulado e passar ao proximo
        resposta = resposta + contarDigitosImpares ( cadeia, x + 1 ); // motor da recursividade
    }
    return ( resposta );
}

// Method_0618
void method_0618 ( void )
{
    char cadeia [ STR_SIZE ];

    readstring ( "Entrar com uma sequencia: ", cadeia, STR_SIZE );

    printf ( "Digitos impares em \"%s\" = %d\n", cadeia, contarDigitosImpares ( cadeia, 0 ) );

    printf ( "Teste (\"P4LaVr@1\") = %d\n", contarDigitosImpares ( "P4LaVr@1", 0 ) );
    printf ( "Teste (\"13579024\") = %d\n", contarDigitosImpares ( "13579024", 0 ) );
} 

// Contar recursivamente maiusculas no intervalo ['L', 'Q'].
int contarMaiusculasLQ ( const char *cadeia, int x )
{
    int resposta = 0;

    if ( 0 <= x && x < strlen ( cadeia ) )
    {
        if ( cadeia[x] >= 'L' && cadeia[x] <= 'Q' )
        {
            resposta = 1;
        } 
        // somar acumulado e passar ao proximo
        resposta = resposta + contarMaiusculasLQ ( cadeia, x + 1 ); // motor da recursividade
    } 

    return ( resposta );
}

//Method_0619
void method_0619 ( void )
{
    char cadeia [ STR_SIZE ];

    readstring ( "Entrar com uma sequencia: ", cadeia, STR_SIZE );

    printf ( "Maiusculas ['L'..'Q'] em \"%s\" = %d\n", cadeia, contarMaiusculasLQ ( cadeia, 0 ) );

    printf ( "Teste (\"P4LaVr@1\") = %d\n", contarMaiusculasLQ ( "P4LaVr@1", 0 ) );
    printf ( "Teste (\"LMNO PQR\") = %d\n", contarMaiusculasLQ ( "LMNO PQR", 0 ) );
}

// Gerador de numero da serie de Fibonacci.
int fibonacci ( int x )
{
    int resposta = 0;

    if ( x == 1 || x == 2 )
    {
        resposta = 1;
    }
    else
    {
        if ( x > 2 )
        {
            resposta = fibonacci ( x - 1 ) + fibonacci ( x - 2 ); 
        }
    } 
    return ( resposta );
}

// Somar certa quantidade de termos pares de Fibonacci.
int somarFibonacciPares ( int ordem, int pares_encontrados, int meta_pares )
{
    int soma = 0;
    int termo = 0;

    if ( pares_encontrados < meta_pares )
    {
        termo = fibonacci ( ordem );

        if ( termo % 2 == 0 )
        {
            printf ( "%d ", termo );
            soma = termo + somarFibonacciPares ( ordem + 1, pares_encontrados + 1, meta_pares );
        }
        else
        {
            soma = somarFibonacciPares ( ordem + 1, pares_encontrados, meta_pares );
        } // end if
    } // end if

    return ( soma );
}

// Method_0620
void method_0620 ( void )
{
    int quantidade = 0;
    int soma = 0;

    quantidade = readint ( "Entrar com a quantidade de termos pares: " );

    printf ( "Termos pares: " );
    soma = somarFibonacciPares ( 1, 0, quantidade );
    printf ( "\nSoma = %d\n", soma );
}

// Calculo recursivo de base elevada a expoente inteiro positivo.
double potencia ( double base, int expoente )
{
    double resposta = 1.0;

    if ( expoente > 0 )
    {
        resposta = base * potencia ( base, expoente - 1 );
    } 

    return ( resposta );
}

// Calcular parcelas da funcao recursivamente.
double funcao06E1 ( double x, int n, int termo )
{
    double soma = 0.0;

    if ( termo < n )
    {
        soma = potencia ( x, 2 * termo ) + funcao06E1 ( x, n, termo + 1 );
    } 

    return ( soma );
}

// Method_06E1
void method_06E1 ( void )
{
    double x = 0.0;
    int n = 0;
    double resultado = 0.0;

    x = readdouble ( "Entrar com o valor de x: " );
    n = readint ( "Entrar com a quantidade de termos n: " );

    resultado = funcao06E1 ( x, n, 0 );

    printf ( "f(%lf, %d) = %lf\n", x, n, resultado );
}

// Calculo recursivo de fatorial.
double fatorial ( int x )
{
    double resposta = 1.0;

    if ( x > 1 )
    {
        resposta = ( double ) x * fatorial ( x - 1 );
    } 
    return ( resposta );
}

double calcularSerieE2 ( int termo, int n )
{
    double soma = 0.0;

    if ( termo < n )
    {
        if ( termo == 0 )
        {
            soma = 1.0 + calcularSerieE2 ( termo + 1, n );
        }
        else
        {
            double numerador = ( double )( 2 * termo + 1 );
            double denominador = fatorial ( 2 * termo + 2 );
            soma = ( numerador / denominador ) + calcularSerieE2 ( termo + 1, n );
        }
    }

    return ( soma );
}

// Method_06E2
void method_06E2 ( void )
{
    int n = 0;
    double resultado = 0.0;

    n = readint ( "Entrar com o numero de termos n: " );

    resultado = calcularSerieE2 ( 0, n );

    printf ( "Valor da serie e (%d termos) = %.10lf\n", n, resultado );
}

int main ( void ) {
    int opcao = 0;
    printf ( "%s\n", "935146 - AED1" );
    printf ( "\n" );
    do {
        opcao = readint ( "Qual a opcao? " );
        printf ( "%s%d\n", "opcao=", opcao );
        switch ( opcao ) {
            case 0: break;
            case 1:  method_0611 ( ); break;
            case 2:  method_0612 ( ); break;
            case 3:  method_0613 ( ); break;
            case 4:  method_0614 ( ); break;
            case 5:  method_0615 ( ); break;
            case 6:  method_0616 ( ); break;
            case 7:  method_0617 ( ); break;
            case 8:  method_0618 ( ); break;
            case 9:  method_0619 ( ); break;
            case 10: method_0620 ( ); break;
            case 11: method_06E1 ( ); break;
            case 12: method_06E2 ( ); break;

            default:
                printf ( "%s\n", "ERRO: Opcao invalida." );
                break;
        }
    } while ( opcao != 0 );

    printf ( "%s\n", "Fim do programa\n" );
    return 0;
}
