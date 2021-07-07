#include <bits/stdc++.h>

using namespace std;


void input (int n, int **array){
   cout << "Enter the array of the weight, not necessarily ordered" << "\n"; 
   for(int i=0;i<n;++i){
      cin >> (*array)[i];
   }
   /*for(int i=0;i<n;++i){
      cout << (*array)[i] << " ";
   }*/
   cout << "\n";
   return;
   
}


void sort(int **array, int l, int r){
   int buffer = 0;
   while(r-l<=1){
      if((*array)[l]>(*array)[r]){
         buffer = (*array)[r];
         (*array)[r] = (*array)[l];
         (*array)[l] = buffer;
      }
      return; //the size of the array must be greater than 3
   }
   int b = l, e = r, temp = (*array)[b];   //b: begin, e: end;
   while(b<e){
      while((b<e) && ((*array)[e] >= temp)){
         --e;
      }
      (*array)[b] = (*array)[e];
      while((b<e) && ((*array)[b] <= temp)){
         ++b;
      }
      (*array)[e] = (*array)[b];  
   }
   (*array)[b] = temp;
   sort(array, l, b);
   sort(array, b+1, r);
}


void combinatorics(int n, int *array, int** sum){
    const int N = 1<<n;
    int add[N][n];
    for(int i =0; i<N; ++i){
      for(int j =0; j<n; ++j){
         add[i][j] = 0;
      }
   } 
   
   int pos = 0;
   for(int i =0; i<n; ++i){
      pos = 1<<i;
      add[pos][i] = 1; 
      for(int j =1; j<pos; ++j){
         for(int k= 0; k<n; ++k){
            add[pos+j][k] = add[pos][k] + add[j][k]; 
         }
      }   
   }
   
   
   int number = 0;
   int temp = 0;
   int l1 = 0, l2 = 0, iteration = 1;
   //Main Loop
   
   for(int i =0; i<N; ++i){
      for(int j=0; j<n; ++j){
         (*sum)[i] += add[i][j] * array[j]; 
      }   
      if(((*sum)[i] % 2 == 0) && ((*sum)[i] > 0)){
         temp = 0;
         for(int k =n-1; k>=0; --k){
            temp += add[i][k] * array[k];
            //A possible balance!
            if(2 * temp == (*sum)[i]){
               iteration = 1;
               l1 = 0;
               l2 = 0;
               for(int m =0; m <n; ++m){
                  l1 = ((array[m] * add[i][m] == array[k]) && (m<k)) ? l1+1 : l1;
                  l2 = ((array[m] * add[i][m] == array[k]) && (m>=k)) ? l2+1 : l2;
               }
               //Factorial: # of possible permutation
               for(int f =0; f<l1; ++f){
                  iteration *= (l1+l2-f);
               }
               for(int f =1; f<=l1; ++f){
                  iteration /= f;
               }
               
               while(iteration > 0){
               ++number;
               cout << "#" << number << " Left: ";
               for(int l =0; l<n; ++l){
                  if((add[i][l] != 0) && (l<k)){
                     cout << array[l] << " ";
                  }
                  if(l == k){
                     cout << "Right: ";
                  }
                  if((add[i][l] != 0) && (l>=k)){
                     cout << array[l] << " ";
                  }
               }
               cout << "\n";   //output one of possible combinatorics    
               --iteration;
              }      
              break;
            }   
        
         }
      }
   }
   
   
}


int main(){
   int n;
   cout << "Enter the length of the array n:" << "\n"; 
   cin >> n;
   const int N = 1<<n; 
   int* array; 
   array = (int*) malloc(n*sizeof(int)); 
   input(n, &array);
   sort(&array, 0, n-1);
   for(int i=0; i<n; ++i){
      cout << array[i] << " ";
   }
   cout << "\n";
   
   int *sum = (int*) malloc(N * sizeof(int));
   combinatorics(n, array, &sum);
   
   free(array);
   free(sum);
   return 0;
}
