#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<stdbool.h>
// Structure for the term in the polynomial
struct Term {
    float coefficient;
    float exponent;
};

// Structure for the Sparse matrix
struct SparseMatrix {
    int numRows;
    int numCols;
    int numTerms;
    struct Term* terms;
};
struct Element{
    char *p; //pointer to traverse
    int size; //size of the array
    int used; //no of used elements
};
bool create(struct Element *E, size_t Arr_size){
    E->p=(char *)malloc(sizeof(char)*Arr_size); //malloc function allocating memory to *p struct char array
    if(E->p==NULL && Arr_size<=0){
    return false;
    }
    else{
    E->size=Arr_size;
    E->used=0;
    return true;
    }
}
// function to increase the memory allocated
bool incsize(struct Element *E){
    size_t newSize;
    newSize=E->size*2; //increasing the size by *2 increments
    E->p=(char *)realloc(E->p,sizeof(int)*newSize); 
    if(E->p==NULL && newSize==0){
    return false;
    }
    else{
    E->size=newSize;
    return true;
    }
}
bool freeEle(struct Element *E){
    if(E->size!=0)
    free(E->p);
    if(E->p==NULL)
    return true;
    else
    return false;
}
// Function to create a sparse matrix for the polynomial using Arrays.
void create(struct SparseMatrix* poly, int numberTerms) {
    poly->numTerms=numberTerms;
    poly->numRows = poly->numTerms;
    poly->numCols = 2;
    poly->terms = (struct Term*)malloc(poly->numTerms * sizeof(struct Term));
    
}
// Display Function
void display(struct SparseMatrix poly) {
    printf("Polynomial: ");
    for (int i = 0; i < poly.numTerms; i++) {
        printf("%f*x^%f ", poly.terms[i].coefficient, poly.terms[i].exponent);
        if (i < poly.numTerms - 1) {
            printf("+ ");
        }
    }
    printf("\n");
}
// Addition Function Adding two Polynomials
struct SparseMatrix add(struct SparseMatrix poly1, struct SparseMatrix poly2) {
    struct SparseMatrix result;
    result.numRows = poly1.numRows + poly2.numRows;
    result.numCols = poly1.numCols;
    result.numTerms = poly1.numTerms + poly2.numTerms;
    result.terms = (struct Term*)malloc(result.numTerms * sizeof(struct Term));

    int i = 0, j = 0, k = 0;
    // When the exponent of the first polynomial is greater than the second.
    while (i < poly1.numTerms && j < poly2.numTerms) {
        if (poly1.terms[i].exponent > poly2.terms[j].exponent) {
            result.terms[k] = poly1.terms[i];
            i++;
            // When the exponent of the second polynomial is greater than the first.
        } else if (poly1.terms[i].exponent < poly2.terms[j].exponent) {
            result.terms[k] = poly2.terms[j];
            j++;
            // When the exponents are equal
        } else {
            result.terms[k].coefficient = poly1.terms[i].coefficient + poly2.terms[j].coefficient;
            result.terms[k].exponent = poly1.terms[i].exponent;
            i++;
            j++;
        }
        k++;
    }
     // Copy the remaining terms of the first polynomial, if any
    while (i < poly1.numTerms) {
        result.terms[k] = poly1.terms[i];
        i++;
        k++;
    }
     // Copy the remaining terms of the second polynomial, if any
    while (j < poly2.numTerms) {
        result.terms[k] = poly2.terms[j];
        j++;
        k++;
    }

    return result;
}

void swap(struct Term* a, struct Term* b) {
    struct Term temp = *a;
    *a = *b;
    *b = temp;
}

int partition(struct SparseMatrix* poly, int low, int high) {
    int pivot = poly->terms[high].exponent;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (poly->terms[j].exponent < pivot) {
            i++;
            swap(&poly->terms[i], &poly->terms[j]);
        }
    }

    swap(&poly->terms[i + 1], &poly->terms[high]);
    return i + 1;
}

void quickSort(struct SparseMatrix* poly, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(poly, low, high);
        quickSort(poly, low, pivotIndex - 1);
        quickSort(poly, pivotIndex + 1, high);
    }
}

float minElement(struct SparseMatrix poly){
       // Find the minimum exponent value
       float minExponent;
    for (int i = 1; i < poly.numTerms; i++) {
        if (poly.terms[i].exponent < minExponent) {
            minExponent = poly.terms[i].exponent;
        }
    }
    return minExponent;
}

struct SparseMatrix multiply(struct SparseMatrix poly1, struct SparseMatrix poly2){
    struct SparseMatrix result;
    result.numCols=poly1.numCols;
    result.numRows=poly1.numRows+poly2.numRows;
    result.numTerms=0;
    result.terms=(struct Term*)malloc(result.numTerms*sizeof(struct Term));
    size_t sizeOfTerm = sizeof(result.terms);
    int i,j;
    for(i=0; i<poly1.numTerms; i++){
        for(j=0; j<poly2.numTerms; j++){
            float coefficient = poly1.terms[i].coefficient * poly2.terms[j].coefficient;
            float exponent = poly1.terms[i].exponent + poly2.terms[j].exponent;
            result.terms[result.numTerms].coefficient = coefficient;
            result.terms[result.numTerms].exponent = exponent;
            result.numTerms++;

        }
    }
    return result;
}




int main() {
    //Create two polynomials
    struct SparseMatrix polynomial1;
    struct SparseMatrix polynomial2;
int x,y;
printf("Enter number of terms for poly1:");
scanf("%d",&x);
    create(&polynomial1,x);
    quickSort(&polynomial1,minElement(polynomial1),polynomial1.numTerms-1);
    display(polynomial1);
printf("Enter number of terms for poly2:");
scanf("%d",&y);
    create(&polynomial2,y);
    quickSort(&polynomial2,minElement(polynomial2),polynomial2.numTerms-1);
    display(polynomial2);
    //display(add(polynomial1,polynomial2));
    display(multiply(polynomial1,polynomial2));


    free(polynomial1.terms);
    free(polynomial2.terms);
    


    return 0;
}
