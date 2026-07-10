//Q9/Q10/Q11
import java.util.Arrays;
public class Pixel extends Point {
    public Pixel() {
        super(); // calls superclass Point()
    }

    public Pixel(double xarg, double yarg) {
        super(xarg, yarg); // calls Point(double,double) constructor
    }
    public static void main( String[] args ) {
        Pixel [] p = {
            new Pixel(),
            new Pixel(2,3),
            new Pixel(4,5)
        };
        System.out.println("In Pixel.main().\n");
        System.out.println(Arrays.toString(p));
        System.out.println("Number of Pixels:\n" + Pixel.npoints);
        // Output: prints Point's points and overloaded toString() as Pixel's toString is not overloaded
        // Pixel inherits from Point
    }
};

// Output: First error: Pixel has no Constructors defined, Superclass's Constructor is called by super() which is a no-arg Constructor but no Arg-Constructor for int so 2nd line fails
// Output: 2nd Error: Arrays package import is file specific - not defined in Pixel.java