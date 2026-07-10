/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q2
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.util.Scanner;
class notEven extends Exception {
    notEven(String msg) {
        super(msg);
    }
}

public class odd {
    static void checkNumber(int n) throws notEven {
        if (n % 2 != 0) {
            throw new notEven("Number is odd!");
        } else {
            System.out.println(n);
        }
    }
    public static void main(String[] args)
    {
        try {
            Scanner scan = new Scanner(System.in);
            int number = scan.nextInt();
            checkNumber(number);
        } catch (notEven e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}