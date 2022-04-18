#include <stdio.h>
#include <string.h>
#include "manager.h"
void searchName(Product *p, int count){
        int scnt = 0;
        char search[20];
        printf("검색할 제품명은? ");
        scanf("%s", search);
        printf("\t\t\t제품명 \t설명\t중량\t판매가격\t배송방법\n");
        printf("************************************************************************************\n");
        for(int i=0; i<count; i++){
                if(p[i].price == -1)continue;
                if(strstr(p[i].name,search)){
                        printf("%2d ", i+1);
                        readProduct(p[i]);
                        scnt++;
                }
        }
        if(scnt == 0) printf("=> 검색된 데이터 없음!");
        printf("\n");
}

int loadData(Product *p){
        int i = 0;
        FILE *fp;
        fp = fopen("product.txt","rt");
        if(fp==NULL){
                printf("=>파일 없음\n");
                return 0;
        }
        for(;i < 100; i++){
                fscanf(fp,"%s",p[i].name);
        fscanf(fp,"%s",p[i].explan);
                if(feof(fp))break;
                fscanf(fp, "%s",p[i].weight);
                fscanf(fp, "%d",&p[i].price);
                fscanf(fp, "%d",&p[i].deliv);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        return i;
}


void saveData(Product *p, int count){
        FILE *fp;
        fp = fopen("product.txt","wt");
        for(int i=0; i<count; i++){
                if(p[i].price == -1)continue;
                fprintf(fp,"%s %s %s %d %d\n",p[i].name,p[i].explan,p[i].weight,p[i].price,p[i].deliv);
        }
        fclose(fp);
        printf("=> 저장됨!\n");
}


void listProduct(Product *p, int count){
	printf("\t\t\t제품명 \t설명\t중량\t판매가격\t배송방법\n");
	printf("************************************************************************************\n");
	for(int i=0;i<count ; i++){
		if(p[i].price == -1){continue;}
		else{
			printf("%-2d ", i+1);
			readProduct(p[i]);
		}
		printf("\n");
	}
}
int selectDataNo(Product *p, int count){
	int no;
	listProduct(p, count);
	printf("원하는 번호는(취소:0)? ");
	scanf("%d",&no);
	return no;
}




char delivway[2][50] = {"새벽배송","택배배송"};

int addProduct(Product *p){
	printf("제품명은?");
	scanf("%[^\n]s",p->name);
    getchar();
	printf("설명은?");
	scanf("%[^\n]s",p->explan);
    getchar();
	printf("무게는?");
	scanf("%s",p->weight);
	printf("가격은?");
	scanf("%d",&p->price);
    printf("배달방법은?(새벽배송:1, 택배배송:2)");
	scanf("%d",&p->deliv);
	printf("==> 추가됨!\n");
	return 1;
}

int selectMenu(){
	int menu;
	printf("\n**********\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 저장\n");
	printf("6. 이름검색\n");
	printf("0. 종료\n\n");
	printf("=> 원하는 메뉴는? ");
	scanf("%d", &menu);
    getchar();
	return menu;
}

void readProduct(Product p){
	if(p.price==-1){return ;}
	printf("%8s, %30s, %3s, %5d, %s",p.name ,p.explan ,p.weight ,p.price, delivway[p.deliv-1]);
}

int updateProduct(Product *p){
	printf("제품명은?");
	scanf("%[^\n]s",p->name);
    getchar();
	printf("설명은?");
	scanf("%[^\n]s",p->explan);
    getchar();
	printf("무게는?");
    scanf("%s",p->weight);
	printf("가격은?");
	scanf("%d",&p->price);
    printf("배달방법은?(새벽배송:0, 택배배송:1");
	scanf("%d",&p->deliv);
	printf("==> 수정됨!\n");
	return 1;
}

int deleteProduct(Product *p){
    p->price = -1;
    printf("=>삭제됨\n");
    return 1;
}

