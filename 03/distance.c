#include <stdio.h>

typedef struct point {
    double x;
    double y;
} Point;

double distance(Point p, Point q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    Point p = {1, 2};
    Point q = {4, 6};

    printf("Distance between p and q: %f\n", distance(p, q));
}