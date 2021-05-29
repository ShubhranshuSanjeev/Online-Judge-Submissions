import java.util.Scanner;
class MinDel
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            int a,gcdVal=0;

            for(int i=0;i<n;i++)
            {
                a = sc.nextInt();
                if(i==0)
                    gcdVal = a;
                else
                {
                    if(gcdVal>=a)
                        gcdVal = gcd(a,gcdVal);
                    else if(gcdVal<a)
                        gcdVal = gcd(gcdVal,a);
                } 
            }
            if(gcdVal==1)
                System.out.println("0");
            else
                System.out.println("-1");
            t--;
        }
    }

    public static int gcd(int a,int b)
    {
        if(b%a==0)
            return a;
        return gcd(b%a,a);
    }
}
