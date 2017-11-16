#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BRANCO 1
#define PRETO 0
#define LARGURATABULEIRO 8
#define COMPRIMENTOTABULEIRO 8
#define TAMANHOJOGADA 7

typedef struct{
    int x, y;
    int foraDoJogo;
}Peca;

typedef struct{
    Peca cavalo1;
    Peca cavalo2;
    Peca rei;
    Peca rainha;
    Peca bispo1;
    Peca bispo2;
    Peca torre1;
    Peca torre2;
    Peca peao[8];
}Jogador;

void mostrarMensagemMenu(int *opcao){
    system("clear");
    printf("-----------------------\n");
    printf("--------XADREZ---------\n");
    printf("-- 1 -> Novo Jogo -----\n");
    printf("-- 2 -> Sair ----------\n");
    printf("-----------------------\n");

    printf("\nDigite sua opcao: ");
    scanf("%d", opcao);

    while(*opcao != 1 && *opcao != 2){
        printf("\n\nOps. Voce digitou uma opcao invalida. Insira uma nova opcao: ");
        scanf("%d", opcao);
    }
}

void mostrarMensagemSaida(){
    printf("-------------------------\n");
    printf("-- Obrigado por jogar! --\n");
    printf("--------- GGML ----------\n");
}

void mostraMensagemMovimentoInvalido(){
    printf("\n*** O movimento que voce tentou fazer eh invalido. ***\n");
    printf("*** Lembre que voce nao pode comer sua propria peca, ficar na mesma posicao***\n");
    printf("*** ou realizar movimentos incondizentes com a peca que voce quer mover.\n\n");
    printf("*** Insira um novo movimento: ");
}

void mostrarMensagemJogadaBranco(){
    printf("\n---- Jogador da vez: branco (pecas minusculas)\n");
    printf("---- Jogada: ");
}

void mostrarMensagemJogadaPreto(){
    printf("\n---- Jogador da vez: preto (pecas maiusculas)\n");
    printf("---- Jogada: ");
}

void mostrarTabuleiro(char tabuleiro[][LARGURATABULEIRO]){
    system("clear");
    printf("\n------ TABULEIRO ATUAL ------\n");

    printf("   ");

    for(int i = 0; i < 8; ++i){
        printf(" %c ", 'a' + i);
    }

    printf("\n\n");

    for(int i = 0; i < COMPRIMENTOTABULEIRO; ++i){
        printf(" %d ", 1+i);
        for(int j = 0; j < LARGURATABULEIRO; ++j){
            printf(" %c ", tabuleiro[i][j]);
        }
        printf(" %d \n", 1+i);
    }

    printf("\n");

    printf("   ");

    for(int i = 0; i < 8; ++i){
        printf(" %c ", 'a' + i);
    }

    printf("\n-----------------------------\n\n");
}

void marcaPecaBranca(char peca, int Xinicial, int Yinicial, int Xfinal, int Yfinal, Jogador *branco){
    int i;
    switch(peca){
        case 'p':
            for(i = 0; i < 8; ++i){
                if(!branco->peao[i].foraDoJogo){
                    if(branco->peao[i].x == Xinicial && branco->peao[i].y == Yinicial){
                        branco->peao[i].x = Xfinal;
                        branco->peao[i].y = Yfinal;
                        break;
                    }
                }
            }
            break;
        case 't':
            if(branco->torre1.x == Xinicial && branco->torre1.y == Yinicial){
                branco->torre1.x = Xfinal;
                branco->torre1.y = Yfinal;
            } else{
                branco->torre2.x = Xfinal;
                branco->torre2.y = Yfinal;
            }
            break;
        case 'r':
            branco->rei.x = Xfinal;
            branco->rei.y = Xfinal;
            break;
        case 'c':
            if(branco->cavalo1.x == Xinicial && branco->cavalo1.y == Yinicial){
                branco->cavalo1.x = Xfinal;
                branco->cavalo1.y = Yfinal;
            } else{
                branco->cavalo2.x = Xfinal;
                branco->cavalo2.y = Yfinal;
            }
            break;
        case 'd':
            branco->rainha.x = Xfinal;
            branco->rainha.y = Yfinal;
            break;
        case 'b':
            if(branco->bispo1.x == Xinicial && branco->bispo1.y == Yinicial){
                branco->bispo1.x = Xfinal;
                branco->bispo1.y = Yfinal;
            } else{
                branco->bispo2.x = Xfinal;
                branco->bispo2.y = Yfinal;
            } 
            break;
    }
}

