#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int a,b,c,baru, jum,pilih,cari,index;
char user[10],pass[10];
COORD coord={0,0};

void gotoxy(int x,int y){

     HANDLE handle;
     coord.X=x;
     coord.Y=y;
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
     handle  = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleCursorPosition(handle,coord);

}

struct transaksi{

char no[10],meja[10],makan[30],minum[30],harga[30];

};

struct transaksi trs[100];

void membuat(){
    system("cls");
    buat:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|             MEMBUAT DATA TRANSAKSI            |\n");
    gotoxy(32,4);
    printf("|                   RESTORAN OM                 |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
    gotoxy(32,6);
    printf("------------------------------------------------");
    gotoxy(32,7);
    printf("DATA MAKSIMAUM YANG DAPAT DIINPUT     : 5");
    gotoxy(32,10);
    printf("------------------------------------------------");
    gotoxy(32,9);
    printf("BANYAK DATA YANG INGIN ANDA DIINPUT   : ");
    scanf("%d", &b);
    if(b>5){
        system("cls");
        goto buat;
    }else if (b<1){
        system("cls");
        goto buat;
    }
    printf("\n");
    buatt(b);
    for(a=0; a<b; a++){
        printf("\n\t\t\t\tDATA TRANSAKSI KE-%d\n",a+1);
        printf("\t\t\t\t::  No Transaksi   :       ");
        scanf("%s",&trs[a].no);
        printf("\t\t\t\t::  No Meja        :       ");
        scanf("%s",&trs[a].meja);
        printf("\t\t\t\t::  Makanan        :       ");
        scanf("%s",&trs[a].makan);
        printf("\t\t\t\t::  Minuman        :       ");
        scanf("%s",&trs[a].minum);
        printf("\t\t\t\t::  Harga          : Rp.   ");
        scanf("%s",&trs[a].harga);
        printf("\t\t\t\t------------------------------------------------");
    }
    	printf("\n\n\t\t\t\t\tTekan ENTER untuk kembali ke menu");
        getch();
}

void buatt(){
    int x;
    for(x=0;x<jum;x++){
    }
    memset(trs, 0, sizeof trs);
    jum = b;
}

void menampilkan(){

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
    printf("\t\t\t\t _______________________________________________\n");
    printf("\t\t\t\t|                                               |\n");
    printf("\t\t\t\t|           MENAMPILKAN DATA TRANSAKSI          |\n");
    printf("\t\t\t\t|                   RESTORAN OM                 |\n");
    printf("\t\t\t\t|_______________________________________________|\n");
    printf("\t\t====================================================================================\n\n");
    printf("\t\t\t\t         DATA TRANSAKSI YANG TELAH DIINPUT\n");
    printf("\n");
    printf("\t\t====================================================================================\n");
    printf("\t\t  NO TRANSAKSI\t\tNO MEJA\t\tMAKANAN\t\tMINUMAN\t\tHARGA\n");
    printf("\t\t====================================================================================\n\n");

    for(a=0; a<b; a++){

        if (trs[a].no == NULL) continue;
        printf("\t\t\t%s",trs[a].no);
        printf("\t\t%s",trs[a].meja);
        printf("\t\t%s",trs[a].makan);
        printf("\t\t%s",trs[a].minum);
        printf("\t\tRp.%s",trs[a].harga);
        printf("\n\n");
    }
    printf("\n\t\t====================================================================================\n");

	printf("\n\n\t\t\t\t\tTekan ENTER untuk melanjutkan");
	getch();
}

void menambah(){
    system("cls");
    tambah:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|             MENAMBAH DATA TRANSAKSI           |\n");
    gotoxy(32,4);
    printf("|                   RESTORAN OM                 |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
    gotoxy(32,6);
    printf("________________________________________________");
    gotoxy(32,8);
    printf("    DATA MAKSIMUM YANG BISA DIINPUT    :   5 ");
    gotoxy(32,10);
    printf("________________________________________________");
    gotoxy(32,9);
    printf("    DATA YANG INGIN DITAMBAH           :   ");
    scanf("%d", &c);
    if(b>5){
        system("cls");
        goto tambah;
    }else if(b<1){
        system("cls");
        goto tambah;
    }
    for(a=b;a<(b+c);a++){
        printf("\n\n\t\t\t\tDATA TRANSAKSI KE-%d\n",a+1);
        printf("\t\t\t\t::  No Transaksi   :       ");
        scanf("%s",&trs[a].no);
        printf("\t\t\t\t::  No Meja        :       ");
        scanf("%s",&trs[a].meja);
        printf("\t\t\t\t::  Makanan        :       ");
        scanf("%s",&trs[a].makan);
        printf("\t\t\t\t::  Minuman        :       ");
        scanf("%s",&trs[a].minum);
        printf("\t\t\t\t::  Harga          :       ");
        scanf("%s",&trs[a].harga);
        printf("\t\t\t\t_______________________________________________");

    }
    b = b+ c;
        printf("\n\n\t\t\t\t\t      DATA BERHASIL DITAMBAH!");
        printf("\n\n\n\n\n\t\t\t\t\tTekan ENTER untuk kembali ke menu");
	getch();
}

void hapusin(int index){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),14);

    int a;
        for(a=index; a<index+1; a++){
            trs[a] = trs[a+1];
        }
        b--;
}
int checkNo(no){
    int a;
    for(a=0;a<b;a++){
        if(strcmp(trs[a].no, no) == 0){
            return 1;
        }
    }
    return 0;
}
int checkIndexBy(char cari[100],int code){

    for(a=0;a<b;a++){
        switch(code){

            case 1:
            if(strcmp(trs[a].no, cari)==0){
                return a;
            }
            break;

            case 2:
            if(strcmp(trs[a].meja, cari)==0){
                return a;
            }
            break;

            case 3:
            if(strcmp(trs[a].makan, cari)==0){
                return a;
            }
            break;

            case 4:
            if(strcmp(trs[a].minum, cari)==0){
                return a;
            }
            break;

            case 5:
            if(strcmp(trs[a].harga, cari)==0){
                return a;
            }
            break;
            default:
            break;
            }
        }
    return 0;
}
void menghapus(){

    menampilkan();
    system("cls");
    char cariNo[100];
    int indexCari = 0;
    pus:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|            MENGHAPUS DATA TRANSAKSI           |\n");
    gotoxy(32,4);
    printf("|                   RESTORAN OM                 |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
    gotoxy(32,9);
    printf("MASUKKAN NO TRANSAKSI YANG INGIN DIHAPUS    :   ");
    scanf("%s", &cariNo);
    indexCari = checkIndexBy(cariNo, 1);
    gotoxy(32,11);
    printf("NO TRANSAKSI            :   %s",trs[indexCari].no);
    gotoxy(32,12);
    printf("NO MEJA                 :   %s",trs[indexCari].meja);
    gotoxy(32,13);
    printf("MAKANAN                 :   %s",trs[indexCari].makan);
    gotoxy(32,14);
    printf("MINUMAN                 :   %s",trs[indexCari].minum);
    gotoxy(32,15);
    printf("HARGA                   :   %s",trs[indexCari].harga);

    hapusin(indexCari);

}
void mengedit(){
    menampilkan();
    system("cls");
    char cariNo[100], baru[100];
    int indexCari = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
    edit:
    printf("\t\t\t\t _______________________________________________\n");
    printf("\t\t\t\t|                                               |\n");
    printf("\t\t\t\t|             MENGEDIT DATA TRANSAKSI           |\n");
    printf("\t\t\t\t|                   RESTORAN OM                 |\n");
    printf("\t\t\t\t|_______________________________________________|\n\n\n");
    printf("\n");
        gotoxy(32,7);
        printf("Apa yang ingin anda edit?\n");
        gotoxy(32,9);
        printf("1. No Transaksi\n");
        gotoxy(32,10);
        printf("2. No Meja\n");
        gotoxy(32,11);
        printf("3. Makanan\n");
        gotoxy(32,12);
        printf("4. Minuman\n");
        gotoxy(32,13);
        printf("5. Harga\n\n\n");
        gotoxy(32,15);
        printf("----------------------------------------------");
        gotoxy(32,14);
        printf("Pilihan Anda                            :   ");
        scanf("%d", &pilih);
        gotoxy(32,16);
        printf("Masukkan No Transaksi yang akan diubah  :   ");
        scanf("%s", &cariNo);

        printf("\n");
        indexCari = checkIndexBy(cariNo, 1);
        switch(pilih)
        {

        case 1:
            gotoxy(32,18);
            printf("DATA SAAT INI             :   %s",trs[indexCari].no);
            gotoxy(32,20);
            printf("MASUKKAN DATA BARU        : ");
            scanf("%s", &trs[indexCari]. no);
            printf("\n");
            break;

        case 2:
            gotoxy(32,18);
            printf("DATA SAAT INI             :   %s",trs[indexCari].meja);
            gotoxy(32,20);
            printf("MASUKKAN DATA BARU        : ");
            scanf("%s", &trs[indexCari]. meja);
            printf("\n");
            break;

        case 3:
            gotoxy(32,18);
            printf("DATA SAAT INI             :   %s",trs[indexCari].makan);
            gotoxy(32,20);
            printf("MASUKKAN DATA BARU        : ");
            scanf("%s", &trs[indexCari]. makan);
            printf("\n");
            break;

        case 4:
            gotoxy(32,18);
            printf("DATA SAAT INI             :   %s",trs[indexCari].minum);
            gotoxy(32,20);
            printf("MASUKKAN DATA BARU        : ");
            scanf("%s", &trs[indexCari]. minum);
            printf("\n");
            break;

        case 5:
            gotoxy(32,18);
            printf("DATA SAAT INI             :   %s",trs[indexCari].harga);
            gotoxy(32,20);
            printf("MASUKKAN DATA BARU        : ");
            scanf("%s", &trs[indexCari]. harga);
            printf("\n");
            break;

        default:
            system("cls");
            goto edit;
        }
    printf("\n\n\t\t\t\t\tTekan ENTER untuk kembali ke menu");
	getch();

}

void lihatCari(int index){

    system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        gotoxy(24,1);
        printf("_______________________________________________________________________________");
        gotoxy(58,2);
        printf("HASIL PENCARIAN DATA\n");
        gotoxy(24,3);
        printf("_______________________________________________________________________________");
        gotoxy(24,4);
        printf("NO          MEJA            MAKAN           MINUM             HARGA            ");
        gotoxy(24,5);
        printf("_______________________________________________________________________________\n");

        printf("\t\t\t%s\t",trs[index].no);
        printf("\t%s\t",trs[index].meja);
        printf("\t%s\t",trs[index].makan);
        printf("\t%s",trs[index].minum);
        printf("\t\t%s",trs[index].harga);
        printf("\n\t\t\t_______________________________________________________________________________");


}

void mencari(){

    system("cls");
    awal:
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|              MENCARI DATA TRANSAKSI           |\n");
    gotoxy(32,4);
    printf("|                   RESTORAN OM                 |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
    gotoxy(42,7);
    printf("Data apa yang ingin anda cari ? \n");
    gotoxy(32,9);
    printf("1. NO TRANSAKSI\n");
    gotoxy(32,10);
    printf("2. NO MEJA\n");
    gotoxy(32,11);
    printf("3. MAKANAN\n");
    gotoxy(32,12);
    printf("4. MINUMAN\n");
    gotoxy(32,13);
    printf("5. HARGA\n");
    gotoxy(32,14);
    printf("_______________________________________________\n");
    gotoxy(32,15);
    printf("Pilihan Anda : ");
    scanf("%d", &pilih);

    char textCari[100];
    int indexDicari = 0;

    switch(pilih){

    case 1 :
    printf("\n");
    printf("\n");
    gotoxy(42,16);

    printf("No Transaksi yang dicari : ");
    scanf("%s", &textCari);
    indexDicari = checkIndexBy(textCari, 1);
    lihatCari(indexDicari);
    printf("\n");

    break;

    case 2 :
    printf("\n");
    printf("\n");
    gotoxy(42,16);
    printf("No Meja yang dicari : ");
    scanf("%s", &textCari);
    indexDicari = checkIndexBy(textCari, 1);
    lihatCari(indexDicari);
    printf("\n");
    break;

    case 3 :
    printf("\n");
    printf("\n");
    gotoxy(42,16);
    printf("Makanan yang dicari : ");
    scanf("%s", &textCari);
    indexDicari = checkIndexBy(textCari, 1);
    lihatCari(indexDicari);
    printf("\n");
    break;

    case 4 :
    printf("\n");
    printf("\n");
    gotoxy(42,16);
    printf("Minuman yang dicari : ");
    scanf("%s", &textCari);
    indexDicari = checkIndexBy(textCari, 1);
    lihatCari(indexDicari);
    printf("\n");
    break;

    case 5 :
    printf("\n");
    printf("\n");
    gotoxy(42,16);
    printf("Harga yang dicari : ");
    scanf("%s", &textCari);
    indexDicari = checkIndexBy(textCari, 1);
    lihatCari(indexDicari);
    printf("\n");
    break;

    default:
        system("cls");
        goto awal;
    }
    gotoxy(8,25);
	printf("\t\t\t\t\tTekan ENTER untuk kembali ke menu");
	getch();
}



void riwayat(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|             RIWAYAT DATA TRANSAKSI            |\n");
    gotoxy(32,4);
    printf("|                  RESTORAN OM                  |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
}


int struct_compare_no(const void *a, const void *b)
{
    struct transaksi *ia = (struct transaksi *)a;
    struct transaksi *ib = (struct transaksi *)b;
}
int struct_compare_meja(const void *a, const void *b)
{
    struct transaksi *ia = (struct transaksi *)a;
    struct transaksi *ib = (struct transaksi *)b;
}
int struct_compare_makan(const void *a, const void *b)
{
    struct transaksi *ia = (struct transaksi *)a;
    struct transaksi *ib = (struct transaksi *)b;
}
int struct_compare_minum(const void *a, const void *b)
{
    struct transaksi *ia = (struct transaksi *)a;
    struct transaksi *ib = (struct transaksi *)b;
}
int struct_compare_harga(const void *a, const void *b)
{
    struct transaksi *ia = (struct transaksi *)a;
    struct transaksi *ib = (struct transaksi *)b;
}



void mengurutkan(){
    urut:
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|           MENGURUTKAN DATA TRANSAKSI          |\n");
    gotoxy(32,4);
    printf("|                  RESTORAN OM                  |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|\n");
    gotoxy(42,7);
    printf("Urutkan Berdasarkan Apa ? \n");
    gotoxy(42,9);
    printf("1. NO TRANSAKSI\n");
    gotoxy(42,10);
    printf("2. NO MEJA\n");
    gotoxy(42,11);
    printf("3. MAKANAN\n");
    gotoxy(42,12);
    printf("4. MINUMAN\n");
    gotoxy(42,13);
    printf("5. HARGA");
    gotoxy(32,14);
    printf("_______________________________________________\n");
    gotoxy(32,15);
    printf("Pilih : ");
    scanf("%d", &pilih);
    if(pilih>5){
        system("cls");
        goto urut;
    }

    struct transaksi tempTrs[100];
    memmove(tempTrs, trs, sizeof(trs));

    switch(pilih){
    case 1 :
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_no);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_meja);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_makan);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_minum);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_harga);
        break;
    case 2 :
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_no);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_meja);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_makan);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_minum);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_harga);
        break;
    case 3 :
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_no);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_meja);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_makan);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_minum);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_harga);
        break;
    case 4 :
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_no);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_meja);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_makan);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_minum);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_harga);
        break;
    case 5 :
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_no);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_meja);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_makan);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_minum);
        qsort(tempTrs, b, sizeof(struct transaksi), struct_compare_harga);
        break;
    }
    system("cls");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
    printf("\t\t====================================================================================\n\n");
    printf("\t\t\t\t         DATA TRANSAKSI YANG TELAH DIINPUT\n");
    printf("\n");
    printf("\t\t====================================================================================\n");
    printf("\t\t  NO TRANSAKSI\t\tNO MEJA\t\tMAKANAN\t\tMINUMAN\t\tHARGA\n");
    printf("\t\t====================================================================================\n\n");

        for(a=0;a<b;a++){
        printf("\n\n\t\t\t\t%s\t",tempTrs[a].no);
        printf("\t%s\t",tempTrs[a].meja);
        printf("\t%s\t",tempTrs[a].makan);
        printf("\t%s",tempTrs[a].minum);
        printf("\t\t%s",tempTrs[a].harga);
        }
        printf("\n\t\t====================================================================================\n\n");

        gotoxy(8,25);
        printf("\t\t\t\tTekan ENTER untuk kembali ke menu");
            getch();
}

