#include <iostream>
#include <cmath>

int number_of_digits(int nNumber) {
    int nSize;
    
    nSize = 0;
    while (nNumber / (int)pow(10, nSize)) {
        nSize++;
    }
    return nSize;
}

void reverse_array(int* pnArray, int nSize) {
  int nMid;

  nMid = nSize / 2;
  for (int i = 0, j = nSize - 1; i < nMid; i++, j--) {
    int nTemp;
    
    nTemp = pnArray[i];
    pnArray[i] = pnArray[j];
    pnArray[j] = nTemp;
  }
}

int* get_digits(int nNumber) {
    int nSize, nIndex;
    int *pnDigits;
    
    nSize = number_of_digits(nNumber);
    pnDigits = new int[nSize];
    
    nIndex = 0;
    while (nNumber) {
        int nRem;
        
        nRem = nNumber % 10;
        pnDigits[nIndex++] = nRem;
        nNumber /= 10;
    }

    reverse_array(pnDigits, nSize);
    return pnDigits;
}

int main() {
    int *pnDigits;
    int nNumber, nSize;

    nNumber = 1001;
    pnDigits = get_digits(nNumber);
    nSize = number_of_digits(nNumber);

    for (int i = 0; i < nSize; i++)
      std::cout << pnDigits[i] << '\n';

    delete[] pnDigits;
}
