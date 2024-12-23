/*  TE 04/2022
    ES.5 JAVA GENERICS  
*/

import OrderedStack.OrderedStack;

public class App {
    public static void main(String[] args) throws Exception {
        OrderedStack<Integer> s = new OrderedStack<Integer>();

        s.push(2);
        s.push(1);
        s.push(0);
        s.push(8);

        System.out.println(s.max());
        System.out.println(s.min());

        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.empty());
        System.out.println(s.pop());
        System.out.println(s.pop());
        System.out.println(s.empty());

    }
}
