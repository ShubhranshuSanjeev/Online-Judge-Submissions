import java.util.Scanner;
class ChoosingBucket
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner (System.in);

        int n = sc.nextInt();
        int k = sc.nextInt();
        
        int bucketBall[][] = new int[n][k];
        int totalBalls[] = new int[n];

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<k;j++)
            {
                bucketBall[i][j] = sc.nextInt();
                totalBalls[i]+=bucketBall[i][j];
            }
        }
        double probability = 0.0;
        for(int i=0;i<k;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(j==0)
                    probability = bucketBall[j][i]/(totalBalls[j]*1.0);
                else
                {
                    probability = (probability * (bucketBall[j][i] + 1.0) / (totalBalls[j] + 1.0)) + ((1.0-probability)*bucketBall[j][i]/(totalBalls[j]+1.0));
                }
            }

            System.out.print(probability+" ");
        }



        sc.close();
    }
}
