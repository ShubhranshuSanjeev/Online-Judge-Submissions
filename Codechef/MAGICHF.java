import java.io.*;
class Magician
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			String inp[] = br.readLine().split(" ",3);
			int n = Integer.parseInt(inp[0]);
			int x = Integer.parseInt(inp[1]);
			int s = Integer.parseInt(inp[2]);
			String swaps[][] = new String[s][2];			
			for (int j=0;j<s;j++)
			{
				swaps[j] = br.readLine().split(" ",2);
				if(Integer.parseInt(swaps[j][0])==x)
					x=Integer.parseInt(swaps[j][1]);
				else if(Integer.parseInt(swaps[j][1])==x)
					x=Integer.parseInt(swaps[j][0]);
			}

			System.out.println(x);
		}
	}
}
