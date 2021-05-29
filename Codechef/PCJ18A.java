import java.io.*;
class SecIngredient
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			String inp[] = br.readLine().split(" ");
			int n = Integer.parseInt(inp[0]);
			int x = Integer.parseInt(inp[1]);

			String amt[] = br.readLine().split(" ",n);

			int f = 0;

			for(int j=0;j<n;j++)
			{
				if(Integer.parseInt(amt[j])>=x)
				{
					f=1;
					System.out.println("YES");
					break;
				}
			}

			if(f!=1)
				System.out.println("NO");
		}
	}
}
