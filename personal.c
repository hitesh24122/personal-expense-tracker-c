#include <stdio.h>
#include <string.h>
struct personal_expense
{
    int id;
    char title[50];
    char category[50];
    float amount;
};
void load_file(struct personal_expense s[], int *count);
void add_expense(struct personal_expense s[], int *count);
void display_expense(struct personal_expense s[]);
void search_expense(struct personal_expense s[], int count);
void total_expense();
void highest_expense();
void Category_wise_Expenses();
void Update_Expense(struct personal_expense s[], int count);
void Delete_Expense(struct personal_expense s[], int *count);
int main()
{
    int count = 0;
    struct personal_expense s1[1000];
    load_file(s1,&count);
    while (1)
    {
        int choice;
        printf("1. Add New Expense\n2. Display All Expenses\n3. Search Expense by ID\n4. Calculate Total Expenses\n5. Find Highest Expense\n6. Calculate Category-wise Expenses\n7. Update Expense\n8. Delete Expense\n9. Exit\n");
        scanf("%d", &choice);
        if (choice == 1)
        {
            add_expense(s1, &count);
        }
        else if (choice == 2)
        {
            display_expense(s1);
        }
        else if (choice == 3)
        {
            search_expense(s1, count);
        }
        else if (choice == 4)
        {
            total_expense();
        }
        else if (choice == 5)
        {
            highest_expense();
        }
        else if (choice == 6)
        {
            Category_wise_Expenses();
        }
        else if (choice == 7)
        {
            Update_Expense(s1, count);
        }
        else if (choice == 8)
        {
            Delete_Expense(s1, &count);
        }
        else if (choice == 9)
        {
            printf("thank you\n\n");
            break;
        }
        else{
            printf("invaid choice\n");
        }
        /*for (int i = 0; i < 5; i++)
        {
            printf("%d %s %s %.2f\n", s1[i].id, s1[i].title, s1[i].category, s1[i].amount);
        }*/
    }
    return 0;
}
void add_expense(struct personal_expense s[], int *count)
{
    if (*count == 0)
    {
        printf("enter expense id:");
        scanf("%d", &s[*count].id);
        printf("enter title of expense:");
        scanf("%s", &s[*count].title);
        printf("enter category of expense:");
        scanf("%s", &s[*count].category);
        while (1)
        {
            printf("enter amount you spend:");
            scanf("%f", &s[*count].amount);
            if (s[*count].amount <= 0)
            {
                fflush(stdout);
                printf("you enter negative amount\n");
            }
            else
            {
                FILE *ptr;
                ptr = fopen("personl.txt", "a");
                fprintf(ptr, "%d %s %s %.2f\n", s[*count].id, s[*count].title, s[*count].category, s[*count].amount);
                *count = *count + 1;
                fclose(ptr);
                break;
            }
        }
    }
    else if (*count < 100)
    {
        int found = 0;
        int m = 1;
        int id;
        printf("enter expense id:");
        scanf("%d", &id);
        for (int i = 0; i < *count; i++)
        {
            if (s[i].id == id)
            {
                printf("same id found\n");
                found = 1;
                break;
            }
        }
        if (found != 1)
        {
            s[*count].id = id;
            printf("enter title of expense:");
            scanf("%s", &s[*count].title);
            printf("enter category of exponese:");
            scanf("%s", &s[*count].category);
            while (m != 0)
            {
                printf("enter amount you spend:");
                scanf("%f", &s[*count].amount);
                if (s[*count].amount <= 0)
                {
                    printf("enter nagetiver amount\n");
                }
                else
                {
                    FILE *ptr;
                    ptr = fopen("personl.txt", "a");
                    fprintf(ptr, "%d %s %s %.2f\n", s[*count].id, s[*count].title, s[*count].category, s[*count].amount);
                    m = 0;
                    *count = *count + 1;
                    fclose(ptr);
                }
            }
        }
    }
    else
    {
        printf("you reach the add limit\n\n");
    }
}
void display_expense(struct personal_expense s[])
{
    int m;
    char n[50], j[50];
    float f;
    FILE *ptr;
    ptr = fopen("personl.txt", "r");
    if (ptr == NULL)
    {
        fflush(stdout);
        printf("not data found\n");
    }
    else
    {
        while (1)
        {
            if (fscanf(ptr, "%d%s%s%f", &m, n, j, &f) == 4)
            {
                printf("| id : %d | title : %s | category : %s | amount : %.2f |\n", m, n, j, f);
            }
            else
            {
                break;
            }
        }
        fclose(ptr);
    }
}
void search_expense(struct personal_expense s[], int count)
{
    int m, id;
    char n[50], j[50];
    float f;
    if (count == 0)
    {
        printf("data is not found in file\n");
    }
    else
    {
        printf("enter id you want to search:");
        scanf("%d", &id);
        int found = 0;
        FILE *ptr;
        ptr = fopen("personl.txt", "r");
        while (1)
        {
            if (fscanf(ptr, "%d%s%s%f", &m, n, j, &f) == 4)
            {
                if (id == m)
                {
                    printf("| id : %d | title : %s | category : %s | amount : %.2f |\n", m, n, j, f);
                    found = 1;
                    break;
                }
            }
            else
            {
                break;
            }
        }
        if (found == 0)
        {
            printf("id is not found\n");
        }
        fclose(ptr);
    }
}
void total_expense()
{
    float f, sum = 0;
    int found = 0;
    FILE *ptr;
    ptr = fopen("personl.txt", "r");
    if (ptr == NULL)
    {
        printf("data is not found");
    }
    else
    {
        while (fscanf(ptr, "%*d%*s%*s%f", &f) == 1)
        {
            sum = sum + f;
        }
        printf("Total expense is : %.2f \n", sum);
        fclose(ptr);
    }
    
}
void highest_expense()
{
    int n;
    char m[50], j[50];
    float f, high = 0;
    FILE *ptr;
    ptr = fopen("personl.txt", "r");
    if (ptr == NULL)
    {
        printf("data not found\n");
    }
    else
    {
        while (fscanf(ptr, "%d%s%s%f", &n, m, j, &f) == 4)
        {
            if (f > high)
            {
                high = f;
            }
        }
        printf("%.2f", high);
        rewind(ptr);
        while (fscanf(ptr, "%d%s%s%f", &n, m, j, &f) == 4)
        {
            if (f == high)
            {
                printf("| id : %d | title : %s | category : %s | amount : %.2f |\n", n, m, j, f);
            }
        }
        fclose(ptr);
    }
}
void Category_wise_Expenses()
{
    int n, found = 0;
    char m[50], j[50], cat[50];
    float f, sum = 0;
    FILE *ptr;
    ptr = fopen("personl.txt", "r");
    if (ptr == NULL)
    {
        printf("not data found\n");
    }
    else
    {
        printf("enter category you want to find expense:");
        scanf("%s", &cat);
        while (fscanf(ptr, "%d%s%s%f", &n, m, j, &f) == 4)
        {
            printf("%s", j);
            if (strcmp(cat, j) == 0)
            {
                sum = sum + f;
                found = 1;
            }
        }
        if (found == 0)
        {
            printf("category are not found\n");
        }
        else
        {
            printf("the category %s and there expense is %.2f\n", cat, sum);
        }
        fclose(ptr);
    }
}
void Update_Expense(struct personal_expense s[], int count)
{
    float new_expense;
    int id;
    int found = 0;
    if (count == 0)
    {
        printf("data are not found\n");
    }
    else
    {
        printf("enter id you want to change expense:");
        scanf("%d", &id);
        for (int i = 0; i < count; i++)
        {
            if (s[i].id == id)
            {
                printf("enter new amount:");
                scanf("%f", &new_expense);
                s[i].amount = new_expense;
                found = 1;
            }
        }
        if (found == 0)
        {
            printf("id not found\n");
        }
        else
        {
            FILE *ptr;
            ptr = fopen("personl.txt", "w");
            for (int i = 0; i < count; i++)
            {
                fprintf(ptr, "%d %s %s %.2f\n", s[i].id, s[i].title, s[i].category, s[i].amount);
            }
            printf("update successfully\n");
            fclose(ptr);
        }
    }
}
void Delete_Expense(struct personal_expense s[], int *count)
{
    int id;
    int found=0;
    int index;
    printf("enter id you want to delete :");
    scanf("%d",&id);
    for (int i=0;i<*count;i++){
        if(id==s[i].id){
            index=i;
            found=1;
            break;
        }
    }
    if(found==1){
        for(int i=index;i<*count-1;i++){
            s[i]=s[i+1];
        }
        *count=*count-1;
        FILE *ptr;
        ptr=fopen("personl.txt","w");
        for (int i=0;i<*count;i++){
            fprintf(ptr,"%d %s %s %.2f\n",s[i].id,s[i].title,s[i].category,s[i].amount);
        }
        fclose(ptr);
    }
    else{
        printf("id not found\n");
    }

}
void load_file(struct personal_expense s[], int *count)
{
    *count = 0;
    int n, found = 0;
    char m[50], j[50];
    float f;
    FILE *ptr;
    ptr = fopen("personl.txt", "r");
    if (ptr == NULL)
    {
        printf("data not found\n");
    }
    else
    {
        for (int i = 0;; i++)
        {
            if (fscanf(ptr, "%d%s%s%f", &n, m, j, &f) == 4)
            {
                s[i].id = n;
                strcpy(s[i].title, m);
                strcpy(s[i].category, j);
                s[i].amount = f;
                *count = *count + 1;
                found = 1;
            }
            else
            {
                break;
            }
        }
        fclose(ptr);
        if (found == 1)
        {
            printf("data laod successfully\n");
        }
        else
        {
            printf("data not found\n");
        }
    }
    
}