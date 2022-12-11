#include "jogo.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função que representa o segundo menu do joga
void segundoMenu(int escolha, Jogador jogadorA) {
    switch (escolha) {
        case 1:
            printf("1 - Jogar com um amigo\n");
            printf("2 - Jogar contra o computador\n");
            printf("3 - Sair \n");
            printf("Opcao: ");
            break;
        case 2:
            printf("\n ==> Jogador %s escolha a peca que quer usar no jogo <==\n", jogadorA.nome);
            printf("1 - X\n");
            printf("2 - O\n");
            printf("Opcao: ");
            break;
        case 3:
            printf("1 - Comecar de novo\n");
            printf("2 - Sair\n");
            printf("Opcao: ");
            break;
        case 4:
            printf("1 - Jogar peca\n");
            printf("2 - Ver jogadas anteriores\n");
            printf("3 - Gravar\n");
            printf("4 - Sair\n");
            printf("Opcao: ");
            break;
        default:
            printf("Menu indisponível !!");
            break;
    }
}

//Mostra o tabuleiro
void mostrarTab(Tabuleiro *tab) {
    int i, j;

    for (i = 0; i < 12; i++) {
        printf("X ");   //impresao dos x antes do tabuleiro
    }

    printf("\n");

    printf("X      C1 ");
    for (i = 2; i <= 3; i++) {  //impressao das colunas
        printf(" C%d ", i);
    }
    printf("    X");

    printf("\n");
    printf("X     ");
    for (i = 0; i < 13; i++) {
        printf("-");
    }
    printf("   X");
    printf("\n");


    for (i = 0; i < 3; i++) {
        printf("X ");

        for (j = 0; j < 3; j++) {
            if (j == 0)
                printf(" L%d ", i + 1);
            printf("| %c ", tab->tab[i][j]);
        }

        printf("|");
        printf("   X");

        printf("\n");
        printf("X     ");
        for (int h = 0; h < 13; h++) {
            printf("-");
        }
        printf("   X");
        printf("\n");
    }
    for (i = 0; i < 12; i++) {
        printf("X ");
    }
    printf("\n");
}

// Cria o tabuleiro inicial
void criarTab(Tabuleiro *tab) {

    tab->linhas = 3;
    tab->colunas = 3;
    tab->tab = malloc(sizeof(char *) * tab->linhas);
    if (tab->tab == NULL) {
        printf("Erro !");
        exit(0);
    }
    for (int i = 0; i < tab->linhas; i++) {
        tab->tab[i] = malloc(sizeof(char) * tab->colunas);
        if (tab->tab[i] == NULL) {
            printf("Erro !");
            exit(0);
        }
    }
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            tab->tab[i][j] = ' ';
        }
    }
}
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!VERIFICAR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//Mostra o mini tabuleiro
void mostrarMiniTab(Tabuleiro *miniTab) {
    int i, j;

    for (i = 0; i < 12; i++) { //impresao dos x antes do tabuleiro
        printf("X ");
    }
    printf("\n");

    printf("X      C1 ");
    for (i = 2; i <= 3; i++) {  //impressao das colunas
        printf(" C%d ", i);
    }
    printf("    X");

    printf("\n");
    printf("X     ");
    for (i = 0; i < 13; i++) {
        printf("-");
    }
    printf("   X");
    printf("\n");

    for (i = 0; i < 3; i++) {
        printf("X ");
        for (j = 0; j < 3; j++) {
            if (j == 0) {
                printf(" L%d ", i + 1);
            }
            printf("| %c ", miniTab->tab[i][j]);
        }

        printf("|");
        printf("   X");

        printf("\n");
        printf("X     ");
        for (int h = 0; h < 13; h++) {
            printf("-");
        }
        printf("   X");
        printf("\n");
    }
    for (i = 0; i < 12; i++) {
        printf("X ");
    }
    printf("\n");
}
//Mostrar tab do joga

// Cria os mini tabuleiros
void criarMiniTab(Minis *minis) {
    for (int i = 0; i < 9; i++) {
        minis->miniTab[i].linhas = minis->miniTab[i].colunas = 3;
        minis->miniTab[i].tab = malloc(sizeof(char *) * minis->miniTab[i].linhas);
        if (minis->miniTab[i].tab == NULL) {
            printf("Erro !");
            exit(0);
        }
        for (int j = 0; j < minis->miniTab[i].linhas; j++) {
            minis->miniTab[i].tab[j] = malloc(sizeof(char) * minis->miniTab[i].colunas);
            if (minis->miniTab[i].tab[j] == NULL) {
                printf("Erro !");
                exit(0);
            }
        }
        for (int k = 0; k < minis->miniTab[i].colunas; k++) {
            for (int j = 0; j < minis->miniTab[i].linhas; j++) {
                minis->miniTab[i].tab[j][k] = ' ';
            }
        }
    }

}


