#include "header.h"

void CreateEmpty(ListParent *L)
{
	(*L).first = NULL;
}

int isEmpty(ListParent L)
{
	if(L.first==NULL)
		return 1;
	else
		return 0;	
}

//fungsi Parent
int HaveChild(adrParent L)
{
	if(L->firstChild!=NULL)
		return 1;
	else
		return 0;	
}
int HaveChild2(adrParent L)
{
	if(L->firstChild2!=NULL)
		return 1;
	else
		return 0;	
}

int cekMeja(ListParent L, int idP, int noMeja)
{
	adrParent P;
	adrChildMeja M;
	P=FindParent(L,idP);

	M=P->firstChild;
	while(M!=NULL)
	{
		if(M->noMeja == noMeja)
		{
			if(strcmpi(M->M.nama,"-")!=0)
			{
				return 0;
			}else 
				return 1;
		}else
			M=M->nextChild;
	}
	return 0;
}

adrChildMeja findMeja(ListParent L, int noMeja){
	adrParent P;
	adrChildMeja M;
	P = FindParent(L,1);
	
	while(P!=NULL){
		M = P->firstChild;
		while(M!=NULL){
			if(M->noMeja == noMeja){
				return M;
			}
			M = M->nextChild;
		}
		break;
	}
	return NULL;
}


int findNoMeja(ListParent L, int noMeja){
	adrParent P;
	adrChildMeja M;
	int temp;
	P = FindParent(L,1);
	
	while(P!=NULL){
		M = P->firstChild;
		while(M!=NULL){
			if(M->noMeja == noMeja){
				temp++;
			}
			M = M->nextChild;
		}
	}
	return temp;
}

adrParent AlokasiP(int id)
{
	adrParent P;
	P = (adrParent)malloc(sizeof(Parent));
	P->id = id;
	P->nextParent=NULL;
	P->firstChild=NULL;
	P->firstChild2=NULL;
	return P;	
}

adrParent FindParent(ListParent L, int id)
{
	adrParent P = L.first;
	while(P!=NULL && P->id != id)
	{
		P = P->nextParent;
	}
	return P;
}

void insertFirstParent(ListParent *L, int databaru)
{
	adrParent P;
	P=AlokasiP(databaru);
	P->nextParent = (*L).first;
	(*L).first = P;
}

void insertLastParent(ListParent *L, int databaru)
{
	adrParent P, last;
	if(isEmpty(*L))
		insertFirstParent(&(*L),databaru);
	else{
		P = AlokasiP(databaru);
		last = (*L).first;
		while(last->nextParent!=NULL)
		{
			last = last->nextParent;
		}
		last->nextParent=P;
	}	
}

void printTerbanyak(ListParent L, int idP){
	adrParent P = FindParent(L,idP);
	adrChildNota N = P->firstChild2;
		Meja M;
		int NasGor=0,Steak=0,Tea=0,Lime=0,temp;
		if(HaveChild2(P)){
			while(N!=NULL){
				NasGor =N->M.NasGor+NasGor;
				Steak = N->M.Steak+Steak;
				Tea = N->M.Tea+Tea;
				Lime =N->M.Lime+Lime;
				N=N->nextChild;
			}
		}else
		{
			gotoxy(50,2);printf("Nota masih kosong");	
		}
		gotoxy(50,2);printf("Menu Terfavorit Hari ini :) ");
		if(NasGor>Steak){
			gotoxy(50,3);printf("Makanan : Nasi Goreng sebanyak %d",NasGor);	
		}else if(NasGor == Steak){
			gotoxy(50,3);printf("Makanan : Steak dan NasGor sebanyak %d",Steak);
		}else if(Steak>NasGor){
			gotoxy(50,3);printf("Makanan : Steak sebanyak %d",Steak);
		}
		
		
		if(Tea>Lime){
			gotoxy(50,4);printf("Minuman : Tea sebanyak %d",Tea);
		}else if(Tea == Lime){
			gotoxy(50,4);printf("Minuman : Tea dan Lime sebanyak %d",Tea);
		}else if(Tea<Lime){
			gotoxy(50,4);printf("Minuman : Lime sebanyak %d",Lime);
		}
			
}

