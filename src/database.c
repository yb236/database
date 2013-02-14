    #include<stdio.h>
    #include <string.h>
     
    int input(void);
    int search(void);
     
    int main()
    {
            int n;
     
            printf("�{�I�ɖ{��ǉ�����(1) �{�I����{��T��(2)\n>>");
     
            while(1){
                    scanf("%d", &n);
                    if(n == 1 || n == 2){
                            break;
                    }
                    printf("\a1��2�̐�������͂��Ă��������I\n>>");
            }
     
            switch(n){
                    case 1:
                            input();
                            break;
                    case 2:
                            search();
                            break;
            }
            return 0;
    }
     
    int input(void)
    {
            FILE *fp;
            char name[64];
            char author[64];
            char category[64];
            int i = 1;
     
            if((fp = fopen("database.txt", "a")) == NULL){
                    printf("\a�t�@�C�����I�[�v���ł��܂���I\n");
                    return 1;
            }
     
            while(1){
                    printf("%d���ڂɓ����{�̖��O�A���̖{�̒��ҁA�{�̃J�e�S���[����͂��Ă��������B(CTRL + Z�ŏI��)\n", i);
                    if((scanf("%s %s %s", name, author, category)) == EOF){
                            break;
                    }
                    fprintf(fp, "%s %s %s\n", name, author, category);
                    printf("�{�I�ɒǉ����܂����I\n");
                    i++;
            }
            printf("�I�����܂��B\n");
            fclose(fp);
     
            return 0;
    }
     
    int search(void)
    {
            FILE *fp;
            char name[64];
            char author[64];
            char category[64];
            char dname[64];
            char dauthor[64];
            char dcategory[64];
            int flg;
     
            if((fp = fopen("database.txt", "r")) == NULL){
                    printf("\a�t�@�C�����I�[�v���ł��܂���I\n");
                    return 1;
            }
            do{
                    printf("�{�̖��O�A���̖{�̒��ҁA�{�̃J�e�S���[����͂��Ă��������B�i�킩��Ȃ����ڂ������0����́j");
                    scanf("%s %s %s", name, author, category);
                    if(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0){
                            printf("\a1�ȏ�킩�鍀�ڂ���͂��Ă��������I\n");
                    }
            }while(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0);
     
            while((fscanf(fp, "%s %s %s", dname, dauthor, dcategory)) != EOF){
                    if(strcmp(name, dname) == 0 || strcmp(author, dauthor) == 0 || strcmp(category, dcategory) == 0){
                            printf("\n");
                            printf("�Y������{��������܂����I\n");
                            printf("%20s %20s %20s\n", "�{�̖��O", "����", "�J�e�S���[");
                            printf("%20s%20s%20s\n", dname, dauthor, dcategory);
                            flg = 1;
                    }
            }
            if(flg != 1){
                    printf("\a������܂���ł����B\n");
            }
            fclose(fp);
            return 0;
    }
