import java.io.*;
class SpellBob
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());

		for(int i=0;i<t;i++)
		{
			String f = br.readLine();
			String b = br.readLine();
			int c=0;

			if((f.charAt(0)=='b'||b.charAt(0)=='b')&&(f.charAt(1)=='o'||b.charAt(1)=='o')&&(f.charAt(2)=='b'||b.charAt(2)=='b'))
				c++;
			else if((f.charAt(0)=='o'||b.charAt(0)=='o')&&(f.charAt(1)=='b'||b.charAt(1)=='b')&&(f.charAt(2)=='b'||b.charAt(2)=='b'))
				c++;
			else if((f.charAt(0)=='b'||b.charAt(0)=='b')&&(f.charAt(1)=='b'||b.charAt(1)=='b')&&(f.charAt(2)=='o'||b.charAt(2)=='o'))
				c++;

			if(c>0)
				System.out.println("yes");
			else
				System.out.println("no");
		}
	}
}
