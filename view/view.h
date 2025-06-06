void DisplayOption(int n,int M, char *options[M])
{
	gotoxy(30,13);printf("============================================================");
	for(i=0;i<M+2;i++)
	{
		gotoxy(30,14+i);printf("|                                                          |");
	}
	gotoxy(30,16+M);printf("============================================================");
    for (i = 0; i < M; i++) {
        if (i == n) {
            gotoxy(50,15+i);printf("\033[1;37;46m%-20s\033[0m ", options[i]); // Menyoroti opsi yang dipilih
        } else {
            gotoxy(50,15+i);printf("%s", options[i]);
        }
    }
}