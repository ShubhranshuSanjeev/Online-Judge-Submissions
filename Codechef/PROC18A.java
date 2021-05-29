import java.io.*;
class GreatRun
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		for (int i = 0; i < t; i++)
		{
			String d[] = br.readLine().split(" ");
			int n = Integer.parseInt(d[0]);
			int k = Integer.parseInt(d[1]);
			String nG[] = br.readLine().split(" ", n);
			int max = 0;
			for (int j = 0; j < n - k + 1; j++)
			{
				int s = 0;
				for (int x = j; x < j + k; x++)
					s += Integer.parseInt(nG[x]);
				if (max < s)
					max = s;
			}
			System.out.println(max);
		}
	}
}
