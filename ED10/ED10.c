/* Autora: Lavinia Franca da Silva */

#include "io.h"

//Definicoes de tipos
typedef int* ints;

typedef struct s_int_Array
{
    int length;
    ints data;
    int ix;
} int_Array;

typedef int_Array* ref_int_Array;

typedef struct s_int_Matrix
{
    int rows;
    int columns;
    ints* data;
    int ix, iy;
} int_Matrix;

typedef int_Matrix* ref_int_Matrix;

//Funcoes de gerenciamento de memoria e utilitarios
ref_int_Array new_int_Array(int n)
{
    ref_int_Array tmp = (ref_int_Array) malloc(sizeof(int_Array));
    if (tmp == NULL)
    {
        printf("\nERRO: Falta espaco para descritor de arranjo.\n");
    }
    else
    {
        tmp->length = 0;
        tmp->data = NULL;
        tmp->ix = -1;
        if (n > 0)
        {
            tmp->length = n;
            tmp->data = (ints) malloc(n * sizeof(int));
            if (tmp->data == NULL)
            {
                printf("\nERRO: Falta espaco para dados do arranjo.\n");
                tmp->length = 0;
            }
            else
            {
                tmp->ix = 0;
            }
        }
    }
    return tmp;
}

void free_int_Array(ref_int_Array tmp)
{
    if (tmp != NULL)
    {
        if (tmp->data != NULL)
        {
            free(tmp->data);
        }
        free(tmp);
    }
}

ref_int_Matrix new_int_Matrix(int rows, int columns)
{
    ref_int_Matrix tmp = (ref_int_Matrix) malloc(sizeof(int_Matrix));
    if (tmp == NULL)
    {
        printf("\nERRO: Falta espaco para descritor de matriz.\n");
    }
    else
    {
        tmp->rows = 0;
        tmp->columns = 0;
        tmp->data = NULL;
        tmp->ix = 0;
        tmp->iy = 0;
        if (rows > 0 && columns > 0)
        {
            tmp->rows = rows;
            tmp->columns = columns;
            tmp->data = (ints*) malloc(rows * sizeof(ints));
            if (tmp->data == NULL)
            {
                printf("\nERRO: Falta espaco para linhas da matriz.\n");
                tmp->rows = 0;
                tmp->columns = 0;
            }
            else
            {
                for (tmp->ix = 0; tmp->ix < rows; tmp->ix = tmp->ix + 1)
                {
                    tmp->data[tmp->ix] = (ints) malloc(columns * sizeof(int));
                }
            }
        }
    }
    return tmp;
}

void free_int_Matrix(ref_int_Matrix tmp)
{
    if (tmp != NULL)
    {
        if (tmp->data != NULL)
        {
            for (tmp->ix = 0; tmp->ix < tmp->rows; tmp->ix = tmp->ix + 1)
            {
                if (tmp->data[tmp->ix] != NULL)
                {
                    free(tmp->data[tmp->ix]);
                }
            }
            free(tmp->data);
        }
        free(tmp);
    }
}

void printIntArray(int_Array array)
{
    if (array.data != NULL && array.length > 0)
    {
        for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
        {
            printf("%2d: %d\n", array.ix, array.data[array.ix]);
        }
    }
    else
    {
        printf("\nArranjo vazio ou nulo.\n");
    }
}

void printIntMatrix(ref_int_Matrix matrix)
{
    if (matrix != NULL && matrix->data != NULL)
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
            {
                printf("%4d\t", matrix->data[matrix->ix][matrix->iy]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("\nMatriz vazia ou nula.\n");
    }
}

ref_int_Array readArrayFromFile(const char* fileName)
{
    ref_int_Array array = NULL;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo %s para leitura.\n", fileName);
    }
    else
    {
        int n = 0;
        if (fscanf(arquivo, "%d", &n) == 1 && n > 0)
        {
            array = new_int_Array(n);
            if (array != NULL && array->data != NULL)
            {
                for (array->ix = 0; array->ix < array->length; array->ix = array->ix + 1)
                {
                    fscanf(arquivo, "%d", &(array->data[array->ix]));
                }
            }
        }
        else
        {
            printf("\nERRO: Tamanho invalido no arquivo %s.\n", fileName);
        }
        fclose(arquivo);
    }
    return array;
}

