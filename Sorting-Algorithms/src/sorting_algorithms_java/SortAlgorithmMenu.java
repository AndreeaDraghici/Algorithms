package sorting_algorithms_java;

import java.util.Scanner;

public class SortAlgorithmMenu {
	
    SortAlgorithm sort=new SortAlgorithm();
    int[] arr= {13, 45, 2, 90, 66, 34, 21, 32, 10, 7, 5, 56, 11, 19, 23, 75, 100, 88};
    Scanner inputScan=new Scanner(System.in);
    
    protected void DisplayMenu()
    { 
  	        System.out.println("----- Sort Algorithm Menu -----");
  		System.out.println("0.Exit");
  		System.out.println("1.Print Initial Array");
  		System.out.println("2.Print Bubble Sort");
  		System.out.println("3.Print Selection Sort");
  		System.out.println("4.Print Insertion Sort");
  		System.out.println("\nYour choice...");
    }
  	
  public void Run()
  {	
 int choice=0;
 do {
	  try {  
		    DisplayMenu();
		  
		    choice=inputScan.nextInt();	
		     
		     switch (choice) {
		     
		     case 1:
				  System.out.println("--- Initial Array ---");
				  sort.printArr((arr));
				  break;
		     case 2:
				  System.out.println("--- Bubble Sort ---");
				  System.out.println("\n");
				  int bubble[] = arr.clone();
				  sort.bubbleSort(bubble);
				  sort.printArr(bubble);
				  break;
		     case 3:
				  System.out.println("--- Selection Sort ---");
				  System.out.println("\n");
				  int selection[] = arr.clone();
				  sort.selectionSort(selection);
				  sort.printArr(selection);
		                  break;
		     case 4:        
				  System.out.println("--- Insertion Sort ---");
				  System.out.println("\n");
				  int insertion[] = arr.clone();
				  sort.insertionSort(insertion);
				  sort.printArr(insertion);
				  break;
		     default:
		    	 System.out.println("\n");
		    	 System.out.println ("Sorting Algorithms Done...");
		     }
	    }catch(Exception e)
	            {
	               System.out.println(e.getMessage());
	               continue; 
	            }
	      finally
	       {
		       System.out.println("\n");
	       }
	 }while(choice!=0);
			 
	  System.out.println("Done.... ");		     
  }

}
