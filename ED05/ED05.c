/*Autora: Lavinia Franca da Silva*/

#include "io.h"

// metodo 1
// funcao para gerar valores multiplos de 4
int multiplo_de_quatro(int i)
{
    return (4 * i);
}

//procedimento para testar a funcao e gerar os multiplos em ordem crescente.
void procedimento0511(int n)
{
    // Identificacao
     printf("\n{ ");

    // Repeticao para gerar e mostrar os termos
    for (int i = 1; i <= n; i = i + 1)
    {
        printf("%d", multiplo_de_quatro(i));

        if (i < n)
        {
            printf(", ");
        }
    }

    printf(" }\n\n");
}

//metodo
void method_0511(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de valores: ");

    if (n <= 0)
    {
       printf("\nERRO: Quantidade deve ser maior que zero.\n");
    }
    else
    {
        procedimento0511(n);
    }
}

// metodo 2
// funcao para gerar valores multiplos de 2 e 3
int multiplos_de_dois_e_tres(int i)
{
    return (6 * i);
}

//procedimento para testar a funcao e gerar os multiplos em ordem crescente.
void procedimento0512(int n)
{
    // Identificacao
     printf("\n{ ");

    // Repeticao para gerar e mostrar os termos
    for (int i = 1; i <= n; i = i + 1)
    {
        printf("%d", multiplos_de_dois_e_tres(i));

        if (i < n)
        {
            printf(", ");
        }
    }

    printf(" }\n\n");
}

//metodo
void method_0512(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de valores: ");

    if (n <= 0)
    {
       printf("\nERRO: Quantidade deve ser maior que zero.\n");
    }
    else
    {
        procedimento0512(n);
    }
}

// metodo 3
// funcao para gerar valores em potencias de 4
int potencia_de_quatro(int expoente)
{
    int resultado = 1;

    for (int i = 0; i < expoente; i = i + 1)
    {
        resultado = resultado * 4;
    }

    return resultado;
}

//procedimento para testar a funcao e gerar as potencias em ordem decrescente
void procedimento0513(int n)
{
    // Identificacao
     printf("\n{ ");

    // Repeticao para gerar e mostrar os termos
    for (int i = n; i >= 1; i = i - 1)
    {
        printf("%d", potencia_de_quatro( i ));

        if (i > 1)
        {
            printf(", ");
        }
    }

    printf(" }\n\n");
}

//metodo
void method_0513(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de valores: ");

    if (n <= 0)
    {
       printf("\nERRO: Quantidade deve ser maior que zero.\n");
    }
    else
    {
        procedimento0513(n);
    }
}

// metodo 4
// funcao para gerar valores crescentes nos denominadores multiplos de 4.
int denominador(int i)
{
   return ( 4 * i);
}

//procedimento para testar a funcao e gerar as potencias em ordem decrescente
void procedimento0514(int n)
{
    // Identificacao
     printf("\n{ ");

    // Repeticao para gerar e mostrar os termos
     for (int i = 1; i <= n; i = i + 1) 
     {
        printf("1/%d", denominador( i ));

        if (i < n)
        {
            printf(", ");
        }
    }

    printf(" }\n\n");
}

//metodo
void method_0514(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de valores: ");

    if (n <= 0)
    {
       printf("\nERRO: Quantidade deve ser maior que zero.\n");
    }
    else
    {
        procedimento0514(n);
    }
}

// metodo 5
// funcao para gerar valores pares crescentes nos denominadores da sequencia apresentada
double denominador_2(double x, int i)
{
    int expoente = (2 * i) - 1;
    return pow(x, expoente);
}

//procedimento para testar a funcao e gerar a sequencia
void procedimento0515(int n, double x)
{
    // Identificacao
     printf("\n{ ");

    for (int i = 1; i <= n; i = i + 1)
    {
        if (i == 1)
        {
       printf("1");
    }
      else
    {

    printf("1/x^%d", (2 * i) - 1);

    }
        // Formatacao da virgula
        if (i < n)
        {
            printf(", ");
        }
    }

    printf(" }\n\n");
}

