
typedef struct List{
		
	struct Item *head;//Аддресс начала списка
	struct Item *tail;//Аддресс конца списка
	
} List;

typedef struct Item{
	
	struct Item *before;//Находящийся ПЕРЕД элементом
	struct Item *after;//Находящийся ПОСЛЕ элемента
	
} obj;

//Вырезка элемента из списка по адресу
void rezet(List *list, const obj *current);
//Отчистка буфера
void ClearBuf(obj **buf, int *rplus);
//Заполнение данных в ячейку листа
//void Write_Element(obj *obj);
//Получения номера от пользователя
int GetNumber();


//
void Add(List *list, const obj *obj_get);
//
obj* GetItem(List *list, const int num);
//
obj* Remove(List *list, const int num);
//Новые параметры связаны с отчисткой буфера
void Del(List *list, const int num, obj **buf, int *rplus);
//
void Insert(List *list, obj *obj_get, const  int num);
//
int Count(const List *list);
//
void Clear(List *list);
//
int GetIndex(const List *list, const obj *new_obj);
//Ввывод меню, запрос ключа
void Menu(int *a);