void fprintIntArray(const char* fileName, int_Array array)
{
    FILE* arquivo = fopen(fileName, "wt");
    if (arquivo == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo %s para escrita.\n", fileName);
    }
    else
    {
        fprintf(arquivo, "%d\n", array.length);
        if (array.data != NULL)
        {
            for (array.ix = 0; array.ix < array.length; array.ix = array.ix + 1)
            {
                fprintf(arquivo, "%d\n", array.data[array.ix]);
            }
        }
        fclose(arquivo);
    }
}

ref_int_Matrix readMatrixFromFile(const char* fileName)
{
    ref_int_Matrix matrix = NULL;
    FILE* arquivo = fopen(fileName, "rt");
    if (arquivo == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo %s para leitura.\n", fileName);
    }
    else
    {
        int rows = 0, cols = 0;
        if (fscanf(arquivo, "%d", &rows) == 1 && fscanf(arquivo, "%d", &cols) == 1 && rows > 0 && cols > 0)
        {
            matrix = new_int_Matrix(rows, cols);
            if (matrix != NULL && matrix->data != NULL)
            {
                for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
                {
                    for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                    {
                        fscanf(arquivo, "%d", &(matrix->data[matrix->ix][matrix->iy]));
                    }
                }
            }
        }
        else
        {
            printf("\nERRO: Dimensoes invalidas no arquivo %s.\n", fileName);
        }
        fclose(arquivo);
    }
    return matrix;
}

void fprintIntMatrix(const char* fileName, ref_int_Matrix matrix)
{
    FILE* arquivo = fopen(fileName, "wt");
    if (arquivo == NULL)
    {
        printf("\nERRO: Nao foi possivel abrir o arquivo %s para escrita.\n", fileName);
    }
    else
    {
        if (matrix == NULL || matrix->data == NULL)
        {
            printf("\nERRO: Matriz invalida para gravacao.\n");
        }
        else
        {
            fprintf(arquivo, "%d\n", matrix->rows);
            fprintf(arquivo, "%d\n", matrix->columns);
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    fprintf(arquivo, "%d\n", matrix->data[matrix->ix][matrix->iy]);
                }
            }
        }
        fclose(arquivo);
    }
}

//Metodo 1011
int RandomIntGenerate(int inferior, int superior)
{
    int valor = 0;
    if (inferior > superior)
    {
        int temp = inferior;
        inferior = superior;
        superior = temp;
    }
    int amplitude = (superior - inferior + 1);
    valor = inferior + (rand() % amplitude);
    if (valor > 1000000)
    {
        valor = 1000000;
    }
    return valor;
}

void method_1011(void)
{
    int inferior = 0, superior = 0, n = 0;
    printf("Limite inferior: ");
    scanf("%d", &inferior);
    printf("Limite superior: ");
    scanf("%d", &superior);
    printf("Quantidade de elementos (N): ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("\nERRO: Quantidade deve ser positiva.\n");
    }
    else
    {
        ref_int_Array arranjo = new_int_Array(n);
        if (arranjo != NULL && arranjo->data != NULL)
        {
            for (arranjo->ix = 0; arranjo->ix < arranjo->length; arranjo->ix = arranjo->ix + 1)
            {
                arranjo->data[arranjo->ix] = RandomIntGenerate(inferior, superior);
            }
            fprintIntArray("DADOS.TXT", *arranjo);
            printf("\nValores gerados e gravados em DADOS.TXT com sucesso:\n");
            printIntArray(*arranjo);
            free_int_Array(arranjo);
        }
    }
}

