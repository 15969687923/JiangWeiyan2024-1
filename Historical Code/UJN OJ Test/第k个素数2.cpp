#include<iostream>    
#include<math.h>    
using namespace std;  
int main()  
{    
    long n;  
    while(cin >> n){
	    bool flag = false;  
	    int count = 0;  
	    int num;  
	    while (count < n)  
	    {  
	        for (int i = 2; i <= 10000000; i++)  
	        {  
	            int j = 2;  
	            for (j = 2; j <= sqrt((double)i); j++)  
	            {  
	                if (i % j == 0)  
	                    break;  
	            }  
	            if (j > sqrt((double)i))  
	            {  
	                count++;  
	                num = i;  
	  
	                if (count == n)  
	                    break;  
	            }  
	        }  
	    }  
	    cout << num << endl;  
	}
	return 0; 
}  