void printNota(ListParent L){
	adrParent P;
	adrChildMeja C;
	adrChildNota N;
	float total = omzet(L);
	if(isEmpty(L))
		printf("List Kosong...");
	else
	{
		nota(L);
		P = L.first;
		while(P!=NULL)	
		{
			if(HaveChild2(P)){
				N=P->firstChild2;
				PrintChildNota(N,total);
			}
			P=P->nextParent;	
		}
	}	
}
void printMeja(ListParent L){
	
	adrParent P;
	adrChildMeja C;
	adrChildNota N;
	
	if(isEmpty(L))
		printf("List Kosong...");
	else
	{
		tampil(L);
		P = L.first;
		while(P!=NULL)	
		{
			
			if(HaveChild(P))
			{
				C=P->firstChild;
				PrintChildMeja(C);
			}
			P=P->nextParent;	
		}
	}	
}
void printInput(Meja M,int meja){
	tampilInput();
	int a=1;
	gotoxy(60,a++);printf("No Meja : %d",meja);
	gotoxy(60,a++);printf("Pembeli : %s",M.nama);
	a++;
	gotoxy(60,a++);printf("Nasi Goreng : %d",M.NasGor);
	gotoxy(60,a++);printf("Steak : %d",M.Steak);
	gotoxy(60,a++);printf("Tea : %d",M.Tea);
	gotoxy(60,a++);printf("Lime : %d",M.Lime);
	gotoxy(60,a++);printf("Biaya : %.2f\n",M.biaya);	
}
//fungsi Child
void insertMeja(ListParent *L,int idP,int meja,Meja M){
	adrParent P;
	adrChildMeja Me;
	P=FindParent((*L),idP);
	
	while(P!=NULL)
	{
		Me = P->firstChild;
		while(Me->noMeja!=meja)
		{
			Me=Me->nextChild;
		}
		Me->M=M;
		break;
	}
}
adrChildMeja AlokasiCM(Meja M, int noMeja)
{
	adrChildMeja C;
	
	C = (adrChildMeja)malloc(sizeof(ChildMeja));
	C->noMeja=noMeja;
	C->M = M;
	C->nextChild=NULL;
	return C;
}

adrChildNota AlokasiN(Meja M, int noMeja,int noNota, int totalBeli)
{
	adrChildNota C;
	
	C = (adrChildNota)malloc(sizeof(ChildNota));
	C->noMeja=noMeja;
	C->noNota=noNota;
	C->totalBeli =totalBeli;
	C->M = M;
	C->nextChild=NULL;
	return C;
}

void printInfo(Meja M, int a){
			
	gotoxy(60,a++);printf("Pembeli : %s",M.nama);
	a++;
	gotoxy(60,a++);printf("Nasi Goreng : %d",M.NasGor);
	gotoxy(60,a++);printf("Steak : %d",M.Steak);
	gotoxy(60,a++);printf("Tea : %d",M.Tea);
	gotoxy(60,a++);printf("Lime : %d",M.Lime);
	gotoxy(60,a++);printf("Biaya : %.2f\n",M.biaya);	
}

adrChildMeja printInfoSplit(adrChildMeja C, int noMeja){
	if(C!=NULL)
	{
		gotoxy(66,6);printf("List Nota");
		while(C!=NULL && C->noMeja==noMeja)
		{
			
			gotoxy(64,8);printf("[1]Nasi Goreng	: %d",C->M.NasGor);
			gotoxy(64,9);printf("[2]Steak 	: %d",C->M.Steak);
			gotoxy(64,10);printf("[3]Tea 		: %d",C->M.Tea);
			gotoxy(64,11);printf("[4]Lime 	: %d",C->M.Lime);
			return C;
			C=C->nextChild;
		}
	}
}


void PrintChildMeja(adrChildMeja C){
	int a=2, b=1;
	if(C!=NULL)
	{
//		gotoxy(10,a);printf("List Meja");
		while(C!=NULL)
		{	
			gotoxy(60,b);printf("No Meja : %d",C->noMeja);
			b=b+10;
			printInfo(C->M,a);
			a=a+10;
			C=C->nextChild;
		}
	}
}


