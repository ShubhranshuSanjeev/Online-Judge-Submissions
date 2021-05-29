import java.util.Scanner;
import java.util.Arrays;
class TruthDare
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t>0)
        {
            int pos = -1,flagTruth=1,flagDare = 1;

            int tr = sc.nextInt();
            int tRam[] = new int[tr]; 
            for(int i=0;i<tr;i++)
            {
                tRam[i] = sc.nextInt();
            }
            Arrays.sort(tRam);

            int dr = sc.nextInt();
            int dRam[] = new int[dr]; 
            for(int i=0;i<dr;i++)
            {
                dRam[i] = sc.nextInt();
            }
            Arrays.sort(dRam);

            int ts = sc.nextInt();
            int tShy;
            for(int i=0;i<ts;i++)
            {
                tShy = sc.nextInt();
                int l = 0 , r = tRam.length - 1;
                pos = -1;
                while (l <= r) 
                { 
                    int m = l + (r-l)/2; 
                    if (tRam[m] == tShy) 
                        pos = m; 
                    if (tRam[m] < tShy) 
                        l = m + 1; 
                    else
                        r = m - 1; 
                }
                if(pos==-1)
                {
                    flagTruth = 0;
                }
            }

            int ds = sc.nextInt();
            int dShy;
            for(int i=0;i<ds;i++)
            {
                dShy = sc.nextInt();
                int l = 0 , r = dRam.length - 1;
                pos=-1;
                while (l <= r) 
                { 
                    int m = l + (r-l)/2; 
                    if (dRam[m] == dShy) 
                        pos = m; 
                    if (dRam[m] < dShy) 
                        l = m + 1; 
                    else
                        r = m - 1; 
                }
                if(pos==-1)
                {
                    flagDare = 0;
                }
            }

            if(flagDare==1&&flagTruth==1)
                System.out.println("yes");
            else
                System.out.println("no");
            t--;
        }
    }
}
