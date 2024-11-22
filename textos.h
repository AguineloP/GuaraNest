#ifndef TEXTOS_H_INCLUDED
#define TEXTOS_H_INCLUDED


void CABECALHO(){
    printf("\n\n");
    printf("-----------------------------------------------");
    printf("\n\tBEM VINDO AO HOTEL %s\n", nomeHotel);
    printf("-----------------------------------------------");
    printf("\n");
}

void MENU_OPCOES(){
    printf("\nMenu: \n");
    printf("\n0 - Sair\n1 - Solicitar reserva\n2 - Consultar Reserva\n3 - Cancelar reserva\n");
}

void PRECO_CAMAS(){
    FILE *camas;
    char nomeCama[50];
    float valorCama;
    int cnt = 0;

    camas = fopen("arquivos/camasValor.txt","r");

    if(camas == NULL){
        printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
        return 1;
    }

    printf("\n");

    while (fscanf(camas,"%s %f",nomeCama, &valorCama) != EOF) {
        printf("%d - Quarto com Cama de %s R$: %.2f\n",cnt + 1, nomeCama, valorCama);
        cnt++;
    }

    fclose(camas);
}

void ADM(){
    printf("\n-----------------------------------------------\n");
    printf("\n\tPAINEL DO ADMINISTRADOR\n");
    printf("\n-----------------------------------------------\n");
}


#endif // TEXTOS_H_INCLUDED
