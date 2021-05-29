import java.math.BigInteger;
import java.io.*;
class Pin {
	public static void main(String args[])throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int testCases = Integer.parseInt(br.readLine());
		
		for(int t=0;t<testCases;t++)
		{
			int lengthOfPin = Integer.parseInt(br.readLine());
			BigInteger ten = BigInteger.valueOf(10);
			BigInteger numerator = BigInteger.valueOf(1);
			BigInteger denominator = ten.pow(lengthOfPin - (int)Math.ceil(lengthOfPin/2.0));
			System.out.println(numerator+" "+denominator);
		}
	}
}
