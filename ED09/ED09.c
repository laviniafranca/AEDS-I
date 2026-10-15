/* Autora: Lavinia Franca da Silva */

#include "io.h"

// Mostrar arranjo bidimensional com valores inteiros
void printIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            printf ( "%3d\t", matrix[ x ][ y ] );
        }
        printf ( "\n" );
    }
}

// Ler arranjo bidimensional com valores inteiros
void readIntMatrix ( int rows, int columns, int matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    int z = 0;

    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            printf ( "%d, %d : ", x, y );
            scanf ( "%d", &z );
            matrix[ x ][ y ] = z;
        }
    }
}

// Gravar arranjo bidimensional com valores inteiros em arquivo
void fprintIntMatrix ( const char *fileName, int rows, int columns, int matrix[ ][columns] )
{
    FILE* arquivo = fopen ( fileName, "w" );
    int x = 0;
    int y = 0;

    if ( arquivo == NULL )
    {
        printf ( "\nERRO: Nao foi possivel abrir o arquivo para gravacao.\n" );
    }
    else
    {
        fprintf ( arquivo, "%d\n", rows );
        fprintf ( arquivo, "%d\n", columns );

        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                fprintf ( arquivo, "%d\n", matrix[ x ][ y ] );
            }
        }
        fclose ( arquivo );
    }
}

// Ler tamanho (linhas) da matriz do arquivo
int freadMatrixRows ( const char *fileName )
{
    int n = 0;
    FILE* arquivo = fopen ( fileName, "r" );
    if ( arquivo != NULL )
    {
        fscanf ( arquivo, "%d", &n );
        if ( n <= 0 )
        {
            printf ( "ERRO: Valor invalido.\n" );
            n = 0;
        }
        fclose ( arquivo );
    }
    return ( n );
}

// Ler tamanho (colunas) da matriz do arquivo
int freadMatrixColumns ( const char *fileName )
{
    int n = 0;
    FILE* arquivo = fopen ( fileName, "r" );
    if ( arquivo != NULL )
    {
        fscanf ( arquivo, "%d", &n ); // Pula linhas
        fscanf ( arquivo, "%d", &n ); // Le colunas
        if ( n <= 0 )
        {
            printf ( "ERRO: Valor invalido.\n" );
            n = 0;
        }
        fclose ( arquivo );
    }
    return ( n );
}

// Ler matriz inteira de arquivo
void freadIntMatrix ( const char *fileName, int rows, int columns, int matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    int z = 0;
    FILE* arquivo = fopen ( fileName, "r" );

    if ( arquivo == NULL )
    {
        printf ( "ERRO: Nao foi possivel abrir o arquivo para leitura.\n" );
    }
    else
    {
        fscanf ( arquivo, "%d", &x );
        fscanf ( arquivo, "%d", &y );

        if ( rows <= 0 || rows > x || columns <= 0 || columns > y )
        {
            printf ( "ERRO: Dimensoes incompativeis com o arquivo.\n" );
        }
        else
        {
            x = 0;
            while ( !feof(arquivo) && x < rows )
            {
                y = 0;
                while ( !feof(arquivo) && y < columns )
                {
                    if ( fscanf ( arquivo, "%d", &z ) == 1 )
                    {
                        matrix[ x ][ y ] = z;
                    }
                    y = y + 1;
                }
                x = x + 1;
            }
        }
        fclose ( arquivo );
    }
}

// Copiar matriz com valores inteiros
void copyIntMatrix ( int rows, int columns, int matrix2[ ][columns], int matrix1[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 )
    {
        printf ( "ERRO: Valor invalido.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                matrix2[ x ][ y ] = matrix1[ x ][ y ];
            }
        }
    }
}

// Transpor matriz de inteiros
void transposeIntMatrix ( int rows, int columns, int matrix2[ ][rows], int matrix1[ ][columns] )
{
    int x = 0;
    int y = 0;
    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            matrix2[ y ][ x ] = matrix1[ x ][ y ];
        }
    }
}

// Testar se a matriz eh identidade
bool isIdentity ( int rows, int columns, int matrix[ ][columns] )
{
    bool result = false;
    int x = 0;
    int y = 0;

    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "\nERRO: Valor invalido.\n" );
    }
    else
    {
        x = 0;
        result = true;
        while ( x < rows && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                if ( x == y )
                {
                    result = result && ( matrix[ x ][ y ] == 1 );
                }
                else
                {
                    result = result && ( matrix[ x ][ y ] == 0 );
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }
    return ( result );
}

// Testar igualdade entre matrizes inteiras
bool isEqual ( int rows, int columns, int matrix1[ ][columns], int matrix2[ ][columns] )
{
    bool result = true;
    int x = 0;
    int y = 0;

    while ( x < rows && result )
    {
        y = 0;
        while ( y < columns && result )
        {
            result = result && ( matrix1[ x ][ y ] == matrix2[ x ][ y ] );
            y = y + 1;
        }
        x = x + 1;
    }
    return ( result );
}

// Somar matrizes: matrix3 = matrix1 + k * matrix2
void addIntMatrix ( int rows, int columns, int matrix3[ ][columns],
                    int matrix1[ ][columns], int k, int matrix2[ ][columns] )
{
    int x = 0;
    int y = 0;
    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            matrix3[ x ][ y ] = matrix1[ x ][ y ] + k * matrix2[ x ][ y ];
        }
    }
}

