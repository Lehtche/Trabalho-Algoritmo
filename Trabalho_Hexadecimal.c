#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

double calculo_func(int x, double b) {
    double a0 = 186752;
    double a1 = -148235;
    double a2 = 34504.9;
    double a3 = -3509.1;
    double a4 = 0.183166;
    double a5 = -0.00513554;
    double a6 = 0.0000735464;
    double a7 = -4.22038e-7;
    return round(a0 + (a1 + b) * x + a2 * x * x + a3 * x * x * x +
                 a4 * pow(x, 4) + a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7));
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int num_msg , m, i;
    printf("===========================================================================\n");
	printf("                    Decodificação de Código Hexadecimal                    \n");
    printf("Digite o número de mensagens (1 a 10000): ");
    scanf("%d", &num_msg);
    
    if (num_msg < 1 || num_msg > 10000) {
        printf("Número de mensagens inválido.\n");
        return 1;
    }
    
    for ( m = 0; m < num_msg; m++) {
        double b;
        char MsgHexa[101]; // até 100 caracteres + 1 para o nulo

        printf("Digite o valor de b: ");
        scanf("%lf", &b);
        printf("Digite a mensagem em hexadecimal (máx 100 caracteres): ");
        scanf("%s", MsgHexa);

        int x = 1; // Posição do caractere, começando em 1
        for ( i = 0; i < strlen(MsgHexa); i += 2) {
            // Verifica se ainda há pares para processar
            if (i + 1 >= strlen(MsgHexa)) {
                break;
            }

            // Converte os dois caracteres hexadecimais para um inteiro
            char hex_par[3] = {MsgHexa[i], MsgHexa[i + 1], '\0'};
            int Ascii = (int)strtol(hex_par, NULL, 16);

            // Ignora caracteres inválidos
            if (Ascii == 0) {
                continue;
            }

            // Aplica a função de validação
            double resultado = calculo_func(x, b);
            if (resultado != 0) {
                printf("%c", (char)Ascii);
            }
            x++;
        }
        printf("\n");
    }
  	printf("\nDecofidicação Completa!!\n");
  	printf("\n===========================================================================\n");  

    return 0;
}
