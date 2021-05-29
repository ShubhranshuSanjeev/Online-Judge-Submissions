import java.io.*;
class LIFELTD
{
    public static void main(String args[])throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); 
        int t = Integer.parseInt(br.readLine());
        while(t>0)
        {
            char matrix[][] = new char[3][3];
            int flag = 0;
            for(int i=0;i<3;i++)
            {
                String inp = br.readLine();
                matrix[i][0] = inp.charAt(0) ;
                matrix[i][1] = inp.charAt(1) ;
                matrix[i][2] = inp.charAt(2) ;
            }

            for(int i=0;i<3;i++)
            {
                for(int j=0;j<3;j++)
                {
                    if('l'== matrix[i][j] && i<2 && j<2)
                    {
                        if('l' == matrix[i+1][j] && 'l' == matrix[i+1][j+1])
                        {
                            flag=1;
                            break;
                        }    

                    }
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                System.out.println("yes");
            else
                System.out.println("no");
            t--;
        }
    }
}
