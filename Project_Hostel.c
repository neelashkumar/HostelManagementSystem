#include<stdio.h>
#include<stdlib.h>
int num_boys_app=0;
int num_girls_app=0;
int num_boys=0;
int num_girls=0;
struct details
{
    int admission_no;
    char name[20];
    char degree[7];
    char course[7];
    char native_place[10];
    int room_no;
    struct details *next;
}*head1=NULL,*head2=NULL,*p,*q,*temp;
void insert_app()
{
    printf("\n1.Boy\n2.Girl");
    int op;
    scanf("%d",&op);
    if(op==1)
        insert_boys_app();
    else
        insert_girls_app();
}
void insert_boys_app()
{
    int co=0;
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen("boys", "r");
    if(fp == NULL)
    {
        printf("\nCould not open file");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
            count = count + 1;
    }
    fclose(fp);
   co=count-1;
   num_boys_app=co;
    if(co>=20)
        printf("\nAll rooms are full no place for allocation");
    else
    {
        temp=(struct details*)malloc(sizeof(struct details));
        printf("\nEnter the details\nEnter admission number in 3 digits\nAdmission_no:");
        scanf("%d",&(temp->admission_no));
        printf("\nName:");
        scanf("%s",temp->name);
        printf("\nDegree:");
        scanf("%s",temp->degree);
        printf("\nCourse:");
        scanf("%s",temp->course);
        printf("\nNative_place:");
        scanf("%s",temp->native_place);
        if(head1==NULL)
        {
            head1=temp;
            temp->next=NULL;
        }
        else
        {
            p=head1;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            temp->next=NULL;
        }
        num_boys_app+=1;
        temp->room_no=num_boys_app%5;
        if(temp->room_no==0)
            temp->room_no=5;
         printf("\nRoom no is %d",temp->room_no);
         FILE *p1;
         p1=fopen("boys","a");
         fprintf(p1,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%d",temp->admission_no,temp->name,temp->degree,temp->course,temp->native_place,temp->room_no);
         fclose(p1);
    }

}
void insert_girls_app()
{
    int co=0;
    FILE *fp;
    int count = 0;
    char c;
    fp = fopen("girls", "r");
    if(fp == NULL)
    {
        printf("\nCould not open file");
        return 0;
    }
    for (c = getc(fp); c != EOF; c = getc(fp))
    {
        if (c == '\n')
            count = count + 1;
    }
    fclose(fp);
   co=count-1;
   num_girls_app=co;
    if(co>=20)
        printf("\nAll rooms are full no place for allocation");
    else
    {
        temp=(struct details*)malloc(sizeof(struct details));
        printf("\nEnter the details\nEnter admission number in 3 digits\nAdmission_no:");
        scanf("%d",&(temp->admission_no));
        printf("\nName:");
        scanf("%s",temp->name);
        printf("\nDegree:");
        scanf("%s",temp->degree);
        printf("\nCourse:");
        scanf("%s",temp->course);
        printf("\nNative_place:");
        scanf("%s",temp->native_place);
        if(head2==NULL)
        {
            head2=temp;
            temp->next=NULL;
        }
        else
        {
            p=head2;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=temp;
            temp->next=NULL;
        }
        num_girls_app+=1;
        temp->room_no=num_girls_app%5;
        if(temp->room_no==0)
            temp->room_no=5;
         printf("\nRoom no is %d",temp->room_no);
         FILE *p1;
         p1=fopen("girls","a");
         fprintf(p1,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%d",temp->admission_no,temp->name,temp->degree,temp->course,temp->native_place,temp->room_no);
         fclose(p1);
    }

}
void find_student_app()
{
    int ad_no,flag=0,no1[3],i=0,ch=0,a,j=1,op;
    char c,no[4];
    printf("\n1.Boy\n2.Girl");
    scanf("%d",&op);
    if(op==1)
    {
        printf("\nEnter the admission number of the  student\t");
        scanf("%d",&ad_no);
        FILE *p1;
        p1=fopen("boys","r");
        if(p1==NULL)
        {
            printf("\nCould not open file");
            return 0;
        }
        for (c = getc(p1); c != EOF; c = getc(p1))
        {
            if (c == '\n')
            {
                c=getc(p1);
                no[0]=c-48;
                c=getc(p1);
                no[1]=c-48;
                c=getc(p1);
                no[2]=c-48;
                no[3]='\0';
                no1[2]=ad_no%10;
                no1[1]=ad_no%100;
                no1[1]=no1[1]/10;
                no1[0]=ad_no/100;
                i=0;
                while(i<3)
                {
                    if(no[i]==no1[i])
                    {
                        ch=1;
                    }
                    else
                    {
                        ch=0;
                        break;
                    }
                    ++i;
                }
                if(ch==1)
                {
                    printf("\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
                    printf("\n%d",ad_no);
                    flag=1;
                    while((c=getc(p1))!='\n')
                    {
                        printf("%c",c);
                        if(c==EOF)
                            return 0;
                    }

                }
            }
        }
        fclose(p1);
    }
    else if(op==2)
    {
        printf("\nEnter the admission number of the  student\t");
        scanf("%d",&ad_no);
        FILE *p1;
        p1=fopen("girls","r");
        if(p1==NULL)
        {
            printf("\nCould not open file");
            return 0;
        }
        for (c = getc(p1); c != EOF; c = getc(p1))
        {
            if (c == '\n')
            {
                c=getc(p1);
                no[0]=c-48;
                c=getc(p1);
                no[1]=c-48;
                c=getc(p1);
                no[2]=c-48;
                no[3]='\0';
                no1[2]=ad_no%10;
                no1[1]=ad_no%100;
                no1[1]=no1[1]/10;
                no1[0]=ad_no/100;
                i=0;
                while(i<3)
                {
                    if(no[i]==no1[i])
                    {
                        ch=1;
                    }
                    else
                    {
                        ch=0;
                        break;
                    }
                    ++i;
                }
                if(ch==1)
                {
                    printf("\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
                    printf("\n%d",ad_no);
                    flag=1;
                    while((c=getc(p1))!='\n')
                    {
                        printf("%c",c);
                        if(c==EOF)
                            return 0;
                    }

                }
            }
        }
        fclose(p1);
    }
    if(flag==0)
        printf("\nInvalid admission number\nIn admission number %d there is no student",ad_no);
}
void find_room_students_app()
{
    int op;
    printf("\n1.Boys\n2.Girls\t");
    scanf("%d",&op);
    if(op==1)
        boys_rooms_app();
    else
        girls_rooms_app();
}
void boys_rooms_app()
{
    int ro_no,ro,flag=0,co=0,count;
    char c;
    printf("\nEnter the room number\t");
    scanf("%d",&ro_no);
    if(ro_no==5)
        ro_no=0;
    FILE *p1;
    p1=fopen("boys","r");
    if(p1==NULL)
    {
        printf("\nCould not open file");
        return 0;
    }
    c=getc(p1);
    while(c!=EOF)
    {
        if(co==0)
        {
            while((c=getc(p1))!='\n')
            {
                count=0;
                co=1;
            }
        }
        while((c=getc(p1))!=EOF)
        {
            if((co%5)==ro_no)
            {
                if(count==0)
                {
                    printf("\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
                    count=1;
                }
                printf("\n%c",c);
                while((c=getc(p1))!='\n')
                {
                    printf("%c",c);
                    flag=1;
                    if(c==EOF)
                        return 0;
                }
            }
            if(c=='\n')
                ++co;
        }
    }

    fclose(p1);
    if(flag==0&&ro_no==0)
        printf("\nThere is no students in room number 5");
    else if(flag==0)
        printf("\nThere is no students in room number %d",ro_no);

}
void girls_rooms_app()
{
    int ro_no,ro,flag=0,co=0,count;
    char c;
    printf("\nEnter the room number\t");
    scanf("%d",&ro_no);
    if(ro_no==5)
        ro_no=0;
    FILE *p1;
    p1=fopen("girls","r");
    if(p1==NULL)
    {
        printf("\nCould not open file");
        return 0;
    }
    c=getc(p1);
    while(c!=EOF)
    {
        if(co==0)
        {
            while((c=getc(p1))!='\n')
            {
                count=0;
                co=1;
            }
        }
        while((c=getc(p1))!=EOF)
        {
            if((co%5)==ro_no)
            {
                if(count==0)
                {
                    printf("\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
                    count=1;
                }
                printf("\n%c",c);
                while((c=getc(p1))!='\n')
                {
                    printf("%c",c);
                    flag=1;
                    if(c==EOF)
                        return 0;
                }
            }
            if(c=='\n')
                ++co;
        }
    }

    fclose(p1);
    if(flag==0&&ro_no==0)
        printf("\nThere is no students in room number 5");
    else if(flag==0)
        printf("\nThere is no students in room number %d",ro_no);
}
void insert()
{
    printf("\n1.Boy\n2.Girl");
    int op;
    scanf("%d",&op);
    if(op==1)
        insert_boys();
    else if(op==2)
        insert_girls();

}
void insert_boys()
{
    FILE *ptr;
    ptr=fopen("boys","r");
    if(ptr==NULL||num_boys!=0)
    {
        fclose(ptr);
        int co=0;
        p=head1;
        while(p!=NULL)
        {
            co+=1;
            p=p->next;
        }
        if(co>=20)
            printf("\nAll rooms are full no place for allocation");
        else
        {
            temp=(struct details*)malloc(sizeof(struct details));
            printf("\nEnter the details\nEnter the admission number in 3 digits\nAdmission_no:");
            scanf("%d",&(temp->admission_no));
            printf("\nName:");
            scanf("%s",temp->name);
            printf("\nDegree:");
            scanf("%s",temp->degree);
            printf("\nCourse:");
            scanf("%s",temp->course);
            printf("\nNative_place:");
            scanf("%s",temp->native_place);
            if(head1==NULL)
            {
                head1=temp;
                temp->next=NULL;
            }
            else
            {
                p=head1;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p->next=temp;
                temp->next=NULL;
            }
            num_boys+=1;
            temp->room_no=num_boys%5;
            if(temp->room_no==0)
                temp->room_no=5;
            printf("\nRoom no is %d",temp->room_no);
            FILE *p1;
            p1=fopen("boys","a");
            if(num_boys==1)
                fprintf(p1,"\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
            fprintf(p1,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%d",temp->admission_no,temp->name,temp->degree,temp->course,temp->native_place,temp->room_no);
            fclose(p1);
        }
    }
    else
    {
        fclose(ptr);
        printf("\nAlready room is allocated so select\nAlready room allocation done choice");
    }

}
void insert_girls()
{
    FILE *ptr;
    ptr=fopen("girls","r");
    if(ptr==NULL||num_girls!=0)
    {
        fclose(ptr);
        int co1=0;
        p=head2;
        while(p!=NULL)
        {
            co1+=1;
            p=p->next;
        }
        if(co1>=20)
            printf("\nAll rooms are full no place for allocation");
        else
        {
            temp=(struct details*)malloc(sizeof(struct details));
            printf("\nEnter the details\nEnter the admission number in 3 digits\nAdmission_no:");
            scanf("%d",&(temp->admission_no));
            printf("\nName:");
            scanf("%s",temp->name);
            printf("\nDegree:");
            scanf("%s",temp->degree);
            printf("\nCourse:");
            scanf("%s",temp->course);
            printf("\nNative_place:");
            scanf("%s",temp->native_place);
            if(head2==NULL)
            {
                head2=temp;
                temp->next=NULL;
            }
            else
            {
                p=head2;
                while(p->next!=NULL)
                {
                    p=p->next;
                }
                p->next=temp;
                temp->next=NULL;
            }
            num_girls+=1;
            temp->room_no=num_girls%5;
            if(temp->room_no==0)
                temp->room_no=5;
            printf("\nRoom no is %d",temp->room_no);
            FILE *p2;
            p2=fopen("girls","a");
            if(num_girls==1)
                fprintf(p2,"\nAdmission_no\tName\t\tDegree\t\tCourse\t\tNative_place\t\tRoom no");
            fprintf(p2,"\n%d\t\t%s\t\t%s\t\t%s\t\t%s\t\t\t%d",temp->admission_no,temp->name,temp->degree,temp->course,temp->native_place,temp->room_no);
            fclose(p2);
        }
    }
    else
    {
        fclose(ptr);
        printf("\nAlready room is allocated so select\nAlready room allocation done choice");
    }
}
int main()
{
    int ch,op1,choice;
    printf("Sona College Of Technology\n\tSalem-5");
    printf("\nHostel rooms allocation for first year students 2017-2018\nThe total number of rooms for boys is 5\nThe total number of rooms for girls is 5");
    printf("\nIn each room 4 students can stay");
    printf("\n1.First time allocating rooms\n2.Already room allocation done\t");
    scanf("%d",&choice);
    if(choice==1)
    {
        a:
            printf("\nEnter 1 to continue\t");
            scanf("%d",&ch);
            while(ch==1)
            {
                printf("\n1.Entering the details\n2.Finding particular students\n3.Finding particular room students\t");
                scanf("%d",&op1);
                switch(op1)
                {
                    case 1:insert();break;
                    case 2:find_student_app();break;
                    case 3:find_room_students_app();break;
                }
                printf("\nEnter 1 to continue\nEnter 2 to go to Already room allocation done option\nEnter 3 to exit\t");
                scanf("%d",&ch);
                if(ch==2)
                    choice=2;
                else if(ch==3)
                    return 0;
            }
    }
    if(choice==2)
    {
        printf("\nEnter 1 to continue\t");
        scanf("%d",&ch);
        while(ch==1)
        {
            printf("\n1.Entering the details\n2.Finding particular students\n3.Finding particular room students\t");
            scanf("%d",&op1);
            switch(op1)
            {
                case 1:insert_app();break;
                case 2:find_student_app();break;
                case 3:find_room_students_app();break;
            }
            printf("\nEnter 1 to continue\nEnter 2 to go to First time allocating rooms option\nEnter 3 to exit\t");
            scanf("%d",&ch);
            if(ch==2)
                goto a;
            else if(ch==3)
                return 0;
        }
    }
    return 0;
}