void marcaPecaPreta(char peca, int Xinicial, int Yinicial, int Xfinal, int Yfinal, Jogador *preto){
    int i;
    switch(peca){
        case 'p':
            for(i = 0; i < 8; ++i){
                if(!preto->peao[i].foraDoJogo){
                    if(preto->peao[i].x == Xinicial && preto->peao[i].y == Yinicial){
                        preto->peao[i].x = Xfinal;
                        preto->peao[i].y = Yfinal;
                        break;
                    }
                }
            }
            break;
        case 't':
            if(preto->torre1.x == Xinicial && preto->torre1.y == Yinicial){
                preto->torre1.x = Xfinal;
                preto->torre1.y = Yfinal;
            } else{
                preto->torre2.x = Xfinal;
                preto->torre2.y = Yfinal;
            }
            break;
        case 'r':
            preto->rei.x = Xfinal;
            preto->rei.y = Xfinal;
            break;
        case 'c':
            if(preto->cavalo1.x == Xinicial && preto->cavalo1.y == Yinicial){
                preto->cavalo1.x = Xfinal;
                preto->cavalo1.y = Yfinal;
            } else{
                preto->cavalo2.x = Xfinal;
                preto->cavalo2.y = Yfinal;
            }
            break;
        case 'd':
            preto->rainha.x = Xfinal;
            preto->rainha.y = Yfinal;
            break;
        case 'b':
            if(preto->bispo1.x == Xinicial && preto->bispo1.y == Yinicial){
                preto->bispo1.x = Xfinal;
                preto->bispo1.y = Yfinal;
            } else{
                preto->bispo2.x = Xfinal;
                preto->bispo2.y = Yfinal;
            } 
            break;
    }
}

void desmarcaPecaBranca(char peca, int x, int y, Jogador *branco){
    int i;
    switch(peca){
        case 'p':
            for(i = 0; i < 8; ++i){
                if(!branco->peao[i].foraDoJogo){
                    if(branco->peao[i].x == x && branco->peao[i].y == y){
                        branco->peao[i].foraDoJogo = 1;
                        break;
                    }
                }
            }
            break;
        case 't':
            if(branco->torre1.x == x && branco->torre1.y == y){
                branco->torre1.foraDoJogo = 1;
            } else{
                branco->torre2.foraDoJogo = 1;
            }
            break;
        case 'c':
            if(branco->cavalo1.x == x && branco->cavalo1.y == y){
                branco->cavalo1.foraDoJogo = 1;
            } else{
                branco->cavalo2.foraDoJogo = 1;
            }
            break;
        case 'r':
            branco->rei.foraDoJogo = 1;
            break;
        case 'd':
            branco->rainha.foraDoJogo = 1;
            break;
        case 'b':
            if(branco->bispo1.x == x && branco->bispo1.y == y){
                branco->bispo1.foraDoJogo = 1;
            } else{
                branco->bispo2.foraDoJogo = 1;
            } 
            break;
    }
}

void desmarcaPecaPreta(char peca, int x, int y, Jogador *preto){
    int i;
    switch(peca){
        case 'P':
            for(i = 0; i < 8; ++i){
                if(!preto->peao[i].foraDoJogo){
                    if(preto->peao[i].x == x && preto->peao[i].y == y){
                        preto->peao[i].foraDoJogo = 1;
                        break;
                    }
                }
            }
            break;
        case 'T':
            if(preto->torre1.x == x && preto->torre1.y == y){
                preto->torre1.foraDoJogo = 1;
            } else{
                preto->torre2.foraDoJogo = 1;
            }
            break;
        case 'C':
            if(preto->cavalo1.x == x && preto->cavalo1.y == y){
                preto->cavalo1.foraDoJogo = 1;
            } else{
                preto->cavalo2.foraDoJogo = 1;
            }
            break;
        case 'R':
            preto->rei.foraDoJogo = 1;
            break;
        case 'D':
            preto->rainha.foraDoJogo = 1;
            break;
        case 'B':
            if(preto->bispo1.x == x && preto->bispo1.y == y){
                preto->bispo1.foraDoJogo = 1;
            } else{
                preto->bispo2.foraDoJogo = 1;
            } 
            break;
    }
}

int pecaEhValida(char peca, int jogadorAtual){
    switch(jogadorAtual){
        case BRANCO:
            if(peca == 't' || peca == 'b' || peca == 'd' || peca == 'r' || peca == 'p' || peca == 'c') return 1;
            else return 0;
            break;
        case PRETO:
            if(peca == 'T' || peca == 'B' || peca == 'D' || peca == 'R' || peca == 'P' || peca == 'C') return 1;
            else return 0;
            break;
    }
    return 0;
}

