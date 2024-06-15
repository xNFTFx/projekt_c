#pragma once

typedef struct Data{
    int dzien;
    int h;
} Data;

typedef struct Sala{
    int nr_sali;
}Sala;

typedef struct Rezerwacja{
    int id;
    Sala sala_rezerwowana;
    Data data_rezerwacji;
}Rezerwacja;
