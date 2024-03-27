#include <stdio.h>
#include <stdlib.h>

int powi(int m, int l) {
    if(l == 0) 
        return 1;
        
    int p = m;
    for(int i = 0; i < l - 1; ++i) {
        p *= m;
    }

    return p;
}

int countDigit(int i) {
    int o = 0;
    while(i!=0) {  
       i = i/10;  
       o++;  
    }
    return o;  
}

int swap(int number, int l, int p) {
    int *numberArray = malloc(sizeof(int) * countDigit(number));

    int count = 0;    
    int n = number;

    while (n != 0){
        numberArray[count] = n % 10;
        n /= 10;
        count++;
    }

    int l1 = numberArray[countDigit(number) - 1 - l];
    int p1 = numberArray[countDigit(number) - 1 - p];
    numberArray[countDigit(number) - 1 - l] = p1;
    numberArray[countDigit(number) - 1 - p] = l1;

    int po = 0;
    for(int i = countDigit(number) - 1; i >= 0 ; --i) {
        po += numberArray[i] * powi(10, i);
    }

    free(numberArray);

    return po;
}

   

/*
void permute(string a, int l, int r) 
{ 
    // Base case 
    if (l == r) {
        cout<<a<<endl; 
    } 
    else
    { 
        // Permutations made 
        for (int i = l; i <= r; i++) 
        { 
  
            // Swapping done 
            swap(a[l], a[i]); 
  
            // Recursion called 
            permute(a, l+1, r); 
  
            //backtrack 
            swap(a[l], a[i]); 
        } 
    } 
} 
*/

int main() {
    //int x;
    //scanf("%d", &x);
    
    printf("%d", swap(123456165, 1, 2));

    //if(x < 0) {
    //    printf("X could not be less then zero");
    //    return 1;
    //}
//
    //int dig = countDigit(x);
    //int need_array = malloc(sizeof(int) * dig * dig);
    //for(int i = 0; i < dig*dig; ++i) {
    //    for(int i = 0; i < dig*dig; ++i) {
    //    }
    //}
//
    //int n;
    //scanf("%d", &n);
    //if(n < 1) {
    //    printf("Size of an array could not be less then one");
    //    return 1;
    //}
//
    //int *array = malloc(sizeof(int) * n);
    //for(int i = 0; i < n;) {
    //    int tmp;
    //    scanf("%d", &tmp);
//
    //    if(tmp < 0) {
    //        printf("Element of the array could not be less then zero");
    //        continue;
    //    } else {
    //        array[i] = tmp; 
    //        ++i;   
    //    }
    //}
//
    //for(int i = 0; i < n; ++i) {
    //    printf("%d ", array[i]);
    //}

    return 0;
}