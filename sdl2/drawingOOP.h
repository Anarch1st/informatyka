#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct Color {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    unsigned char alpha;
};

class Shape
{
public:
    Shape() {};
    int m_x = 0;
    int m_y = 0;
    Color m_color{ 0,0,0,0 };
    virtual void Draw() { cout << "Base Draw\n"; };
};

class Circle : public Shape
{
    string m_name;
    float m_radius;
public:

    Circle(string name, int x, int y, float radius, const Color& color) : m_name(name), m_radius(radius)
    {
        m_x = x;
        m_y = y;
        m_color = color;
    };

    void Draw() override;
};

class Rectangle : public Shape
{
    int m_width;
    int m_height;
    string m_name;
public:
    Rectangle(string name, int x, int y, int width, int height, const Color& color) : m_name(name), m_width(width), m_height(height)
    {
        m_x = x;
        m_y = y;
        m_color = color;
    };
    void Draw() override;
    
};

class Triangle : public Shape {
    int m_width;
    int m_height;
    string m_name;
public:
    Triangle(string name, int x, int y, int width, int height, const Color& color) : m_name(name), m_width(width), m_height(height)
    {
        m_x = x;
        m_y = y;
        m_color = color;
    };
    void Draw() override;
};


class DrawingEngine
{
public:
    static void Render(vector<Shape*>& shapes)
    {
        for (Shape* it : shapes)
        {
            it->Draw();
            delete it;
        }
    }
};