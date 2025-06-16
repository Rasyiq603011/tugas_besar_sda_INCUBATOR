#include "data_struct_test.h"

// ================================================
// =============== PROVINSI SECTION ===============
// ================================================

void test_provinsi() {
    Provinsi* p1;
    create_provinsi(&p1, "Jawa Barat", 10000000, 20);
    assert(p1 != NULL);
    assert(strcmp(get_name_provinsi(p1), "Jawa Barat") == 0);
    assert(get_pendapatan_provinsi(p1) == 10000000);
    assert(get_jumlah_bioskop_provinsi(p1) == 20);

    set_name_provinsi(p1, "Jawa Timur");
    assert(strcmp(get_name_provinsi(p1), "Jawa Timur") == 0);

    set_pendapatan_provinsi(p1, 5000000);
    assert(get_pendapatan_provinsi(p1) == 5000000);

    set_jumlah_bioskop_provinsi(p1, 15);
    assert(get_jumlah_bioskop_provinsi(p1) == 15);

    Provinsi* p2 = constructor_provinsi("Jawa Timur", 5000000, 15);
    assert(compare_provinsi_value(p1, p2));

    destructor_provinsi(p1);
    destructor_provinsi(p2);

    printf("Semua unit test berhasil!\n");
}

// ================================================
// ================= KOTA SECTION =================
// ================================================

void test_constructor_and_accessor_kota() {
    Kota* k = constructor_kota("Bandung", 5000000, 10);
    assert(k != NULL);
    assert(strcmp(get_name_kota(k), "Bandung") == 0);
    assert(get_pendapatan_kota(k) == 5000000);
    assert(get_jumlah_bioskop_kota(k) == 10);
    destructor_kota(k);
}

void test_mutator_kota() {
    Kota* k = constructor_kota("Jakarta", 8000000, 20);
    assert(k != NULL);

    set_name_kota(k, "Surabaya");
    set_pendapatan_kota(k, 9000000);
    set_jumlah_bioskop_kota(k, 15);

    assert(strcmp(get_name_kota(k), "Surabaya") == 0);
    assert(get_pendapatan_kota(k) == 9000000);
    assert(get_jumlah_bioskop_kota(k) == 15);

    destructor_kota(k);
}

void test_compare_kota() {
    Kota* k1 = constructor_kota("Yogyakarta", 2000000, 5);
    Kota* k2 = constructor_kota("Yogyakarta", 2000000, 5);
    Kota* k3 = constructor_kota("Medan", 3000000, 6);

    assert(compare_kota_value(k1, k2) == 1);
    assert(compare_kota_value(k1, k3) == 0);
    assert(compare_kota_value(NULL, k2) == 0);
    assert(compare_kota_value(k1, NULL) == 0);

    destructor_kota(k1);
    destructor_kota(k2);
    destructor_kota(k3);
}

void test_set_name_null_safety_kota() {
    Kota* k = constructor_kota("Palembang", 1000000, 2);
    set_name_kota(k, NULL); 
    assert(strcmp(get_name_kota(k), "Palembang") == 0); 

    destructor_kota(k);
}

void test_kota() {
    printf("Memulai unit test Kota...\n");
    test_constructor_and_accessor_kota();
    test_mutator_kota();
    test_compare_kota();
    test_set_name_null_safety_kota();
    printf("✅ Semua unit test Kota berhasil!\n");
}

// ================================================
// =============== BIOSKOP SECTION ================
// ================================================

void test_constructor_and_accessor_bioskop() {
    Bioskop* b = constructor_bioskop("Cinemax", 10000000, "Jl. Sudirman");

    assert(b != NULL);
    assert(strcmp(get_name_bioskop(b), "Cinemax") == 0);
    assert(strcmp(get_alamat_bioskop(b), "Jl. Sudirman") == 0);
    assert(get_pendapatan_bioskop(b) == 10000000);

    destructor_bioskop(b);
}

void test_mutator_bioskop() {
    Bioskop* b = constructor_bioskop("XXI", 5000000, "Jl. Merdeka");
    assert(b != NULL);

    set_name_bioskop(b, "CGV");
    assert(strcmp(get_name_bioskop(b), "CGV") == 0);

    set_alamat_bioskop(b, "Jl. Gatot Subroto");
    assert(strcmp(get_alamat_bioskop(b), "Jl. Gatot Subroto") == 0);

    set_pendapatan_bioskop(b, 7000000);
    assert(get_pendapatan_bioskop(b) == 7000000);

    destructor_bioskop(b);
}

