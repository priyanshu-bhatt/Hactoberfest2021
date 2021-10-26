#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void insertionSort(int a[],int n){
     
     for(int i=1;i<n;i++){
        int j=i-1;
        int current = a[i];
        while(a[j]>current && j>=0){
        
            a[j+1]=a[j];
            j--;
        }
            a[j+1]=current;
    }
}

int main(){
    int n=10000;
    int a[n];
    clock_t t1,t2,t5,t6;
    for(int i=0;i<n;i++){
        a[i]=rand()%100;
    }
    t1=clock();
    insertionSort(a,n);
    t2 = clock();

    double p = double (t2-t1)/double CLOCKS_PER_SEC;
    cout<<"time taken at avg case : "<<fixed<<p<<setprecision(5)<<endl;

    //best case 
    
    int best[n];
    for(int i=0;i<n;i++){
        best[i]=a[i];
    }
    clock_t t3,t4;
    
    t3= clock();
    insertionSort(best,n);
    t4=clock();
    double q = double (t4-t3)/double CLOCKS_PER_SEC;
    cout<<"time taken at best case : "<<fixed<<q<<setprecision(5)<<endl;;
    
    
    //worst case
    int temp;
    int s=0,e=n;
    for(int i = 0;i<n;i++){
        while(s!=e){
           temp= best[s];
           best[s]=best[e];
           best[e]=temp;
           s++;
           e--;
        }
    }
    t5=clock();
    insertionSort(best,n);
    t6=clock();
     double r = double (t6-t5)/double CLOCKS_PER_SEC;
    cout<<"time taken at worst case : "<<fixed<<r<<setprecision(5);
       
          
}