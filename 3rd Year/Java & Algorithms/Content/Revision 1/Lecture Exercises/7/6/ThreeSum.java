/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 7 Exercises
Q6
Credits Sources: Oracle, W3Schools, Lectures
*/
public class ThreeSum {
    public static int count(int[] a) {
        int N = a.length;
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                for (int k = j+1; k < N; k++) {
                    if (a[i] + a[j] + a[k] == 0) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
    public static void main(String[] args) {
        int a[] = Reader.readAllInts(args[0]);
        long start = System.nanoTime();
        int cnt = count(a);
        long end = System.nanoTime() ;
        System.out.println(cnt);
        System.out.println("elapsed time = "
                           + (end-start)/(1000.0*1000.0) + " ms");
    }
};
