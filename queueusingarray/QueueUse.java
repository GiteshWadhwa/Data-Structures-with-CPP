/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package queueusingarray;

/**
 *
 * @author admin
 */
public class QueueUse {
     public static void main(String[] args) {
        // TODO code application logic here
     QueueUsingArray queue=new QueueUsingArray();
     for(int i=1;i<=5;i++){
      try{
         queue.enqueue(i);
      }catch(QueueFullException e){
      
      }
     }
     
     while(!queue.isEmpty())
     {
         try{
         System.out.println(queue.dequeue());
         } catch (QueueEmptyException e){
           
         }
         }
    }
}