//Metodo 1012
bool arraySearch(int valor, int_Array array)
{
    bool encontrado = false;
    if (array.data == NULL || array.length <= 0)
    {
        printf("\nERRO: Arranjo invalido para busca.\n");
    }
    else
    {
        for (array.ix = 0; array.ix < array.length && !encontrado; array.ix = array.ix + 1)
        {
            if (array.data[array.ix] == valor)
            {
                encontrado = true;
            }
        }
    }
    return encontrado;
}

void method_1012(void)
{
    ref_int_Array arranjo = readArrayFromFile("DADOS.TXT");
    if (arranjo != NULL)
    {
        int valor = 0;
        printf("Valor a procurar: ");
        scanf("%d", &valor);
        bool resposta = arraySearch(valor, *arranjo);
        if (resposta)
        {
            printf("\nResultado: O valor %d FOI encontrado no arranjo.\n", valor);
        }
        else
        {
            printf("\nResultado: O valor %d NAO foi encontrado no arranjo.\n", valor);
        }
        free_int_Array(arranjo);
    }
}

//Metodo 1013
bool arrayCompare(int_Array a1, int_Array a2)
{
    bool iguais = true;
    if (a1.length != a2.length || a1.data == NULL || a2.data == NULL)
    {
        iguais = false;
    }
    else
    {
        for (a1.ix = 0; a1.ix < a1.length && iguais; a1.ix = a1.ix + 1)
        {
            if (a1.data[a1.ix] != a2.data[a1.ix])
            {
                iguais = false;
            }
        }
    }
    return iguais;
}

void method_1013(void)
{
    ref_int_Array a1 = readArrayFromFile("DADOS1.TXT");
    ref_int_Array a2 = readArrayFromFile("DADOS2.TXT");
    if (a1 != NULL && a2 != NULL)
    {
        bool resposta = arrayCompare(*a1, *a2);
        if (resposta)
        {
            printf("\nResultado: Os arranjos sao IGUAIS.\n");
        }
        else
        {
            printf("\nResultado: Os arranjos sao DIFERENTES.\n");
        }
    }
    else
    {
        printf("\nERRO: Nao foi possivel carregar ambos os arquivos (DADOS1.TXT e DADOS2.TXT).\n");
    }
    free_int_Array(a1);
    free_int_Array(a2);
}

//Metodo 1014
ref_int_Array arrayAdd(int_Array a1, int k, int_Array a2)
{
    ref_int_Array soma = NULL;
    if (a1.length != a2.length || a1.data == NULL || a2.data == NULL || a1.length <= 0)
    {
        printf("\nERRO: Arranjos de tamanhos incompativeis ou nulos.\n");
    }
    else
    {
        soma = new_int_Array(a1.length);
        if (soma != NULL && soma->data != NULL)
        {
            for (soma->ix = 0; soma->ix < soma->length; soma->ix = soma->ix + 1)
            {
                soma->data[soma->ix] = a1.data[soma->ix] + (k * a2.data[soma->ix]);
            }
        }
    }
    return soma;
}

void method_1014(void)
{
    ref_int_Array a1 = readArrayFromFile("DADOS1.TXT");
    ref_int_Array a2 = readArrayFromFile("DADOS2.TXT");
    if (a1 != NULL && a2 != NULL)
    {
        int k = 0;
        printf("Constante multiplicadora (k): ");
        scanf("%d", &k);
        ref_int_Array soma = arrayAdd(*a1, k, *a2);
        if (soma != NULL)
        {
            printf("\nResultado de a1 + (%d * a2):\n", k);
            printIntArray(*soma);
            free_int_Array(soma);
        }
    }
    free_int_Array(a1);
    free_int_Array(a2);
}