void keluar(){
    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);

    const char aw[] =
"\
                                                       /^\\\n\
                                                      / _ \\\n\
                                                      |   |\n\
                                                      | S |\n\
                                                      | E |\n\
                                              ________| L |________\n\
                                             /        | E |        \\\n\
           _                                /_________| S |_________\\\n\
          /^\\                                         | A |\n\
          | |                                         | I |\n\
     _____|F|_____                                    |   |\n\
    /_____|T|_____\\                                   | L |\n\
          |I|                                       __| U |__\n\
          | |                                      /    R     \\\n\
         /___\\                                    /____________\\\n\
                                                                                                   _\n\
                                                        T                                         /^\\\n\
                                                        E                                         | |\n\
                                                        R                                         |U|\n\
                                                        I                                    _____|K|_____\n\
                                                        M                                   /_____|S|_____\\\n\
                                                        A                                         |W|\n\
                                                                                                  | |\n\
                                                        K                                        /___\\\n\
                                                        A\n\
                                                        S\n\
                                                        I\n\
                                                        H\n\
                                                        ";
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    for (int i = 0; i < 10; i ++) printf("\n");
    printf("%s", aw);
    int j = 300000;
    for (int i = 0; i < 100; i ++) {
        usleep(j);
        j = (int)(j * 0.99);
        printf("\n");
    }
    system("taskkill/IM cb_console_runner.exe");
    }

