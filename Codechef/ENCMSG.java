import java.io.*;
class EncodingMessages {
	public static void main(String args[])throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		
		String abc = "abcdefghijklmnopqrstuvwxyz";
		String newString = "";
		String arrResult[] = new String[testCases];
		
		for(int t=0;t<testCases;t++)
		{
			int length =Integer.parseInt(br.readLine());
			String sentence = br.readLine();
			
			for (int i=0;i<length-1;i+=2)
			{
				newString+=String.valueOf(abc.charAt(25-abc.indexOf(sentence.charAt(i+1)))) + String.valueOf(abc.charAt(25-abc.indexOf(sentence.charAt(i))));
			}
			if(length%2!=0)
			{
				newString+=String.valueOf(abc.charAt(25-abc.indexOf(sentence.charAt(length-1))));
			}
			arrResult[t] = newString;
			newString = "";
		}
		for(int t=0;t<testCases;t++)
		{
			System.out.println(arrResult[t]);
		}
	}
}

