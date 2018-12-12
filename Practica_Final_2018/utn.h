
int getInt();
float getFloat();
char getChar();

char getNumeroAleatorio(int desde , int hasta, int iniciar);

int esNumerico(char *str) ;
int esTelefono(char *str);
int esAlfaNumerico(char *str);
int esSoloLetras(char *str);
int esNumericoFlotante(char str[]);

void getString(char mensaje[],char input[]);
int getStringLetras(char mensaje[],char input[]);
int getStringNumeros(char mensaje[],char input[]);
int getStringNumerosFlotantes(char mensaje[],char input[]);

int getValidInt(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);
void getValidString(char requestMessage[],char errorMessage[], char input[]);

void cleanStdin(void);

float getValidFloat(char requestMessage[],char errorMessage[], int lowLimit, int hiLimit);

char getValidSexo( char requestMessage[], char* input);

int esSoloLetrasYNumeros(char str[]);
void getStringConEspacio(char mensaje[],char input[]);
void getSuperAlfaNumerico(char requestMessage[],char errorMessage[], char input[]);

void arreglarCadena(char lista[], int tamanio);




int getStringValidNombre(char mensaje[],char input[]);
void getValidStringEspaciosYLetras(char requestMessage[],char errorMessage[], char input[]);



int getNumeros(char mensaje[],char input[]);
void getValidStringNumeros(char requestMessage[],char errorMessage[], char input[]);




int getNumerosFlotantes(char mensaje[],char input[]);
void getValidStringNumerosFlotantes(char requestMessage[],char errorMessage[], char input[]);


