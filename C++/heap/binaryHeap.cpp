#include <iostream>
#include <vector>
using namespace std;

class BHeap{
    private:
       vector <int> heap;
       int left(int index){ return 2 * index; };
       int right(int index){ return (2 * index) + 1};
       int par(int index){ return (index / 2) };
       void swap( int a, int b){
           int temp = 0;
           temp = a;
           a = b;
           b = temp;
       }
    public:
       void siftUp(int i){
           while( i > 1 && H[par(i)] < H[i]){
               swap( H(parent(i)) , H[i]);
               i = par(i);
           }
       }

       void siftDown(int i){
           while()
       }
}
int main(){

}
