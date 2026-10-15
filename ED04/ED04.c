/* Autora: Lavinia Franca da Silva*/

#include "io.h"

// Funcoes necessarias

int maiuscula(char c) {
    return (c >= 'A' && c <= 'Z');
}

int minuscula(char c) {
    return (c >= 'a' && c <= 'z');
}

int digito(char c) {
    return (c >= '0' && c <= '9');
}

int letra(char c) {
    return ( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
}

int alfanumerico(char c) {
    return ( letra(c) || digito(c) );
}

int contarAlfanumericos(char cadeia[]) {
    int i = 0;
    int cont = 0;
    char c;

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( alfanumerico(c) ) {
            cont = cont + 1;
        }
        i = i + 1;
    }
    return cont;
}

int contar_simbolos(char sequencia[]) {
    int i = 0;
    int cont = 0;
    char c;

    while ( sequencia[i] != '\0' ) {
        c = sequencia[i];
        if ( minuscula(c) && c >= 'l' && c <= 'q' ) {
            cont = cont + 1;
        }
        i = i + 1;
    }
    return cont;
}

void separar_simbolos(char sequencia[], char simbolos[]) {
    int i = 0;
    char c;
    char unitaria[2];

    simbolos[0] = '\0';

    while ( sequencia[i] != '\0' ) {
        c = sequencia[i];
        if ( minuscula(c) && c >= 'l' && c <= 'q' ) {
            unitaria[0] = c;
            unitaria[1] = '\0';
            strcat(simbolos, unitaria);
        }
        i = i + 1;
    }
}

int contarSimbolos(const char cadeia[]) {
    int i = 0;
    int cont = 0;
    char c;

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( (minuscula(c) && c >= 'l' && c <= 'q') ||
             (maiuscula(c) && c >= 'L' && c <= 'Q') ) {
            cont = cont + 1;
        }
        i = i + 1;
    }
    return cont;
}

void separarSimbolos(const char *cadeia, char *simbolos) {
    int i = 0;
    char c;
    char unitaria[2];

    simbolos[0] = '\0';

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( (minuscula(c) && c >= 'l' && c <= 'q') ||
             (maiuscula(c) && c >= 'L' && c <= 'Q') ) {
            unitaria[0] = c;
            unitaria[1] = '\0';
            strcat(simbolos, unitaria);
        }
        i = i + 1;
    }
}

int alfanumericoOuEspaco(char c)
{
    return ( (c >= 'a' && c <= 'z') ||
             (c >= 'A' && c <= 'Z') ||
             (c >= '0' && c <= '9') ||
             (c == ' ') );
}

int contar_Simbolos(char cadeia[])
{
    int i = 0;
    int cont = 0;
    char c;
 
    while ( cadeia[i] != '\0' )
    {
        c = cadeia[i];
        if ( alfanumericoOuEspaco(c) )
        {
            cont = cont + 1;
        }
        i = i + 1;
    }
 
    return cont;
}
 
int contarDigitosImpares(const char cadeia[]) {
    int i = 0;
    int cont = 0;
    char c;

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( digito(c) && (int)c % 2 != 0 ) {
            cont = cont + 1;
        }
        i = i + 1;
    }
    return cont;
}

int contarDigitos(char cadeia[])
{
    int i = 0;
    int cont = 0;
    char c;
 
    while ( cadeia[i] != '\0' )
    {
        c = cadeia[i];
        if ( digito(c) )
        {
            cont = cont + 1;
        }
        i = i + 1;
    }
 
    return cont;
}

char *separarNaoAlfanumericos(char *cadeia, char *simbolos) {
    int i = 0;
    char c;
    char unitaria[2];

    simbolos[0] = '\0';

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( !alfanumerico(c) ) {
            unitaria[0] = c;
            unitaria[1] = '\0';
            strcat(simbolos, unitaria);
        }
        i = i + 1;
    }
    return simbolos;
}

void separarAlfanumericos(char cadeia[], char simbolos[]) {
    int i = 0;
    char c;
    char unitaria[2];

    simbolos[0] = '\0';

    while ( cadeia[i] != '\0' ) {
        c = cadeia[i];
        if ( alfanumerico(c) ) {
            unitaria[0] = c;
            unitaria[1] = '\0';
            strcat(simbolos, unitaria);
        }
        i = i + 1;
    }
}

int totalAlfanumericos(int quantidade, int contagens[])
{
    int i = 0;
    int total = 0;
 
    while ( i < quantidade )
    {
        total = total + contagens[i];
        i = i + 1;
    }

    return total;
}

// Métodos

void method_0411 ( void ) {
    int n = 0;
    double intervalo_1 = 0.0;
    double intervalo_2 = 0.0;
    double input = 0.0;
    int cont = 0;
    int cont_2 = 0;

    n = (int) readdouble ("Entrar com quantidade de valores reais: ");
    intervalo_1 = readdouble ("Entrar com primeiro valor real para o intervalo: ");
    intervalo_2 = readdouble ("Entrar com segundo valor real para o intervalo: ");

    while ( n > 0 ) {
        printf("Entrar com valor real: ");
        scanf("%lf", &input);
        getchar( );
        if ( input >= intervalo_1 && input <= intervalo_2 ) {
            cont = cont + 1;
        } else {
            cont_2 = cont_2 + 1;
        }
        n = n - 1;
    }

    printf("Valores dentro do intervalo: %d\n", cont);
    printf("Valores fora do intervalo: %d\n", cont_2);
}

void method_0412 ( void ) {
    char sequencia[100];
    int i = 0;
    int cont = 0;
    char c;

    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    while ( sequencia[i] != '\0' ) {
        char = sequencia[i];
        if ( minuscula(c) && c >= 'l' && c <= 'q' ) {
            cont = cont + 1;
        }
        i = i + 1;
    }
    printf("Quantidade de letras minusculas entre l e q: %d\n", cont);
}

