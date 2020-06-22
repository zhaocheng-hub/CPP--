#include<iostream>
using namespace std;
constexpr auto maxSize = 10000;;  //ͬ #define maxSzie 10000;

//˳���    ����ʹ��һά�������䵱˳��洢�Ĳ��� �������Ͳ���һ��ʹ�ã�
typedef struct SqList {
	int data[maxSize]; //���������Ԫ�ظ�����һ���㹻��ģ���Ŀ���ܸ����� ���Ϳ��Ի����������Ϳ���ĿҪ��
	int length; //���˳���ĳ���
};

//����֪һ�����򣨵�������˳���L �� 
//���һ���㷨������һ��Ԫ��x�����Σ��󱣳ָ�˳�����Ȼ����
int findElem(SqList L,int x) {  // ��������˳����е�һ����x���Ԫ�ص�λ�á�
	int i;
	for (int i = 0; i < L.length; i++) {
		if (x < L.data[i]) {
			return i;
		}
	}
	return i;
}
void insertElem(SqList &L, int x) {  //��ɲ������㷨�� ��ΪLҪ�����ı����Լ�&
	int p, i;
	p = findElem(L, x);  //���Ҳ���λ��p
	for (int i = L.length - 1; i >= p; --i) {
		L.data[i + 1] = L.data[i]; //�������������Ԫ������һ��λ��
	}
	L.data[p] = x; //��x���ڲ���λ��p��
	++(L.length); //˳�����+1
}

//Ӧ���߱���дһ���������㷢��ʹ֮��ɻ��������������� 

//�ﰴֵ���� ������˳�����Ҳ��������
//��˳����в��ҵ�һ��ֵ����x��Ԫ�أ����������±�
//�������������ƣ�ע�����֣��������������ĸ�д��
int findElem(SqList L, int x) {  
	int i;
	for (int i = 0; i < L.length; i++) {
		if (x < L.data[i]) {
			return i;    //���ҵ����ض�Ӧ�±�
		}
	}
	return -1;   //û�ҵ�������-1����Ϊʧ�ܱ��
}

//��������Ԫ�ص��㷨
//��˳���L�ĵ�p��λ�ã���һ���Ǻ���λ�ã������µ�Ԫ��x,��p��λ�ò���ȷ���򷢻�0���������ʧ�ܣ�
//��p��λ����ȷ������������Ĳ��룬
//�������������ƣ�ע�����֣��������������ĸ�д��
int insertElem1(SqList &L, int x,int p) {  // ��ΪLҪ�����ı����Լ�&
	int i;
	if (p<0 || p>L.length || L.length == maxSize) //λ�ô�����߱��ﵽ���
		return 0;
	for (int i = L.length - 1; i >= p; --i) {
		L.data[i + 1] = L.data[i]; //�������������Ԫ������һ��λ��
	}
	L.data[p] = x; //��x���ڲ���λ��p��
	++(L.length); //˳�����+1
	return 1;
}

//�����µ��㷨�ͺ����㷨���������˽�Ϊ��

//ɾ��˳���L���±�Ϊp����һ���Ϸ�����Ԫ�أ����ɹ�����1�����򷵻�0������ɾ��Ԫ�ص�ֵ��ֵ��e
int deleteElem(SqList &L, int p, int &e) {//��Ҫ�ı����&
	int i;
	if (p<0 || p>L.length - 1) {
		return 0;   //λ�ò��Ϸ���
	}
	e = L.data[p];  //����ɾ��Ԫ�ظ�ֵ��e
	for (i = p; i < L.length - 1; ++i) {   //��p��ʼ�����ÿ��Ԫ��ǰ��һ��λ�ã�
		L.data[i] = L.data[i + 1];
	}
	--(L.length);
	return 1;
}

//��ʼ��˳���  
void initList(SqList &L) {//��Ҫ�ı����&
	L.length = 0;  //ֻ��Ҫ��L.length ��Ϊ0����
}

//��ȡָ��λ��Ԫ�ص��㷢
int getElem(SqList L, int p, int &e) {
	if(p<0 || p>L.length - 1) {
		return 0;   //λ�ò��Ϸ���
	}
	e = L.data[p];  //����ɾ��Ԫ�ظ�ֵ��e
	return 1;
}

