#include <stdio.h>
#include <limits.h>

int main() {


    /* TABELA DE VARIÁVEIS DO MÍNIMO AO MÁXIMO */
    
    printf("| TIPO                   | MINIMO                | MAXIMO              |\n");
    printf("|________________________|_______________________|_____________________|\n");
    printf("| char                   | %d                  | %d                 |\n", CHAR_MIN, CHAR_MAX);
    printf("| int                    | %d           | %d          |\n", INT_MIN, INT_MAX);
    printf("| short int              | %d                | %d               |\n", SHRT_MIN, SHRT_MAX);
    printf("| unsigned int           | 0                     | %u          |\n", UINT_MAX);
    printf("| long int               | %ld           | %ld          |\n", LONG_MIN, LONG_MAX);
    printf("| unsigned long int      | 0                     | %lu          |\n", ULONG_MAX);
    printf("| long long int          | %lld  | %lld |\n", LLONG_MIN, LLONG_MAX);
    printf("| unsigned long long int | 0                     | %llu|\n", ULLONG_MAX);

    /* Exemplo de valor fora do limite */
    
    int num = INT_MAX; 
    printf("\nExemplo de valor fora do limite \n");
    
    printf("Valor original de num: %d\n", num);
    
num += 1;            /* Adicionando 1 ao valor máximo, logo, ultrapassando o limite suportado pela variável */  

    printf("O valor apresentado apos passar do limite eh de: %d\n", num);   

    return 0;
}


