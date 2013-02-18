    #include<stdio.h>
    #include <string.h>
     
    int input(void);	//�f�[�^�x�[�X�ɒǉ����邽�߂̎���֐�
    int search(void);	//�f�[�^�x�[�X���猟�����邽�߂̎���֐�
     
    int main()
    {
            int n;	//�����^�Ő錾
     
            printf("�{�I�ɖ{��ǉ�����(1) �{�I����{��T��(2)\n>>");
     
            while(1){	//�������[�v
                    scanf("%d", &n);	//n�����
                    if(n == 1 || n == 2){	//n��1�܂���2�Ȃ��
                            break;	//���[�v�E�o
                    }
                    printf("\a1��2�̐�������͂��Ă��������I\n>>");		//\a�̓r�[�v����炷�G�X�P�[�v�V�[�P���X
            }
     
            switch(n){
                    case 1:		//n��1�Ȃ��
                            input();	//input�֐������s
                            break;
                    case 2:		//n��2�Ȃ��
                            search();		//search�֐������s
                            break;
            }
            return 0;
    }
     
    int input(void)
    {
            FILE *fp;	//�t�@�C���I�[�v���ɗp����ϐ�
            char name[64];	//�������i�[����ϐ�
            char author[64];	//���҂��i�[����ϐ�
            char category[64];	//�{�̃J�e�S�����i�[����ϐ�
            int i = 1;
     
            if((fp = fopen("database.txt", "a")) == NULL){		//database.txt���ǋL���[�h(a)�ŊJ���Ȃ�������
                    printf("\a�t�@�C�����I�[�v���ł��܂���I\n");
                    return 1;	//1��Ԃ��ċً}�E�o
            }
     
            while(1){
                    printf("%d���ڂɓ����{�̖��O�A���̖{�̒��ҁA�{�̃J�e�S���[����͂��Ă��������B(CTRL + Z�ŏI��)\n", i);
                    if((scanf("%s %s %s", name, author, category)) == EOF){		//Crl + Z���ł����܂Ń��[�v
                            break;
                    }
                    fprintf(fp, "%s %s %s\n", name, author, category);		//fp�̕ϐ��ŊJ���Ă���t�@�C���ɁA�����A���ҁA�J�e�S�����������݉��s����
                    printf("�{�I�ɒǉ����܂����I\n");
                    i++;	//i = i + 1�Ɠ���
            }
            printf("�I�����܂��B\n");
            fclose(fp);		//�t�@�C�������
     
            return 0;
    }
     
    int search(void)
    {
            FILE *fp;
            char name[64];
            char author[64];
            char category[64];
            char dname[64];		//�f�[�^�x�[�X����E���Ă����������i�[����
            char dauthor[64];	//�f�[�^�x�[�X����E���Ă������҂��i�[����
            char dcategory[64];	//�f�[�^�x�[�X����E���Ă����J�e�S�����i�[����
            int flg;
     
            if((fp = fopen("database.txt", "r")) == NULL){	//database.txt���ǂݎ�胂�[�h(r)�ŊJ���Ȃ�������
                    printf("\a�t�@�C�����I�[�v���ł��܂���I\n");
                    return 1;
            }
            do{
                    printf("�{�̖��O�A���̖{�̒��ҁA�{�̃J�e�S���[����͂��Ă��������B�i�킩��Ȃ����ڂ������0����́j");
                    scanf("%s %s %s", name, author, category);		//�{�̖��O�A���ҁA�J�e�S�������
                    if(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0){		//�����A���ҁA�J�e�S�����ׂ�0���ł���Ă�����
                            printf("\a1�ȏ�킩�鍀�ڂ���͂��Ă��������I\n");
                    }
            }while(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0);
     
            while((fscanf(fp, "%s %s %s", dname, dauthor, dcategory)) != EOF){		//fp�̕ϐ��ŊJ���Ă���t�@�C������A�����A���ҁA�J�e�S���̏����擾���e�ϐ��ɑ������ �����EOF(�ŏI�s)�܂ő�����
                    if(strcmp(name, dname) == 0 || strcmp(author, dauthor) == 0 || strcmp(category, dcategory) == 0){	//name��dname����v���Ă��邩�Aauthor��dauthor����v���Ă��邩�Acategory��dcategory����v���Ă���Ȃ��
                            printf("\n");
                            printf("�Y������{��������܂����I\n");
                            printf("%-20s%-20s%-20s\n", "�{�̖��O", "����", "�J�e�S���[");	//20�o�C�g���̗̈��p���ďo�́i���ɑ����j
                            printf("%-20s%-20s%-20s\n", dname, dauthor, dcategory);		//20�o�C�g���̗̈��p���ďo�́i���ɑ����j
                            flg = 1;		//���ł��Y������{�����������ꍇ��flg��1��������
                    }
            }
            if(flg != 1){		//flg��1�ȊO�i�Y������{��������Ȃ������j�Ȃ��
                    printf("\a������܂���ł����B\n");
            }
            fclose(fp);
            return 0;
    }
