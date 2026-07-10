/*
Student IDs:
Student Names: R. Sumeer, R. Makani
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 09/03/2026
Code Purpose: CA2 - Car Mileage
Credits Sources: W3Schools, Geek4Geeks, Stackoverflow, Medium, Oracle, Lecture Notes
Sorting & comparing dates - https://www.geeksforgeeks.org/java/how-to-sort-an-arraylist-of-objects-by-property-in-java/
LocalDate parsing - https://medium.com/@AlexanderObregon/javas-localdate-parse-method-explained-d2c2bb7322cb
Method chaining - https://www.geeksforgeeks.org/java/method-chaining-in-java-with-examples/
Enhanced loop - https://runestone.academy/ns/books/published/csjava/Unit7-Arrays/topic-7-3-arrays-with-foreach.html
*/
import java.util.ArrayList;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
import java.time.LocalDate;
import java.util.Locale;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
/*
* Mileage class
* @constructors
* Mileage(LocalDate d, int km, float l) - Instantiates a Mileage record object

* @fields
* date - The date of fuel fill details
* kilometers - The odometer reading at each fuel fill
* litres - The amount of petrol bought in litres at each fuel fill
* car_efficiency - The fuel efficiency of the car (litres per 100km)

* @methods
* noArgumentsChecker(String args[]) - Checks that a file was given in the standard input
* sortRecordsDate(ArrayList<Mileage> records) - Sorts mileage records by earliest date to last date order
* recordedDate() - Returns the record date
* getEfficiency() - Returns stored efficiency
* calculateEfficiency(Mileage p) - Calculates efficiency using current & previous record
* toString() - Converts to a string & overloaded to print out mileage record details
* fileRead(String fileName) - Reads records from a file and creates a new mileage record

* @Exception classes
* somethingBadException - User defined exception thrown when no arguments are given
*/
class somethingBadException extends Exception {
    somethingBadException(String msg) {
        super(msg);
    }
}

public class Mileage {
    public static void noArgumentsChecker(String args[]) throws somethingBadException {
        if (args.length < 1) {
            throw new somethingBadException("No file name given to check records!");
        }
    }

    public static void sortRecordsDate(ArrayList<Mileage> records) {
        records.sort((a, b) -> a.recordedDate().compareTo(b.recordedDate()));
    }

    private LocalDate date;
    private int kilometers;
    private float litres;
    public float car_efficiency;

    public Mileage(LocalDate d, int km, float l) {
        date = d;
        kilometers = km;
        litres = l;
        car_efficiency = 0.0f; // Not yet found
    }

    public LocalDate recordedDate() { return date; }
    public float getEfficiency() { return car_efficiency; }

    public float calculateEfficiency(Mileage p) {
        int kmDifference = kilometers - p.kilometers;
        return (litres / kmDifference) * 100;
    }

    @Override
    public String toString() {
        return (date + " " + kilometers + "Km " + litres + " Litres (" + car_efficiency + " L/100km)");
    }

    public static ArrayList<Mileage> fileRead(String fileName) {
        ArrayList<Mileage> records = new ArrayList<Mileage>(); // Stores mileage records from text file

        try {
            Scanner scanFile = new Scanner(new File(fileName));
            scanFile.nextLine(); //skip a header line to get to actual readings

            /* Create a formatter that follows the date format in the text records
                So that program knows how to read the date string as a LocalDate object
            */
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy", Locale.ENGLISH);

            while (scanFile.hasNext()) { // Read records until EOF
                try {
                    String fileDate = scanFile.next();

                    // Parse date from text file using formatter and convert to LocalDate object
                    LocalDate date = LocalDate.parse(fileDate, formatter);

                    // Read odometer & bought fuel records
                    int fileKm = scanFile.nextInt();
                    float fileLitres = scanFile.nextFloat();

                    Mileage fileRecord = new Mileage(date, fileKm, fileLitres); // Create new mileage object & store in list
                    records.add(fileRecord);
                } catch (DateTimeParseException d) { // Bad formatted date line 
                    System.out.println("Error: Bad line: " + d.getMessage());
                }
            }
            scanFile.close();
        } catch (FileNotFoundException e) { // File not found or cannot be opened
            System.out.println("File error: " + e.getMessage());
        }
        return records; // Return all read records from file
    }

    public static void main(String args[]) {
        try {
            noArgumentsChecker(args);
            ArrayList<Mileage> records = fileRead(args[0]);
            sortRecordsDate(records);

            // Calculate fuel efficiencies for each record and show efficencies
            for (int i = 1; i < records.size(); i++) {
                records.get(i).car_efficiency = records.get(i).calculateEfficiency(records.get(i-1));
            }

            // Print all mileage records
            for (Mileage r : records) {
                System.out.println(r);
            }
        } catch (somethingBadException e) {
            System.out.println(e.getMessage());
        }
    }
}