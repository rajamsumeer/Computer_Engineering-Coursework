/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q4
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

class isPositive extends Exception {
    isPositive(String msg) {
        super(msg);
    }
}

public class positive {
    static void checkNumber(int n) throws isPositive {
        if (n % 2 == 0) {
            throw new isPositive("A number is positive!");
        } else {
            System.out.println(n);
        }
    }
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        File myFile = new File(scan.nextLine());
        scan.close();
        try {
            Scanner read = new Scanner(myFile);
            while (read.hasNext()) {
                String data = read.next();
                int toInt = Integer.parseInt(data);
                checkNumber(toInt);
            }
        read.close();
        } catch (isPositive e) {
            System.out.println("Error: " + e.getMessage());
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}