#include <iostream>
#include <cassert>
#include <math.h>

#include "intersect.h"

void test_intersection(Segment3D seg1, Segment3D seg2, Vector3D expected){
    assert(intersection(seg1, seg2) == expected);
}

int main(){
    // отрезки, пересекающиеся в (2,0,0)
    test_intersection(Segment3D(Vector3D(2,2,0), Vector3D(2,-2,0)),
        Segment3D(Vector3D(2,0,2), Vector3D(2,0,-2)),
        Vector3D(2,0,0));
    
    // отрезки, пересекающиеся в (0,2,0)
    test_intersection(Segment3D(Vector3D(2,2,0), Vector3D(-2,2,0)),
        Segment3D(Vector3D(0,2,2), Vector3D(0,2,-2)),
        Vector3D(0,2,0));
    
    // отрезки, пересекающиеся в (0,0,2)
    test_intersection(Segment3D(Vector3D(0,2,2), Vector3D(0,-2,2)),
        Segment3D(Vector3D(2,0,2), Vector3D(-2,0,2)),
        Vector3D(0,0,2));
    
    // отрезки, пересекающиеся в (-2,-4,2)
    test_intersection(Segment3D(Vector3D(-2,-4,0), Vector3D(-2,-4,5)),
        Segment3D(Vector3D(0,-4,1), Vector3D(-4,-4,3)),
        Vector3D(-2,-4,2));
    
    // отрезки, пересекающиеся в (2,3,1)
    test_intersection(Segment3D(Vector3D(0,1,-1), Vector3D(3,4,2)),
        Segment3D(Vector3D(4,4,1), Vector3D(0,2,1)),
        Vector3D(2,3,1));
    
    // непересекающиеся прямые
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,1,1)),
        Segment3D(Vector3D(2,3,4), Vector3D(2,2,2)),
        Vector3D(INFINITY, INFINITY, INFINITY));
    
    // непересекающиеся отрезки, лежащие на пересекающихся прямых
    test_intersection(Segment3D(Vector3D(0,1,-1), Vector3D(3,4,2)),
        Segment3D(Vector3D(6,5,1), Vector3D(4,4,1)),
        Vector3D(INFINITY, INFINITY, INFINITY));
    
    // отрезок и не лежащая на нем точка
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(3,2,1), Vector3D(3,2,1)),
        Vector3D(INFINITY, INFINITY, INFINITY));

    // отрезок и лежащая на нем точка
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(2.5,2.5,2.5)),
        Vector3D(2.5,2.5,2.5));

    // несовпадающие точки
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Segment3D(Vector3D(4,3,7), Vector3D(4,3,7)),
        Vector3D(INFINITY, INFINITY, INFINITY));

    // совпадающие точки (1,2,3)
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Vector3D(1,2,3));

    // подотрезок, возвращаем (2.5,2.5,2.5)
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(3.25,2.75,2.25)),
        Vector3D(2.5,2.5,2.5));

    // подотрезок
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(3.25,2.75,2.25)),
        Vector3D(2.5,2.5,2.5));

    // подотрезок
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(5,5,5)),
        Segment3D(Vector3D(1,1,1), Vector3D(3,3,3)),
        Vector3D(1,1,1));

    // пересекаются по отрезку
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(3.25,2.75,2.25)),
        Segment3D(Vector3D(4,3,2), Vector3D(2.5,2.5,2.5)),
        Vector3D(3.25,2.75,2.25));

    // пересекаются по отрезку
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(3,3,3)),
        Segment3D(Vector3D(1,1,1), Vector3D(5,5,5)),
        Vector3D(3,3,3));

    // коллинеарны, но не пересекаются
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(1,1,1)),
        Segment3D(Vector3D(3,3,3), Vector3D(5,5,5)),
        Vector3D(INFINITY,INFINITY,INFINITY));

    // отрезок и точка, лежащая на его продолжении
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(3,3,3)),
        Segment3D(Vector3D(5,5,5), Vector3D(5,5,5)),
        Vector3D(INFINITY,INFINITY,INFINITY));
}
