// 2.1
import java.util.Scanner;

public class second {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int number = scan.nextInt();

        if (isEven(number)) {

            System.out.println("Even.");

        } else {

            System.out.println("Odd.");

        }

    }

    private static boolean isEven(int arg) {

        if (arg % 2 == 0) {

            return true;

        } else {

            return false;

        }

    }

} // public class ...