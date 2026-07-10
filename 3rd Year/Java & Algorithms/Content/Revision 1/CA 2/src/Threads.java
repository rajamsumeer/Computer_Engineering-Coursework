/*
Student IDs:
Student Names: R. Sumeer, R. Makani
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 09/03/2026
Code Purpose: CA2 - Car Mileage
Credits Sources: W3Schools, Geek4Geeks, Stackoverflow, Medium, Oracle, Lecture Notes
Method chaining - https://www.geeksforgeeks.org/java/method-chaining-in-java-with-examples/
Threads (isAlive, join()) - [https://www.geeksforgeeks.org/java/java-threads/] [https://medium.com/javarevisited/java-threads-and-its-methods-c3cb20dde51c]
[https://www.w3schools.com/java/java_threads.asp] [Lecture 6]
*/
import java.util.ArrayList;
/*
* Mileage Threads
* @fields
* efficiency_min - Store calculated minimum efficiency of mileage records
* efficiency_max - Store calculated maximum efficiency of mileage records
* efficiency_average - Store calculated average efficiency of mileage records

* @methods
* run() - Runs when thread starts, calculates efficiencies, then finds min, max and average of them and displays results
* findMin() - Iterates through Mileage records and finds lowest calculated efficiency value
* findMax() - Iterates through Mileage records and finds highest calculated efficiency value
* findAverage() - Iterates through Mileage records and calculates average efficiency for all mileage records

* @Interfaces
* Runnable - Allows a class instance to run as a seperate thread

* @Exception classes
* somethingBadException - User defined exception thrown when no arguments are given
*/
public class Threads implements Runnable {
    public static ArrayList<Mileage> records;

    private static float efficiency_min;
    private static float efficiency_max;
    private static float efficiency_average;

    @Override
    public void run() {
        System.out.println("Calculating car mileage efficiencies in Thread 1");

        // Calculate efficiencies for each record based on distance since each fill, once
        for (int i = 1; i < records.size(); i++) {
            // set car_efficiency for each record
            records.get(i).car_efficiency = records.get(i).calculateEfficiency(records.get(i-1));
        }

        // Compute efficiencies and display results
        efficiency_min = findMin();
        efficiency_max = findMax();
        efficiency_average = findAverage();
        System.out.println("Min efficiency: " + efficiency_min);
        System.out.println("Max efficiency: " + efficiency_max);
        System.out.println("Average efficiency: " + efficiency_average);
    }

    public static void main(String args[]) {
        try {
            Mileage.noArgumentsChecker(args);
            records =  Mileage.fileRead(args[0]);

            Threads m = new Threads(); // Create instance of Runnable class
            Thread t = new Thread(m); // Create thread object and pass Runnable to it
            t.start();

            while (t.isAlive()) { // While thread is still running
                System.out.println("Waiting...");
                t.join(1000); // Pause for 1 second before re-checking
            }
        } catch (somethingBadException e) {
            System.out.println(e.getMessage());
        } catch (InterruptedException i) { // Thread was interrupted
            System.out.println("Thread interrupted: " + i.getMessage());
        }
    }

    private static float findMin() {
        // Initalize first valid efficiency value 
        efficiency_min = records.get(1).getEfficiency();

        for (Mileage r : records) {
            if (r.getEfficiency() != 0.0f) { // Skip a record with efficiency of equal to 0.0
                if (efficiency_min > r.getEfficiency()) {
                    efficiency_min = r.getEfficiency();
                }
            }
        }
        return efficiency_min;
    }

    private static float findMax() {
        // Initalize first valid efficiency value 
        efficiency_max = records.get(1).getEfficiency();

        for (Mileage r : records) {
            if (r.getEfficiency() != 0.0f) { // Skip a record with efficiency of equal to 0.0
                if (efficiency_max < r.getEfficiency()) {
                    efficiency_max = r.getEfficiency();
                }
            }
        }
        return efficiency_max;
    }

    private static float findAverage() {
        float sum = 0.0f; // Total efficiency
        int count = 0; // Valid efficiency records count

        for (Mileage r : records) {
            if (r.getEfficiency() != 0.0f) { // Skip a record with efficiency of equal to 0.0
                sum += r.getEfficiency();
                count++;
            }
        }
        // Return average which is total computed efficiency by number of valid records
        return (sum/count);
    }
}