// Multiplicar matrizes de inteiros
void mulIntMatrix ( int rows3, int columns3, int matrix3[ ][columns3],
                    int rows1, int columns1, int matrix1[ ][columns1],
                    int rows2, int columns2, int matrix2[ ][columns2] )
{
    int x = 0, y = 0, z = 0, soma = 0;
    if ( rows1 <= 0 || columns1 <= 0 || rows2 <= 0 || columns2 <= 0 ||
         rows3 <= 0 || columns3 <= 0 || columns1 != rows2 ||
         rows1 != rows3 || columns2 != columns3 )
    {
        printf ( "\nERRO: Dimensoes incompativeis para multiplicacao.\n" );
    }
    else
    {
        for ( x = 0; x < rows3; x = x + 1 )
        {
            for ( y = 0; y < columns3; y = y + 1 )
            {
                soma = 0;
                for ( z = 0; z < columns1; z = z + 1 )
                {
                    soma = soma + matrix1[ x ][ z ] * matrix2[ z ][ y ];
                }
                matrix3[ x ][ y ] = soma;
            }
        }
    }
}


// Ler matriz de double com valores >= 0
void readPositiveDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    double valor = 0.0;
    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            do
            {
                printf ( "[%d][%d] = ", x, y );
                scanf ( "%lf", &valor );
                if ( valor < 0.0 )
                {
                    printf ( "ERRO: Digite apenas valores nao negativos (>= 0).\n" );
                }
            }
            while ( valor < 0.0 );
            matrix[ x ][ y ] = valor;
        }
    }
}

void printDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            printf ( "%6.2lf\t", matrix[ x ][ y ] );
        }
        printf ( "\n" );
    }
}

void method_0911 ( )
{
    int rows = 0, columns = 0;
    printf ( "Quantidade de linhas: " );
    scanf ( "%d", &rows );
    printf ( "Quantidade de colunas: " );
    scanf ( "%d", &columns );

    if ( rows <= 0 || columns <= 0 || rows > 10 || columns > 10 )
    {
        printf ( "ERRO: Dimensoes invalidas (permitido entre 1 e 10).\n" );
    }
    else
    {
        double matrix[ rows ][ columns ];
        readPositiveDoubleMatrix ( rows, columns, matrix );
        printf ( "\nMatriz lida:\n" );
        printDoubleMatrix ( rows, columns, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Gravar e Ler matriz de double em arquivo
void fprintDoubleMatrix ( const char *fileName, int rows, int columns, double matrix[ ][columns] )
{
    FILE* arquivo = fopen ( fileName, "w" );
    int x = 0;
    int y = 0;
    if ( arquivo == NULL )
    {
        printf ( "ERRO: Nao foi possivel abrir o arquivo para escrita.\n" );
    }
    else
    {
        fprintf ( arquivo, "%d\n", rows );
        fprintf ( arquivo, "%d\n", columns );
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                fprintf ( arquivo, "%lf\n", matrix[ x ][ y ] );
            }
        }
        fclose ( arquivo );
    }
}

void freadDoubleMatrix ( const char *fileName, int rows, int columns, double matrix[ ][columns] )
{
    FILE* arquivo = fopen ( fileName, "r" );
    int r = 0, c = 0;
    int x = 0, y = 0;
    double valor = 0.0;

    if ( arquivo == NULL )
    {
        printf ( "ERRO: Arquivo nao encontrado.\n" );
    }
    else
    {
        fscanf ( arquivo, "%d", &r );
        fscanf ( arquivo, "%d", &c );
        if ( rows > r || columns > c )
        {
            printf ( "ERRO: Dimensoes incompativeis com o arquivo.\n" );
        }
        else
        {
            for ( x = 0; x < rows; x = x + 1 )
            {
                for ( y = 0; y < columns; y = y + 1 )
                {
                    if ( fscanf ( arquivo, "%lf", &valor ) == 1 )
                    {
                        matrix[ x ][ y ] = valor;
                    }
                }
            }
        }
        fclose ( arquivo );
    }
}

void method_0912 ( )
{
    int rows = 0, columns = 0;
    printf ( "Quantidade de linhas: " );
    scanf ( "%d", &rows );
    printf ( "Quantidade de colunas: " );
    scanf ( "%d", &columns );

    if ( rows <= 0 || columns <= 0 || rows > 10 || columns > 10 )
    {
        printf ( "ERRO: Dimensoes invalidas.\n" );
    }
    else
    {
        double matrix[ rows ][ columns ];
        double recuperada[ rows ][ columns ];

        readPositiveDoubleMatrix ( rows, columns, matrix );
        fprintDoubleMatrix ( "MATRIX_01.TXT", rows, columns, matrix );

        freadDoubleMatrix ( "MATRIX_01.TXT", rows, columns, recuperada );
        printf ( "\nMatriz lida e recuperada do arquivo MATRIX_01.TXT:\n" );
        printDoubleMatrix ( rows, columns, recuperada );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar diagonal principal (x == y)
void printDiagonalDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            printf ( "%6.2lf\t", matrix[ x ][ x ] );
        }
        printf ( "\n" );
    }
}

