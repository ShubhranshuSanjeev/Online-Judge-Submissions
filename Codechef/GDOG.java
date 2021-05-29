import java.io.*;
class GreedyPup
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			String inp[] = br.readLine().split(" ",2);
			int n = Integer.parseInt(inp[0]);
			int k = Integer.parseInt(inp[1]);
			int max = 0;

			for(int j=2;j<=k;j++)
			{
				if (n%j!=0)
				{
					if(max<n%j)
					{
						max=n%j;
					}
				}	
			}

			System.out.println(max);
		}
	}
}
