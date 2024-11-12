

// Declara o numero total de clientes cadastrados e reservas feitas, 
// esses valores começam com base nos valores inseridos na base de dados
int numeroDeClientes = 2, numeroDeReservas = 1; 
char nomeHotel[200] = "***";    // Nome do hotel
float camaSolteiro = 0, camaCasal = 0, camaQueen = 0;  // Valores dos quartos por camas

struct CLIENTES{
    char nomeCliente[100];
    char cpfCliente[13];
}cliente[100];

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
    // Entradas base de clientes

    strcpy(cliente[0].nomeCliente, "Joao Silva");
    strcpy(cliente[0].cpfCliente, "12345678901");
    
    strcpy(cliente[1].nomeCliente, "Maria Galdina");
    strcpy(cliente[1].cpfCliente, "13456729263");

    strcpy(cliente[2].nomeCliente, "Eli Tomaz");
    strcpy(cliente[2].cpfCliente, "98765432787");

    // Entradas base de reservas

    reserva[0].numeroDoQuarto = 1;
    reserva[0].tipoDeCama = 2;
    //reserva[0].tipoDeTv = 1;
    strcpy(reserva[0].dataDeEntrada, "23/09/2024");
    strcpy(reserva[0].dataDeSaida, "25/09/2024");
    reserva[0].cliente = &cliente[0];
}