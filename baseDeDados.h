#ifndef BASEDEDADOS_H_INCLUDED
#define BASEDEDADOS_H_INCLUDED


// Declara o numero total de clientes cadastrados e reservas feitas,
// esses valores começam com base nos valores inseridos na base de dados
int numeroDeReservas = 1;
char nomeHotel[200] = "PEPA PIG";    // Nome do hotel

struct CLIENTES {
    char nomeCliente[100];
    int cpfCliente;
}cliente;

struct RESERVAS{
    int numeroDoQuarto;
    int tipoDeCama;
    //int tipoDeTv;
    char dataDeEntrada[12];
    char dataDeSaida[12];
    struct CLIENTES *cliente;
}reserva[200];

struct ADMIN{
    char nomeAdmin[100];
    int idAdmin;
}adm;

struct ADMIN adm = {"Rayssa", 12345};

void ENTRADAS_BASE(){
    // Entradas base de reservas

    reserva[0].numeroDoQuarto = 1;
    reserva[0].tipoDeCama = 2;
    //reserva[0].tipoDeTv = 1;
    strcpy(reserva[0].dataDeEntrada, "23/09/2024");
    strcpy(reserva[0].dataDeSaida, "25/09/2024");
    reserva[0].cliente = &cliente;
}


#endif // BASEDEDADOS_H_INCLUDED
