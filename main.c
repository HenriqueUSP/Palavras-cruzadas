#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char m[15][15]; //matriz de referencia

char Mjogo[15][15]; //matriz de jogo

struct coord {//transformada em coord pois sem isso não dá pra fazer a impressão de dicas ou fazer a melhoria de escolha da jogada
char resposta[50];
char dica[100];
int orientacao;
int lugar1;
int lugar2;
int acerto;
}info[50];

void impdica(int k){//imprime as dicas, inicio e fim
int i=1,lf,cf;
while(i<=k){
    if(info[i].acerto==0){
            if(info[i].orientacao==1){
                lf=info[i].lugar1 + strlen(info[i].resposta)-1;
                cf=info[i].lugar2;
            }
            else{
                cf=info[i].lugar2+strlen(info[i].resposta)-1;
                lf=info[i].lugar1;
            }

        printf(" N: %d \n Inicio: %d %d \n fim: %d %d \n Dica: %2s \n\n", i, info[i].lugar1, info[i].lugar2, lf, cf, info[i].dica);
    }
    i++;
}


}
int compara(){
int c=0,b=0,p=1;
while(b<15){
    while(c<15){
        if(m[b][c]!=Mjogo[b][c]){
            p=0;
        }
        c++;
    }
    b++;
    c=0;
}
return p;
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

void preencher_matriz(int n){

int i, j, k, l, validade;
//char dicacopia[100];

//printf("pergunta:\n");
//scanf("%s", p.pergunta);

printf("resposta:\n");
scanf("%s", info[n].resposta);

info[n].orientacao=0;

while((info[n].orientacao!=1)&&(info[n].orientacao!=2)){//impede jogadas inválidas

printf("orientacao:\n");

scanf("%d", &info[n].orientacao);

if((info[n].orientacao!=1)&&(info[n].orientacao!=2)){

    printf("escreva um valor valido(1-horizontal, 2-vertical)\n");
}

}
validade=0;

printf("lugar:\n");

while(validade!=1){//impede jogadas inválidas
scanf("%d", &info[n].lugar1);
scanf("%d", &info[n].lugar2);
if(info[n].orientacao == 1){
if((info[n].lugar2+strlen(info[n].resposta)>15)||(info[n].lugar1>14)||(info[n].lugar1<0)||(info[n].lugar2>14)||(info[n].lugar2<0)){
    validade=0;
    printf("insira valores válidos\n");
}
else{
    validade=1;
}
}else{
    if((info[n].lugar1+strlen(info[n].resposta)>15)||(info[n].lugar1>14)||(info[n].lugar1<0)||(info[n].lugar2>14)||(info[n].lugar2<0)){
    validade=0;
    printf("insira valores válidos\n");
}
else{
    validade=1;
}}}

printf("Dica:\n");//dica de cada palavra
//fgets(info[n].dica,100,stdin);
scanf("%s",info[n].dica );
//gets(info[n].dica);
printf("\n");

//strcpy(info[n].dica, dicacopia);

if(info[n].orientacao == 1){ //imprime a palavra na matriz (vertical)

    j = info[n].lugar2;
    l=strlen(info[n].resposta);
    for(i=info[n].lugar1, k=0 ; i<(info[n].lugar1 + l) , k < l; i++ , k++){

        m[i][j] = info[n].resposta[k]; //imprime a palavra dada no lugar desejad

        if(m[i][j] == NULL){ //troca todos os espacos vazios por -
            m[i][j] = '-';
        }

        }

}

if(info[n].orientacao == 2){ //imprime a palavra na matriz (horizontal)

 i = info[n].lugar1;
    l=strlen(info[n].resposta);
    for(j=info[n].lugar2, k=0 ; j<(info[n].lugar1 + l) , k < l; j++ , k++){

        m[i][j] = info[n].resposta[k]; //imprime a palavra dada no lugar desejado

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

impressora(m);


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

int main()
{
int n; //quantidade de palavras
int i, j; //acessar matriz
int k,v=2; //condicao do while
char dicacopia[10];

/*scanf("%100[^\n]s", info[1].dica);
printf("%s\n", info[1].dica);*/

for(i=0; i<15; i++){ //define os espaços vazios da matriz
        for(j=0; j<15; j++){
            m[i][j] = '-';
        }}

printf("Quantas palavras quer utilizar ?\n");
scanf("%d", &n);
k=n;

while(n != 0){ //coloca quantas palavras na matriz quanto forem desejadas

    preencher_matriz(n);

/*printf("Dica:\n");//dica de cada palavra
//fgets(info[n].dica,100,stdin);
scanf("%100[^\n]s", dicacopia);
//gets(info[n].dica);
printf("\n");
strcpy(info[n].dica, dicacopia);
impressora(m);*/

    n = n - 1;
}

impressora(m);

printf("\n\n\n");

impressora(Mjogo);


while(v != 1){ //roda o jogo

    impdica(k);

    jogo();

    impressora(Mjogo);

    v=compara();
}
if(v==1){
  printf("\nParabens, voce venceu!!!!");
  return 0;
}
//v = jogo();
}
