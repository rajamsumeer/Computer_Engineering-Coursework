/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 7 Exercises
Q2
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.util.Scanner;

public class LinearSearch {
    public static int rank(int[] a, int key) {
        for (int i = 0; i < a.length; i++) {
            if (key == a[i]) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String args[]) {
        int[] whitelist = Reader.readAllInts(args[0]);

        Scanner scan = new Scanner(System.in);
        while (scan.hasNext()) {
            int n = scan.nextInt();
            if (rank(whitelist, n) == -1) {
                System.out.println(n);
            }
        }
        scan.close();
    }
}