import java.io.*;

class Pair
{
	public static void main(String[] args)throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int t = Integer.parseInt(br.readLine());

		while(t>0)
		{
			int n = Integer.parseInt(br.readLine());
			int arr[] = new int[n];
			int check[] = new int[100001];
			for(int i=0;i<n;i++)
			{	
				arr[i] = Integer.parseInt(br.readLine());
				check[arr[i]]++;
			}
			for (int i = 0; i < n-1; i++) 
	            for (int j = 0; j < n-i-1; j++) 
	                if (arr[j] > arr[j+1]) 
	                {
	                    int temp = arr[j]; 
	                    arr[j] = arr[j+1]; 
	                    arr[j+1] = temp; 
	                }
	        int flag = 0;
	        for(int i=0;i<n-1;i++)
	        {
	        	if(arr[i]==arr[i+1])
	        		i+=1;
	        	else
	        	{
		        	System.out.println(arr[i]);
		        	flag=1;
		        	break;
	        	}	
	        }

	        if(flag==0)
	        	System.out.println(arr[n-1]);
			t--;
		}
	}
}