void waktu() {
    struct wk *Sys_T;

    time_t Tval;
    Tval = time(NULL);
    Sys_T = localtime(&Tval);
    gotoxy(43,9);
    printf ( " %s", asctime (Sys_T));
}

void login(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
    int pilih, y, x, z;

    login:
    gotoxy(32,1);
    printf(" _______________________________________________\n");
    gotoxy(32,2);
    printf("|                                               |\n");
    gotoxy(32,3);
    printf("|         SELAMAT DATANG DI DATA TRANSAKSI      |\n");
    gotoxy(32,4);
    printf("|                   RESTORAN OM                 |\n");
    gotoxy(32,5);
    printf("|_______________________________________________|");
    gotoxy(32,10);
    printf(" _______________________________________________");
    gotoxy(32,11);
    printf("|                                               |");
    gotoxy(32,15);
    printf("|_______________________________________________|");
    waktu();
    gotoxy(32,13);
    printf("|                                               |");
    gotoxy(32,12);
    printf("|     Masukkan Username (admin)  :              |");
    gotoxy(32,14);
    printf("|     Masukkan Password ( 123 )  :              |");
    gotoxy(67,12);
    scanf("%s",&user);
    gotoxy(67,14);
    char a[10],c;
    int i;

    fflush(stdin);
    for ( i = 0 ; i<100 ; i++ )
    {
        fflush(stdin);
        c = getch();
        a[i] = c;

        if ( a[i] == '\b')
        {
            printf("\b \b");
            i-= 2;
            continue;
        }
        if ( a[i] == ' ' || a[i] == '\r' )
            printf(" ");
        else
            printf("*");
        if ( a[i]=='\r')
            break;
    }
    a[i]='\0';
    printf("" , a);

    if(strcmp(user,"admin")==0 && strcmp(a,"123")==0){
        gotoxy(43,22);
        printf("----------------------------");
        gotoxy(43,23);
        printf("+   AKSES ADMIN DITERIMA   +");
        gotoxy(43,24);
        printf("----------------------------");
        gotoxy(57,25);
        printf(" ");
        getch();
        system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
    gotoxy(40,13);
    int  y;
    char ad[]="L     O     A     D     I     N     G  .  .  .";
         for(y=0; ad[y]!=NULL; y++){
             printf("%c",ad[y]);
             Sleep(30);
            }
        system("cls");
    gotoxy(40,13);
    char da[]="L     O     A     D     I     N     G  .  .  .";
         for(y=0; da[y]!=NULL; y++){
             printf("%c",da[y]);
             Sleep(30);
            }
        system("cls");
    gotoxy(40,13);
    char aad[]="L     O     A     D     I     N     G  .  .  .";
         for(y=0; aad[y]!=NULL; y++){
             printf("%c",aad[y]);
             Sleep(30);
            }
    gotoxy(44,28);
    printf("Tekan ENTER untuk melanjutkan...");
    getch();
    }
    else{
        gotoxy(30,23);
        printf("------------------------------------------------------");
        gotoxy(30,24);
        printf("+                 AKSES ADMIN DITOLAK!               +");
        gotoxy(30,25);
        printf("+  Username atau Passowrd yang anda masukkan salah!  +");
        gotoxy(30,26);
        printf("------------------------------------------------------");
        gotoxy(55,27);
        printf("");
        getch();

        system("cls");
        goto login;
    }
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    gotoxy(25,13);
    char aad[]="W     E     L     C     O     M     E";
         for(y=0; aad[y]!=NULL; y++){
             printf("%c",aad[y]);
             Sleep(50);
            }

}

