#include "list.h"

enum Material { None, Wood, Glass, Metal };
enum Type { eBolt, eNail, eRivet };
//int ID = 0;

typedef struct Detail
{
    struct Detail * before;
    struct Detail * after;
    
    int id;
    char name[20];
    enum Material material;
    double width;
    double length;
    char shifr[6];
} Detail;

typedef struct Implement
{
    struct Detail * before;
    struct Detail * after;
    
    int detal_ID;
    char name[20];
    int count;
    enum Type type;
} Implement;

obj* Write_Element();

Detail* Write_Detail();

Implement* Write_Implement();

