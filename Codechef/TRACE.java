import java.util.Scanner;
class Trace{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            int matrix[][] = new int[n][n];
            int maxNum = 0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    matrix[i][j] = sc.nextInt();
                }
            }
            for(int i=0;i<=n-1;i++)
            {
                int a=i,b=0,sumDiag=0,sumDiag1=0;
                while(a<n&&b<n)
                {
                    sumDiag+=matrix[a][b];
			        sumDiag1+=matrix[b][a];
                    a+=1;
                    b+=1;
                }

                if(sumDiag1<sumDiag)
                {
                    if(maxNum<sumDiag)
                        maxNum = sumDiag;
                }    
                else
                {
                    if(maxNum<sumDiag1)
                        maxNum = sumDiag1;
                }
                    
            }
            System.out.println(maxNum);
            t--;
        }
    }
}
