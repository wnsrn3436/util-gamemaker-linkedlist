#include "list.h"

LIST *FIRST, *LAST, *L_POS;
DATA *D_POS;
double Count_Index = 0, List_Number = 0, Data_Pos = 0;

double list_create()
{
    if(List_Number==0)
    {
        FIRST = new LIST;
        FIRST->index = 0;
        FIRST->next = FIRST;
        FIRST->back = FIRST;
        FIRST->size = 0;
        LAST = FIRST;
        //최초 리스트 생성 
    }
    else
    {
        LIST *buffer = new LIST;
        buffer->index = Count_Index;
        buffer->next = FIRST;
        buffer->back = LAST;
        buffer->size = 0;
        LAST->next = buffer;
        LAST = buffer;
        //추가 리스트 생성 
    }
    List_Number++;
    Count_Index++;
    return Count_Index-1;
}

double list_set_index(double index)
{
    if(List_Number!=0)
    {
        LIST *buffer = FIRST;
        do
        {
            if(buffer->index==index){L_POS = buffer; list_data_set_read_pos(0); return 1;}
            else{buffer = buffer->next;}
        }while(buffer != FIRST);
        L_POS = LAST; list_data_set_read_pos(0);
    }
    return 0;
}

void list_destroy()
{
    if(L_POS->size!=0)
    {
        DATA *buffer = L_POS->first, *buffer2;
        for(double i=0; i!=L_POS->size; i++)
        {
            buffer2 = buffer->next;
            delete buffer;
            buffer = buffer2;
        }
        //리스트 데이터 제거 
    }
    if(FIRST==L_POS)
    {
        LIST *buffer = FIRST->next;
        buffer->back = buffer;
        delete FIRST;
        FIRST = buffer;
        LAST->next = buffer;
        //최초 리스트 제거 
    }
    else
    {
        if(LAST==L_POS){LAST = LAST->back;}
        LIST *buffer = L_POS->next, *buffer2 = L_POS->back;
        delete L_POS;
        buffer->back = buffer2;
        buffer2->next = buffer;
        //추가 리스트 제거 
    }
    List_Number--;
}

void list_data_clear()
{
    if(L_POS->size!=0)
    {
        DATA *buffer = L_POS->first, *buffer2;
        for(double i=0; i!=L_POS->size; i++)
        {
            buffer2 = buffer->next;
            delete buffer;
            buffer = buffer2;
        }
        L_POS->size = 0;
    }
}

void list_data_add(double data)
{
    if(L_POS->size==0)
    {
        L_POS->first = new DATA;
        L_POS->first->data = data;
        L_POS->first->next = L_POS->first;
        L_POS->first->back = L_POS->first;
        L_POS->last = L_POS->first;
        L_POS->size++;
        list_data_set_read_pos(0);
        //최초 데이터 삽입 
    }
    else
    {
        DATA *buffer = new DATA;
        buffer->data = data;
        buffer->next = L_POS->first;
        buffer->back = L_POS->last;
        L_POS->last->next = buffer;
        L_POS->last = buffer;
        L_POS->size++;
        //추가 데이터 삽입 
    }
}

double list_data_set_read_pos(double pos)
{
    if(L_POS->size!=0)
    {
        if(L_POS->size>=pos)
        {
            DATA *buffer = L_POS->first;
            for(double i=0; i!=pos; i++)
            {
                buffer = buffer->next;
            }
            D_POS = buffer;
            Data_Pos = pos;
            return 1;
        }
        D_POS = L_POS->last;
        Data_Pos = L_POS->size-1;
    }
    return 0;
}

double list_data_get_read_pos()
{
    return Data_Pos;
}

double list_data_get_size()
{
    return L_POS->size;
}

double list_data_get_data()
{
    if(L_POS->size==0){return 0;}
    double data = D_POS->data;
    D_POS = D_POS->next;
    Data_Pos++;
    if(Data_Pos>L_POS->size){Data_Pos=0;}
    return data;
}

double list_data_get_data_delete()
{
    if(L_POS->size==0){return 0;}
    L_POS->size--;
    double data = D_POS->data;
    if(L_POS->first==D_POS)
    {
        DATA *buffer = D_POS->next;
        buffer->back = buffer;
        delete D_POS;
        L_POS->first = buffer;
        L_POS->last->next = buffer;
        list_data_set_read_pos(0);
        //읽기 위치가 최초 위치일 때 
    }
    else
    {
        if(L_POS->last==D_POS){L_POS->last = L_POS->last->back; Data_Pos--;}
        DATA *buffer = D_POS->next, *buffer2 = D_POS->back;
        delete D_POS;
        buffer2->next = buffer;
        list_data_set_read_pos(Data_Pos);
        //읽기 위치가 중간 부분일 때 
    }
    return data;
}

void list_data_delete()
{
    if(L_POS->size!=0)
    {
        L_POS->size--;
        if(L_POS->first==D_POS)
        {
            DATA *buffer = D_POS->next;
            buffer->back = buffer;
            delete D_POS;
            L_POS->first = buffer;
            list_data_set_read_pos(0);
            //읽기 위치가 최초 위치일 때 
        }
        else
        {
            if(L_POS->last==D_POS){L_POS->last = L_POS->last->back; Data_Pos--;}
            DATA *buffer = D_POS->next, *buffer2 = D_POS->back;
            delete D_POS;
            buffer->back = buffer2;
            buffer2->next = buffer;
            list_data_set_read_pos(Data_Pos);
            //읽기 위치가 중간 부분일 때 
        }
    }
}

void list_data_replace(double data)
{
    if(L_POS->size!=0)
    {
        D_POS->data = data;
    }
}

void list_data_insert(double data)
{
    if(L_POS->size!=0)
    {
        L_POS->size++;
        if(L_POS->first==D_POS)
        {
            DATA *buffer = L_POS->first;
            L_POS->first = new DATA;
            L_POS->first->data = data;
            L_POS->first->next = buffer;
            L_POS->first->back = L_POS->first;
            buffer->back = L_POS->first;
            L_POS->last->next = L_POS->first;
            list_data_set_read_pos(0);
            //읽기 위치가 최초 위치일 때 
        }
        else
        {
            DATA *buffer = new DATA;
            buffer->data = data;
            buffer->next = D_POS->next;
            buffer->back = D_POS;
            D_POS->next->back = buffer;
            D_POS->next = buffer;
            list_data_set_read_pos(Data_Pos);
            //읽기 위치가 중간 부분일 때 
        }
    }
}
