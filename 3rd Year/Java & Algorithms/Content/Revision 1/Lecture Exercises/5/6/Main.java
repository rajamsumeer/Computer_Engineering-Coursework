/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 5 Exercises
Q6/Q7
Credits Sources: Oracle, W3Schools, Lectures
*/
public class Main {
    public static void main(String[] args) {
        Shape r = new Rectangle(5.0, 10.0);
        Shape circ = new Circle(5.0); //Q7
        System.out.println("Area of rectangle: " + r.getArea());
        System.out.println("Area of circle: " + circ.getArea()); //Q7
        Circle c = new Circle(5.0); //Q7
        System.out.println("Perimeter of circle: " + c.getPerimeter());
    }
}