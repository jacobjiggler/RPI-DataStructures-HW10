#include <vector>
#include "polygons.h"

using namespace std;


//polygon checker
bool Polygon::isNotPolygon(const vector<Point> & vertices) {
//checks to see if 3 points are in a direct line which would make the whole class invalid by allowing you to creat triangles with 4 points.
    if((vertices[vertices.size()-1].x == vertices[0].x && vertices[vertices.size()-1].x == vertices[vertices.size()-2].x) || (vertices[vertices.size()-1].y == vertices[0].y && vertices[vertices.size()-1].y == vertices[vertices.size()-2].y) || vertices.size() < 3)
        return true;
    if((vertices[0].x == vertices[1].x && vertices[0].x == vertices[vertices.size()-1].x) || (vertices[0].y == vertices[1].y && vertices[0].y == vertices[vertices.size()-1].y))
        return true;
//goes through all points next to each other to check
    for (int i = 1; i < vertices.size() - 1; i++) {
        if((vertices[i].x == vertices[i+1].x && vertices[i].x == vertices[i-1].x) || (vertices[i].y == vertices[i+1].y && vertices[i].y == vertices[i-1].y))
            return true;
    }
    return false;
}

bool Polygon::HasARightAngle() {
//checks all angles to see if they are right
    if(RightAngle(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]))) {
        return true;
    }
    if(RightAngle(Angle(vertices[0],vertices[vertices.size()-1],vertices[vertices.size()-2]))) {
        return true;
    }
    for (int i = 1; i < vertices.size() - 1; i++) {
        if(RightAngle(Angle(vertices[i-1],vertices[i],vertices[i+1]))) {
            return true;
        }
    }
    return false;
}

bool Polygon::HasAllEqualSides() {
//checks all sies to see if they are all equal
    for(int i = 1; i < vertices.size(); i++) {
        if(!EqualSides(DistanceBetween(vertices[vertices.size()-1],vertices[0]),DistanceBetween(vertices[i],vertices[i-1])))
            return false;
    }
    return true;
}

bool Polygon::HasAllEqualAngles() {
//checks all angles to see if they are all equal
    if(!EqualAngles(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]),Angle(vertices[vertices.size()-2],vertices[vertices.size()-1],vertices[0])))
        return false;
    for (int i = 1; i < vertices.size() - 1; i++) {
        if(!EqualAngles(Angle(vertices[vertices.size()-1],vertices[0],vertices[1]),Angle(vertices[i-1],vertices[i],vertices[i+1])))
            return false;
    }
    return true;
}

bool Triangle::isNotTriangle(const vector<Point> & vertices) {
//checks to see if there are 3 points
    if(vertices.size() != 3) {
        return true;
    }
    return false;
}


bool IsoscelesTriangle::isNotIsoscelesTriangle(const vector<Point> & vertices) {
//checks to see if at least 2 of the 3 sides are the same
    if(!(EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[1],vertices[2])) || EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[0],vertices[2])) || EqualSides(DistanceBetween(vertices[0],vertices[2]),DistanceBetween(vertices[1],vertices[2])))) {
        return true;
    }
    return false;
}

bool EquilateralTriangle::isNotEquilateralTriangle(const vector<Point> & vertices) {
//checks if every side is equal
    if((!EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[1],vertices[2]))) || (!EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[0],vertices[2])))) {
        return true;
    }
    return false;
}

bool Quadrilateral::isNotQuadrilateral(const vector<Point> & vertices) {
//just checks if size isnt 4
    if(vertices.size() != 4) {
        return true;
    }
    return false;
}

bool Kite::isNotKite(const vector<Point> & vertices) {
//checks if sides next to each other have the same length
    if(!((EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[3],vertices[0])) && EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[2],vertices[3]))) || (EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[1],vertices[2])) && EqualSides(DistanceBetween(vertices[2],vertices[3]),DistanceBetween(vertices[3],vertices[0])))) ) {
        return true;
    }
    return false;
}

bool Trapezoid::isNotTrapezoid(const vector<Point> & vertices) {
//checks if at least one side is parallel
    if(!(Parallel(Vector(vertices[0],vertices[1]),Vector(vertices[2],vertices[3])) || Parallel(Vector(vertices[1],vertices[2]),Vector(vertices[3],vertices[0])))) {
        return true;
    }
    return false;
}

bool Parallelogram::isNotParallelogram(const vector<Point> & vertices) {
//check if both sides are parallel 
    if(!(Parallel(Vector(vertices[0],vertices[1]),Vector(vertices[2],vertices[3])) && Parallel(Vector(vertices[1],vertices[2]),Vector(vertices[3],vertices[0])))) {
        return true;

    }
//check if parallel sides are equal
        if(!((EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[2],vertices[3]))) && (EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[3],vertices[0])))))  {
            return true;
        }


    return false;
}


bool Rhombus::isNotRhombus(const vector<Point> & vertices) {
//checks if all sides have equal lengths
    if(!EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[2],vertices[3])) || !EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[0],vertices[3])) || !EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[0],vertices[1])))  {
        return true;
    }
    return false;
}

bool IsoscelesTrapezoid::isNotIsoscelesTrapezoid(const vector<Point> & vertices) {

//checks if all base angles are the same
if(EqualAngles(Angle(vertices[0],vertices[1],vertices[2]),Angle(vertices[1],vertices[2],vertices[3])) && EqualAngles(Angle(vertices[2],vertices[3],vertices[0]),Angle(vertices[3],vertices[0],vertices[1]))){
        return false;
		}

	if((EqualSides(DistanceBetween(vertices[1],vertices[2]),DistanceBetween(vertices[0],vertices[3])) && Parallel(Vector(vertices[0],vertices[1]),Vector(vertices[2],vertices[3]))) && (EqualAngles(Angle(vertices[3],vertices[0],vertices[1]),Angle(vertices[0],vertices[1],vertices[2])) && EqualAngles(Angle(vertices[1],vertices[2],vertices[3]),Angle(vertices[2],vertices[3],vertices[0])))) {
return false;
	}
	
	 if((EqualSides(DistanceBetween(vertices[0],vertices[1]),DistanceBetween(vertices[2],vertices[3])) && Parallel(Vector(vertices[1],vertices[2]),Vector(vertices[3],vertices[0]))) && (EqualAngles(Angle(vertices[0],vertices[1],vertices[2]),Angle(vertices[1],vertices[2],vertices[3])) && EqualAngles(Angle(vertices[2],vertices[3],vertices[0]),Angle(vertices[3],vertices[0],vertices[1])))){
		return false;
    }
	
    return true;
}