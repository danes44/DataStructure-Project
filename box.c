#include "header.h"

void maximize(){
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_SHOWMAXIMIZED);
}

void SetColour(char text, char bg)
{
	unsigned short color=bg*16+text;
	HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsoleOutput,color);
}

void gotoxy(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD dwCursorPosition;
	
	dwCursorPosition.X = x;
	dwCursorPosition.Y = y;
	
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void tampilInput(){
	int i,j;
	for(i=50;i<85;i++)
	{
		for(j=0;j<10;j++)
		{
			gotoxy(i,0);printf("%c",h);
			gotoxy(i,10);printf("%c",h);
			gotoxy(50,j);printf("%c",v);
			gotoxy(85,j);printf("%c",v);
			gotoxy(i,3);printf("%c",h);
			
		}
	}
	
	gotoxy(50,0);printf("%c",nw);
	gotoxy(85,0);printf("%c",ne);
	gotoxy(50,10);printf("%c",sw);
	gotoxy(85,10);printf("%c",se);
}
void nota(ListParent L){
	int i,j,k,no;
	no=notaTertinggi(L,2)*13;

			for(j=0;j<no;j+=13)
			{
				for(i=50;i<85;i++)
				{
					gotoxy(i,0);printf("%c",h);
					gotoxy(i,no);printf("%c",h);
					gotoxy(i,j);printf("%c",h);	
					gotoxy(i,no+5);printf("%c",h);
				}
			}
			for(i=0;i<no+5;i++)
			{
				if(i%13==0){
					gotoxy(50,i);printf("%c",w);
					gotoxy(85,i);printf("%c",e);
				}else{
					gotoxy(50,i);printf("%c",v);
					gotoxy(85,i);printf("%c",v);
				}
			}
			
		gotoxy(50,0);printf("%c",nw);
		gotoxy(85,0);printf("%c",ne);
		gotoxy(50,no);printf("%c",w);
		gotoxy(85,no);printf("%c",e);
		
		gotoxy(50,no+5);printf("%c",sw);
		gotoxy(85,no+5);printf("%c",se);
}

void tampil(ListParent L){
	int i,j,k,no,ni;
	no=mejaTertinggi(L,1)*10;
	ni=mejaTertinggi(L,1);

			for(j=0;j<no;j+=10)
			{
				for(i=50;i<85;i++)
				{
					gotoxy(i,0);printf("%c",h);
					gotoxy(i,no);printf("%c",h);
					gotoxy(i,j);printf("%c",h);
					for(k=3;k<no;k+=10)
					{
						gotoxy(i,k);printf("%c",h);
					}
				}
			}
			for(i=0;i<no;i++)
			{
				for(k=3;k<no;k+=10){
					if(i%10==0){
						if(k%3==0){
							gotoxy(50,i);printf("%c",w);
							gotoxy(85,i);printf("%c",e);
						}
					}
					else{
						gotoxy(50,i);printf("%c",v);
						gotoxy(85,i);printf("%c",v);
					}
				}
			}
			gotoxy(50,0);printf("%c",nw);
			gotoxy(85,0);printf("%c",ne);
			gotoxy(50,no);printf("%c",sw);
			gotoxy(85,no);printf("%c",se);
}

void box(int pil){

	int i,j,k;
	
	switch(pil){
		case 0:
			
			for(i=50;i<100;i++){
				gotoxy(i,0);printf("%c",h);
				gotoxy(i,4);printf("%c",h);
				gotoxy(i,22);printf("%c",h);
				gotoxy(i,18);printf("-");
			}
			for(j=0;j<22;j++){
				gotoxy(50,j);printf("%c",v);
				gotoxy(100,j);printf("%c",v);
			}
			gotoxy(50,0);printf("%c",nw);
			gotoxy(100,0);printf("%c",ne);
			gotoxy(50,4);printf("%c",w);
			gotoxy(100,4);printf("%c",e);
			gotoxy(50,22);printf("%c",sw);
			gotoxy(100,22);printf("%c",se);
			
			break;
	
		case 1:
			
			for(i=50;i<100;i++){
				gotoxy(i,0);printf("%c",h);
				gotoxy(i,5);printf("%c",h);
				gotoxy(i,7);printf("-");
				gotoxy(i,14);printf("-");
				gotoxy(i,18);printf("%c",h);
			}
			
			for(i=0;i<18;i++){
				gotoxy(50,i);printf("%c",v);
				gotoxy(100,i);printf("%c",v);
			}
			
			gotoxy(50,0);printf("%c",nw);
			gotoxy(100,0);printf("%c",ne);
			gotoxy(50,18);printf("%c",sw);
			gotoxy(100,18);printf("%c",se);
			gotoxy(50,5);printf("%c",w);
			gotoxy(100,5);printf("%c",e);
			
			break;
			
		case 2:
			for(i=50;i<75;i++){
				for(j=0;j<15;j++){
					gotoxy(i,0);printf("%c",h);
					gotoxy(i,15);printf("%c",h);
					gotoxy(50,j);printf("%c",v);
					gotoxy(75,j);printf("%c",v);
					
				}
			}
			
			gotoxy(50,0);printf("%c",nw);
			gotoxy(75,0);printf("%c",ne);
			gotoxy(50,15);printf("%c",sw);
			gotoxy(75,15);printf("%c",se);
			break;
		case 3 :
				
			for(i=0;i<50;i++){
				gotoxy(i,0);printf("%c",h);
				gotoxy(i,5);printf("%c",h);
				gotoxy(i,7);printf("-");
				gotoxy(i,14);printf("-");
				gotoxy(i,18);printf("%c",h);
			}
			
			for(i=0;i<18;i++){
				gotoxy(0,i);printf("%c",v);
				gotoxy(50,i);printf("%c",v);
			}
			
			gotoxy(0,0);printf("%c",nw);
			gotoxy(50,0);printf("%c",ne);
			gotoxy(0,18);printf("%c",sw);
			gotoxy(50,18);printf("%c",se);
			gotoxy(0,5);printf("%c",w);
			gotoxy(50,5);printf("%c",e);
			
			break;
			  
	}
	
}
