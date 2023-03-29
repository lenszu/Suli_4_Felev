#include <stdio.h>
#include <math.h>

int main()
{
    printf("Adj meg egy egesz szamot: ");
    int n;
    scanf("%d", &n);

    printf("A megadott szam: %d\n", n);
    printf("A megadott szam negyzete: %.0lf\n", pow(n, 2));
    printf("A megadott szam gyoke: %.2lf\n", sqrt(n));
    printf("A pi elore definialt erteke: %lf\n", M_PI);

    return 0;
}