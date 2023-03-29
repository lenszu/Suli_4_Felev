#include <stdio.h>
#include <math.h>

// Irjunk fuggvenyt, amely kiszamolja ketto db pont tavolsagat.

typedef struct
{
    int x;
    int y;
} Pont;

double distance(Pont a, Pont b);

int main()
{
    Pont a;
    a.x = 4;
    a.y = 6;

    Pont b;
    b.x = 1;
    b.y = 9;

    printf("A ket pont tavolsaga: %.2lf", distance(a, b));

    return 0;
}

double distance(Pont a, Pont b)
{
    return sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
}
