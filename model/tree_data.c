#include "tree_data.h"
<<<<<<< HEAD

address create_node(Infotype info, Datatype tipe){

    address new_node = (address) malloc(sizeof(ElmtList));
    new_node->tipe = tipe;
    new_node->first_son = NULL;
    new_node->next_brother = NULL;
    switch(tipe){
        case PROVINSI:
            new_node->info.provinsi = // Fungsi Constructor Struct Provinsi
            break;
        case KOTA:
            new_node->info.kota = // Fungsi Constructor Struct Kota
            break;
        case BIOSKOP:
            new_node->info.bioskop = // Fungsi Constructor Struct Bioskop
            break;
        case FILM:
            new_node->info.film = // Fungsi Constructor Struct Film;
            break;
        case TANGGAL:
            new_node->info.tanggal = // Fungsi Constructor Struct Tanggal;
            break;
        case JADWAL:
            new_node->info.jadwal = // Fungsi Constructor Struct Jadwal;
    }
    return new_node;


void add_child(address parent, address child){
    if(parent.)

}
}

=======
>>>>>>> refs/remotes/origin/main
