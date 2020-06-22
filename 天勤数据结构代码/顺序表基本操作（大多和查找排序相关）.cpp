#include<iostream>
using namespace std;
constexpr auto maxSize = 10000;;  //同 #define maxSzie 10000;

//顺序表    往往使用一维数组来充当顺序存储的操作 （往往和查找一起使用）
typedef struct SqList {
	int data[maxSize]; //这里的数字元素个数开一个足够大的（题目可能给）。 类型可以换成其他类型看题目要求
	int length; //存放顺序表的长度
};

//★已知一个有序（递增）的顺序表L ， 
//设计一个算法，插入一个元素x（整形）后保持该顺序表依然有序
int findElem(SqList L,int x) {  // 查找有序顺序表中第一个比x大的元素的位置。
	int i;
	for (int i = 0; i < L.length; i++) {
		if (x < L.data[i]) {
			return i;
		}
	}
	return i;
}
void insertElem(SqList &L, int x) {  //完成操作的算法， 因为L要发生改变所以加&
	int p, i;
	p = findElem(L, x);  //查找插入位置p
	for (int i = L.length - 1; i >= p; --i) {
		L.data[i + 1] = L.data[i]; //从右往左，逐个将元素右移一个位置
	}
	L.data[p] = x; //将x放在插入位置p上
	++(L.length); //顺序表长度+1
}

//应当具备改写一下面两个算发，使之完成基本操作的能力， 

//★按值查找 （后面顺序查找也是这样）
//在顺序表中查找第一个值等于x的元素，并返回其下标
//和上面代码很类似，注意区分（上面代码是这个的改写）
int findElem(SqList L, int x) {  
	int i;
	for (int i = 0; i < L.length; i++) {
		if (x < L.data[i]) {
			return i;    //若找到返回对应下标
		}
	}
	return -1;   //没找到，返回-1，作为失败标记
}

//插入数据元素的算法
//在顺序表L的第p个位置（不一定是合理位置）插入新的元素x,若p的位置不正确，则发挥0，代表插入失败；
//若p的位置正确，则进行正常的插入，
//和上面代码很类似，注意区分（上面代码是这个的改写）
int insertElem1(SqList &L, int x,int p) {  // 因为L要发生改变所以加&
	int i;
	if (p<0 || p>L.length || L.length == maxSize) //位置错误或者表长达到最大
		return 0;
	for (int i = L.length - 1; i >= p; --i) {
		L.data[i + 1] = L.data[i]; //从右往左，逐个将元素右移一个位置
	}
	L.data[p] = x; //将x放在插入位置p上
	++(L.length); //顺序表长度+1
	return 1;
}

//再往下的算法和后续算法关联不大，了解为主

//删除顺序表L中下标为p（不一定合法）的元素，若成功返回1，否则返回0，并将删除元素的值赋值给e
int deleteElem(SqList &L, int p, int &e) {//需要改变的用&
	int i;
	if (p<0 || p>L.length - 1) {
		return 0;   //位置不合法，
	}
	e = L.data[p];  //将待删除元素赋值给e
	for (i = p; i < L.length - 1; ++i) {   //从p开始后面的每个元素前移一个位置；
		L.data[i] = L.data[i + 1];
	}
	--(L.length);
	return 1;
}

//初始化顺序表  
void initList(SqList &L) {//需要改变的用&
	L.length = 0;  //只需要将L.length 设为0即可
}

//获取指定位置元素的算发
int getElem(SqList L, int p, int &e) {
	if(p<0 || p>L.length - 1) {
		return 0;   //位置不合法，
	}
	e = L.data[p];  //将待删除元素赋值给e
	return 1;
}

//★★  设顺序表用数组A[]表示，表中元素存储在数组下标0~m+n-1的范围内，
//前m个元素递增有序，后n个元素也递增有序，设计一个算发，使整个顺序表递增有序
void insertElem(int A[], int m, int n) {   //★★这个算法不好，但是没有额外的辅助空间，可以自己写一个有辅助空间的。
	int i, j, temp;
	for (int i = m; i < m + n; ++i) { //将A[m,m+n-1]插入到A[0,m-1]中 //逐个插入
		temp = A[i];
		for (j = i - 1; j >= 0 && temp < A[j]; --j) { //寻找一个合适的位置
			A[j + 1] = A[j];  //元素后移
		}
		A[j + 1] = temp; 
	}
}

