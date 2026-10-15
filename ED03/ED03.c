/*Autora: Lavinia Franca da Silva*/

#include <stdio.h>

//Funcao para testar se o caractere e uma letra maiuscula.
int maiuscula(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    }
    return 0;
}

//Funcao para testar se o caractere e uma letra minuscula.
int minuscula(char c) {
    if (c >= 'a' && c <= 'z') {
        return 1;
    }
    return 0;
}
//Funcao para testar se o caractere e uma letra.

int letra(char c) {
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
        return 1;
    }
    return 0;
    }

//Funcao para testar se o caractere e um digito impar.
int impar(char c) {
    if (c == '1' || c == '3' || c == '5' || c == '7' || c == '9') {
        return 1;
    }
    return 0;
    }

//Funcao para testar se o caractere e um digito par.
int par(char c) {
    if (c == '0' || c == '2' || c == '4' || c == '6' || c == '8') {
        return 1;
    }
    return 0;
    }

//Funcao para testar se o numero e multiplo de 3.
int multiplo_3(int valor){
    if (valor%3 == 0); {
        return 1;
    }
    return 0;
}

//Funcao para testar se o valor pertence ao intervalo [a, b].
int intervalo(int valor, int a, int b) {
    if (valor >= a && valor <= b){
        return 1;
    }
    return 0;
}

//Funcao para testar se o valor e multiplo de 5 e nao e multiplo de 3.
int multiplo_5_nao_3(int valor) {
    if (valor % 5 == 0 && valor % 3 != 0) {
        return 1;
    }
    return 0;
}

//Funcao para testar se o numero e impar e menor que 5
int impar_menor_que_5(int valor) {
    if (valor % 2 != 0 && valor < 5) {
        return 1;
    }
    return 0;
}

//Funcao para testar se o valor real pertence ao intervalo aberto (a, b).
int intervalo_aberto(double valor, double a, double b) {
    if (valor > a && valor < b) {
        return 1;
    }
    return 0;
}

void metodo_0311(void) 
{
    char palavra[100];
    int cont = 0;

    printf("\nMetodo 0311\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Letras maiusculas <= L: ");
    while (palavra[cont] != '\0') {
        char c = palavra[cont];
        if (maiuscula(c) == 1 && c <= 'L') {
            printf("%c ", c);
        }
        cont = cont + 1;
    }
}

void metodo_0312(void) {
    char palavra[100];
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0312\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    printf("Letras minusculas >= 'l': ");
    while (palavra[i] != '\0') {
        char c = palavra[i];
        if (minuscula(c) == 1 && c >= 'l') {
            printf("%c ", c);
        contador = contador + 1;
        }
        i = i + 1;
    }
    printf("\nTotal de letras encontradas: %d\n", contador);
}

void metodo_0313(void) {
    char palavra[100];
    int tamanho = 0;
    int contador = 0;
    int i = 0;

    printf("\nMetodo 0313\n");
    printf("Digite uma palavra: ");
    scanf("%s", palavra);

    //Descobrir o tamanho da palavra
    while (palavra[tamanho] != '\0') {
        tamanho = tamanho + 1;
    }

    printf("Letras maiusculas <= 'L' (do fim para o inicio): ");
    
    i = tamanho - 1;

    //Percorrer de tras para frente
    while (i >= 0) {
        char c = palavra[i];
        if (maiuscula(c) == 1 && c <= 'L') {
            printf("%c ", c);
            contador = contador + 1;
        }
        i = i - 1;
    }

    printf("\nTotal de letras encontradas: %d\n", contador);
    }

    void metodo_0314(void) {
    char cadeia[100];
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0314\n");
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    printf("Letras encontradas: ");
    while (cadeia[i] != '\0') {
        char c = cadeia[i];
        if (letra(c) == 1) {
            printf("%c ", c);
            contador = contador + 1;
        }
        i = i + 1;
    }

    printf("\nTotal de letras encontradas: %d\n", contador);
}


void metodo_0315(void) {
    char cadeia[100];
    int tamanho = 0;
    int contador = 0;
    int i = 0;

    printf("\nMetodo 0315\n");
    printf("Digite uma cadeia de caracteres:");
    scanf("%s", cadeia);

    //Descobrir o comprimento da cadeia
    while (cadeia[tamanho] != '\0') {
        tamanho = tamanho + 1;
    }

    printf("Digitos impares (do fim para o inicio):");

    //Apontar para o ultimo caractere
    i = tamanho - 1;

    //Percorrer de tras para frente
    while (i >= 0) {
        char c = cadeia[i];
        if (impar(c) == 1) {
            printf("%c ", c);
            contador = contador + 1;
        }
        i = i - 1;
    }

    printf("\nTotal de digitos impares: %d\n", contador);
}

void metodo_0316(void){
    char cadeia[100];
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0316\n");
    printf("Digite uma cadeia de caracteres: ");
    scanf("%s", cadeia);

    printf("Simbolos que nao sao digito par nem letra: ");
    while (cadeia[i] != '\0') {
        char c = cadeia[i];
        
        if (c != par(c) && c != letra(c) ) {
            printf("%c ", c);
            contador = contador + 1;
        }
        i = i + 1;
    }

    printf("\nTotal encontrado: %d\n", contador);
}

