/*
Student ID:
Student Name: Raja M Sumeer
Module: Java & Algorithms @ Year 3, Semester 2 (Technological University Dublin)
Date: 28/02/2026
Code Purpose: Lecture 5 Exercises
Q3/Q4/Q5
Credits Sources: Oracle, W3Schools, Lectures
*/
public class Main {
    public static void main(String[] args) {
        Animal any = new Animal();
        Animal cat = new Cat();
        Animal dog = new Dog(); //Q4
        any.makeSound();
        cat.makeSound();
        dog.makeSound(); //Q4

        //Q5
        Animal[] myAnimals = {
            new Dog(),
            new Dog(),
            new Dog(),
            new Cat(),
            new Cat()
        };
        for (int i = 0; i < myAnimals.length; i++) {
            myAnimals[i].makeSound();
        }
    }
}