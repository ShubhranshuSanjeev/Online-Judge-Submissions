import java.util.Scanner;
class DecChall_2
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        int x = 1;
        System.out.println(x); 
        int y = sc.nextInt();
        
        if(y==2)
            System.out.println("3");
        else if(y==3)
            System.out.println("2");
        sc.close();
    }
}
