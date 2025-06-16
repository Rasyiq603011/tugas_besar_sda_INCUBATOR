#include "test/testing.h"

int main(int argc, char *argv[])
{
    printf("========== UNIT TEST BIOSKOP PROGRAM ==========\n");
    test_crud_film();
    test_tree_json_roundtrip();
    printf("===============================================\n");
    return 0;
}


