#include <iostream>
#include <cassert>
#include <math.h>

#include "intersect.h"

void test_intersection(Segment3D seg1, Segment3D seg2, Vector3D expected){
    assert(intersection(seg1, seg2) == expected);
}

int main(){
    // segments, intersecting in (2,0,0)
    test_intersection(Segment3D(Vector3D(2,2,0), Vector3D(2,-2,0)),
        Segment3D(Vector3D(2,0,2), Vector3D(2,0,-2)),
        Vector3D(2,0,0));
    
    // segments, intersecting in (0,2,0)
    test_intersection(Segment3D(Vector3D(2,2,0), Vector3D(-2,2,0)),
        Segment3D(Vector3D(0,2,2), Vector3D(0,2,-2)),
        Vector3D(0,2,0));
    
    // segments, intersecting in (0,0,2)
    test_intersection(Segment3D(Vector3D(0,2,2), Vector3D(0,-2,2)),
        Segment3D(Vector3D(2,0,2), Vector3D(-2,0,2)),
        Vector3D(0,0,2));
    
    // segments, intersecting in (-2,-4,2)
    test_intersection(Segment3D(Vector3D(-2,-4,0), Vector3D(-2,-4,5)),
        Segment3D(Vector3D(0,-4,1), Vector3D(-4,-4,3)),
        Vector3D(-2,-4,2));
    
    // segments, intersecting in (2,3,1)
    test_intersection(Segment3D(Vector3D(0,1,-1), Vector3D(3,4,2)),
        Segment3D(Vector3D(4,4,1), Vector3D(0,2,1)),
        Vector3D(2,3,1));
    
    // non-intersecting segments
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,1,1)),
        Segment3D(Vector3D(2,3,4), Vector3D(2,2,2)),
        Vector3D(INFINITY, INFINITY, INFINITY));
    
    // non-intersecting segments, laying on intersecting lines
    test_intersection(Segment3D(Vector3D(0,1,-1), Vector3D(3,4,2)),
        Segment3D(Vector3D(6,5,1), Vector3D(4,4,1)),
        Vector3D(INFINITY, INFINITY, INFINITY));
    
    // segment and dot
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(3,2,1), Vector3D(3,2,1)),
        Vector3D(INFINITY, INFINITY, INFINITY));

    // segment and dot
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(2.5,2.5,2.5)),
        Vector3D(2.5,2.5,2.5));

    // different dots
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Segment3D(Vector3D(4,3,7), Vector3D(4,3,7)),
        Vector3D(INFINITY, INFINITY, INFINITY));

    // same dots (1,2,3)
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Segment3D(Vector3D(1,2,3), Vector3D(1,2,3)),
        Vector3D(1,2,3));

    // subsegment (2.5,2.5,2.5)
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(3.25,2.75,2.25)),
        Vector3D(2.5,2.5,2.5));

    // subsegment
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(4,3,2)),
        Segment3D(Vector3D(2.5,2.5,2.5), Vector3D(3.25,2.75,2.25)),
        Vector3D(2.5,2.5,2.5));

    // subsegment
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(5,5,5)),
        Segment3D(Vector3D(1,1,1), Vector3D(3,3,3)),
        Vector3D(1,1,1));

    // have same subsegment
    test_intersection(Segment3D(Vector3D(1,2,3), Vector3D(3.25,2.75,2.25)),
        Segment3D(Vector3D(4,3,2), Vector3D(2.5,2.5,2.5)),
        Vector3D(3.25,2.75,2.25));

    // have same subsegment
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(3,3,3)),
        Segment3D(Vector3D(1,1,1), Vector3D(5,5,5)),
        Vector3D(3,3,3));

    // on the same line, but have no intersection
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(1,1,1)),
        Segment3D(Vector3D(3,3,3), Vector3D(5,5,5)),
        Vector3D(INFINITY,INFINITY,INFINITY));

    // segment and dot, laying on the segment continuation
    test_intersection(Segment3D(Vector3D(0,0,0), Vector3D(3,3,3)),
        Segment3D(Vector3D(5,5,5), Vector3D(5,5,5)),
        Vector3D(INFINITY,INFINITY,INFINITY));
}
