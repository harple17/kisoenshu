#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX_STUDENT 100
#define MAX_SUBJECT 30
#define N 32

struct SCORE {
    struct STUDENT *p_student_arr;
    struct SUBJECT *p_subject_arr;
    struct SCORE *p_student;
    struct SCORE *p_subject;
    int score;
};
struct STUDENT {
    struct SCORE *p_score;
    char stu_num[N];
    char fam_name[N];
    char first_name[N];
    char phone_num[N];    
}STUDENT[MAX_STUDENT];
int NUM_OF_STUDENT;
struct SUBJECT {
    struct SCORE *p_score;
    char name[N];
}SUBJECT[MAX_SUBJECT];
int NUM_OF_SUBJECT;
void init() {
    NUM_OF_STUDENT=0;
    NUM_OF_SUBJECT=0;
    for (int i=0;i<MAX_STUDENT;i++) STUDENT[i].p_score=NULL;
    for (int i=0;i<MAX_SUBJECT;i++) SUBJECT[i].p_score=NULL;
}
void addStudent(char *sn,char *famn,char *fstn,char *phn) {
    int i;
    for (i=0;i<NUM_OF_STUDENT&&strcmp(STUDENT[i].stu_num,"EMPTY");i++);
    if(i>=MAX_STUDENT) {
        printf("overflow(cannnot add another subject)\n");
        return ;
    }
    strcpy(STUDENT[i].stu_num,sn);
    strcpy(STUDENT[i].fam_name,famn);
    strcpy(STUDENT[i].first_name,fstn);
    strcpy(STUDENT[i].phone_num,phn); 
    if(i==NUM_OF_STUDENT) NUM_OF_STUDENT++;
}
void addSubject(char *sn) {
    int i;
    for (i=0;i<NUM_OF_SUBJECT&&strcmp(SUBJECT[i].name,"EMPTY");i++);
    if(i>=MAX_SUBJECT) {
        printf("overflow(cannnot add another subject)\n");
        return ;
    }
    strcpy(SUBJECT[i].name,sn);
    if(i==NUM_OF_SUBJECT) NUM_OF_SUBJECT++;
}
void regSub(int reg_num_stu,int reg_num_sub,int score) {
    if(reg_num_stu>=NUM_OF_STUDENT||reg_num_sub>=NUM_OF_SUBJECT) {
        printf("cannnot register(student or subject does not exist)\n");
    }
    struct SCORE *p=(struct SCORE*)malloc(sizeof(struct SCORE));
    p->p_student=STUDENT[reg_num_stu].p_score;
    STUDENT[reg_num_stu].p_score=p;
    p->p_student_arr=&STUDENT[reg_num_stu];
    p->p_subject=SUBJECT[reg_num_sub].p_score;
    SUBJECT[reg_num_sub].p_score=p;
    p->p_subject_arr=&SUBJECT[reg_num_sub];
    p->score=score;
}
void delSub(int reg_num_stu,int reg_num_sub) {
    struct SCORE *p=STUDENT[reg_num_stu].p_score;
    struct SCORE *tmp;
    while(p->p_subject_arr!=&SUBJECT[reg_num_sub]) {
        tmp=p;
        p=p->p_student;
        if (p==NULL) {
            printf("not found\n");
            return ;
        }
    }
    if (p==STUDENT[reg_num_stu].p_score) {
        STUDENT[reg_num_stu].p_score=p->p_student;
        p->p_student=NULL;
    }else {
        tmp->p_student=p->p_student;
        p->p_student=NULL;
    }
    p=SUBJECT[reg_num_sub].p_score;
    while(p->p_student_arr!=&STUDENT[reg_num_stu]) {
        tmp=p;
        p=p->p_subject;
        if (p==NULL) {
            printf("not found\n");
            return ;
        }
    }
    if (p==SUBJECT[reg_num_sub].p_score) {
        SUBJECT[reg_num_sub].p_score=p->p_subject;
        p->p_subject=NULL;
    }else {
        tmp->p_subject=p->p_subject;
        p->p_subject=NULL;
    }
    free(p);
}
void deleteStudent(int reg_num_stu) {
    struct SCORE *p;
    for (int i=0;i<NUM_OF_SUBJECT;i++) {
        p=STUDENT[reg_num_stu].p_score;
        while(p!=NULL) {
            if (p->p_subject_arr==&SUBJECT[i]) {
                delSub(reg_num_stu,i);
            }
            p=p->p_student;
        }
    }
    strcpy(STUDENT[reg_num_stu].stu_num,"EMPTY");
    strcpy(STUDENT[reg_num_stu].fam_name,"EMPTY");
    strcpy(STUDENT[reg_num_stu].first_name,"EMPTY");
    strcpy(STUDENT[reg_num_stu].phone_num,"EMPTY"); 
}
void deleteSubject(int reg_num_sub) {
    struct SCORE *p;
    for (int i=0;i<NUM_OF_STUDENT;i++) {
        p=SUBJECT[reg_num_sub].p_score;
        while(p!=NULL) {
            if (p->p_student_arr==&STUDENT[i]) {
                delSub(reg_num_sub,i);
            }
            p=p->p_subject;
        }
    }
    strcpy(SUBJECT[reg_num_sub].name,"EMPTY");
}
void showRegisterdStudent() {
    for (int i=0;i<NUM_OF_STUDENT;i++) {
        printf("Register Number%d\nStudent Number:%s|Family Name:%s|First Name:%s|Phone Number:%s\n",i,STUDENT[i].stu_num,STUDENT[i].fam_name,STUDENT[i].first_name,STUDENT[i].phone_num);
    }
}
void showRegisterdSubject() {
    for (int i=0;i<NUM_OF_SUBJECT;i++) {
        printf("Register Number%d\nSubject Name:%s\n",i,SUBJECT[i].name);
    }
}
void printIndAveandStd(int reg_num_stu) {
    struct SCORE *p=STUDENT[reg_num_stu].p_score;
    int c=0;
    int sum=0;
    int pow2_sum=0;
    if (p==NULL) {
        printf("no score\n");
        return ;
    }
    while(p!=NULL) {
        sum+=p->score;
        pow2_sum+=p->score*p->score;
        c++;
        p=p->p_student;
    }
    double ave=sum/c;
    printf("Indivisual Average:%lf\n",ave);
    if (c>1) printf("Indivisual Standard Deviation:%lf\n",sqrt((pow2_sum/c-ave*ave)/(c-1)));
}
void printSubAveandStd(int reg_num_sub) {
    struct SCORE *p=SUBJECT[reg_num_sub].p_score;
    int c=0;
    int sum=0;
    int pow2_sum=0;
    if (p==NULL) {
        printf("no score\n");
        return ;
    }
    while(p!=NULL) {
        sum+=p->score;
        pow2_sum+=p->score*p->score;
        c++;
        p=p->p_subject;
    }
    double ave=sum/c;
    printf("Subject Average:%lf\n",ave);
    if (c>1) printf("Subject Standard Deviation:%lf\n",sqrt((pow2_sum/c-ave*ave)/(c-1)));
}