void PrintChildNota(adrChildNota C, float total){
	int a,b;
	
	if(C!=NULL)
	{
		
		a = 1,b=0;while(C!=NULL)
		{
			gotoxy(52,a++);
			printf("No Nota : %d",C->noNota);
			gotoxy(52,a++);
			printf("No Meja : %d",C->noMeja);	
			gotoxy(52,a++);
			printf("Total Pembelian : %d",C->totalBeli);
			printInfo(C->M,a);
			a=a+10;
			C=C->nextChild;
		}
		b=a;
		gotoxy(62,b);printf("Total Omzet");
		gotoxy(60,b+1);printf("27 November 2020 :");
		gotoxy(60,a+3);printf("%.2f Rupiah",total);
	}
}

void insertFirstChildMeja(ListParent *L, int idP, Meja M, int noMeja){
	adrChildMeja C;
	adrParent P;
	P=FindParent((*L),idP);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=AlokasiCM(M,noMeja);
		C->nextChild = P->firstChild;
		P->firstChild=C;
	}	
}

void insertFirstChildNota(ListParent *L, int idP, Meja M, int noMeja, int noNota, int totalBeli){
	adrChildNota C;
	adrParent P;
	P=FindParent((*L),idP);
	if(P==NULL)
		printf("Parent tidak ada");
	else
	{
		C=AlokasiN(M,noMeja,noNota,totalBeli);
		C->nextChild = P->firstChild2;
		P->firstChild2=C;
	}	
}


void insertLastChildMeja(ListParent *L, int idP, Meja M, int noMeja){
	adrChildMeja C, LastChild;
	adrParent P;
	P=FindParent((*L),idP);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChild(P))	
		insertFirstChildMeja(&(*L),idP,M,noMeja);
	else
	{
		C=AlokasiCM(M,noMeja);
		LastChild = P->firstChild;
		while(LastChild->nextChild!=NULL)	
		{
			LastChild=LastChild->nextChild;
		}
		LastChild->nextChild=C;
	}	
}


void insertLastChildNota(ListParent *L, int idP, Meja M, int noMeja, int noNota, int totalBeli){
	adrChildNota C, LastChild;
	adrParent P;
	P=FindParent((*L),idP);
	if(P==NULL)
		printf("Parent tidak ada");
	else if(!HaveChild2(P))	
		insertFirstChildNota(&(*L),idP,M,noMeja,noNota,totalBeli);
	else
	{
		C=AlokasiN(M,noMeja,noNota,totalBeli);
		LastChild = P->firstChild2;
		while(LastChild->nextChild!=NULL)	
		{
			LastChild=LastChild->nextChild;
		}
		LastChild->nextChild=C;
	}	
}


void CreateMeja(ListParent *L){
	int i;
	Meja D;
	for(i=1;i<=10;i++)
	{
		D=makeMeja(0,0,0,0,"-");
		insertLastChildMeja(&(*L),1,D,i);
	}
}




Meja makeMeja(int NasGor, int Steak, int Tea, int Lime, string nama){
	Meja M;
	
	M.NasGor=NasGor;
	M.Steak=Steak;
	M.Tea=Tea;
	M.Lime=Lime;
	strcpy(M.nama,nama);
	M.biaya=((nasgor*NasGor)+(steak*Steak)+(tea*Tea)+(lime*Lime));
	
	return M;
}


void tambahMeja(ListParent *L, int idP,Meja M){
	adrParent P;
	adrChildMeja Me;
	P=FindParent((*L),idP);
	int nomor;
	
	while(P!=NULL)
	{
		Me = P->firstChild;
		while(Me->nextChild!=NULL)
		{
			Me=Me->nextChild;
		}
		break;
	}
	nomor = Me->noMeja+1;
	Me->nextChild=AlokasiCM(M,nomor);
}

int mejaTertinggi(ListParent L, int idP){
	adrParent P;
	adrChildMeja Me;
	P=FindParent(L,idP);
	int nomor;
	
	while(P!=NULL)
	{
		Me = P->firstChild;
		while(Me->nextChild!=NULL)
		{
			Me=Me->nextChild;
		}
		break;
	}
	nomor = Me->noMeja;
	return nomor;
}

int CountIdNota(ListParent L){
	adrParent P;
	adrChildNota N;
	int counter=0;
	P = FindParent(L,2);
	
	N = P->firstChild2;
	while(N!=NULL){
		counter = counter+1;
		N = N->nextChild;	
	}
	
	return counter+1;	
}

