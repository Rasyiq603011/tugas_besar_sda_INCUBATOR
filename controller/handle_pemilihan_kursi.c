#include "handle_pemilihan_kursi.h"

void prmilihan_kursi()
{
    int key, option;

    while (1)
	{
        display_kursi();
        key = getch();
        if (key == 0 || key == 224) {
	        key = getch();
            option = option + kelola_operasi(key);
	    } else if (key == 13) {  // Enter
				Beep(600,100);
	            break;
	    }
	}
}

int kelola_operasi(int key)
{
    switch (key)
    {
    case 72: // UP ARROW
        return -1;
    case 77: // RIGHT ARROW
        return 10;
    case 80: // DOWN ARROW
        return 1;
    case 75: // LEFT ARROW
        return -10;
    default:
        break;
    }
}