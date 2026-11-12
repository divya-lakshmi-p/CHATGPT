import java.util.Scanner;

class Main
{
    public static void main(String [] args)
    {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt() , mini = Integer.MAX_VALUE ;

        int [] arr = new int[n];
        for(int i=0; i<n; i++)
        {
            arr[i] = sc.nextInt();
        }

        int  first = arr[0] , second = 0;
        boolean find = false;

        for(int i=1; i<n; i++)
        {
            if(i==0 || arr[i] > first)
            {   second = first;
                first = arr[i];
                find = true;
            }
            else if(arr[i] <first && (!find || arr[i] > second))
            {
                second = arr[i];
                find = true;
            }
        }

        if(find)
        System.out.println(second);
        else
            System.out.println("No second largest distince element");
    }
}
