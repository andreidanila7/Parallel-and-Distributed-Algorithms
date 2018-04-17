#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
using namespace std;
mutex mtx;
sem_t mutex;
queue<int> Q;
int p;
condition_variable CondProd;
condition_variable CondCons;
  
void Producer()
{
    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(3);
 
          sem_wait(&mutex);
          while (Q.size == 10)
   	         CondProd.wait();
        
          Q.push(1);
          cout << "The product was added in que" << endl;
          sem_post(&mutex);
        
        
          CondCons.notify_all();
    }
}
 
void Consumer()
{
    while (true)
 
    {
        sem_wait(&mutex);
        std::this_thread::sleep_for(std::chrono::seconds(1));
 
        if (Q.size() == 0)
        {
            cout << "The queue is empty, please wait" << endl;
            sem_post(&mutex);
        }
        else
        {
            Q.pop();
            cout << "The product is out of the que." << endl;
            sem_post(&mutex);
        }
        while (Q.size == 0)
            CondCons.wait();
        CondProd.notify_all();
    }
 
}
 
int main()
{
    thread Prod(Producer);
    thread Cons(Consumer);
 
    Prod.join();
    Cons.join();
 
 
    system("pause");
    return 0;
}
