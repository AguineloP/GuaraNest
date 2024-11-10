
void VERIFICA_CLIENTES(){
    int i;
    printf("\n\n\tCLINTES CADASTRADOS\n");
    for(i = 0; i < numeroDeClientes; i++){
        printf("\n%s, %s\n", cliente[i].nomeCliente, cliente[i].cpfCliente);
    }
}

void VERIFICA_RESERVAS(){
    int i;
    printf("\n\n\tRESERVAS FEITAS\n");
    for(i = 0; i < numeroDeReservas; i++){
        printf("\nCliente: %s\nQuarto: %d\nData de entrada: %s\tData de saida: %s\n", reserva[i].cliente->nomeCliente, reserva[i].numeroDoQuarto, reserva[i].dataDeEntrada, reserva[i].dataDeSaida);
    }
}

void PAINEL_ADM(int ID){
    char nomeAdm[100] = "";
    int opcaoAdm = 666;
    if(ID == adm.idAdmin){
        strcpy(nomeAdm, adm.nomeAdmin); //Pega o nome do admin logado
    }

    printf("\n-----------------------------------------------\n");
    printf("\n\tPAINEL DO ADMINISTRADOR\n");
    printf("\nSeja bem vindo %s\n", nomeAdm);

    do{
        printf("\nSelecione a opcao desejada:\n");
        printf("\n0 - Sair\n1 - Verificar clientes cadastrados\n2 - Verificar reservas\n3 - Informar infracao\n");
        scanf("%d", &opcaoAdm);

        switch (opcaoAdm){
        case 0:
            printf("\nOperacao encerrada\n");
            ACESSO_INICIAL();   //Retorna ao menu inicial 
            break;

        case 1:
            VERIFICA_CLIENTES(); //Exibe os clientes cadastrados
            PAINEL_ADM(ID);     //Retorna ao painel adm principal
            break;

        case 2: 
            VERIFICA_RESERVAS(); //Exibe as reservas feitas
            //Falta fazer a função de alterar/cancelar as reservas
            PAINEL_ADM(ID); //Retorna ao painel adm principal
            break;

        case 3: //Falta fazer a função de multa
            break;

        default:
            printf("\nOpcao invalida! Tente novamente!");
            break;
        }
    } while (opcaoAdm != 0 && opcaoAdm != 1 && opcaoAdm != 2 && opcaoAdm != 3);   
}