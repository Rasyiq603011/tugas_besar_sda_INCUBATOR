#ifndef TESTING_H
#define TESTING_H
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "model/file_manipulation/crud_film.h"
#include "model/file_manipulation/read_json.h"
#include "model/file_manipulation/write_json.h"

#define TEMP_FILM_FILE "../assets/test_film.dat"
#define TEMP_TREE_FILE "../assets/test_bioskop.dat"

void test_crud_film();

void test_tree_json_roundtrip();

#endif