void PemBayaran(float biaya){
	float cash;
	SetColour(black,putih);gotoxy(56,15);printf("                                         ");
	SetColour(black,putih);gotoxy(56,16);printf("                                         ");
	SetColour(black,putih);gotoxy(56,17);printf("                                         ");
	gotoxy(64,15);printf("Total Harga : %.2f",biaya);
	do{
		gotoxy(64,16);printf("Cash : ");scanf("%f",&cash);
		if(cash<biaya){
			MessageBox(0,"Cash Tidak Cukup !", "WARNING", MB_OK );
			SetColour(black,putih);gotoxy(70,16);printf("               ");
		}
	}while(cash<biaya);
	gotoxy(64,17);printf("Kembalian : %.2f",cash-biaya);
	
}


void Bayar(ListParent *L, int noMeja){
	int totalBeli,idNota=0;
	adrChildMeja Me = findMeja((*L),noMeja);
	
	PemBayaran(Me->M.biaya);
	totalBeli = Me->M.NasGor+Me->M.Steak+Me->M.Tea+Me->M.Lime;
	idNota = CountIdNota(*L);
	insertLastChildNota(&(*L),2,Me->M,Me->noMeja,idNota,totalBeli);
	Me->M.Lime=Me->M.NasGor=Me->M.Steak=Me->M.Tea=Me->M.biaya = 0;
	strcpy(Me->M.nama,"-");
}

void gabungMeja(ListParent *L, int noMeja, int noMeja2){
	adrChildMeja Me1,Me2;
	Me1 = findMeja((*L),noMeja);
	Me2 = findMeja((*L),noMeja2);
	
	Me1->M.NasGor += Me2->M.NasGor;
	Me1->M.Lime += Me2->M.Lime;
	Me1->M.Steak += Me2->M.Steak;
	Me1->M.Tea += Me2->M.Tea;
	Me1->M.biaya += Me2->M.biaya;
	
	Me2->M.NasGor =
	Me2->M.Lime = 
	Me2->M.Steak = 
	Me2->M.Tea = 
	Me2->M.biaya = 0;
	strcpy(Me2->M.nama,"-");
}


void SplitMenu(int *banyak,int *menu){
	int banyak2,status=1;
	
	do{		
		gotoxy(56,16);printf("Masukkan Banyak yang ingin di split : ");scanf("%d",&banyak2);
		if(banyak2>*menu){
				MessageBox(0,"[!]Split Melebihi Banyak Pembelian !", "WARNING",MB_OK );
			//status = 0;
		}
	}while(banyak2>*menu);
	*banyak += banyak2;
	*menu -= banyak2;
	
}

void splitByMenu(ListParent *L, int noMeja){
	int tNasgor,tSteak,tLime,tTea;
	int menu,status,idNota,totalBeli;
	string yesno;
	float tTotal;
	adrParent P;
	adrChildMeja Me,C;
	Meja M;
	P=FindParent((*L),1);
	Me = findMeja((*L),noMeja);
	idNota = CountIdNota(*L);
	tNasgor=tSteak=tLime=tTea=tTotal = 0;
	
	do{
		C = printInfoSplit(Me,noMeja);
		do{
			SetColour(black,putih);gotoxy(91,13);printf("      ");
			SetColour(black,putih);gotoxy(56,15);printf("               ");
			SetColour(black,putih);gotoxy(56,16);printf("                                         ");
			SetColour(black,putih);gotoxy(56,17);printf("                                         ");
			status=1;
			gotoxy(56,13);printf("Input Nomor Menu yang ingin di pisah : ");scanf("%d",&menu);
			
			if(menu==1 && C->M.NasGor==0){
				status = 2;
			}
			if(menu==2 && C->M.Steak==0){
				status = 3;
			}	
			if(menu==3 && C->M.Tea==0){
				status = 4;
			}	
			if(menu==4 && C->M.Lime==0){
				status = 5;
			}	
			if(menu > 4 || menu==0)
					MessageBox(0,"[!]Menu Tidak Ada !", "WARNING",MB_OK );
			if(status!=1)
				MessageBox(0,"[!]Menu ini tidak bisa di split !", "WARNING",MB_OK );
		
		}while(menu>4 || menu==0 || status !=1);
		
		if(menu==1){
			gotoxy(56,15);printf("---NASGOR---");
			SplitMenu(&tNasgor,&C->M.NasGor);	
		}else if(menu==2){
			gotoxy(56,15);printf("---STEAK---");
			SplitMenu(&tSteak,&C->M.Steak);
		}else if(menu==3){
			gotoxy(56,15);printf("---TEA---");
			SplitMenu(&tTea,&C->M.Tea);
		}else if(menu==4){
			gotoxy(56,15);printf("---LIME---");
			SplitMenu(&tLime,&C->M.Lime);
		}
		
		if(C->M.NasGor==0 && C->M.Steak==0 && C->M.Tea==0 &&C->M.Lime==0){
			break;
		}
		
		do{
	
		gotoxy(56,17);printf("Apakah Masih ingin Split ? [Y/T] ");fflush(stdin);gets(yesno);
		SetColour(black,putih);gotoxy(82,17);printf("   ");
		if(strcmpi(yesno,"T")!=0 && strcmpi(yesno,"Y")!=0)
			MessageBox(0,"[!]Pilihan hanya Ya[Y] atau Tidak[T] !", "WARNING",MB_OK );
		}while(strcmpi(yesno,"T")!=0 && strcmpi(yesno,"Y")!=0);
	}while(strcmpi(yesno,"T")!=0);
	
	
	tTotal = ((nasgor*tNasgor)+(steak*tSteak)+(tea*tTea)+(lime*tLime));
	if(tTotal==0){
		MessageBox(0,"Split Nota diBatalkan !", "WARNING",MB_OK );
	}else{
		PemBayaran(tTotal);
	}
	totalBeli = tNasgor+tSteak+tTea+tLime;
	C->M.biaya -= tTotal;
	M = makeMeja(tNasgor,tSteak,tTea,tLime,C->M.nama);
	insertLastChildNota(&(*L),2,M,Me->noMeja,idNota,totalBeli);
	
	if(C->M.NasGor==0 && C->M.Steak==0 && C->M.Tea==0 &&C->M.Lime==0)
			strcpy(C->M.nama,"-");
}

