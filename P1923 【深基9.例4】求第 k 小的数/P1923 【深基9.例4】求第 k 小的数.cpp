#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n,k;
    scanf("%d%d",&n,&k);
    int arr[n];
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    printf("%d",arr[k]);
    return 0;
}