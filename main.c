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
    }}
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

printf("                        1 1 1 1 1\n"); //numeros de referencia da matriz (coluna)
printf("    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4\n");
printf(" 0 ");
    for(i=0; i<15; i++){
        for(j=0; j<15; j++){
            printf("%2c", mat[i][j]);
        }
            printf("\n");

            if(i<9){ //numeros de referencia da matriz (linha)
                printf(" %d ", i+1);
            }

            if((i >= 9)&&(i < 14)){ //numeros de referencia da matriz (linha)
                printf(" %d", i+1);
            }

        }
}

void preencher_matriz(int n){

int i, j, k, l, validade;

printf("resposta:\n");
scanf("%s", info[n].resposta);

info[n].acerto=0;
info[n].orientacao=0;

while((info[n].orientacao!=1)&&(info[n].orientacao!=2)){//impede jogadas inválidas

printf("orientacao:\n");

scanf("%d", &info[n].orientacao);

if((info[n].orientacao!=1)&&(info[n].orientacao!=2)){

    printf("escreva um valor valido(1-vertical, 2-horizontal)\n");
}

}
validade=0;

printf("lugar:\n");

while(validade!=1){//impede jogadas inválidas
scanf("%d", &info[n].lugar1);
scanf("%d", &info[n].lugar2);
if(info[n].orientacao == 1){
if((info[n].lugar1+strlen(info[n].resposta)>15)||(info[n].lugar1>14)||(info[n].lugar1<0)||(info[n].lugar2>14)||(info[n].lugar2<0)){
    validade=0;
    printf("insira valores validos\n");
}
else{
    validade=1;
}

if(validade == 1){ //verifica se nao havera conflito com outras palavras

 k = info[n].lugar1;
 j = info[n].lugar2;

    for(i = 0; i < strlen(info[n].resposta); i++){

       l = k + i;

        if((m[l][j] != info[n].resposta[i]) || (m[l][j] != '*')){
            validade = 0;
            printf("insira valores validos\n");
            i = 15;
        } else{validade = 1;}
    }
}

}else{
    if((info[n].lugar2+strlen(info[n].resposta)>15)||(info[n].lugar1>14)||(info[n].lugar1<0)||(info[n].lugar2>14)||(info[n].lugar2<0)){
    validade=0;
    printf("insira valores validos\n");
}
else{
    validade=1;
}}}

printf("Dica:\n");//dica de cada palavra

//fgets(info[n].dica,100,stdin); //nao funcionaram
//gets(info[n].dica);
//strcpy(info[n].dica, dicacopia);

scanf("%s",info[n].dica );
printf("\n");



if(info[n].orientacao == 1){ //imprime a palavra na matriz (vertical)

    j = info[n].lugar2;
    l=strlen(info[n].resposta);
    for(i=info[n].lugar1, k=0 ; i<(info[n].lugar1 + l) , k < l; i++ , k++){

        m[i][j] = info[n].resposta[k]; //imprime a palavra dada no lugar desejad

        if(&m[i][j] == NULL){ //troca todos os espacos vazios por *
            m[i][j] = '*';
        }

        }

}

if(info[n].orientacao == 2){ //imprime a palavra na matriz (horizontal)

 i = info[n].lugar1;
 l=strlen(info[n].resposta);

    for(j=info[n].lugar2, k=0 ; j<(info[n].lugar1 + l) , k < l; j++ , k++){

        m[i][j] = info[n].resposta[k]; //imprime a palavra dada no lugar desejado

        if(&m[i][j] == NULL){ //troca todos os espacos vazios por -
            m[i][j] = '*';
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

            if(Mjogo[i][j] != '*'){
        Mjogo[i][j] = '0';}

        }
        }

impressora(m);


}

void jogo(){ //Funcao em que ocorre a troca dos espacos com 0 pelas palavras na matriz

int i, j, k, c, r, s=0, x=0;//acessar matriz e vetor
char p[10]; //palavra desejada

printf("Qual palavra voce deseja tentar?\n");
r=1;
while(r==1){
scanf("%d", &c);
if(((c>k)||(c<1))&&(info[c].acerto!=1)){
    printf("insira um numero valido\n");
}
    else{
        r=0;
    }
}
printf("determine a palavra desejada\n");
scanf("%s", p);

if(strcmp(p,info[c].resposta)==0){
while(s<strlen(info[c].resposta)){
    if(info[c].orientacao==1){
        Mjogo[info[c].lugar1+x][info[c].lugar2]=info[c].resposta[s];
        x++;
        s++;
    }
    else{
        Mjogo[info[c].lugar1][info[c].lugar2+x]=info[c].resposta[s];
        x++;
        s++;
    }
}
info[c].acerto=1;
}
else{
    printf("Resposta errada\n");
}
x=0;
s=0;

}

int main()
{
int n; //quantidade de palavras
int i, j; //acessar matriz
int k,v=2; //condicao do while

for(i=0; i<15; i++){ //define os espaços vazios da matriz
        for(j=0; j<15; j++){
            m[i][j] = '*';
        }}
   /* m[1][1] = 'a';
    m[2][1] = 'b'; */ //teste de funcionamento

printf("Quantas palavras quer utilizar ?\n");
scanf("%d", &n);
k=n;

impressora(m);

while(n != 0){ //coloca quantas palavras na matriz quanto forem desejadas

    preencher_matriz(n);

    n = n - 1;
}

impressora(m);

printf("\n\n\n");

impressora(Mjogo);


while(v != 1){ //roda o jogo

    impdica(k);

    jogo(k);

    impressora(Mjogo);

    v=compara();
}
if(v==1){
  printf("\nParabens, voce venceu!!!!");
  return 0;
}
//v = jogo();
}
