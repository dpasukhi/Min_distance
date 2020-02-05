#include "..\include\distance.h"
#include "string"
using namespace std;
int main()
{
momo:
	cout << "Do you want to know the distance in 2D or in 3D?" << endl;
	cout << "Input 2 or 3 ";
	string input_num = "";
	float x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, z4, y4;
	cin >> input_num;
	if (!input_num.find(2)||!input_num.find(3))
		goto momo;
	if (input_num == "2")
	{
		cout << " Input  the first segment (x,y) & (x1,y1)" << endl;
		cout << "Input x ";
		cin >> x1;
		cout << "\nInput y ";
		cin >> y1;
		cout << "\nInput x1 ";
		cin >> x2;
		cout << "\nInput y1 ";
		cin >> y2;
		cout << " \n Input the second segment (x2,y2) & (x3,y3)" << endl;
		cout << "Input x2 ";
		cin >> x3;
		cout << "\nInput y2 ";
		cin >> y3;
		cout << "\nInput x3 ";
		cin >> x4;
		cout << "\nInput y3 ";
		cin >> y4;
		cout << endl;
		point p1(x1, y1, 0.f);
		point p2(x2, y2, 0.f);
		point p3(x3, y3, 0.f);
		point p4(x4, y4, 0.f);
		cout << "\nYout min distance is: " << distance_segment_to_segment(p1, p2, p3, p4) << endl;
	}
	else 
	{
		cout << " Input  the first segment (x,y,z) & (x1,y1,z1)" << endl;
		cout << "Input x ";
		cin >> x1;
		cout << "\nInput y ";
		cin >> y1;
		cout << "\nInput z ";
		cin >> z1;
		cout << "\nInput x1 ";
		cin >> x2; 
		cout << "\nInput y1 ";
		cin >> y2;
		cout << "\nInput z1 ";
		cin >> z2;
		cout << " \n Input the second segment (x2,y2,z2) & (x3,y3,z3)" << endl;
		cout << "Input x2 ";
		cin >> x3;
		cout << "\nInput y2 ";
		cin >> y3;
		cout << "\nInput z2 ";
		cin >> z3;
		cout << "\nInput x3 ";
		cin >> x4;
		cout << "\nInput y3 ";
		cin >> y4;
		cout << "\nInput z3 ";
		cin >> z4;
		cout << endl;		
		point p1(x1, y1, z1);
		point p2(x2, y2, z2);
		point p3(x3, y3, z3);
		point p4(x4, y4, z4);
		cout << "\nYout min distance is: "<< distance_segment_to_segment(p1, p2, p3, p4) << endl;
	}
	cout << "Repeat?(1/0)/(y/n) " << endl;
	string mind;
	cin >> mind;
	if (mind.find('y') || mind.find('Y') || mind.find('1'))
		goto momo;
	system("pause>nul");
	return 0;
}