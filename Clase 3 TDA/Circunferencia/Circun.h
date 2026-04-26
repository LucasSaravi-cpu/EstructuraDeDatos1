#ifndef CIRCUN_H_INCLUDED
#define CIRCUN_H_INCLUDED
typedef struct{
    float x,y;
}punto;
typedef struct {
    float r;
    punto centro;
}Circun;
float distancia(punto,punto);
float superf(Circun);
float perimetro(Circun);
void inclu(Circun,Circun);
void ingresaC(Circun *);

#endif // CIRCUN_H_INCLUDED
