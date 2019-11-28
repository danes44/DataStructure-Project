#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define nasgor 10000.0
#define steak 15000.0
#define tea	5000.0
#define lime 7000.0

#define putih 15
#define black 0
#define nw 201
#define sw 200
#define w 204
#define n 203
#define ne 187
#define c 206
#define s 202
#define v 186
#define h 205
#define e 185
#define se 188


typedef char string[30];

typedef struct tParent* adrParent;
typedef struct tChildMeja* adrChildMeja;
typedef struct tChildNota* adrChildNota;


typedef struct
{
	int NasGor;
	int Steak;
	int Tea;
	int Lime;
	string nama;
	float biaya;
}Meja;

typedef struct tChildMeja
{
	int noMeja;
	Meja M;
	adrChildMeja nextChild;
}ChildMeja;

typedef struct tChildNota
{
	int noMeja;
	int noNota;
	int totalBeli;
	Meja M;
	adrChildNota nextChild;
}ChildNota;

typedef struct tParent
{
	int id;
	adrParent nextParent;
	adrChildMeja firstChild;
	adrChildNota firstChild2;
}Parent;

typedef struct
{
	adrParent first;
}ListParent;


//fungsi List
void CreateEmpty(ListParent *L);
int isEmpty(ListParent L);


//fungsi Parent
int HaveChild(adrParent L);
adrParent AlokasiP(int id);
adrParent FindParent(ListParent L, int id);
void insertFirstParent(ListParent *L, int databaru);
void insertLastParent(ListParent *L, int databaru);
void insertAfterParent(ListParent *L, int datasebelum, int databaru);


//fungsi Child
void CreateMeja(ListParent *L);
int cekMeja(ListParent L, int idP, int noMeja);
adrChildMeja findMeja(ListParent L, int noMeja);
int findNoMeja(ListParent L, int noMeja);
adrChildMeja AlokasiCM(Meja M, int noMeja);
adrChildNota AlokasiN(Meja M, int noMeja,int noNota, int totalBeli);
void Bayar(ListParent *L, int noMeja);
void insertFirstChildMeja(ListParent *L, int idP, Meja M,int  meja);
void insertFirstChildNota(ListParent *L, int idP, Meja M, int noMeja, int noNota, int totalBeli);
void insertLastChildMeja(ListParent *L, int idP, Meja M, int noMeja);
void insertLastChildNota(ListParent *L, int idP, Meja M, int noMeja, int noNota, int totalBeli);
Meja makeMeja(int NasGor, int Steak, int Tea, int Lime, string nama);
void tambahMeja(ListParent *L, int idP,Meja M);
int mejaTertinggi(ListParent L, int idP);
int cekNama(ListParent L, int idP, string nama);
int notaTertinggi(ListParent L, int idP);
int cariMejaDariNama(ListParent L, int idP, int noMeja, string nama);
int CountIdNota(ListParent L);
void PemBayaran(float biaya);
void gabungMeja(ListParent *L, int noMeja, int noMeja2);
void SplitMenu(int *banyak,int *menu);
void splitByMenu(ListParent *L, int noMeja);
void edit(ListParent *L);
void insertMeja(ListParent *L, int idP, int meja, Meja M);
float omzet(ListParent L);

//Tampilan
void printTerbanyak(ListParent L, int idP);
void printMeja(ListParent L);
void printNota(ListParent L);
void nota(ListParent L);
void tampil(ListParent L);
void tampilInput();
void printInput(Meja M,int meja);
void printInfo(Meja M, int a);
adrChildMeja printInfoSplit(adrChildMeja C, int noMeja);
void PrintChildMeja(adrChildMeja C);
void PrintChildNota(adrChildNota C, float total);

//File Handling
void saveMeja(ListParent L, int idP);
void writeMeja(ListParent *L);
void saveNota(ListParent L, int idP);
void writeNota(ListParent *L);
void saveLaporan(ListParent L);
