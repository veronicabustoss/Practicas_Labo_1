#include "reglasNegocio.h"
#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* this);

int controller_List(LinkedList* this);

int controller_saveAsText(char* path, LinkedList* pArrayAbono);

int controller_saveAsBinary(char* path, LinkedList* pArrayAbono);

int controller_listAbonos(LinkedList* this, LinkedList* this2);

int menu();

