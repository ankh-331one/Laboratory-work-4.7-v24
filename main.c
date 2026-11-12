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
int input(char name, char mass, l_diapazon, r_diapazon);

void mass_input(FILE* in_X, int nx, int mx, double** *X);
void mass_print(FILE output, char a, int nx, int mz, double** X);
void mass_free(int nx, doube** *X);

void vvod_new_mass(int mx, double* *new_X, int nx, double** X, double zadan_znach);
void new_mass_print(char a, int ma, doible* new_X);

double 

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
    setlocale(0,"");
    setlocale(LC_NUMERIC, "C");
    
    FIlE* out_file = fopen("output.txt", "a");
    fprintf(out_file, "лабораторная 4.7 v24 запуск: %s %s", __DATE__, __TIME__);
    
    FILE* in_A = fopen("input_A", "r");
    int na = input('n', 'A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int ma = input('m', 'A', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double** A;
    mass_input(in_A,na,ma,&A);
    fclose(in_A);
    
    FILE* in_B = fopen("input_B", "r");
    int nb = input('n', 'B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int mb = input('m', 'B', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double** B;
    mass_input(in_B,nb,mb,&B);
    fclose(in_B);
    
    FILE* in_C = fopen("input_C", "r");
    int nc = input('n', 'C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    int mc = input('m', 'C', L_DIAPAZON_MASSIV, R_DIAPAZON_MASSIV);
    double** C;
    mass_input(in_C,nc,mc,&C);
    fclose(in_C);
    
    double zadan_znach;
    printf("vvod zadan znach: ");
    scanf("%lf", &zadan_znach);
    
    mass_print(out_file, 'A', na, ma, A);
    mass_print(out_file, 'B', nb, mb, B);
    mass_print(out_file, 'C', nc, mc, C);
    fprintf(out_file, "vvedeno zadan_znach: %.3f", zadan_znach);
    
    double* new_A;
    vvod_new_mass(ma, &new_A, na, A, zadan_znach);
    
    double* new_B;
    vvod_new_mass(mb, &new_B, nb, B, zadan_znach);
    
    double* new_C;
    vvod_new_mass(mc, &new_C, nc, C, zadan_znach);
    
    fprintf(out_file, "result:");
    new_mass_print('A', ma, new_A);
    new_mass_print('B', mb, new_B);
    new_mass_print('C', mc, new_C);
    
    fclose(out_file);
    mass_free(na, &A);
    mass_free(nb, &B);
    mass_free(nc, &C);
    free(new_A), new_A = NULL;
    free(new_B), new_B = NULL;
    free(new_C), new_C = NULL;
    return 0;
}