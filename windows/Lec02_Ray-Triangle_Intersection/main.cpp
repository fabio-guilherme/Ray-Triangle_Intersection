#include <iostream>
#include <GL/freeglut.h>
#include "Triangle.hpp"
#include "Vector3D.hpp"

// Declare global variables
Vector3D rayOrigin(0.0, 0.0, 0.0);
Vector3D rayVector(0.0, 0.0, 0.0);
Triangle* triangle = nullptr;
Vector3D intersectionPoint(0.0, 0.0, 0.0);
bool intersects;

bool RayIntersectsTriangle(Vector3D rayOrigin,
    Vector3D rayVector,
    Triangle* inTriangle,
    Vector3D& outIntersectionPoint)
{
    const float EPSILON = 0.0000001;
    Vector3D vertex0 = inTriangle->vertex0;
    Vector3D vertex1 = inTriangle->vertex1;
    Vector3D vertex2 = inTriangle->vertex2;
    float a, f, u, v;
    Vector3D edge1 = vertex1 - vertex0;
    Vector3D edge2 = vertex2 - vertex0;
    Vector3D h = rayVector.crossProduct(edge2);
    
    a = edge1.dotProduct(h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.
    
    f = 1.0 / a;
    Vector3D s = rayOrigin - vertex0;
    u = f * s.dotProduct(h);
    if (u < 0.0 || u > 1.0)
        return false;
    
    Vector3D q = s.crossProduct(edge1);
    v = f * rayVector.dotProduct(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dotProduct(q);
    if (t > EPSILON) // ray intersection
    {
        outIntersectionPoint = rayOrigin + rayVector * t;
        return true;
    }
    else // This means that there is a line intersection but not a ray intersection.
        return false;
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    // Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(triangle->vertex0.getX(), triangle->vertex0.getY(), triangle->vertex0.getZ());
    glVertex3f(triangle->vertex1.getX(), triangle->vertex1.getY(), triangle->vertex1.getZ());
    glVertex3f(triangle->vertex2.getX(), triangle->vertex2.getY(), triangle->vertex2.getZ());
    glEnd();

    // Set the line width to 3 pixels
    glLineWidth(2.0);

    // Ray
    Vector3D rayEnd = rayOrigin + rayVector * 100;
    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(rayOrigin.getX(), rayOrigin.getY(), rayOrigin.getZ());
    //glVertex3f(rayEnd.getX(), rayEnd.getY(), rayEnd.getZ());
    glVertex3f(rayOrigin.getX() + rayVector.getX(), rayOrigin.getY() + rayVector.getY(), rayOrigin.getZ() + rayVector.getZ());
    glEnd();

    glBegin(GL_POINTS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(rayOrigin.getX(), rayOrigin.getY(), rayOrigin.getZ());
    if (intersects)
    {
        glColor3f(0.0, 0.0, 0.0);
        glVertex3f(intersectionPoint.getX(), intersectionPoint.getY(), intersectionPoint.getZ());
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    // Create triangle
    Vector3D v0 = Vector3D(-0.5, -0.5, -0.5);
    Vector3D v1 = Vector3D(0.5, -0.5, -0.5);
    Vector3D v2 = Vector3D(0.0, 0.5, -0.5);
    triangle = new Triangle(v0, v1, v2);

    // Create ray
    rayOrigin = Vector3D(-0.2, -0.3, 0.0);
    rayVector = Vector3D(0.5, 0.5, -1.0);
    rayVector.normalize();

    // Call function
    intersects = RayIntersectsTriangle(rayOrigin, rayVector, triangle, intersectionPoint);
    if (intersects)
    {
        std::cout << "Intersection point: (" << intersectionPoint.getX() << ", " << intersectionPoint.getY() << ", " << intersectionPoint.getZ() << ")" << std::endl;
    }
    else
    {
        std::cout << "No intersection" << std::endl;
    }

    // Draw elements
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Triangle");
    glutDisplayFunc(display);
    glutMainLoop();

    // Clean up
    delete triangle;
    return 0;
}
