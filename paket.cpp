#include <iostream>
#include <conio.h>
#include <windows.h>
#define MAX 10

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};
struct paket kirim[MAX];
int top = 1;

bool isEmpty()
{
    return top == -1;
}

bool isFull()
{
    return top == MAX - 1;
}

/*******************************************/
void bersihlayar()
{
    for (int a = 0; a < 80; a++)
    {
        for (int b = 0; b <= 24; b++)
        {
            gotoxy(a, b);
            cout << " ";
        }
    }
}

void tambahdata()
{
    if (top < MAX)
    {
        gotoxy(20, 15);
        cout << "Inputkan Jenis Barang    :";
        cin >> kirim[top].jenis_brg;
        gotoxy(20, 16);
        cout << "Inputkan Berat           :";
        cin >> kirim[top].berat;
        gotoxy(20, 17);
        cout << "Inputkan Kota Tujuan     :";
        cin >> kirim[top].kota;
        top++;
    }
    else
    {
        cout << "Sorry Stack is FULL!!!" << endl;
        cout << "Press Any Key ...";
        getch();
        cout << endl;
    }
}

void tampildata()
{
    gotoxy(40, 10);
    cout << "Daftar Kiriman Paket" << endl;
    for (int a = 1; a < top; a++)
    {
        gotoxy(40, 19 - a);
        cout << a << " ";
        cout << kirim[a].jenis_brg << " ";
        cout << kirim[a].berat << " ";
        cout << kirim[a].kota << endl;
    }
    gotoxy(40, 20);
    cout << "Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata()
{
    if (top > 1)
    {
        gotoxy(40, 12);
        cout << "Data Terakhir yang anda Hapus Adalah :" << endl;
        gotoxy(40, 13);
        cout << kirim[top - 1].jenis_brg << " ";
        cout << kirim[top - 1].berat << " Kg ";
        cout << kirim[top - 1].kota << endl
             << endl;

        gotoxy(40, 15);
        cout << "Press Any Key...";
        getch();
        top--;
    }
    else
    {
        cout << "Sorry Stack is Empty!!!" << endl;
        cout << "Press Any Key ...";
        getch();
        cout << endl;
    }
}
void jumlahdata()
{
    int jumlah = 0;
    for (int i = 1; i < top; i++)
    {
        jumlah++;
    }
    cout << "Jumlah Data - " << jumlah << endl;
    cout << "Press Any Key...";
    getch();
}

int main()
{
    int pilih;
    int datake = 1;
    do
    {
        bersihlayar();
        gotoxy(1, 1);
        cout << "MENU UTAMA";
        gotoxy(1, 2);
        cout << "1. Tambah Data";
        gotoxy(1, 3);
        cout << "2. Hapus Data Terakhir" << endl;
        gotoxy(1, 4);
        cout << "3. Tampil Data" << endl;
        gotoxy(1, 5);
        cout << "4. Jumlah Data" << endl;
        gotoxy(1, 6);
        cout << "9. Keluar" << endl;

        gotoxy(1, 7);
        cout << "Pilihan Anda [1-9] : ";
        cin >> pilih;
        if (pilih == 1)
        { /*Menambah data baru diletakan di DATAKE*/
            tambahdata();
        }
        if (pilih == 2)
        { /*Menghapus Data Terakhir (DATAKE-1*/
            hapusdata();
        }
        if (pilih == 3)
        {
            tampildata();
        }
        if (pilih == 4)
        {
            jumlahdata();
        }
    } while (pilih != 9);
    return 0;
}
