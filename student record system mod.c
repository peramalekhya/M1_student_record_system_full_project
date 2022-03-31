void mod_student(){
    clearWindow();
    print_heading("Modify Record");
    SetColor(45);
    char s_id[15];
    int isFound = 0, print = 37;
    gotoxy(37,10);printf("Enter ID to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.ID) == 0){
            fflush(stdin);
            gotoxy(print,12);printf("ID: ");gets(stu.ID);
            gotoxy(print,13);printf("Name: ");gets(stu.name);
            gotoxy(print,14);printf("Address: ");gets(stu.add);
            gotoxy(print,15);printf("Parent's name: ");gets(stu.parname);
            gotoxy(print,16);printf("Class: ");scanf("%d",&stu.Class);
            gotoxy(print,17);printf("Phone Number: ");scanf("%ld",&stu.phone_no);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        gotoxy(print, 12);printf("No Record Found");
    }
    fclose(fp);
    SetColor(28);
    return;
}