void method_0913 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nMatriz Completa:\n" );
        printDoubleMatrix ( n, n, matrix );
        printf ( "\nDiagonal Principal:\n" );
        printDiagonalDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar diagonal secundaria (y == columns - 1 - x)
void printSDiagonalDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            printf ( "%6.2lf\t", matrix[ x ][ columns - 1 - x ] );
        }
        printf ( "\n" );
    }
}

void method_0914 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nMatriz Completa:\n" );
        printDoubleMatrix ( n, n, matrix );
        printf ( "\nDiagonal Secundaria:\n" );
        printSDiagonalDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar valores abaixo da diagonal principal (x > y)
void printLDTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                if ( x > y )
                {
                    printf ( "%6.2lf\t", matrix[ x ][ y ] );
                }
                else
                {
                    printf ( "\t" );
                }
            }
            printf ( "\n" );
        }
    }
}

void method_0915 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nValores abaixo da diagonal principal:\n" );
        printLDTriangleDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar valores acima da diagonal principal (x < y)
void printLUTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                if ( x < y )
                {
                    printf ( "%6.2lf\t", matrix[ x ][ y ] );
                }
                else
                {
                    printf ( "\t" );
                }
            }
            printf ( "\n" );
        }
    }
}

void method_0916 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nValores acima da diagonal principal:\n" );
        printLUTriangleDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar valores abaixo e na diagonal secundaria (x + y >= rows - 1)
void printSLDTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                if ( x + y >= rows - 1 )
                {
                    printf ( "%6.2lf\t", matrix[ x ][ y ] );
                }
                else
                {
                    printf ( "\t" );
                }
            }
            printf ( "\n" );
        }
    }
}

void method_0917 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nValores abaixo e na diagonal secundaria:\n" );
        printSLDTriangleDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Mostrar valores acima e na diagonal secundaria (x + y <= rows - 1)
void printSLUTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
    }
    else
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            for ( y = 0; y < columns; y = y + 1 )
            {
                if ( x + y <= rows - 1 )
                {
                    printf ( "%6.2lf\t", matrix[ x ][ y ] );
                }
                else
                {
                    printf ( "\t" );
                }
            }
            printf ( "\n" );
        }
    }
}

void method_0918 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nValores acima e na diagonal secundaria:\n" );
        printSLUTriangleDoubleMatrix ( n, n, matrix );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Testar se sao todos zeros abaixo da diagonal principal (x > y)
bool allZerosLTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    bool result = true;
    int x = 0;
    int y = 0;

    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
        result = false;
    }
    else
    {
        x = 0;
        while ( x < rows && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                if ( x > y && matrix[ x ][ y ] != 0.0 )
                {
                    result = false;
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }
    return ( result );
}

void method_0919 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nMatriz:\n" );
        printDoubleMatrix ( n, n, matrix );

        bool result = allZerosLTriangleDoubleMatrix ( n, n, matrix );
        if ( result )
        {
            printf ( "\nResultado: TODOS os elementos abaixo da diagonal principal sao zeros.\n" );
        }
        else
        {
            printf ( "\nResultado: Existem elementos NAO-NULOS abaixo da diagonal principal.\n" );
        }
    }
    pause ( "Apertar ENTER para continuar" );
}

// Testar se NAO sao zeros os valores acima da diagonal principal (x < y)
bool allZerosUTriangleDoubleMatrix ( int rows, int columns, double matrix[ ][columns] )
{
    bool result = true;
    int x = 0;
    int y = 0;

    if ( rows <= 0 || columns <= 0 || rows != columns )
    {
        printf ( "ERRO: Matriz nao e quadrada ou dimensoes invalidas.\n" );
        result = false;
    }
    else
    {
        x = 0;
        while ( x < rows && result )
        {
            y = 0;
            while ( y < columns && result )
            {
                if ( x < y && matrix[ x ][ y ] == 0.0 )
                {
                    result = false;
                }
                y = y + 1;
            }
            x = x + 1;
        }
    }
    return ( result );
}

