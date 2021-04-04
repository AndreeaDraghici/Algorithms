package pentagonalnumbers;

public class PentagonalNumbers {

	public static void main(String[] args) {
		for(int n=1;n<=10;n++)
		{
			int number=n*(3*n-1)/2;
			System.out.println(number+"");
		}
		System.out.println("");
	}

}
