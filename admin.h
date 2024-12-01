#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED

// Tô chamando as funções aqui pra parar de ficar mostrando alertas de função implicita.
void ALTERAR_INFOS(int id);
int PRECOS_QUARTOS(int id);

void VERIFICA_CLIENTES(){

    FILE *clientes;

    clientes = fopen("arquivos/clientes.txt","r");
    printf("\n\n\tCLINTES CADASTRADOS\n");

    int cpfVerifica;
    char nomeVerifca[100],sobrenomeVerifica[100];

     while (fscanf(clientes, "%s %s %d",nomeVerifca, sobrenomeVerifica, &cpfVerifica) != EOF) {
        printf("\nNome: %s %s\tCPF: %d\n", nomeVerifca, sobrenomeVerifica, cpfVerifica);

    }


    printf("\nDeseja emitir o extrato dos clientes atuais? (s/n) ");
    char emitirExtratoC;
    getchar();
    scanf("%c", &emitirExtratoC);
    if(emitirExtratoC == 's' || emitirExtratoC == 'S'){
        //EXTRATO_CLIENTES();     // Emite o extrato (arquivo) dos clientes atuais
    }
}

void VERIFICA_RESERVAS(){

    FILE *reservas;

    reservas = fopen("arquivos/reservas.txt","r");
    if(reservas == NULL){
        printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
        return 1;
    }
    char nomeVerifca[100],sobrenomeVerifica[100];
    int dataE[3];
    int dataS[3];
    char bed[20];
    int quartoEscolhido;

    rewind(reservas);
    while(fscanf(reservas, "%s %s %d %d %d %d %d %d %s %d\n",nomeVerifca, sobrenomeVerifica,
    &dataE[0],&dataE[1],&dataE[2],
    &dataS[0],&dataS[1],&dataS[2], bed, &quartoEscolhido) != EOF){

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("- Nome: %s %s \n- Data de entrada: %d/%d/%d \n- Data de saida: %d/%d/%d \n- Cama escolhida: %s \n- Numero do quarto: %d\n", nomeVerifca, sobrenomeVerifica,
    dataE[0], dataE[1], dataE[2],
    dataS[0], dataS[1], dataS[2], bed, quartoEscolhido);
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
    }
    fclose(reservas);
    printf("\n");
}

void PAINEL_ADM(int ID){
    char nomeAdm[100] = "";
    int opcaoAdm = 666;
    if(ID == adm.idAdmin){
        strcpy(nomeAdm, adm.nomeAdmin); // Pega o nome do admin logado
    }

    ADM();
    printf("\nSeja bem vindo %s\n", nomeAdm);

    do{
        printf("\nSelecione a opcao desejada:\n");
        printf("\n0 - Sair\n1 - Verificar clientes cadastrados\n2 - Verificar reservas\n3 - Informar infracao\n4 - Alterar informacoes do hotel\n");
        scanf("%d", &opcaoAdm);

        switch (opcaoAdm){
        case 0:
            printf("\nOperacao encerrada.\n");
            ACESSO_INICIAL();   // Retorna ao menu inicial
            break;

        case 1:
            VERIFICA_CLIENTES(); // Exibe os clientes cadastrados e gera extrato
            PAINEL_ADM(ID);      // Retorna ao painel adm principal
            break;

        case 2:
            VERIFICA_RESERVAS(); // Exibe as reservas feitas e gera extrato
            // Falta fazer a função de alterar/cancelar as reservas
            PAINEL_ADM(ID); // Retorna ao painel adm principal
            break;

        case 3: // Falta fazer a função de multa
            break;

        case 4:
            ALTERAR_INFOS(ID);  // Função para alterar os valores e informações do hotel
            break;

        default:
            printf("\nOpcao invalida! Tente novamente!");
            break;
        }
    } while (opcaoAdm != 0 && opcaoAdm != 1 && opcaoAdm != 2 && opcaoAdm != 3 && opcaoAdm != 4);
}

