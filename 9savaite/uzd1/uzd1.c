#include <stdio.h>
#include <math.h>

typedef struct Point {
    double x;
    double y;
} Point;

Point createPoint(double x, double y) {
    return (Point){ x, y };
}

double getDistance(Point a, Point b) {
    return sqrt( (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y) );
}

void printPoint(Point p) {
    printf("(%f, %f)", p.x, p.y);
}

int main() {
    /*
    Point p1 = createPoint(2.0, -3.0);
    Point p2 = createPoint(-4.0, 5.0);
    
    printPoint(p1);
    printf("\n");
    printPoint(p2);
    */

    printf("\n%f", getDistance(createPoint(2.0, -3.0), createPoint(-4.0, 5.0)));

    return 0;
}