//declaracao de bibliotecas:
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "raylib.h"

//definicoes de constantes:
#define ALTURA 600
#define LARGURA 1200

#define LADO 20

#define LINHAS 30
#define COLUNAS 60

#define MAX_INIMIGOS 50
#define MAX_RECURSOS 50

#define MAPA_TESTE "mapa0.txt"

//definicoes de estruturas:
typedef struct Posicao //posicao de objetos
{
    int x, y;
}
POS;

typedef struct Direcao //direcao do proximo movimento
{
    int dx, dy;
}
DIR;

typedef struct Inimigo //valores de inimigos
{
    POS pos;
    DIR dir;
}
INIMIGO;

typedef struct Player
{
    POS pos;
    DIR dir;
    int vida, recursos;
}
PLAYER;

typedef struct Base
{
    int vida;
}
BASE;

//variavel global para pausar
bool Pausado = false;



//funcoes de movimentacao:
/*int canMove(POS pos, DIR dir)//checa se é possível se movimentar(0=false, 1=true)
{
    if(pos.x+(dir.dx*LADO) >= ALTURA ||
       pos.x+(dir.dx*LADO) <= 0 ||
       pos.y+(dir.dy*LADO) >= LARGURA ||
       pos.y+(dir.dy*LADO) <= 0 ||
       (dir.dx==0 && dir.dy==0))
        return 0;
    else
        return 1;
}*/

int colisao(POS pos, DIR dir, POS posF)//checa se há colisao com algum objeto
{
    if(pos.x+(dir.dx*LADO) == posF.x && pos.y+(dir.dy*LADO) == posF.y)
        return 1;
    else
        return 0;
}

int colisaoMovel(POS pos, DIR dir, POS posF, DIR dirF)//checa se há colisao com algum objeto movel
{
    if(pos.x+(dir.dx*LADO) == posF.x+(dirF.dx*LADO) && pos.y+(dir.dy*LADO) == posF.y+(dirF.dy*LADO))
        return 1;
    else
        return 0;
}

void move(POS *pos, DIR dir)//Atualiza a posicao do objeto
{
    pos->x = pos->x + (dir.dx*LADO);
    pos->y = pos->y + (dir.dy*LADO);
}

void atualizaDirInimigo(DIR *dir)//Atualiza e valida a direcao
{
    do{
        dir->dx = (rand()%3) - 1;
        dir->dy = (rand()%3) - 1;
    }
    while((dir->dx==0 && dir->dy==0) || (dir->dx!=0 && dir->dy!=0));
}

//funcoes de manipulacao de arquivos:
int leMapa(char fileName[], char tile[LINHAS][COLUNAS]) //le o arquivo texto de mapa
{
    int l, c;
    FILE *file;

    if((file = fopen(fileName, "r")) == NULL){
        fclose(file);
        return 0;
    }
    else{
        for(l=0; l<LINHAS; l++){
            for(c=0; c<COLUNAS; c++){
                {
                    tile[l][c] = getc(file);
                    while(tile[l][c] == '\n'){
                        tile[l][c] = getc(file);
                    }
                }
            }
        }
        fclose(file);
        return 1;
    }
}