//de acordo com o modo de joga inicializa os jogadores
void inicializaJogadores(int modo, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga) {

    if (modo == 1) {   //se modo jogador vs jogador
        printf("\nDigite o nome do jogador A:\n");
        printf("Nome: ");
        scanf("%s", jogadorA->nome);
        fflush(stdin);

        do {
            printf("\nDigite o nome do jogador B:\n");
            printf("Nome: ");
            scanf("%s", jogadorB->nome);
            fflush(stdin);
        } while (strcmp(jogadorB->nome, jogadorA->nome) == 0);

    } else if (modo == 2) {  //se modo jogador vs bot
        printf("\nDigite o nome do jogador:\n");
        printf("Nome: ");
        scanf("%s", jogadorA->nome);
        fflush(stdin);
        strcpy(jogadorB->nome, "BOT");
    }
    int n = rand() % 2;
    joga->jogadorAtual = n + 1;
}

//Troca o jogador depois da sua jogada
void mudaJogador(Jogo *joga) {
    if (joga->jogadorAtual == 1) {
        joga->jogadorAtual = 2;
    } else {
        joga->jogadorAtual = 1;
    }
}

// Pede para o utilizador escolher a linha em que pertende jogar
void pedeLinha(Jogo *joga) {
    do {
        printf("Escolha a linha em que pretende jogar: ");
        scanf("%d", &joga->linhaEscolhida);

    } while (joga->linhaEscolhida < 1 || joga->linhaEscolhida > 3);
    joga->linhaEscolhida = joga->linhaEscolhida - 1;
}

// Pede para o utilizador escolher a coluna em que pertende jogar
void pedeColuna(Jogo *joga) {
    do {
        printf("Escolha a coluna em que pretende jogar: ");
        scanf("%d", &joga->colunaEscolhida);

    } while (joga->colunaEscolhida < 1 || joga->colunaEscolhida > 3);
    joga->colunaEscolhida = joga->colunaEscolhida - 1;
}


int jogar(Tabuleiro *tab, Jogo *joga, Minis *minis, Jogador jogadorA, Jogador jogadorB, pMinis listaMiniTab) {

    int opcao = 0;

    joga->linhaEscolhida = 0;
    joga->colunaEscolhida = 0;
    tab->nJogadas = 1;
    for (int i = 0; i < 9; ++i) {
        minis->miniTab[i].nJogadas = 1;
    }


    //criação do Tabuleiro grande e dos 9 mini Tabuleiros
    criarTab(tab);
    criarMiniTab(minis);

    //conjunto de Tabuleiros, está a apontar para o último que modificado
    //criação do ponteiro para o tabuleiro grande
    pTabuleiro principalInicial = NULL;

    //criação do ponteiro para cada mini tab que vou ter guardado
    listaMiniTab = NULL;

    //mostra o tabuleiro grande
    printf("\n=== Tabuleiro Inicial === \n");
    mostrarTab(tab);
    printf("\n");

    segundoMenu(1, jogadorA);
    scanf("%d", &opcao);
    if (opcao == 1) { //jogador vs jogador
        inicializaJogadores(1, &jogadorA, &jogadorB, joga);
        do {
            segundoMenu(2, jogadorA); //menu para escolher a peça
            scanf("%d", &opcao);
            if (opcao == 1) {
                jogadorA.peca = 'X';
                jogadorB.peca = 'O';
            } else if (opcao == 2) {
                jogadorA.peca = 'O';
                jogadorB.peca = 'X';
            }
        } while (opcao != 1 && opcao != 2);
        joga->modo = 1;
        jogadorVSjogador(&jogadorA, &jogadorB, joga, tab, *minis, listaMiniTab);
    } else if (opcao == 2) { //jogador vs BOT
        inicializaJogadores(2, &jogadorA, &jogadorB, joga);
        do {
            segundoMenu(2, jogadorA); // menu para escolher a peça
            scanf("%d", &opcao);
            if (opcao == 1) {
                jogadorA.peca = 'X';
                jogadorB.peca = 'O';
            } else if (opcao == 2) {
                jogadorA.peca = 'O';
                jogadorB.peca = 'X';
            }
        } while (opcao != 1 && opcao != 2);
        joga->modo = 2;
        jogarBot(&jogadorA, &jogadorB, joga, tab, *minis, listaMiniTab);
    } else if (opcao == 3) { //escolha para sair
        return 0;
    }
    return 0;
}

int
jogarJogoCarregado(Tabuleiro *tab, Jogo *joga, Minis *minis, Jogador jogadorA, Jogador jogadorB, pMinis listaMiniTab) {

    joga->linhaEscolhida = 0;
    joga->colunaEscolhida = 0;

    //conjunto de Tabuleiros, está a apontar para o último que modificado
    //criação do ponteiro para o tabuleiro grande
    pTabuleiro principalInicial = NULL;

    //criação do ponteiro para cada mini tab que vou ter guardado
    listaMiniTab = NULL;

    //mostra o tabuleiro grande
    printf("\n=== Tabuleiro Inicial === \n");
    mostrarTab(tab);
    printf("\n");

    if (joga->modo == 1) { //jogador vs jogador
        jogadorVSjogador(&jogadorA, &jogadorB, joga, tab, *minis, listaMiniTab);
    } else if (joga->modo == 2) { //jogador vs BOT
        jogarBot(&jogadorA, &jogadorB, joga, tab, *minis, listaMiniTab);
    }
    return 0;
}

int verificaLinhaTabGrande(Tabuleiro *tab) {
    int verifica = 1;
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas - 1; j++) {
            if (tab->tab[i][j] == tab->tab[i][j + 1] && tab->tab[i][j] != ' ') {
                verifica++;
            }
        }
        if (verifica == tab->linhas) {
            return 1;
        } else {
            verifica = 1;
        }
    }
    return 0;
}