void metodo_0317(void) {
    int a = 0;
    int b = 0;
    int n = 0;
    int x = 0;
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0317\n");
    
    //Leitura do intervalo [a:b]
    printf("Digite o limite inferior (a): ");
    scanf("%d", &a);
    printf("Digite o limite superior (b): ");
    scanf("%d", &b);

    // Ajuste caso o usuario digite o maior primeiro
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }

    //Leitura da quantidade n
    printf("Digite a quantidade de valores a serem testados (n): ");
    scanf("%d", &n);

    //Leitura e teste dos n valores com while
    i = 0;
    while (i < n) {
        printf("Digite o %do valor (x): ", i + 1);
        scanf("%d", &x);

        // Testa se e multiplo de 3 e pertence ao intervalo [a:b]
        if (multiplo_3(x) == 1 && intervalo(x, a, b) == 1) {
            printf(" O valor %d e multiplo de 3 e pertence a [%d:%d]\n", x, a, b);
            contador = contador + 1;
        }

        i = i + 1;
    }

    printf("\nTotal de valores validos encontrados: %d\n", contador);
}

    void metodo_0318(void) {
    int a = 0;
    int b = 0;
    int n = 0;
    int x = 0;
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0318\n");

    //Leitura do intervalo [a:b]
    printf("Digite o limite inferior (a): ");
    scanf("%d", &a);
    printf("Digite o limite superior (b): ");
    scanf("%d", &b);

    //Leitura da quantidade n
    printf("Digite a quantidade de valores a serem testados (n): ");
    scanf("%d", &n);

    //Leitura e teste dos n valores com while
    i = 0;
    while (i < n) {
        printf("Digite o %do valor (x): ", i + 1);
        scanf("%d", &x);

        // Testa as condicoes: multiplo de 5, nao de 3, e dentro de [a:b]
        if (intervalo(x, a, b) == 1 && multiplo_5_nao_3(x) == 1) {
            printf(" O valor %d e multiplo de 5 (nao de 3) e pertence a [%d:%d]\n", x, a, b);
            contador = contador + 1;
        }

        i = i + 1;
    }

    printf("\nTotal de valores validos encontrados: %d\n", contador);
}

void metodo_0319(void) {
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;
    int n = 0;
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0319\n");

    do {
        printf("Digite o limite inferior (a): ");
        scanf("%lf", &a);
        printf("Digite o limite superior (b, maior que a): ");
        scanf("%lf", &b);
        }

     while (a >= b);

    //Leitura da quantidade n
    printf("Digite a quantidade de valores a testar (n): ");
    scanf("%d", &n);

    //Leitura e teste dos n valores
    i = 0;
    while (i < n) {
        printf("Digite o %do valor real (x): ", i + 1);
        scanf("%lf", &x);

        //Extrai a parte inteira usando type casting
        int parte_inteira = (int)x;

        //Testa o intervalo aberto (a:b) e a condicao da parte inteira
        if (intervalo_aberto(x, a, b) == 1 &&
            impar_menor_que_5(parte_inteira) == 1) {
            printf(" -> %.2f (parte inteira: %d) e valida!\n", x, parte_inteira);
            contador = contador + 1;
        }

        i = i + 1;
    }

    printf("\nTotal de valores validos encontrados: %d\n", contador);
    }

    void metodo_0320(void) {
    double a = 0.0;
    double b = 0.0;
    double x = 0.0;
    int n = 0;
    int i = 0;
    int contador = 0;

    printf("\nMetodo 0320\n");

    int limites_validos = 0;
    while (limites_validos == 0) {
        printf("Digite o limite inferior 'a' (entre 0 e 1): ");
        scanf("%lf", &a);
        printf("Digite o limite superior 'b' (maior que 'a' e menor que 1): ");
        scanf("%lf", &b);

        if (a > 0.0 && a < 1.0 && b > 0.0 && b < 1.0 && a < b) {
            limites_validos = 1;
    }

    //Leitura da quantidade n
    printf("Digite a quantidade de valores a testar (n): ");
    scanf("%d", &n);

    //Leitura e teste dos n valores
    i = 0;
    while (i < n) {
        printf("Digite o %do valor real (x): ", i + 1);
        scanf("%lf", &x);

        // Extrai a parte inteira por type casting e calcula a parte fracionaria
        int parte_inteira = (int)x;
        double parte_fracionaria = x - (double)parte_inteira;

        // Testa se a parte fracionaria pertence ao intervalo aberto (a:b)
        if (intervalo_aberto(parte_fracionaria, a, b) == 1) {
            printf("%.2f (parte fracionaria: %.2f) pertence a ]%.2f : %.2f[\n", 
                   x, parte_fracionaria, a, b);
            contador = contador + 1;
        }

        i = i + 1;
    }

    printf("\nTotal de valores validos encontrados: %d\n", contador);
}
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
          metodo_0311 ( );
           break;
           case 2:
           metodo_0312 ( );
           case 3:
           metodo_0313 ( );
           break;
           case 4:
           metodo_0314 ( );
           break;
           case 5:
           metodo_0315 ( );
           break;
           case 6:
           metodo_0316 ( );
           break;
           case 7:
           metodo_0317 ( );
           break;
           case 8:
           metodo_0318 ( );
           break;
           case 9:
           metodo_0319 ( );
           break;
           case 10:
           metodo_0320 ( );
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
