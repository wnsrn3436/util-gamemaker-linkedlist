#include "list.h"
#include <stdio.h>
#include <iostream>

int main()
{
    double index1 = list_create(), index2 = list_create();
    printf("[Create Test]\nindex1 : %.f\nindex2 : %.f\n\n", index1, index2);
    //리스트 인덱스 테스트 
    
    list_set_index(index1); //index 1
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index2); //index 2
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index1); //index 1
    printf("[Add Test]\nindex1 : ");
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n", list_data_get_size());
    list_set_index(index2); // index 2
    printf("index2 : ");
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n\n", list_data_get_size());
    //데이터 추가 데스트 
    
    list_set_index(index1); //index 1
    list_data_clear();
    list_set_index(index2); //index 2
    list_data_clear();
    list_set_index(index1); //index 1
    printf("[Clear Test]\nindex1 : size[%.f]\n", list_data_get_size());
    list_set_index(index2); //index 2
    printf("index2 : size[%.f]\n\n", list_data_get_size());
    //데이터 클리어 테스트 
    
    list_set_index(index1); //index 1
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index2); //index 2
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index1); //index 1
    printf("[Read Delete Test]\nindex1 : ");
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("size[%.f]\n", list_data_get_size());
    list_set_index(index2); //index 2
    printf("index2 : ");
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("%.f, ", list_data_get_data_delete());
    printf("size[%.f]\n\n", list_data_get_size());
    //데이터 읽고 지우기 테스트 
    
    list_set_index(index1); //index 1
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index2); //index 2
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index1); //index 1
    printf("[Replace Test]\nindex1 : ");
    printf("%.f, ", list_data_get_data());
    list_data_replace(100);
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n", list_data_get_size());
    list_data_clear();
    list_set_index(index2); //index 2
    printf("index2 : ");
    printf("%.f, ", list_data_get_data());
    list_data_replace(100);
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n\n", list_data_get_size());
    list_data_clear();
    //데이터 교체 테스트 
    
    list_set_index(index1); //index 1
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index2); //index 2
    list_data_add(1); list_data_add(2); list_data_add(3);
    list_set_index(index1); //index 1
    printf("[Insert Test]\nindex1 : ");
    printf("%.f, ", list_data_get_data());
    list_data_insert(100);
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n", list_data_get_size());
    list_destroy();
    list_set_index(index2); //index 2
    printf("index2 : ");
    printf("%.f, ", list_data_get_data());
    list_data_insert(100);
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("%.f, ", list_data_get_data());
    printf("size[%.f]\n", list_data_get_size());
    list_destroy();
    //데이터 삽입 테스트 
    
    std::cin.get();
    return 0;
}
