// 2.2 + 2.3
import java.util.Scanner;

public class doubles {

    public static void main(String[] args) {

        System.out.println("Enter 3 doubles:");
        Scanner scan = new Scanner(System.in);

        double[] numberArray = null;
        numberArray = new double[3];
        for (int i = 0; i < 3; i++) {
            numberArray[i] = scan.nextDouble();
        }

        System.out.println("Answer: " + sum(numberArray[0], numberArray[1], numberArray[2]));

    }

    private static double sum(double x, double y, double z) {
        return (x + y + z);
    }

} // public class ...