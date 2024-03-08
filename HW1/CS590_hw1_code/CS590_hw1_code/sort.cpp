#include <cstdio>
#include <cstdlib>

#include "sort.h"


int ivector_length(int* v, int n)
{
  int sum;

  sum = 0;
  for (int i = 0; i < n; i++)
    sum += (v[i] < 0) ? -v[i] : v[i];

  return sum;
}

/*
 * insertion sort
 */
void insertion_sort(int** A, int n, int l, int r)
{ 
  int i;
  int* comp;

  for (int j = l+1; j <= r; j++)
    {
      comp = A[j];
      i = j - 1;

      while ((i >= l) && (ivector_length(A[i], n) > ivector_length(comp, n)))
        {
	  A[i+1] = A[i];
	  i = i - 1;
	}

      A[i+1] = comp;
    }
}

/*
*   TO IMPLEMENT: Improved Insertion Sort for problem 1.
*/
void insertion_sort_im(int** A, int n, int l, int r)
{ 
  int* comp;
  int comp_value;
  int* sumArray = new int[r+1];
  int i=0, j=0;
   
  for(i = 0; i <= r; i++) 
  {
    sumArray[i] = ivector_length(A[i], n);
  }
   
  for(i = 1; i <= r; i++) 
  {
    comp = A[i];
    comp_value = sumArray[i];
    j = i - 1;
	  
    while(j >= l && (sumArray[j] > comp_value)) 
    {
      A[j+1] = A[j];
      sumArray[j+1] = sumArray[j];
      j = j - 1;
    }
    A[j+1] = comp;
    sumArray[j+1] = comp_value;
  }
}

void merge(int** A, int* sumArray, int p , int q, int r)
{
  // Used pseudo code as reference to write below code for merge.
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r-q;   
    int Left[n1];
    int Right[n2];
    int** arrLeft = new int*[n1];
    int** arrRight = new int*[n2];
    for(int i=0;i<n1;i++)
    {
        Left[i] = sumArray[p+i];
        arrLeft[i] = A[p+i];
    }
    for(int j=0; j<n2;j++)
    {
        Right[j] = sumArray[q+1+j];
        arrRight[j] = A[q+1+j];
    }
    
    i = 0;
    j=0;
    k=p;
    
    while(i< n1 && j<n2)
    {
        if(Left[i] <= Right[j])
        {
            sumArray[k] = Left[i];
            A[k] = arrLeft[i];
            i++;
        }
        else{
            sumArray[k] = Right[j];
            A[k] = arrRight[j];
            j++;
        }
        k++;
    }

    while(i<n1)
    {
        sumArray[k] = Left[i];
        A[k] = arrLeft[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        sumArray[k] = Right[j];
        A[k] = arrRight[j];
        j++;
        k++;
    }
}

void mergesort(int** A, int* sumArray ,int p, int r)
{
    int q;
    if(p<r)
    {
        q = p + (r-p)/2;
        mergesort(A,sumArray,p, q);
        mergesort(A,sumArray,q+1, r);
        merge(A,sumArray, p,q,r);
    }
}

void merge_sort(int** A, int n, int p, int r)
{
    int* sumArray;
    sumArray = new int [r+1];
    
    //Compute the length of each vector
    for(int i=0 ; i < r+1 ;i++)
    {
        sumArray[i] = ivector_length(A[i], n);
    }
    
    mergesort(A,sumArray,p,r);
}

/*
 * Simple function to check that our sorting algorithm did work
 * -> problem, if we find position, where the (i-1)-th element is 
 *    greater than the i-th element.
 */
bool check_sorted(int** A, int n, int l, int r)
{
  for (int i = l+1; i <= r; i++)
    if (ivector_length(A[i-1], n) > ivector_length(A[i], n))
      return false;
  return true;
}


/*
 * generate sorted/reverse/random arrays of type hw1type
 */
int** create_ivector(int n, int m)
{
  int** iv_array;

  iv_array = new int*[m];
  for (int i = 0; i < m; i++)
    iv_array[i] = new int[n];

  return iv_array;
}

void remove_ivector(int** iv_array, int m)
{
  for (int i = 0; i < m; i++)
    delete[] iv_array[i];
  delete[] iv_array;
}

int** create_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = (i+j)/n;

  return iv_array;
}

int** create_reverse_sorted_ivector(int n, int m)
{
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      iv_array[i][j] = ((m-i)+j)/n;

  return iv_array;
}

int** create_random_ivector(int n, int m, bool small)
{
  random_generator rg;
  int** iv_array;

  iv_array = create_ivector(n, m);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++)
      {
	rg >> iv_array[i][j];
	if (small)
	  iv_array[i][j] %= 100;
	else
	  iv_array[i][j] %= 65536;
      }

  return iv_array;
}