int verificaMovimentoPeao(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    int distanciaX = abs(Xfinal - Xinicial);
    switch(jogador){
        case BRANCO:
            if(Xinicial == 6){
                if(Yfinal == Yinicial){
                    if(distanciaX == 1){
                        if(tabuleiro[Xfinal][Yfinal] == '.') return 1;
                        else if(isupper(tabuleiro[Xfinal][Yfinal])) return 1;
                    } else if(distanciaX == 2){
                        for(int i = 1; i <= 2; ++i){
                            if(tabuleiro[Xfinal-i][Yfinal] != '.'){
                                if(!isupper(tabuleiro[Xfinal-i][Yfinal])) return 0;
                            }
                        }
                        return 1;
                    }
                } else{
                    if(Yfinal == Yinicial + 1 || Yfinal == Yinicial - 1){
                        if(Xfinal == Xinicial - 1){
                            if(isupper(tabuleiro[Xfinal][Yfinal])){
                                return 1;
                            }
                        }
                    }
                }
            } else{
                if(Yfinal == Yinicial){
                    if(distanciaX == 1) return 1;
                } else{
                    if(Yfinal == Yinicial + 1 || Yfinal == Yinicial - 1){
                        if(Xfinal == Xinicial - 1){
                            if(isupper(tabuleiro[Xfinal][Yfinal])){
                                return 1;
                            }
                        }
                    }
                }
            }
            break;
        case PRETO:
            if(Xinicial == 1){
                if(Yfinal == Yinicial){
                    printf("DistanciaX eh %d\n", distanciaX);
                    if(distanciaX == 1){
                        if(tabuleiro[Xfinal][Yfinal] == '.') return 1;
                        else if(islower(tabuleiro[Xfinal][Yfinal])) return 1;
                    } else if(distanciaX == 2){
                        for(int i = 1; i <= 2; ++i){
                            if(tabuleiro[Xfinal+i][Yfinal] != '.'){
                                if(!islower(tabuleiro[Xfinal+i][Yfinal])) return 0;
                            }
                        }
                        return 1;
                    }
                } else{
                    if(Yfinal == Yinicial + 1 || Yfinal == Yinicial - 1){
                        if(Xfinal == Xinicial + 1){
                            if(islower(tabuleiro[Xfinal][Yfinal])){
                                return 1;
                            }
                        }
                    }
                }
            } else{
                if(Yfinal == Yinicial){
                    if(distanciaX == 1) return 1;
                } else{
                    if(Yfinal == Yinicial + 1 || Yfinal == Yinicial - 1){
                        if(Xfinal == Xinicial + 1){
                            if(islower(tabuleiro[Xfinal][Yfinal])){
                                return 1;
                            }
                        }
                    }
                }
            }
            break;
    }
    return 0;
}

int verificaMovimentoTorre(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    int i;
    switch(jogador){
        case BRANCO:
            if(Xinicial == Xfinal){
                if(Yinicial > Yfinal){
                    for(i = Yfinal + 1; i < Yinicial; ++i){
                        if(tabuleiro[Xinicial][i] != '.') return 0;
                    }
                } else{
                    for(i = Yinicial + 1; i < Yfinal; ++i){
                        if(tabuleiro[Xinicial][i] != '.') return 0;
                    }
                }
            } else if(Yinicial == Yfinal){
                if(Xinicial > Xfinal){
                    for(i = Xfinal + 1; i < Xinicial; ++i){
                        if(tabuleiro[i][Yinicial] != '.') return 0;
                    }
                } else{
                    for(i = Xinicial + 1; i < Xfinal; ++i){
                        if(tabuleiro[i][Yinicial] != '.') return 0;
                    }
                }
            }
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && islower(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
        case PRETO:
            if(Xinicial == Xfinal){
                if(Yinicial > Yfinal){
                    for(i = Yfinal + 1; i < Yinicial; ++i){
                        if(tabuleiro[Xinicial][i] != '.') return 0;
                    }
                } else{
                    for(i = Yinicial + 1; i < Yfinal; ++i){
                        if(tabuleiro[Xinicial][i] != '.') return 0;
                    }
                }
            } else if(Yinicial == Yfinal){
                if(Xinicial > Xfinal){
                    for(i = Xfinal + 1; i < Xinicial; ++i){
                        if(tabuleiro[i][Yinicial] != '.') return 0;
                    }
                } else{
                    for(i = Xinicial + 1; i < Xfinal; ++i){
                        if(tabuleiro[i][Yinicial] != '.') return 0;
                    }
                }
            }
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
    }

    return 1;
}

int verificaMovimentoBispo(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    if(abs(Xinicial - Xfinal) != abs(Yinicial - Yfinal)) return 0;

    int i;

    switch(jogador){
        case BRANCO:
            if(Xfinal > Xinicial){
                if(Yfinal > Yinicial){
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial + i][Yinicial + i] != '.') return 0;
                    }
                } else{
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial + i][Yinicial - i] != '.') return 0;
                    }
                }
            } else{
                if(Yfinal > Yinicial){
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial - i][Yinicial + i] != '.') return 0;
                    }
                } else{
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial - i][Yinicial - i] != '.') return 0;
                    }
                }
            }
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && islower(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
        case PRETO:
            if(Xfinal > Xinicial){
                if(Yfinal > Yinicial){
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial + i][Yinicial + i] != '.') return 0;
                    }
                } else{
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial + i][Yinicial - i] != '.') return 0;
                    }
                }
            } else{
                if(Yfinal > Yinicial){
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial - i][Yinicial + i] != '.') return 0;
                    }
                } else{
                    for(i = 1; Xinicial + i != Xfinal; ++i){
                        if(tabuleiro[Xinicial - i][Yinicial - i] != '.') return 0;
                    }
                }
            }
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
    }

    return 0;
}

