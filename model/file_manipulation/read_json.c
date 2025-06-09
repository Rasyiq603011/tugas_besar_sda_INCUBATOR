#include "read_json.h"

void json_to_kursi()
{

}

void json_to_jadwal()
{

}

void json_to_list_kursi(cJSON* json, Kursi*** list_kursi) 
{
    int row, col;
    for (row = 0; row < 3; ++row) 
    {
        cJSON* kursi_row = cJSON_GetArrayItem(json, row);
        for (col = 0; col < 3; ++col) 
        {
            cJSON* kursi_col = cJSON_GetArrayItem(kursi_row, col);
            list_kursi[row][col] = kursi_col->valueint;
        }
    }
}

/*
1. 



*/
