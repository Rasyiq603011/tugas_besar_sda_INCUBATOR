#include "write_json.h"

cJSON* kursi_to_json(Kursi* current_kursi) 
{
    if (!current_kursi) return NULL;
    cJSON* obj_kursi = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj_kursi, "id", get_id_kursi(current_kursi));
    cJSON_AddBoolToObject(obj_kursi, "status", get_status_kursi(current_kursi));
    cJSON_AddNumberToObject(obj_kursi, "tipe", get_tipe_kursi(current_kursi));
    return obj_kursi;
}

cJSON* jadwal_to_json(Jadwal* current_jadwal) 
{
    if (!current_jadwal) return NULL;
    cJSON* obj_jadwal = cJSON_CreateObject();
    String waktu_start = time_to_string(get_waktu_start(current_jadwal));
    String waktu_end = time_to_string(get_waktu_end(current_jadwal));
    String tanggal = date_to_string(get_tanggal_tayang(current_jadwal));

    cJSON* kursi_array = cJSON_CreateArray();
    for (int i = 0; i < get_jumlah_tiket(current_jadwal); i++) 
    {
        cJSON* kursi_obj = kursi_to_json(get_kursi_value_by_index(current_jadwal, i));
        if (kursi_obj) cJSON_AddItemToArray(kursi_array, kursi_obj);
    }

    cJSON_AddStringToObject(obj_jadwal, "waktu_start", waktu_start);
    cJSON_AddStringToObject(obj_jadwal, "waktu_end", waktu_end);
    cJSON_AddStringToObject(obj_jadwal, "tanggal", tanggal);
    cJSON_AddStringToObject(obj_jadwal, "film", get_film_name(current_jadwal));
    cJSON_AddNumberToObject(obj_jadwal, "harga", get_harga_tiket(current_jadwal));
    cJSON_AddNumberToObject(obj_jadwal, "jumlah_tiket", get_jumlah_tiket(current_jadwal));
    cJSON_AddItemToObject(obj_jadwal, "kursi", kursi_array);

    free(waktu_start);
    free(waktu_end);
    free(tanggal);

    return obj_jadwal;
}

cJSON* studio_to_json(Studio* current_studio) 
{
    if (!current_studio) return NULL;
    cJSON* obj_studio = cJSON_CreateObject();
    cJSON* jadwal_array = cJSON_CreateArray();

    pnode jadwal_node = (get_jadwal_studio(current_studio))->First;
    while (jadwal_node) 
    {
        cJSON* jadwal_obj = jadwal_to_json(jadwal_node->info.jadwal);
        if (jadwal_obj) cJSON_AddItemToArray(jadwal_array, jadwal_obj);
        jadwal_node = jadwal_node->next;
    }

    cJSON_AddStringToObject(obj_studio, "nama", get_name_studio(current_studio));
    cJSON_AddNumberToObject(obj_studio, "pendapatan", get_pendapatan_studio(current_studio));
    cJSON_AddNumberToObject(obj_studio, "jumlah_kursi", get_jumlah_kursi_studio(current_studio));
    cJSON_AddItemToObject(obj_studio, "jadwal", jadwal_array);

    return obj_studio;
}

cJSON* bioskop_to_json(Bioskop* current_bioskop, address studio_node) 
{
    cJSON* array_studio = cJSON_CreateArray();
    while (studio_node) 
    {
        cJSON* studio_obj = tree_to_json(studio_node);
        if (studio_obj) cJSON_AddItemToArray(array_studio, studio_obj);
        studio_node = studio_node->next_brother;
    }

    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_bioskop(current_bioskop));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_bioskop(current_bioskop));
    cJSON_AddStringToObject(obj, "alamat", get_alamat_bioskop(current_bioskop));
    cJSON_AddItemToObject(obj, "studio", array_studio);
    return obj;
}

cJSON* kota_to_json(Kota* current_kota, address bioskop_node) 
{
    cJSON* array_bioskop = cJSON_CreateArray();
    while (bioskop_node) 
    {
        cJSON* bioskop_obj = tree_to_json(bioskop_node);
        if (bioskop_obj) cJSON_AddItemToArray(array_bioskop, bioskop_obj);
        bioskop_node = bioskop_node->next_brother;
    }

    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_kota(current_kota));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_kota(current_kota));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_kota(current_kota));
    cJSON_AddItemToObject(obj, "bioskop", array_bioskop);
    return obj;
}

cJSON* provinsi_to_json(Provinsi* current_provinsi, address kota_node) 
{
    cJSON* array_kota = cJSON_CreateArray();
    while (kota_node) 
    {
        cJSON* kota_obj = tree_to_json(kota_node);
        if (kota_obj) cJSON_AddItemToArray(array_kota, kota_obj);
        kota_node = kota_node->next_brother;
    }

    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "nama", get_name_provinsi(current_provinsi));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_provinsi(current_provinsi));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_provinsi(current_provinsi));
    cJSON_AddItemToObject(obj, "kota", array_kota);
    return obj;
}

