import java.io.*;
class ByteBit
{
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int t = Integer.parseInt(br.readLine());
        while(t>0)
        {
            long n = Long.parseLong(br.readLine());
            long step = n/26;
            long remain = n%26;
            long pop =(long) Math.pow(2,step);
            long popprev =(long) Math.pow(2,(step-1));

            if(remain == 0)
                System.out.println("0 0 "+popprev);
            else if(remain>0 && remain<=2)
                System.out.println(pop+" 0 0");
            else if(remain>2 && remain<=10)
                System.out.println("0 "+pop+" 0");
            else
                System.out.println("0 0 "+pop);
            t--;
        }
    }
}
