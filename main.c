#include <stdio.h>
#include <stdlib.h>

char m[15][15]; //matriz de referencia

char Mjogo[15][15]; //matriz de jogo

struct info{
char pergunta[50];
int orientacao;
int lugar1;
int lugar2;
};

int main()
{
int n; //quantidade de palavras
int i, j; //acessar matriz
int v; //condicao do while

for(i=0; i<15; i++){ //define os espaços vazios da matriz
        for(j=0; j<15; j++){
            m[i][j] = '-';
        }}

printf("Quantas palavras quer utilizar ?\n");
scanf("%d", &n);

while(n != 0){ //coloca quantas palavras na matriz quanto forem desejadas

    preencher_matriz();

    n = n - 1;
}

impressora(m);

printf("\n\n\n");

impressora(Mjogo);

v = 2;

while(v != 1){ //roda o jogo

    jogo();

    impressora(Mjogo);

}

//v = jogo();
}

void jogo(){ //Funcao em que ocorre a troca dos espacos com 0 pelas palavras na matriz

int i, j, k;//acessar matriz e vetor
int d[4]; //armazena a delimitacao (1 e 3 = linha) (2 e 4 = coluna)
char p[10]; //palavra desejada

printf("determine a delimitacao que deseja\n");
scanf("%d%d%d%d", &d[1], &d[2], &d[3], &d[4]);
printf("determine a palavra desejada\n");
scanf("%s", p);

if(d[1] == d[3]){ //horizontal

    i = d[1];

  /*  for(j=d[2]; j <= d[4]; j++){ //verifica se todos os espacos selecionados contem 0

        if(Mjogo[i][j] != '0'){

            return;
        }
    } */

    k = 0;

    for(j=d[2]; j <= d[4] ; j++){ //compara os espacos selecionados na matriz de referencia com a palavra dada

        if(m[i][j] != p[k]){

            return;
        }

        k = k + 1;
    }

    for(j=d[2]; j <= d[4]; j++){ //troca os espacos com 0 pela palavra na matriz de referencia

            Mjogo[i][j] = m[i][j];
        }
    }

if(d[2] == d[4]){ //vertical

    j = d[2];

  /*  for(i=d[1]; i <= d[3]; i++){ //verifica se todos os espacos selecionados contem 0

        if(Mjogo[i][j] != '0'){

            return;
        }
    } */

    k = 0;

    for(i=d[1]; i <= d[3]; i++){ //compara os espacos selecionados na matriz de referencia com a palavra dada

        if(m[i][j] != p[k]){

            return;
        }

        k = k + 1;
    }

    for(i=d[1]; i <= d[3]; i++){ //troca os espacos com 0 pela palavra na matriz de referencia

            Mjogo[i][j] = m[i][j];
        }
    }

}



void impressora(char mat[15][15]){ //imprime a matriz
    int i=0,j=0;
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            printf("%2c", mat[i][j]);
        }
            printf("\n");
        }
}


void preencher_matriz(){

struct info p;
char resposta[10];
//int lugar1
//int lugar2
//int orienta

int i, j, k;

//printf("pergunta:\n");
//scanf("%s", p.pergunta);

printf("resposta:\n");
scanf("%s", resposta);

printf("orientacao:\n");
scanf("%d", &p.orientacao);

printf("lugar:\n");
scanf("%d", &p.lugar1);
scanf("%d", &p.lugar2);

if(p.orientacao == 1){ //imprime a palavra na matriz (vertical)

    j = p.lugar2;

    for(i=p.lugar1, k=0 ; i<(p.lugar1 + 10) , k < 10; i++ , k++){

        m[i][j] = resposta[k]; //imprime a palavra dada no lugar desejad

        if(m[i][j] == NULL){ //troca todos os espacos vazios por -
            m[i][j] = '-';
        }

        }

}

if(p.orientacao == 2){ //imprime a palavra na matriz (horizontal)

 i = p.lugar2;

    for(j=p.lugar1, k=0 ; j<(p.lugar1 + 10) , k < 10; j++ , k++){

        m[i][j] = resposta[k]; //imprime a palavra dada no lugar desejado

        if(m[i][j] == NULL){ //troca todos os espacos vazios por -
            m[i][j] = '-';
        }

        }

}

for(i=0; i<15; i++){ //transforma a matriz de jogo em uma copia da matriz de referencia
        for(j=0; j<15; j++){
            Mjogo[i][j] = m[i][j];
        }
        }

for(i=0; i<15; i++){  //transforma tudo diferente de - em um simbolo na matriz de jogo, no caso, 0
        for(j=0; j<15; j++){

            if(Mjogo[i][j] != '-'){
        Mjogo[i][j] = '0';}

        }
        }

}
