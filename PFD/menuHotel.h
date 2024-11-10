
void MENU_OPCOES(){
    printf("\nMenu: \n");
    printf("\n0 - Sair\n1 - Solicitar reserva\n2 - Consultar Reserva\n3 - Cancelar reserva\n");
}

void MENU_HOTEL(char nome[]){
    int opc = 555;
    CABECALHO();
    printf("\nSeja bem vindo %s\n", nome);
    MENU_OPCOES();

    do{
        printf("\nDigite a opcao escolhida: ");
        scanf("%d", &opc);

        switch (opc){
        case 0:  
            ACESSO_INICIAL();   //Retorna ao menu anterior
            break;
        
        case 1: 
            printf("\n------------------------------------\n");
            printf("\n\tCADASTRO DE RESERVA\n");
            printf("\n------------------------------------\n");

            char dtEntrada[11], dtSaida[11];
            int tipoCama, numQuarto;

            printf("\nQual a data de entrada? (Formato: DD/MM/AA) ");
            getchar();
            fgets(dtEntrada, sizeof(dtEntrada), stdin);
            dtEntrada[strcspn(dtEntrada, "\n")] = '\0';

            printf("\nQual a data de saida? (Formato: DD/MM/AA) ");
            getchar();
            fgets(dtSaida, sizeof(dtSaida), stdin);
            dtSaida[strcspn(dtSaida, "\n")] = '\0';

            do{
                printf("\nQual o tamanho de cama desejado? ");
                printf("\n1 - Solteiro\n2 - Casal\n3 - Queen size\n");
                scanf("%d", &tipoCama);
            } while (tipoCama != 1 && tipoCama != 2 && tipoCama != 3);

            printf("\nVerificando disponibilidade...\n");         

            numQuarto = FAZER_RESERVA(nome, dtEntrada, dtSaida, tipoCama);
            if (numQuarto != -1) {
                printf("\nReserva efetuada com sucesso!\nSeu quarto e o numero %d.", numQuarto);
                MENU_HOTEL(nome);
            } else {
                printf("\nNao foi possivel fazer a reserva.\n");
                MENU_HOTEL(nome);
            }

            break;
        
        case 2:
            //CONSULTA_RESERVA(nome); //Consulta e edita a reserva
            break;
        
        case 3:
            //CANCELA_RESERVA(nome); //Cancela a reserva
            break;
        
        default:
            printf("\nOpcao invalida! Tente novamente.");
            break;
        }
    } while (opc != 0 && opc != 1 && opc != 2 && opc != 3);
    
    
}

// Função para converter a data (DD/MM/AA) em um inteiro AAAAMMDD
int CONVERTER_DATA(const char *data) {
    int dia, mes, ano;
    sscanf(data, "%2d/%2d/%2d", &dia, &mes, &ano);  //Pega o dia, mes e ano e os atribui a variaveis separadas
    return (ano + 2000) * 10000 + mes * 100 + dia;  //Faz a multiplicação pra que a data final fique um valor AAAAMMDD
}

int FAZER_RESERVA(char nome[], char entrada[], char saida[], int cama){
    //Converte as datas de string para numerico
    int i, dataEntrada = CONVERTER_DATA(entrada), dataSaida = CONVERTER_DATA(saida); 

    for (i = 0; i < 200; i++) {
        //Verifica se o numero do quarto e diferente de 0 e se o tipo de cama esta entre os disponiveis
        if (reserva[i].numeroDoQuarto != 0 && reserva[i].tipoDeCama == cama) { 
            int dataReservadaEntrada = CONVERTER_DATA(reserva[i].dataDeEntrada);
            int dataReservadaSaida = CONVERTER_DATA(reserva[i].dataDeSaida);

            // Verifica se as datas se sobrepõem
            if (!(dataSaida < dataReservadaEntrada || dataEntrada > dataReservadaSaida)) {
                printf("\nQuarto indisponível para o período selecionado.\n");
                return -1; // Indica que a reserva não foi possível
            }
        }
    }

    // Procura uma posição livre para a nova reserva
    for (i = 0; i < 200; i++) {
        if (reserva[i].numeroDoQuarto == 0) {
            reserva[i].numeroDoQuarto = i + 1;  // Define o número do quarto
            reserva[i].tipoDeCama = cama;       //Define a cama

            strcpy(reserva[i].dataDeEntrada, entrada);  //Define o data de entra 
            strcpy(reserva[i].dataDeSaida, saida);      //Define o data de saida

            reserva[i].cliente = malloc(sizeof(struct CLIENTES));      //Descobre a quantidade de memoria necessária para os dados do cliente
            strcpy(reserva[i].cliente->nomeCliente, nome);      //Atribui o nome do cliente a reserva

            numeroDeReservas++;
            return reserva[i].numeroDoQuarto; // Retorna o numero do quarto reservado
        }
    }

    printf("Não há quartos disponíveis para o tipo selecionado.\n");
    return 0;
}