/* File        : date.c */
/* Deskripsi   : Unit untuk keperluan ADT Date */

/***************************/
/*  BODY PRIMITIF DATE     */
/***************************/

#include "date.h"

/*********** Operasi Primitif ************/
/* Constructor Membentuk sebuah DATE, dengan nilai default adalah 01/01/1900 */
void CreateDate (date * D){
	SetTgl (01, &(* D));
	SetBln (01, &(* D));
	SetThn (1900, &(* D));
}

// date getTodayDate(){
// 	date today;
// 	today.Tgl = time_t;
// 	today.Tgl ;
// 	today.Thn;

// 	return today;
// }

/******* Selector komponen **********/
/* Mengambil bagian Tgl dari date */
int GetTgl (date D){
	return(D.Tgl);
}

/* Mengambil bagian Bln dari date */
int GetBln (date D){
	return(D.Bln);
}

/* Mengambil bagian Thn dari date */
int GetThn (date D){
	return(D.Thn);
}


/****** Pengubah komponen ******/
/* Memberi nilai untuk Tgl */
void SetTgl (int NewTgl, date * D){
	(* D).Tgl = NewTgl;
}

/* Memberi nilai untuk Bln */
void SetBln (int NewBln, date * D){
	(* D).Bln = NewBln;
}

/* Memberi nilai untuk Thn */
void SetThn (int NewThn, date * D){
	(* D).Thn = NewThn;
}

int getInt(const char *prompt) {
    char buffer[100];
    int value;
    
    while (1) {
        printf("%s", prompt);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Hapus newline jika ada
            buffer[strcspn(buffer, "\n")] = '\0';
            if (sscanf(buffer, "%d", &value) == 1) {
                return value;
            }
        }
        printf("Input tidak valid. Silakan masukkan angka yang benar.\n");
    }
}

/****** Kelompok Interaksi dengan I/O device, BACA/TULIS ******/
/* Membentuk DATE dari iTgl, iBln dan iThn yang dibaca dari keyboard */
void ReadDate (date * D){
	printf("Masukkan Nilai Date!\n");
	(* D).Tgl = getInt("Tanggal : ");
	(* D).Bln = getInt("Bulan : ");
	(* D).Thn = getInt("Tahun :");
	if (! isValid(* D))
	{
		printf ("Data yang anda masukkan tidak valid ! jadi di reset\n");
		CreateDate (&(* D));
	}
}

/* Memeriksa apakah suatu tanggal valid, yaitu dengan memperhatikan batas akhir per bulan */
boolean isValid(date D){
	if ((GetThn(D) < 1900)||(GetThn(D) > 30000)||(GetBln(D) < 1) ||(GetBln(D) > 12)||(GetTgl(D) < 1)||(GetTgl(D) > getEndDate(D)))
		return (false);
	else
		return (true);
}

/* Print nilai D dengan format dd/mm/yyyy */
void PrintObj (date D){
	printf ("%d/%d/%d\n", GetTgl(D), GetBln(D), GetThn(D));
}

/****** Operator Relasional ******/
/* Memeriksa apakah suatu tanggal adalah kabisat; Dipakai untuk bulan == 2 saja
Harusnya kabisat adalah thn yang habis dibagi 4, atau habis dibagi 100 dan 400, tapi implementasinya seringkali hanya menggunakan 4 sebagai pembagi */
boolean isKabisat (date D){
	return (((GetThn(D) % 4 != 0) || ((GetThn(D) % 100 == 0) && (GetThn(D) % 400 != 0)))? false : true);

}

/***** Predikat lain *******/
/* Memberikan tanggal terakhir dari sebuah bulan */
int getEndDate (date D){
	if ((GetBln(D) == 1) || (GetBln(D) == 3) || (GetBln(D) == 5) || (GetBln(D) == 7)||(GetBln(D) == 8)||(GetBln(D) == 10) || (GetBln(D) == 12))
		return (31);
	else if ((GetBln(D) == 4)||(GetBln(D) == 6)||(GetBln(D) == 9)|| (GetBln(D) == 11))
			return (30);
	else
		return (isKabisat(D) ? 29 : 28);

}

