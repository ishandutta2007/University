/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package colacola;

import java.util.Scanner;

/**
 *
 * @author PoorE
 */
public class ColaCola {
    /**
     * @param args the command line arguments
     */
    
    int money;
    int nBottom;
    int nCola;
    public ColaCola(int n){
        money = n * 100;
        nCola = 0;
        nBottom = 0;
    }
    
    public static void main(String[] args) {
        // TODO code application logic here
        Scanner scan = new Scanner(System.in);
        System.out.println("Now input the total money you have:");
        int n;
        n = scan.nextInt();
        ColaCola cola = new ColaCola(n);
        System.out.println("The max number of cola is "+cola.getMaxCola());
        
    }

    private int getMaxCola() {
        nCola = nBottom = money / 48;
        
        while(nBottom >= 3){
            if(nBottom >= 20){
                nCola += 7;
                nBottom -= 13;
            }
            else{
                nCola += 1;
                nBottom -= 2;
            }
        }
        return nCola;
    }
    
}
