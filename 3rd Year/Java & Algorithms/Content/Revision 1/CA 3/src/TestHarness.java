/*
Student ID: , Student Name: R. Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 12/04/2026
Code Purpose: CA3 - Tail - Test Harness
Credits Sources: W3Schools, Geek4Geeks, Stackoverflow, Oracle, Lecture Notes
*/
import java.io.File;
import java.util.Scanner;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;
public class TestHarness {
    private static void printMeta(int t, String msg) {
        System.out.println("--------------");
        System.out.println("Test " + t + ":" + " " + msg);
    }

    private static void handleArgs(String args[]) {
        if (args.length == 0) return;
        if (args[0].equals("--help")) {
            System.out.println("*Usage: java TestHarness <test number>");
            System.out.println("Note: once you have given a number, press CTRL+Z");
            System.exit(0);
        }
    }

    public static void main(String args[]) {
        System.out.println("Type a Test number to run:");
        printMeta(0, "Concluded: Exit program");
        printMeta(1, "Positive k:");
        printMeta(2, "0 or negative k:");
        printMeta(3, "No arguments:");
        printMeta(4, "File empty:");
        printMeta(5, "Queue capacity testing:");
        printMeta(6, "Non-integer k:");
        handleArgs(args);
        Scanner input = new Scanner(System.in);
        int selected = input.nextInt();
        
        switch (selected) {
            case 0:
        System.out.println("Test 0 Selected: Exiting Program Test");
        break;
            case 1:
        printMeta(1, "Positive k:");
        try {
            String[] tailArgs = {"5"};
            Tail.main(tailArgs);
            System.out.println("Test 1 passed: Valid k");
        } catch (Exception e) {
            System.out.println("Test 1 failed: " + e.getMessage());
        }
        break;
            case 2:
        printMeta(2, "0 or negative k:");
        try {
            String[] tailArgs = {"0"};
            Tail.main(tailArgs);
            System.out.println("Test 2 passed: 0 or negative k");
        } catch (Exception e) {
            System.out.println("Test 2 failed: " + e.getMessage());
        }
        break;
            case 3:
        printMeta(3, "No arguments:");
        try {
            String[] tailArgs = {};
            Tail.main(tailArgs);
            System.out.println("Test 3 passed: No arguments");
        } catch (Exception e) {
            System.out.println("Test 3 failed: " + e.getMessage());
        }
        break;
            case 4:
        printMeta(4, "File empty:");
        try {
            Scanner scan = new Scanner(new File("empty.txt"));
            if (!scan.hasNextLine()) {
                System.out.println("Test 4 passed: File empty");
            } else {
                System.out.println("Test 4 failed: File empty");  
            }
        } catch (Exception e) {
            System.out.println("Test 4 failed: " + e.getMessage());
        }
        break;
            case 5:
        printMeta(5, "Queue capacity testing:");
            String[] words = {"This", "is", "a", "test", "harness", "!"};
            int limit = 5;
            ArrayBlockingQueue<String> queue = new ArrayBlockingQueue<String>(limit);
            for (String word : words) {
            System.out.println("Remaining Queue capacity: " + queue.remainingCapacity());
            if (queue.size() == limit) {
                System.out.println("Queue full: removing element: " + queue.peek());
                    queue.poll();
                }
                queue.offer(word);
                System.out.println("Adding to Queue: " + word);
                System.out.println("Current Queue: " + queue);
            }
        break;
            case 6:
        printMeta(6, "Non-integer k:");
        try {
            String[] tailArgs = {"abc"};
            Tail.main(tailArgs);
            System.out.println("Test 6 passed: Invalid k");
        } catch (Exception e) {
            System.out.println("Test 6 failed: " + e.getMessage());
        }
        break;
            default:
                System.out.println("Invalid Test choice");
        }
        input.close();
    }
}