import java.util.Scanner;
class MaxEle
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int coins = 1000;
        int n = sc.nextInt();
        int co = sc.nextInt();
        int l=1,u=n,a=u/4,b=2*(u-l)/4,c=3*(u-l)/4,m1=a/2,m2=a+((b-a)/2),m3=b+((c-b)/2),m4=c+((u-c)/2); 
        while(l<=u)
        {
            int positions[] = {l,m1,a,m2,b,m3,c,m4,u};
            for(int i=0;i<9;i++)
            {
                System.out.println("1 "+positions[i]);
                c--;
                int r = sc.nextInt();
                if(r==0)
                {
                    l = positions[i]+1;
                    a = l+((u-l)/4);
                    b = l+(2*(u-l)/4);
                    c = l+(3*(u-l)/4);
                    m1 = l+((a-l)/2);
                    m2 = a+((b-a)/2);
                    m3 = b+((c-b)/2);
                    m4 = c+((u-c)/2);
                }
                else if(r==1)
                {
                    System.out.println("2");
                    u = positions[i]-1;
                    break;
                }
            }
            a = l+((u-l)/4);
            b = l+(2*(u-l)/4);
            c = l+(3*(u-l)/4);
            m1 = l+((a-l)/2);
            m2 = a+((b-a)/2);
            m3 = b+((c-b)/2);
            m4 = c+((u-c)/2);    
        }
        System.out.println("3 "+m1); 
    }
}
