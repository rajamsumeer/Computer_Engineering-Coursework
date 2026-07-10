/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q5
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;
class isEmpty extends Exception {
    isEmpty(String msg) {
        super(msg);
    }
}

public class empty {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        File myFile = new File(scan.nextLine());
        scan.close();
        try {
            Scanner read = new Scanner(myFile);
            if (!read.hasNextLine()) {
                throw new isEmpty("File is empty!"); 
            }
            while (read.hasNext()) {
                String data = read.nextLine();
                System.out.println(data);
            }
            read.close();
        } catch (FileNotFoundException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}