#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
int space;
void scores(void);
void menu(void);
void show(int alan[][9],int seviye);
int zorluk(int alan[][9]);
void oyun(int alan[][9]);
int kotrol(int alan[][9]);
int oyuncu(int alan[][9], int seviye);
void kayit(int zaman,int seviye);
int main() {
	int sat, sut, v;
	int zaman, seviye, ctrl;
	int alan[11][9]={0};
	menu();
	oyun(alan);
	seviye = zorluk(alan);
	show(alan,seviye);
	zaman=oyuncu(alan,seviye);
	ctrl = kotrol(alan);
	if(ctrl)
	kayit(zaman,seviye);
	fflush(stdin);
	getchar();
    
	return 0;
} 
void scores(void){
	FILE *f;
	if((f=fopen("scores.txt","r"))==NULL)
	{
		printf("hic scor bulunamadi\n");
		fflush(stdin);
		getchar();system("CLS");
		return;
	}
	while(!feof(f))
	{
		printf("%c", fgetc(f));
	}
	fflush(stdin);
	getchar();
	system("CLS");
	menu();
	fclose(f);
	
}
void menu(void){
	while(1)
	{
		int secim;
		printf("1)New game\n"
	           "2)Scores\n"
			   "3)Exit\n"
			   "Seciminizi girin:");fflush(stdin);
	    scanf("%d",&secim);
	    switch(secim)
	    {
	    	case 1: return ; break;
	    	case 2: scores(); break;
	    	case 3: exit(0) ; break; 
	    	default: system("CLS");menu(); 
		}
	}
	
}
void show(int alan[][9],int seviye){
	int i,j;
 	 for(i=0;i<11;i++)
	{
		if(i==9)
		printf("+---+---+---+---+---+---+---+---+---+\n\n\n");
		printf("+---+---+---+---+---+---+---+---+---+\n");
		for(j=0;j<9;j++)
		{
			if(alan[i][j]!=0)
			printf("| %d ",alan[i][j]);
			else printf("|   ");
		}
		printf("|\n");
		if(seviye>=3&&i==8)break;
	}
	printf("+---+---+---+---+---+---+---+---+---+\n");
}
int zorluk(int alan[][9]){
	int i,seviye,sat,sut;
	while(1)
	{
		system("CLS");
		printf("1)baby\n"
	           "2)easy\n"
	           "3)hard\n"
	           "4)imposible\n"
               "zorluk seviyesi giriniz:");
        scanf("%d",&seviye);
        if(seviye<=4&&seviye>0)break; 
	}
	for(i=0;i<9;i++)
	alan[9][i]=i+1;
	if(seviye==1)space=15;
	else if(seviye==4)space=40;
	else space=30;
	for(i=0;i<space;i++)
	{
		sat=rand()%9;
		sut=rand()%9;
		if(alan[sat][sut]!=0)
		{
			alan[10][(alan[sat][sut]-1)]++;
			alan[sat][sut]=0;
		}
		else i--;
	}
	system("CLS");
	return seviye;
}
void oyun(int alan[][9]){
	int i=0,j,x=0,y=0,t=0,k,l,m,n,r,f=0,p=0;
	srand(time(NULL));
	int sat=0,sut=0,v;
	while(1)
	{
		
		while(1)
    	{
    		if(f==300)
    		{
    			for(i=0;i<9;i++)
    			{
    				for(j=0;j<9;j++)
    				{
    					alan[i][j]=0;
    					
					}
				}	
				i=0,f=0;
			}
		    x=0,y=0,t=0;
    		sat=rand()%9;
			sut=rand()%9;
			v=rand()%9+1;
			for(j=0;j<9;j++)
			{
				if(v==alan[sat][j])x++;
				if(v==alan[j][sut])y++;
			}
			for(k=0;k<7;k=k+3)
			{
				if(sat>=k&&sat<=k+2)l=k;
				if(sut>=k&&sut<=k+2)m=k;
			}
			for(r=l;r<l+3;r++)
			{
				for(n=m;n<m+3;n++)
				{
					if(v==alan[r][n])t++;
					
				}
				
			}
			
			if(x==0&&y==0&&t==0)break;
			
		}
		f++;
		if(sat<9&&sat>=0&&sut<9&&sut>=0&&v<=9&&v>0)
  		{
  		    if(alan[sat][sut]==0)
			i++;
			alan[sat][sut]=v;
			if(i==81)
			break;
 		}
			
	}
}
int kotrol(int alan[][9]){
	int i,j,k,l,m,r,n;
	int x=0,y=0,t=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			for(k=0;k<9;k++)
			{
				if(j!=k)
				if(alan[i][j]==alan[i][k])x++;
				if(i!=k)
				if(alan[i][j]==alan[k][j])y++;
			}
			for(k=0;k<7;k=k+3)
			{
				if(i>=k&&i<=k+2)l=k;
				if(j>=k&&j<=k+2)m=k;
			}
			for(r=l;r<l+3;r++)
			{
				for(n=m;n<m+3;n++)
				{
					if(i!=r&&j!=n)
					if(alan[i][j]==alan[r][n])t++;	
				}
			}			
		}
	}
	if(x==0&&y==0&&t==0)
	{
		printf("tebrikler kazandiniz!!!\n");
		return 1;
	}
	else 
	{
		printf("kaybettiniz!!!\n");getchar();
		return 0;
	}
}
int oyuncu(int alan[][9], int seviye){
	int err;
	int sat ,sut, v, zaman;
	time_t start,end;time(&start);
	git:
	while(space)
	{
		printf("satir giriniz:");
		err=scanf("%d",&sat);sat--;
		if(err==0)
		{
			fflush(stdin);
			system("CLS");
			show(alan,seviye);
			goto git;
		}
		printf("sutun giriniz:");
		err=scanf("%d",&sut);sut--;
		if(err==0)
		{
			fflush(stdin);
			system("CLS");
			show(alan,seviye);
			goto git;
		}
		printf("deger giriniz(silmek icin 0):");
		err=scanf("%d",&v);
		if(err==0)
		{
			fflush(stdin);
			system("CLS");
			show(alan,seviye);
			goto git;
		}
		system("CLS");
		if(sat<9&&sat>=0&&sut<9&&sut>=0&&v<=9&&v>=0)
		{
			if(v==0)
			{
				alan[10][alan[sat][sut]-1]++;
				alan[sat][sut]=0;
				space++;
			}
		    else if(alan[sat][sut]==0)
			{
				alan[10][v-1]--;
				alan[sat][sut]=v;
				space--;
			}
			else printf("bu alan dolu!!!\n");
		}
		else printf("tekrar deneyiniz!!\n");
		
		show(alan,seviye);
	}
	time(&end);
	zaman = difftime(end, start);
	return zaman;
	
}
void kayit(int zaman,int seviye){
	int p=0,len;
	char ch, head[50],diff[10];
	struct tm *tarih;
	time_t loc;
	loc = time(NULL);
	tarih=localtime(&loc);
	
	FILE *f;
	f=fopen("scores.txt","a+");
	
	strcpy(head,"======================== SCORES ========================\n\n");
	while(!feof(f))
	{
		ch=fgetc(f);
		p++;
	}
	//printf("%d\n",p);
	if(p<=1)
	fprintf(f,head);
	len=strlen(head);
	fclose(f);
	f=fopen("scores.txt","a+");
	if(seviye==1)strcpy(diff,"BABY");
	else if(seviye==2)strcpy(diff,"EASY");
	else if(seviye==3)strcpy(diff,"HARD");
	else strcpy(diff,"IMPOSIBLE");
	
	p=0;
	while(!feof(f))
	{
		ch=fgetc(f);
		p++;
		
	}
	
	//printf("%d\n",p);
	 
	fprintf(f,"%d)%.24s      %.2d h %.2d m %.2d s %s\n", (p-(len+1))/(47+strlen(diff))+1, asctime(tarih), zaman/3600, zaman/60, zaman%60,diff);
	fclose(f);
	
	return;
}