int cekNama(ListParent L, int idP, string nama){
	adrParent P;
	adrChildMeja C;
	P=FindParent(L,idP);

		C=P->firstChild;
		while(C!=NULL)
		{
			if(strcmpi(C->M.nama,nama)==0)
			{
				return 1;
			}
			C=C->nextChild;
		}
	return 0;
}


int cariMejaDariNama(ListParent L, int idP, int noMeja, string nama){
	adrParent P;
	adrChildMeja M;
	P=FindParent(L,idP);
	while(P!=NULL)
	{
		M=P->firstChild;
		while(M!=NULL)
		{
			if(M->noMeja == noMeja)
			{
				if(strcmpi(M->M.nama,nama)==0)
				{
					return 1;
				}else 
					return 0;
			}else
				M=M->nextChild;
		}
	}
	return 0;
}

void edit(ListParent *L){

	string nama;
	adrChildMeja C,C2;
	adrParent P;
	Meja M;
	int i=0,pil,NasGor,Steak,Tea,Lime,noMeja,cek=0;
	system("cls");
	
	gotoxy(52,2);printf("Masukkan Nama Pembeli : ");fflush(stdin);gets(nama);	
	if(cekNama(*L,1,nama))
	{
		P = FindParent(*L,1);
		C = P->firstChild;
		int a=2;
		while(C!=NULL)
		{
			if(strcmpi(C->M.nama,nama)==0)
			{
				a++;
				for(i=52;i<82;i++){
					gotoxy(i,a);printf("%c",h);
					gotoxy(52,a);printf("%c",nw);
					gotoxy(82,a);printf("%c",ne);
				}
				a++;
				gotoxy(57,a++);printf("Meja %d",C->noMeja);
				gotoxy(57,a++);printf("[1]Nasi Goreng : %d",C->M.NasGor);
				gotoxy(57,a++);printf("[2]Steak : %d",C->M.Steak);
				gotoxy(57,a++);printf("[3]Tea : %d",C->M.Tea);
				gotoxy(57,a++);printf("[4]Lime : %d",C->M.Lime);
				a+2;	
				for(i=52;i<82;i++){
					gotoxy(i,a);printf("%c",h);
					gotoxy(52,a);printf("%c",sw);
					gotoxy(82,a);printf("%c",se);
				}
				cek++;		
				C2=C;
			}
			C = C->nextChild;
		}
		getch();
		if(cek==1)
		{
			goto edit;
		}
		else
		{
			box(3);
			do{
				gotoxy(8,3);printf("Masukkan No Meja : ");scanf("%d",&noMeja);
			}while(noMeja<=0 || !cariMejaDariNama(*L,1,noMeja,nama));
			
			C2 = findMeja(*L,noMeja); 
			edit:
				
			if(C2!=NULL)
			{
				system("cls");
				box(3);
				do{	
					
					for(i=52;i<82;i++){
						gotoxy(i,4);printf("%c",h);
						gotoxy(52,4);printf("%c",nw);
						gotoxy(82,4);printf("%c",ne);
					}
					gotoxy(57,5);printf("Meja %d",C2->noMeja);
					gotoxy(57,6);printf("[1]Nasi Goreng : %d",C2->M.NasGor);
					gotoxy(57,7);printf("[2]Steak : %d",C2->M.Steak);
					gotoxy(57,8);printf("[3]Tea : %d",C2->M.Tea);
					gotoxy(57,9);printf("[4]Lime : %d",C2->M.Lime);
					for(i=52;i<82;i++){
						gotoxy(i,10);printf("%c",h);
						gotoxy(52,10);printf("%c",sw);
						gotoxy(82,10);printf("%c",se);
					}
					
					gotoxy(16,6);printf("Pilhan Makanan");
					gotoxy(16,8);printf("[1] Nasi Goreng");
					gotoxy(16,9);printf("[2] Steak");
					gotoxy(16,10);printf("[3] Tea");
					gotoxy(16,11);printf("[4] Lime");
					gotoxy(16,12);printf("[0] Selesai");
					gotoxy(16,13);printf("==> ");scanf("%d",&pil);
											
					switch(pil)
					{
						case 1 : 
							do{
								gotoxy(12,16);printf("Jumlah Nasi Goreng : ");scanf("%d",&NasGor);
									if(NasGor<C2->M.NasGor){
										MessageBox(0,"Tidak Boleh Batalkan Pesanan!", "WARNING", MB_OK );
									}
										SetColour(black,putih);gotoxy(10,16);printf("                             ");
							}while(NasGor<C2->M.NasGor);
							C2->M.NasGor=NasGor;
						break;
						case 2 :
							do{
								gotoxy(12,16);printf("Jumlah Steak : ");scanf("%d",&Steak);
									if(Steak<C2->M.Steak){
										MessageBox(0,"Tidak Boleh Batalkan Pesanan!", "WARNING", MB_OK );
									}
									SetColour(black,putih);gotoxy(10,16);printf("                             ");
							}while(Steak<C2->M.Steak);
							C2->M.Steak=Steak;
						break;
						case 3 :
							do{
								gotoxy(12,16);printf("Jumlah Tea : ");scanf("%d",&Tea);
									if(Tea<C2->M.Tea){
										MessageBox(0,"Tidak Boleh Batalkan Pesanan!", "WARNING", MB_OK );
									}
									SetColour(black,putih);gotoxy(10,16);printf("                             ");
							}while(Tea<C2->M.Tea);
							C2->M.Tea=Tea;
						break;
						case 4 :
							do{
								gotoxy(12,16);printf("Jumlah Lime : ");scanf("%d",&Lime);
									if(Lime<C2->M.Lime){
										MessageBox(0,"Tidak Boleh Batalkan Pesanan!", "WARNING", MB_OK );
									}
									SetColour(black,putih);gotoxy(10,16);printf("                             ");
							}while(Lime<C2->M.Lime);
							C2->M.Lime=Lime;
						break;
						case 0 :
						break;	
						default : MessageBox(0,"Menu Makanan Tidak Tersedia !", "WARNING", MB_OK );
						break;
						
					}
					C2->M.biaya = ((nasgor*C2->M.NasGor) + (steak*C2->M.Steak) + (tea*C2->M.Tea) + (lime*C2->M.Lime));
						SetColour(black,putih);gotoxy(19,13);printf("     "); 
						SetColour(black,putih);gotoxy(10,16);printf("                             ");
				}while(pil!=0);
			}
			else
				MessageBox(0,"Tidak ketemu mejanya !", "WARNING", MB_OK );
		}
		
	}
	else
		MessageBox(0,"Tidak Ketemu !", "WARNING", MB_OK );
}
int notaTertinggi(ListParent L, int idP){
	adrParent P;
	adrChildNota No;
	P=FindParent(L,idP);
	int nomor;
	
	while(P!=NULL)
	{
		No = P->firstChild2;
		while(No->nextChild!=NULL)
		{
			No=No->nextChild;
		}
		break;
	}
	nomor = No->noNota;
	return nomor;
}
float omzet(ListParent L){
	adrParent P = FindParent(L,2);
	adrChildNota No = P->firstChild2;
	float total=0;
	
	while(No!=NULL)
	{
		total = No->M.biaya + total;
		No = No->nextChild;
	}
	
	return total;
}

