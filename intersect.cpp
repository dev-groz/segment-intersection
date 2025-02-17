#include "intersect.h"
#include "math.h"

Vector3D::Vector3D(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
}
Vector3D::Vector3D(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}
    
bool Vector3D::operator==(const Vector3D& other)
{
    return this->x == other.x && this->y == other.y && this->z == other.z;
}

Segment3D::Segment3D(Vector3D start, Vector3D end){
    this->start = start;
    this->end = end;
}

double distance(Vector3D a, Vector3D b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)); 
}

Vector3D on_same_line(Segment3D seg1, Segment3D seg2, double alpha, double beta, double gamma){
    if (0 <= -gamma/beta && -gamma/beta <= 1) { // t == 0
        return seg1.start;
    }
    if (0 <= -(gamma - alpha)/beta && -(gamma - alpha)/beta <= 1) { // t == 1
        return seg1.end;
    }
    if (0 <= gamma/alpha && gamma/alpha <= 1) { // l == 0
        return seg2.start;
    }
    if (0 <= (gamma + beta)/alpha && (gamma + beta)/alpha <= 1) { // l == 1
        return seg2.end;
    }
    return Vector3D(INFINITY, INFINITY, INFINITY);
}

Vector3D on_intersecting_lines(Segment3D seg, double t, double l) {
    if (0 <= t && t <= 1 && 0 <= l && l <= 1) {
        double x = seg.start.x + (seg.end.x - seg.start.x) * t;
        double y = seg.start.y + (seg.end.y - seg.start.y) * t;
        double z = seg.start.z + (seg.end.z - seg.start.z) * t;
        return Vector3D(x, y, z);
    }
    return Vector3D(INFINITY, INFINITY, INFINITY);
}

Vector3D intersection(Segment3D seg1, Segment3D seg2) {
    bool firstSegmentIsDot = (seg1.start == seg1.end);
    bool secondSegmentIsDot = (seg2.start == seg2.end);

    if (firstSegmentIsDot && secondSegmentIsDot) {
        if (seg1.start == seg2.start) {
            return seg1.start;
        }
        return Vector3D(INFINITY, INFINITY, INFINITY);
    }

    if (firstSegmentIsDot) {
        if (distance(seg1.start, seg2.start) + distance(seg1.end, seg2.end) == distance(seg2.start, seg2.end)){
            return seg1.start;
        }
        return Vector3D(INFINITY, INFINITY, INFINITY); 
    }

    if (secondSegmentIsDot) {
        if (distance(seg1.start, seg2.start) + distance(seg1.end, seg2.end) == distance(seg1.start, seg1.end)){
            return seg2.start;
        }
        return Vector3D(INFINITY, INFINITY, INFINITY); 
    }
    
    double alphax = seg1.end.x - seg1.start.x;
    double alphay = seg1.end.y - seg1.start.y;
    double alphaz = seg1.end.z - seg1.start.z;
    
    double betax = seg2.end.x - seg2.start.x;
    double betay = seg2.end.y - seg2.start.y;
    double betaz = seg2.end.z - seg2.start.z;
    
    double gammax = seg2.start.x - seg1.start.x;
    double gammay = seg2.start.y - seg1.start.y;
    double gammaz = seg2.start.z - seg1.start.z;

    if (alphax == 0 && betax == 0) {
        if (gammax != 0) {
            return Vector3D(INFINITY, INFINITY, INFINITY);
        }
        if (alphay == 0 && betay == 0) {
            if (gammay != 0) {
                return Vector3D(INFINITY, INFINITY, INFINITY);
            }
            return on_same_line(seg1, seg2, alphaz, betaz, gammaz);
        }
        if (betay == 0) {
            double t = gammay/alphay;
            double l = -(gammaz - alphaz * t)/(betaz);
            return on_intersecting_lines(seg1, t, l);
        }
        if (alphay == 0) {
            double l = -gammay/betay;
            double t = (gammaz + betaz*l)/alphaz;
            return on_intersecting_lines(seg1, t, l);
        }
        double l = -(gammaz - alphaz/alphay*betay)/(betaz - alphaz/alphay*betay);
        double t = (gammay + betay*l)/alphay;
        return on_intersecting_lines(seg1, t, l);
    }

    if (alphax == 0) {
        double l = -gammax/betax;
        if (alphay == 0) {
            double t = (gammaz - betaz*l)/alphaz;            
            return on_intersecting_lines(seg2, l, t);
        }
        if (alphaz == 0) {
            double t = (gammay - betay*l)/alphay;
            return on_intersecting_lines(seg2, l, t);
        }
        double ty = (gammay + betay * l)/alphay;
        double tz = (gammaz + betaz * l)/alphaz;

        if (ty != tz) {
            return Vector3D(INFINITY, INFINITY, INFINITY);
        }
        return on_intersecting_lines(seg1, ty, l);
    }

    bool notDependsOnLY = (betay - alphay/alphax * betax == 0);
    bool notDependsOnLZ = (betaz - alphaz/alphax * betax == 0);

    if (notDependsOnLY && notDependsOnLZ) {
        if (gammay - alphay/alphax*gammax == 0 && gammaz - alphaz/alphax*gammax == 0) {
            return on_same_line(seg1, seg2, alphax, betax, gammax);
        }
        return Vector3D(INFINITY, INFINITY, INFINITY);  
    }

    if (notDependsOnLY) {
        if (gammay - alphay/alphax*gammax != 0){
            return Vector3D(INFINITY, INFINITY, INFINITY);
        }
        double lz = -(gammaz - alphaz/alphax * gammax)/(betaz - alphaz/alphax * betax);
        double t = (gammax + betax * lz) / alphax;
        return on_intersecting_lines(seg1, t, lz);
    }

    if (notDependsOnLZ) {
        if (gammaz - alphaz/alphax*gammax != 0){
            return Vector3D(INFINITY, INFINITY, INFINITY);
        }
        double ly = -(gammay - alphay/alphax * gammax)/(betay - alphay/alphax * betax);
        double t = (gammax + betax * ly) / alphax;
        return on_intersecting_lines(seg1, t, ly);
    }

    double lz = -(gammaz - alphaz/alphax * gammax)/(betaz - alphaz/alphax * betax);
    double ly = -(gammay - alphay/alphax * gammax)/(betay - alphay/alphax * betax);

    if (lz != ly) {
        return Vector3D(INFINITY, INFINITY, INFINITY);
    }

    double t = (gammax + betax * lz) / alphax;
    return on_intersecting_lines(seg1, t, ly);
}
