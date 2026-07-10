/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q1
Credits Sources: Oracle, W3Schools, Lectures
*/
public class exception {
    public static void main(String[] args)
    {
        try {
            int number = 12 / 0; // division by zero
            System.out.println(number);
        } catch (ArithmeticException e) {
            System.out.println("Arithmetic error: " + e.getMessage());
        }
    }
}