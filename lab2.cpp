#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void shakerPartyMaker(int* array, int size, bool log);
void ViborkaParty(int* arr, int a);
void VstavkaParty(int* arr, int a);
void BubbleParty(int* arr, int a);
void Timer(int* arr, int size);
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int arr[10];
    for (int i = 0; i < 10; i++) {
        arr[i] = rand() % 160;
    }
    for (int i = 0; i < 10; i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;
    cout << "Відсортований масив: " << endl;
    shakerPartyMaker(arr, 10, true);
 
    int* arr1 = new int[880];
    int* arr21 = new int[8800];
    int* arr31 = new int[88000];
    Timer(arr1, 880);
    Timer(arr21, 8800);
    Timer(arr31, 88000);
}
void shakerPartyMaker(int* array, int size, bool log) {
    int left = 0, right = size - 1; //границі масиву
    int check = 1; //перевірка чи відбуваєтсья переміщення
    while ((left < right) && check > 0) {
        check = 0;
        for (int i = left; i < right; i++) { //*Прохід знизу вгору*
            if (array[i] > array[i + 1]) {
                int t = array[i];
                array[i] = array[i + 1];
                array[i + 1] = t;
                check = 1;
                if (log) {
                    for (int i = 0; i < 10; i++) {
                        cout << array[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        right--;
        for (int i = right; i > left; i--) { //*Прохід з гори вниз*
            if (array[i - 1] > array[i]) {
                int t = array[i];
                array[i] = array[i - 1];
                array[i - 1] = t;
                check = 1;
                if (log) {
                    for (int i = 0; i < 10; i++) {
                        cout << array[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
        left++;
    }
}
void ViborkaParty(int* arr, int a) {
    
    for (int i = 0; i < a; i++) {
        int min = arr[i];
        for (int j = i+1; j < a; j++) {
            if (arr[i] > arr[j]) {
                min = arr[i];
                arr[i] = arr[j];
                arr[j] = min;
            }
        }
    } 
}
void VstavkaParty(int* arr, int a) {
    for (int i = 0; i < a; i++) {//Прохід по масиву
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--) {
            int elem = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = elem;
        }
    }
}
void BubbleParty(int* arr, int a) {
    for (int i = 0; i < a - 1; i++) {
        for (int j = i + 1; j < a; j++) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
                
            }
        }
    }
}
void Timer(int* arr, int size) {
    int* arr1 = new int[size];
    int* arr2 = new int[size];
    int* arr3 = new int[size];
    for (int i = 0; i < size; i++) {
        arr[i] = arr1[i] = arr2[i] = arr3[i] = rand() % 10000;
    }
    cout << "Cортування масиву на " << (size) << " елементів... " << endl;
    double start = clock();
    BubbleParty(arr, size);
    double end = clock();
    cout << "Час сортування бабл: " << (end - start) / 1000.0 << endl;
    cout << "////////////////////////////////////" << endl;
    start = clock();
    shakerPartyMaker(arr1, size, false);
    end = clock();
    cout << "Час сортування шейкер: " << (end - start) / 1000.0 << endl;
    cout << "////////////////////////////////////" << endl;
    start = clock();
    ViborkaParty(arr2, size);
    end = clock();
    cout << "Час сортування виборкою: " << (end - start) / 1000.0 << endl;
    cout << "////////////////////////////////////" << endl;
    start = clock();
    VstavkaParty(arr3, size);
    end = clock();
    cout << "Час сортування вставкою: " << (end - start) / 1000.0 << endl;
    cout << "////////////////////////////////////" << endl;
    cout << endl;
}