//codigo main:
int main()
{
    int i, l, c; //contadores para "for"
    char map[LINHAS][COLUNAS]; //matriz do mapa

    //Criacao de variaveis estruturas:
    PLAYER player;
    BASE base;

    INIMIGO inimigo[MAX_INIMIGOS]; int quantInimigo = 0; int timer;//vetor de inimigos no mapa e quantidade atual e timer para movimento

    //status do player
    player.recursos = 0;
    player.vida = 1;

    base.vida = 3; //status da base



    POS recurso[MAX_RECURSOS]; int quantRecurso = 0; //vetor de recursos no mapa e quantidade atual
    POS obstaculo[MAX_RECURSOS]; int quantObstaculo = 0; //vetor de obstaculos no mapa e qauntia atual
    POS posObj; //variavel buffer

    srand(time(NULL));


    if((leMapa(MAPA_TESTE, map)) == 1){ //leitura do arquivo do mapa
        printf("Mapa carregado com sucesso\n");
    }
    else{
        printf("Falha no carregamento\n");
    }

    for(l=0; l<LINHAS; l++){
        for(c=0; c<COLUNAS; c++)
        {
            if(map[l][c] == 'J'){ //inicializa a posicao do player
                player.pos.x = c*LADO;
                player.pos.y = l*LADO;
            }
            if(map[l][c] == 'M'){ //inicializa a posicao e conta a quantidade dos inimigos
                inimigo[quantInimigo].pos.x = c*LADO;
                inimigo[quantInimigo].pos.y = l*LADO;
                quantInimigo++;
            }
            if(map[l][c] == 'R'){ //inicializa a posicao e conta a quantidade dos recursos
                recurso[quantRecurso].x = c*LADO;
                recurso[quantRecurso].y = l*LADO;
                quantRecurso++;
            }
        }
    }

    for(i=0; i<quantInimigo; i++){ //inicializa a direcao dos inimigos
        atualizaDirInimigo(&inimigo[i].dir);
    }

    //Inicializa a janela
    InitWindow(LARGURA, ALTURA, "Tower Defense");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {

       if(IsKeyPressed(KEY_P))
        Pausado = !Pausado;
       if(Pausado)
       {
        DrawText("Jogo Pausado!", 80, 150, 150, BLUE);
        DrawText("Pressione Q para sair e P para retornar", 60, 500, 50, DARKBLUE);
        if(IsKeyPressed(KEY_Q))
            CloseWindow();
       }
       else
       {
        //movimento do player:
        player.dir.dx = 0;
        player.dir.dy = 0;

        if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
            player.dir.dx = 1;
            player.dir.dy = 0;
            move(&player.pos, player.dir);
        }
        if (IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)){
            player.dir.dx = -1;
            player.dir.dy = 0;
            move(&player.pos, player.dir);
        }
        if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)){
            player.dir.dx = 0;
            player.dir.dy = -1;
            move(&player.pos, player.dir);
        }
        if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)){
            player.dir.dx = 0;
            player.dir.dy = 1;
            move(&player.pos, player.dir);
        }

        /*for(c=0; c<COLUNAS; c++){
            for(l=0; l<LINHAS; l++)
            {
                if(map[l][c] == 'W')
                {
                    posObj.x = c*LADO;
                    posObj.y = l*LADO;
                    if(colisao(posPlayer, dirPlayer, posObj) == 0){ //checa se colide com parede
                        dirPlayer.dx = 0;
                        dirPlayer.dy = 0;
                    }
                }
            }
        }
        move(&posPlayer, dirPlayer);
*/

        //movimento do inimigo:
        for(i=0; i<quantInimigo; i++){
            for(c=0; c<COLUNAS; c++){
                for(l=0; l<LINHAS; l++)
                {
                    if(map[l][c] == 'W' || map[l][c] == 'H')
                    {
                        posObj.x = c*LADO;
                        posObj.y = l*LADO;
                        while(colisao(inimigo[i].pos, inimigo[i].dir, posObj) == 1){ //colisao com parede
                            atualizaDirInimigo(&inimigo[i].dir);// NAO FUNCIONA COM MULTIPLAS PAREDES
                        }
                    }
                    if(map[l][c] == 'S')
                    {
                        posObj.x = c*LADO;
                        posObj.y = l*LADO;
                        if(colisao(inimigo[i].pos, inimigo[i].dir, posObj) == 1){ //colisao com a base
                                //DESTROI O INIMIGO E A BASE PERDE UMA VIDA
                        }
                    }
                }
            }
            move(&inimigo[i].pos, inimigo[i].dir);
        }
       }
        BeginDrawing(); //começo do desenho
        ClearBackground(WHITE);

        for(l=0; l<LINHAS; l++){
            for(c=0; c<COLUNAS; c++){
                if(map[l][c] == 'W'){
                    DrawRectangle(c*LADO, l*LADO, LADO, LADO, BLACK);//desenha as paredes
                }
                if(map[l][c] == 'H'){
                    DrawRectangle(c*LADO, l*LADO, LADO, LADO, GRAY);//desenha os buracos
                }
                if(map[l][c] == 'S'){
                    DrawRectangle(c*LADO, l*LADO, LADO, LADO, BLUE);//desenha a base
                }
            }
        }

        DrawRectangle(player.pos.x, player.pos.y, LADO, LADO, GREEN); //desenha o player

        for(i=0; i<quantInimigo; i++){
            DrawRectangle(inimigo[i].pos.x, inimigo[i].pos.y, LADO, LADO, RED);//desenha os inimigos
        }

        for(i=0; i<quantRecurso; i++){
            DrawRectangle(recurso[i].x, recurso[i].y, LADO, LADO, ORANGE);//desenha os recursos
        }

        EndDrawing();
    }

    return 0;
}
