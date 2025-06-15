#ifndef WRITE_JSON_H
#define WRITE_JSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "../linked.h"
#include "../tree_data.h"

#define DATABASE_BIOSKOP "../../assets/bioskop_database.json"

cJSON* kursi_to_json(Kursi* current_kursi);

cJSON* jadwal_to_json(Jadwal* current_jadwal);

cJSON* studio_to_json(Studio* current_studio);

cJSON* bioskop_to_json(Bioskop* current_bioskop, address studio_node);

cJSON* kota_to_json(Kota* current_kota, address bioskop_node);

cJSON* provinsi_to_json(Provinsi* current_provinsi, address kota_node);

cJSON* negara_to_json(Negara* current_negara, address provinsi_node);

cJSON* tree_to_json(address node_tree);

void save_tree_to_file(address root, const char* filename);

#endif
