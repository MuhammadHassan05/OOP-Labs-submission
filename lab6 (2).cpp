//#include <iostream>
//using namespace std;
//
//// Function to sort poly in decreasing order of expo
//void sortPolynomial(int* coeff, int* expo, int size) 
//{
//    for (int i = 0; i < size - 1; i++) 
//    {
//        for (int j = i + 1; j < size; j++)
//        {
//            if (expo[i] < expo[j]) 
//            {
//                int tempExpo = expo[i];
//                expo[i] = expo[j];
//                expo[j] = tempExpo;
//                int tempCoeff = coeff[i];
//                coeff[i] = coeff[j];
//                coeff[j] = tempCoeff;
//            }
//        }
//    }
//}
//
//// Function to combine like terms
//void combineLikeTerms(int* coeff, int* expo, int& size)
//{
//    for (int i = 0; i < size; i++) 
//    {
//        for (int j = i + 1; j < size;) 
//        {
//            if (expo[i] == expo[j])
//            {
//                coeff[i] += coeff[j];
//                // shift elements to left
//                for (int k = j; k < size - 1; k++) 
//                {
//                    coeff[k] = coeff[k + 1];
//                    expo[k] = expo[k + 1];
//                }
//                size--;
//            }
//            else 
//            {
//                j++;
//            }
//        }
//    }
//}
//
//// Function to input polynomial
//void inputPolynomial(int*& coeff, int*& expo, int& size)
//{
//    int terms;
//    cout << "Enter number of terms "<<endl;
//    cin >> terms;
//    int* tempCoeff = new int[terms];
//    int* tempExpo = new int[terms];
//    for (int i = 0; i < terms; i++)
//    {
//        cout << "Enter coefficient and exponent for term " << i + 1 << "= "<<endl;
//        cin >> tempCoeff[i] >> tempExpo[i];
//    }
//    coeff = new int[terms];
//    expo = new int[terms];
//    size = 0;
//    for (int i = 0; i < terms; i++)
//    {
//        bool found = false;
//        for (int j = 0; j < size; j++) 
//        {
//            if (expo[j] == tempExpo[i]) 
//            {
//                coeff[j] += tempCoeff[i];
//                found = true;
//                break;
//            }
//        }
//        if (!found) 
//        {
//            coeff[size] = tempCoeff[i];
//            expo[size] = tempExpo[i];
//            size++;
//        }
//    }
//
//    sortPolynomial(coeff, expo, size);
//    combineLikeTerms(coeff, expo, size);
//
//    delete[] tempCoeff;
//    delete[] tempExpo;
//}
//
//// Function to display polynomial
//void displayPolynomial(int* coeff, int* expo, int size) 
//{
//    for (int i = 0; i < size; i++) 
//    {
//        if (coeff[i] == 0) 
//            continue;
//        if (i > 0 && coeff[i] > 0) 
//            cout << " + ";
//            cout << coeff[i];
//        if (expo[i] != 0) 
//            cout << "x^" << expo[i];
//    }
//    cout << endl;
//}
//
//// Function to add two polynomials
//void addPolynomials(int* c1, int* e1, int size1,
//                    int* c2, int* e2, int size2,
//                    int*& resultCoeff, int*& resultExpo, int& resultSize)
//{
//    resultSize = size1 + size2;
//    resultCoeff = new int[resultSize];
//    resultExpo = new int[resultSize];
//    int k = 0;
//    for (int i = 0; i < size1; i++) 
//    {
//        resultCoeff[k] = c1[i];
//        resultExpo[k] = e1[i];
//        k++;
//    }
//    for (int i = 0; i < size2; i++) 
//    {
//        resultCoeff[k] = c2[i];
//        resultExpo[k] = e2[i];
//        k++;
//    }
//    resultSize = k;
//    sortPolynomial(resultCoeff, resultExpo, resultSize);
//    combineLikeTerms(resultCoeff, resultExpo, resultSize);
//}
//
//// Function to multiply two polynomials
//void multiplyPolynomials(int* c1, int* e1, int size1,
//                         int* c2, int* e2, int size2,
//                         int*& resultCoeff, int*& resultExpo, int& resultSize) 
//{
//    resultSize = size1 * size2;
//    resultCoeff = new int[resultSize];
//    resultExpo = new int[resultSize];
//    int k = 0;
//    for (int i = 0; i < size1; i++)
//    {
//        for (int j = 0; j < size2; j++)
//        {
//            resultCoeff[k] = c1[i] * c2[j];
//            resultExpo[k] = e1[i] + e2[j];
//            k++;
//        }
//    }
//    resultSize = k;
//    sortPolynomial(resultCoeff, resultExpo, resultSize);
//    combineLikeTerms(resultCoeff, resultExpo, resultSize);
//}
//
//// Main function
//int main() {
//    int* coeff1, * expo1, size1;
//    int* coeff2, * expo2, size2;
//    int* sumCoeff, * sumExpo, sumSize;
//    int* prodCoeff, * prodExpo, prodSize;
//
//    cout << "******* Input First Polynomial *******" << endl;
//    inputPolynomial(coeff1, expo1, size1);
//    cout << "Polynomial 1 is ";
//    displayPolynomial(coeff1, expo1, size1);
//    cout << endl;
//    cout << "****** Input Second Polynomial ******" << endl;
//    inputPolynomial(coeff2, expo2, size2);
//    cout << "Polynomial 2 is ";
//    displayPolynomial(coeff2, expo2, size2);
//    cout << endssl;
//    cout << "****** Addition Result ******" << endl;
//    addPolynomials(coeff1, expo1, size1, coeff2, expo2, size2, sumCoeff, sumExpo, sumSize);
//    cout << "Sum = ";
//    displayPolynomial(sumCoeff, sumExpo, sumSize);
//    cout << endl;
//    cout << "****** Multiplication Result ******" << endl;
//    multiplyPolynomials(coeff1, expo1, size1, coeff2, expo2, size2, prodCoeff, prodExpo, prodSize);
//    cout << "Product = ";
//    displayPolynomial(prodCoeff, prodExpo, prodSize);
//
//    // delete memory
//    delete[] coeff1;
//    delete[] expo1;
//    delete[] coeff2;
//    delete[] expo2;
//    delete[] sumCoeff;
//    delete[] sumExpo;
//    delete[] prodCoeff;
//    delete[] prodExpo;
//
//    return 0;
//}
