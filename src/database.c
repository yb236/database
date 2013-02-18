    #include<stdio.h>
    #include <string.h>
     
    int input(void);	//データベースに追加するための自作関数
    int search(void);	//データベースから検索するための自作関数
     
    int main()
    {
            int n;	//整数型で宣言
     
            printf("本棚に本を追加する(1) 本棚から本を探す(2)\n>>");
     
            while(1){	//無限ループ
                    scanf("%d", &n);	//nを入力
                    if(n == 1 || n == 2){	//nが1または2ならば
                            break;	//ループ脱出
                    }
                    printf("\a1か2の整数を入力してください！\n>>");		//\aはビープ音を鳴らすエスケープシーケンス
            }
     
            switch(n){
                    case 1:		//nが1ならば
                            input();	//input関数を実行
                            break;
                    case 2:		//nが2ならば
                            search();		//search関数を実行
                            break;
            }
            return 0;
    }
     
    int input(void)
    {
            FILE *fp;	//ファイルオープンに用いる変数
            char name[64];	//著名を格納する変数
            char author[64];	//著者を格納する変数
            char category[64];	//本のカテゴリを格納する変数
            int i = 1;
     
            if((fp = fopen("database.txt", "a")) == NULL){		//database.txtが追記モード(a)で開けなかったら
                    printf("\aファイルをオープンできません！\n");
                    return 1;	//1を返して緊急脱出
            }
     
            while(1){
                    printf("%d冊目に入れる本の名前、その本の著者、本のカテゴリーを入力してください。(CTRL + Zで終了)\n", i);
                    if((scanf("%s %s %s", name, author, category)) == EOF){		//Crl + Zが打たれるまでループ
                            break;
                    }
                    fprintf(fp, "%s %s %s\n", name, author, category);		//fpの変数で開いているファイルに、著名、著者、カテゴリを書き込み改行する
                    printf("本棚に追加しました！\n");
                    i++;	//i = i + 1と同じ
            }
            printf("終了します。\n");
            fclose(fp);		//ファイルを閉じる
     
            return 0;
    }
     
    int search(void)
    {
            FILE *fp;
            char name[64];
            char author[64];
            char category[64];
            char dname[64];		//データベースから拾ってきた著名を格納する
            char dauthor[64];	//データベースから拾ってきた著者を格納する
            char dcategory[64];	//データベースから拾ってきたカテゴリを格納する
            int flg;
     
            if((fp = fopen("database.txt", "r")) == NULL){	//database.txtが読み取りモード(r)で開けなかったら
                    printf("\aファイルをオープンできません！\n");
                    return 1;
            }
            do{
                    printf("本の名前、その本の著者、本のカテゴリーを入力してください。（わからない項目があれば0を入力）");
                    scanf("%s %s %s", name, author, category);		//本の名前、著者、カテゴリを入力
                    if(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0){		//著名、著者、カテゴリすべて0が打たれていたら
                            printf("\a1つ以上わかる項目を入力してください！\n");
                    }
            }while(strcmp(name, "0") == 0 && strcmp(author, "0") == 0 && strcmp(category, "0") == 0);
     
            while((fscanf(fp, "%s %s %s", dname, dauthor, dcategory)) != EOF){		//fpの変数で開いているファイルから、著名、著者、カテゴリの情報を取得し各変数に代入する これをEOF(最終行)まで続ける
                    if(strcmp(name, dname) == 0 || strcmp(author, dauthor) == 0 || strcmp(category, dcategory) == 0){	//nameとdnameが一致しているかつ、authorとdauthorが一致しているかつ、categoryとdcategoryが一致しているならば
                            printf("\n");
                            printf("該当する本が見つかりました！\n");
                            printf("%-20s%-20s%-20s\n", "本の名前", "著者", "カテゴリー");	//20バイト分の領域を用いて出力（左に揃う）
                            printf("%-20s%-20s%-20s\n", dname, dauthor, dcategory);		//20バイト分の領域を用いて出力（左に揃う）
                            flg = 1;		//一回でも該当する本が見つかった場合はflgに1を代入する
                    }
            }
            if(flg != 1){		//flgが1以外（該当する本が見つからなかった）ならば
                    printf("\a見つかりませんでした。\n");
            }
            fclose(fp);
            return 0;
    }
