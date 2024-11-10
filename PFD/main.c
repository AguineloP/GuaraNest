#include <stdio.h>
#include <string.h>

int numeroDeClientes = 2; //Declara o numero total de clientes cadastrados

#include "bancoDeDados.h" //Possui as structs com os dados do hotel
#include "cabecalho.h" //Possui o cabeçalho base do sistema
#include "admin.h" //Possui a pagina do administrador
#include "login.h" //Possui as verificações de login/registro do sistema
#include "menuHotel.h" //Possui a pagina principal do hotel

int main(){
    ENTRADAS_BASE();
    CABECALHO();
    
    int opcaoAcesso;
    printf("\nEscolha sua nivel de acesso: \n");
    printf("\n0 - Sair\n1 - Cliente\n2 - Administrador\n");
    scanf("%d", &opcaoAcesso);

    switch (opcaoAcesso){ //Verifica a opção de acesso do usuário e o direciona a proxima parte.
    case 1:
        CLIENTE();
        break;
    case 2:
        ADMIN();
        break;
    case 0:
        printf("\nSistema encerrado\n");
        break;
    default:
        printf("\nOpcao invalida, por favor tente novamente.\n\n");
        break;
    }

    return 0;
}