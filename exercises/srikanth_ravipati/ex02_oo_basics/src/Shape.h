#define _USE_MATH_DEFINES

#include <iostream>
#include "cmath"

class Shape{

    protected:
        std::string type;
        unsigned int nSides;
        double perimeter;
        double area;

    public:

        Shape(const std::string&, const unsigned int&);

        virtual void calculatePerimeter(){}
        virtual void calculateArea(){}
        void calculateInfo();

        std::string getType() const {return type;}
        unsigned int get_N_Sides() const {return nSides;}
        double getPerimeter() const { return perimeter; }
        double getArea() const { return area; }

        bool isSameType(const std::string& inputType) const { return type == inputType;}
        bool hasEqual_N_Sides(const int& input_N_Sides) const { return nSides == input_N_Sides;}

        void printInfo() const;
};

class Rectangle : public Shape{

    private:
        double side1, side2;

    public:
        Rectangle(const std::string&, const unsigned int&, const double&, const double&);
        void calculatePerimeter() override { perimeter = 2 * (side1 + side2); }
        void calculateArea() override { area = side1 * side2; }
};

class Circle : public Shape{

    private:
        double radius;

    public:
        Circle(const std::string&, const unsigned int&, const double&);
        void calculatePerimeter() override { perimeter = 2.0 * M_PI * radius; }
        void calculateArea() override { area = M_PI * radius  * radius; }
};

class Triangle : public Shape{

    private:
        double base, height;

    public:
        Triangle(const std::string& inputType, const unsigned int&, const double&, const double&);
        void calculatePerimeter() override { perimeter = base + 2 * sqrt(height * height + (base * base) / 4); }
        void calculateArea() override { area = 0.5 * base * height; }
};