//metodo
void method_0515(void)
{
    double x = 0.0;
    int n = 0;

    x = readdouble("Entrar com um valor real para a base: ");
    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade de termos deve ser maior que zero.\n");
    }
    else if (x == 0.0)
    {
        printf("\nERRO: A base nao pode ser zero (divisao por zero).\n");
    }
    else
    {
        procedimento0515(n, x);
    }
}

// metodo 6
// Funcao para calcular a soma dos n primeiros numeros positivos
int somar_termos(int n)
{
    int soma = 0;
    int contador = 0; 
    int candidato = 4; 

    while (contador < n)
    {
        // Verifica se e multiplo de 2 e nao e multiplo de 3
        if (candidato % 2 == 0 && candidato % 3 != 0)
        {
            soma = soma + candidato;
            contador = contador + 1;
        }

        // Avanca para o proximo par positivo
        candidato = candidato + 2;
    }

    return (soma);
}

//Procedimento para exibir a expressao da soma na tela
void procedimento0516(int n)
{
    int contador  = 0;
    int candidato = 4;

    printf("\nSoma para n = %d:\n", n);

    while (contador < n)
    {
        if (candidato % 2 == 0 && candidato % 3 != 0)
        {
            printf("%d", candidato);
            contador = contador + 1;

            if (contador < n)
            {
                printf(" + ");
            }
        }

        candidato = candidato + 2;
    }

    // Exibe o total calculado pela funcao
    printf(" = %d\n\n", somar_termos(n));
}

//metodo
void method_0516(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade de termos deve ser maior que zero.\n");
    }
    else
    {
        procedimento0516(n);
    }
}

// metodo 7
// Funcao para calcular a soma dos inversos dos primeiros n valores
double somar_inversos(int n)
{
    double soma = 0.0;
    int    contador = 0;
    int    candidato = 3;

    while (contador < n)
    {
        // Verifica se nao e multiplo de 5
        if (candidato % 5 != 0)
        {
            soma = soma + (1.0 / (double) candidato);
            contador = contador + 1;
        }

        // Avanca para o proximo multiplo de 3
        candidato = candidato + 3;
    }

    return (soma);
}

//Procedimento para exibir a expressao dos inversos e o resultado da soma.
void procedimento0517(int n)
{
    int contador = 0;
    int candidato = 3;

    printf("\nExpressao para n = %d:\n", n);

    while (contador < n)
    {
        if (candidato % 5 != 0)
        {
            printf("1/%d", candidato);
            contador = contador + 1;

            if (contador < n)
            {
                printf(" + ");
            }
        }

        candidato = candidato + 3;
    }

    printf(" = %.6lf\n", somar_inversos(n));
}

//metodo
void method_0517 (void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade deve ser maior que zero.\n");
    }
    else
    {
        // Teste com o valor lido
        procedimento0517(n);

        // Testes adicionais para quantidades diferente
        printf("\nTestes automaticos para outras quantidades");
        procedimento0517(3);
        procedimento0517(5);
        procedimento0517(7);
    }
}

// metodo 8
// Funcao para calcular a soma dos primeiros n termos da sequencia
int somar_naturais(int n)
{
    int soma = 0;
    int termo = 3;

    for (int i = 0; i < n; i = i + 1)
    {
        termo = termo + i;
        soma  = soma + termo;
    }

    return (soma);
}

//Procedimento para exibir a expressao dos inversos e o resultado da soma.
void procedimento0518(int n)
{
    int termo = 3;

    printf("\nExpressao para n = %d:\n", n);

    for (int i = 0; i < n; i = i + 1)
    {
        termo = termo + i;
        printf("%d", termo);

        if (i < n - 1)
        {
            printf(" + ");
        }
    }

    printf(" = %d\n", somar_naturais(n));
}

//metodo
void method_0518 (void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade de termos deve ser maior que zero.\n");
    }
    else
    {
        procedimento0518(n);

        // Testes com quantidades diferentes
        printf("\nTestes automaticos para outras quantidades");
        procedimento0518(3);
        procedimento0518(5);
        procedimento0518(7);
    }
}

