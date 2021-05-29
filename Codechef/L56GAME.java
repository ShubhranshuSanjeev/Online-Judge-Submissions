import java.io.*;
class SeqGame
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for (int i=0;i<t;i++)
		{
			int n = Integer.parseInt(br.readLine());
			String seq[] = br.readLine().split(" ",n);
			int x=0;
			for (int j=0;j<n;j++)
			{
				int a = Integer.parseInt(seq[j]);
				if(a%2!=0)
					x++;
			}
			if(x%2!=0&&n>1)
				System.out.println("2");
			else if(x%2==0)
				System.out.println("1");
			if(x==1&&n==1)
				System.out.println("1");
		}
	}
}
