#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct
{
    char makanan[30];
    char minuman[30];

}tambah,cek,hapus,sort[100];



 int login()
 {
     char user[10], pass[10];
     time_t now = time(0);
     char *dt = ctime(&now);
     printf("%s", dt);

     printf("\n");

     printf("Masukan Username : ");
     scanf("%s", user);
     printf("\nMasukan Password : ");
     fflush(stdin);
     char ch;
     int i=0;
     while ((ch=(char)_getch())!='\r')
     {
         pass[i]=ch;
         printf("*");

         i++;
     }
     printf("\n");


     if (strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0)
     {
         printf("Akses diterima Selamat Datang\n");
          system("cls");
         return 1;
     }
     else
     {

         printf("\nUsername/password salah!\n");
         printf("\nTap apapun untuk mencoba login ulang ");

         return 0;
     }
 }

void menu()
{
    system("cls");
    char makanan[255],minuman[255];
    int i=0;
    FILE *fp;
    fp=fopen("menuresto.txt","w");
    int jumlah;
    printf("mau input berapa jenis makanan : ");
    scanf("%d", &jumlah);
    for (i = 0; i <jumlah; i++)
    {
        printf("Makanan ke %d: ",i+1); fflush(stdin); gets(makanan);
        fprintf(fp, "%s\n",makanan);
    }

    fclose(fp);
    printf("Data makananan berhasil di simpan\n");

    printf("\n");

    fp=fopen("menuresto.txt","a");
    printf("mau input berapa jenis minuman : ");
    scanf("%d", &jumlah);
    for (i = 0; i <jumlah; i++)
    {
        printf("Minuman ke %d: ",i+1); fflush(stdin); gets(minuman);
        fprintf(fp, "%s\n",minuman);
    }

    fclose(fp);
    printf("Data makananan berhasil di simpan\n");
    getchar();
    system("cls");

}
void lihat()
{
    system("cls");
    char data[50];
    int i=1;
    FILE *fp;

    fp=fopen("menuresto.txt", "r");

    while(fgets(data,50,fp)!=NULL) //membaca dan mengulang sampai data habis
    {
        printf("menu-%d : %s", i, data);
        i++;
    }
    fclose(fp);
    system("pause");
    system("cls");

}
//void tambahdata()
//{
//
//}
//void edit()
//{
//
//}
//void hapus()
//{
//
//}
void keluar()
{
    system("cls");
    printf("+----------------+\n");
    printf(" TR Asdos ASD\n");
    printf("+----------------+\n");
    printf("Ricardho Gunawan\n");
    printf("Carens Gabriel\n");
    printf("Stevie Angela Andrianto");
    exit(0);
}
void main()
{
    int pilihan = 0;
    char ulang;
    while (login() == 0)
    {
        scanf("%c", &ulang);
        getchar();
    }

    do
    {
//        system("cls");
        printf("+---------------------------------+\n");
        printf("selamat datang di database restoran\n");
        printf("+---------------------------------+\n");
        printf("1. untuk Input menu makanan dan Minuman\n");
        printf("2. untuk melihat Menu\n");
        printf("3. untuk menambah data Baru\n");
        printf("4. untuk mengupdate menu\n");
        printf("5. untuk menghapus isi inputan\n");
        printf("6. untuk mencari isi inputan\n");
        printf("7. keluar\n");
        printf("+---------------------------------+\n");
        printf("silakan masukan pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            menu();
            break;
        case 2:
            lihat();
            break;
//        case 3:
//            tambahdata();
//         case 4:
//             edit();
//             break;
        // case 5:
        //     hapus();
        //     break;
        // case 6:
        //     mencari_data();
        //     break;
        case 7:
            keluar();
        default:
            printf("Silakan masukan pilihanmu: ");
            break;
        }
    } while (pilihan != 7);
}