cJSON* negara_to_json(Negara* current_negara, address provinsi_node) 
{
    cJSON* array_provinsi = cJSON_CreateArray();
    while (provinsi_node) 
    {
        cJSON* provinsi_obj = tree_to_json(provinsi_node);
        if (provinsi_obj) cJSON_AddItemToArray(array_provinsi, provinsi_obj);
        provinsi_node = provinsi_node->next_brother;
    }

    cJSON* obj = cJSON_CreateObject();
    printf("Nama negara: %s\n", get_name_negara(current_negara));
    cJSON_AddStringToObject(obj, "nama", get_name_negara(current_negara));
    cJSON_AddNumberToObject(obj, "pendapatan", get_pendapatan_negara(current_negara));
    cJSON_AddNumberToObject(obj, "jumlah_bioskop", get_jumlah_bioskop_negara(current_negara));
    cJSON_AddItemToObject(obj, "provinsi", array_provinsi);
    return obj;
}

cJSON* tree_to_json(address node_tree) 
{
    if (!node_tree) return NULL;
    switch (node_tree->tipe) {
        case TYPE_NEGARA:
            return negara_to_json(info_negara(node_tree), node_tree->first_son);
        case TYPE_PROVINSI:
            return provinsi_to_json(info_provinsi(node_tree), node_tree->first_son);
        case TYPE_KOTA:
            return kota_to_json(info_kota(node_tree), node_tree->first_son);
        case TYPE_BIOSKOP:
            return bioskop_to_json(info_bioskop(node_tree), node_tree->first_son);
        case TYPE_STUDIO:
            return studio_to_json(info_studio(node_tree));
        default:
            return NULL;
    }
}

void save_tree_to_file(address root, const char* filename) 
{

    cJSON* json_tree = tree_to_json(root);
    if (!json_tree) 
    {
        fprintf(stderr, "Gagal mengkonversi tree ke JSON.\n");
        return;
    }

    char* json_string = cJSON_Print(json_tree);
    if (!json_string) 
    {
        fprintf(stderr, "Gagal mengkonversi cJSON ke string.\n");
        cJSON_Delete(json_tree);
        return;
    }

    FILE* file = fopen(filename, "wb");
    if (!file) 
    {
        fprintf(stderr, "Gagal membuka file %s untuk ditulis.\n", filename);
        free(json_string);
        cJSON_Delete(json_tree);
        return;
    }

    fprintf(file, "%s", json_string);
    fclose(file);

    printf("Data berhasil disimpan ke file: %s\n", filename);

    free(json_string);
    cJSON_Delete(json_tree);
}

static cJSON* load_users_from_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) return cJSON_CreateArray();

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    rewind(file);

    char* content = (char*)malloc(size + 1);
    if (!content || fread(content, 1, size, file) != size) {
        fclose(file);
        free(content);
        return cJSON_CreateArray(); // fallback
    }
    content[size] = '\0';
    fclose(file);

    cJSON* root = cJSON_Parse(content);
    free(content);
    return root ? root : cJSON_CreateArray();
}

static void write_users_to_file(const char* filename, cJSON* root) {
    FILE* file = fopen(filename, "w");
    if (!file) return;

    char* json_string = cJSON_PrintUnformatted(root);
    if (json_string) {
        fprintf(file, "%s", json_string);
        free(json_string);
    }
    fclose(file);
}

static cJSON* convert_riwayat_to_json(Riwayat* riwayat) {
    cJSON* array = cJSON_CreateArray();
    while (riwayat) {
        cJSON* obj = cJSON_CreateObject();
        cJSON_AddStringToObject(obj, "judul_film", get_judul_film_riwayat(riwayat) ?: "");
        cJSON_AddStringToObject(obj, "tanggal", get_tanggal_riwayat(riwayat) ?: "");
        cJSON_AddStringToObject(obj, "jam", get_jam_riwayat(riwayat) ?: "");
        cJSON_AddNumberToObject(obj, "harga_tiket", get_harga_tiket_riwayat(riwayat));
        cJSON_AddStringToObject(obj, "kursi", get_kursi_riwayat(riwayat) ?: "");
        cJSON_AddItemToArray(array, obj);
        riwayat = get_next_riwayat(riwayat);
    }
    return array;
}

static cJSON* create_user_json_object(User* user) {
    cJSON* obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "username", get_username_user(user) ?: "");
    cJSON_AddStringToObject(obj, "password", get_password_user(user) ?: "");
    cJSON_AddNumberToObject(obj, "saldo", get_saldo_user(user));
    cJSON_AddNumberToObject(obj, "prioritas", get_prioritas_user(user));
    cJSON_AddItemToObject(obj, "riwayat", convert_riwayat_to_json(get_pointer_to_riwayat(user)));
    return obj;
}

// ===============================
// Main Function
// ===============================

void save_user_to_json(User* user) 
{
    if (!user) return;

    const char* target_username = get_username_user(user);
    if (!target_username) return;

    cJSON* root = load_users_from_file(USER_FILE);

    // Cari jika user sudah ada
    int index = -1;
    for (int i = 0; i < cJSON_GetArraySize(root); ++i) {
        cJSON* item = cJSON_GetArrayItem(root, i);
        cJSON* uname = cJSON_GetObjectItem(item, "username");
        if (uname && strcmp(uname->valuestring, target_username) == 0) {
            index = i;
            break;
        }
    }

    // Buat object user JSON
    cJSON* user_obj = create_user_json_object(user);

    // Replace atau tambahkan
    if (index != -1) {
        if (!user_obj) 
        {
            cJSON_Delete(root);
            return;
        }
        cJSON_ReplaceItemInArray(root, index, user_obj);
    } else {
        cJSON_AddItemToArray(root, user_obj);
    }

    // Tulis ke file
    write_users_to_file(USER_FILE, root);

    // Cleanup
    cJSON_Delete(root);
}
