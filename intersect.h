#pragma once

class Vector3D{    
public:
    double x;
    double y;
    double z;
    Vector3D();
    Vector3D(double x, double y, double z);

    bool operator==(const Vector3D& other);
};

class Segment3D{
public:
    Vector3D start;
    Vector3D end;
    Segment3D(Vector3D start, Vector3D end);
};


double distance(Vector3D a, Vector3D b);
Vector3D on_same_line(Segment3D seg1, Segment3D seg2, double alpha, double beta, double gamma);
Vector3D on_intersecting_lines(Segment3D seg, double t, double l);

Vector3D intersection(Segment3D seg1, Segment3D seg2);
