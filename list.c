#include <stdio.h>
#include <stdlib.h>
#include "list.h"



//Вырезка элемента из списка по адресу
void rezet(List *list, const obj *current){
	if(!list || !current){
		
	}
	else{		
		//При начальном элементе	
		if(current->after == 0){
	        list->tail = current->before;
	        if(list->tail != 0)
	       		list->tail->after = 0;
	    }
	    
	    //При конечном элементе
	    if(current->before == 0){
	        list->head = current->after;
	        if(list->head != 0)
	        	list->head->before = 0; 	
	    } 
	    
	    //Между двумя элементами       
		if(current->after != 0 && current->before != 0){
		    current->after->before = current->before;
		    current->before->after = current->after;
		}
	}
}


//Отчистка буфера
void ClearBuf(obj **buf, int *rplus){
	if((*buf) != 0 && rplus && (*rplus) == 1){
		free(*buf);
		*rplus = 0;			
	}	
	(*buf) = 0;
}


////Заполнение данных в ячейку листа
//void Write_Element(obj* obj){	
//	printf(">> Write name\n<< ");
//	getchar ();
////	cin.getline((obj->data.name),20);		
//}


//Получения номера от пользователя
int GetNumber(){
	int num = 0;
	while(printf(">> Enter the number (Back - 0)\n<< "),fflush(stdin),scanf("%d",&num)!=1?(printf("Invalid number\n"), 1):0)
	;
	return(num);
}


//
void Add(List *list, const obj *obj_get){
	if(!list && !obj_get)
	;	
	else{
		if(list->tail == 0){
			list->tail = malloc( sizeof(obj) );
			list->head = list->tail;
			list->tail->before = 0;
			list->tail->after = 0;			
		}
		else{
			obj *tmp = malloc( sizeof(obj) );
			tmp->before = list->tail;
			tmp->after = 0;
			list->tail->after = tmp;
			list->tail = tmp;
			free(tmp);
		}		
//		list->tail->data = obj_get->data;
	}
}


//
obj* GetItem(List *list, const int num){
	obj *current;
	if(!list || num == 0 || list->head == 0){
		return(0);
	}
	else if(list->head == list->tail){
		current = list->head;
		return(current);
	}
	else{	
		int s; 	
		if(num > 0){
	        current = list->head;        
			for(s = 1; s != num && current->after != 0 ;current = current->after,s++)
	        ; 	
		}
		else{
	        current = list->tail;
		    for(s = -1; s != num && current->before != 0; current = current->before,s--)
	        ;      
		}
		return(current);		
	}
}


//
obj* Remove(List *list, const int num){
	if(!list || num == 0 || list->head == 0){
		return(0);
	}	
	else{		
		obj *current = GetItem(list, num);
		if(list->head == list->tail)
			list->head = list->tail = 0;
		else
			rezet(list, current);       
		return(current);		
	}
}


//Новые параметры связаны с отчисткой буфера
void Del(List *list, const int num, obj **buf, int *rplus){
	if(!list || num == 0 || list->head == 0 || !buf || !rplus){
		
	}
	else{
		obj *current = Remove(list, num);
		if(current == (*buf)){
			(*rplus) = 1;
			ClearBuf(buf, rplus);
		}		
		else
			free(current);		
	}
} 


//
void Insert(List *list, obj *obj_get, const int num){
	if(!list || !obj_get || num == 0){
		
	}
	else{
		if(list->tail == 0){
			list->tail = malloc( sizeof(obj) );
			list->head = list->tail;
			list->tail->before = 0;
			list->tail->after = 0;
//			list->tail->data = obj_get->data;			
		}else{			
			obj *obj_new = malloc( sizeof(obj) );
			obj *current = GetItem(list, num);
			if(current->before == 0){
				obj_new->before = 0;
				obj_new->after = current;
				list->head = current->before = obj_new;
			}else{
				obj_new->before = current->before;
				obj_new->after = current;
				current->before = current->before->after = obj_new;				 
			}			
//			obj_new->data = obj_get->data;
		}
	}
}


//
int Count(const List *list){
	if(!list || list->head == 0)
	
	return(0);
			
	else{
		int s = 1;
		obj *current = list->head;
		while(current->after != 0){
			current = current->after;
			s++;
		}
		return(s);				
	}
}


//
void Clear(List* list){
	if(!list || list->tail == 0)
	;
		
	else{
		obj *current = list->tail;
		while(current->before != 0){
			current = current->before;
			free(current->after);
		}
		free(current);		
		list->head = 0;
		list->tail = 0;		
	}
}


//
int GetIndex(const List *list, const obj *new_obj){
	if(!list || list->head == 0 || !new_obj){
		return(0);
	}
	else{
		int s;
		obj *current = list->head;
		for(s=1; (current->after != 0) && (current != new_obj); current = current->after, s++)
		;		
		return((current == new_obj)?s:0);
	}
}

//Ввывод меню, запрос ключа
void Menu(int *a){
	if(!a)
	;	
	else{
		printf(	"Add	    1\n"  \
				"Delete		2\n"  \
				"GetItem	3\n"  \
				"Remove		4\n"  \
				"Insert		5\n"  \
				"Count		6\n"  \
				"Clear		7\n"  \
				"GetIndex	8\n"  \
			 	"Exit		0\n"  \
				"<< ");
		//Возможная проверка введеного ключа
		scanf("%d",a);	
		//--	
	}	
}
