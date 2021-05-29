import java.util.Scanner;
class AgeCalc
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in); 
        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            int days[] = new int[n];
            int totalDays = 0;
            for(int i=0;i<n;i++)
            {
                days[i] = sc.nextInt();
                totalDays += days[i]; 
            }
            int yb = sc.nextInt();
            int mb = sc.nextInt();
            int db = sc.nextInt();
            int yc = sc.nextInt();
            int mc = sc.nextInt();
            int dc = sc.nextInt();
            int daySum=0;

            if(yc==yb)
            {
                if(mc==mb)
                {
                    daySum=dc-db;
                }
                else
                {
                    daySum = (days[mb-1]-db)+dc;
                    for(int i=mb+1;i<mc;i++)
                    {
                        daySum+= days[i-1];
                    }
                }
                
            }
            else
            {
                daySum = (days[mb-1]-db)+dc;
                
                for(int i = mb+1;i<=n;i++)
                {
                    daySum += days[i-1]; 
                }

                if(yb%4==0)
                {
                    daySum+=1;
                }
                
                for(int i=yb+1;i<yc;i++)
                {
                    daySum+=totalDays;
                    if(i%4==0)
                    {
                        daySum+=1;
                    }
                }
                for(int i=1;i<mc;i++)
                {
                    daySum+=days[i-1];
                }
            }
            
            System.out.println(daySum+1);
            t--;
        }
        sc.close();
    }
}
