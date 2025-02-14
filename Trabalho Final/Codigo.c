#include <stdio.h>
#include <math.h>
#define N 5

int main(){

    //Vari�veis
    float arranjoX[N];
    float arranjoY[N];
    float calculoDistancia = 999.99;
    float distancia = 0.0;
    float *pontoInicialX;
    float *pontoInicialY;
    float *pontoFinalX;
    float *pontoFinalY;

    for(int i = 0; i < N; i++){

         printf("Informe as coordenadas x e y do ponto %d:", i+1);
         scanf("%f %f", &arranjoX[i], &arranjoY[i]);

    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i != j){
                calculoDistancia = sqrt((pow((arranjoX[i] - arranjoY[i]), 2)) + (pow((arranjoX[j] - arranjoY[j]), 2)));
                //printf("%.02f \n", calculoDistancia);
                if(calculoDistancia < distancia){

                    distancia = calculoDistancia;
                    pontoInicialX = &arranjoX[i];
                    pontoInicialY = &arranjoY[i];
                    pontoFinalX = &arranjoX[j];
                    pontoFinalY = &arranjoY[j];
                    printf("%f", distancia);
                }
            }
        }
    }

    printf("Os pontos (%f0.2, %0.2f) e (%0.2f, %0.2f) tem distancia %0.2f!", *pontoInicialX, *pontoInicialY, *pontoFinalX, *pontoFinalY, &distancia);

    //printf("(%.2f,%.2f)" , arranjoX[i], arranjoY[i]);
    /*for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){



        }
    }
    */













    return 0;
}
