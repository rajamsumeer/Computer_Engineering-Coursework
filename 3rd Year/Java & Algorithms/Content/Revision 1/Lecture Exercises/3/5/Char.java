// Q5
public class Char {
    public static void main(String[] args)
    {
        String original = "software";
        StringBuilder result = new StringBuilder("hi");
        int index = original.indexOf('a');
        /*1*/ result.setCharAt(0, original.charAt(0)); // 'si'
        /*2*/ result.setCharAt(1, original.charAt(original.length()-1)); //'sr'
        /*3*/ result.insert(1, original.charAt(4)); // 'hti'
        /*4*/ result.append(original.substring(1,4)); // 'hisoft'
        /*5*/ result.insert(3, (original.substring(index, index+2) + " ")); // 'hiare '
        System.out.println(result); //swear oft
    }
}