/**This program implements the kSmall algorithm and partition function to find the kth smallest element in an array. 
Mohammad Aryan Khan 
py9242yg 
09/27/2023 
Instructor: Jie Meichsner 
*/ 

#include <iostream> 
using namespace std; 

  
/*Partition function to rearrange elements in the array and calculate the pivot's index 
 * @param list_of_elements pointer to the array 
 * @param first_indice first index of the array 
 * @param last_indice last index of the array 
 * @pre while the left_side indice is less than or equal to to the right_side indice. 
 * @post right_side index of pivot 
 */ 

int partition(int *list_of_elements, int first_indice, int last_indice) { 
  int pivot=list_of_elements[first_indice];//pivot is the first element of the array 
  int left_side=first_indice + 1; 
  int right_side=last_indice; 
  while (left_side<=right_side) { 
    while (list_of_elements[left_side] < pivot && left_side <= last_indice) {  
      left_side++; 
    } 
    while (list_of_elements[right_side] > pivot && right_side >= first_indice) { 
      right_side--; 
    } 
    if (left_side<=right_side) { 
      int temp=list_of_elements[left_side];                //swaps the elements 
      list_of_elements[left_side]=list_of_elements[right_side]; 
      list_of_elements[right_side]=temp; 
      left_side++; 
      right_side--; 
    } 
  } 
  list_of_elements[first_indice]=list_of_elements[right_side]; 
  list_of_elements[right_side]=pivot; 
  return right_side; 
} 

/*kSmall function to find the kth smallest element in the array 
 * @param list_of_elements pointer to the array 
 * @param first_indice first index of the array 
 * @param last_indice last index of the array 
 * @param k index to find the kth smallest element 
 * @pre none 
 * @post kth smallest element in the array 
 */ 

int kSmall(int *list_of_elements, int first_indice, int last_indice, int k) { 
  int pivotIndex=partition(list_of_elements, first_indice, last_indice); 
  if (pivotIndex==k) { 
    return list_of_elements[k]; 
  } 
  if (k<pivotIndex) { 
    return kSmall(list_of_elements, first_indice, pivotIndex - 1, k); 
  } 
  else { 
    return kSmall(list_of_elements, pivotIndex + 1, last_indice, k); 
  } 
} 

  

int main() { 

  int size; 
  cout<<"Enter the number of elements in the array(must be an integer!): "; 
  cin>>size; 
  int *arr=new int[size];// dynamic array generated using new operator 
  cout<<"List the elements in the following way for example: 1 3 5 6 4 8 9\n"; 
  cout<<"Enter the elements of the array(integers only!): "; 
  for (int i=0; i<size; i++) { 
    cin>>arr[i]; 
  } 
  int k; 
  cout<<"Enter the index of the kth smallest element to find(integer only!): "; 
  cin>>k; 
  k=k-1; 
  int result=kSmall(arr, 0, size - 1, k); 
  cout<<"The " <<k + 1<<" smallest element is: "<<result<<endl; 
  delete[] arr; 
  return 0; 

} 
