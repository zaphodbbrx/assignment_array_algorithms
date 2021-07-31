#include <iostream>
#include <vector>
#include "misc.h"

void task1(){
    /*
    Задача 1

    Вам даётся массив целых чисел. Необходимо найти такие два индекса i и j в этом массиве,
    что сумма a[i], a[i+1], a[i+2], … a[j] будет максимально возможной и вывести их.
    Пример:
        a = {-2,1,-3,4,-1,2,1,-5,4}
    Тогда наибольшая сумма последовательных элементов находится между индексами 3 и 6:
        {4,-1,2,1}, сумма = 6. Необходимо вывести 3 и 6
     * */
//    std::vector<int> a = {-2,1,-3,4,-1,2,1,-5,4};
    std::vector<int> a;
    enterVector(a);

    int start = 0, end = 0;
    int sum = a[0], sumCur;
    for (int i = 0; i < a.size(); ++i){
        sumCur = a[i];
        for (int j = i + 1; j < a.size(); ++j){
            sumCur += a[j];
            if (sumCur > sum){
                sum = sumCur;
                start = i;
                end = j;
            }
        }
    }

    std::cout << "start: " << start << " end: " << end  << " sum: " << sum << std::endl;
}

void task2(){
    /*
    Задача 2

    Вам даётся массив целых чисел и одно число -- результат. Необходимо найти в массиве 2 числа, сумма которых будет
    давать результат, и вывести их на экран. Гарантируется, что только одна пара чисел в массиве даёт в сумме результат.
    Пример:
    a = {2, 7, 11, 15}. Результат = 9
    2 + 7 = 9, так что надо вывести числа 2 и
     * */
    std::vector<int> a;
    int res = -1, n1 = 0, n2 = 0;
    enterVector(a);
    enterData(res, INT_MIN, INT_MAX, "res");
    for (int i = 0; i < a.size() - 1; ++i){
        for (int j = i+1; j < a.size(); ++j){
            if(a[i] + a[j] == res) {
                n1 = a[i];
                n2 = a[j];
                break;
            }
        }
    }
    std::cout << "n1: " << n1 << " n2: " << n2 << std::endl;
}

void task3(){
    /*
     Задача 3

    С клавиатуры вводятся числа. Когда пользователь вводит -1 -- необходимо выводить на экран пятое по возрастанию число
    среди введённых. Когда пользователь вводит -2 -- программа завершает работу.
    Пример:
    ввод: 7 5 3 1 2 4 6 -1
    вывод: 5 (в отсортированном виде массив выглядит так: {1,2,3,4,5,6,7})
    ввод: 1 1 1 -1
    вывод: 2 (в отсортированном виде массив выглядит так: {1,1,1,1,2,3,4,5,6,7})
    ввод -2
    завершение программы
     * */
    int fifthElement=INT_MIN, insertIdx=0, nextElement=9000;
    std::vector<int> queue(5, INT_MAX) ;
    while(nextElement != -2){
        enterData(nextElement, INT_MIN, INT_MAX, "next element");
        if (nextElement != -1) {
            insertIdx = 0;
            for (int i = 0; i < queue.size(); i++) {
                if (nextElement < queue[i]) {
                    insertIdx++;
                } else {
                    break;
                }
            }
            for (int i = 1; i <= insertIdx-1; i++) {
                queue[i - 1] = queue[i];
            }
            queue[insertIdx-1] = nextElement;
        }else{
            std::cout << queue[0] << std::endl;
        }
    }
}

void task4(){
    /*
     Задача 4

    Вам даётся массив целых чисел, отсортированных по возрастанию. Необходимо вывести его на экран отсортированным
    в порядке возрастания модуля чисел
    Пример:
    Массив {-100,-50, -5, 1, 10, 15}
    Вывод: 1, -5, 10, 15, -50, -100
    Задание со звёздочкой: оптимизировать решение четвёртой задачи, чтобы оно совершало как можно меньше операций
     */
//    std::vector<int> vec = {-100,-50, -5, 1, 10, 15};
    std::vector<int> vec;
    enterVector(vec);
    int numNegative=0;
    // find number of negative elements
    for (int x : vec){
        if(x < 0){
            numNegative++;
        }
        else{
            break;
        }
    }
    // iterate over them
    for (int i = numNegative - 1; i >= 0; i--){
        // swap numbers for which negative number abs is larger than positive number
        for (int j = i + 1; j < vec.size(); j++){
            if (-vec[j - 1] > vec[j]){
                // do the swap
                swapValVector(vec, j - 1, j);
            }
        }
    }
    for(int x : vec){
        std::cout << x << ", ";
    }
}

int main() {
    int taskNum=0;
    enterData(taskNum, 1, 4, "task number");
    switch (taskNum) {
        case 1:
            task1();
            break;
        case 2:
            task2();
            break;
        case 3:
            task3();
            break;
        case 4:
            task4();
            break;
        default:
            std::cout << "Illegal task number" << std::endl;
            break;

    }
    return 0;
}