//File Handling
void saveMeja(ListParent L, int idP){
	FILE *fileku;
	int retval,i;
	fileku = fopen("Data Meja.txt", "w");  
	adrParent P = FindParent(L,idP);
	adrChildMeja Me = P->firstChild;
	
	for(i=0;i<mejaTertinggi(L,idP);i++)  
	{   
	 	fprintf(fileku,"\nMeja ke-%d",i+1);
		fprintf(fileku,"\n\tNama 			: %s",Me->M.nama);
		fprintf(fileku,"\n\tNasi Goreng		: %d",Me->M.NasGor);
		fprintf(fileku,"\n\tSteak			: %d",Me->M.Steak);
		fprintf(fileku,"\n\tTea			: %d",Me->M.Tea);
		fprintf(fileku,"\n\tLime			: %d",Me->M.Lime);
		Me=Me->nextChild;
	}  
	fclose(fileku);    
	
}

void writeMeja(ListParent *L){
	FILE *fileku;
	fileku = fopen("Data Meja.txt", "r");  
	if(fileku==NULL)   
		printf("File tidak ketemu!\n");  
	else  
	{   
		int i=0, retval,noMeja,NasGor,Steak,Tea,Lime;
		string nama;
		Meja M;   
		fscanf(fileku,"\nMeja ke-%d",&noMeja);
		fscanf(fileku,"\n\tNama 			: %s",&nama);
		fscanf(fileku,"\n\tNasi Goreng		: %d",&NasGor);
		fscanf(fileku,"\n\tSteak			: %d",&Steak);
		fscanf(fileku,"\n\tTea			: %d",&Tea);
		retval = fscanf(fileku,"\n\tLime			: %d",&Lime);   
		if(retval !=-1) 
		{
			M=makeMeja(NasGor,Steak,Tea,Lime,nama);
			insertLastChildMeja(&(*L),1,M,noMeja);
		}
		while(retval != EOF)   
		{    
			fscanf(fileku,"\nMeja ke-%d",&noMeja);
			fscanf(fileku,"\n\tNama 			: %s",&nama);
			fscanf(fileku,"\n\tNasi Goreng		: %d",&NasGor);
			fscanf(fileku,"\n\tSteak			: %d",&Steak);
			fscanf(fileku,"\n\tTea			: %d",&Tea);
			retval = fscanf(fileku,"\n\tLime			: %d",&Lime);  
			if(retval !=-1) 
			{
				M=makeMeja(NasGor,Steak,Tea,Lime,nama);
				insertLastChildMeja(&(*L),1,M,noMeja);
			}
		} 
 	}  
	fclose(fileku);     
}
void saveNota(ListParent L, int idP){
	FILE *fileku;
	int i;
	fileku = fopen("Data Nota.txt", "w");  
	adrParent P = FindParent(L,idP);
	adrChildNota No = P->firstChild2;
	
	for(i=0;i<notaTertinggi(L,idP);i++)  
	{   
	 	fprintf(fileku,"\nNomor Nota : %d",i+1);
	 	fprintf(fileku,"\nNomor Meja : %d",No->noMeja);
		fprintf(fileku,"\n\tNama 			: %s",No->M.nama);
		if(No->M.NasGor!=0)
			fprintf(fileku,"\n\tNasi Goreng		: %d",No->M.NasGor);
		if(No->M.Steak!=0)	
			fprintf(fileku,"\n\tSteak			: %d",No->M.Steak);
		if(No->M.Tea!=0)	
			fprintf(fileku,"\n\tTea			: %d",No->M.Tea);
		if(No->M.Lime!=0)	
			fprintf(fileku,"\n\tLime			: %d",No->M.Lime);
		fprintf(fileku,"\n\tBiaya			: %.2f",No->M.biaya);
		No=No->nextChild;
	}  
	fclose(fileku); 
}
void writeNota(ListParent *L){  
FILE *fileku;
	fileku = fopen("Data Nota.txt", "r");  
	if(fileku==NULL)   
		printf("File tidak ketemu!\n");  
	else  
	{   
		int i=0, retval,noNota,NasGor,Steak,Tea,Lime,noMeja,retur;
		string nama;
		double biaya;
		Meja M;
		retval = fscanf(fileku,"\nNomor Nota : %d",&noNota);
	 	fscanf(fileku,"\nNomor Meja : %d",&noMeja);
		fscanf(fileku,"\n\tNama 			: %s",&nama);
		retur = fscanf(fileku,"\n\tNasi Goreng		: %d",&NasGor);
		if(retur == 0)
			NasGor = 0;
		retur = fscanf(fileku,"\n\tSteak			: %d",&Steak);
		if(retur == 0)
			Steak = 0;
		retur = fscanf(fileku,"\n\tTea			: %d",&Tea);
		if(retur == 0)
			Tea = 0;
		retur = fscanf(fileku,"\n\tLime			: %d",&Lime);   
		if(retur == 0)
			Lime = 0; 
		retur = fscanf(fileku,"\n\tBiaya			: %lf",&biaya);	 
		M = makeMeja(NasGor,Steak,Tea,Lime,nama);
		int totalBeli = NasGor+Steak+Tea+Lime;
		insertLastChildNota(&(*L),2,M,noMeja,noNota,totalBeli);
		while(retur != EOF)   
		{    
			retval = fscanf(fileku,"\nNomor Nota : %d",&noNota);
		 	fscanf(fileku,"\nNomor Meja : %d",&noMeja);
			fscanf(fileku,"\n\tNama 			: %s",&nama);
			retur = fscanf(fileku,"\n\tNasi Goreng		: %d",&NasGor);
			if(retur == 0)
				NasGor = 0;
			retur = fscanf(fileku,"\n\tSteak			: %d",&Steak);
			if(retur == 0)
				Steak = 0;
			retur = fscanf(fileku,"\n\tTea			: %d",&Tea);
			if(retur == 0)
				Tea = 0;
			retur = fscanf(fileku,"\n\tLime			: %d",&Lime);   
			if(retur == 0)
				Lime = 0;
			retur = fscanf(fileku,"\n\tBiaya			: %lf",&biaya);	 
			if(retur != -1)	
			{
				M = makeMeja(NasGor,Steak,Tea,Lime,nama);
				int totalBeli = NasGor+Steak+Tea+Lime;
				insertLastChildNota(&(*L),2,M,noMeja,noNota,totalBeli);
			}
		} 
 	}  
	fclose(fileku);  
}
void saveLaporan(ListParent L)
{
	FILE *fileku;
	fileku = fopen("Data Laporan.txt", "w"); 
	adrParent P = FindParent(L,2);
	adrChildNota N = P->firstChild2;
	int NasGor=0,Steak=0,Tea=0,Lime=0,temp;
	if(HaveChild2(P)){
		while(N!=NULL){
			NasGor =N->M.NasGor+NasGor;
			Steak = N->M.Steak+Steak;
			Tea = N->M.Tea+Tea;
			Lime =N->M.Lime+Lime;
			N=N->nextChild;
		}
	}else
	{
		goto done;
	}
	
	if(NasGor>Steak){
		fprintf(fileku,"\nMakanan Terbanyak adalah Nasi Goreng sebanyak %d",NasGor);	
	}else if(NasGor == Steak){
		fprintf(fileku,"\nMakanan Terbanyak adalah Steak dan NasGor sebanyak %d",Steak);
	}else if(Steak>NasGor){
		fprintf(fileku,"\nMakanan Terbanyak adalah Steak sebanyak %d",Steak);
	}
	
	
	if(Tea>Lime){
		fprintf(fileku,"\nMinuman Terbanyak adalah Tea sebanyak %d",Tea);
	}else if(Tea == Lime){
		fprintf(fileku,"\nMinuman Terbanyak adalah Tea dan Lime sebanyak %d",Tea);
	}else if(Tea<Lime){
		fprintf(fileku,"\nMinuman Terbanyak adalah Lime sebanyak %d",Lime);
	}
	
	float total = omzet(L);
	
	fprintf(fileku,"\nOmzet pada tanggal 27 November 2019 adalah Rp.%.2f",total);
	done:
	fclose(fileku);
	
}
