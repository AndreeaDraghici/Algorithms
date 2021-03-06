package sorting_algorithms_java;


public class SortAlgorithm {
	
 void printArr(int arr[])
 {
	 for(int i=0;i<arr.length;i++)
	 {
		System.out.println(arr[i]+" ");
	 }
	System.out.println(" ");
 }
 
 
  void bubbleSort(int arr[])
  {
    for(int i=0;i<arr.length-1;i++)
    {
    	for(int j=0;j<arr.length-i-1;j++)
    	{
    		if(arr[j]>arr[j+1])
    		{
    			int aux=arr[j];
    			arr[j]=arr[j+1];
    			arr[j+1]=aux;
    			printArr(arr);
    		}
    	}
    }
 }
    
    
  
  
  void selectionSort(int arr[])
  {
	  for(int i=0;i<arr.length-1;i++)
	  {
		  int min_element=i;
		  for(int j=i+1;j<arr.length;j++)
		  {
			  if(arr[j]<arr[min_element])
			  {
				  min_element=j;
			  }
		  }
		  int aux=arr[min_element];
		  arr[min_element]=arr[i];
		  arr[i]=aux;
		  
		  printArr(arr);
	  }
  }
  
  
  void insertionSort(int arr[])
  {
	  for(int i=0;i<arr.length;i++)
	  {
		  int key=arr[i];
		  int j=i-1;
		  while(j>=0&&arr[j]>key)
		  {
			  arr[j+1]=arr[j];
			  j--;
		  }
		  arr[j+1]=key;
		  printArr(arr);
	  }
  }
  
  
}