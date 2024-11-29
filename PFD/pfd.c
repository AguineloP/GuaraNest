#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    const int qnt = 20; //máximo de opcionais que o hotel pode oferecer, acho q 20 seja suficiente
    char opcionais[qnt][100];
    int count = 0, i;

    FILE *arq = fopen("trabalho.txt", "r");
    if (!arq) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    //leitura dos opcionais do arquivo
    while (fgets(opcionais[count], sizeof(opcionais[count]), arq) != NULL && count < qnt) {
        opcionais[count][strcspn(opcionais[count], "\n")] = '\0'; //só para remover o '\n' do final
        count++;
    }
    fclose(arq);

    //exibindo os opcionais lidos
    printf("Opcionais: \n");
    for (i = 0; i < count; i++) {
        printf("%d: %s\n", i + 1, opcionais[i]);
    }

    //variáveis
    int um_tres = 0, dois_quatro = 0, tres_cinco = 0, seis_oito = 0, sete_nove = 0;
    int dez_doze = 0, onze_treze = 0, doze_quatorze = 0, quinze_dezessete = 0, dezesseis_dezoito = 0;
    int dezenove_vinte = 0;

    //criando as condições para as combinações
    if (count >= 3 && strcmp(opcionais[0], opcionais[2]) == 0) {
        um_tres = 1;
    }
    if (count >= 4 && strcmp(opcionais[1], opcionais[3]) == 0) {
        dois_quatro = 1;
    }
    if (count >= 5 && strcmp(opcionais[2], opcionais[4]) == 0) {
        tres_cinco = 1;
    }
    if (count >= 8 && strcmp(opcionais[5], opcionais[7]) == 0) {
        seis_oito = 1;
    }
    if (count >= 9 && strcmp(opcionais[6], opcionais[8]) == 0) {
        sete_nove = 1;
    }
    if (count >= 12 && strcmp(opcionais[9], opcionais[11]) == 0) {
        dez_doze = 1;
    }
    if (count >= 13 && strcmp(opcionais[10], opcionais[12]) == 0) {
        onze_treze = 1;
    }
    if (count >= 14 && strcmp(opcionais[11], opcionais[13]) == 0) {
        doze_quatorze = 1;
    }
    if (count >= 17 && strcmp(opcionais[14], opcionais[16]) == 0) {
        quinze_dezessete = 1;
    }
    if (count >= 18 && strcmp(opcionais[15], opcionais[17]) == 0) {
        dezesseis_dezoito = 1;
    }
    if (count >= 20 && strcmp(opcionais[18], opcionais[19]) == 0) {
        dezenove_vinte = 1;
    }

    //vetor com as variáveis geradas
    int *variables[] = {&um_tres, &dois_quatro, &tres_cinco, &seis_oito, &sete_nove,
                        &dez_doze, &onze_treze, &doze_quatorze, &quinze_dezessete,
                        &dezesseis_dezoito, &dezenove_vinte};

    return 0;
}
