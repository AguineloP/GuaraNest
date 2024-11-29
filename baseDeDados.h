#ifndef BASEDEDADOS_H_INCLUDED
#define BASEDEDADOS_H_INCLUDED


char nomeHotel[200] = "PEPA PIG";    // Nome do hotel

struct CLIENTES {
    char nomeCliente[100];
    int cpfCliente;
}cliente;



typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

struct ADMIN{
    char nomeAdmin[100];
    int idAdmin;
}adm;


struct ADMIN adm = {"Rayssa", 12345};



#endif // BASEDEDADOS_H_INCLUDED
