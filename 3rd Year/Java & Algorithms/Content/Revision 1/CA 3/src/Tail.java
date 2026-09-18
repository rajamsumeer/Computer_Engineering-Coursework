/*
Student ID: , Student Name: R. Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 23/03/2026
Code Purpose: CA3 - Tail
Credits Sources: W3Schools, Geek4Geeks, Stackoverflow, Oracle, Lecture Notes
Integer parsing - https://www.tutorialspoint.com/java/number_parseint.html
*/
import java.util.Scanner;
import java.util.Queue;
import java.util.concurrent.ArrayBlockingQueue;
import java.io.File;
import java.io.FileNotFoundException;
/*
* Tail class
* @methods
* readWords(Scanner scan) - Reads words from standard input file data until EOF (using Ternary operator)
* fileChecker(Scanner scan) - Checks if standard input file data is empty (using Ternary operator)
* handleArgs(String args[]) - Handles user input for sufficient arguments

* @Exception classes (Handling program conditions)
* somethingBadException - User defined exception thrown when invalid conditions arise
*/
class somethingBadException extends Exception {
    somethingBadException(String msg) {
        super(msg);
    }
}
public class Tail {
    private static String readWords(Scanner scan) {
        return scan.hasNext() ? scan.next() : null;
    }

    private static boolean fileChecker(Scanner scan) {
        return !scan.hasNext() ? false : true;
    }

    private static void handleArgs(String args[]) throws somethingBadException {
        if (args.length == 0) { 
            throw new somethingBadException("No arguments detected!\nRun 'java Tail --help' for details."); 
        }
        if (args[0].equals("--help")) {
            System.out.println("*Usage: java Tail <argument>\nUsage options:");
            System.out.println("java Tail [<n length strings>] < [<dataset file>]\njava Tail --help");
            System.exit(0);
        }
    }

    public static void main(String args[]) {
        try {
            handleArgs(args);
            int k = Integer.parseInt(args[0]); // Parse k from input for "last k strings"
            if (k <= 0) { 
                throw new somethingBadException("Zero or negative detected!");
            }

            // Queue of size "k", never extends more than "k"
            ArrayBlockingQueue<String> queue = new ArrayBlockingQueue<String>(k);

            Scanner scanWord = new Scanner(System.in);
            if (!fileChecker(scanWord)) {
                throw new somethingBadException("Dataset file is empty!");
            }
            String inputWord = readWords(scanWord);
            while (inputWord != null) { // get words until EOF
                if (queue.size() == k) { // if Queue is full, remove head of Queue (oldest) (FIFO)
                    queue.poll();
                }
                queue.offer(inputWord); // add new word into tail of Queue
                inputWord = readWords(scanWord); // read next word
            }
            scanWord.close();
            for (String strings : queue) { // print remaining Queue elements (last k strings)
                System.out.println(strings);
            }
        } catch (somethingBadException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException n) {
            System.out.println(args[0] + " is not an integer.");
        }
    }
}
// DEBUG LINE: System.out.println("Remaining Queue capacity: " + queue.remainingCapacity());
// DEBUG LINE: System.out.println("Queue full: removing element: " + queue.peek());
// DEBUG LINE: System.out.println("Current Queue: " + queue);