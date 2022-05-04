#include <stdio.h>
#include <math.h>

#define PI 3.1415927

double Agn_W(double x);
double Q_Hyp(double x);
double L_Ber(double x);

int main() {
    for (int i = 0; i < 42; i++) {
        double x = -PI + i * 2 * PI / 41;
        char line[255];
        if (x >= 0 && x < 1.45) {
            printf("%.7lf|%.7lf|%.7lf|%.7lf|\n", x, Agn_W(x), L_Ber(x), Q_Hyp(x));
        } else {
            printf("%.7lf|%.7lf| - |%.7lf|\n", x, Agn_W(x), Q_Hyp(x));
        }
    }
    return 0;
}

double Agn_W(double x) {
    return 1 / (1 + x * x);
}

double Q_Hyp(double x) {
    return 1 / (x * x);
}

double L_Ber(double x) {
    return sqrt(sqrt(1 + 4 * x * x) - x * x - 1);
}
