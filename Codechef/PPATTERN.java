import java.util.Scanner;
class Pattern
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        
        while(t>0)
        {
            int n = sc.nextInt();
            int pattern[][] = new int [n][n];
            int num = 1;
            
            for(int i=0;i<n;i++)
            {   
                int j = 0;
                if(i==0&&j==0)
                {
                    pattern[i][j] = num;
                    num+=1;
                    continue;
                }    
                int r = i;
                for(int k = 0;k<(i+1);k++) 
                {
                    // System.out.println(r+" "+j);
                    pattern[j][r] = num;
                    --r;
                    ++j;
                    ++num;
                }
            }

            for(int i=1;i<n;i++)
            {
                int j = n-1;
                int r = i;
                int steps = (int) Math.abs(i-j)+1;
                for(int k = 0;k<steps;k++) 
                {
                    // System.out.println(r+" "+j);
                    pattern[r][j] = num;
                    ++r;
                    --j;
                    ++num;
                }
            }

            for(int i=0;i<n;i++)
            {
                for(int k=0;k<n;k++)
                {
                    if(k!=n-1)
                        System.out.print(pattern[i][k]+" ");
                    else
                        System.out.print(pattern[i][k]);
                }
                    
                System.out.println();
            }
            --t;
        }

        sc.close();
    }
} 
