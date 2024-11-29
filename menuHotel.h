#ifndef MENUHOTEL_H_INCLUDED
#define MENUHOTEL_H_INCLUDED



int FAZER_RESERVA(char nome[], char entrada[], char saida[], int cama, int andar); // Tô chamando a função aqui pra parar de ficar mostrando alertas de função implicita.

void MENU_HOTEL(char nome[]){
    int opc = 666;
    CABECALHO();
    printf("\nSeja bem vindo %s\n", nome);

    do{
        MENU_OPCOES();
        printf("\nDigite a opcao escolhida: ");
        scanf("%d", &opc);

        switch (opc){
        case 0:
            ACESSO_INICIAL();   // Retorna ao menu anterior
            break;

        case 1:
            printf("\n------------------------------------\n");
            printf("\n\tCADASTRO DE RESERVA\n");
            printf("\n------------------------------------\n");

            char dtEntrada[11], dtSaida[11];
            int tipoCama, numQuarto,andar;

            printf("\nQual a data de entrada? (Formato: DD/MM/AA) ");
            getchar();
            fgets(dtEntrada, sizeof(dtEntrada), stdin);
            dtEntrada[strcspn(dtEntrada, "\n")] = '\0';

            printf("\nQual a data de saida? (Formato: DD/MM/AA) ");
            getchar();
            fgets(dtSaida, sizeof(dtSaida), stdin);
            dtSaida[strcspn(dtSaida, "\n")] = '\0';

            do{
                printf("\nQual o tipo de quarto desejado? ");
                PRECO_CAMAS();
                scanf("%d", &tipoCama);

            } while (tipoCama != 1 && tipoCama != 2 && tipoCama != 3);

            do{
                printf("\nQual andar desejado?");
                scanf("%d", &andar);

            } while (andar > 100 || andar < 1);

            printf("\nVerificando disponibilidade...\n");

            numQuarto = FAZER_RESERVA(nome, dtEntrada, dtSaida, tipoCama, andar);

            if (numQuarto != -1) {
                printf("\nReserva efetuada com sucesso!\nSeu quarto e o numero %d.", numQuarto);
                MENU_HOTEL(nome);
            } else {
                printf("\nNao foi possivel fazer a reserva.\n");
                MENU_HOTEL(nome);
            }
            break;

        case 2:
            //CONSULTA_RESERVA(nome); // Consulta e edita a reserva
            MENU_HOTEL(nome);
            break;

        case 3:
            //CANCELA_RESERVA(nome); // Cancela a reserva
            printf("\nDeseja emitir o extrato de cancelamento da reserva do quarto? (s/n) ");
            char emitirExtratoCancelamento;
            getchar();
            scanf("%c", &emitirExtratoCancelamento);
            if(emitirExtratoCancelamento == 's' || emitirExtratoCancelamento == 'S'){
                //EXTRATO_CANCELAMENTO();     // Emite o extrato (arquivo) do cancelamento da reserva quarto
            }
            MENU_HOTEL(nome);
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.");
            break;
        }
    } while (opc != 0 && opc != 1 && opc != 2 && opc != 3);
}


Data CONVERTER_DATA(const char *data){
    Data dataConvertida;

    sscanf(data, "%2d/%2d/%4d", &dataConvertida.dia, &dataConvertida.mes, &dataConvertida.ano);
    return dataConvertida;
}

int FAZER_RESERVA(char nome[], char entrada[], char saida[], int cama, int andar){

    Data dataEntrada = CONVERTER_DATA(entrada);
    Data dataSaida = CONVERTER_DATA(saida);

    FILE *reservas;
    reservas = fopen("arquivos/reservas.txt", "r");

    if (reservas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }

    char nomeVerifca[100],sobrenomeVerifica[100];

    int dataE[3];
    int dataS[3];
    int VerficiaA;
    int c;



    while (fscanf(reservas, "%s %s %d %d %d %d %d %d %d %d",nomeVerifca, sobrenomeVerifica,
    &dataE[0],&dataE[1],&dataE[2],
    &dataS[0],&dataS[1],&dataS[2], &c, &VerficiaA) != EOF) {

        char nomeCompleto[100];
        sprintf(nomeCompleto, "%s %s", nomeVerifca, sobrenomeVerifica);

        if(strcmp(nome, nomeCompleto) == 0) {
            printf("Voce ja tem uma reserva cadastrada, nao e possivel ter mais de uma.");
            return -1;
        }

    }

    fclose(reservas);

    if(dataEntrada.mes > 12 || dataSaida.mes > 12 ||
       dataEntrada.dia > 31 || dataSaida.dia > 31 ||
       dataEntrada.ano < 2024 || dataSaida.ano < 2024){
        printf("\nColoque uma data valida para o cadastro da reserva.");
        return -1;
    }

    reservas = fopen("arquivos/reservas.txt", "a");

    if (reservas == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return -1;
    }


    char nomeV[50], sobrenomeV[50];
    char *token = strtok(nome, " ");

    strcpy(nomeV, token);

    token = strtok(NULL, " ");
    strcpy(sobrenomeV, token);

    fprintf(reservas, "%s %s %d %d %d %d %d %d %d %d\n",nomeV, sobrenomeV,
    dataEntrada.dia,dataEntrada.mes,dataEntrada.ano,
    dataSaida.dia,dataSaida.mes,dataSaida.ano, cama, andar);


    fclose(reservas);

    return 0;
}


#endif // MENUHOTEL_H_INCLUDED
