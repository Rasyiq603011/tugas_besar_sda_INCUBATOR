#ifndef READ_JSON_H
#define READ_JSON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "../linked.h"
#include "../tree_data.h"

#define FILENAME "../../assets/bioskop_database.json"

// === INTERFACE ===
address load_tree_from_file(const char* filename);
address json_to_tree(cJSON* json, DataType tipe);

#endif /* READ_JSON_H */
