class Factorial {
   public static void main () {
   int[] a;
   a = new int[5 - 1];
   int counter;
   counter = 5;
   while(counter > 2){
      a[counter - 2] = counter * 2;
      counter = counter - 1;
   }
   System.out.println(a);

   }
 }