/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 7 Exercises
Q11
Credits Sources: Oracle, W3Schools, Lectures
*/
public class localMin {
    public static int rank(int[] a) {
        int lo = 0;
        int hi = a.length - 1;
        while (lo <= hi) {
            // Key is in a[lo..hi] or not present.
            int mid = lo + (hi - lo) / 2;
            if (a[mid] < a[mid - 1] && a[mid] < a[mid + 1]) {
                return mid; // local min
            } else if (a[mid - 1] < a[mid]) {
                hi = mid -1;
            } else {
                lo = mid + 1;
            }
            // if (key < a[mid]) hi = mid - 1;
            // else if (key > a[mid]) lo = mid + 1;
            // else return mid;
        }
        return -1;
    }
    public static void main(String[] args) {
        int[] num = {5, 9, 3, 2, 8, 7};
        int index = rank(num);
        System.out.println("Local min at " + index + " where value is " + num[index]);
    }
};
