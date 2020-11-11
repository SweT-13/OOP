
typedef struct List{
		
	struct Item *head;//������� ������ ������
	struct Item *tail;//������� ����� ������
	
} List;

typedef struct Item{
	
	struct Item *before;//����������� ����� ���������
	struct Item *after;//����������� ����� ��������
	
} obj;

//������� �������� �� ������ �� ������
void rezet(List *list, const obj *current);
//�������� ������
void ClearBuf(obj **buf, int *rplus);
//���������� ������ � ������ �����
//void Write_Element(obj *obj);
//��������� ������ �� ������������
int GetNumber();


//
void Add(List *list, const obj *obj_get);
//
obj* GetItem(List *list, const int num);
//
obj* Remove(List *list, const int num);
//����� ��������� ������� � ��������� ������
void Del(List *list, const int num, obj **buf, int *rplus);
//
void Insert(List *list, obj *obj_get, const  int num);
//
int Count(const List *list);
//
void Clear(List *list);
//
int GetIndex(const List *list, const obj *new_obj);
//������ ����, ������ �����
void Menu(int *a);