int main(){

    login();
    int f,del;
    menu:
    system("cls");
    gotoxy(33,1);
    printf("_______________________________________________");
    gotoxy(33,5);
    printf("_______________________________________________");
    gotoxy(35,3);
    char aad[]=" SELAMAT DATANG DI DATA TRANSAKSI RESTORAN\n\t\t\t\t\t   xxx RESTORAN MAMA MUDA xxx";
         for(f=0; aad[f]!=NULL; f++){
             printf("%c",aad[f]);
             Sleep(30);
            }
    gotoxy(38,6);
    printf("\n\t\t\t\t _______________________________________________\n");
    printf("\t\t\t\t|                                               |\n");
    printf("\t\t\t\t|   1. Membuat Data Transaksi                   |\n");
    printf("\t\t\t\t|   2. Menampilkan Isi Data Transaksi           |\n");
    printf("\t\t\t\t|   3. Menambah Baru Data Transaksi             |\n");
    printf("\t\t\t\t|   4. Menghapus Data Transaksi                 |\n");
    printf("\t\t\t\t|   5. Mengedit Data Transaksi                  |\n");
    printf("\t\t\t\t|   6. Mencari Data Transaksi                   |\n");
    printf("\t\t\t\t|   7. Riwayat Aktivitas Transaksi              |\n");
    printf("\t\t\t\t|   8. Mengurutkan Data Transaksi               |\n");
    printf("\t\t\t\t|   9. Keluar Dari Program                      |\n");
    printf("\t\t\t\t|_______________________________________________|\n\n");
    printf("\t\t\t\tMasukkan Pilihan    [1-9]:       ");
    scanf("%d", &pilih);

    switch(pilih){

    case 1:
        membuat();
        system("cls");
        goto menu;
    break;

    case 2:
        menampilkan();
        system("cls");
        goto menu;
    break;

    case 3:
        menambah();
        system("cls");
        goto menu;
    break;

    case 4:
        menghapus();
            gotoxy(31,19);
            printf("Apakah anda yakin ingin menghapus?[YA/TIDAK]     :   ");
            scanf("%s", &del);
                if(del=='y'|del=='YA'|del=='ya'|del=='Ya'|del=='yA'|del=='Y'){
                gotoxy(43,22);
                printf("----------------------------");
                gotoxy(43,23);
                printf("   DATA BERHASIL DIHAPUS!  ");
                gotoxy(43,24);
                printf("----------------------------");
                }else{
                    system("cls");
                    goto menu;
                }
            gotoxy(41,28);
            printf("Tekan ENTER untuk kembali ke menu");
            getch();
        system("cls");
        goto menu;
    break;

    case 5:
        mengedit();
        system("cls");
        goto menu;
    break;

    case 6:
        mencari();
        system("cls");
        goto menu;
    break;
        keluar();
    case 7:
        riwayat();
        system("cls");
        goto menu;
    break;

    case 8:
        mengurutkan();
        system("cls");
        goto menu;
    break;

    case 9:
        keluar();
        printf("\n");
        system("cls");
        exit(0);
    break;
    default:
        gotoxy(43,24);
        printf("----------------------------");
        gotoxy(43,25);
        printf("+    PILIHAN TIDAK ADA!    +");
        gotoxy(43,26);
        printf("----------------------------");
        getch();
        system("cls");

        goto menu;
    }
}
