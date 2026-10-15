/* Autora: Lavinia Franca da Silva*/

#include "io.h"

//funcoes auxiliares

void printArray(int n, int array[])
{
    int i = 0;
    while (i < n)
    {
        printf("%2d: %d\n", i, array[i]);
        i = i + 1;
    }
}

int lerArquivoTamanho(const char* fileName)
{
    int n = 0;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo != NULL)
    {
        if (fscanf(arquivo, "%d", &n) != 1 || n <= 0)
        {
            n = 0;
        }
        fclose(arquivo);
    }
    return n;
}

void lerArquivoDados(const char* fileName, int n, int array[])
{
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo != NULL)
    {
        int total = 0;
        int i = 0;
        fscanf(arquivo, "%d", &total);
        while (!feof(arquivo) && i < n)
        {
            if (fscanf(arquivo, "%d", &array[i]) == 1)
            {
                i = i + 1;
            }
        }
        fclose(arquivo);
    }
}

void gravarArquivo(const char* fileName, int n, int array[])
{
    FILE* arquivo = fopen(fileName, "wt");
    if (arquivo != NULL)
    {
        fprintf(arquivo, "%d\n", n);
        int i = 0;
        while (i < n)
        {
            fprintf(arquivo, "%d\n", array[i]);
            i = i + 1;
        }
        fclose(arquivo);
    }
}

// Metodo 0811
void lerImpares(int* n, int arranjo[])
{
    int tamanho = 0;
    printf("Digite o tamanho do arranjo (positivo): ");
    scanf("%d", &tamanho);

    if (tamanho <= 0)
    {
        printf("\nERRO: Tamanho invalido ou nulo.\n");
        *n = 0;
    }
    else
    {
        *n = tamanho;
        int i = 0;
        int valor = 0;
        while (i < *n)
        {
            printf("Digite um valor positivo e impar para [%d]: ", i);
            scanf("%d", &valor);
            if (valor > 0 && valor % 2 != 0)
            {
                arranjo[i] = valor;
                i = i + 1;
            }
            else
            {
                printf("Valor invalido! Deve ser positivo e impar.\n");
            }
        }
    }
}

void method_0811(void)
{
    int n = 0;
    int arranjo[100];
    lerImpares(&n, arranjo);
    if (n > 0)
    {
        printf("\nArranjo com valores positivos e impares lido:\n");
        printArray(n, arranjo);
    }
}

// Metodo 0812
void gravarParesPositivos(int n, int array[], const char* outFile)
{
    gravarArquivo(outFile, n, array);
}

void method_0812(void)
{
    char nomeEntrada[100];
    char nomeSaida[100];
    printf("Nome do arquivo de entrada: ");
    scanf("%s", nomeEntrada);
    printf("Nome do arquivo de saida: ");
    scanf("%s", nomeSaida);

    FILE* arq = fopen(nomeEntrada, "rt");
    if (arq == NULL)
    {
        printf("ERRO: Nao foi possivel abrir o arquivo de entrada.\n");
    }
    else
    {
        int totalOriginal = 0;
        fscanf(arq, "%d", &totalOriginal);

        int filtrados[100];
        int cont = 0;
        int valor = 0;
        int lidos = 0;

        while (!feof(arq) && lidos < totalOriginal)
        {
            if (fscanf(arq, "%d", &valor) == 1)
            {
                // Descarta pares e negativos
                if (valor > 0 && valor % 2 != 0)
                {
                    filtrados[cont] = valor;
                    cont = cont + 1;
                }
                lidos = lidos + 1;
            }
        }
        fclose(arq);

        gravarParesPositivos(cont, filtrados, nomeSaida);
        printf("\nGravados %d valores positivos e impares em %s.\n", cont, nomeSaida);
        printArray(cont, filtrados);
    }
}

//Metodo 0813
int gerarInt(int inferior, int superior)
{
    // Intervalo aberto ]inferior, superior[
    int amplitude = (superior - inferior) - 1;
    if (amplitude <= 0) return inferior;
    return (inferior + 1) + (rand() % amplitude);
}

void method_0813(void)
{
    int inf = 0, sup = 0, n = 0;
    printf("Limite inferior do intervalo: ");
    scanf("%d", &inf);
    printf("Limite superior do intervalo: ");
    scanf("%d", &sup);
    printf("Quantidade de elementos (N): ");
    scanf("%d", &n);

    if (sup - inf <= 1 || n <= 0)
    {
        printf("ERRO: Intervalo aberto vazio ou N invalido.\n");
    }
    else
    {
        int array[n];
        int i = 0;
        while (i < n)
        {
            array[i] = gerarInt(inf, sup);
            i = i + 1;
        }
        gravarArquivo("DADOS.TXT", n, array);
        printf("\nDados aleatorios gerados e gravados em DADOS.TXT:\n");
        printArray(n, array);
    }
}

