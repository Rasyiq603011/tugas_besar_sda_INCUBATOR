#include "read_json.h"

static address parse_negara(cJSON* json);
static address parse_provinsi(cJSON* json);
static address parse_kota(cJSON* json);
static address parse_bioskop(cJSON* json);
static address parse_studio(cJSON* json);
static Jadwal* parse_jadwal(cJSON* jadwal_json);
static Kursi* parse_kursi(cJSON* kursi_json);
static void add_existing_child(address parent, address child);

address load_tree_from_file(const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (!file) 
    {
        fprintf(stderr, "Gagal membuka file %s untuk dibaca.\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(length + 1);
    fread(buffer, 1, length, file);
    buffer[length] = '\0';
    fclose(file);

    cJSON* root_json = cJSON_Parse(buffer);
    free(buffer);

    if (!root_json) 
    {
        fprintf(stderr, "Gagal parsing JSON: %s\n", cJSON_GetErrorPtr());
        return NULL;
    }

    address root = json_to_tree(root_json, TYPE_NEGARA);
    cJSON_Delete(root_json);
    return root;
}

// Dispatcher
address json_to_tree(cJSON* json, DataType tipe) 
{
    switch (tipe) 
    {
        case TYPE_NEGARA: return parse_negara(json);
        case TYPE_PROVINSI: return parse_provinsi(json);
        case TYPE_KOTA: return parse_kota(json);
        case TYPE_BIOSKOP: return parse_bioskop(json);
        case TYPE_STUDIO: return parse_studio(json);
        default: return NULL;
    }
}

static void add_existing_child(address parent, address child) 
{
    if (!parent->first_son) 
    {
        parent->first_son = child;
    }
     else 
    {
        address last = get_last_son(parent);
        last->next_brother = child;
    }
}

static address parse_negara(cJSON* json) 
{
    cJSON* nama = cJSON_GetObjectItem(json, "nama");
    cJSON* pendapatan = cJSON_GetObjectItem(json, "pendapatan");
    cJSON* jumlah_bioskop = cJSON_GetObjectItem(json, "jumlah_bioskop");

    if (!nama || !pendapatan || !jumlah_bioskop) return NULL;

    printf("[DEBUG] parse_negara: nama = %s, pendapatan = %lf, bioskop = %d\n",
        nama->valuestring, pendapatan->valueint, jumlah_bioskop->valueint);
        
    Negara* new_negara = constructor_negara(nama->valuestring, pendapatan->valueint, jumlah_bioskop->valueint);

    address node = create_node(NEGARA_INFO(new_negara), TYPE_NEGARA);
    cJSON* children = cJSON_GetObjectItem(json, "provinsi");

    cJSON* child = (children != NULL) ? children->child : NULL;
    while (child != NULL) 
    {
        address child_node = json_to_tree(child, TYPE_PROVINSI);
        if (child_node) add_existing_child(node, child_node);
        child = child->next;
    }
    return node;
}

static address parse_provinsi(cJSON* json) 
{
    cJSON* nama = cJSON_GetObjectItem(json, "nama");
    cJSON* pendapatan = cJSON_GetObjectItem(json, "pendapatan");
    cJSON* jumlah_bioskop = cJSON_GetObjectItem(json, "jumlah_bioskop");

    if (!nama || !pendapatan || !jumlah_bioskop) return NULL;

    Provinsi* new_provinsi = constructor_provinsi(nama->valuestring, pendapatan->valueint, jumlah_bioskop->valueint);

    address node = create_node(PROVINSI_INFO(new_provinsi), TYPE_PROVINSI);
    cJSON* children = cJSON_GetObjectItem(json, "kota");

    cJSON* child = (children != NULL) ? children->child : NULL;
    while (child != NULL) 
    {
        address child_node = json_to_tree(child, TYPE_KOTA);
        if (child_node) add_existing_child(node, child_node);
        child = child->next;
    }
    return node;
}

static address parse_kota(cJSON* json) 
{
    cJSON* nama = cJSON_GetObjectItem(json, "nama");
    cJSON* pendapatan = cJSON_GetObjectItem(json, "pendapatan");
    cJSON* jumlah_bioskop = cJSON_GetObjectItem(json, "jumlah_bioskop");

    if (!nama || !pendapatan || !jumlah_bioskop) return NULL;

    Kota* new_kota = constructor_kota(nama->valuestring, pendapatan->valueint, jumlah_bioskop->valueint);

    address node = create_node(KOTA_INFO(new_kota), TYPE_KOTA);
    cJSON* children = cJSON_GetObjectItem(json, "bioskop");

    cJSON* child = (children != NULL) ? children->child : NULL;
    while (child != NULL) 
    {
        address child_node = json_to_tree(child, TYPE_BIOSKOP);
        if (child_node) add_existing_child(node, child_node);
        child = child->next;
    }
    return node;
}

static address parse_bioskop(cJSON* json) 
{
    cJSON* nama = cJSON_GetObjectItem(json, "nama");
    cJSON* alamat = cJSON_GetObjectItem(json, "alamat");
    cJSON* pendapatan = cJSON_GetObjectItem(json, "pendapatan");

    if (!nama || !alamat || !pendapatan) return NULL;

    Bioskop* new_bioskop =  constructor_bioskop(nama->valuestring, pendapatan->valueint, alamat->valuestring);

    address node = create_node(BIOSKOP_INFO(new_bioskop), TYPE_BIOSKOP);
    cJSON* children = cJSON_GetObjectItem(json, "studio");

    cJSON* child = (children != NULL) ? children->child : NULL;
    while (child != NULL) 
    {
        address child_node = json_to_tree(child, TYPE_STUDIO);
        if (child_node) add_existing_child(node, child_node);
        child = child->next;
    }
    return node;
}

static address parse_studio(cJSON* json) {
    cJSON* nama = cJSON_GetObjectItem(json, "nama");
    cJSON* pendapatan = cJSON_GetObjectItem(json, "pendapatan");
    cJSON* jumlah_kursi = cJSON_GetObjectItem(json, "jumlah_kursi");
    if (!nama || !pendapatan || !jumlah_kursi) return NULL;

    Studio* new_studio = constructor_studio(nama->valuestring, pendapatan->valueint, jumlah_kursi->valueint);
    List* list_jadwal = (List*)malloc(sizeof(List));
    CreateList(list_jadwal);
    pnode jadwal_node = list_jadwal->First;

    cJSON* jadwal_array = cJSON_GetObjectItem(json, "jadwal");
    if (jadwal_array && cJSON_IsArray(jadwal_array)) 
    {
        cJSON* jadwal_json = jadwal_array->child;
        while (jadwal_json) 
        {
            Jadwal* new_jadwal = parse_jadwal(jadwal_json);
            if (new_jadwal)
            {
                insert_value_last(&jadwal_node, JADWAL_INFO(new_jadwal), TYPE_JADWAL);
            }
            jadwal_json = jadwal_json->next;
        }
    }
    set_jadwal_studio(new_studio, list_jadwal);

    return create_node(STUDIO_INFO(new_studio), TYPE_STUDIO);
}

static Jadwal* parse_jadwal(cJSON* jadwal_json) {
    if (!jadwal_json) return NULL;

    // Ambil data utama
    cJSON* waktu_start_json = cJSON_GetObjectItem(jadwal_json, "waktu_start");
    cJSON* waktu_end_json   = cJSON_GetObjectItem(jadwal_json, "waktu_end");
    cJSON* tanggal_json     = cJSON_GetObjectItem(jadwal_json, "tanggal");
    cJSON* film_json        = cJSON_GetObjectItem(jadwal_json, "film");
    cJSON* harga_json       = cJSON_GetObjectItem(jadwal_json, "harga");
    cJSON* jumlah_tiket_json= cJSON_GetObjectItem(jadwal_json, "jumlah_tiket");
    cJSON* kursi_array      = cJSON_GetObjectItem(jadwal_json, "kursi");

    if (!waktu_start_json || !waktu_end_json || !tanggal_json || !film_json ||
        !harga_json || !jumlah_tiket_json || !kursi_array)
        return NULL;

    Time* waktu_start = (Time*)malloc(sizeof(Time));
    Time* waktu_end   = (Time*)malloc(sizeof(Time));
    date* tanggal_tayang= (date*)malloc(sizeof(date));

    if (!waktu_start || !waktu_end || !tanggal_tayang) {
        free(waktu_start); free(waktu_end); free(tanggal_tayang);
        return NULL;
    }

    if (!string_to_time(waktu_start_json->valuestring, waktu_start) ||
        !string_to_time(waktu_end_json->valuestring, waktu_end) ||
        !string_to_date(tanggal_json->valuestring, tanggal_tayang)) 
    {
        free(waktu_start); free(waktu_end); free(tanggal_tayang);
        return NULL;
    }

    Jadwal* new_jadwal = constructor_jadwal(*waktu_start, *waktu_end, *tanggal_tayang, harga_json->valueint, film_json->valuestring, jumlah_tiket_json->valueint);

    if (!new_jadwal) {
        free(waktu_start); free(waktu_end); free(tanggal_tayang);
        return NULL;
    }

    Kursi* kursi_list[jumlah_tiket_json->valueint];
    if (cJSON_IsArray(kursi_array)) {
        int index_kursi = 0;
        cJSON* kursi_json = kursi_array->child;
        while (kursi_json && index_kursi < jumlah_tiket_json->valueint) 
        {
            Kursi* new_kursi = parse_kursi(kursi_json);
            if (new_kursi)
            {
                kursi_list[index_kursi] = new_kursi;
            }
            kursi_json = kursi_json->next;
            index_kursi++;
        }
    }
    set_daftar_kursi(new_jadwal, kursi_list, jumlah_tiket_json->valueint);
    return new_jadwal;
}

static Kursi* parse_kursi(cJSON* kursi_json) 
{
    if (!kursi_json) return NULL;
    cJSON* id = cJSON_GetObjectItem(kursi_json, "id");
    cJSON* status = cJSON_GetObjectItem(kursi_json, "status");
    cJSON* tipe = cJSON_GetObjectItem(kursi_json, "tipe");
    if (!id || !status || !tipe) return NULL;

    Kursi* new_kursi = constructor_kursi(id->valueint, status->valueint, tipe->valueint);
    return new_kursi;
}

User* load_user_from_json(const char* username_target) 
{
    FILE* file = fopen(DATABASE_USER, "r");
    if (!file) return NULL;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* content = malloc(size + 1);
    fread(content, 1, size, file);
    content[size] = '\0';
    fclose(file);

    cJSON* root = cJSON_Parse(content);
    free(content);
    if (!cJSON_IsArray(root)) {
        cJSON_Delete(root);
        return NULL;
    }

    for (int i = 0; i < cJSON_GetArraySize(root); i++) 
    {
        cJSON* user_obj = cJSON_GetArrayItem(root, i);
        cJSON* uname = cJSON_GetObjectItem(user_obj, "username");

        if (uname && strcmp(uname->valuestring, username_target) == 0) 
        {
            // Ambil field utama
            cJSON* pass = cJSON_GetObjectItem(user_obj, "password");
            cJSON* saldo = cJSON_GetObjectItem(user_obj, "saldo");
            cJSON* prioritas = cJSON_GetObjectItem(user_obj, "prioritas");

            int parsed_saldo = saldo ? saldo->valueint : 0;
            Prioritas parsed_prioritas = prioritas ? (Prioritas)prioritas->valueint : REGULER;

            User* user = create_user(uname->valuestring, pass->valuestring, parsed_prioritas, parsed_saldo);

            // Ambil array riwayat
            cJSON* riwayat_arr = cJSON_GetObjectItem(user_obj, "riwayat");
            if (cJSON_IsArray(riwayat_arr)) 
            {   
                for (int j = 0; j < cJSON_GetArraySize(riwayat_arr); j++) 
                {
                    cJSON* riw = cJSON_GetArrayItem(riwayat_arr, j);
                    const char* judul = cJSON_GetObjectItem(riw, "judul_film")->valuestring;
                    const char* tanggal = cJSON_GetObjectItem(riw, "tanggal")->valuestring;
                    const char* jam = cJSON_GetObjectItem(riw, "jam")->valuestring;
                    int harga = cJSON_GetObjectItem(riw, "harga_tiket")->valueint;
                    const char* kursi = cJSON_GetObjectItem(riw, "kursi")->valuestring;

                    Riwayat* new_riwayat = create_riwayat(strdup(judul), (char*)tanggal, (char*)jam, harga, strdup(kursi));
                    add_riwayat_user(user, new_riwayat);
                }
            }

            cJSON_Delete(root);
            return user;
        }
    }

    cJSON_Delete(root);
    return NULL; // user tidak ditemukan
}

bool is_username_available(const char* username_to_check, const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (!file) return true; // jika file belum ada, berarti username pasti belum dipakai

    fseek(file, 0, SEEK_END);
    long filesize = ftell(file);
    rewind(file);

    char* content = malloc(filesize + 1);
    fread(content, 1, filesize, file);
    content[filesize] = '\0';
    fclose(file);

    cJSON* root = cJSON_Parse(content);
    free(content);

    if (!root || !cJSON_IsArray(root)) 
    {
        cJSON_Delete(root);
        return true; // JSON rusak atau bukan array → anggap belum dipakai
    }
    
    int i;
    for (i = 0; i < cJSON_GetArraySize(root); i++) 
    {
        cJSON* user = cJSON_GetArrayItem(root, i);
        cJSON* username = cJSON_GetObjectItem(user, "username");
        if (username && strcmp(username->valuestring, username_to_check) == 0)
        {
            cJSON_Delete(root);
            return false; // sudah dipakai
        }
    }

    cJSON_Delete(root);
    return true; // tidak ditemukan → username tersedia
}

bool is_password_correct(const char* username, const char* password_input, const char* filename) 
{
    FILE* file = fopen(filename, "r");
    if (!file) return false;

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* content = malloc(size + 1);
    fread(content, 1, size, file);
    content[size] = '\0';
    fclose(file);

    cJSON* root = cJSON_Parse(content);
    free(content);
    if (!cJSON_IsArray(root)) 
    {
        cJSON_Delete(root);
        return false;
    }

    int i;
    for (i = 0; i < cJSON_GetArraySize(root); i++) 
    {
        cJSON* user_obj = cJSON_GetArrayItem(root, i);
        cJSON* uname = cJSON_GetObjectItem(user_obj, "username");
        cJSON* pass = cJSON_GetObjectItem(user_obj, "password");

        if (uname && pass && strcmp(uname->valuestring, username) == 0) 
        {
            bool result = strcmp(pass->valuestring, password_input) == 0;
            cJSON_Delete(root);
            return result;
        }
    }

    cJSON_Delete(root);
    return false; // username tidak ditemukan
}
