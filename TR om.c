#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct menu
{
    char makanan[30];
    char minuman[30];
    int harga;

} resto;

// int login()
// {
//     char user[10], pass[10];

//     time_t now = time(0);
//     char *dt = ctime(&now);
//     printf("%s", dt);

//     printf("\n");

//     printf("Masukan Username : ");
//     scanf("%s", user);
//     printf("\nMasukan Password : ");
//     scanf("%s", pass);

//     if (strcmp(user, "admin") == 0 && strcmp(pass, "123") == 0)
//     {
//         printf("Akses diterima Selamat Datang\n");
//         // system("clear");
//         return 1;
//     }
//     else
//     {

//         printf("\nUsername/password salah!\n");
//         printf("\nTap apapun untuk mencoba login ulang ");

//         return 0;
//     }
// }

void makanan()
{
    int jumlah;
    printf("mau input berapa data makanan: ");
    scanf("%d", &jumlah);
    for (int i = 0; i < jumlah; i++)
    {
        printf("menu makanan: ");
        scanf("%s", &resto.makanan);
        gets(resto.makanan);
    }
    printf("berhasil di simpan\n");
}
void minuman()
{
    int jumlah;
    printf("mau input berapa data minuman: ");
    scanf("%d", &jumlah);
    for (int i = 0; i < jumlah; i++)
    {
        printf("menu makanan: ");
        scanf("%s", &resto.minuman);
        gets(resto.minuman);
    }
    printf("berhasil di simpan\n");
}

void lihat()
{
    printf("%s",resto.makanan);
    printf("%s",resto.minuman);
}
// void hapus()
// {

// }

int main()
{
    int pilihan = 0;

    // char ulang;

    // while (login() == 0)
    // {
    //     scanf("%c", &ulang);
    //     getchar();
    // }

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
        case 2:
            minuman();
            break;
        case 3:
            lihat();
            break;
        // case 4:
        //     edit();
        //     break;
        // case 5:
        //     hapus();
        //     break;
        // case 6:
        //     mencari_data();
        //     break;
        default:
            printf("Silakan masukan pilihanmu: ");
            break;
        }
    } while (pilihan != 7);
}