//Metodo 0814
int acharMenorImpar(int n, int array[])
{
    int menor = 1;
    bool achou = false;
    int i = 0;

    // Buscar primeira referencia impar
    while (i < n && !achou)
    {
        if (array[i] % 2 != 0)
        {
            menor = array[i];
            achou = true;
        }
        i = i + 1;
    }

    // Se achou uma referencia, procurar se existe outro menor
    while (i < n)
    {
        if (array[i] % 2 != 0 && array[i] < menor)
        {
            menor = array[i];
        }
        i = i + 1;
    }

    return menor;
}

void method_0814(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio ou invalido.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        printf("Dados lidos de DADOS.TXT:\n");
        printArray(n, array);

        int menor = acharMenorImpar(n, array);
        printf("\nMenor valor impar: %d\n", menor);
    }
}

//Metodo 0815
int acharMaiorParNaoDivisivelPorTres(int n, int array[])
{
    int maior = 0;
    bool achou = false;
    int i = 0;

    while (i < n && !achou)
    {
        if (array[i] % 2 == 0 && array[i] % 3 != 0)
        {
            maior = array[i];
            achou = true;
        }
        i = i + 1;
    }

    while (i < n)
    {
        if (array[i] % 2 == 0 && array[i] % 3 != 0 && array[i] > maior)
        {
            maior = array[i];
        }
        i = i + 1;
    }

    return maior;
}

void method_0815(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio ou inexistente.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        printf("Dados lidos:\n");
        printArray(n, array);

        int maior = acharMaiorParNaoDivisivelPorTres(n, array);
        printf("\nMaior valor par nao divisivel por 3: %d\n", maior);
    }
}

//Metodo 0816
double acharMedia(int n, int array[])
{
    if (n <= 0) return 0.0;
    double soma = 0.0;
    int i = 0;
    while (i < n)
    {
        soma = soma + array[i];
        i = i + 1;
    }
    return soma / n;
}

void method_0816(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio ou invalido.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        double media = acharMedia(n, array);
        printf("Media calculada: %.2f\n", media);

        int menoresIguais[n];
        int maiores[n];
        int cMenor = 0;
        int cMaior = 0;
        int i = 0;

        while (i < n)
        {
            if (array[i] <= media)
            {
                menoresIguais[cMenor] = array[i];
                cMenor = cMenor + 1;
            }
            else
            {
                maiores[cMaior] = array[i];
                cMaior = cMaior + 1;
            }
            i = i + 1;
        }

        gravarArquivo("MENORES.TXT", cMenor, menoresIguais);
        gravarArquivo("MAIORES.TXT", cMaior, maiores);
        printf("Dados separados em MENORES.TXT (%d itens) e MAIORES.TXT (%d itens).\n", cMenor, cMaior);
    }
}

//Metodo 0817
bool decrescente(int n, int array[])
{
    bool ordenado = true;
    int i = 0;
    while (i < n - 1 && ordenado)
    {
        if (array[i] < array[i + 1])
        {
            ordenado = false;
        }
        i = i + 1;
    }
    return ordenado;
}

void method_0817(void)
{
    int teste1[] = { 10, 8, 5, 2, 1 };
    int teste2[] = { 10, 5, 8, 2, 1 };

    printf("Teste 1:\n");
    printArray(5, teste1);
    printf("Decrescente: %s\n\n", decrescente(5, teste1) ? "SIM" : "NAO");

    printf("Teste 2:\n");
    printArray(5, teste2);
    printf("Decrescente: %s\n", decrescente(5, teste2) ? "SIM" : "NAO");
}

//Metodo 0818
bool acharValor(int procurado, int inicio, int n, int array[])
{
    bool existe = false;
    int i = inicio;
    while (i < n && !existe)
    {
        if (array[i] == procurado)
        {
            existe = true;
        }
        i = i + 1;
    }
    return existe;
}

void method_0818(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        int procurado = 0;
        int posInicio = 0;
        printf("Valor a procurar: ");
        scanf("%d", &procurado);
        printf("Posicao inicial de busca (0 a %d): ", n - 1);
        scanf("%d", &posInicio);

        bool achou = acharValor(procurado, posInicio, n, array);
        printf("O valor %d %s a partir da posicao %d.\n",
               procurado, achou ? "EXISTE" : "NAO EXISTE", posInicio);
    }
}

//Metodo 0819
int acharPosicao(int procurado, int inicio, int n, int array[])
{
    int posicao = -1;
    int i = inicio;
    while (i < n && posicao == -1)
    {
        if (array[i] == procurado)
        {
            posicao = i;
        }
        i = i + 1;
    }
    return posicao;
}