int main() {
    init();
    int option,yn,reg,reg_stu,reg_sub,score;
    char stu_num[N],fam_name[N],first_name[N],phone_num[N],sub_name[N];
    do {
        printf("Select an action>>1:Add Student 2:Delete Student 3:Add Subject 4:Delete Subject 5:Register Score 6:Remove Score 7:Show personal average and standard deviation 8:Show Subject Average and standard deviation 9:See Register Data of Student 10:See Register Data of Subject 0:End\n");
        scanf("%d",&option);
        if (option==1) {
            printf("Add a student. Input some info.\n");
            printf("student number:"); scanf("%s",stu_num);
            printf("family name:"); scanf("%s",fam_name);
            printf("first name:");  scanf("%s",first_name);
            printf("phone number:"); scanf("%s",phone_num);
            addStudent(stu_num,fam_name,first_name,phone_num);
        }
        if (option==2) {
            printf("Delete a Student. All data realted to the student will be cleared. Continue? (prepare register number by using \"See Register Data of Student\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number\n");
                scanf("%d",&reg);
                deleteStudent(reg);
            }
            if (yn==1) continue;
        }
        if (option==3) {
            printf("Add a subject. Input info.\n");
            printf("Subject name:"); scanf("%s",sub_name);
            addSubject(sub_name);
        }
        if (option==4) {
            printf("Delete a Subject. Continue? (prepare register number by using \"See Register Data of Subject\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number\n");
                scanf("%d",&reg);
                deleteSubject(reg);
            }
            if (yn==1) continue;
        }
        if (option==5) {
            printf("Register Score (prepare register number by using \"See Register Data of Student\" and \"See Register Data of Subject\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number of student and that of subject and score\n");
                printf("register number of student:"); scanf("%d",&reg_stu);
                printf("register number of subject:"); scanf("%d",&reg_sub);
                printf("score:"); scanf("%d",&score);
                regSub(reg_stu,reg_sub,score);
            }
            if (yn==1) continue;
        }
        if (option==6) {
            printf("Delete Score (prepare register number by using \"See Register Data of Student\" and \"See Register Data of Subject\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number of student and that of subject\n");
                scanf("%d",&reg_stu);
                scanf("%d",&reg_sub);
                delSub(reg_stu,reg_sub);
            }
            if (yn==1) continue;
        }
        if (option==7) {
            printf("Show Indivisual Average of Score and Standard Deviation (prepare register number by using \"See Register Data of Student\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number of student\n");
                scanf("%d",&reg_stu);
                printIndAveandStd(reg_stu);
            }
            if (yn==1) continue;
        }
        if (option==8) {
            printf("Show Subject's Average of Score and Standard Deviation (prepare register number by using \"See Register Data of Subject\")0:Continue 1:Back\n");
            scanf("%d",&yn);
            if (yn==0) {
                printf("input register number of subject\n");
                scanf("%d",&reg_sub);
                printSubAveandStd(reg_sub);
            }
            if (yn==1) continue;
        }
        if (option==9) showRegisterdStudent();
        if (option==10) showRegisterdSubject(); 
    } while (option!=0);
    
    return 0;
}