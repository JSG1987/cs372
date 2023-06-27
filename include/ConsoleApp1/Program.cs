using System;

public class Exercise5
{
    
    
        public static void Main(string[] args)
        {
        int number1, number2, temp;
            Console.WriteLine("\nInput the first Number : ");
            number1 = int.Parse(Console.ReadLine());
            Console.WriteLine("\nInput the second Number: ");
            number2 = int.Parse(Console.ReadLine());
            temp = number1;
            number1 = number2;
            number2 = temp;
            Console.Write("\nAfter Swapping:");
            Console.Write("\nFirst Number : " + number1);
            Console.Write("\nSecond Number: " + number2);
            Console.Read();
        }
    
}