void method_0920 ( )
{
    int n = 0;
    printf ( "Dimensao da matriz quadrada (n): " );
    scanf ( "%d", &n );

    if ( n <= 0 || n > 10 )
    {
        printf ( "ERRO: Dimensao invalida.\n" );
    }
    else
    {
        double matrix[ n ][ n ];
        readPositiveDoubleMatrix ( n, n, matrix );
        printf ( "\nMatriz:\n" );
        printDoubleMatrix ( n, n, matrix );

        bool result = allZerosUTriangleDoubleMatrix ( n, n, matrix );
        if ( result )
        {
            printf ( "\nResultado: NAO ha zeros acima da diagonal principal (todos sao != 0).\n" );
        }
        else
        {
            printf ( "\nResultado: Ha pelo menos um zero acima da diagonal principal.\n" );
        }
    }
    pause ( "Apertar ENTER para continuar" );
}

// Preencher por colunas
void fillMatrixColumnMajor ( int rows, int columns, int matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    int count = 1;

    for ( y = 0; y < columns; y = y + 1 )
    {
        for ( x = 0; x < rows; x = x + 1 )
        {
            matrix[ x ][ y ] = count;
            count = count + 1;
        }
    }
}

void method_09E1 ( )
{
    int rows = 0, columns = 0;
    printf ( "Quantidade de linhas: " );
    scanf ( "%d", &rows );
    printf ( "Quantidade de colunas: " );
    scanf ( "%d", &columns );

    if ( rows <= 0 || columns <= 0 || rows > 10 || columns > 10 )
    {
        printf ( "ERRO: Dimensoes invalidas.\n" );
    }
    else
    {
        int matrix[ rows ][ columns ];
        fillMatrixColumnMajor ( rows, columns, matrix );

        printf ( "\nMatriz gerada por colunas:\n" );
        printIntMatrix ( rows, columns, matrix );

        fprintIntMatrix ( "MATRIZ_E1.TXT", rows, columns, matrix );
        printf ( "\nMatriz gravada com sucesso em MATRIZ_E1.TXT.\n" );
    }
    pause ( "Apertar ENTER para continuar" );
}

// Preencher decrescente por linhas a partir de rows * columns ate 1
void fillMatrixDescending ( int rows, int columns, int matrix[ ][columns] )
{
    int x = 0;
    int y = 0;
    int count = rows * columns;

    for ( x = 0; x < rows; x = x + 1 )
    {
        for ( y = 0; y < columns; y = y + 1 )
        {
            matrix[ x ][ y ] = count;
            count = count - 1;
        }
    }
}

void method_09E2 ( )
{
    int rows = 0, columns = 0;
    printf ( "Quantidade de linhas: " );
    scanf ( "%d", &rows );
    printf ( "Quantidade de colunas: " );
    scanf ( "%d", &columns );

    if ( rows <= 0 || columns <= 0 || rows > 10 || columns > 10 )
    {
        printf ( "ERRO: Dimensoes invalidas.\n" );
    }
    else
    {
        int matrix[ rows ][ columns ];
        fillMatrixDescending ( rows, columns, matrix );

        printf ( "\nMatriz gerada em ordem decrescente:\n" );
        printIntMatrix ( rows, columns, matrix );

        fprintIntMatrix ( "MATRIZ_E2.TXT", rows, columns, matrix );
        printf ( "\nMatriz gravada com sucesso em MATRIZ_E2.TXT.\n" );
    }
    pause ( "Apertar ENTER para continuar" );
}

int main ( void ) {
    int opcao = 0;
    printf ( "%s\n", "935146 - AED1" );
    printf ( "\n" );
    do {
        opcao = readint ( "Qual a opcao? " );
        printf ( "%s%d\n", "Opcao =", opcao );
        switch ( opcao ) {
            case 0:
            printf ( "\nPrograma finalizado.\n" ); break;
            case 1:  method_0911 ( ); break;
            case 2:  method_0912 ( ); break;
            case 3:  method_0913 ( ); break;
            case 4:  method_0914 ( ); break;
            case 5:  method_0915 ( ); break;
            case 6:  method_0916 ( ); break;
            case 7:  method_0917 ( ); break;
            case 8:  method_0918 ( ); break;
            case 9:  method_0919 ( ); break;
            case 10: method_0920 ( ); break;
            case 11: method_09E1 ( ); break;
            case 12: method_09E2 ( ); break;

            default:
            printf ( "\nOpcao invalida!\n" );
            pause ( "Aperte ENTER para continuar." );
            break;
        }
    }
    while ( opcao != 0 );

    return ( 0 );
}
