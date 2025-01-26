#include <stdio.h>
#include <stdlib.h>


//Struct for values and position indicators
typedef struct {

    int value;
    int pos;

}Pairs;

//Initializing void pointers
int sort_values(const void* x_void, const void* y_void){
    //Casting then dereferencing pointers
    const Pairs* x = (const Pairs*)x_void;
    const Pairs* y = (const Pairs*)y_void;

    //Will return value less than zero
    return x->value - y->value;

}

//Sorting position indicators
int sort_pos(const void* x_void, const void* y_void){
    //Casting then defererencing pointers
    const Pairs* x = (const Pairs*)x_void;
    const Pairs* y = (const Pairs*)y_void;

    //Will return value less than zero
    return x->pos - y->pos;
}

int main(){

    int n;
//Taking user input for size of array
printf("Please enter how many values you would like to enter: ");
scanf("%d", &n);

//Initializing array of structs
Pairs pairs[n];

//User input for values
for(int i = 0; i < n; i++){
    printf("Enter the value for position [%d]: ", i);
    scanf("%d", &pairs[i].value);
    pairs[i].pos = i;
}

//Calling qsort() to sort values first
qsort(pairs, n, sizeof(Pairs), sort_values);

//Loop to overwrite duplicates
int j = 1;
for(int i = 1; i < n; i++){
    if(pairs[i].value != pairs[i-1].value){
        pairs[j++] = pairs[i];
    }
}

//Making new array
Pairs new_pairs[j];

//Copying over sorted elements
for(int i = 0; i < j; i++){
    new_pairs[i] = pairs[i];
}

//Using qsort() to sort elements over by keys
qsort(new_pairs, j, sizeof(Pairs), sort_pos);

//Printing out values
for(int i = 0; i < j; i++){
    printf("[%d]: %d\n",new_pairs[i].pos, new_pairs[i].value);
}
    return 0;
}