//���  ��˳���������A[]��ʾ������Ԫ�ش洢�������±�0~m+n-1�ķ�Χ�ڣ�
//ǰm��Ԫ�ص������򣬺�n��Ԫ��Ҳ�����������һ���㷢��ʹ����˳����������
void insertElem(int A[], int m, int n) {   //�������㷨���ã�����û�ж���ĸ����ռ䣬�����Լ�дһ���и����ռ�ġ�
	int i, j, temp;
	for (int i = m; i < m + n; ++i) { //��A[m,m+n-1]���뵽A[0,m-1]�� //�������
		temp = A[i];
		for (j = i - 1; j >= 0 && temp < A[j]; --j) { //Ѱ��һ�����ʵ�λ��
			A[j + 1] = A[j];  //Ԫ�غ���
		}
		A[j + 1] = temp; 
	}
}

//˳���Ԫ�������
void reverse(SqList &L) {
	int i, j, temp;
	for (int i = 0, j = L.length - 1; i < j; ++i, --j) {
		temp = L.data[i];
		L.data[i] = L.data[j];
		L.data[j] = temp;
	}
}

//˳�������һ���㷨���±�i~j������Ԫ��ɾ�����ٶ�i,j���ǺϷ���
void Delete(SqList &L, int i, int j) {
	int k, delta;
	delta = j - i + 1;
	for (k = j + 1; k < L.length; ++k) {
		L.data[k - delta] = L.data[k]; //�õ�k��Ԫ��ȥ������ǰ��ĵ�delta��Ԫ��
	}
	L.length -= delta;//���ı�
}

//�������һ���㷢����˳���L����С�ڱ�ͷ��Ԫ�ص���������ǰ�벿�֣����ڱ�ͷԪ�ص��������ں�벿��
//����㷢�Ϳ������������ ,��������ĵ�һ��
void move(SqList &L) {
	int temp;
	int i = 0, j = L.length - 1; //�������
	temp = L.data[i];
	while (i<j){
		while (i<j&&L.data[j]>temp) { //��������ɨ�裬�ҵ���һ����tempС��Ԫ��ֹͣ������Ҫ��i���Ҳ�
			--j;
		}
		if (i < j) {
			L.data[i] = L.data[j];
			i++;
		}
		while (i < j&&L.data[i] < temp) { //��������ɨ�裬�ҵ���һ����temp���Ԫ�أ�
			i++;
		}
		if (i < j) {
			L.data[j] = L.data[i];
			--j;
		}
	}
	L.data[i] = temp; 
}
//��N����λ�����������int������ A[0,N-1]�У�NΪ�Ѷ���ó�����N<=9������A[]�ó���ΪN��
//���һ��int�ͱ���i��Ҫ��ֻ������������i����N+1�����ͱ���дһ���㷨���ҳ���N�������е���С�ߣ�
//�Ҳ����ƻ�����A[]�е����ݡ�   ���Ŀ��ܼ���
void findMin(int A[], int &i) {
	i = A[0];
	int N; //N��֪
	while (i / 10 <= N - 1) { // ȡiʮλ������Ϊѭ����������N-1�Ƚ�
		if (i % 10 > A[i / 10]) {//ȡi�ø�λ�ϵ�������A[i/10]�еĸ���ֵ���Ƚ�
			i = i - i % 10;     //���i�ĸ�λ���ִ���A[i/10]�����֣���i�ĸ�λ�ϵ����ֻ���A[i/10]
			i = i + A[i / 10];
			}
		i = i + 10;  //i��ʮλ�� ���ּ�1������A[]�е���һ�����ֽ��м��
	}
	i = i % 10;  //i�ĸ�λ�ϱ�������С����ֵ
}
//���Ѱ��˳�������ֵ����Сֵ��Ҫ��ƽ���Ƚϴ���������3n/2
void FindMaxMin(int A[], int n, int &max, int &min) {
	max = min = A[1];
	for (int i = 2; i <= n; ++i) {
		if (A[i] > max) {  //�ҳ���������
			max = A[i];   
		}
		else if (A[i] < min) { //�ҳ���С������
			min = A[i];  
		}
	}
}
//����轫n�����������һά����R�У����һ����ʱ��Ϳռ価���ܸ�Ч���㷢
//��R�б��������ѭ������P��0<P<N) ��λ�ã�����R��������(X0,...Xn-1)�任Ϊ(Xp..Xn-1,X0...Xp-1)
void Reverse(int R[], int l, int r) { //��ת����
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

//�����������A=[A0,An-1]Ѱ����Ԫ��(���������Ǹ�����������ռ��������һ�뼰����)
int majority(int A[], int n) {
	bool *C = new bool[n];  //ɢ��һ��  ��ΪAi ���Ϊn
	for (int i = 0; i < n; i++) { //��ʼ��C 
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