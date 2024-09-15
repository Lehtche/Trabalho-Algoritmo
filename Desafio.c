#include <stdio.h>
#include <locale.h>

float media(float a, float b, float c, float d){
	if (d == 1){
		d-=1;
	}
	return a+b+c+d;
}


int main(){
	setlocale(LC_ALL,"Portuguese");
	float N1,N2,N3,PPD,NotEU;
	int SeEU,SeN3;
	
	printf("===============================================================\n");
	printf("                  Sistema de Avaliação                         \n");
	printf("Digite as notas:\n");
	printf("N1:");
	scanf("%f",&N1);
	printf("N2:");
	scanf("%f",&N2);
	printf("PPD:");
	scanf("%f",&PPD);
	printf("Realizou o Exame Unificado?\nDigite [1] para sim e [0] para não: ");
	scanf("%d",&SeEU);
	printf("Realizou o N3?\nDigite [1] para sim e [0] para não: ");
	scanf("%d",&SeN3);
	
	if (SeEU == 1){
		printf("Digite sua nota do EU:");
		scanf("%f",&NotEU);
		printf("Nota Exame unificado: %.2f\n",NotEU);
	}
	if (SeN3 == 1){
		printf("Digite sua nota do N3:");
		scanf("%f",&N3);
		if (N3 > 4.5){
			printf("ERRO!! NOTA INVÁLIDA\n");
			return 3;
		}
		if (N1 < N2){
			N1=N3;
		}
		else{
			N2=N3;
		}
	}
	if (N1>4.5 || N2 >4.5 || PPD > 1){
		printf("ERRO!! NOTAS INVÁLIDAS\n");
		return 3;
	}
	if (media(N1,N2,PPD,NotEU)< 7){
		printf("Reprovado!!\n");
	}
	else if(media(N1,N2,PPD,NotEU)>7){
	printf("Aprovado!!\n");
	}if (media(N1,N2,PPD,NotEU)>10){
	}
	printf("Sua média é %.2f", media(N1,N2,PPD,NotEU));
	printf("\n===============================================================");
	return 0;
}
