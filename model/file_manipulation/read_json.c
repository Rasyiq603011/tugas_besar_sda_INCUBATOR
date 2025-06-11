#include "read_json.h"

cJSON* load_json_file() 
{
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


Time json_to_time(cJSON* obj) 
{
    Time current_time;
    current_time.jam = cJSON_GetObjectItem(obj, "jam")->valueint;
    current_time.menit = cJSON_GetObjectItem(obj, "menit")->valueint;
    current_time.detik = cJSON_GetObjectItem(obj, "detik")->valueint;
    return current_time;
}

date json_to_date(cJSON* obj) 
{
    date current_date;
    current_date.Tgl = cJSON_GetObjectItem(obj, "tgl")->valueint;
    current_date.Bln = cJSON_GetObjectItem(obj, "bln")->valueint;
    current_date.Thn = cJSON_GetObjectItem(obj, "thn")->valueint;
    return current_date;
}

Kursi* json_to_kursi(cJSON* obj) 
{
    Kursi* current_kursi;
    const char* id = cJSON_GetObjectItem(obj, "id")->valuestring;
    boolean status = cJSON_IsTrue(cJSON_GetObjectItem(obj, "status"));
    KursiType tipe = cJSON_GetObjectItem(obj, "tipe")->valueint;
    create_new_kursi(&current_kursi, id, status, tipe);
    return current_kursi;
}

void set_kursi_from_json_array(Jadwal* jadwal, cJSON* kursi_arr) 
{
    int row = 0;
    cJSON* row_item;
    cJSON_ArrayForEach(row_item, kursi_arr) 
    {
        int col = 0;
        cJSON* col_item;
        cJSON_ArrayForEach(col_item, row_item) 
        {
            Kursi k = json_to_kursi(col_item);
            set_kursi_value_by_index(jadwal, row, col, k);
            col++;
        }
        row++;
    }
}

Jadwal* json_to_jadwal(cJSON* obj) {
    Jadwal* current_jadwal;
    set_time(j, json_to_time(cJSON_GetObjectItem(obj, "waktu")));
    set_date(j, json_to_date(cJSON_GetObjectItem(obj, "tanggal")));
    set_film_name(j, cJSON_GetObjectItem(obj, "film")->valuestring);
    set_harga_tiket(j, cJSON_GetObjectItem(obj, "harga")->valueint);

    cJSON* kursi_array = cJSON_GetObjectItem(obj, "kursi");
    if (kursi_array) set_kursi_from_json_array(j, kursi_array);

    return j;
}

Studio* json_to_studio(cJSON* obj) {
    Studio* s = create_studio();
    set_name(s, cJSON_GetObjectItem(obj, "nama")->valuestring);
    set_pendapatan(s, cJSON_GetObjectItem(obj, "pendapatan")->valueint);

    cJSON* jadwal_array = cJSON_GetObjectItem(obj, "jadwal");
    if (jadwal_array) {
        List* l = get_jadwal(s);
        cJSON* item;
        cJSON_ArrayForEach(item, jadwal_array) {
            add_jadwal(l, json_to_jadwal(item));
        }
    }

    return s;
}

Bioskop* json_to_bioskop(cJSON* obj, address* out_first_son) {
    Bioskop* b = create_bioskop();
    set_name(b, cJSON_GetObjectItem(obj, "nama")->valuestring);
    set_pendapatan_bioskop(b, cJSON_GetObjectItem(obj, "pendapatan")->valueint);
    set_alamat(b, cJSON_GetObjectItem(obj, "alamat")->valuestring);

    cJSON* studio_arr = cJSON_GetObjectItem(obj, "studio");
    if (studio_arr) {
        *out_first_son = json_array_to_tree(studio_arr, TYPE_STUDIO);
    }

    return b;
}

Kota* json_to_kota(cJSON* obj, address* out_first_son) {
    Kota* k = create_kota();
    set_name(k, cJSON_GetObjectItem(obj, "nama")->valuestring);
    set_pendapatan_kota(k, cJSON_GetObjectItem(obj, "pendapatan")->valueint);
    set_jumlah_bioskop(k, cJSON_GetObjectItem(obj, "jumlah_bioskop")->valueint);

    cJSON* bioskop_arr = cJSON_GetObjectItem(obj, "bioskop");
    if (bioskop_arr) {
        *out_first_son = json_array_to_tree(bioskop_arr, TYPE_BIOSKOP);
    }

    return k;
}

Provinsi* json_to_provinsi(cJSON* obj, address* out_first_son) {
    Provinsi* p = create_provinsi();
    set_name(p, cJSON_GetObjectItem(obj, "nama")->valuestring);
    set_pendapatan_provinsi(p, cJSON_GetObjectItem(obj, "pendapatan")->valueint);
    set_jumlah_bioskop(p, cJSON_GetObjectItem(obj, "jumlah_bioskop")->valueint);

    cJSON* kota_arr = cJSON_GetObjectItem(obj, "kota");
    if (kota_arr) {
        *out_first_son = json_array_to_tree(kota_arr, TYPE_KOTA);
    }

    return p;
}

Negara* json_to_negara(cJSON* obj, address* out_first_son) {
    Negara* n = create_negara();
    set_name(n, cJSON_GetObjectItem(obj, "nama")->valuestring);
    set_pendapatan_negara(n, cJSON_GetObjectItem(obj, "pendapatan")->valueint);
    set_jumlah_bioskop(n, cJSON_GetObjectItem(obj, "jumlah_bioskop")->valueint);

    cJSON* provinsi_arr = cJSON_GetObjectItem(obj, "provinsi");
    if (provinsi_arr) {
        *out_first_son = json_array_to_tree(provinsi_arr, TYPE_PROVINSI);
    }

    return n;
}

address json_array_to_tree(cJSON* arr, int tipe) {
    address first = NULL, prev = NULL;
    cJSON* item;

    cJSON_ArrayForEach(item, arr) {
        address node = allocate_node();

        switch (tipe) {
            case TYPE_PROVINSI:
                node->info.provinsi = json_to_provinsi(item, &node->first_son);
                break;
            case TYPE_KOTA:
                node->info.kota = json_to_kota(item, &node->first_son);
                break;
            case TYPE_BIOSKOP:
                node->info.bioskop = json_to_bioskop(item, &node->first_son);
                break;
            case TYPE_STUDIO:
                node->info.studio = json_to_studio(item);
                break;
            default:
                break;
        }

        node->tipe = tipe;
        node->next_brother = NULL;

        if (!first) first = node;
        else prev->next_brother = node;

        prev = node;
    }

    return first;
}