void ALTERAR_INFOS(int id){
    ADM();
    int opc;
    do{
        printf("\nQual informacao gostaria de alterar? ");
        printf("\n0 - Voltar\n1 - Alterar nome do hotel\n2 - Alterar valores\n");
        scanf("%d", &opc);

        switch (opc){
        case 0:
            PAINEL_ADM(id); // Retorna ao menu anterior
            break;

        case 1:     //Altera o nome do hotel
            printf("\nQual o novo nome do hotel? ");
            getchar();
            fgets(nomeHotel, sizeof(nomeHotel), stdin);
            nomeHotel[strcspn(nomeHotel, "\n")] = '\0';

            printf("\nTroca bem sucedida!\n");
            ALTERAR_INFOS(id);
            break;

        case 2: // Altera os valores do quartos, camas e serviços
            printf("\n");   // Isso aqui existe só pra não dar conflito com a declaração do int.
            int opcPrecos = 666;
            do{
                printf("Qual valor deseja alterar? ");    // TEM QUE ADICIONAR MAIS
                printf("\n0 - Voltar\n1 - Valores dos quartos por tipo de cama\n");
                scanf("%d", &opcPrecos);

                switch (opcPrecos){
                case 0:     // Volta ao menu anterior
                    ALTERAR_INFOS(id);
                    break;

                case 1:     //Altera os preços dos quartos
                    PRECOS_QUARTOS(id);
                    break;

                default:
                    printf("\nOpcao invalida! Tente novamente.\n");
                    break;
                }
            }while(opcPrecos != 0 && opcPrecos != 1);
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
            break;
        }
    } while (opc != 0 && opc != 1 && opc != 2);
}

// Altera os preços dos quartos
int PRECOS_QUARTOS(int id){
    int cnt = 0, cama;
    char nomeCama[20];
    char camaEscolhida[20];
    float valorCama, newValue;
    char* camasOpcoes[3] = {"Solteiro","Casal","QueenSize"};
    float valores[3];


    FILE *camas;
    camas = fopen("arquivos/camasValor.txt","r");

    if(camas == NULL){
        printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
        return 1;
    }

    printf("\n0 - Voltar\n");


    while (fscanf(camas,"%s %f",nomeCama, &valorCama) != EOF) {
        printf("%d - Quarto com Cama de %s R$: %.2f\n",cnt + 1, nomeCama, valorCama);
        valores[cnt] = valorCama;
        cnt++;
    }

    fclose(camas);


    printf("\n\tALTERACAO DE VALOR DOS QUARTOS\n");


    do{
        printf("\nQual cama deseja alterar? ");
        scanf("%d", &cama);

        switch (cama){
        case 0:
            ALTERAR_INFOS(2);
            break;

        case 1: // Cama de solteiro
            printf("\nDigite o novo valor do quarto com cama de Solteiro: ");
            scanf("%f", &newValue);

            strcpy(camaEscolhida, "Solteiro");

            break;

        case 2: // Cama de casal
            printf("\nDigite o novo valor do quarto com cama de Casal: ");
            scanf("%f", &newValue);

            strcpy(camaEscolhida, "Casal");
            break;

        case 3: // Cama queen size
            printf("\nDigite o novo valor do quarto com cama Queen size: ");
            scanf("%f", &newValue);

            strcpy(camaEscolhida, "QueenSize");
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.");
            break;
        }
    }while(cama != 0 && cama != 1 && cama != 2 && cama != 3);

    camas = fopen("arquivos/camasValor.txt", "w");

    if (camas == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 1;
    }

    for(int i = 0; i < 3; i++){
        if (strcmp(camasOpcoes[i], camaEscolhida) == 0) {
            valores[i] = newValue;
        }

        fprintf(camas,"%s %.2f\n",camasOpcoes[i], valores[i]);
    }


    fclose(camas);



    if(cama != 0){ ALTERAR_INFOS(2); }// colocar aqui em baixo por boa pratica ( uso repetitivo da funcao )

}

#endif // ADMIN_H_INCLUDED
