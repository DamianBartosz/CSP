#include "Random.h"
#include <random>

int random::randInt(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

double random::randDouble(double min, double max) {
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}