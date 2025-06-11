#include "write_json.h"

cJSON *time_to_json(Time* current_time)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "jam", current_time->jam);
    cJSON_AddNumberToObject(obj, "menit", current_time->menit);
    cJSON_AddNumberToObject(obj, "detik", current_time->detik);
    return obj;
}

cJSON *date_to_json(date* current_date)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "tgl", current_date->Tgl);
    cJSON_AddNumberToObject(obj, "bln", current_date->Bln);
    cJSON_AddNumberToObject(obj, "thn", current_date->Thn);
    return obj;
}

cJSON *kursi_to_json(Kursi* current_kursi)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "id", get_id_kursi(current_kursi));
    cJSON_AddBoolToObject(obj, "status", get_status_kursi(current_kursi));
    cJSON_AddNumberToObject(obj, "tipe", get_tipe_kursi(current_kursi));
    return obj;
}

cJSON *jadwal_to_json(Jadwal* current_jadwal)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddObjectToObject(obj, "waktu", time_to_json(get_time(current_jadwal)));
    cJSON_AddObjectToObject(obj, "tanggal", date_to_json(get_date(current_jadwal)));
    cJSON_AddStringToObject(obj, "film", get_film_name(current_jadwal));
    cJSON_AddNumberToObject(obj, "harga", get_harga_tiket(current_jadwal));
    cJSON_AddItemToObject(obj, "kursi", list_kursi_to_json(current_jadwal));
    return obj;
}

cJSON* list_kursi_to_json(Jadwal* current_jadwal) 
{
    int row, col;
    cJSON* outer = cJSON_CreateArray();  
    for (row = 0; row < 3; ++row) 
    {
        cJSON* inner = cJSON_CreateArray();  
        for (col = 0; col < 3; ++col) {
            cJSON_AddItemToArray(inner, kursi_to_json(get_kursi_value_by_index(current_jadwal, row, col)));
        }
        cJSON_AddItemToArray(outer, inner);
    }

    return outer;
}

cJSON *studio_to_json(Studio* current_studio)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_studio));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan(current_studio));
    cJSON_AddItemToObject(obj, "jadwal", create_array_json_from_list(get_jadwal(current_studio)));
    return obj;
}

cJSON *bioskop_to_json(Bioskop* current_bioskop, address first_son)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_bioskop));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_bioskop(current_bioskop));
    cJSON_AddStringToObject(obj, "alamat", get_alamat(current_bioskop));
    cJSON_AddItemToObject(obj, "studio", create_array_json_from_tree_nodes(first_son));
    return obj;
}

cJSON *kota_to_json(Kota* current_kota, address first_son)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_kota));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_kota(current_kota));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop(current_kota));
    cJSON_AddItemToObject(obj, "bioskop", create_array_json_from_tree_nodes(first_son));
    return obj;
}

cJSON *provinsi_to_json(Provinsi* current_provinsi, address first_son)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_provinsi));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_provinsi(current_provinsi));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop(current_provinsi));
    cJSON_AddItemToObject(obj, "kota", create_array_json_from_tree_nodes(first_son));
    return obj;
}

cJSON *negara_to_json(Negara* current_negara, address first_son)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_negara));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_negara(current_negara));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop(current_negara));
    cJSON_AddItemToObject(obj, "provinsi", create_array_json_from_tree_nodes(first_son));
    return obj;
}

cJSON *create_array_json_from_list(List* object)
{
    cJSON *array = cJSON_CreateArray();
    pnode temp = object->First;

    while (temp != NULL)
    {
        switch (Type(temp))
        {
        case TYPE_JADWAL:
            cJSON_AddItemToArray(array, jadwal_to_json(temp->info.jadwal));
            break;

        case TYPE_EVENT:
            cJSON_AddItemToArray(array, event_to_json(temp->info.event));
            break;

        case TYPE_FILM:
            cJSON_AddItemToArray(array, film_to_json(temp->info.film));
            break;

        default:
            break;
        }
        temp = temp->next;
    }
    return array;
}

cJSON *create_array_json_from_tree_nodes(address first_son)
{
    cJSON *array = cJSON_CreateArray();
    if (first_son == NULL) return array;
    while (first_son != NULL)
    {
        switch (first_son->tipe)
        {
        case TYPE_NEGARA:
            cJSON_AddItemToArray(array, negara_to_json(first_son->info.negara, first_son->first_son));
            break;
    
        case TYPE_PROVINSI:
            cJSON_AddItemToArray(array, provinsi_to_json(first_son->info.provinsi, first_son->first_son));
            break;

        case TYPE_KOTA:
            cJSON_AddItemToArray(array, kota_to_json(first_son->info.kota, first_son->first_son));
            break;

        case TYPE_BIOSKOP:
            cJSON_AddItemToArray(array, bioskop_to_json(first_son->info.bioskop, first_son->first_son));
            break;

        case TYPE_STUDIO:
            cJSON_AddItemToArray(array, studio_to_json(first_son->info.studio));
            break;

        default:
            break;
        } 
        first_son = first_son->next_brother;
    }
    return array;
}