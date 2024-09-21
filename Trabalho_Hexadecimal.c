#include <stdio.h>
#include <math.h>
#include <string.h>
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
    return a0 + (a1 + b) * x + a2 * pow(x, 2) + a3 * pow(x, 3) + a4 * pow(x, 4) + 
           a5 * pow(x, 5) + a6 * pow(x, 6) + a7 * pow(x, 7);

}
int main() {
    char MsgHex[100]; 
    int x = 1;  
    double b; 
    int i;
    setlocale(LC_ALL, "Portuguese");
    
	printf("===========================================================================\n");
	printf("                    Decodificação de Código Hexadecimal                    \n");
    printf("Digite o valor de b: ");
    scanf("%lf", &b);
    
    	while (1) {
       	printf("Digite a mensagem em hexadecimal (até 50 caracteres): ");
        scanf("%s", MsgHex);
    	if (strlen(MsgHex) < 51) {
            break;
        }else {
            printf("Erro!! A mensagem deve ter até 50 caracteres.\n Tente novamente.\n");
        }
    }
    for (i = 0; i < strlen(MsgHex); i += 2) { //Passa pela MsgHex 2 caracteres por vez, formando um par
    	//converte par para valor inteiro
        char hexPar[3] = {MsgHex[i], MsgHex[i+1], '\0'};
        int Ascii = (int)strtol(hexPar, NULL, 16); 

        if (Ascii == 0) {
        	printf("\nCaractere Nulo!!\n");
            break;
        }
        
        double resultFun = calculo_func(x, b);//recebe o resultado do calculo da função
        
        if (resultFun == (int)resultFun) { //se o resultado for inteiro, ignora o caractere 
            x++; 
            continue;
        }
        x++;
    }
    printf("\nDecofidicação Completa!!\n");
  	printf("\n===========================================================================\n"); 
    return 0;
}
