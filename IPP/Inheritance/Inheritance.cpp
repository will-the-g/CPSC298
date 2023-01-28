#include <iostream>
#include <math.h>
using namespace std;

class Shape{

public:
    Shape(double dHeight, double dWidth){
        double m_dHeight = dHeight;
        double m_dWidth = dWidth;
    };
    virtual ~Shape(){}
    virtual void scale(double dScaleFactor) = 0;
    virtual double area() = 0;
    virtual double perimeter() = 0;
    virtual void displayProperties(){}
protected:
    double m_dHeight;
    double m_dWidth;
    string m_strType;
};
class Rectangle : public Shape {
    double m_dHeight;
    double m_dWidth;
public:
    Rectangle(double dHeight, double dWidth) : Shape(m_dHeight, m_dWidth){
        m_dHeight = dHeight;
        m_dWidth = dWidth;
    }
    virtual ~Rectangle(){}
    void displayProperties(){
        cout << "Shape Type: Rectangle, height: " << m_dHeight << ", width: " << m_dWidth << endl;
    }
    void scale(double dScaleFactor){
        m_dHeight *= dScaleFactor;
        m_dWidth *= dScaleFactor;
    }
    double area(){
        return m_dHeight * m_dWidth;
    }
    double perimeter(){
        return (2.0 * m_dHeight + 2.0 * m_dWidth);
    }
};
class Circle : public Shape {
    double m_dWidth;
    double m_dHeight;
public:
    Circle(double dHeight, double dWidth) : Shape(m_dHeight, m_dWidth){
        m_dHeight = dHeight;
        m_dWidth = dWidth;
    }
    virtual ~Circle(){}
    void displayProperties(){
        cout << "Shape Type: Circle, height: " << m_dHeight << ", width: " << m_dWidth << endl;
    }
    void scale(double dScaleFactor){
        m_dHeight *= dScaleFactor;
        m_dWidth *= dScaleFactor;
    }
    double area(){
        return M_PI * pow((m_dHeight / 2.0), 2);
    }
    double perimeter(){
        return M_PI * m_dHeight;
    }
};


int main(){
    Rectangle* p_shapeRectangle = new Rectangle(2.0, 3.0);
    Circle* p_shapeCircle = new Circle(2.0, 2.0);
    Shape* p_shapes[2];
    p_shapes[0] = p_shapeCircle;
    p_shapes[1] = p_shapeRectangle;

    for (int i = 0; i < 2; i++){
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area();
        cout << ", Perimeter: " << p_shapes[i]->perimeter() << endl;
        p_shapes[i]->scale(2.0);
        p_shapes[i]->displayProperties();
        cout << "Area: " << p_shapes[i]->area();
        cout << ", Perimeter: " << p_shapes[i]->perimeter() << endl;
    }
    delete p_shapes[0];
    delete p_shapes[1];
    return 0;
}