#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED


void CLIENTE();     // Tô chamando a função aqui pra parar de ficar mostrando alertas de função implicita.

int ENTRAR(int CPF, char nome[]){
    FILE *clientes;
    clientes = fopen("arquivos/clientes.txt","r");

    if(clientes == NULL){
        printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
        return 1;
    }

    int cpfVerifica;
    char nomeVerifca[100],sobrenomeVerifica[100];

    while (fscanf(clientes, "%s %s %d",nomeVerifca, sobrenomeVerifica, &cpfVerifica) != EOF) {
        char nomeCompleto[100];
        sprintf(nomeCompleto, "%s %s", nomeVerifca, sobrenomeVerifica);

        if(cpfVerifica == CPF && strcmp(nome, nomeCompleto) == 0) {
            cliente.cpfCliente = CPF;   // GUARDA OS DADOS DE ACESSO CASO PRECISE FUTURAMENTE
            strcpy(cliente.nomeCliente, nome);
            return 1;
        }

    }

    fclose(clientes);

    return 0; // CPF não encontrado
}

void CADASTRO(char nome[], int cpf){
    int contador = 0;
    char linha[200];
    FILE *clientes;

    clientes = fopen("arquivos/clientes.txt","r");

    if(clientes == NULL){
        printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
        return 1;
    }

    while (fgets(linha, sizeof(linha), clientes) != NULL) {
        contador++;
    }

    fclose(clientes);
    if(contador >= 100){
        printf("LIMITE DE USUARIOS CADASTRADOS ALCANCADO(100).");
        return 1;
    }else{
        if(strlen(nome) > 0){ // Verifica  se o nome não esta vazio
            clientes = fopen("arquivos/clientes.txt","a");

            if(clientes == NULL){
                printf("ERRO INESPERADO POR PARTE DO SERVIDOR, POR FAVOR TENTE NOVAMENTE UMA OUTRA HORA");
                return 1;
            }

            fprintf(clientes,"%s %d\n",nome,cpf);
            fclose(clientes);

            printf("\nCliente cadastrado com sucesso!\n");

            cliente.cpfCliente = cpf;   // GUARDA OS DADOS DE ACESSO CASO PRECISE FUTURAMENTE
            strcpy(cliente.nomeCliente, nome);
            MENU_HOTEL(nome);   // Envia o cliente para a pagina principal

        }
    }

    fclose(clientes);
}

void CLIENTE(){
    int opEntrada = 666;
    printf("\nSeja bem vindo querido Cliente!\n");
    do{
        printf("\nPor favor, selecione sua opcao de entrada: ");
        printf("\n0 - Voltar\n1 - Entrar\n2 - Cadastro\n");
        scanf("%d", &opEntrada);

        switch (opEntrada){
        case 0: // Volta a pagina inicial
            ACESSO_INICIAL();
            break;

        case 1:
            printf("\n-----------------------------------------------\n");
            printf("\tLOGIN DE CLIENTE");
            printf("\n-----------------------------------------------\n");

            char Nome[100];
            int CPF;

            printf("\nDigite seu nome e sobrenome: ");
            getchar();
            fgets(Nome, sizeof(Nome), stdin);
            Nome[strcspn(Nome, "\n")] = '\0';

            printf("\nDigite seu CPF(Apenas numeros!): ");
            scanf("%d", &CPF);

            if(ENTRAR(CPF,Nome)){
                printf("\nLogin bem sucedido!");
                MENU_HOTEL(Nome); // Envia o cliente para o menu principal
            }else{
                printf("\n\tLogin invalido!!\n");
                CLIENTE(); // Envia o cliente de volta ao menu anterior
            }
            break;

        case 2:
            printf("\n-----------------------------------------------\n");
            printf("\tCADASTRO DE CLIENTE");
            printf("\n-----------------------------------------------\n");
            char nome[100];
            int cpf;

            printf("\nDigite seu nome e sobrenome: ");
            getchar();
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';

            printf("\nDigite seu CPF(Apenas numeros!): ");
            scanf("%d", &cpf);

            CADASTRO(nome, cpf); // Faz a inserção na base de dados

            break;
        default:
            printf("\nOpcao invalida! Tente novamente.");
            break;
        }
    // Mantem o loop enquanto uma das as opções validas não forem selecionadas
    } while (opEntrada != 0 && opEntrada != 1 && opEntrada != 2);
}

void ADMIN(){
    int idEntrada;
    printf("\nPor favor insira a sua senha de acesso: ");
    scanf("%d", &idEntrada);

    // Verifica se o ID do admin esta na base de dados
    if(idEntrada == adm.idAdmin){
        PAINEL_ADM(idEntrada); // Envia o adm para sua pagina principal
    }else{
        printf("\nEntrada invalida.\n");
        ACESSO_INICIAL();
    }
}

#endif // LOGIN_H_INCLUDED
