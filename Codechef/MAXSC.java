import java.io.*;
import java.util.*;

class Q2
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t>0)
        {
            int n = Integer.parseInt(br.readLine());
            String inp[][] = new String[n][n];
            for(int i = 0; i < n; i++)
            {
                inp[i] = br.readLine().split(" ",n);
            }

            long max = 0,sum = 0;
            int flag = 0,count=0;
            long maxArr[] = new long[n];

            for(int i = n-1; i >= 0 ; i--)
            {
                for(int j = 0 ; j < n; j++)
                {
                    if(max < Long.parseLong(inp[i][j]) && i < n-1)
                    {
                        if(Long.parseLong(inp[i][j]) < maxArr[i+1])
                        {
                            max = Long.parseLong(inp[i][j]);
                            flag = 1;
                        }
                    }    
                    else if(max < Long.parseLong(inp[i][j]) && i==n-1)
                    {
                        max = Long.parseLong(inp[i][j]);
                        flag = 1;
                    }
                }
                maxArr[i] = max;
                max = 0;
                sum+=maxArr[i];
                if(flag == 0)
                    count++;
                else
                    flag = 0;
            }
            if (count>0)
                System.out.println("-1");
            else
                System.out.println(sum);
            t--;
        }
    }
}
