// Q2
class List {
    private Object [] items;
    private int numItems;
    static int numLists = 0;
    public List()
    {
        items = new Object[10];
        numItems = 0;
        numLists++;
    }
    public void addToEnd(Object ob) {
    }
    static public int get_numLists() {
        return numLists;
    }
    static public void main() {
        System.out.println(List.get_numLists() );
    }
}