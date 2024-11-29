#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ACESSO_INICIAL(void);  // Tô chamando a função aqui pra parar de ficar mostrando alertas de função implicita.

#include "baseDeDados.h" // Possui as structs com os dados do hotel
#include "textos.h"      // Possui os textos base do sistema
#include "admin.h"       // Possui a pagina do administrador
#include "menuHotel.h"   // Possui a pagina principal do hotel
#include "login.h"       // Possui as verificações de login e registro do sistema

int main(){
    ACESSO_INICIAL();
    return 0;
}

void ACESSO_INICIAL(){
    int opcaoAcesso;
    CABECALHO();
    printf("\nEscolha sua nivel de acesso: \n");
    printf("\n0 - Sair\n1 - Cliente\n2 - Administrador\n");
    scanf("%d", &opcaoAcesso);

    switch (opcaoAcesso){ // Verifica a opção de acesso do usuário e o direciona a proxima parte.
    case 0:
        printf("\nSistema encerrado.\n");
        break;
    case 1:
        CLIENTE();
        break;

    case 2:
        ADMIN();
        break;
    default:
        printf("\nOpcao invalida, por favor tente novamente.\n\n");
        ACESSO_INICIAL();
        break;
    }
}
