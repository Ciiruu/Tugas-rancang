#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>

typedef struct
{
    char makanan[30];
    char minuman[30];
    int harga;

}resto;

resto menu;


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

void makanan()
{
    char resto[255];
    int i=0;
    FILE *fp;
    fp=fopen("menuresto.txt","w");
    int jumlah;
    printf("mau input berapa data makanan: ");
    scanf("%d", &jumlah);
    for (i = 0; i <jumlah; i++)
    {
        printf("Makanan ke %d: ",i+1); fflush(stdin); gets(resto);
        fprintf(fp, "%s\n",resto);
    }
    printf("\n");
    fclose(fp);
    printf("Data makananan berhasil di simpan\n\n");
}
//void minuman()
//{
//    system("cls");
//    int jumlah,i;
//    printf("mau input berapa data minum: ");
//    scanf("%d", &jumlah);
//    for (i = 0; i <jumlah; i++)
//    {
//        printf("Minuman kes %d: ",i+1);
//        scanf("%s",menu.minuman);
//        gets(menu.minuman);
//    }
//    printf("\n");
//    printf("Data minuman berhasil di simpan\n\n");
//}
//void lihat()
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
        printf("+---------------------------------+\n");
        printf("selamat datang di database restoran\n");
        printf("+---------------------------------+\n");
        printf("1. untuk Input menu makanan\n");
        printf("2. untuk Input menu minuman\n");
        printf("3. untuk melihat isi inputan\n");
        printf("4. untuk mengupdate isi inputan\n");
        printf("5. untuk menghapus isi inputan\n");
        printf("6. untuk mencari isi inputan\n");
        printf("7. keluar\n");
        printf("+---------------------------------+\n");
        printf("silakan masukan pilihan: ");
        scanf("%d", &pilihan);
        switch (pilihan)
        {
        case 1:
            makanan();
            break;
//         case 2:
//             minuman();
//             break;
//        case 3:
//            lihat();
//            break;
        // case 4:
        //     edit();
        //     break;
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
