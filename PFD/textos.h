
void CABECALHO(){
    printf("\n\n");
    printf("-----------------------------------------------");
    printf("\n\tBEM VINDO AO HOTEL %s\n", nomeHotel);
    printf("-----------------------------------------------");
    printf("\n");
}

void MENU_OPCOES(){
    printf("\nMenu: \n");
    printf("\n0 - Sair\n1 - Solicitar reserva\n2 - Consultar Reserva\n3 - Cancelar reserva\n");
}

void PRECO_CAMAS(){ // No local de x será colocado a variavel com o preço de cada cama
    printf("\nTipo\t\tPreco\n\n1 - Solteiro\tR$x,00\n2 - Casal\tR$x,00\n3 - Queen size\tR$x,00\n");
}

void ADM(){
    printf("\n-----------------------------------------------\n");
    printf("\n\tPAINEL DO ADMINISTRADOR\n");
    printf("\n-----------------------------------------------\n");
}