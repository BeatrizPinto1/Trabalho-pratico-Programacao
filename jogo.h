#ifndef TP_JOGO_H
#define TP_JOGO_H


//Estrutura para tabuleiro grande
typedef struct tabuleiro Tabuleiro , *pTabuleiro, *pMinis;
struct tabuleiro {
    char **tab;
    int linhas;
    int colunas;
    int nJogadas;
    pMinis proxMini;
    pTabuleiro prox;
};

typedef struct minis Minis;
struct minis{
    struct tabuleiro miniTab[9];
};

// Estrutura joga
typedef struct joga{
    int modo;
    int jogadorAtual;
    int linhaEscolhida;
    int colunaEscolhida;
}Jogo;

//Estrutura para o jogador
typedef struct jogador{
    char nome[50];
    char peca;
} Jogador;


void segundoMenu(int escolha, Jogador jogadorA);
void mostrarTab(Tabuleiro *tab);
void criarTab(Tabuleiro *tab);
void pedeColuna(Jogo *joga);
void pedeLinha(Jogo *joga);
void mostrarMiniTab(Tabuleiro *miniTab);
void criarMiniTab(Minis *minis);
void jogarBot (Jogador *jogadorA, Jogador *jogadorB ,Jogo *joga ,Tabuleiro *tab, Minis minis, pMinis listaMiniTab);
void inicializaJogadores (int modo, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga);
void mudaJogador (Jogo *joga);
int jogar(Tabuleiro *tab, Jogo *joga, Minis *minis, Jogador jogadorA, Jogador jogadorB, pMinis listaMiniTab);
void jogadorVSjogador(Jogador *jogadorA, Jogador *jogadorB ,Jogo *joga ,Tabuleiro *tab,Minis minis, pMinis listaMiniTab);
pMinis guardarJogadasMinis(Tabuleiro *miniTab, Tabuleiro *lista, Tabuleiro *tab);
pTabuleiro guardarJogadasTabuleiro(Tabuleiro *tab, pTabuleiro principalInicial);
void mostraJogadas(pTabuleiro p, int jogadas, Tabuleiro *tab);
void writeToFile(Tabuleiro *tab, Minis minis);
int verificaFicheiro();
void guardar(Tabuleiro *tab, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *inicial, Minis minis);
Tabuleiro carregar(Tabuleiro *tab, Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *inicial, Minis minis);
int jogarJogoCarregado(Tabuleiro *tab, Jogo *joga, Minis *minis, Jogador jogadorA, Jogador jogadorB, pMinis listaMiniTab);
int verificaLinhaTabGrande(Tabuleiro *tab);
int verificaLinhaMinis(Minis minis);
int verificaColunaTabGrande(Tabuleiro *tab);
int verificaColunaMinis(Minis minis);
int verificaDiagonalTabGrande(Tabuleiro *tab);
int verificaDiagonalMinis(Minis minis);
int verificaEmpateTabGrande(Tabuleiro *tab);
int verificaEmpateMinis(Minis minis);
int fimJogoTabGrande(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Tabuleiro *tab);
int fimJogoMinis(Jogador *jogadorA, Jogador *jogadorB, Jogo *joga, Minis minis, Tabuleiro *tab);


#endif //TP_JOGO_H

