import java.io.*;
class LCMGCD
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			String inp[] = br.readLine().split(" ",2);

			long x = Integer.parseInt(inp[0]);
			long y = Integer.parseInt(inp[1]);

			long hcf = GCD(Math.min(x,y),Math.max(x,y));
			long lcm = (long)(x*y*1.0)/hcf;
			System.out.println(hcf+" "+lcm);
		}
	}

	public static long GCD(long a,long b)
	{
		if(b%a==0)
		{
			return a;
		}

		return GCD(b%a,a);
	}
}
