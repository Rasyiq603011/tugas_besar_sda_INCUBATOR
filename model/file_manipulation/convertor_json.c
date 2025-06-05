#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cJSON.h"
#include "../data_struct.h"

typedef struct
{
    int info;
}infotype;



cJSON *kursi_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *jadwal_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *film_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *bioskop_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *kota_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *provinsi_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *negara_to_json(infotype k)
{
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddNumberToObject(obj, "komponen 1", k.info);
    cJSON_AddNumberToObject(obj, "komponen 2", k.info);
    cJSON_AddStringToObject(obj, "komponen 3", k.info);
    return obj;
}

cJSON *create_array_json_from_list()
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

/*
1. 



*/