//Metodo 1015
bool isArrayDecrescent(int_Array array)
{
    bool decrescente = true;
    if (array.data == NULL || array.length <= 0)
    {
        printf("\nERRO: Arranjo sem dados validos.\n");
        decrescente = false;
    }
    else
    {
        for (array.ix = 0; array.ix < (array.length - 1) && decrescente; array.ix = array.ix + 1)
        {
            if (array.data[array.ix] <= array.data[array.ix + 1])
            {
                decrescente = false;
            }
        }
    }
    return decrescente;
}

void method_1015(void)
{
    ref_int_Array arranjo = readArrayFromFile("DADOS1.TXT");
    if (arranjo != NULL)
    {
        bool resposta = isArrayDecrescent(*arranjo);
        if (resposta)
        {
            printf("\nResultado: O arranjo ESTA em ordem decrescente.\n");
        }
        else
        {
            printf("\nResultado: O arranjo NAO esta em ordem decrescente.\n");
        }
        free_int_Array(arranjo);
    }
}

//Metodo 1016
ref_int_Matrix matrixTranspose(ref_int_Matrix matrix)
{
    ref_int_Matrix transposta = NULL;
    if (matrix == NULL || matrix->data == NULL || matrix->rows <= 0 || matrix->columns <= 0)
    {
        printf("\nERRO: Matriz invalida para transposicao.\n");
    }
    else
    {
        transposta = new_int_Matrix(matrix->columns, matrix->rows);
        if (transposta != NULL && transposta->data != NULL)
        {
            for (matrix->ix = 0; matrix->ix < matrix->rows; matrix->ix = matrix->ix + 1)
            {
                for (matrix->iy = 0; matrix->iy < matrix->columns; matrix->iy = matrix->iy + 1)
                {
                    transposta->data[matrix->iy][matrix->ix] = matrix->data[matrix->ix][matrix->iy];
                }
            }
        }
    }
    return transposta;
}

void method_1016(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    if (m1 != NULL)
    {
        ref_int_Matrix m2 = matrixTranspose(m1);
        if (m2 != NULL)
        {
            printf("\nMatriz Transposta:\n");
            printIntMatrix(m2);
            free_int_Matrix(m2);
        }
        free_int_Matrix(m1);
    }
}

//Metodo 1017
bool matrixZero(ref_int_Matrix matrix)
{
    bool soZeros = true;
    if (matrix == NULL || matrix->data == NULL || matrix->rows <= 0 || matrix->columns <= 0)
    {
        printf("\nERRO: Matriz nula ou invalida.\n");
        soZeros = false;
    }
    else
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows && soZeros; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns && soZeros; matrix->iy = matrix->iy + 1)
            {
                if (matrix->data[matrix->ix][matrix->iy] != 0)
                {
                    soZeros = false;
                }
            }
        }
    }
    return soZeros;
}

void method_1017(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    if (m1 != NULL)
    {
        bool resposta = matrixZero(m1);
        if (resposta)
        {
            printf("\nResultado: A matriz contem APENAS zeros.\n");
        }
        else
        {
            printf("\nResultado: A matriz CONTEM elementos diferentes de zero.\n");
        }
        free_int_Matrix(m1);
    }
}

//Metodo 1018
bool matrixCompare(ref_int_Matrix m1, ref_int_Matrix m2)
{
    bool iguais = true;
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        iguais = false;
    }
    else if (m1->rows != m2->rows || m1->columns != m2->columns)
    {
        iguais = false;
    }
    else
    {
        for (m1->ix = 0; m1->ix < m1->rows && iguais; m1->ix = m1->ix + 1)
        {
            for (m1->iy = 0; m1->iy < m1->columns && iguais; m1->iy = m1->iy + 1)
            {
                if (m1->data[m1->ix][m1->iy] != m2->data[m1->ix][m1->iy])
                {
                    iguais = false;
                }
            }
        }
    }
    return iguais;
}

