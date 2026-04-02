#include <string.h>
#include <stdio.h>


#define MAX_EST 10
#define MAX_ALF 2
#define MAX_PAL 100


typedef struct {
    int qtd_est;   // quantidade de estados
    int qtd_alf;   // quantidade de simbolos do alfabeto
    char alf[MAX_ALF]; // alfabeto
    int trans[MAX_EST][MAX_ALF]; // funcao de transicao
    int est_ini;   // estado inicial
    int est_fin[MAX_EST]; // estados finais (1 = final)
} AFD;




void desenhar_afd() {
    printf("\n=== DESENHO DO AUTOMATO ===\n");
    printf("Estados:\n");
    printf("q0 (inicio)\n");
    printf("q1 (ultimo = a)\n");
    printf("q2 (ultimo = b)\n");
    printf("q3 (final - encontrou aa ou bb)\n\n");


    printf("Transicoes:\n");
    printf("q0 --a--> q1\n");
    printf("q0 --b--> q2\n");
    printf("q1 --a--> q3\n");
    printf("q1 --b--> q2\n");
    printf("q2 --a--> q1\n");
    printf("q2 --b--> q3\n");
    printf("q3 --a--> q3\n");
    printf("q3 --b--> q3\n");
    printf("===========================\n");
}


int pegar_indice(AFD *afd, char s) {
    for (int i = 0; i < afd->qtd_alf; i++) {
        if (afd->alf[i] == s)
            return i;
    }
    return -1;
}


int executar(AFD *afd, char *pal) {
    int est_at = afd->est_ini; // estado atual


    printf("\n=== PASSO A PASSO ===\n");


    for (int i = 0; i < strlen(pal); i++) {
        char s = pal[i];
        int idx = pegar_indice(afd, s);


        if (idx == -1) {
            printf("Simbolo invalido: %c\n", s);
            return 0;
        }


        printf("Estado atual: q%d | Lendo: %c ", est_at, s);


        est_at = afd->trans[est_at][idx];


        printf("-> Novo estado: q%d\n", est_at);
    }


    printf("======================\n");


    if (afd->est_fin[est_at]) {
        return 1;
    } else {
        return 0;
    }
}


int main() {
    AFD afd;


    afd.qtd_est = 4;
    afd.qtd_alf = 2;


    afd.alf[0] = 'a';
    afd.alf[1] = 'b';


    afd.est_ini = 0;


    // estados finais
    for (int i = 0; i < MAX_EST; i++)
        afd.est_fin[i] = 0;


    afd.est_fin[3] = 1;


    // funcao de transicao
    // q0
    afd.trans[0][0] = 1; // a
    afd.trans[0][1] = 2; // b


    // q1
    afd.trans[1][0] = 3; // aa
    afd.trans[1][1] = 2;


    // q2
    afd.trans[2][0] = 1;
    afd.trans[2][1] = 3; // bb


    // q3 (final)
    afd.trans[3][0] = 3;
    afd.trans[3][1] = 3;


    char pal[MAX_PAL];


    desenhar_afd();


    printf("\nDigite a palavra (somente a e b): ");
    scanf("%s", pal);


    int res = executar(&afd, pal);


    if (res)
        printf("\nResultado: PALAVRA ACEITA\n");
    else
        printf("\nResultado: PALAVRA REJEITADA\n");


    return 0;
}
