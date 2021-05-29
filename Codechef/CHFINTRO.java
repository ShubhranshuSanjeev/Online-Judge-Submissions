import java.util.Scanner;
class DecChall_1
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int r = sc.nextInt();
        
        for(int i=1;i<=n;i++)
        {
            int a = sc.nextInt();
            if(a>=r)
                System.out.println("Good boi");
            else
                System.out.println("Bad boi");
        }
        sc.close();
    }
}
