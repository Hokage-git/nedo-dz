#include <iostream>
#include <ctime>
#include <cstring>
#include <string.h>
#include <conio.h>
#define Endl (cout<<endl)

using namespace std;

void sum_prev(int mounth, int *day,int days[]) {
    for (int i = 0; i < mounth; i++) 
        *day += days[i];
}

void days() {
    int day1 = 0;
    int day2 = 0;
    int mounth1 = 0;
    int mounth2 = 0;
    int year1 = 0;
    int year2 = 0;
    int day = 0;
    int mounth = 0;
    int year = 0;
    int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int sum_days = 0;

    cout << "\t\tПримечание: 1 дата должна быть больше 2!!";
    Endl;
    cout << "Введите дату по принципу День Месяц Год через пробелы:";
    cin >> day1 >> mounth1 >> year1;
    Endl;
    cout << "Введите ещё одну дату по принципу День Месяц Год через пробелы:";
    cin >> day2 >> mounth2 >> year2;
    Endl;

    if (year1 % 400 == 0 || year2 % 400 == 0) {
        days[1] = 29;
    }
    else if (year1 % 100 == 0 || year2 % 100 == 0) {
        days[1] = 28;
    }
    else if (year1 % 4 == 0 || year2 % 4 == 0) {
        days[1] = 29;
    }
    else {
        days[1] = 28;
    }

    for (int i = 0; i < 12; ++i)
        sum_days += days[i];

    sum_prev(mounth1, &day1, days);
    sum_prev(mounth2, &day2, days);
    
    year1 *= sum_days;
    year2 *= sum_days;
    
    day1 += year1;
    day2 += year2;
    day += day1 - day2;

    cout << "Между датами " << day << " дней";
    Endl; Endl;
}

void Massive(int arr[]) {
    int size = 0;
    double sum = 0;
    cout << "Введите размер массива-";
    cin >> size;
    arr = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = rand() * 100 / RAND_MAX;
        cout << arr[i] << " ";
    }

    for (int i = 0; i < size; i++)
        sum += arr[i];

    sum = sum / size;
    cout << "Среднее арифметическое=" << sum;
    delete[] arr;
    Endl; Endl;
}

void sort(int arr[]) {
    int poloz = 0;
    int nulevie = 0;
    int otric = 0;
    int size = 0;
    cout << "Введите размер массива-";
    cin >> size;
    arr = new int[size];
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr[i] = 20 - rand() * 40 / RAND_MAX;
        cout << arr[i] << " ";
    }
    Endl;

    for (int i = 0; i < size; i++) {
        if (arr[i] > 0)
            poloz++;
        if (arr[i] == 0)
            nulevie++;
        if (arr[i] < 0)
            otric++;
    }
    cout << "Положительных-" << poloz;
    Endl;
    cout << "Отрицательные-" << otric;
    Endl;
    cout << "Нулевые-" << nulevie;
    Endl; Endl;
    delete[] arr;
}

void matrix(int** matrix) {
    int num;
    int var;
    cin >> num;
    int* min = new int[num];

    matrix = new int* [num];
    for (int i = 0; i < num; i++) {
        matrix[i] = new int[num];
    }

    for (int i = 0; i < num; i++) {
        Endl;
        for (int j = 0; j < num; j++) {
            matrix[i][j] = 10 + rand() % 89;
            cout << matrix[i][j] << " ";
        }
    }
    Endl;
    for (int i = 0; i < num; i++) {
        min[i] = matrix[i][0];
    }

    for (int i = 0; i < num;i++) {
        for (int j = 0; j < num; j++) {
            if (min[i] > matrix[i][j+1]) {
                var = matrix[i][j+1];
                matrix[i][j+1]= min[i];
                min[i] = var;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        Endl;
        for (int j = 0; j < num; j++) {
            cout << matrix[i][j] << " ";
        }
    }

    for (int i = 0; i < num; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    Endl; Endl;
}

void matrix(char** matrix) {
    int num;
    int var;
    cin >> num;
    int* min = new int[num];

    matrix = new char* [num];
    for (int i = 0; i < num; i++) {
        matrix[i] = new char[num];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            matrix[i][j] = 10 + rand() % 89;
        }
    }

    for (int i = 0; i < num; i++) {
        min[i] = matrix[i][0];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (min[i] > matrix[i][j]) {
                var = min[i];
                min[i] = matrix[i][j];
                matrix[i][j] = var;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        Endl;
        for (int j = 0; j < num; j++) {
            cout << matrix[i][j] << " ";
        }
    }

    for (int i = 0; i < num; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    Endl; Endl;
}

void matrix(double** matrix) {
    int num;
    int var;
    cin >> num;
    int* min = new int[num];

    matrix = new double* [num];
    for (int i = 0; i < num; i++) {
        matrix[i] = new double[num];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            matrix[i][j] = 10 + rand() % 89;
        }
    }

    for (int i = 0; i < num; i++) {
        min[i] = matrix[i][0];
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (min[i] > matrix[i][j]) {
                var = min[i];
                min[i] = matrix[i][j];
                matrix[i][j] = var;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        Endl;
        for (int j = 0; j < num; j++) {
            cout << matrix[i][j] << " ";
        }
    }

    for (int i = 0; i < num; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    Endl; Endl;
}

int main()
{
    system("color F0");
    setlocale(LC_ALL, "rus");
    auto a = 0;
    int arr1[1];
    days();
    Massive(arr1);
    sort(arr1);
    int** arr = 0;
    char** zarr = 0;
    double** carr = 0;
    int chooser;
    cout << "1.double\n2.int\n3.char\n";
    cin >> chooser;
    switch (chooser) {
    case 3:
        matrix(zarr);
        break;
    case 2:
        matrix(arr);
        break;
    case 1:
        matrix(carr);
        break;
    }

    //strncat(); это тоже 
    //char c;
    //do {
    //	c = _getch();

    //} while (('1' > c) || (c < '4'));
}
