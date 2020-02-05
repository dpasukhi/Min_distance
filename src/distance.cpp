    #include "..\include\distance.h"

straight_segment::straight_segment() :point_one(0.f, 0.f, 0.f), point_two(0.f, 0.f, 0.f)
{
}

straight_segment::straight_segment(float x, float y, float z, float x2, float y2, float z2) : point_one(x, y, z), point_two(x2, y2, z2)
{
}

straight_segment::straight_segment(point p1, point p2) : point_one(p1),point_two(p2)
{
}

point operator+(point p, vector v)
{
	return point(p.x+v.x,p.y+v.y,p.z+v.z);
}

point operator-(point p, vector v)
{
	return point(p.x - v.x, p.y - v.y, p.z - v.z);
}

vector operator-(point p, point v)
{
	return vector(p.x - v.x, p.y - v.y, p.z - v.z);
}

vector operator+(vector p, vector v)
{
	return vector(p.x + v.x, p.y + v.y, p.z + v.z);
}

vector operator-(vector p, vector v)
{
	return vector(p.x - v.x, p.y - v.y, p.z - v.z);
}

vector operator*(float sc, vector v)
{
	return vector(v.x*sc,v.y*sc,v.z*sc);
}

float distance_segment_to_segment(point S1_O, point S1_T, point S2_O, point S2_T)
{
    straight_segment S1(S1_O,S1_T);
    straight_segment S2(S2_O, S2_T);
    vector   u = S1.point_two - S1.point_one;
    vector   v = S2.point_two - S2.point_one;
    vector   w = S1.point_one - S2.point_one;
    float    a = dot(u, u);         // =|u|^2  always >= 0
    float    b = dot(u, v);         // sc mult
    float    c = dot(v, v);         // =|v|^2  always >= 0
    float    d = dot(u, w);         //sc mult
    float    e = dot(v, w);         //sc mult
    float    D = a * c - b * b;        // always >= 0
    float    sc, sN, sD = D;       // sc = sN / sD, default sD = D >= 0
    float    tc, tN, tD = D;       // tc = tN / tD, default tD = D >= 0
    if (D < SMALL_NUM) { // the lines are almost parallel
        sN = 0.0;         // force using point P0 on segment S1
        sD = 1.0;         // to prevent possible division by 0.0 later
        tN = e;
        tD = c;
    }
    else {                 // get the closest points on the infinite lines
        sN = (b * e - c * d);
        tN = (a * e - b * d);
        if (sN < 0.0) {        // sc < 0 => the s=0 edge is visible
            sN = 0.0;
            tN = e;
            tD = c;
        }
        else if (sN > sD) {  // sc > 1  => the s=1 edge is visible
            sN = sD;
            tN = e + b;
            tD = c;
        }
    }

    if (tN < 0.0) {            // tc < 0 => the t=0 edge is visible
        tN = 0.0;
        // recompute sc for this edge
        if (-d < 0.0)
            sN = 0.0;
        else if (-d > a)
            sN = sD;
        else {
            sN = -d;
            sD = a;
        }
    }
    else if (tN > tD) {      // tc > 1  => the t=1 edge is visible
        tN = tD;
        // recompute sc for this edge
        if ((-d + b) < 0.0)
            sN = 0;
        else if ((-d + b) > a)
            sN = sD;
        else {
            sN = (-d + b);
            sD = a;
        }
    }
    // finally do the division to get sc and tc
    sc = (abs(sN) < SMALL_NUM ? 0.0 : sN / sD);
    tc = (abs(tN) < SMALL_NUM ? 0.0 : tN / tD);

    // get the difference of the two closest points
    vector   dP = w + (sc * u) - (tc * v);  // =  S1(sc) - S2(tc)

    return norm(dP);   // return the closest distance
}
