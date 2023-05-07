#include <stdio.h>
#include <string.h>

#define MAX_CIUDADES 10

typedef struct {
    char ciudad[20];
    int superficie;
    long canHabitantes;
} Treg;

void cantDensidad(char max[], char min[], Treg ciudades[]);
void ingresaDatos();

int main() {
    CreoArchivo();
    Treg ciudades[MAX_CIUDADES];
    ingresaDatos(ciudades);

    char maxInicial, minInicial;
    cantDensidad(&maxInicial, &minInicial, ciudades);
    printf("La ciudad con mayor densidad de habitantes es %c y la de menor cantidad es %c", maxInicial, minInicial);

    return 0;
}



void  CreoArchivo(){
    FILE * archb;
    int n,i;
    Treg reg;
    archb=fopen("ejercicio21.dat", "wb");   // Se abre para lectura y escritura

    printf("Ingrese la cantidad de ciudades ");
    scanf("%d",&n);


    for (i=0; i<n; i++){
        printf("ingrese nombre de la ciudad ");
        fflush(stdin);
        gets(reg.ciudad);
        printf("ingrese la superficie");
        fflush(stdin);
        scanf("%d", &reg.superficie);
        printf("ingrese la cantidad de habitantes");
        fflush(stdin);
        scanf("%d", &reg.canHabitantes);

        fwrite(&reg, sizeof(Treg), 1, archb); // Se escribe en el archivo
    }
    fclose(archb);
}

void cantDensidad(char* maxInicial, char* minInicial, Treg ciudades[]) {
    float maxn, minn;
    Treg reg;
    reg = ciudades[0];
    minn = maxn = (float) reg.canHabitantes / reg.superficie;
    *maxInicial = reg.ciudad[0];
    *minInicial = reg.ciudad[0];

    for (int i = 1; i < MAX_CIUDADES; i++) {
        reg = ciudades[i];
        float densidad = (float) reg.canHabitantes / reg.superficie;
        if (densidad > maxn) {
            maxn = densidad;
            *maxInicial = reg.ciudad[0];
        } else if (densidad < minn) {
            minn = densidad;
            *minInicial = reg.ciudad[0];
        }
    }
}

void ingresaDatos(Treg ciudades[]) {
    FILE *archb;
    archb = fopen("ejercicio21.dat", "rb");

    if (!archb) {
        printf("Error al abrir el archivo");
        return;
    }

    fread(ciudades, sizeof(Treg), MAX_CIUDADES, archb);
    fclose(archb);
}

/*México superficie de 1,485 km² y una población de 8.9 millones de habitantes

Nueva York superficie de 468.9 km² y una población de 8.3 millones de habitantes.

Tokio  superficie de 2,194 km² y una población de 13.5 millones de habitantes.

São Paulo superficie de 1,521 km² y una población de 12.3 millones de habitantes.

Bombay superficie de 603.4 km² y una población de 20.7 millones de habitantes.

Shanghái superficie de 6,341 km² y una población de 24.2 millones de habitantes.

Moscú superficie de 2,511 km² y una población de 12.5 millones de habitantes.

París superficie de 105.4 km² y una población de 2.1 millones de habitantes.

Madrid superficie de 604.3 km² y una población de 3.3 millones de habitantes.

Estambul  superficie de 5,343 km² y una población de 15.5 millones de habitantes.

Roma: superficie de 1,285 km² y una población de 2.8 millones de habitantes. */
