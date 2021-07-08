#include <bits/stdc++.h>

using namespace std;


void input (int n, int **array){
   cout << "Enter the array of the weight, not necessarily ordered" << "\n"; 
   for(int i=0;i<n;++i){
      cin >> (*array)[i];
   }

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
      return; 
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

void findsum(int n, int *array, int **sum){
   int a[n]; //determine whether k-th number in the array would be chosen 
   for(int i =0; i<n; ++i){
      a[i] = 0;
   }
   (*sum)[0] = 0;
   int temp = 0, number = 0, l1 = 0, l2 = 0, iteration = 0;
   for(int i=0; i<n; ++i){
      a[i] = 1;
      (*sum)[(1<<i)] = a[i] * array[i];
      for(int j=1; j<1<<i; ++j){
         (*sum)[(1<<i)+j] += a[i] * array[i];
         temp = j;
         for(int k=i-1; k>=0; --k){
                // e.g. 7=2^2+2^1+2^0 -> a[0]=a[1]=a[2]=1
                if(temp-(1<<k) >= 0){ 
                   a[k] = 1;
                   (*sum)[(1<<i)+j] += a[k] * array[k];
                   temp -= 1<<k;
                }
                else{
                   a[k] = 0;
                }
             
         }
         //(*sum)[1<<i] can not make possible balance
         if((*sum)[(1<<i)+j] % 2 == 0){
               temp = 0;
               l1 = 0;
               l2 = 0;
               iteration = 0; //A MUST initialize!
               for(int l = i; l>=0; --l){
                  temp += a[l] * array[l];
                  if((*sum) [(1<<i)+j] == temp << 1){
                     //Exists a Possible balance
                     for(int s=0; s<=i; ++s){ 
                     //find iteration:= (l1+l2) choose (l1)
                        l1 = ((array[s] == array[l]) && (a[s] == 1) && s<l) ? 1+l1: l1;
                        l2 = ((array[s] == array[l]) && (a[s] == 1) && s>=l) ? 1+l2: l2;
                     }
                        iteration = 1;                    
                        for(int q=0; q<l1; ++q){
                           iteration *= (l1+l2-q);
                        }
                        for(int q=1; q<=l1; ++q){
                           iteration /= q;
                        }
                        
                        while(iteration >0){
                           ++number;
                           cout << "#" << number << " LEFT: ";
                           for(int m=0; m<l; ++m){
                              if(a[m] == 1){
                                 cout << array[m] << " ";  
                              }
                           }
                           cout << "RIGHT ";
                           for(int m=l; m<=i; ++m){
                              if(a[m] == 1){
                                 cout << array[m] << " ";  
                              }
                           }
                           cout << "\n";
                           --iteration;
                        }
                        break;
                  }
               }
         }  
      }
   }
   return;
}


/*
void combinatorics(int n, int *array, int** sum){
    const int N = 1<<(n>>1); //N := 2^[n/2]
    int add[N][n];
    for(int i =0; i<N; ++i){
      for(int j =0; j<n; ++j){
         add[i][j] = 0;
      }
   } 
   

   for(int i =0; i<(n>>1); ++i){
      add[1<<i][i] = 1; 
      for(int j =1; j<(1<<i); ++j){
         for(int k= 0; k<n; ++k){
            add[1<<i+j][k] = add[1<<i][k] + add[j][k]; 
         }
      }   
   }
   
   
   int number = 0;
   int temp = 0;
   int l1 = 0, l2 = 0, iteration = 1;
   //Calculate Sum of "window" with smaller size (ranging form 1 to n/2) 
   
   for(int i =0; i<(1<<(n>>1)); ++i){
      for(int j=0; j<(1<<i); ++j){
         (*sum)[i] += add[i][j] * array[j]; 
      }   
   }   
   for(int i =(n>>1); i<n; ++i){
      for(int j=0; j<(1<<i); ++j){
         (*sum)[i] += add[i][j] * array[j]; 
      }   
   }   
      
   
   
}
*/

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
   //combinatorics(n, array, &sum);
   findsum(n, array, &sum);
   free(array);
   free(sum);
   return 0;
}
