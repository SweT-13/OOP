#include <stdio.h>
#include <stdlib.h>
#include "list.h"
	
//Главная функция
int main() 
{ 
	int key, num;
	int rplus = 0;//переменная отвечает за тип содержимого буфера(елемент или аддресс)
	List list = {0,0};	
	obj *buf = 0;
	printf("Hello User\n\n");
	
	do
	{
   		Menu(&key);
		switch(key){			
   				case(1): //Add					
					if(buf == 0 || rplus == 0){
						Write_Element(buf);
							rplus = 1;		
					}					
   					Add(&list, buf);
   					ClearBuf(&buf, &rplus);   					
				   	break;
   				case(2): //Delete
   					Del(&list, GetNumber(),&buf,&rplus);
				   	break;
   				case(3): //GetItem
   					if(num = GetNumber()){
						ClearBuf(&buf,&rplus);
	   					buf = GetItem(&list, num);
						buf == 0? :(rplus = 0);  			
					}
				   	break;
   				case(4): //Remove
				    if(num = GetNumber()){						
						ClearBuf(&buf,&rplus);
	   					buf = Remove(&list, num); 
						buf == 0? :(rplus = 1); 			
					}    				
				   	break;
   				case(5): //Insert
   					if(buf == 0 || rplus == 0){   						
						buf = malloc( sizeof(obj) ); 
						if(buf != 0){
							Write_Element(buf);
							rplus = 1;	
						} 	
					}					
   					Insert(&list, buf, GetNumber());
   					ClearBuf(&buf, &rplus);   					
				   	break;				   	
   				case(6): //Count
				    printf(">> %d\n",Count(&list));
				    system("pause");
				   	break;
   				case(7): //Clear
   					Clear(&list);
   					ClearBuf(&buf,&rplus);   					
				   	break;
   				case(8): //GetIndex
   					//Ввод аддресса??Чем оно должно быть представленно?
				    printf(">> %d\n",GetIndex(&list,buf));
				    system("pause");
				   	break;			
		}
		
	system("cls");
	printf("Buf: %p\n\n",buf);		
	}
    while(key);
    system("cls");
    Clear(&list);
    ClearBuf(&buf,&rplus);
    printf("Good bye\n\n");
    system("pause"); 
    return(0); 
}
