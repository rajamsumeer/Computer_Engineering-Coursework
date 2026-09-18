/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 5 Exercises
Q1
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.util.Arrays;
class Point implements Comparable<Point> {
// ... definition of members etc. ...
    private static final Point ORIGIN = new Point(0,0);
    private double x, y;
    Point(double xx, double yy) {
        x = xx ;
        y = yy ;
    }
    public double distance(Point p) {
        return Math.hypot(x-p.x, y-p.y);
    }
    @Override
    public String toString() {
        return "( " + x + ", " + y + ")" ;
    }
    public int compareTo(Point p) {
        double pDist = p.distance(ORIGIN);
        double dist = this.distance(ORIGIN);
        if (dist > pDist) {
            return 1;
        } else if (dist == pDist) {
            return 0;
        } else {
            return -1;
        }
    }
    public static void main(String[] args) {
        Point p[] = {
            new Point(1,1),
            new Point(0.5,0),
            new Point(-1, 0),
            new Point(-0.5,-0.5),
            new Point(0,-1)
        };
        java.util.Arrays.sort(p);
        System.out.println("After sorting ... ");
        System.out.println(Arrays.toString(p));
    }
}