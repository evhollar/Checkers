//
// Created by Lisa Dion on 10/10/17.
//

#ifndef CS120B_SHAPES_SHAPES_H
#define CS120B_SHAPES_SHAPES_H

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

class Shape {
public:
    // Constructors
    Shape();
    Shape(color f);
    Shape(point p);
    Shape(int x_in, int y_in);
    Shape(color f, point p);
    Shape(color f, int x_in, int y_in);
    Shape(const Shape &s); // copy constructor

    // Destructor
    ~Shape();

    // getters
    double get_area() const;
    double get_perimeter() const;
    color get_fill() const;
    point get_position() const;
    double get_x() const;
    double get_y() const;

    // setters
    void set_fill(color f);
    void set_fill(double r, double g, double b);
    void set_position(point p);
    void set_position(int x_in, int y_in);

    void move(int delta_x, int delta_y);

    // will add canvas parameter when we learn graphics
    // pure virtual (class is abstract)
    virtual void draw() const = 0;

protected:
    color fill;
    point position;
    // helper methods
    // pure virtual
    virtual double calculate_area() const = 0;
    virtual double calculate_perimeter() const = 0;
};

class Circle : public Shape {
public:
    // Constructors
    // will call calculate_area and calculate_perimeter
    Circle();
    Circle(double r);
    Circle(double r, color f);
    Circle(color f);

    // getter
    double get_radius() const;

    // setter
    // will call calculate_area and calculate_perimeter
    void set_radius(double r);

    void draw() const override;

    // detect if the circle is overlapping with a coordinate point
    bool is_overlapping(const point &p) const;
    bool is_overlapping(int x, int y) const;

    // detect if the circle is overlapping with another circle
    bool is_overlapping(const Circle &c) const;

private:
    double calculate_area() const override;
    double calculate_perimeter() const override;
    double radius;
    // Note: the inherited point will represent the
    // center of the circle
};

class Rect : public Shape {
public:
    // Constructors
    Rect();
    Rect(double b, double h);
    Rect(double b, double h, color f);
    Rect(color f);
    Rect(int x_in, int y_in);
    Rect(point p);
    Rect(double b, double h, color f, int x_in, int y_in);

    // getters
    // setters
    // want point to have x, y coordinates >= 0
    void set_top_left(int x_in, int y_in);
    // want base to be >= 0
    void set_base(double b);
    // want height to be >= 0
    void set_height(double h);
    void set_dimensions(double b, double h);

    void draw() const override;

    // detect if the Rect is overlapping with a coordinate point
    bool is_overlapping(const point &p) const;
    bool is_overlapping(int x, int y) const;

    // detect if the Rect is overlapping with another Rect
    bool is_overlapping(const Rect &r) const;

private:
    double calculate_area() const override;
    double calculate_perimeter() const override;
    double base;
    double height;
    // Note: the inherited point will represent
    // the top left corner of the Rect
};


#endif //CS120B_SHAPES_SHAPES_H