/*
 It is easily proved that no equilateral triangle exists with integral length sides and integral area. However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

 We shall define an almost equilateral triangle to be a triangle for which two sides are equal and the third differs by no more than one unit.

 Find the sum of the perimeters of all almost equilateral triangles with integral side lengths and area and whose perimeters do not exceed one billion (1,000,000,000).
 */
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long int sum = 0;
    for (int side = 2; side<=333333333; side++){
        double area = (1/double(2)) * sqrt( (pow(side,2) - pow((side+1)/double(2),2))) * (side+1);
        if (area == long(area)){
            //cout << side << " " << side << " " << side + 1 << endl;
            sum += (side*2 + side+1);
            //cout << "area: " << area << endl;
            //cout << "---------" << endl;
        }
    }
    cout << "sum of the perimeters of triangles is " << sum << endl;
}


/*
int main(){
    long long int sum = 0;
    for (int side = 2; side<=333333333; side++){
        double area = sqrt( (pow(side,2) - pow((side+1)/double(2),2)));
        if (area == long(area)){
            cout << side << " " << side << " " << side + 1 << endl;
            sum += (3*side + 1);
            //cout << "area: " << area << endl;
            //cout << "---------" << endl;
        }
    }
    cout << "sum of the perimeters of triangles is " << sum << endl;
}
*/