int verificaLinhaMinis(Minis minis) {
    int verifica = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < minis.miniTab[i].linhas; j++) {
            for (int k = 0; k < minis.miniTab[i].colunas - 1; k++) {
                if (minis.miniTab[i].tab[j][k] == minis.miniTab[i].tab[j][k + 1] && minis.miniTab[i].tab[j][k] != ' ') {
                    verifica++;
                }
            }
            if (verifica == minis.miniTab[i].linhas) {
                return 1;
            } else {
                verifica = 1;
            }
        }
    }
    return 0;
}

/*
int verificaLinha(Tabuleiro *tab) {
    int verifica = 1;
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas - 1; j++) {
            if (tab->tab[i][j] == tab->tab[i][j + 1] && tab->tab[i][j] != ' ') {
                verifica++;
            }
        }
        if (verifica == tab->colunas) {
            return 1;
        } else {
            verifica = 1;
        }
    }
    return 0;
}
*/

int verificaColunaTabGrande(Tabuleiro *tab) {
    int verifica = 1;
    for (int i = 0; i < tab->colunas; i++) {
        for (int j = 0; j < tab->linhas - 1; j++) {
            if (tab->tab[j][i] == tab->tab[j + 1][i] && tab->tab[j][i] != ' ') {
                verifica++;
            }
        }
        if (verifica == tab->colunas) {
            return 1;
        } else {
            verifica = 1;
        }
    }
    return 0;
}

int verificaColunaMinis(Minis minis) {
    int verifica = 1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < minis.miniTab[i].linhas - 1; j++) {
            for (int k = 0; k < minis.miniTab[i].colunas; k++) {
                if (minis.miniTab[i].tab[j][k] == minis.miniTab[i].tab[j + 1][k] && minis.miniTab[i].tab[j][k] != ' ') {
                    verifica++;
                }
            }
            if (verifica == minis.miniTab[i].colunas) {
                return 1;
            } else {
                verifica = 1;
            }
        }
    }
    return 0;
}

/*
int verificaColuna(Tabuleiro *tab) {
    int verifica = 1;
    for (int i = 0; i < tab->colunas; i++) {
        for (int j = 0; j < tab->linhas - 1; j++) {
            if (tab->tab[j][i] == tab->tab[j + 1][i] && tab->tab[j][i] != ' ') {
                verifica++;
            }
        }
        if (verifica == tab->colunas) {
            return 1;
        } else {
            verifica = 1;
        }
    }
    return 0;
}
*/

int verificaDiagonalTabGrande(Tabuleiro *tab) {
    int verifica = 1;
    //verificação diagonal principal
    if (tab->tab[0][0] == tab->tab[1][1] && tab->tab[0][0] == tab->tab[2][2] && tab->tab[0][0] != ' ') {
        return 1;
    }
    //verificação diagonal secundaria
    for (int i = 0; i < tab->colunas - 1; i++) {
        for (int j = 0, k = tab->colunas - 1; k > 0; k--, j++) {
            if (tab->tab[j][k] == tab->tab[j + 1][k - 1] && tab->tab[j][k] != ' ') {
                verifica++;
            } else {
                verifica = 1;
            }
        }
        if (verifica == tab->colunas) {
            return 1;
        }
    }
    return 0;
}

int verificaDiagonalMinis(Minis minis) {
    int verifica = 1;
    for (int i = 0; i < 9; i++) {
        if (minis.miniTab[i].tab[0][0] == minis.miniTab[i].tab[1][1] &&
            minis.miniTab[i].tab[0][0] == minis.miniTab[i].tab[2][2] && minis.miniTab[i].tab[0][0] != ' ') {
            return 1;
        }
        for (int j = 0; j < minis.miniTab[i].colunas - 1; j++) {
            for (int k = 0, l = minis.miniTab[i].colunas - 1; l > 0; l--, k++) {
                if (minis.miniTab[i].tab[k][l] == minis.miniTab[i].tab[k + 1][l - 1] &&
                    minis.miniTab[i].tab[k][l] != ' ') {
                    verifica++;
                } else {
                    verifica = 1;
                }
            }
            if (verifica == minis.miniTab[i].colunas) {
                return 1;
            }
        }
    }


    return 0;
}

/*
int verificaDiagonal(Tabuleiro *tab) {
    int verifica = 1;
    if (tab->tab[0][0] == tab->tab[1][1] && tab->tab[0][0] == tab->tab[2][2] && tab->tab[0][0] != ' ') {
        return 1;
    }
    for (int i = 0; i < tab->colunas - 1; i++) {
        for (int j = 0, k = tab->colunas - 1; k > 0; k--, j++) {
            if (tab->tab[j][k] == tab->tab[j + 1][k - 1] && tab->tab[j][k] != ' ') {
                verifica++;
            } else {
                verifica = 1;
            }
        }
        if (verifica == tab->colunas) {
            return 1;
        }
    }
    return 0;
}
 */