void method_0819(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        int procurado = 0;
        int posInicio = 0;
        printf("Valor a procurar: ");
        scanf("%d", &procurado);
        printf("Posicao inicial (0 a %d): ", n - 1);
        scanf("%d", &posInicio);

        int pos = acharPosicao(procurado, posInicio, n, array);
        if (pos != -1)
        {
            printf("Valor %d encontrado no indice: %d\n", procurado, pos);
        }
        else
        {
            printf("Valor %d nao encontrado.\n", procurado);
        }
    }
}

//Metodo 0820
int acharQuantos(int procurado, int inicio, int n, int array[])
{
    int count = 0;
    int i = inicio;
    while (i < n)
    {
        if (array[i] == procurado)
        {
            count = count + 1;
        }
        i = i + 1;
    }
    return count;
}

void method_0820(void)
{
    int n = lerArquivoTamanho("DADOS.TXT");
    if (n <= 0)
    {
        printf("ERRO: DADOS.TXT vazio.\n");
    }
    else
    {
        int array[n];
        lerArquivoDados("DADOS.TXT", n, array);
        int procurado = 0;
        int posInicio = 0;
        printf("Valor a procurar: ");
        scanf("%d", &procurado);
        printf("Posicao inicial (0 a %d): ", n - 1);
        scanf("%d", &posInicio);

        int total = acharQuantos(procurado, posInicio, n, array);
        printf("O valor %d aparece %d vez(es) a partir da posicao %d.\n", procurado, total, posInicio);
    }
}

//Metodo 07E1
int obterDivisoresImpares(int numero, int divisores[])
{
    if (numero < 0) numero = -numero;
    int cont = 0;
    int divisor = 1;

    while (divisor <= numero)
    {
        if (numero % divisor == 0 && divisor % 2 != 0)
        {
            divisores[cont] = divisor;
            cont = cont + 1;
        }
        divisor = divisor + 1;
    }
    return cont;
}

void method_08E1(void)
{
    int num = 0;
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    int maxTamanho = (num < 0) ? -num : num;
    if (maxTamanho == 0) maxTamanho = 1;

    int divisores[maxTamanho];
    int qtd = obterDivisoresImpares(num, divisores);

    printf("\nDivisores impares de %d:\n", num);
    printArray(qtd, divisores);

    gravarArquivo("DIVISORES.TXT", qtd, divisores);
    printf("Gravado em DIVISORES.TXT.\n");
}

//Metodo 08E2
int filtrarPalavras(const char* fileName, char resultado[10][100])
{
    FILE* arq = fopen(fileName, "rt");
    int count = 0;

    if (arq != NULL)
    {
        char buffer[100];
        while (!feof(arq) && count < 10)
        {
            if (fscanf(arq, "%99s", buffer) == 1)
            {
                int len = strlen(buffer);
                if (len > 0)
                {
                    char prim = buffer[0];
                    char ult = buffer[len - 1];

                    bool comecaS = (prim == 's' || prim == 'S');
                    bool terminaS = (ult == 's' || ult == 'S');

                    // Regra: Nao comecar NEM terminar com 's'/'S'
                    if (!comecaS && !terminaS)
                    {
                        strcpy(resultado[count], buffer);
                        count = count + 1;
                    }
                }
            }
        }
        fclose(arq);
    }
    return count;
}

void method_08E2(void)
{
    char palavras[10][100];
    int total = filtrarPalavras("PALAVRAS.TXT", palavras);

    if (total == 0)
    {
        printf("Nenhuma palavra compativel encontrada ou arquivo PALAVRAS.TXT inexistente.\n");
    }
    else
    {
        printf("As %d primeiras palavras que nao comecam e nem terminam com 's'/'S':\n", total);
        int i = 0;
        while (i < total)
        {
            printf("%2d: %s\n", i, palavras[i]);
            i = i + 1;
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
            case 0:
            printf ( "\nPrograma finalizado.\n" ); break;
            case 1:  method_0811 ( ); break;
            case 2:  method_0812 ( ); break;
            case 3:  method_0813 ( ); break;
            case 4:  method_0814 ( ); break;
            case 5:  method_0815 ( ); break;
            case 6:  method_0816 ( ); break;
            case 7:  method_0817 ( ); break;
            case 8:  method_0818 ( ); break;
            case 9:  method_0819 ( ); break;
            case 10: method_0820 ( ); break;
            case 11: method_08E1 ( ); break;
            case 12: method_08E2 ( ); break;

            default:
            printf ( "\nOpcao invalida!\n" );
            pause ( "Aperte ENTER para continuar." );
            break;
        }
    }
    while ( opcao != 0 );

    return ( 0 );
}
