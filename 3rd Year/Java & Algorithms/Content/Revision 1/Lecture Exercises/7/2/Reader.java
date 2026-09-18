import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Reader {
    public static int[] readAllInts(String fileName) {
        ArrayList<Integer> IntList = new ArrayList<>();
        try {
            Scanner fileScan = new Scanner(new File(fileName));
            while (fileScan.hasNext()) {
                int n = fileScan.nextInt();
                IntList.add(n);
            }
            fileScan.close();
        } catch (FileNotFoundException e) {
            System.out.println("File Error: " + e.getMessage());
        }
        int[] ar = new int[IntList.size()];
        for (int i = 0; i < IntList.size(); i++) {
            ar[i] = IntList.get(i);
        }
        return ar;
    }
}