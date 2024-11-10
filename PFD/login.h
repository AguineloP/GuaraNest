
int ENTRAR(char cpf[]){
    int i;
    for(i = 0; i < numeroDeClientes; i++){
        if(strcmp(cpf, cliente[i].cpfCliente) == 0){ //Verifica se o cpf digitado esta na base de dados
            return 1; //CPF encontrado
        }
    }
    return 0; //CPF não encontrado
}

void CADASTRO(char nome[], char cpf[]){
    if(numeroDeClientes < 100 && strlen(nome) > 0){ //Verifica se o numero de clientes e menor que o tamanho maximo e se o nome não esta vazio
        strcpy(cliente[numeroDeClientes].nomeCliente, nome);
        strcpy(cliente[numeroDeClientes].cpfCliente, cpf);
        numeroDeClientes++;//Incrementa o numero de clientes ja cadastrado
        
        printf("\nCliente cadastrado com sucesso!\n");
        //MENU_HOTEL(nome);//Envia o cliente para a pagina principal

    }else{
        if (numeroDeClientes >= 100) {
            printf("\nLimite de clientes atingido.\n");
        } else {
            printf("\nO nome do cliente nao pode ser vazio.\n");
        }
    }

}

void CLIENTE(){
    int opEntrada = 666;
    printf("\n-----------------------------------------------\n");
    printf("\nSeja bem vindo querido Cliente!\n");    
    do{
        printf("\nPor favor, selecione sua opcao de entrada: ");
        printf("\n0 - Sair\n1 - Entrar\n2 - Cadastro\n");
        scanf("%d", &opEntrada);

        switch (opEntrada){
        case 1:
            printf("\n\n-----------------------------------------------");
            printf("\n\tLOGIN DE CLIENTE\n");
            
            char Nome[100], CPF[12];

            printf("\nDigite seu nome: ");
            getchar();
            fgets(Nome, sizeof(Nome), stdin);
            Nome[strcspn(Nome, "\n")] = '\0';

            printf("\nDigite seu CPF(Apenas numeros!): ");
            getchar();
            fgets(CPF, sizeof(CPF), stdin);
            CPF[strcspn(CPF, "\n")] = '\0';
            
            if(ENTRAR(CPF)){
                printf("\nLogin bem sucedido!");
                //MENU_HOTEL(Nome); //Envia o cliente para o menu principal
            }else{
                printf("\nLogin invalido!\n");
                CLIENTE(); //Envia o cliente de volta ao menu anterior
            }

            break;

        case 2:
            printf("\n\n-----------------------------------------------");
            printf("\n\tCADASTRO DE CLIENTE\n");
            char nome[100], cpf[12];

            printf("\nDigite seu nome: ");
            getchar();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nDigite seu CPF (Apenas numeros!): ");
            getchar();
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';

            CADASTRO(nome, cpf); //Faz a inserção na base de dados
            
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.");
            break;
        }
    } while (opEntrada != 0 && opEntrada != 1 && opEntrada != 2); //Mantem o loop enquanto uma das as opções validas não forem selecionadas
}

void ADMIN(){
    int idEntrada;
    printf("\nPor favor insira seus dados de acesso: ");
    scanf("%d", &idEntrada);

    if(idEntrada == adm.idAdmin){ //Verifica se o ID do admin esta na base de dados
        PAINEL_ADM(idEntrada); //Envia o adm para sua pagina principal
    }else{
        printf("\nEntrada invalida.\n");
    }
}