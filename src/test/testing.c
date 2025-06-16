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

void test_tree_json_roundtrip() 
{
    // Negara
    Negara* idn = constructor_negara("Indonesia", 10000000, 10);
    address root = create_node(NEGARA_INFO(idn), TYPE_NEGARA);
	printf("Validasi nama sebelum create_node: %s\n", get_name_negara(idn));

    // Provinsi
    Provinsi* jabar = constructor_provinsi("Jawa Barat", 2000000, 2);
	add_child(root, PROVINSI_INFO(jabar), TYPE_PROVINSI);
	address prov_node = get_last_son(root);

    // Kota
    Kota* bdg = constructor_kota("Bandung", 1500000, 1);
    add_child(prov_node, KOTA_INFO(bdg), TYPE_KOTA);
    address kota_node = get_last_son(prov_node);

    // Bioskop
    Bioskop* cgv = constructor_bioskop("CGV Paris Van Java", 100000, "Jl. Sukajadi 123");
    add_child(kota_node, BIOSKOP_INFO(cgv), TYPE_BIOSKOP);
    address bioskop_node = get_last_son(kota_node);

    // Studio
    Studio* studio1 = constructor_studio("Studio 1", 50000, 100);
    add_child(bioskop_node, STUDIO_INFO(studio1), TYPE_STUDIO);
    address studio_node = get_last_son(bioskop_node);

    save_tree_to_file(root, "output.json");
    printf(">> Data berhasil disimpan ke output.json\n");

    address loaded_root = load_tree_from_file("output.json");
    printf(">> Data berhasil dimuat kembali dari output.json\n");
    
	printf("Original: [%s]\n", get_name_negara(info_negara(root)));
	printf("Loaded  : [%s]\n", get_name_negara(info_negara(loaded_root)));

    assert(strcmp(get_name_negara(info_negara(root)), get_name_negara(info_negara(loaded_root))) == 0);
    assert(strcmp(get_name_provinsi(info_provinsi(root->first_son)), get_name_provinsi(info_provinsi(loaded_root->first_son))) == 0);
    assert(strcmp(get_name_kota(info_kota(root->first_son->first_son)), get_name_kota(info_kota(loaded_root->first_son->first_son))) == 0);
    assert(strcmp(get_name_bioskop(info_bioskop(root->first_son->first_son->first_son)), get_name_bioskop(info_bioskop(loaded_root->first_son->first_son->first_son))) == 0);
    assert(strcmp(get_name_studio(info_studio(root->first_son->first_son->first_son->first_son)), get_name_studio(info_studio(loaded_root->first_son->first_son->first_son->first_son))) == 0);

    printf(">> Validasi data berhasil.\n");

    remove("output.json");
    printf(">> File sementara dihapus.\n");

    printf("? CRUD TREE JSON TEST PASSED ?\n");
}


