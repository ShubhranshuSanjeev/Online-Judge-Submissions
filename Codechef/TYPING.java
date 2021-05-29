import java.util.Scanner;
class ChefTyping
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t>0)
        {
            int n = sc.nextInt();
            String srr[] = new String[n];
            int time = 0;
            char left[] = {'d','f'};
            char right[] = {'j','k'};
            int flag = 0,count=0;
            for(int i=0;i<n;i++)
            {
                String inp = sc.next();
                int timeCurr = 2;
                for(int k = 1;k<inp.length();k++)
                {
                    char chCurr = inp.charAt(k);
                    char chPrev = inp.charAt(k-1);
                    if(((chCurr==left[0]||chCurr==left[1])&&(chPrev==right[0]||chPrev==right[1]))||((chCurr==right[0]||chCurr==right[1])&&(chPrev==left[0]||chPrev==left[1])))
                        timeCurr+=2;
                    else if(((chCurr==right[0]||chCurr==right[1])&&(chPrev==right[0]||chPrev==right[1]))||((chCurr==left[0]||chCurr==left[1])&&(chPrev==left[0]||chPrev==left[1])))
                        timeCurr+=4;                    
                }

                for(int j=0;j<count;j++)
                {
                    if(srr[j].equals(inp))
                    {
                        flag = 1;
                        break;
                    }
                }
                srr[i] = inp;
                count++;
                if(flag==1)
                    timeCurr=timeCurr/2;
                flag = 0;
                time+=timeCurr; 
            }
            System.out.println(time);
            t--;
        }
    }
}

