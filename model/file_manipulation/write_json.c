#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "tree_data.h"
#include "linked.h"


cJSON* kursi_to_json(Kursi* current_kursi) {
    if (!current_kursi) return NULL;
    cJSON* obj_kursi = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj_kursi, "id", get_id_kursi(current_kursi));
    cJSON_AddBoolToObject(obj_kursi, "status", get_status_kursi(current_kursi));
    cJSON_AddNumberToObject(obj_kursi, "tipe", get_tipe_kursi(current_kursi));
    return obj_kursi;
}

cJSON* jadwal_to_json(Jadwal* current_jadwal) {
    if (!current_jadwal) return NULL;
    cJSON* obj_jadwal = cJSON_CreateObject();
    String waktu_start = time_to_string(get_waktu_start(current_jadwal));
    String waktu_end = time_to_string(get_waktu_end(current_jadwal));
    String tanggal = date_to_string(get_tanggal_tayang(current_jadwal));

    cJSON* kursi_array = cJSON_CreateArray();
    int current_kursi;
    for (current_kursi = 0; current_kursi < get_jumlah_tiket(current_jadwal); current_kursi++) {
        cJSON* kursi_obj = kursi_to_json(get_kursi_value_by_index(current_jadwal, current_kursi));
        cJSON_AddItemToArray(kursi_array, kursi_obj);
    }
    cJSON_AddStringToObject(obj_jadwal, "waktu_start", waktu_start);
    cJSON_AddStringToObject(obj_jadwal, "waktu_end", waktu_end);
    cJSON_AddStringToObject(obj_jadwal, "tanggal", tanggal);
    cJSON_AddStringToObject(obj_jadwal, "film", get_film(current_jadwal));
    cJSON_AddNumberToObject(obj_jadwal, "harga", get_harga_tiket(current_jadwal));
    cJSON_AddNumberToObject(obj_jadwal, "jumlah_tiket", get_jumlah_tiket(current_jadwal));
    cJSON_AddItemToObject(obj_jadwal, "kursi", kursi_array);
    free(waktu_start);
    free(waktu_end);
    free(tanggal);

    return obj_jadwal;
}

cJSON* studio_to_json(Studio* current_studio) {
    if (!current_studio) return NULL;
    cJSON* obj_studio = cJSON_CreateObject();
    cJSON* jadwal_array = cJSON_CreateArray();

    pnode jadwal_node = (get_jadwal_studio(current_studio))->First;
    while (jadwal_node) {
        cJSON* jadwal_obj = jadwal_to_json(jadwal_node->info.jadwal);
        cJSON_AddItemToArray(jadwal_array, jadwal_obj);
        jadwal_node = jadwal_node->next;
    }

    cJSON_AddStringToObject(obj_studio, "nama", get_name_studio(current_studio));
    cJSON_AddNumberToObject(obj_studio, "pendapatan", get_pendapatan_studio(current_studio));
    cJSON_AddNumberToObject(obj_studio, "jumlah_kursi", get_jumlah_kursi_studio(current_studio));
    cJSON_AddItemToObject(obj_studio, "jadwal", jadwal_array);

    return obj_studio;
}

cJSON* bioskop_to_json(Bioskop* current_bioskop, cJSON* array_studio) {
    if (!current_bioskop) return NULL;
    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_bioskop(current_bioskop));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_bioskop(current_bioskop));
    cJSON_AddStringToObject(obj, "alamat", get_alamat_bioskop(current_bioskop));
    cJSON_AddItemToObject(obj, "studio", array_studio);
    return obj;
}

cJSON* kota_to_json(Kota* current_kota, cJSON* array_bioskop) {
    if (!current_kota) return NULL;
    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_kota(current_kota));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_kota(current_kota));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_kota(current_kota));
    cJSON_AddItemToObject(obj, "bioskop", array_bioskop);
    return obj;
}

cJSON* provinsi_to_json(Provinsi* current_provinsi, cJSON* array_kota) {
    if (!current_provinsi) return NULL;
    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_provinsi(current_provinsi));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_provinsi(current_provinsi));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_provinsi(current_provinsi));
    cJSON_AddItemToObject(obj, "kota", array_kota);
    return obj;
}

cJSON* negara_to_json(Negara* current_negara, cJSON* array_provinsi) {
    if (!current_negara) return NULL;
    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_negara(current_negara));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_negara(current_negara));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_negara(current_negara));
    cJSON_AddItemToObject(obj, "provinsi", array_provinsi);
    return obj;
}

