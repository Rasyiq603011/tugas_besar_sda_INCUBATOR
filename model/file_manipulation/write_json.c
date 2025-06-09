#include "write_json.h"

cJSON* load_json_file() {
    FILE* file = fopen(FILENAME, "rb");
    if (!file) return cJSON_CreateArray();

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* data = (char*)malloc(size + 1);
    fread(data, 1, size, file);
    data[size] = '\0';
    fclose(file);

    cJSON* bioskop_database = cJSON_Parse(data);
    free(data);
    return bioskop_database ? bioskop_database : cJSON_CreateArray();
}

cJSON *time_to_json(Time* current_kursi)
{

}

cJSON *date_to_json(date* current_kursi)
{

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
    cJSON_AddItemToObject(obj, "", list_kursi_to_json(current_jadwal));
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
    cJSON_AddStringToObject(obj, "nama", k.info);
    cJSON_AddNumberToObject(obj, "pendapatan", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *bioskop_to_json(Bioskop* current_bioskop)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name(current_bioskop));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_bioskop(current_bioskop));
    cJSON_AddStringToObject(obj, "alamat", get_alamat(current_bioskop));
    return obj;
}

cJSON *kota_to_json(Kota* current_kota)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *provinsi_to_json(Provinsi* current_provinsi)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *negara_to_json(Negara* current_negara)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *create_array_json_from_list(List object)
{
    cJSON *array = cJSON_CreateArray();
    infotype k;
    cJSON_AddItemToArray(array, negara_to_json(k));

    cJSON *jadwal_array = cJSON_CreateArray();
    int i;
    for (i = 0; i < f.jumlah_jadwal; i++) {
        cJSON_AddItemToArray(jadwal_array, jadwal_to_json(f.jadwal[i]));
    }
    cJSON_AddItemToObject(obj, "jadwal", jadwal_array);
}