#define LEN 10

typedef struct {
	char name[50];
	int year;
	char country[50];
	int population;
} city;


int Input(city* cities); // функція заповнення масиву структур 
int Percent(int counter, city* cities); //розрахування відсотку
void printCity(int counter, city* cities); //функція роздруку таблиці

