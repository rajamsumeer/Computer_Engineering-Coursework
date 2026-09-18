/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 5 Exercises
Q6
Credits Sources: Oracle, W3Schools, Lectures
*/
public class Circle extends Shape {
    private double radius;

    public Circle(double r) {
        super(r, r);
        radius = r;
    }
    
    public double getArea() {
        return (Math.PI * radius * radius);
    }

    public double getPerimeter() {
        return (2 * Math.PI * radius);
    }
}