/* Menampilkan tanggal sebelumnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal sebelumnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika jan, thn-1 */
void DateBefore (date D){
	if (GetTgl(D)==1){
		if(GetBln(D)==1){
			printf (" adalah Tanggal %d/%d/%d\n", 31, 12, GetThn(D) - 1);
		}
		else if(GetBln(D) == 3){
			printf(" adalah Tanggal %d/%d/%d\n",(isKabisat(D)? 29 : 28), 2, GetThn(D));
		}
		else{
			printf(" adalah Tanggal %d/%d/%d\n",(((GetBln(D) == 2)|| (GetBln(D) == 4)||(GetBln(D) == 6)||(GetBln(D) == 8)||(GetBln(D) == 9)|| (GetBln(D) == 11))? 31 : 30), GetBln(D) - 1, GetThn(D));
		}
	}
	else{
		printf(" adalah Tanggal %d/%d/%d\n",GetTgl(D) - 1, GetBln(D) , GetThn(D));
	}

}

/* Menampilkan tanggal berikutnya dari sebuah Date
	I.S = Tanggal tertentu diketahui
	F.S = Tanggal berikutnya diketahui
	Hal yang perlu diketahui : Batas akhir tiap bulan dan jika des, thn+1 */
void NextDate (date D){
	if (GetTgl(D) == getEndDate(D)){
		if(GetBln(D)==12){
			printf(" adalah Tanggal %d/%d/%d\n", 1, 1 , GetThn(D) + 1);
		}
		else{
			printf(" adalah Tanggal %d/%d/%d\n", 1, GetBln(D) + 1 , GetThn(D));
		}
	}
	else{
		printf(" adalah Tanggal %d/%d/%d\n",GetTgl(D) + 1, GetBln(D) , GetThn(D));
	}
}

/* Menampilkan selisih dua tanggal
	I.S = 2 buah Tanggal tertentu diketahui
	F.S = Tampil selisih dua buah tanggal
	Asumsi : 1 tahun = 365 hari */
void DifferenceDate (date D1, date D2){
	
	int jml;
	int I;
	int N;

		if (GetThn(D1) != GetThn(D2))
		{
			I = GetBln(D1)+1;
			N = 12;
			jml = getEndDate(D1) - GetTgl(D1);	//menghitung sisa Tanggal Yang ada pada bulan awal
			jml += GetTgl(D2);				//menghitung sisa Tanggal Yang ada pada bulan akhir
			while(I <= N) // Menghitung Tanggal setiap bulan dalam tahun awal
			{
				if ((I == 1) ||(I == 3) || (I == 5) || (I == 7)||(I == 8)||(I == 10) || (I == 12))
				{
					jml += 31;
				}
				else if ((I == 4)||(I == 6)||(I == 9)|| (I == 11))
				{
					jml += 30;
				}
				else
				{
					(((GetThn(D1) % 4 != 0) || ((GetThn(D1) % 100 == 0) && (GetThn(D1) % 400 != 0)))? (jml += 28): (jml += 29));
				}
				I++;
			}
			I = 1;
			N = GetBln(D2);
			while(I < N) // Menghitung Tanggal setiap bulan dalam tahun akhir
			{
				if ((I == 1) ||(I == 3) || (I == 5) || (I == 7)||(I == 8)||(I == 10) || (I == 12))
				{
					jml += 31;
				}
				else if ((I == 4)||(I == 6)||(I == 9)|| (I == 11))
				{
					jml += 30;
				}
				else
				{
					(((GetThn(D1) % 4 != 0) || ((GetThn(D1) % 100 == 0) && (GetThn(D1) % 400 != 0)))? (jml += 28) : (jml += 29));
				}
				I++;
			}
			// Menghitung Jumlah tahun yang berbeda
			I = GetThn(D1);
			N = GetThn(D2)-1;
			while (I < N)
			{
				if ((N % 4 != 0) || ((N % 100 == 0) && (N % 400 != 0)))
				{
					jml += 365;
				}
				else {jml += 366;}
				N--;
				
			}
				
		}
		else if (GetBln(D1) != GetBln(D2))
		{
			I = GetBln(D1)+1;
			N = GetBln(D2);
			jml = getEndDate(D1) - GetTgl(D1);	//menghitung sisa Tanggal Yang ada pada bulan awal
			jml += GetTgl(D2);
			while(I < N)
			{
				if ((I == 1)||(I == 3) || (I == 5) || (I == 7)||(I == 8)||(I == 10) || (I == 12))
				{
					jml += 31;
				}
				else if ((I == 4)||(I == 6)||(I == 9)|| (I == 11))
				{
					jml += 30;
				}
				else
				{
					(((GetThn(D1) % 4 != 0) || ((GetThn(D1) % 100 == 0) && (GetThn(D1) % 400 != 0)))? (jml += 28): (jml += 29));
				}
				I++;
			}
		}
		else
		{
			jml = GetTgl(D2) - GetTgl(D1);	//menghitung sisa Tanggal Yang ada pada bulan awal
		}
	printf("adalah %d hari", jml);
	
}  

