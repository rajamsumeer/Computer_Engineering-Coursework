/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q6
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.util.Scanner;
import java.util.ArrayList;
class Multiple extends Exception {
    Multiple(String msg) {
        super(msg);
    }
}

public class duplicate {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer>();
        try {
            while (scan.hasNextInt()) {
                int number = scan.nextInt();
                if (list.contains(number)) {
                    throw new Multiple("Duplicate!: " + number);
                }
                list.add(number);
            }
            scan.close();
        } catch (Multiple e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}