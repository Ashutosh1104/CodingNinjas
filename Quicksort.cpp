#include <iostream>
using namespace std;

int partition(int a[],int s,int e){
    int pivot=a[s],p=0;
    for(int i=s+1;i<=e;i++){
        if(a[i]<pivot) p++;
    }

    int pi=s+p;
    int temp=a[pi];
    a[pi]=a[s];
    a[s]=temp;
  
    int i=s,j=e;
    while(i<j ){
        if(a[i]<pivot) i++;
        else if(a[j]>pivot) j--;
        else if(a[i]>=pivot && a[j]<=pivot){
            int temp=a[j];
            a[j]=a[i];
            a[i]=temp;
            i++;j--;
        }
    }
    return pi; 
}
void qsort(int a[],int s,int e){
    if(s>=e) return;
    int pi=partition(a,s,e);
    qsort(a,s,pi-1);
    qsort(a,pi+1,e);
}

void quickSort(int input[], int size){
	qsort(input,0,size-1); 
}
int main(){
    int n;
    cin >> n;
  
    int *input = new int[n];
    
    for(int i = 0; i < n; i++) {
        cin >> input[i];
    }
    
    quickSort(input, n);
    for(int i = 0; i < n; i++) {
        cout << input[i] << " ";
    }
    
    delete [] input;

}