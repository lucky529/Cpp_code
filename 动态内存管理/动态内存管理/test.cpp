int globalVar = 1;
static int GlobalVar = 1;
void Test()
{
	static int staticVar = 1;
	int localVar = 1;
	int num[10] = { 1, 2, 3, 4 };
	char char2[] = "abcd";
	char* pChar = "abcd";
	int* ptr1 = (int*)malloc(sizeof(int)* 4);
	int* ptr2 = (int*)calloc(4, sizeof(int));
	int* ptr3 = (int*)realloc(ptr3, sizeof(int)* 4);
	free(ptr1);
	free(ptr3);
}