int verificaMovimentoRei(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    int movReiX[] = { -1, -1, -1,  1, 1, 1,  0, 0 };
    int movReiY[] = { -1,  0,  1, -1, 0, 1, -1, 1 };

    int i;

    for(i = 0; i < 8; ++i){
        int x = movReiX[i] + Xinicial;
        int y = movReiY[i] + Yinicial;
        if(x == Xfinal && y == Yfinal){
            if(x >= 0 && x < 8 && y >= 0 && y < 8){
                switch(jogador){
                    case BRANCO:
                        if(isupper(tabuleiro[x][y]) || tabuleiro[x][y] == '.') return 1;
                        break;
                    case PRETO:
                        if(islower(tabuleiro[x][y]) || tabuleiro[x][y] == '.') return 1;
                        break;
                }
            }
            break;
        }
    }

    return 0;
}

int verificaMovimentoRainha(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    int i;

    if(Xinicial == Xfinal){
        if(Yinicial > Yfinal){
            for(i = Yfinal + 1; i < Yinicial; ++i){
                if(tabuleiro[Xinicial][i] != '.') return 0;
            }
        } else{
            for(i = Yinicial + 1; i < Yfinal; ++i){
                if(tabuleiro[Xinicial][i] != '.') return 0;
            }
        }
    } else if(Yinicial == Yfinal){
        if(Xinicial > Xfinal){
            for(i = Xfinal + 1; i < Xinicial; ++i){
                if(tabuleiro[i][Yinicial] != '.') return 0;
            }
        } else{
            for(i = Xinicial + 1; i < Xfinal; ++i){
                if(tabuleiro[i][Yinicial] != '.') return 0;
            }
        }
    } else if(abs(Xinicial - Xfinal) == abs(Yinicial - Yfinal)){
        if(Xfinal > Xinicial){
            if(Yfinal > Yinicial){
                for(i = 1; ; ++i){
                    if(Xinicial + i == Xfinal) break;
                    if(tabuleiro[Xinicial + i][Yinicial + i] != '.') return 0;
                }
            } else{
                for(i = 1; ; ++i){
                    if(Xinicial + i == Xfinal) break;
                    if(tabuleiro[Xinicial + i][Yinicial - i] != '.') return 0;
                }
            }
        } else{
            if(Yfinal > Yinicial){
                for(i = 1; ; ++i){
                    if(Xinicial - i == Xfinal) break;
                    if(tabuleiro[Xinicial - i][Yinicial + i] != '.') return 0;
                }
            } else{
                for(i = 1; ; ++i){
                    if(Xinicial - i == Xfinal) break;
                    if(tabuleiro[Xinicial - i][Yinicial - i] != '.') return 0;
                }
            }
        }
    } else return 0;

    switch(jogador){
        case BRANCO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && islower(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
        case PRETO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
    }

    return 1;
}

int verificaMovimentoCavalo(int jogador, int Xinicial, int Yinicial, int Xfinal, int Yfinal, char tabuleiro[][LARGURATABULEIRO]){
    int i;
    int movCavaloX[] = {  1, 1, -1, -1, 2, 2, -2, -2 };
    int movCavaloY[] = { -2, 2, -2,  2, 1, -1, 1, -1 };

    switch(jogador){
        case BRANCO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && islower(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
        case PRETO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])) return 0;
            break;
    }

    for(i = 0; i < 8; ++i){
        int x = Xinicial + movCavaloX[i];
        int y = Yinicial + movCavaloY[i];
        if(x == Xfinal && y == Yfinal){
            if(x >= 0 && x < 8 && y >= 0 && y < 8) return 1;
            break;
        }
    }

    return 0;
}

