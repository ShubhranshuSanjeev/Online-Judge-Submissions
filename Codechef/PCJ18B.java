import java.io.*;
class ChefBoard
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			int n = Integer.parseInt(br.readLine());

			int noOfOddSquare = n*n;
			for(int j=3;j<=n;j+=2)
			{
				int x = (n-j+1)*(n-j+1);
				noOfOddSquare+=x;
			}

			System.out.println(noOfOddSquare);
		}
	}
}