//顺序表元素逆序★
void reverse(SqList &L) {
	int i, j, temp;
	for (int i = 0, j = L.length - 1; i < j; ++i, --j) {
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}

//顺序表，设置一个算法将下标i~j的所有元素删除，假定i,j都是合法的
void Delete(SqList &L, int i, int j) {
	int k, delta;
	delta = j - i + 1;
	for (k = j + 1; k < L.length; ++k) {
		L.data[k - delta] = L.data[k]; //用第k个元素去覆盖它前面的第delta个元素
	}
	L.length -= delta;//更改表长
}

//★★★设计一个算发，将顺序表L所有小于表头的元素的整数放在前半部分，大于表头元素的整数放在后半部分
//这个算发和快速排序很相似 ,快速排序的第一趟
void move(SqList &L) {
	int temp;
	int i = 0, j = L.length - 1; //表的两侧
	temp = L.data[i];
	while (i<j){
		while (i<j&&L.data[j]>temp) { //从右往左扫描，找到第一个比temp小的元素停止，并且要在i的右侧
			--j;
		}
		if (i < j) {
			L.data[i] = L.data[j];
			i++;
		}
		while (i < j&&L.data[i] < temp) { //从左往右扫描，找到第一个比temp大的元素，
			i++;
		}
		if (i < j) {
			L.data[j] = L.data[i];
			--j;
		}
	}
	L.data[i] = temp; 
}
//在N个个位正整数存放在int数组中 A[0,N-1]中，N为已定义得常量且N<=9，数组A[]得长度为N，
//另给一个int型变量i，要求只用上述变量与i，这N+1个整型变量写一个算法，找出这N个整数中得最小者，
//且不能破坏数组A[]中得数据。   考的可能极低
void findMin(int A[], int &i) {
	i = A[0];
	int N; //N已知
	while (i / 10 <= N - 1) { // 取i十位数字作为循环变量，与N-1比较
		if (i % 10 > A[i / 10]) {//取i得各位上的数字与A[i/10]中的各数值作比较
			i = i - i % 10;     //如果i的各位数字大于A[i/10]的数字，则将i的个位上的数字换成A[i/10]
			i = i + A[i / 10];
			}
		i = i + 10;  //i的十位上 数字加1，即对A[]中的下一个数字进行检测
	}
	i = i % 10;  //i的个位上保留了最小数的值
}
//★★寻找顺序表的最大值和最小值，要求平均比较次数不多于3n/2
void FindMaxMin(int A[], int n, int &max, int &min) {
	max = min = A[1];
	for (int i = 2; i <= n; ++i) {
		if (A[i] > max) {  //找出最大的整数
			max = A[i];   
		}
		else if (A[i] < min) { //找出最小的整数
			min = A[i];  
		}
	}
}
//★★设将n个整数存放在一维数组R中，设计一个在时间和空间尽可能高效的算发
//将R中保存的序列循环左移P（0<P<N) 个位置，即将R中数据由(X0,...Xn-1)变换为(Xp..Xn-1,X0...Xp-1)
void Reverse(int R[], int l, int r) { //反转操作
	int i, j, temp;
	for (i = 1, j = r; i < j; ++i, --j) {
		temp = R[i];
		R[i] = R[j];
		R[j] = temp;
	}
}
int RCR(int R[], int n, int p) {
	if (p <= 0 || p > n) {
		return 0;
	}
	else {
		Reverse(R, 0, p - 1);
		Reverse(R, p, n - 1);
		Reverse(R, 0, n - 1);
	}
}

//★★整数序列A=[A0,An-1]寻找主元素(出现最多的那个数，且数量占总数量的一半及以上)
int majority(int A[], int n) {
	bool *C = new bool[n];  //散列一种  因为Ai 最大为n
	for (int i = 0; i < n; i++) { //初始化C 
		C[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		C[A[i]]++;
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (C[i] > max) {
			max = C[i];
		}
	}
	return max;
}