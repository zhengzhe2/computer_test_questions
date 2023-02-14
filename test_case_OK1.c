#include "test_case_OK1.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _df_h_type
{
    char data[1024];
    int size;
    struct _df_h_type* next; 
}df_h_type;


int convert_G_2_M(char* size_str)
{
    if (strlen(size_str) == 0) {
        return 0;
    }
    double size = 0.0;
    if (*(size_str + (strlen(size_str) - 1)) == 'G') {
        *(size_str + (strlen(size_str) - 1)) = '\0';
        size = atof(size_str) * 1024;
    }
    if (*(size_str + (strlen(size_str) - 1)) == 'M') {
        *(size_str + (strlen(size_str) - 1)) = '\0';
        size = atof(size_str);
    }
    return (int)size;
}

void sort(df_h_type* df_h_array)
{
    df_h_type* p = df_h_array;
    df_h_type* q = NULL;
    while (p) {
        q = p->next;
        while (q) {
            if (p->size > q->size) {
                char temp[1024];
                int temp_size;
                strcpy(temp, p->data);
                temp_size = p->size;
                strcpy(p->data, q->data);
                p->size = q->size;
                strcpy(q->data, temp);
                q->size =temp_size;
            }
            q = q->next;
        }
        p = p->next;
    }
}

void solution_1()
{
    char out_buffer[1024];
    char* cmd = "df -h";
    FILE* pipeLine = popen(cmd, "r");
    if (!pipeLine) {
        perror("Fail to popen\n");
        return;
    }
    df_h_type* p_tail = NULL;
    df_h_type* p_context = (df_h_type*)malloc(sizeof(df_h_type));
    if (p_context == NULL) {
        return;
    }
    memset(p_context, 0, sizeof(df_h_type));
    p_tail = p_context;
    int line_index = 0;
    int index = 0;
    char title_buffer[1024];
    while(fgets(out_buffer, 1024, pipeLine) != NULL) {
        char temp_buffer[1024] = {0};
        strcpy(temp_buffer, out_buffer);
        char* sub_field = NULL;
        if (line_index == 0) {
            strcpy(title_buffer, temp_buffer);
            for (sub_field = strtok(temp_buffer, " "); sub_field != NULL; sub_field = strtok(NULL, " ")) {
                if (strcmp(sub_field, "Size") == 0) {
                    break;
                }
                ++index;
            }
        } 
        else {
            if (line_index == 1) {
                strcpy(p_tail->data, out_buffer);
                p_tail->next = NULL;
                int count = 0;
                for (sub_field = strtok(temp_buffer, " "); sub_field != NULL; sub_field = strtok(NULL, " "), ++count) {
                    if (count == index) {
                        if (sub_field == NULL) {
                            printf("sub_field is NULL");
                            return;
                        }
                        p_tail->size = convert_G_2_M(sub_field);
                        break;
                    }
                }    
            } else {
                df_h_type* p_line_info = (df_h_type*)malloc(sizeof(df_h_type));
                if (p_line_info == NULL) {
                    return;
                }
                memset(p_line_info, 0, sizeof(df_h_type));
                strcpy(p_line_info->data, out_buffer);
                int count = 0;
                for (sub_field = strtok(temp_buffer, " "); sub_field != NULL; sub_field = strtok(NULL, " "), ++count) {
                    if (count == index) {
                        if (sub_field == NULL) {
                            printf("sub_field is NULL");
                            return;
                        }
                        p_line_info->size = convert_G_2_M(sub_field);
                        break;
                    }
                }  
                p_line_info->next = NULL;
                p_tail->next = p_line_info;
                p_tail = p_line_info;
            }         
        }
        ++line_index;
    }

    sort(p_context);
    printf("%s", title_buffer);
    df_h_type* head = p_context;
    while (head != NULL)
    {
        printf("%s", head->data);
        df_h_type* temp = head->next;
        free(head);
        head = temp;
    }
    pclose(pipeLine); 
}