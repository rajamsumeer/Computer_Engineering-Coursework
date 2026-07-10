// Q6/Q7/Q8/Q9/Q11/Q12
import java.util.Arrays;
public class Point {
    private double x;
    private double y;

    public Point(double xarg, double yarg) { // Constructor
        x = xarg;
        y = yarg;
        npoints++;
    }

    public Point() { // Call constructor Point(xarg, yarg)
        this(0, 0); // Initalize point to 0,0
    }

    public String toString() { // toString overloaded
        return ("(" + x + "," + y + ")");
    } //Q6-7

    protected static int npoints = 0;

    public static void main(String[] args) // Main
    {
        Point [] p = { // Array of objects p, references to Objects below
            new Point(), // Intializer Constructor called
            new Point(2,3),
            new Point(4,5)
        };
        //for (int i=0; i<p.length; i++)
        //  System.out.println( p[i] ); // prints Objects toString() but toString() was overloaded
        System.out.println(Arrays.asList(p));
        //System.out.println(Arrays.toString(p));
        // calls each array element's toString()
        //Q8
    }
}

// Q12: Was it wise?: Only to see how many Objects sucessfully created, not a reliable way to track Objects
// Is it accurate after a P object destroyed?: No, it only shows the initial amount created, it is not dynamically updating
// Yes, if you need to know how many objects were created initially and how many are currently stored, this count is not lost due to the garbage collector since the array stores it unless the array's reference changes