int verificaEmpateTabGrande(Tabuleiro *tab) {
    int contaPecas = 0;
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            if (tab->tab[i][j] != ' ') {
                contaPecas++;
                if (contaPecas == 9 && verificaLinhaTabGrande(tab) == 0 && verificaColunaTabGrande(tab) == 0 &&
                    verificaDiagonalTabGrande(tab) == 0) {
                    printf("Houve um empate!!\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}

int verificaEmpateMinis(Minis minis) {
    int contaPecas = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < minis.miniTab[i].linhas; j++) {
            for (int k = 0; k < minis.miniTab[i].colunas; k++) {
                if (minis.miniTab[i].tab[j][k] != ' ') {
                    contaPecas++;
                    if (contaPecas == 9 && verificaLinhaMinis(minis) == 0 && verificaColunaMinis(minis) == 0 &&
                        verificaDiagonalMinis(minis) == 0) {
                        printf("Houve um empate!!\n");
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

/*
int verificaEmpate(Tabuleiro *tab) {
    int contaPecas = 0;
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            if (tab->tab[i][j] != ' ') {
                contaPecas++;
                if (contaPecas == 9 && verificaLinha(tab) == 0 && verificaColuna(tab) == 0 &&
                    verificaDiagonal(tab) == 0) {
                    printf("Houve um empate!!\n");
                    return 1;
                }
            }
        }
    }
    return 0;
}
*/

int fimJogoTabGrande(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *tab) {
    if (verificaEmpateTabGrande(tab) == 1) {
        for (int j = 0; j < tab->colunas; j++) {
            for (int i = 0; i < tab->linhas; i++) {
                printf("O jogo empatou!!\n");
                //writeToFile(tab, );
                //verificaFicheiro();
                return 1;
            }
        }
    }

    if (verificaLinhaTabGrande(tab) == 1 || verificaColunaTabGrande(tab) == 1 || verificaDiagonalTabGrande(tab) == 1) {
        if (joga->jogadorAtual == 1) {
            printf("O jogador %s ganhou o jogo!!\n", jogadorB->nome);
            //writeToFile(tab, );
            //verificaFicheiro();
            return 1;
        } else if (joga->jogadorAtual == 2) {
            printf("O jogador %s ganhou o jogo!!\n", jogadorA->nome);
            //writeToFile(tab, );
            //verificaFicheiro();
            return 1;
        }
    }
    return 0;
}

int fimJogoMinis(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Minis minis, Tabuleiro *tab) {
    for (int i = 0; i < 9; i++) {
        if (verificaEmpateMinis(minis) == 1) {
            for (int j = 0; j < minis.miniTab[i].colunas; j++) {
                for (int k = 0; k < minis.miniTab[i].linhas; k++) {
                    minis.miniTab[i].tab[k][j] = ' ';
                    return 1;
                }
            }
        }

        if (verificaLinhaMinis(minis) == 1 || verificaColunaMinis(minis) == 1 || verificaDiagonalMinis(minis) == 1) {
            if (joga->jogadorAtual == 1) {
                printf("O jogador %s ganhou o jogo desse mini tabuleiro!!\n", jogadorB->nome);
                return 1;
            } else if (joga->jogadorAtual == 2) {
                printf("O jogador %s ganhou o jogo desse mini tabuleiro!!\n", jogadorA->nome);
                return 1;
            }
        }
    }
    return 0;
}

/*
int fimJogo(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *tab) {
    if (verificaEmpate(tab) == 1) {
        for (int j = 0; j < tab->colunas; j++) {
            for (int i = 0; i < tab->linhas; i++) {
                tab->tab[i][j] = ' ';
                return 1;
            }
        }
    }

    if (verificaLinha(tab) == 1 || verificaColuna(tab) == 1 || verificaDiagonal(tab) == 1) {
        if (joga->jogadorAtual == 1) {
            printf("O jogador %s ganhou o jogo!!\n", jogadorB->nome);
            return 1;
        } else if (joga->jogadorAtual == 2) {
            printf("O jogador %s ganhou o jogo!!\n", jogadorA->nome);
            return 1;
        }
    }
    return 0;
}
*/

void jogarBot(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *tab, Minis minis, pMinis listaMiniTab) {
    int opcao;
    int loop = 1;
    do {
        printf("\n");
        if (fimJogoTabGrande(jogadorA, jogadorB, joga, tab) == 1) {
            loop = 0;
        } else if (fimJogoMinis(jogadorA, jogadorB, joga, minis, tab) == 1) {
            loop = 0;
        } else {
            if (joga->jogadorAtual == 1) { //jogadorAtual = 1 => jogadorA
                printf("E a vez do jogador %s jogar, que tem a peca %c.\n", jogadorA->nome, jogadorA->peca);
            } else if (joga->jogadorAtual == 2) { //jogadorAtual = 2 => jogadorA
                printf("E a vez do jogador %s jogar, que tem a peca %c.\n", jogadorB->nome, jogadorB->peca);
            }
            if (joga->jogadorAtual == 1) { //vez do jogadorA jogar
                segundoMenu(4, *jogadorA); //menu para saber se quer jogar a peça
                scanf("%d", &opcao);
                if (opcao == 1) { //escolhe jogar peça
                    if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[0], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[1], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[2], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[3], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[4], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[5], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[6], listaMiniTab, tab);
                        //minis.miniTab[6].nJogadas++;
                        tab->nJogadas++;
                        //minis.miniTab[6].JogadasTotais += minis.miniTab[6].nJogadas;
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[7], listaMiniTab, tab);
                        //minis.miniTab[7].nJogadas++;
                        tab->nJogadas++;
                        //minis.miniTab[7].JogadasTotais += minis.miniTab[7].nJogadas;
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[8], listaMiniTab, tab);
                        //minis.miniTab[8].nJogadas++;
                        tab->nJogadas++;
                        //minis.miniTab[8].JogadasTotais += minis.miniTab[8].nJogadas;
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        mudaJogador(joga);

                        /*for (int i = 0; i < 9; i++) {
                            minis.miniTab[i].JogadasTotais += minis.miniTab[i].nJogadas;
                        }*/
                    }
                } else if (opcao == 2) { //ver jogadas anteriores
                    int certo = 0;
                    int numeroJogadasAVer;
                    printf("\n ========================================================================= \n");
                    do {
                        printf("Quantas jogadas pretende ver? (1-10)\n");
                        printf("\nNúmero jogadas: ");
                        scanf(" %d ", &numeroJogadasAVer);
                        for (int i = 0; i < 9; ++i) {
                            if (numeroJogadasAVer <= tab->nJogadas && numeroJogadasAVer > 0 &&
                                numeroJogadasAVer <= 10) {
                                mostraJogadas(listaMiniTab, numeroJogadasAVer, tab);
                                certo = 1;
                            }
                        }
                    } while (certo != 1);
                    mostraJogadas(listaMiniTab, numeroJogadasAVer, tab);
                } else if (opcao == 3) { //gravar jogo
                    guardar(tab, jogadorA, jogadorB, joga, listaMiniTab, minis);
                } else if (opcao == 4) { //sair jogo
                    loop = 0;
                }
            } else if (joga->jogadorAtual == 2) {
                if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 0) {
                    printf("\n=== Mini-Tabuleiro 11 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[0]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[0], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 11 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[0]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 1) {
                    printf("\n=== Mini-Tabuleiro 12 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[1]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[1], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 12 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[1]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 2) {
                    printf("\n=== Mini-Tabuleiro 13 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[2]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[2], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 13 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[2]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 0) {
                    printf("\n=== Mini-Tabuleiro 21 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[3]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[3], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 21 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[3]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 1) {
                    printf("\n=== Mini-Tabuleiro 22 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[4]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[4], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 22 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[4]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 2) {
                    printf("\n=== Mini-Tabuleiro 23 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[5]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[5], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 23 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[5]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 0) {
                    printf("\n=== Mini-Tabuleiro 31 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[6]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[6], listaMiniTab, tab);
                    //minis.miniTab[6].nJogadas++;
                    tab->nJogadas++;
                    //minis.miniTab[6].JogadasTotais += minis.miniTab[6].nJogadas;
                    printf("\n=== Mini-Tabuleiro 31 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[6]);
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 1) {
                    printf("\n=== Mini-Tabuleiro 32 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[7]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[7], listaMiniTab, tab);
                    //minis.miniTab[7].nJogadas++;
                    tab->nJogadas++;
                    //minis.miniTab[7].JogadasTotais += minis.miniTab[7].nJogadas;
                    printf("\n=== Mini-Tabuleiro 32 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[7]);
                    mudaJogador(joga);
                } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 2) {
                    printf("\n=== Mini-Tabuleiro 33 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[8]);
                    do {
                        do {
                            joga->linhaEscolhida = intUniformRnd(0, 2);
                            joga->colunaEscolhida = intUniformRnd(0, 2);
                        } while (joga->linhaEscolhida < 0 || joga->linhaEscolhida > 2);
                        if (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                            printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                        }
                    } while (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                    minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                    listaMiniTab = guardarJogadasMinis(&minis.miniTab[8], listaMiniTab, tab);
                    printf("\n=== Mini-Tabuleiro 33 === \n "
                           " === Jogada %d ===\n", tab->nJogadas);
                    mostrarMiniTab(&minis.miniTab[8]);
                    tab->nJogadas++;
                    mudaJogador(joga);
                }
            }
        }
    } while (loop == 1);
    printf("jogadas totais: %d", tab->nJogadas);
}

void
jogadorVSjogador(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *tab, Minis minis, pMinis listaMiniTab) {
    int opcao;
    int loop = 1;
    do {
        printf("\n");
        if (fimJogoTabGrande(jogadorA, jogadorB, joga, tab) == 1) {
            loop = 0;
        } else if (fimJogoMinis(jogadorA, jogadorB, joga, minis, tab) == 1) {
            loop = 0;
        } else {
            if (joga->jogadorAtual == 1) { //jogadorAtual = 1 => jogadorA
                printf("E a vez do jogador %s jogar, que tem a peca %c.\n", jogadorA->nome, jogadorA->peca);
            } else if (joga->jogadorAtual == 2) { //jogadorAtual = 2 => jogadorB
                printf("E a vez do jogador %s jogar, que tem a peca %c.\n", jogadorB->nome, jogadorB->peca);
            }
            segundoMenu(4, *jogadorA); //menu para saber se quer jogar a peça
            scanf("%d", &opcao);
            if (opcao == 1) { // escolhe jogar peça
                if (joga->jogadorAtual == 1) { //vez do jogadorA jogar
                    if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[0], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[1], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[2], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[3], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[4], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[5], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[6], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[7], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorA->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[8], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    }
                } else if (joga->jogadorAtual == 2) { //Vez do jogadorB jogar
                    if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[0].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[0], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 11 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[0]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[1].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[1], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 12 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[1]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 0 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[2].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[2], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 13 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[2]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[3].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[3], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 21 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[3]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[4].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[4], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 22 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[4]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 1 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[5].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[5], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 23 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[5]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 0) {
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[6].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[6], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 31 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[6]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 1) {
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[7].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[7], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 32 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[7]);
                        tab->nJogadas++;
                        mudaJogador(joga);
                    } else if (joga->linhaEscolhida == 2 && joga->colunaEscolhida == 2) {
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        do {
                            pedeLinha(joga);
                            pedeColuna(joga);
                            if (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ') {
                                printf("!!! Essa posicao ja se encontra ocupada !!! \n === Escolha uma posicao diferente! ===\n");
                            }
                        } while (minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] != ' ');
                        minis.miniTab[8].tab[joga->linhaEscolhida][joga->colunaEscolhida] = jogadorB->peca;
                        listaMiniTab = guardarJogadasMinis(&minis.miniTab[8], listaMiniTab, tab);
                        printf("\n=== Mini-Tabuleiro 33 === \n "
                               " === Jogada %d ===\n", tab->nJogadas);
                        mostrarMiniTab(&minis.miniTab[8]);
                        tab->nJogadas++;
                        mudaJogador(joga);

                    }
                }
            } else if (opcao == 2) { //ver jogadas anterior
                int numeroJogadasAVer;
                printf("\n ========================================================================= \n");
                do {
                    printf("Quantas jogadas pretende ver? (1-10)");
                    printf("\nNumero jogadas a ver:");
                    scanf("%d", &numeroJogadasAVer);
                    if (numeroJogadasAVer < 0 || numeroJogadasAVer > 10) {
                        printf("!!! Tem de ver no minimo 1 jogada e no máximo 10 !!!\n");
                    }
                } while (numeroJogadasAVer < 0 || numeroJogadasAVer > 10);
                    if (numeroJogadasAVer <= tab->nJogadas && numeroJogadasAVer > 0 && numeroJogadasAVer <= 10) {
                        mostraJogadas(listaMiniTab, numeroJogadasAVer, tab);
                    }

            } else if (opcao == 3) { //gravar jogo
                guardar(tab, jogadorA, jogadorB, joga, listaMiniTab, minis);
            } else if (opcao == 4) { //sair jogo
                loop = 0;
            }
        }
    } while (loop == 1);
    printf("jogadas totais: %d", tab->nJogadas);
}

//função que vai guardar as jogadas numa lista ligada do tabuleiro grande
pTabuleiro guardarJogadasTabuleiro(Tabuleiro *tab, pTabuleiro principalInicial) {
    Tabuleiro *auxTab;
    if (principalInicial == NULL) {
        principalInicial = malloc(sizeof(Tabuleiro));
        principalInicial->linhas = tab->linhas;
        principalInicial->colunas = tab->colunas;
        //aloquei memória necessária para as linhas do miniTabuleiro
        principalInicial->tab = malloc(sizeof(char *) * principalInicial->linhas);
        //aloquei memória necessária para as colunas do miniTabuleiro
        for (int i = 0; i < principalInicial->linhas; i++) {
            principalInicial->tab[i] = malloc(sizeof(char *) * principalInicial->colunas);
        }
        //guardar os valores do miniTabuleiro
        for (int i = 0; i < principalInicial->linhas; ++i) {
            for (int j = 0; j < principalInicial->colunas; ++j) {
                principalInicial->tab[i][j] = tab->tab[i][j];
            }
        }
    } else {
        //vou buscar o array de miniTabuleiros
        auxTab = principalInicial;
        //percorrer o array até ao último inserido
        while (auxTab->prox != NULL) {
            auxTab = auxTab->prox;
        }
        auxTab = malloc(sizeof(Tabuleiro));
        auxTab->linhas = tab->linhas;
        auxTab->colunas = tab->colunas;
        //aloquei memória necessária para as linhas do miniTabuleiro
        auxTab->tab = malloc(sizeof(char *) * auxTab->linhas);
        //aloquei memória necessária para as colunas do miniTabuleiro
        for (int i = 0; i < auxTab->linhas; i++) {
            auxTab->tab[i] = malloc(sizeof(char *) * auxTab->colunas);
        }
        //guardar os valores do miniTabuleiro
        for (int i = 0; i < auxTab->linhas; i++) {
            for (int j = 0; j < auxTab->colunas; j++) {
                auxTab->tab[i][j] = auxTab->tab[i][j];
            }
        }
        auxTab->prox = NULL;
    }
    return principalInicial;
}


//Função que vai guardar as jogadas numa lista ligada dos mini tabuleiros
pMinis guardarJogadasMinis(Tabuleiro *miniTab, Tabuleiro *lista, Tabuleiro *tab) {
    Tabuleiro *auxMini = NULL;
    if (lista == NULL) {
        lista = malloc(sizeof(Tabuleiro));
        lista->linhas = miniTab->linhas;
        lista->colunas = miniTab->colunas;
        lista->nJogadas = tab->nJogadas;
        printf("Jogadas dentro guarda:%d \n", tab->nJogadas);
        //aloquei memória necessária para as linhas do miniTabuleiro
        lista->tab = malloc(sizeof(char *) * lista->linhas);
        //aloquei memória necessária para as colunas do miniTabuleiro
        for (int i = 0; i < lista->linhas; i++) {
            lista->tab[i] = malloc(sizeof(char *) * lista->colunas);
        }
        //guardar os valores do miniTabuleiro
        for (int i = 0; i < lista->linhas; i++) {
            for (int j = 0; j < lista->colunas; j++) {
                lista->tab[i][j] = miniTab->tab[i][j];
            }
        }
    } else {
        //vou buscar o array de miniTabuleiros
        auxMini = lista;
        //percorrer o array até ao último inserido
        while (auxMini->proxMini != NULL) {
            auxMini = auxMini->proxMini;
            auxMini = malloc(sizeof(Tabuleiro));
            auxMini->linhas = miniTab->linhas;
            auxMini->colunas = miniTab->colunas;
            auxMini->nJogadas = miniTab->nJogadas;
            //aloquei memória necessária para as linhas do miniTabuleiro
            auxMini->tab = malloc(sizeof(char *) * auxMini->linhas);
            //aloquei memória necessária para as colunas do miniTabuleiro
            for (int i = 0; i < auxMini->linhas; i++) {
                auxMini->tab[i] = malloc(sizeof(char *) * auxMini->colunas);
            }
            //guardar os valores do miniTabuleiro
            for (int i = 0; i < auxMini->linhas; i++) {
                for (int j = 0; j < auxMini->colunas; j++) {
                    auxMini->tab[i][j] = miniTab->tab[i][j];
                }
            }
        }
        lista->proxMini = auxMini;
    }

    return lista;
}

//Função para mostrar as jogadas anteriores
void mostraJogadas(pTabuleiro p, int jogadas, Tabuleiro *tab) {
    pTabuleiro auxp = p;
    int jogadasTotais = tab->nJogadas - 1;
    int contador = 1;


    int recuos = (jogadasTotais - jogadas);

    printf("\nJogadas: %d\nJogadas Totais: %d \nrecuos: %d\n", jogadas, jogadasTotais, recuos);

    while (p != NULL) {
        if (contador > recuos && contador < 10 && contador > recuos) {
            printf("Jogada: %d\n", p->nJogadas);
            mostrarMiniTab(p);
        }
        p = p->proxMini;
        contador++;
    }
}

void writeToFile(Tabuleiro *tab, Minis minis) {
    FILE *fptr;
    char nome[20], nomec[20];
    printf("Insira um nome do ficheiro onde pretende guardar o historico: ");
    scanf("%s", nome);
    snprintf(nomec, sizeof(nomec), "historicos/%s.txt", nome);
    fptr = fopen(nomec, "w");
    if (tab == NULL) {
        printf("Error\n");
    } else {
        fprintf(fptr, "=== Historico do jogo ===");
        while (tab != NULL) {
            for (int i = 0; i < 9; i++) {
                fprintf(fptr, "\n=== Jogada tab %d Jogadas minis %d  ===\n", tab->nJogadas, minis.miniTab[i]);
                fprintf(fptr, "  ");
            }
            for (int i = 1; i <= tab->colunas; i++) {
                fprintf(fptr, "%d ", i);
            }
            fprintf(fptr, "\n");
            for (int i = 0; i < tab->linhas; i++) {
                fprintf(fptr, "%d ", i + 1);
                for (int j = 0; j < tab->colunas; j++) {
                    fprintf(fptr, "%c ", tab->tab[i][j]);
                }
                fprintf(fptr, "\n");
            }
            tab = tab->prox;
        }
    }
    fclose(fptr);
    printf("\n");
}

int verificaFicheiro() {
    FILE *fh = fopen("jogo.bin", "rb");
    if (fh == NULL) {
        return 0;
    }
    return 1;
}

void guardar(Tabuleiro *tab, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *inicial, Minis minis) {
    char nomec[20];
    char nome[] = "jogo";
    snprintf(nomec, sizeof(nomec), "%s.bin", nome);
    FILE *fh = fopen(nomec, "wb");
    if (fh == NULL) {
        fprintf(stderr, "\nErro a abrir o ficheiro !!\n");
    } else {
        fwrite(&joga->modo, sizeof(int), 1, fh);
        fwrite(&jogadorA->nome, sizeof(char), 10, fh);
        fwrite(&jogadorB->nome, sizeof(char), 10, fh);
        fwrite(&joga->jogadorAtual, sizeof(int), 1, fh);
        fwrite(&jogadorA->peca, sizeof(char), 1, fh);
        fwrite(&jogadorB->peca, sizeof(char), 1, fh);
        fwrite(&tab->linhas, sizeof(int), 1, fh);
        fwrite(&tab->colunas, sizeof(int), 1, fh);
        fwrite(&tab->nJogadas, sizeof(int), 1, fh);
        for (int i = 0; i < tab->linhas; i++) {
            for (int j = 0; j < tab->colunas; j++) {
                fwrite(&tab->tab[i][j], sizeof(char), 1, fh);
            }
        }
        for (int j = 0; j < 9; j++) {
            for (int i = 0; i < minis.miniTab[j].linhas; i++) {
                for (int k = 0; k < minis.miniTab[j].colunas; k++) {
                    fwrite(&minis.miniTab[j].tab[i][k], sizeof(char), 1, fh);
                }
            }
        }
        /*
        //parte lista ligada
        while(inicial!=NULL){
            fwrite(&inicial->linhas, sizeof(int), 1, fh);
            fwrite(&inicial->colunas, sizeof(int), 1, fh);
            fwrite(&inicial->nJogadas, sizeof(int), 1, fh);
            fwrite(&inicial->prox, sizeof(Tabuleiro), 1, fh);
            for (int i = 0; i < inicial->linhas; i++)
                for (int j = 0; j < inicial->colunas; j++)
                    fwrite(&inicial->tab[i][j], sizeof(char), 1, fh);
            inicial = inicial->prox;
        }*/
    }
    printf("\nJogo guardado com sucesso !!\n");
    fclose(fh);
}


Tabuleiro carregar(Tabuleiro *tab, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *inicial, Minis minis) {
    char nomec[20];
    Tabuleiro *aux = NULL;
    char nome[] = "jogo";

    snprintf(nomec, sizeof(nomec), "%s.bin", nome);
    FILE *fh = fopen(nomec, "rb");
    fread(&joga->modo, sizeof(int), 1, fh);
    fread(&jogadorA->nome, sizeof(char), 10, fh);
    fread(&jogadorB->nome, sizeof(char), 10, fh);
    fread(&joga->jogadorAtual, sizeof(int), 1, fh);
    fread(&jogadorA->peca, sizeof(char), 1, fh);
    fread(&jogadorB->peca, sizeof(char), 1, fh);
    fread(&tab->linhas, sizeof(int), 1, fh);
    fread(&tab->colunas, sizeof(int), 1, fh);
    fread(&tab->nJogadas, sizeof(int), 1, fh);
    tab->tab = malloc(sizeof(char *) * tab->linhas);
    for (int i = 0; i < tab->linhas; i++) {
        tab->tab[i] = malloc(sizeof(char) * tab->colunas);
    }
    for (int i = 0; i < tab->linhas; i++) {
        for (int j = 0; j < tab->colunas; j++) {
            fread(&tab->tab[i][j], sizeof(char), 1, fh);
        }
    }
    for (int i = 0; i < 9; i++) {
        minis.miniTab[i].tab = malloc(sizeof(char *) * minis.miniTab[i].linhas);
        for (int j = 0; j < minis.miniTab[i].linhas; j++) {
            minis.miniTab[i].tab[j] = malloc(sizeof(char) * minis.miniTab[i].colunas);
        }
    }

    /*
    while(!feof(fh)){
        if(inicial==NULL){
            inicial = malloc(sizeof (Tabuleiro));
            fread(&inicial->linhas, sizeof(int), 1, fh);
            fread(&inicial->colunas, sizeof(int), 1, fh);
            fread(&inicial->jogada, sizeof(int), 1, fh);
            fread(&inicial->prox,sizeof (Tabuleiro),1,fh);
            inicial->tab=malloc(sizeof (char*) *inicial->linhas);
            for(int i=0; i<inicial->linhas; i++){
                inicial->tab[i]= malloc(sizeof (char) *inicial->colunas);
            }
            for(int i=0; i<inicial->linhas; i++){
                for(int j=0; j<inicial->colunas; j++){
                    fread(&inicial->tab[i][j], sizeof(char), 1, fh);
                }
            }
            if(inicial->prox!=NULL){
                inicial->prox = malloc(sizeof(Tabuleiro));
            }else{
                fclose(fh);
                return inicial;
            }
        }else{
            aux=inicial;
            while(aux->prox!=NULL)
                aux=aux->prox;
            fread(&aux->linhas, sizeof(int), 1, fh);
            fread(&aux->colunas, sizeof(int), 1, fh);
            fread(&aux->jogada, sizeof(int), 1, fh);
            fread(&aux->prox,sizeof (Tabuleiro),1,fh);
            aux->tab = malloc(sizeof(char*)*aux->linhas);
            for(int i=0; i<aux->linhas; i++){
                aux->tab[i]= malloc(sizeof (char)*aux->colunas);
            }
            for(int i=0;i<aux->linhas;i++){
                for(int j=0;j<aux->colunas;j++){
                    fread(&aux->tab[i][j], sizeof(char), 1, fh);
                }
            }
            if(aux->prox==NULL){
                return inicial;
            }
            aux->prox = malloc(sizeof(Tabuleiro));
        }
    }*/
    fclose(fh);
}


/// TODO: jogadorVSjogador existe empate limpa tabuleiro)
/// TODO: quando alguem ganha jogo no minitab, a sua peça aparece no tab inicial (meter a aparecer o tabuleiro inicial quando este é alterado)
/// TODO: gravar e load
/// TODO: ver jogadas anteriores (minimo 1, maximo 10) mais antiga --> mais recente, não é necessário mostar tabuleiros basta em texto
/// TODO: FINAL do joga exporta para ficheiro jogadas realizadas, nome do ficheiro pedido ao utilizador
/// TODO: Como proibo jogar no mini tabuleiro que o jogo já acabou??