void method_1018(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    ref_int_Matrix m2 = readMatrixFromFile("DADOS2.TXT");
    if (m1 != NULL && m2 != NULL)
    {
        bool resposta = matrixCompare(m1, m2);
        if (resposta)
        {
            printf("\nResultado: As matrizes sao IGUAIS.\n");
        }
        else
        {
            printf("\nResultado: As matrizes sao DIFERENTES.\n");
        }
    }
    free_int_Matrix(m1);
    free_int_Matrix(m2);
}

//Metodo 1019
ref_int_Matrix matrixAdd(ref_int_Matrix m1, int k, ref_int_Matrix m2)
{
    ref_int_Matrix soma = NULL;
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("\nERRO: Matrizes nulas.\n");
    }
    else if (m1->rows != m2->rows || m1->columns != m2->columns)
    {
        printf("\nERRO: Dimensoes incompativeis para soma.\n");
    }
    else
    {
        soma = new_int_Matrix(m1->rows, m1->columns);
        if (soma != NULL && soma->data != NULL)
        {
            for (soma->ix = 0; soma->ix < soma->rows; soma->ix = soma->ix + 1)
            {
                for (soma->iy = 0; soma->iy < soma->columns; soma->iy = soma->iy + 1)
                {
                    soma->data[soma->ix][soma->iy] = m1->data[soma->ix][soma->iy] + (k * m2->data[soma->ix][soma->iy]);
                }
            }
        }
    }
    return soma;
}

void method_1019(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    ref_int_Matrix m2 = readMatrixFromFile("DADOS2.TXT");
    if (m1 != NULL && m2 != NULL)
    {
        int k = 0;
        printf("Constante multiplicadora (k): ");
        scanf("%d", &k);
        ref_int_Matrix soma = matrixAdd(m1, k, m2);
        if (soma != NULL)
        {
            printf("\nResultado da soma m1 + (%d * m2):\n", k);
            printIntMatrix(soma);
            free_int_Matrix(soma);
        }
    }
    free_int_Matrix(m1);
    free_int_Matrix(m2);
}

//Metodo 1020
ref_int_Matrix matrixProduct(ref_int_Matrix m1, ref_int_Matrix m2)
{
    ref_int_Matrix prod = NULL;
    if (m1 == NULL || m2 == NULL || m1->data == NULL || m2->data == NULL)
    {
        printf("\nERRO: Matrizes nulas.\n");
    }
    else if (m1->columns != m2->rows)
    {
        printf("\nERRO: Incompatibilidade de dimensoes: colunas de m1 (%d) != linhas de m2 (%d).\n", m1->columns, m2->rows);
    }
    else
    {
        prod = new_int_Matrix(m1->rows, m2->columns);
        if (prod != NULL && prod->data != NULL)
        {
            for (prod->ix = 0; prod->ix < prod->rows; prod->ix = prod->ix + 1)
            {
                for (prod->iy = 0; prod->iy < prod->columns; prod->iy = prod->iy + 1)
                {
                    prod->data[prod->ix][prod->iy] = 0;
                    for (int k = 0; k < m1->columns; k = k + 1)
                    {
                        prod->data[prod->ix][prod->iy] = prod->data[prod->ix][prod->iy] + (m1->data[prod->ix][k] * m2->data[k][prod->iy]);
                    }
                }
            }
        }
    }
    return prod;
}

void method_1020(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    ref_int_Matrix m2 = readMatrixFromFile("DADOS2.TXT");
    if (m1 != NULL && m2 != NULL)
    {
        ref_int_Matrix prod = matrixProduct(m1, m2);
        if (prod != NULL)
        {
            printf("\nResultado do produto matricial:\n");
            printIntMatrix(prod);
            free_int_Matrix(prod);
        }
    }
    free_int_Matrix(m1);
    free_int_Matrix(m2);
}