void test_compare_value_bioskop() {
    Bioskop* a = constructor_bioskop("CGV", 10000000, "Jl. Gatsu");
    Bioskop* b = constructor_bioskop("CGV", 10000000, "Jl. Gatsu");
    Bioskop* c = constructor_bioskop("XXI", 8000000, "Jl. Lain");

    assert(compare_value_bioskop(a, b) == 1); // identical
    assert(compare_value_bioskop(a, c) == 0); // different
    assert(compare_value_bioskop(NULL, NULL) == 1); // both NULL
    assert(compare_value_bioskop(a, NULL) == 0); // one NULL

    destructor_bioskop(a);
    destructor_bioskop(b);
    destructor_bioskop(c);
}

void test_compare_pendapatan_bioskop() {
    Bioskop* a = constructor_bioskop("A", 5000, "A");
    Bioskop* b = constructor_bioskop("B", 10000, "B");

    assert(compare_pendapatan_bioskop(a, b) == -1);
    assert(compare_pendapatan_bioskop(b, a) == 1);
    assert(compare_pendapatan_bioskop(a, a) == 0);

    destructor_bioskop(a);
    destructor_bioskop(b);
}

void test_invalid_constructor_bioskop() {
    assert(constructor_bioskop(NULL, 1000, "Alamat") == NULL);
    assert(constructor_bioskop("Nama", -1, "Alamat") == NULL);
    assert(constructor_bioskop("Nama", 1000, NULL) == NULL);
}

int test_bioskop() {
    test_constructor_and_accessor_bioskop();
    test_mutator_bioskop();
    test_compare_value_bioskop();
    test_compare_pendapatan_bioskop();
    test_invalid_constructor_bioskop();

    printf("✅ Semua unit test bioskop lulus.\n");
    return 0;
}

// ================================================
// =============== STUDIO SECTION ================
// ================================================

void test_constructor_and_accessor_studio() {
    Studio* current_studio = constructor_studio("Studio 1", 5000000, 120);
    assert(current_studio != NULL);
    assert(strcmp(get_name_studio(current_studio), "Studio 1") == 0);
    assert(get_pendapatan_studio(current_studio) == 5000000);
    assert(get_jumlah_kursi_studio(current_studio) == 120);
    destructor_studio(current_studio);
}

void test_mutator_studio() {
    Studio* current_studio;
    create_studio(&current_studio, "Studio X", 1000000, 80);
    set_name_studio(current_studio, "Studio Z");
    set_pendapatan_studio(current_studio, 2000000);
    set_jumlah_kursi_studio(current_studio, 100);

    assert(strcmp(get_name_studio(current_studio), "Studio Z") == 0);
    assert(get_pendapatan_studio(current_studio) == 2000000);
    assert(get_jumlah_kursi_studio(current_studio) == 100);
    destructor_studio(current_studio);
}

// void test_jadwal_filtering_and_checking() {
//     Studio* current_studio = constructor_studio("Studio C", 0, 150);

//     // Buat jadwal
//     Jadwal* j1 = create_jadwal(create_time(10, 0), create_time(12, 0), create_date(2025, 6, 16), NULL, 50000, 100);
//     Jadwal* j2 = create_jadwal(create_time(14, 0), create_time(16, 0), create_date(2025, 6, 17), NULL, 55000, 100);

//     insert_value_last(&(current_studio->jadwal_studio->First), JADWAL_INFO(j1), TYPE_JADWAL);
//     insert_value_last(&(current_studio->jadwal_studio->First), JADWAL_INFO(j2), TYPE_JADWAL);

//     // Filter berdasarkan tanggal
//     List* filtered = get_jadwal_by_date(*(current_studio->jadwal_studio), create_date(2025, 6, 16));
//     assert(filtered != NULL);
//     assert(count_list(*filtered) == 1);
//     assert(compare_date(get_tanggal_tayang(info_jadwal(filtered->First)), create_date(2025, 6, 16)));

//     // Cek konflik waktu (harus true)
//     int conflict = is_exits_jadwal(*(current_studio->jadwal_studio), create_date(2025, 6, 16), create_time(11, 0), create_time(13, 0));
//     assert(conflict == 1);

//     // Cek konflik tidak ada (harus false)
//     conflict = is_exits_jadwal(*(current_studio->jadwal_studio), createDate(2025, 6, 16), create_time(13, 0), create_time(14, 0));
//     assert(conflict == 0);

//     // Clean up
//     clear_list(&(filtered->First));
//     free(filtered);
//     destructor_studio(current_studio);
// }

void test_studio() {
    test_constructor_and_accessor_studio();
    printf("[PASS] Constructor & Accessor\n");

    test_mutator_studio();
    printf("[PASS] Mutator\n");

    // test_jadwal_filtering_and_checking();
    // printf("[PASS] Jadwal Filtering & Conflict Check\n");

    printf("✅ Semua unit test berhasil dijalankan!\n");
}















