// 2.5
import java.util.Scanner;

public class string {

    public static void main(String[] args) {

        System.out.println("Enter 3 strings:");
        Scanner scan = new Scanner(System.in);

        String[] stringArray = null;
        stringArray = new String[3];
        for (int i = 0; i < 3; i++) {
            stringArray[i] = scan.nextLine();
        }

        System.out.println(sum(stringArray[0], stringArray[1], stringArray[2]));
        String appendString = sum(stringArray[0], stringArray[1], stringArray[2]);
        int length = appendString.length();
        System.out.println("String length:"+length);

    }

    private static String sum(String x, String y, String z) {
        return (x + y + z);
    }

} // public class ...