//Extras
ref_int_Array sortArrayDown(int_Array array)
{
    ref_int_Array ordenado = NULL;
    if (array.data == NULL || array.length <= 0)
    {
        printf("\nERRO: Arranjo invalido para ordenacao.\n");
    }
    else
    {
        ordenado = new_int_Array(array.length);
        if (ordenado != NULL && ordenado->data != NULL)
        {
            // Copiar dados
            for (ordenado->ix = 0; ordenado->ix < ordenado->length; ordenado->ix = ordenado->ix + 1)
            {
                ordenado->data[ordenado->ix] = array.data[ordenado->ix];
            }
            // Algoritmo de trocas
            for (int i = 0; i < ordenado->length - 1; i = i + 1)
            {
                for (int j = 0; j < ordenado->length - 1 - i; j = j + 1)
                {
                    if (ordenado->data[j] < ordenado->data[j + 1])
                    {
                        int temp = ordenado->data[j];
                        ordenado->data[j] = ordenado->data[j + 1];
                        ordenado->data[j + 1] = temp;
                    }
                }
            }
        }
    }
    return ordenado;
}

void method_10E1(void)
{
    ref_int_Array arranjo = readArrayFromFile("DADOS1.TXT");
    if (arranjo != NULL)
    {
        ref_int_Array ordenado = sortArrayDown(*arranjo);
        if (ordenado != NULL)
        {
            printf("\nArranjo original:\n");
            printIntArray(*arranjo);
            printf("\nArranjo ordenado decrescente:\n");
            printIntArray(*ordenado);
            free_int_Array(ordenado);
        }
        free_int_Array(arranjo);
    }
}

bool identityMatrix(ref_int_Matrix matrix)
{
    bool identidade = true;
    if (matrix == NULL || matrix->data == NULL)
    {
        identidade = false;
    }
    else if (matrix->rows != matrix->columns || matrix->rows <= 0)
    {
        identidade = false; // Nao e quadrada
    }
    else
    {
        for (matrix->ix = 0; matrix->ix < matrix->rows && identidade; matrix->ix = matrix->ix + 1)
        {
            for (matrix->iy = 0; matrix->iy < matrix->columns && identidade; matrix->iy = matrix->iy + 1)
            {
                if (matrix->ix == matrix->iy)
                {
                    if (matrix->data[matrix->ix][matrix->iy] != 1)
                    {
                        identidade = false;
                    }
                }
                else
                {
                    if (matrix->data[matrix->ix][matrix->iy] != 0)
                    {
                        identidade = false;
                    }
                }
            }
        }
    }
    return identidade;
}

void method_10E2(void)
{
    ref_int_Matrix m1 = readMatrixFromFile("DADOS1.TXT");
    ref_int_Matrix m2 = readMatrixFromFile("DADOS2.TXT");
    if (m1 != NULL && m2 != NULL)
    {
        ref_int_Matrix prod = matrixProduct(m1, m2);
        if (prod != NULL)
        {
            printf("\nProduto das Matrizes:\n");
            printIntMatrix(prod);
            bool resposta = identityMatrix(prod);
            if (resposta)
            {
                printf("\nResultado: O produto E uma matriz identidade.\n");
            }
            else
            {
                printf("\nResultado: O produto NAO e uma matriz identidade.\n");
            }
            free_int_Matrix(prod);
        }
    }
    free_int_Matrix(m1);
    free_int_Matrix(m2);
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
            case 1:  method_1011 ( ); break;
            case 2:  method_1012 ( ); break;
            case 3:  method_1013 ( ); break;
            case 4:  method_1014 ( ); break;
            case 5:  method_1015 ( ); break;
            case 6:  method_1016 ( ); break;
            case 7:  method_1017 ( ); break;
            case 8:  method_1018 ( ); break;
            case 9:  method_1019 ( ); break;
            case 10: method_1020 ( ); break;
            case 11: method_10E1 ( ); break;
            case 12: method_10E2 ( ); break;

            default:
            printf ( "\nOpcao invalida!\n" );
            pause ( "Aperte ENTER para continuar." );
            break;
        }
    }
    while ( opcao != 0 );

    return ( 0 );
}
