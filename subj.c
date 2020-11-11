#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subj.h"
// 71

int ID = 1;
enum Thread { Metric, Cylindrical, Trapezoidal, Thrust };
enum Tab { Flats, Crushing, Notches, Traces };
enum Sideboard { Salient, Secret };

typedef struct Bolt
{
    struct Detail * before;
    struct Detail * after;
    
    int detal_ID;
    char name[20];
    int count;
    
    enum Thread thread;
} Bolt;

typedef struct Nail
{
    struct Detail * before;
    struct Detail * after;
    
    int detal_ID;
    char name[20];
    int count;
    
    enum Tab tab;
} Nail;

typedef struct Rivet
{
    struct Detail * before;
    struct Detail * after;
    
    int detal_ID;
    char name[20];
    int count;
	
	enum Sideboard sideboard;
} Rivet;



Detail* Write_Detail()
{	
	Detail* buf;
	char WorGorM=0;
	do
	{
	buf = malloc( sizeof(Detail) );	
	}
	while(!buf);
	
//	
	buf->id = ID++;
//	
	
//	
	printf(">> What is the name of the part?\n<< ");
	fflush(stdin);
	fgets(buf->name, 20, stdin);
//	

// 
	buf->material = None;
	printf(">> What is the material of the part?\n(Wood/Glass/Metal)\n<< ");
	do
	{
		WorGorM?:printf("\n>> Non-normal stuff, repeat\n<< ");
		fflush(stdin);
		scanf("%c",&WorGorM);	
	}
	while(WorGorM != 'W' && WorGorM != 'w' && WorGorM != 'G' && WorGorM != 'g' && WorGorM != 'M' && WorGorM != 'm');
	!(WorGorM == 'W' || WorGorM == 'w')?:(buf->material = Wood);
	!(WorGorM == 'G' || WorGorM == 'g')?:(buf->material = Glass);
	!(WorGorM == 'M' || WorGorM == 'm')?:(buf->material = Metal);
//

//
	printf(">> Enter part dimensions\n(width,length)\n<< ");
	while(fflush(stdin),scanf("%f%f",&(buf->width), &(buf->length) ) != 2 || !(buf->width > 0 && buf->length > 0))
		printf("\n>> Wrong area, repeat\n<< ");
//

//
	printf(">> What is the name of the part?\n<< ");
	fflush(stdin);
	fgets(buf->name, 7, stdin);
//
	return( buf );
}

Bolt* Write_Bolt()
{
	Bolt* buf;
	do
	{
	buf = malloc( sizeof(Bolt) );	
	}
	while(!buf);
	return(buf);
}
Nail* Write_Nail()
{
	Nail* buf;
	do
	{
	buf = malloc( sizeof(Nail) );	
	}
	while(!buf);
	return(buf);
}
Rivet* Write_Rivet()
{
	Rivet* buf;
	do
	{
	buf = malloc( sizeof(Rivet) );	
	}
	while(!buf);
	return(buf);	
}

Implement* Write_Implement()
{
	Implement* buf;
	char BorNorR;
	int bufID,bufCount;
	
//	
	printf(">> Enter Detail-ID\n\n<< ");
	while(fflush(stdin),scanf("%i",&bufID) != 1 || !(bufID < ID))
		printf("\n>> Parts with this ID do not exist, repeat\n<< ");
//	
	
//	
	printf(">> Enter count\n<< ");
	while(fflush(stdin),scanf("%i",&bufCount) != 1 || (bufCount < 1))
		printf("\n>> Wrong amount, repeat\n<< ");
//	
	
//	
	printf(">> What type of Implement?\n(Bolt/Nail/Rivet)\n<< ");
	do
	{
		fflush(stdin);
		scanf("%c",&BorNorR);	
	}
	while(BorNorR != 'B' && BorNorR != 'b' && BorNorR != 'N' && BorNorR != 'n' && BorNorR != 'R' && BorNorR != 'r');
	!(BorNorR == 'B' || BorNorR == 'b')?:(buf = (Implement*)Write_Bolt(),buf->type = eBolt);
	!(BorNorR == 'N' || BorNorR == 'n')?:(buf = (Implement*)Write_Nail(),buf->type = eNail);
	!(BorNorR == 'R' || BorNorR == 'r')?:(buf = (Implement*)Write_Rivet(),buf->type = eRivet);
//

	buf->detal_ID = bufID;	
	buf->count = bufCount;
	
//	
	printf(">> What is the name of the Implement?\n<< ");
	fflush(stdin);
	fgets(buf->name, 20, stdin);
//

}

obj *Write_Element()
{	
	char DorI=0;
	printf(">> What do you want to create?\n(Detail or Implement)\n<< ");
	do
	{
		DorI?:printf("\n>> Not a normal object, repeat\n<< ");
		fflush(stdin);
		scanf("%c",&DorI);	
	}
	while(DorI != 'D' && DorI != 'I' && DorI != 'd' && DorI != 'i');
	if(DorI != 'D' || DorI != 'd')
		return ((obj*)Write_Detail());
	else
		return ((obj*)Write_Implement());		
}
