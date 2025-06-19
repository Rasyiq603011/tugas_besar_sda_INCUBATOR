#ifndef READ_JSON_H
#define READ_JSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "../linked.h"
#include "../tree_data.h"

#define FILENAME "../../assets/bioskop_database.json"
#define DATABASE_USER "../assets/users.json"

// === INTERFACE ===
address load_tree_from_file(const char* filename);
address json_to_tree(cJSON* json, DataType tipe);
User* load_user_from_json(const char* username_target);
bool is_username_available(const char* username_to_check, const char* filename) ;
bool is_password_correct(const char* username, const char* password_input, const char* filename);

#endif /* READ_JSON_H */
