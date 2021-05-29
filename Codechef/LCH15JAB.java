import java.io.*;

class Cake
{
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while(t>0)
		{
			String s = br.readLine();

			int arr[] = new int[26];
			int counter = 0;

			for(int i=0;i<s.length();i++)
			{
				int p =(int) Math.abs('a' - s.charAt(i));
				arr[p]++;
				counter++;
			}
			int sum=0,max=0;
			for(int i=0;i<26;i++)
			{
				sum+=arr[i];
				if(max<arr[i])
					max=arr[i];
			}

			if((2*max)==sum)
				System.out.println("YES");
			else
				System.out.println("NO");

			t--;
		} 		
	}
}
