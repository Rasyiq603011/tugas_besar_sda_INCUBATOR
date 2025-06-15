#ifndef WRITE_JSON_H
#define WRITE_JSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "linked.h"
#include "tree_data.h"

#define DATABASE_BIOSKOP "../../assets/bioskop_database.json"

cJSON* kursi_to_json(Kursi* current_kursi);

cJSON* jadwal_to_json(Jadwal* current_jadwal);

cJSON* studio_to_json(Studio* current_studio);

cJSON* bioskop_to_json(Bioskop* current_bioskop, cJSON* array_studio);

cJSON* kota_to_json(Kota* current_kota, cJSON* array_bioskop);

cJSON* provinsi_to_json(Provinsi* current_provinsi, cJSON* array_kota);

cJSON* negara_to_json(Negara* current_negara, cJSON* array_provinsi);

cJSON* tree_to_json_rekursif(address root);

void save_tree_to_json(Tree T, const char* filename);

address json_to_tree(cJSON* root);

#endif