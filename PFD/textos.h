
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

void PRECO_CAMAS(){ 
    printf("\nTipo\t\tPreco\n\n1 - Com cama de Solteiro\tR$%.2f\n2 - com cama de Casal\tR$%.2f\n3 - Com cama Queen size\tR$%.2f\n", camaSolteiro, camaCasal, camaQueen);
}

void ADM(){
    printf("\n-----------------------------------------------\n");
    printf("\n\tPAINEL DO ADMINISTRADOR\n");
    printf("\n-----------------------------------------------\n");
}