/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 4 Exercises
Q7
Credits Sources: Oracle, W3Schools, Lectures
*/
import java.util.Scanner;
import java.util.ArrayList;
class noVowel extends Exception {
    noVowel(String msg) {
        super(msg);
    }
}

public class vowel {
    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        String[] vowels = {"a", "e", "i", "o", "u"};
        try {
            String line = scan.nextLine();
            int found = 0;
            for (int i = 0; i < vowels.length; i++) {
                if (line.contains(vowels[i])) {
                    found = 1;
                }
            }
            if (found == 0) {
                throw new noVowel("No vowel!");
            }
            scan.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}