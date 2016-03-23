#ifndef _polygons_h_
#define _polygons_h_
#include <vector>
#include <string>
#include <cmath>
#include "utilities.h"

class Polygon {

public:

    // CONSTRUCTOR
    Polygon(const std::string & n, const std::vector<Point> & vert) {
	//values set
        vertices = vert;
        name = n;
		//check to see if closed bounded object
        if(isNotPolygon(vertices)) {
		//if not throw a int
            throw(1);
        }


    }

	//deconstructer
    virtual ~Polygon() {}


    // ACCESSORS
	//name retriever
    const std::string& getName() const {
        return name;
    }
	
	//right angle check
    bool HasARightAngle();



//checks if all the sides are equal
    bool HasAllEqualSides();

	//checks if all the angles are equal
    bool HasAllEqualAngles();

protected:
//protected so thos that inherit it can call it

    // REPRESENTATION
    std::string name;
    std::vector<Point> vertices;

    //Polygon Check
    bool isNotPolygon(const std::vector<Point> & vertices);

};

//inherits the member functions and variables of a Polygon
class Triangle : public Polygon {
public:
//constructor
    Triangle(const std::string & n, const std::vector<Point> & vert) : Polygon(n,vert) {
	//check to see if it is a triangle
        if(isNotTriangle(vertices)) {
            throw(2);
        }
    }

//deconstructer
    virtual ~Triangle() {}

protected:
    bool isNotTriangle(const std::vector<Point> & vertices);

};


//virtual Triangle because the possibility of a right Isosceles Triangle would create 2 without the virtual call
class RightTriangle : public virtual Triangle {
public:
//constructor
    RightTriangle(const std::string & n, const std::vector<Point> & vert) : Triangle(n,vert)  {
        name = n;
        vertices = vert;
        if(!HasARightAngle()) {
            throw(3);
        }
    }


    virtual ~RightTriangle() {}

};

class IsoscelesTriangle : public virtual Triangle {
public:
//constructor
    IsoscelesTriangle(const std::string & n, const std::vector<Point> & vert) : Triangle(n,vert) {
        name = n;
        vertices = vert;
        if(isNotIsoscelesTriangle(vertices))
            throw(4);
    }



    virtual ~IsoscelesTriangle() {}

protected:
    bool isNotIsoscelesTriangle(const std::vector<Point> & vertices);
};

class EquilateralTriangle : public IsoscelesTriangle {
public:
//constructor
    EquilateralTriangle(const std::string & n, const std::vector<Point> & vert) : Triangle(n,vert), IsoscelesTriangle(n,vert) {
        name = n;
        vertices = vert;
      
        if(isNotEquilateralTriangle(vertices)) {
            throw(5);
        }
    }


    virtual ~EquilateralTriangle() {}

protected:
    bool isNotEquilateralTriangle(const std::vector<Point> & vertices);

};

class IsoscelesRightTriangle : public RightTriangle, public IsoscelesTriangle {
public:
//constructor
    IsoscelesRightTriangle(const std::string & n, const std::vector<Point> & vert) : Triangle(n,vert), RightTriangle(n,vert), IsoscelesTriangle(n,vert) {
        name = n;
        vertices = vert;
        //previous checks already done
    }
    virtual ~IsoscelesRightTriangle() {}

};


class Quadrilateral : public Polygon {
public:
//constructor
    Quadrilateral(const std::string & n, const std::vector<Point> & vert) : Polygon(n,vert)  {

        if(isNotQuadrilateral(vertices)) {
            throw(7);
        }
    }
    virtual ~Quadrilateral() {}

protected:
    bool isNotQuadrilateral(const std::vector<Point> & vertices);
};

class Kite : public virtual Quadrilateral {
public:
//constructor
    Kite(const std::string & n, const std::vector<Point> & vert) :  Quadrilateral(n,vert)  {
        name = n;
        vertices = vert;
        if(isNotKite(vertices)) {
            throw(8);
        }
    }
    virtual ~Kite() {}

protected:
    bool isNotKite(const std::vector<Point> & vertices);
};

class Trapezoid : public virtual Quadrilateral {
public:
//constructor
    Trapezoid(const std::string & n, const std::vector<Point> & vert) :  Quadrilateral(n,vert)  {
        name = n;
        vertices = vert;
        
        if(isNotTrapezoid(vertices)) {
            throw(9);
        }
    }
    virtual ~Trapezoid() {}

protected:
    bool isNotTrapezoid(const std::vector<Point> & vertices);

};

class Parallelogram : public virtual Trapezoid {
public:
//constructor
    Parallelogram(const std::string & n, const std::vector<Point> & vert) : Quadrilateral(n,vert), Trapezoid(n,vert)  {
        name = n;
        vertices = vert;
        if(isNotParallelogram(vertices)) {
            throw(10);
        }
    }
    virtual ~Parallelogram() {}

protected:
    bool isNotParallelogram(const std::vector<Point> & vertices);
};

class Rhombus : public Kite, public virtual Parallelogram {
public:
//constructor
    Rhombus(const std::string & n, const std::vector<Point> & vert) :  Quadrilateral(n,vert), Trapezoid(n,vert), Kite(n,vert), Parallelogram(n,vert)  {
        name = n;
        vertices = vert;
        if(isNotRhombus(vertices)) {
            throw(11);
        }
    }



    virtual ~Rhombus() {}

protected:
    bool isNotRhombus(const std::vector<Point> & vertices);

};

class IsoscelesTrapezoid : public virtual Trapezoid {
public:
//constructor
    IsoscelesTrapezoid(const std::string & n, const std::vector<Point> & vert) : Quadrilateral(n,vert), Trapezoid(n,vert)  {
        name = n;
        vertices = vert;
        if(isNotIsoscelesTrapezoid(vertices)) {
            throw(12);
        }
    }
    virtual ~IsoscelesTrapezoid() {}

protected:

    bool isNotIsoscelesTrapezoid(const std::vector<Point> & vertices);

};

class Rectangle : public IsoscelesTrapezoid, public virtual Parallelogram {
public:
//constructor
    Rectangle(const std::string & n, const std::vector<Point> & vert) : Quadrilateral(n,vert), Trapezoid(n,vert), Parallelogram(n,vert), IsoscelesTrapezoid(n,vert)  {
        name = n;
        vertices = vert;
        if(!(HasAllEqualAngles() && HasARightAngle())) {
            throw(13);
        }
    }


    virtual ~Rectangle() {}
};

class Square : public Rhombus, public Rectangle {
public:
//constructor
    Square(const std::string & n, const std::vector<Point> & vert) : Quadrilateral(n,vert), Parallelogram(n,vert), Trapezoid(n,vert), Rhombus(n,vert), Rectangle(n,vert)  {
        name = n;
        vertices = vert;
        //no need to check. Already done for by inherited classes./ Rhombus and Rectangle
    }
    virtual ~Square() {}

};


#endif
