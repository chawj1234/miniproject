typedef struct {
    char name[100]; //제품명
    char explan[100]; //제품 설명
    char weight[100]; //중량
    int price; //판매가격
    int deliv; //배송방법
} Product;
void saveData(Product *p, int count); //파일에 데이터를 저장한다
int loadData(Product *p); //파일에서 데이터를 불러온다
void searchName(Product *p, int count); //제품을 검색한다
void listProduct(Product *p, int count); //등록된 전체 제품 리스트를 출력한다
int selectDataNo(Product *p, int count); //원하는 번호를 선택한다
int addProduct(Product *p); //제품을 등록한다
void readProduct(Product p); //제품을 읽어온다
int updateProduct(Product *p); //제품을 수정한다
int deleteProduct(Product *p); //제품을 삭제한다
int selectMenu(); //메뉴를 선택한다