// metodo 9
// Funcao para calcular a soma dos quadrados dos numeros naturais
int somar_quadrados(int n)
{
    int soma = 0;
    int base = 2;

    for (int i = 0; i < n; i = i + 1)
    {
        soma = soma + (base * base);
        base = base + 1; 
    }
    return (soma);
}

// Procedimento para exibir a expressao dos quadrados e o resultado da soma
void procedimento0519(int n)
{
    int base = 2;
    int termo = 0;

    printf("\nExpressao para n = %d:\n", n);

    for (int i = 0; i < n; i = i + 1)
    {
        termo = base * base;
        printf("%d", termo);

        if (i < n - 1)
        {
            printf(" + ");
        }

        base = base + 1;
    }

    // Exibe o total acumulado calculado pela funcao
    printf(" = %d\n", somar_quadrados(n));
}

//metodo 9
void method_0519(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade de termos deve ser maior que zero.\n");
    }
    else
    {
        // Teste com a quantidade informada pelo usuario
        procedimento0519(n);

        // Testes adicionais para quantidades diferentes
        printf("\nTestes automaticos para outras quantidades");
        procedimento0519(3);
        procedimento0519(5);
        procedimento0519(7);
    }
}

//metodo 10
// Funcao para calcular o primeiro denominador da sequencia com n termos
int primeiro_denominador(int n)
{
    int inicio = 4;

    for (int k = 1; k < n; k = k + 1)
    {
        inicio = inicio + k;
    }

    return (inicio);
}

// Funcao para calcular a soma dos inversos na sequencia decrescente com diferencas naturais terminando em 4
double somar_inversos0520(int n)
{
    double soma = 0.0;
    int denominador = primeiro_denominador(n);
    int passo = n - 1;

    for (int i = 0; i < n; i = i + 1)
    {
        soma = soma + (1.0 / (double) denominador);

        // Subtrai a diferenca natural decrescente
        denominador = denominador - passo;
        passo = passo - 1;
    }

    return (soma);
}

// Procedimento para exibir a expressao dos inversos e o resultado da soma
void procedimento0520(int n)
{
    int denominador = primeiro_denominador(n);
    int passo = n - 1;

    printf("\nExpressao para n = %d:\n", n);

    for (int i = 0; i < n; i = i + 1)
    {
        printf("1/%d", denominador);

        if (i < n - 1)
        {
            printf(" + ");
        }

        denominador = denominador - passo;
        passo = passo - 1;
    }

    printf(" = %.6lf\n", somar_inversos0520(n));
}

//metodo 10
void method_0520(void)
{
    int n = 0;

    n = readint("Entrar com a quantidade de termos: ");

    if (n <= 0)
    {
        printf("\nERRO: A quantidade de termos deve ser maior que zero.\n");
    }
    else
    {
        // Teste com o valor lido do teclado
        procedimento0520(n);

        // Testes adicionais com quantidades diferentes
        printf("\nTestes automaticos para outras quantidades");
        procedimento0520(3); // 1/7 + 1/5 + 1/4
        procedimento0520(5); // 1/14 + 1/10 + 1/7 + 1/5 + 1/4
        procedimento0520(7); // 1/19 + 1/14 + 1/10 + 1/7 + 1/5 + 1/4
    }
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
            case 1:  method_0511 ( ); break;
            case 2:  method_0512 ( ); break;
            case 3:  method_0513 ( ); break;
            case 4:  method_0514 ( ); break;
            case 5:  method_0515 ( ); break;
            case 6:  method_0516 ( ); break;
            case 7:  method_0517 ( ); break;
            case 8:  method_0518 ( ); break;
            case 9:  method_0519 ( ); break;
            case 10: method_0520 ( ); break;

            default:
                printf ( "%s\n", "ERRO: Opcao invalida." );
                break;
        }
    } while ( opcao != 0 );

    printf ( "%s\n", "Fim do programa\n" );
    return 0;
}
