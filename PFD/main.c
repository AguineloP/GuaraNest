#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int numeroDeClientes = 2, numeroDeReservas = 1; //Declara o numero total de clientes cadastrados

#include "bancoDeDados.h" //Possui as structs com os dados do hotel
#include "cabecalho.h"  //Possui o cabeçalho base do sistema
#include "admin.h"      //Possui a pagina do administrador
#include "login.h"      //Possui as verificações de login/registro do sistema
#include "menuHotel.h"  //Possui a pagina principal do hotel

void ACESSO_INICIAL(){
    int opcaoAcesso;
    CABECALHO();
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
}

int main(){
    ENTRADAS_BASE();
    ACESSO_INICIAL(); 
    return 0;
}