void method_0413 ( void ) {
    char sequencia[100];
    
    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    int cont = contar_simbolos(sequencia);
    printf("Quantidade de letras minusculas entre l e q: %d\n", cont);
}

void method_0414 ( void ) {
    char sequencia[100];
    char simbolos[100];

    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    separar_simbolos(sequencia, simbolos);
    printf("Letras minusculas entre l e q: %s\n", simbolos);
}

void method_0415 ( void ) {
    char sequencia[100];
    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    int cont = contarSimbolos(sequencia);
    printf("Quantidade de letras entre l/L e q/Q: %d\n", cont);
}

void method_0416 ( void ) {
    char sequencia[100];
    char simbolos[100];

    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    separarSimbolos(sequencia, simbolos);
    printf("Letras entre l/L e q/Q: %s\n", simbolos);
}

void method_0417 ( void ) {
    char sequencia[100];
    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    int cont = contarDigitosImpares(sequencia);
    printf("Quantidade de digitos impares: %d\n", cont);
}

void method_0418 ( void ) {
    char sequencia[100];
    char simbolos[100];

    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    separarNaoAlfanumericos(sequencia, simbolos);
    printf("Simbolos nao alfanumericos: %s\n", simbolos);
}

void method_0419 ( void ) {
    char sequencia[100];
    char simbolos[100];

    printf("Entrar com a sequencia de caracteres: ");
    scanf("%s", sequencia);
    getchar( );

    separarAlfanumericos(sequencia, simbolos);
    printf("Simbolos alfanumericos: %s\n", simbolos);
}

void method_0420 ( void )
{
    //definir dados locais
    int quantidade;
    int i = 0;
    char palavra[MAX_TAM];
    int contagens[MAX_PALAVRAS];
    int total;
 
    //ler a quantidade de cadeias a processar
    printf("Quantidade de cadeias de caracteres: ");
    scanf("%d", &quantidade);
 
    //ler cada cadeia, uma por vez, mostrar e contar seus simbolos alfanumericos
    while ( i < quantidade )
    {
        printf("Entrar com a cadeia %d: ", i + 1);
        scanf("%s", palavra);
 
        contagens[i] = contarAlfanumericos(palavra);
 
        printf("Cadeia: %s; simbolos alfanumericos: %d\n", palavra, contagens[i]);
 
        i = i + 1;
    }
 
    //calcular o total acumulado de todas as palavras em outro metodo
    total = totalAlfanumericos(quantidade, contagens);
 
    printf("Total de simbolos alfanumericos: %d\n", total);
}

void method_04EI ( void ) 
    {
    //definir dados locais
    int quantidade;
    int i = 0;
    char palavra[MAX_TAM];
    int cont;
    int total = 0;
 
    //ler a quantidade de cadeias a processar
    printf("Quantidade de cadeias de caracteres: ");
    scanf("%d", &quantidade);
    getchar( );
 
    //ler cada cadeia (linha), permitindo espacos em branco, com fgets
    while ( i < quantidade )
    {
        printf("Entrar com a cadeia %d: ", i + 1);
        fgets(palavra, MAX_TAM, stdin);
 
        //contar os simbolos alfanumericos (incluindo espacos) por meio da funcao
        cont = contar_Simbolos(palavra);
 
        printf("Cadeia: \"%s\" simbolos (com espacos): %d\n", palavra, cont);
 
        //acumular apenas as cadeias com mais de tres simbolos
        if ( cont > 3 )
        {
            total = total + cont;
        }
 
        i = i + 1;
    }
 
    printf("Total de cadeias com mais de 3 simbolos: %d\n", total);
}

void method_04E2 ( void )
{
    {
    //definir dados locais
    char sequencia1[100];
    char sequencia2[100];
    int digitos1;
    int digitos2;
 
    //ler as duas sequencias de caracteres
    printf("Entrar com a primeira sequencia de caracteres:");
    scanf("%s", sequencia1);
    printf("Entrar com a segunda sequencia de caracteres:");
    scanf("%s", sequencia2);
 
    //contar os digitos de cada sequencia por meio da funcao
    digitos1 = contarDigitos(sequencia1);
    digitos2 = contarDigitos(sequencia2);
 
    printf("Sequencia 1 possui %d digitos\n", digitos1);
    printf("Sequencia 2 possui %d digitos\n", digitos2);
 
    //comparar as quantidades de digitos para saber qual e a menor
    if ( digitos1 < digitos2 )
    {
        printf("A sequencia com menor quantidade de digitos e a primeira.\n");
    }
    else if ( digitos2 < digitos1 )
    {
        printf("A sequencia com menor quantidade de digitos e a segunda.\n");
    }
    else
    {
        printf("As duas sequencias possuem a mesma quantidade de digitos.\n");
    }
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
            case 1:  method_0411 ( ); break;
            case 2:  method_0412 ( ); break;
            case 3:  method_0413 ( ); break;
            case 4:  method_0414 ( ); break;
            case 5:  method_0415 ( ); break;
            case 6:  method_0416 ( ); break;
            case 7:  method_0417 ( ); break;
            case 8:  method_0418 ( ); break;
            case 9:  method_0419 ( ); break;
            case 10: method_0420 ( ); break;
            case 11: method_04EI ( ); break;
            case 12: method_04E2 ( ); break;
            default:
                printf ( "%s\n", "ERRO: Opcao invalida." );
                break;
        }
    } while ( opcao != 0 );

    printf ( "%s\n", "Fim do programa\n" );
    return 0;
}
