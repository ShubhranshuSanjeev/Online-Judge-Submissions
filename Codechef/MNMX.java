import java.io.*;
class Mini
{
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while(t>0)
		{
			int n = Integer.parseInt(br.readLine());
			String array[] = br.readLine().split(" ",n);
			long min = Long.parseLong(array[0]),pos=0;
			for(int i=1;i<n;i++)
			{
				if(min>Long.parseLong(array[i]))
				{
					min = Long.parseLong(array[i]);
					pos = i;
				}
			}

			long cost = min*(n-1); 
			System.out.println(cost);
			t--;
		}
	}
}
