#pragma once
#include <iostream>


#define SMALL_NUM   0.00000001 // anything that avoids division overflow
#define dot(u,v)   ((u).x * (v).x + (u).y * (v).y + (u).z * (v).z) //Scalar product of vectors
#define norm(v)    sqrt(dot(v,v))  // length of  vector
#define abs(x)     ((x) >= 0 ? (x) : -(x))   //  absolute value

using namespace std;

struct point
{
	float x;
	float y;
	float z;
	point(float x, float y, float z) :x(x), y(y), z(z) {};
};
struct vector
{
	float x;
	float y;
	float z;
	vector(float x, float y, float z) :x(x), y(y), z(z) {};
};
struct track
{
	point po;
	vector v;
};
class straight_segment
{
	point point_one;
	point point_two;
public:
	straight_segment(); 
	straight_segment(float x, float y, float z, float x2, float y2, float z2);
	straight_segment(point p1, point p2);
	friend point operator+(point p, vector v);
	friend point operator-(point p, vector v);
	friend vector operator-(point p, point v);
	friend vector operator+(vector p, vector v);
	friend vector operator-(vector p, vector v);
	friend vector operator*(float sc, vector v);
	friend float distance_segment_to_segment(point S1_O, point S1_T, point S2_O, point S2_T);
};
