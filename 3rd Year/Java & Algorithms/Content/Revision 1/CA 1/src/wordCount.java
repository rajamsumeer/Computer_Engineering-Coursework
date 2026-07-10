/*
Student ID:
Student Name: R. Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: CA1 - Word Counter
Credits Sources: Oracle, W3Schools, Lecture Exercises
equals() - https://www.w3schools.com/java/ref_string_equals.asp
ArrayList - https://www.w3schools.com/java/java_arraylist.asp | https://www.w3schools.com/java/java_ref_arraylist.asp
scanner - https://docs.oracle.com/javase/8/docs/api/java/util/Scanner.html | https://www.w3schools.com/java/java_user_input.asp | https://www.w3schools.com/java/java_ref_scanner.asp
L - Calling a constructor from a constructor (this)
L3 - toString() overloading
*/
import java.util.ArrayList;
import java.util.Scanner;
/*
* wordCount class
Reads words from standard input and counts the frequency of each word, then printing results.
* @constructors
* wordCount(String w, int occurance) - set word and occurance count
* wordCount(String w) - sets initial word count of 1

* @fields
* word - current word being checked
* occ - number of times word has appeared

* @methods
* add_occ() - increments occurance counnt
* total_occ() - returns total occurance count (int)
* fetchWord() - returns word (string)
* toString() - overloaded formatted string that returns each word and it's total count
*/
public class wordCount {
    private String word;
    private int occ;

    public wordCount(String w, int occurance) {
        word = w;
        occ = occurance;
    }

    public wordCount(String w) {
        this(w, 1);
    }

    public void add_occ() {
        occ++;
    }

    public int total_occ() {
        return occ;
    }

    public String fetchWord() {
        return word;
    }

    public String toString() {
        return (word + " " + occ);
    }

    public static void main(String[] args)
    {
        Scanner scan = new Scanner(System.in);
        ArrayList<wordCount> wordCountList = new ArrayList<wordCount>(); // wordCount object list

        while (scan.hasNext()) { // read each word until EOF of standard input
            int wordFound = 0;
            String userWord = scan.next();

            for (int i = 0; i < wordCountList.size(); i++) { // search list for word
                wordCount current = wordCountList.get(i);
                String currentWord = current.fetchWord();
                boolean equal = currentWord.equals(userWord);

                if (equal) { // if word found, increment it's count
                    wordFound = 1;
                    current.add_occ();
                }
            }
            if (wordFound == 0) { // if word not found, add it to list
                wordCountList.add(new wordCount(userWord));
            }
        }
        scan.close();
        for (int i = 0; i < wordCountList.size(); i++) { // print each word and it's total count
            System.out.println(wordCountList.get(i));
        }
    }
}