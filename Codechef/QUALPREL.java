import java.util.Scanner;
import java.util.Arrays;
class Qualify{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while(t>0)
        {
            int n = sc.nextInt();
            int k = sc.nextInt();
            int score[] = new int[n];
            for(int i=0;i<n;i++)
                score[i] = (-1)*sc.nextInt();
            Arrays.sort(score);
            for(int i=0;i<n;i++)
            {
                score[i] = -1*score[i];
            }
            int i=0;
            int check = score[k-1];
            while(i<n)
            {
                if(score[i]<check)
                    break;
                i++;
            }
            System.out.println(i); 
            t--;
        }
    }
}
