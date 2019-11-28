#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	int menu, NasGor, Steak, Tea, Lime, meja,pil,pilNota,pilSplit,gabung,pilTampil, merge;
	int  NasGor2=0, Steak2=0, Tea2=0, Lime2=0;
	string nama,yesno;
	Meja M;
	ListParent L;
	
	CreateEmpty(&L);
	insertFirstParent(&L,1);
	insertLastParent(&L,2);
	//CreateMeja(&L);
	writeMeja(&L);
	writeNota(&L);
	maximize();
	system("COLOR F0");
	box(2);
	gotoxy(54,6);printf("Restaurant....");
	gotoxy(60,9);printf(" LA'GRANDE ");
	gotoxy(51,14);printf("Press Anything to Start");
	getch();
	do
	{
		NasGor=0, Steak=0, Tea=0, Lime=0;
		NasGor2=0, Steak2=0, Tea2=0, Lime2=0;
		system("cls");
		system("COLOR F0");
		box(0);
		gotoxy(64,2);printf("Restoran LA' Grande");
		gotoxy(64,6);printf("[1] Input Makanan");
		gotoxy(64,8);printf("[2] Tambah Meja");
		gotoxy(64,10);printf("[3] Edit Makanan");
		gotoxy(64,12);printf("[4] Pembayaran");
		gotoxy(64,14);printf("[5] Laporan");
		gotoxy(64,16);printf("[0] Keluar");
		gotoxy(64,20);printf("==> ");scanf("%d",&menu);
		
		switch(menu)
		{
			case 1 :
					 system("cls");
					 box(1);
					do
					 {
					 	gotoxy(58,2);printf("Masukkan Nomor Meja 	: ");scanf("%d",&meja);
						if(meja<=0 || !cekMeja(L,1,meja)){
							MessageBox(0,"Meja Tidak Tersedia !", "WARNING", MB_OK );
							SetColour(black,putih);gotoxy(78,2);printf("          ");
						}			
					 }while(meja<=0 || !cekMeja(L,1,meja));
					 
					 do
					 {
					 	gotoxy(58,3);printf("Masukkan Nama Pembeli	: ");fflush(stdin);gets(nama);
					 }while(strlen(nama)<1);
					 
					 do
					 {
					 	gotoxy(66,6);printf("Pilhan Makanan");
						gotoxy(66,8);printf("[1] Nasi Goreng");
						gotoxy(66,9);printf("[2] Steak");
						gotoxy(66,10);printf("[3] Tea");
						gotoxy(66,11);printf("[4] Lime");
						gotoxy(66,12);printf("[0] Selesai");
						gotoxy(66,13);printf("==> ");scanf("%d",&pil);
					
						
						switch(pil)
						{
							case 1 : gotoxy(62,16);printf("Jumlah Nasi Goreng : ");scanf("%d",&NasGor);
									if(NasGor>=0)
									{
										NasGor2=NasGor2+NasGor;
									}else
									{
										NasGor=0;
									}
							break;
							case 2 : gotoxy(62,16);printf("Jumlah Steak : ");scanf("%d",&Steak);
									if(Steak>=0)
									{
										Steak2=Steak2+Steak;
									}else
									{
										Steak=0;
									}
							break;
							case 3 : gotoxy(62,16);printf("Jumlah Tea : ");scanf("%d",&Tea);
									if(Tea>=0)
									{
										Tea2=Tea2+Tea;
									}else
									{
										Tea=0;
									}
							break;
							case 4 : gotoxy(62,16);printf("Jumlah Lime : ");scanf("%d",&Lime);
									if(Lime>=0)
									{
										Lime2=Lime2+Lime;
									}else
									{
										Lime=0;
									}
							break;
							case 0 : break;
							default : MessageBox(0,"Menu Makanan Tidak Tersedia !", "WARNING", MB_OK );
							break;
						}
							SetColour(black,putih);gotoxy(69,13);printf("     "); 
							SetColour(black,putih);gotoxy(60,16);printf("                             ");
					 }while(pil!=0);
					 if(NasGor2!=0 || Steak2!=0 || Tea2!=0 || Lime2!=0)
					 {
						 M=makeMeja(NasGor2,Steak2,Tea2,Lime2,nama);
						 insertMeja(&L,1,meja,M);
						 system("cls");
						 printInput(M,meja);
						 getch();
					 }else
					 {
					 	MessageBox(0,"Meja Tidak Bisa Dipesan Karena Tidak Beli Apa-Apa !", "WARNING", MB_OK );
					 }
				
			break;
			case 2 :
				M = makeMeja(0,0,0,0,"-");
				tambahMeja(&L, 1,M);
				MessageBox(0,"Meja Berhasil Ditambah !", "WARNING", MB_OK );
			break;
			case 3 :
				edit(&L);
			break;
			
			case 4 :
				system("cls");
				box(1);
					gotoxy(62,2);printf("Masukkan Nomor Meja : ");scanf("%d",&meja); 
					if(meja<=0 || cekMeja(L,1,meja)){
						MessageBox(0,"Meja Belum Pesan!", "WARNING", MB_OK );
						SetColour(black,putih);gotoxy(83,2);printf("   ");
						goto akhir;
					}			
				
					gotoxy(66,6);puts("Jenis Pembayaran");				
					gotoxy(66,8);puts("1. Bayar");
					gotoxy(66,10);puts("2. Gabung Nota");
					gotoxy(66,12);puts("3. Pisah Nota");
					gotoxy(70,13);printf(">>>> ");scanf("%d",&pilNota);
					
					switch(pilNota){
						case 1 :
							Bayar(&L,meja);
							getch();
						break;
						
						case 2 :
							SetColour(black,putih);gotoxy(66,8);printf("              ");
							SetColour(black,putih);gotoxy(66,10);printf("              ");
							SetColour(black,putih);gotoxy(66,12);printf("              ");
							SetColour(black,putih);gotoxy(66,13);printf("              ");
							do{
								do{
									gotoxy(64,6);printf("[ 0 ] untuk keluar");
									gotoxy(54,9);printf("Masukkan Nomor Meja yang ingin di gabung : ");scanf("%d",&gabung);
									if(gabung == 0)
										break;
									if(cekMeja(L,1,gabung)==1){
										MessageBox(0,"Nomor Meja tidak ada !", "WARNING", MB_OK );
										SetColour(black,putih);gotoxy(97,9);printf("  ");
									}
								}while(cekMeja(L,1,gabung)==1);
								if(gabung == 0)
										break;
									gabungMeja(&L,meja,gabung);
								gotoxy(56,10);printf("Apakah ingin menggabung lagi [Y/T] ?");fflush(stdin);gets(yesno);
								if(strcmpi(yesno,"T")!=0 && strcmpi(yesno,"Y")!=0){
									MessageBox(0,"Pilihan hanya Ya[Y] atau Tidak[T]", "WARNING", MB_OK );
								}
									SetColour(black,putih);gotoxy(54,9);printf("                                            ");
									SetColour(black,putih);gotoxy(56,10);printf("                                     ");
									
							}while(strcmpi(yesno,"T")!=0);
							Bayar(&L,meja);
							getch();
						break;
						
						case 3 :
								SetColour(black,putih);gotoxy(66,8);printf("              ");
								SetColour(black,putih);gotoxy(66,10);printf("              ");
								SetColour(black,putih);gotoxy(66,12);printf("              ");
								SetColour(black,putih);gotoxy(66,13);printf("              ");
								splitByMenu(&L,meja);
								getch();
								break;
					}
					akhir:
			break;	
			
			case 5 :
				do{
					system("cls");
					box(1);
					gotoxy(68,2);printf("Laporan Harian");
					gotoxy(66,9);printf("1. Laporan Meja");
					gotoxy(66,10);printf("2. Laporan Nota");
					gotoxy(66,11);printf("3. Laporan Menu Favorit");
					gotoxy(66,12);printf("0. Keluar");
					gotoxy(66,16);printf(">>>> ");scanf("%d",&pilTampil);
					switch(pilTampil){
						case 1:system("cls");
								printMeja(L);
								break;
						case 2:system("cls");
								printNota(L);
								break;
						case 3:system("cls");
								printTerbanyak(L,2);
								break;
						case 0:break;
						default :MessageBox(0,"Menu Tidak Tersedia !", "WARNING", MB_OK );
								break;
					}
					getch();
				}while(pilTampil!=0);
			break;	
			case 0 :system("cls");
					box(2);
					gotoxy(54,6);printf("Have a");
					gotoxy(60,9);printf(" Nice Day... ");
					getch();
					break; 
			default : 
				MessageBox(0,"Menu Tidak Tersedia !", "WARNING", MB_OK );
				SetColour(black,putih);gotoxy(68,20);printf("   ");
			break;
		}
	}while(menu!=0);
	saveMeja(L,1);
	saveNota(L,2);
	saveLaporan(L);
	return 0;
}
