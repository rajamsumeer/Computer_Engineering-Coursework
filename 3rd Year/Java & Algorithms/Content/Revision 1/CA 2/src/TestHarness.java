/*
Student IDs:
Student Names: R. Sumeer, R. Makani
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 09/03/2026
Code Purpose: CA2 - Car Mileage - Test Harness
Credits Sources: W3Schools, Geek4Geeks, Stackoverflow, Medium, Oracle, Lecture Notes
*/
import java.io.File;
import java.util.Scanner;
import java.io.FileNotFoundException;
public class TestHarness {
    public static void main(String args[]) {
        System.out.println("Test 1: File reading:");
        try {
            Mileage.fileRead(args[0]);
            System.out.println("Test passed");
        } catch (Exception e) {
            System.out.println("Test failed: " + e.getMessage());
        }

        System.out.println("--------------");
        System.out.println("Test 2: No file arguments:");
        try {
            Mileage.noArgumentsChecker(args);
            System.out.println("Test passed");
        } catch (somethingBadException e) {
            System.out.println("Test failed: " + e.getMessage());
        }

        System.out.println("--------------");
        System.out.println("Test 3: File empty:");
        try {
            Scanner scanFile = new Scanner(new File(args[0]));
            if (!scanFile.hasNextLine()) {
                System.out.println("File is empty");
            }
            System.out.println("Test failed: File is not empty");
        } catch (FileNotFoundException e) {
            System.out.println("Test passed: " + e.getMessage());
        } catch (Exception e) {
            System.out.println("Test passed: " + e.getMessage());
        }
    }
}