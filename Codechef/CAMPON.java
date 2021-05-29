import java.util.Scanner;
class Camp
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        while(t>0)
        {
            int d = sc.nextInt();
            int plan[] = new int[32];
            int cummulative = 0;
            int prevPos = 1;

            for(int i=0;i<d;i++)
            {
                int di = sc.nextInt();
                for(int j=prevPos;j<di;j++)
                {
                    plan[j] = cummulative;
                }
                cummulative+=sc.nextInt(); 
                plan[di] = cummulative;
                prevPos = di;
            }

            for(int i=prevPos;i<32;i++)
            {
                plan[i] = cummulative;
            }

            int q = sc.nextInt();
            for(int i=0;i<q;i++)
            {
                int deadi = sc.nextInt();
                int reqi = sc.nextInt();
                int val = plan[deadi];
                if(val<reqi)
                    System.out.println("Go Sleep");
                else
                    System.out.println("Go Camp");
            }
            t--;
        }

        sc.close();
    }
}
