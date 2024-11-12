
// Tô chamando as funções aqui pra parar de ficar mostrando alertas de função implicita.
void ALTERAR_INFOS(int id);
void PRECOS_QUARTOS(int id);

void VERIFICA_CLIENTES(){
    int i;
    printf("\n\n\tCLINTES CADASTRADOS\n");
    for(i = 0; i < numeroDeClientes; i++){
        printf("\nNome: %s\tCPF: %s\n", cliente[i].nomeCliente, cliente[i].cpfCliente);
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
    int i;
    printf("\n\n\tRESERVAS FEITAS\n");
    for(i = 0; i < numeroDeReservas; i++){  // Falta adicionar o valor da reserva!
        printf("\nCliente: %s\tCPF: %s\nQuarto: %d\tValor:\nEntrada: %s\tSaida: %s\n", reserva[i].cliente->nomeCliente, reserva[i].cliente->cpfCliente, reserva[i].numeroDoQuarto, reserva[i].dataDeEntrada, reserva[i].dataDeSaida);
    }

    printf("\nDeseja emitir o extrato de reservas feitas? (s/n) ");
    char emitirExtratoR;
    getchar();
    scanf("%c", &emitirExtratoR);
    if(emitirExtratoR == 's' || emitirExtratoR == 'S'){
        //EXTRATO_RESERVAS();     // Emite o extrato (arquivo) das reservas atuais
    }
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
void PRECOS_QUARTOS(int id){       
    printf("\n\tALTERACAO DE VALOR DOS QUARTOS\n");
    printf("\n0 - Voltar\n1 - Quarto com Cama de Solteiro\t\tR$%.2f\n2 - Quarto com Cama de Casal\t\tR$%.2f\n3 - Quarto com Cama QueenSize\t\tR$%.2f\n", camaSolteiro, camaCasal, camaQueen);
    int cama;
    do{
        printf("\nQual cama deseja alterar? ");
        scanf("%d", &cama);
        switch (cama){
        case 0: // Voltar ao menu anterior
            ALTERAR_INFOS(id);
            break;
        
        case 1: // Cama de solteiro
            printf("\nDigite o novo valor do quarto com cama de Solteiro: ");
            scanf("%f", &camaSolteiro);
            printf("\nAlteracao bem sucedida!\n");
            PRECOS_QUARTOS(id);
            break;
        
        case 2: // Cama de casal
            printf("\nDigite o novo valor do quarto com cama de Casal: ");
            scanf("%f", &camaCasal);
            printf("\nAlteracao bem sucedida!\n");
            PRECOS_QUARTOS(id);
            break;
        
        case 3: // Cama queen size
            printf("\nDigite o novo valor do quarto com cama Queen size: ");
            scanf("%f", &camaQueen);
            printf("\nAlteracao bem sucedida!\n");
            PRECOS_QUARTOS(id);
            break;

        default:
            printf("\nOpcao invalida. Tente novamente.");
            break;
        }
    }while(cama != 0 && cama != 1 && cama != 2 && cama != 3);
}