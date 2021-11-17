#include <iostream>
#include <cmath>

/*  
    2.haftanın görevi switch fonksiyonunun kullanımı ile alakalı. 
    Ancak for while yapılarının nasıl kullanıldıklarını öğrenip fonksiyonlara kadar çalışmanızı öneririm çünkü onları atlayacağız.
    Hedef: [1-999] arası girilen sayının yazıyla yazdırılması. (Bitişik ve Türkçe olmalı) 
*/

using namespace std;

string ONES[10] = {"","bir", "iki", "üç", "dört", "beş", "altı", "yedi", "sekiz", "dokuz"};
string TENS[10] = {"","on", "yirmi", "otuz", "kırk", "elli", "altmış", "yetmiş", "seksen", "doksan"};
string HUNDREDS[9] = {"yüz", "ikiyüz", "üçyüz", "dörtyüz", "beşyüz", "altıyüz", "yediyüz", "sekizyüz", "dokuzyüz"};

// Function prototypes
string inWritten(int x);

int main(){

    int number;
    cout << "Type the number: ";
    cin >> number;

    string text = inWritten(number);

    cout << text;

    return 0;
}

// Function to translate integers into their pronunciation
string inWritten(int x){

    // Check how much digits does the number have.
    int digit = log10(x);

    string xInWritten;

    // Create the text
    switch(digit){
        case 0:
            xInWritten = ONES[x];
            break;
        case 1:
            xInWritten = TENS[x/10] + ONES[x%10];
            break;
        case 2:
            xInWritten = HUNDREDS[x/100-1] + TENS[(x%100)/10] + ONES[x%10];
            break;
    }
    
    return xInWritten;
}