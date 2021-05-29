import java.io.*;
class ChefServe {
    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while(t>0)
        {
            String inp = br.readLine();
            String [] arr = inp.split(" ",3);
            int a = Integer.parseInt(arr[0]);
            int b = Integer.parseInt(arr[1]);
            int k = Integer.parseInt(arr[2]);
            int sum = a+b;
            int noOfServes = sum/k;
            if (noOfServes%2==1)
                System.out.println("COOK");
            else
                System.out.println("CHEF");
            t--;
        }
    }
}