int coordenadasValidas(char jogada[TAMANHOJOGADA], int jogadorAtual, char tabuleiro[][LARGURATABULEIRO]){
    char peca = jogada[0];

    int Yinicial = jogada[1] - 'a';
    int Xinicial = jogada[2] - '0' - 1;

    int Yfinal = jogada[4] - 'a';
    int Xfinal = jogada[5] - '0' - 1;

    // printf("Xi,Yi = %d,%d\n", Xinicial, Yinicial);
    // printf("Xf,Yf = %d,%d\n", Xfinal, Yfinal);

    if(Xfinal < 0 || Xfinal >= COMPRIMENTOTABULEIRO) return 0;
    if(Xinicial < 0 || Xinicial >= COMPRIMENTOTABULEIRO) return 0;
    if(Yinicial < 0 || Yinicial >= LARGURATABULEIRO) return 0;
    if(Yfinal < 0 || Yinicial >= LARGURATABULEIRO) return 0;
    if(Xfinal == Xinicial && Yfinal == Yinicial) return 0;

    // printf("my x,y == %d,%d\n", Xinicial, Yinicial);

    // printf("%c %c\n", tabuleiro[Xinicial][Yinicial], peca);

    if(peca != tabuleiro[Xinicial][Yinicial]) return 0;

    printf("nao passei\n");

    switch(jogadorAtual){
        case BRANCO:
            switch(peca){
                case 't':
                    if(!verificaMovimentoTorre(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'c':
                    if(!verificaMovimentoCavalo(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'd':
                    if(!verificaMovimentoRainha(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'r':
                    if(!verificaMovimentoRei(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'b':
                    if(!verificaMovimentoBispo(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'p':
                    if(!verificaMovimentoPeao(BRANCO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
            }
            break;
        case PRETO:
            switch(peca){
                case 'T':
                    if(!verificaMovimentoTorre(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'C':
                    if(!verificaMovimentoCavalo(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'D':
                    if(!verificaMovimentoRainha(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'R':
                    if(!verificaMovimentoRei(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'B':
                    if(!verificaMovimentoBispo(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
                case 'P':
                    if(!verificaMovimentoPeao(PRETO, Xinicial, Yinicial, Xfinal, Yfinal, tabuleiro)) return 0;
                    break;
            }   
            break;
    }

    return 1;
}

int movimentoValido(int jogadorAtual, char jogada[TAMANHOJOGADA], char tabuleiro[][LARGURATABULEIRO]){
    if(!pecaEhValida(jogada[0], jogadorAtual)) return 0;
    printf("deu pau aqui\n");
    if(!coordenadasValidas(jogada, jogadorAtual, tabuleiro)) return 0;

    return 1;
}

void colocaPecaPreta(int x, int y, char tabuleiro[][LARGURATABULEIRO], Jogador *preto){
    switch(x){
        case 0:
            switch(y){
                case 0:
                    tabuleiro[x][y] = 'T';
                    preto->torre1.x = x;
                    preto->torre1.y = y;
                    preto->torre1.foraDoJogo = 0;
                    break;
                case 1:
                    tabuleiro[x][y] = 'C';
                    preto->cavalo1.x = x;
                    preto->cavalo1.y = y;
                    preto->cavalo1.foraDoJogo = 0;
                    break;
                case 2:
                    tabuleiro[x][y] = 'B';
                    preto->bispo1.x = x;
                    preto->bispo1.y = y;
                    preto->bispo1.foraDoJogo = 0;
                    break;
                case 3:
                    tabuleiro[x][y] = 'R';
                    preto->rei.x = x;
                    preto->rei.y = y;
                    preto->rei.foraDoJogo = 0;
                    break;
                case 4:
                    tabuleiro[x][y] = 'D';
                    preto->rainha.x = x;
                    preto->rainha.y = y;
                    preto->rainha.foraDoJogo = 0;
                    break;
                case 5:
                    tabuleiro[x][y] = 'B';
                    preto->bispo2.x = x;
                    preto->bispo2.y = y;
                    preto->bispo2.foraDoJogo = 0;
                    break;
                case 6:
                    tabuleiro[x][y] = 'C';
                    preto->cavalo2.x = x;
                    preto->cavalo2.y = y;
                    preto->cavalo2.foraDoJogo = 0;
                    break;
                case 7:
                    tabuleiro[x][y] = 'T';
                    preto->torre2.x = x;
                    preto->torre2.y = y;
                    preto->torre2.foraDoJogo = 0;
                    break;
            }
            break;
        case 1:
            tabuleiro[x][y] = 'P';
            preto->peao[y].x = x;
            preto->peao[y].y = y;
            preto->peao[y].foraDoJogo = 0;
            break;
    }
}

void colocaPecaBranca(int x, int y, char tabuleiro[][LARGURATABULEIRO], Jogador *branco){
    switch(x){
        case 6:
            tabuleiro[x][y] = 'p';
            branco->peao[y].x = x;
            branco->peao[y].y = y;
            branco->peao[y].foraDoJogo = 0;
            break;
        case 7:
            switch(y){
                case 0:
                    tabuleiro[x][y] = 't';
                    branco->torre1.x = x;
                    branco->torre1.y = y;
                    branco->torre1.foraDoJogo = 0;
                    break;
                case 1:
                    tabuleiro[x][y] = 'c';
                    branco->cavalo1.x = x;
                    branco->cavalo1.y = y;
                    branco->cavalo1.foraDoJogo = 0;
                    break;
                case 2:
                    tabuleiro[x][y] = 'b';
                    branco->bispo1.x = x;
                    branco->bispo1.y = y;
                    branco->bispo1.foraDoJogo = 0;
                    break;
                case 3:
                    tabuleiro[x][y] = 'r';
                    branco->rei.x = x;
                    branco->rei.y = y;
                    branco->rei.foraDoJogo = 0;
                    break;
                case 4:
                    tabuleiro[x][y] = 'd';
                    branco->rainha.x = x;
                    branco->rainha.y = y;
                    branco->rainha.foraDoJogo = 0;
                    break;
                case 5:
                    tabuleiro[x][y] = 'b';
                    branco->bispo2.x = x;
                    branco->bispo2.y = y;
                    branco->bispo2.foraDoJogo = 0;
                    break;
                case 6:
                    tabuleiro[x][y] = 'c';
                    branco->cavalo2.x = x;
                    branco->cavalo2.y = y;
                    branco->cavalo2.foraDoJogo = 0;
                    break;
                case 7:
                    tabuleiro[x][y] = 't';
                    branco->torre2.x = x;
                    branco->torre2.y = y;
                    branco->torre2.foraDoJogo = 0;
                    break;
            }
            break;
    }
}

void inicializarTabuleiro(char tabuleiro[][LARGURATABULEIRO], Jogador *preto, Jogador *branco){
    int i, j;

    for(i = 0; i < 8; ++i){
        for(j = 0; j < 8; ++j){
            if(i == 0 || i == 1){
                colocaPecaPreta(i, j, tabuleiro, preto);
            } else if(i == 7 || i == 6){
                colocaPecaBranca(i, j, tabuleiro, branco);
            } else tabuleiro[i][j] = '.';
        }
    }
}

void printaPartidasNoArquivo(char **jogadasPreto, char **jogadasBranco, int qtdJogadasPreto, int qtdJogadasBranco){
    int i;

    FILE *partidas = fopen("partidas.bin", "ab");

    char pulaLinha[3];
    char separador[18];
    char jogadasP1[50];
    char jogadasP2[50];

    strcpy(pulaLinha, "\n");
    strcpy(separador, "\n-------------\n");
    strcpy(jogadasP1, "Jogadas do jogador preto: ");
    strcpy(jogadasP2, "Jogadas do jogador branco: ");

    fwrite(jogadasP1, sizeof(char), strlen(jogadasP1), partidas);

    for(i = 0; i < qtdJogadasPreto; ++i){
        fwrite(jogadasPreto[i], sizeof(char), strlen(jogadasPreto[i]), partidas);
    }

    fwrite(pulaLinha, sizeof(char), strlen(pulaLinha), partidas);
    fwrite(jogadasP2, sizeof(char), strlen(jogadasP2), partidas);

    for(i = 0; i < qtdJogadasBranco; ++i){
        fwrite(jogadasBranco[i], sizeof(char), strlen(jogadasBranco[i]), partidas);
    }

    fwrite(pulaLinha, sizeof(char), strlen(pulaLinha), partidas);
    fwrite(pulaLinha, sizeof(char), strlen(pulaLinha), partidas);

    fwrite(separador, sizeof(char), strlen(pulaLinha), partidas);

    fclose(partidas);
}

int chegaNoRei(int jogadorAtual, int xRei, int yRei, int peca, char tabuleiro[][LARGURATABULEIRO], int x, int y){
    int i;

    switch(jogadorAtual){
        case BRANCO:
            switch(peca){
                case 't':
                    if(xRei == x){
                        if(yRei > y){
                            for(i = y+1; i < yRei; ++i){
                                if(tabuleiro[xRei][i] != '.') return 0;
                            }
                        } else{
                            for(i = y-1; i > yRei; --i){
                                if(tabuleiro[xRei][i] != '.') return 0;
                            }
                        }
                    } else if(yRei == y){
                        if(xRei > x){
                            for(i = x+1; i < xRei; ++i){
                                if(tabuleiro[i][yRei] != '.') return 0;
                            }
                        } else{
                            for(i = x-1; i > xRei; --i){
                                if(tabuleiro[i][yRei] != '.') return 0;
                            }
                        }
                    }
                    break;
                case 'c':
                    if(xRei == x + 1 || xRei == x - 1){
                        if(yRei == y + 2 || yRei == y - 2) return 1;
                    } else if(xRei == x + 2 || xRei == x - 2){
                        if(yRei == y + 1 || yRei == y - 1) return 1;
                    }
                    break;
                case 'b':
                    break;
                case 'd':
                    break;
                case 'p':
                    if(xRei == x - 1){
                        if(yRei == y - 1 || yRei == y + 1) return 1;
                    }
                    break;
            }
            break;
        case PRETO:
            switch(peca){
                case 'T':
                    if(xRei == x){
                        if(yRei > y){
                            for(i = y+1; i < yRei; ++i){
                                if(tabuleiro[xRei][i] != '.') return 0;
                            }
                        } else{
                            for(i = y-1; i > yRei; --i){
                                if(tabuleiro[xRei][i] != '.') return 0;
                            }
                        }
                    } else if(yRei == y){
                        if(xRei > x){
                            for(i = x+1; i < xRei; ++i){
                                if(tabuleiro[i][yRei] != '.') return 0;
                            }
                        } else{
                            for(i = x-1; i > xRei; --i){
                                if(tabuleiro[i][yRei] != '.') return 0;
                            }
                        }
                    }
                    break;
                case 'C':
                    if(xRei == x + 1 || xRei == x - 1){
                        if(yRei == y + 2 || yRei == y - 2) return 1;
                    } else if(xRei == x + 2 || xRei == x - 2){
                        if(yRei == y + 1 || yRei == y - 1) return 1;
                    }
                    break;
                case 'B':
                    break;
                case 'D':
                    break;
                case 'P':
                    if(xRei == x + 1){
                        if(yRei == y - 1 || yRei == y + 1) return 1;
                    }
                    break;
            }
            break;
    }

    return 0;
}

int provavelXeque(int jogadorAtual, int x, int y, char tabuleiro[][LARGURATABULEIRO], Jogador *preto, Jogador *branco){
    int xRei, yRei;
    char pecaAtual = tabuleiro[x][y];

    switch(jogadorAtual){
        case BRANCO:
            xRei = branco->rei.x;
            yRei = branco->rei.y;
            break;
        case PRETO:
            xRei = preto->rei.x;
            yRei = preto->rei.y;
            break;
    }

    if(chegaNoRei(jogadorAtual, xRei, yRei, pecaAtual, tabuleiro, x, y)) return 1;

    return 0;
}

void processaJogada(int jogadorAtual, char jogada[TAMANHOJOGADA], char tabuleiro[][LARGURATABULEIRO], int *xeque, Jogador *preto, Jogador *branco){
    char peca = jogada[0];

    int Yinicial = jogada[1] - 'a';
    int Xinicial = jogada[2] - '0' - 1;

    int Yfinal = jogada[4] - 'a';
    int Xfinal = jogada[5] - '0' - 1;

    tabuleiro[Xinicial][Yinicial] = '.';

    switch(jogadorAtual){
        case BRANCO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])){
                desmarcaPecaPreta(tabuleiro[Xfinal][Yfinal], Xfinal, Yfinal, preto);
            }
            marcaPecaBranca(peca, Xinicial, Yinicial, Xfinal, Yfinal, branco);
            tabuleiro[Xfinal][Yfinal] = peca;
            break;
        case PRETO:
            if(isalpha(tabuleiro[Xfinal][Yfinal]) && isupper(tabuleiro[Xfinal][Yfinal])){
                desmarcaPecaBranca(tabuleiro[Xfinal][Yfinal], Xfinal, Yfinal, branco);
            }
            marcaPecaPreta(peca, Xinicial, Yinicial, Xfinal, Yfinal, preto);
            tabuleiro[Xfinal][Yfinal] = peca;
            break;
    }

    //if(provavelXeque(jogadorAtual, Xfinal, Yfinal, tabuleiro, preto, branco)) (*xeque) = 1;
    if(branco->rei.foraDoJogo) (*xeque) = 2;
    else if(preto->rei.foraDoJogo) (*xeque) = 1;
}

void mensagemVencedorBranco(int *opcao){
    system("clear");
    printf("\n--------------------------------\n");
    printf("--- O jogador branco ganhou! ---\n");
    printf("--- O que vamos fazer agora? ---\n");
    printf("--- 1 -> Menu inicial ----------\n");
    printf("--- 2 -> Sair do jogo ----------\n");
    printf("--------------------------------\n");

    printf("\nDigite sua escolha: \n");

    scanf("%d", opcao);

    while((*opcao) != 1 && (*opcao) != 2){
        printf("Escolha invalida. Insira ou 1, ou 2: ");
        scanf("%d", opcao);
    }
}

void mensagemVencedorPreto(int *opcao){
    system("clear");
    printf("\n--------------------------------\n");
    printf("--- O jogador preto ganhou! ---\n");
    printf("--- O que vamos fazer agora? ---\n");
    printf("--- 1 -> Menu inicial ----------\n");
    printf("--- 2 -> Sair do jogo ----------\n");
    printf("--------------------------------\n");

    printf("\nDigite sua escolha: \n");

    scanf("%d", opcao);

    while((*opcao) != 1 && (*opcao) != 2){
        printf("Escolha invalida. Insira ou 1, ou 2: ");
        scanf("%d", opcao);
    }
}

int main(){
    char tabuleiro[COMPRIMENTOTABULEIRO][LARGURATABULEIRO];

    int menuInicial = 1;
    int jogo = 0;
    int menuSair = 0;
    int opcao;

    int menuBrancoGanhou = 0;
    int menuPretoGanhou = 0;
    int brancoGanhou = 0;
    int pretoGanhou = 0;

    int i;

    while(1){

        while(menuInicial){
            mostrarMensagemMenu(&opcao);
            switch(opcao){
                case 1:
                    jogo = 1;
                    menuInicial = 0;
                    break;
                case 2:
                    menuInicial = 0;
                    menuSair = 1;
                    break;
            }
        }

        while(jogo){
            char **jogadasPreto = NULL;
            char **jogadasBranco = NULL;

            brancoGanhou = 0;
            pretoGanhou = 0;

            int qtdJogadasPreto = 0;
            int qtdJogadasBranco = 0;
            int xequeMate = 0;
            int xeque = 0;

            int jogadorAtual = BRANCO;

            Jogador preto;
            Jogador branco;

            inicializarTabuleiro(tabuleiro, &preto, &branco);

            while(!xequeMate){
                mostrarTabuleiro(tabuleiro);

                if(jogadorAtual == BRANCO){
                    mostrarMensagemJogadaBranco();
                    qtdJogadasBranco++;
                    jogadasBranco = (char **) realloc(jogadasBranco, (qtdJogadasBranco)*sizeof(char *));
                    jogadasBranco[qtdJogadasBranco - 1] = (char *) malloc(TAMANHOJOGADA);

                    scanf(" %s", jogadasBranco[qtdJogadasBranco - 1]);

                    while(!movimentoValido(BRANCO, jogadasBranco[qtdJogadasBranco - 1], tabuleiro)){
                        mostraMensagemMovimentoInvalido();
                        scanf(" %s", jogadasBranco[qtdJogadasBranco - 1]);
                    }

                    processaJogada(BRANCO, jogadasBranco[qtdJogadasBranco - 1], tabuleiro, &xeque, &preto, &branco);

                } else{
                    mostrarMensagemJogadaPreto();
                    qtdJogadasPreto++;
                    jogadasPreto = (char **) realloc(jogadasPreto, (qtdJogadasPreto)*sizeof(char *));
                    jogadasPreto[qtdJogadasPreto - 1] = (char *) malloc(TAMANHOJOGADA);

                    scanf(" %s", jogadasPreto[qtdJogadasPreto - 1]);

                    while(!movimentoValido(PRETO, jogadasPreto[qtdJogadasPreto - 1], tabuleiro)){
                        mostraMensagemMovimentoInvalido();
                        scanf(" %s", jogadasPreto[qtdJogadasPreto - 1]);
                    }

                    processaJogada(PRETO, jogadasPreto[qtdJogadasPreto - 1], tabuleiro, &xeque, &preto, &branco);
                }

                if(xeque != 0){
                    if(xeque == 1){
                        brancoGanhou = 1;
                        xequeMate = 1;
                    } else{
                        pretoGanhou = 1;
                        xequeMate = 1;
                    }
                }

                jogadorAtual = 1 - jogadorAtual;
            }

            if(brancoGanhou) menuBrancoGanhou = 1;
            else menuPretoGanhou = 1;

            jogo = 0;

            printaPartidasNoArquivo(jogadasPreto, jogadasBranco, qtdJogadasPreto, qtdJogadasBranco);

            for(i = 0; i < qtdJogadasPreto; ++i){
                free(jogadasPreto[i]);
            }

            for(i = 0; i < qtdJogadasBranco; ++i){
                free(jogadasBranco[i]);
            }

            free(jogadasPreto);
            free(jogadasBranco);
        }

        while(menuBrancoGanhou){
            mensagemVencedorBranco(&opcao);
            switch(opcao){
                case 1:
                    menuInicial = 1;
                    menuBrancoGanhou = 0;
                    break;
                case 2:
                    menuSair = 1;
                    menuBrancoGanhou = 0;
                    break;
            }
        }

        while(menuPretoGanhou){
            mensagemVencedorPreto(&opcao);
            switch(opcao){
                case 1:
                    menuInicial = 1;
                    menuPretoGanhou = 0;
                    break;
                case 2:
                    menuSair = 1;
                    menuPretoGanhou = 0;
                    break;
            }
        }

        while(menuSair){
            mostrarMensagemSaida();
            return 0;
        }
    }

    return 0;
}