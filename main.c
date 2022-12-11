#include <stdio.h>
#include "jogo.h"
#include "utils.h"

void menu(int escolha){
    switch (escolha){
        case 1:
            printf("1 - Iniciar novo jogo\n");
            printf("2 - Carregar jogo anterior\n");
            printf("3 - Regras\n");
            printf("4 - Sair\n");
            printf("Opcao: ");
            break;
        default:
            break;
    }
}

int main() {
    Tabuleiro tab;
    Jogo joga;
    Minis minis;
    pMinis listaMiniTab = NULL;

    Jogador jogadorA;
    Jogador jogadorB;

    int escolha=1, sair=1;
    char comando;
    printf("=== TP de Programacao ISEC 21-22 ===\n");
    printf("=== Jogo Ultimate Tic-Tac-Toe ===\n");
    do{
        menu(escolha);
        scanf("%c", &comando);
        while (getchar() != '\n');
        switch(comando) {
            case '1': {
                printf("Vou iniciar o jogo...\n");
                sair = jogar(&tab, &joga, &minis, jogadorA, jogadorB, listaMiniTab);
            }
                break;
            case '2':
                carregar(&tab, &jogadorA, &jogadorB, &joga, listaMiniTab, minis);
                printf("\nModo jogo: %d\n", joga.modo);
                jogarJogoCarregado(&tab, &joga, &minis, jogadorA, jogadorB, listaMiniTab);
                break;
            case '3':
                printf("=== Alternadamente os jogadores vao colocando pecas ===\n");
                printf("=== Ganha o jogador que coloque uma peca que permita formar uma linha, coluna ou diagonal completa no tabuleiro grande ===\n");
                break;
            case '4':
                return 0;
            default:
                printf("Comando invalido!\n");
        }
    }while(sair!=0);
}



