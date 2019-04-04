
package queueusingarray;

/**
 *
 * @author admin
 */
public class QueueUsingArray {

  private int data[];
  private int front;
  private int rear;
  private int size;
  
  QueueUsingArray()
  {
      data=new int[10];
      front=-1;
      rear=-1;
      size=1;
  }
   public int size(){
       return size;
   }
   public boolean isEmpty()
   {
       return size==0;
   }
   public int front() throws QueueEmptyException {
       if(size()==0)
       {
          throw new QueueEmptyException();
       }
       return data[front];
   }
   public void enqueue(int element) throws QueueFullException
   {
       if(size()==data.length)
       {
           throw new QueueFullException();
       }
       if(size()==0)
       {
           front=0;
       }
       size++;
       rear++;
       /*if(rear==data.length)
       {
           rear=0;
       }*/
       rear=(rear+1)%data.length;
       data[rear]=element;
   }
   public int dequeue() throws QueueEmptyException{
       if(size()==0){
           throw new QueueEmptyException();
       }
       int temp=data[front];
       /*front++;
       if(front==data.length)
       {
           front=0;
       }*/
       front=(front+1)%data.length;
       size--;
       if(size()==0)
       {
           front=-1;
           rear=-1;
       }
       return temp;
   }
}
