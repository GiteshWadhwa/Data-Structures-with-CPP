#include<string>
using namespace std;
template<typename V>
class MapNode{
public:
   string key;
   V value;
   MapNode* next;
   MapNode(string key,V value){
   this->key=key;
   this->value=value;
   next=NULL;
   }
   ~MapNode(){
     delete next;
   }
};
template<typename V>
class ourmap{
MapNode<V>** buckets;
int size;
int numBuckets;
public:
    ourmap(){
    count=0;
    numBuckets=5;
    buckets=new MapNode<V>*[numBuckets];//created a dynamic array of size 5
     for(int i=0;i<numBuckets;i++){
        buckets[i]=NULL;//garbage ki jagha null kr dia hr jagha
     }
    }
    ~ourmap(){
    for(int i=0;i<numBuckets;i++){
        delete buckets[i];//delete ll
    }
    delete [] buckets;//now dwlwte complete array....
    }
    int size(){
   return count;
    }
    V getValue(string key){
                int bucketIndex=getBucketIndex(string key);
          MapNode<V>* head=buckets[bucketIndex];
          while(head!=NULL){
            if(head->key=key){
               return head->value;
            }
             head=head->next;
          }
          return 0;
    }
private:
    int getBucketIndex(string key){
      int hashCode =0;
//find hash code by using   key-> base p method.....eg:string "abc"->a*p^2+b*p^1+c*p^0;
      int currentCoeff=1;//p^0=1
   for(int i=key.length()-1;i>=0;i--){
hashCode +=key[i]*currentCoeff;
hashCode=hashCode%numBuckets;
currentCoeff*=37;
currentCoeff=currentCoeff%numBuckets;
   }
      return hashCode % numBuckets;
    }

    public:
    void insert(string key,V value){
        //key->hashFunction->bucketIndex...
        int bucketIndex=getBucketIndex(string key);
        MapNode<V>* head=buckts[bucketIndex];//head aa gaya
        while(head!=NULL){
           if(head->key==key){
              head-value=value;
              return;
           }
            head=head->next;
        }
        head=buckts[bucketIndex];
        MapNode<V>* node=new MapNode<V>(key,,value);
        node->next=head;
        buckets[bucketIndex] =node;
        count++;
    }
    V remove(string key){
        int bucketIndex=getBucketIndex(string key);
      MapNode<V>* head=buckets[bucketIndex];
      MapNode<V>* prev=NULL;
      while(head!=NULL){
            if(head->key==key){
                    if(prev==NULL){
                        buckets[bucketIndex]=head->next;
                    }
                    else{
                prev->next=head->next;}
                  }
            V value=head->value;
            head->next=NULL;
          delete head;
          count--;
          return value;
      }
        prev=head;
            head=head->next;
    }
    return 0;
};
