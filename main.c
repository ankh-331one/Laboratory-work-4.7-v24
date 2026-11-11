/*
 * Лабораторная 4.7 Три двумерных массива
 * Copyright (c) 2026 ankh-331one
 *
 * Licensed under the MIT License; see LICENSE file for details.
 */
/**
Разработать программу для обработки двух или трёх двумерных массивов 
разного размера с использованием подпрограмм. При разработке подпрограмм 
предусмотреть случай, когда искомых элементов нет. Необходимо выбрать 
подходящий тип подпрограммы, для ввода и вывода тоже использовать подпрограммы. 
Будьте внимательны при выборе типа данных заданных массивов.

В каждом из трёх двумерных массивов 
определить для каждого столбца 
среднее арифметическое элементов, 
больших заданного значения. 
Сформировать из них новый массив.
*/
#ifndef P_FUNCTION.H
#define P_FUNCTION.H

#include <stdio.h>
int input(char a, l_diapazon, r_diapazon);


#endif

#include "p_function.h"
#include <malloc.h>

int input(char name, char mass, l_diapazon, r_diapazon){
    int n;
    do{
        printf("vvedine %c %c", name, mass);
        scanf("%d", &n);
        if (n < l_diapazon || n > r_diapazon){
            printf("error");
        }
    }while (n < l_diapazon || n > r_diapazon);
    return n;
}

#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include "p_function.h"

#define L_DIAPAZON_MASSIV 1
#define R_DIAPAZON_MASSIV 99

int main(void){
    int nA = input('n', 'A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int mA = input('m', 'A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    
    
    return 0;
}