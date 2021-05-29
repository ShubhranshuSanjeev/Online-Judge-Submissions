import java.io.*;
class LovelyStr
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		String tStr = "chef";

		for (int i=0;i<t;i++) 
		{
		 	String s = br.readLine();
		 	int lovely = 0;
		 	for (int j=0;j<s.length()-3;j++)
		 	{
		 		char a = s.charAt(j);
		 		int c=0,h=0,e=0,f=0;

		 		if(tStr.indexOf(a)>=0)
		 		{
		 			int flag=1;
		 			for(int x=0;x<=3;x++)
		 			{
		 				if(s.charAt(j+x)=='c')
		 					c++;
		 				else if(s.charAt(j+x)=='h')
		 					h++;
		 				else if(s.charAt(j+x)=='e')
		 					e++;
		 				else if(s.charAt(j+x)=='f')
		 					f++;
		 				else
		 					break;
		 			}
		 		}
		 		if(c==1&&h==1&&e==1&&f==1)
		 			lovely++;
		 	}
		 	if(lovely!=0)
		 		System.out.println("lovely "+lovely);
		 	else
		 		System.out.println("normal");
		} 
	}
}
