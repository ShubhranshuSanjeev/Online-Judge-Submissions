import java.io.*;
class ChefGlove
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int testCases = Integer.parseInt(br.readLine());
		for(int i=0;i<testCases;i++)
		{
			int f=0,b=0;
			int n = Integer.parseInt(br.readLine());
			String fing[] = br.readLine().split(" ",n);
			String glv[] = br.readLine().split(" ",n);
			
			for (int j=0;j<n;j++)
			{
				if(Integer.parseInt(fing[j])>Integer.parseInt(glv[j]))
				{
					f=1;
				}

				if(Integer.parseInt(fing[j])>Integer.parseInt(glv[n-1-j]))
				{
					b=1;
				}

				if(f==1&&b==1)
				{
					System.out.println("none");
					break;
				}
			}

			if(f==0&&b==0)
				System.out.println("both");
			else if(f==0&&b==1)
				System.out.println("front");
			else if(f==1&&b==0)
				System.out.println("back");
		}
	}
}
