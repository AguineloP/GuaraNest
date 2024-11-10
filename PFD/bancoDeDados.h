
struct CLIENTES{
    char nomeCliente[100];
    char cpfCliente[12];
}cliente[100];

struct RESERVAS{
    int numeroDoQuarto;
    int tipoDeCama;
    int tipoDeTv;
    int numeroDeDias;
    char dataDeEntrada[11];
    char dataDeSaida[11];
    struct CLIENTES *cliente;
}reserva[200];

struct ADMIN{
    char nomeAdmin[100];
    int idAdmin;
}adm;

struct ADMIN adm = {"Rayssa", 12345};

void ENTRADAS_BASE(){
    //Entradas base de clientes

    strcpy(cliente[0].nomeCliente, "João Silva");
    strcpy(cliente[0].cpfCliente, "12345678901");
    
    strcpy(cliente[1].nomeCliente, "Maria Galdina");
    strcpy(cliente[1].cpfCliente, "13456729263");

    strcpy(cliente[2].nomeCliente, "Eli Tomaz");
    strcpy(cliente[2].cpfCliente, "98765432787");

    //Entradas base de reservas

    reserva[0].numeroDoQuarto = 001;
    reserva[0].tipoDeCama = 2;
    reserva[0].tipoDeTv = 1;
    strcpy(reserva[0].dataDeEntrada, "23/09/2024");
    strcpy(reserva[0].dataDeSaida, "25/09/2024");
    reserva[0].cliente = &cliente[0];
}