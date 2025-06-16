#include "testing.h" 

void test_crud_film() {
    List filmList;
    CreateList(&filmList);

	printf("pass 1\n");

    // Tambah Film
    Film* f1 = create_film("Naruto: The Last", 1200, 3000000);
    Film* f2 = create_film("Avengers: Endgame", 3000, 9000000);
    insert_value_last(&filmList.First, FILM_INFO(f1), TYPE_FILM);
    insert_value_last(&filmList.First, FILM_INFO(f2), TYPE_FILM);

	printf("%d", filmList.First->type);

    assert(count_list(filmList) == 2);
	printf("pass 2\n");
    // Simpan dan load kembali
    FILE* f = fopen(TEMP_FILM_FILE, "wb"); fclose(f); // Buat file dummy
    save_to_file(filmList);
    List loaded;
    CreateList(&loaded);
    load_from_binary(&loaded);

    assert(count_list(loaded) == 2);
	printf("pass 3\n");
    // Update Film
    printf(get_judul_film(loaded.First->info.film));
//    strcpy(get_judul_film(info_film(First(loaded))), "Naruto: Boruto Next Generation");
    printf(get_judul_film(loaded.First->info.film));
//    assert(strcmp(get_judul_film(info_film(First(loaded))), "Naruto: Boruto Next Generation") == 0);
	printf("pass 4\n");
	
    // Delete Film
    delete_first(&loaded.First, NULL);
    assert(count_list(loaded) == 1);
	printf("pass 5\n");
    // Clean up
    clear_list(&filmList.First);
    clear_list(&loaded.First);
    remove(TEMP_FILM_FILE);
    printf("\nCRUD FILM TEST PASSED\n");
}

void test_tree_json_roundtrip() {
    // Simulasi buat data tree manual
    Negara* idn = constructor_negara("Indonesia", 10000000, 10);
    address root = create_node(NEGARA_INFO(idn), TYPE_NEGARA);
	printf("pass 1\n");
    Provinsi* jabar = constructor("Jawa Barat", 2000000, 2);
    add_child(root, PROVINSI_INFO(jabar), TYPE_PROVINSI);
	printf("pass 2\n");
    Kota* bdg = constructor_kota("Bandung", 1500000, 1);
    add_child(root->first_son, KOTA_INFO(bdg), TYPE_KOTA);
	printf("pass 3\n");
    Bioskop* cgv = constructor_bioskop("CGV Paris Van Java", 100000, "Jl. Sukajadi 123");
    add_child(root->first_son->first_son, BIOSKOP_INFO(cgv), TYPE_BIOSKOP);
	printf("pass 4\n");
    Studio* studio1 = constructor_studio("Studio 1", 50000, 100);
    printf("pass 4.1 construksi berhasil\n");
    add_child(root->first_son->first_son->first_son, STUDIO_INFO(studio1), TYPE_STUDIO);
	printf("pass 5\n");
    // Save to JSON file
    save_tree_to_file(root, "output.json");
	
	printf("pass save data \n");
    // Load from JSON
    address loaded_root = load_tree_from_file("output.json");
	printf("pass 6\n");
    // Cek data consistency (hanya cek root dan satu child saja untuk proof)
    printf("ini load %s\n\n", get_name_negara(info_negara(loaded_root)));
    printf("ini load %s\n\n", get_name_negara(info_negara(root)));
   assert(strcmp(get_name_negara(info_negara(root)), get_name_negara(info_negara(loaded_root))) == 0);
   assert(strcmp(get_name_provinsi(info_provinsi(root->first_son)), get_name_provinsi(info_provinsi(loaded_root->first_son))) == 0);

    // Clean up
    remove(TEMP_TREE_FILE);
    printf("CRUD TREE JSON TEST PASSED\n");
}

