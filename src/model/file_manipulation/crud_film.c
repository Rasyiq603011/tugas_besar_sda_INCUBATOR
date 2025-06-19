#include "crud_film.h"

void create_list_film(List *L) {
    clear_screen();
    printf("=== Tambah Film Baru ===\n");
    
    char judul[MAKS_JUDUL];
    printf("Judul Film: ");
    fgets(judul, MAKS_JUDUL, stdin);
    judul[strcspn(judul, "\n")] = '\0';

    int jumlah_ditonton;
    printf("Jumlah Ditonton: ");
    scanf("%d", &jumlah_ditonton);
    
    int total_pendapatan;
    printf("Total Pendapatan (Rp): ");
    scanf("%d", &total_pendapatan);
    getchar();

    Film *newFilm = create_film(judul, jumlah_ditonton, total_pendapatan);
    if (newFilm == NULL) {
        printf("Gagal membuat film!\n");
        return;
    }

    insert_value_last(&L->First, FILM_INFO(newFilm), TYPE_FILM);
    printf("\nFilm berhasil ditambahkan!\n");
}

void update_film(List *L) {
    clear_screen();
    if (ListEmpty(*L)) {
        printf("Belum ada data film untuk diupdate!\n");
        return;
    }

    printf("=== Update Film ===\n");
    printf("\nMasukkan judul film yang ingin diupdate: ");
    int index;
    scanf("%d", &index);
    getchar();

    pnode current = First(*L);
    int i = 1;
    while (current != NULL && i < index) {
        current = Next(current);
        i++;
    }

    if (current == NULL || i != index) {
        printf("Nomor film tidak valid!\n");
        return;
    }

    Film *film = info_film(current);
    char judul[MAKS_JUDUL];
    printf("Judul Baru: ");
    fgets(judul, MAKS_JUDUL, stdin);
    judul[strcspn(judul, "\n")] = '\0';
    set_judul_film(film, judul);

    int jumlah_ditonton;
    printf("Jumlah Ditonton Baru: ");
    scanf("%d", &jumlah_ditonton);
    set_jumlah_penonton_film(film, jumlah_ditonton);

    int total_pendapatan;
    printf("Total Pendapatan Baru (Rp): ");
    scanf("%d", &total_pendapatan);
    set_total_pendapatan_film(film, total_pendapatan);
    getchar();

    printf("\nData film berhasil diupdate!\n");
}

void deleteFilm(List *L) {
    clear_screen();
    if (ListEmpty(*L)) {
        printf("Belum ada data film untuk dihapus!\n");
        return;
    }

    printf("=== Hapus Film ===\n");
    printf("\nMasukkan nomor film yang ingin dihapus: ");
    int index;
    scanf("%d", &index);
    getchar();

    pnode current = First(*L);
    pnode prev = NULL;
    int i = 1;
    while (current != NULL && i < index) {
        prev = current;
        current = Next(current);
        i++;
    }

    if (current == NULL || i != index) {
        printf("Nomor film tidak valid!\n");
        return;
    }

    InfoList info;
    if (prev == NULL) {
        delete_first(&L->First, &info);
    } else {
        delete_by_value(&L->First, FILM_INFO(info_film(current)), TYPE_FILM);
    }
    printf("\nFilm berhasil dihapus!\n");
}

void save_to_file(List L) {
    FILE *file = fopen(DATABASE_FILM, "wb");
    if (file == NULL) {
        printf("Error membuka file untuk menyimpan!\n");
        return;
    }

    int count = count_list(L);
    fwrite(&count, sizeof(int), 1, file);

    pnode current = First(L);
    while (current != NULL) {
        Film *film = info_film(current);
        char judul[MAKS_JUDUL] = {0};
        strncpy(judul, get_judul_film(film), MAKS_JUDUL - 1);
        int jumlah_ditonton = get_jumlah_penonton_film(film);
        int total_pendapatan = get_jumlah_total_pendapatan_film(film);
        fwrite(judul, sizeof(char), MAKS_JUDUL, file);
        fwrite(&jumlah_ditonton, sizeof(int), 1, file);
        fwrite(&total_pendapatan, sizeof(int), 1, file);
        current = Next(current);
    }

    fclose(file);
}

void load_from_binary(List *L) {
    FILE *file = fopen(DATABASE_FILM, "rb");
    if (file == NULL) {
        return;
    }

    int count;
    fread(&count, sizeof(int), 1, file);

    int i;
    for (i = 0; i < count; i++) {
        char judul[MAKS_JUDUL];
        int jumlah_ditonton;
        int total_pendapatan;
        fread(judul, sizeof(char), MAKS_JUDUL, file);
        fread(&jumlah_ditonton, sizeof(int), 1, file);
        fread(&total_pendapatan, sizeof(int), 1, file);

        Film *newFilm = create_film(judul, jumlah_ditonton, total_pendapatan);
        if (newFilm == NULL) {
            printf("Alokasi memori gagal!\n");
            fclose(file);
            return;
        }
        insert_value_last(&L->First, FILM_INFO(newFilm), TYPE_FILM);
    }

    fclose(file);
}

void clear_screen() {
    system("cls"); 
    // system("clear");
}
