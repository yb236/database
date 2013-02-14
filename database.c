    #include<stdio.h>
    #include <string.h>
     
    int input(void);
    int search(void);
     
    int main()
    {
            int n;
     
            printf("本棚に本を追加する(1) 本棚から本を探す(2)\n>>");
     
            while(1){
                    scanf("%d", &n);
                    if(n == 1 || n == 2){
                            break;
                    }
                    printf("\a1か2の整数を入力してください！\n>>");
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
                    printf("\aファイルをオープンできません！\n");
                    return 1;
            }
     
            while(1){
                    printf("%d冊目に入れる本の名前、その本の著者、本のカテゴリーを入力してください。(CTRL + Zで終了)\n", i);
                    if((scanf("%s %s %s", name, author, category)) == EOF){
                            break;
                    }
                    fprintf(fp, "%s %s %s\n", name, author, category);
                    printf("本棚に追加しました！\n");
                    i++;
            }
            printf("終了します。\n");
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
                    printf("\aファイルをオープンできません！\n");
                    return 1;
            }
            do{
                    printf("本の名前、その本の著者、本のカテゴリーを入力してください。（わからない項目があれば0を入力）");
                    scanf("%s %s %s", name, author, category);
                    if(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0){
                            printf("\a1つ以上わかる項目を入力してください！\n");
                    }
            }while(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0);
     
            while((fscanf(fp, "%s %s %s", dname, dauthor, dcategory)) != EOF){
                    if(strcmp(name, dname) == 0 || strcmp(author, dauthor) == 0 || strcmp(category, dcategory) == 0){
                            printf("\n");
                            printf("該当する本が見つかりました！\n");
                            printf("%20s %20s %20s\n", "本の名前", "著者", "カテゴリー");
                            printf("%20s%20s%20s\n", dname, dauthor, dcategory);
                            flg = 1;
                    }
            }
            if(flg != 1){
                    printf("\a見つかりませんでした。\n");
            }
            fclose(fp);
            return 0;
    }
