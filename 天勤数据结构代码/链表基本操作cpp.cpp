#include<iostream>
using namespace std;
//Ҫ���������Ļ����������в�����д�����Ұ���˫�����ѭ������ģ�û�е��������Ҫ��

//�ṹ����
typedef struct LNode {
	int data;  // �����򣨿������������ͣ�
	struct LNode *next;//ָ���� ���˴�����ָ������ڵ㣩
};

//A��B��������������ͷ�ڵ㣩������Ԫ�ص������� ����
//����һ���㷨��A�Ͳ��ϲ���һ����Ԫ��ֵ�ǵݼ����������C��C��A��B�ڵ����
void merge(LNode *A, LNode *B, LNode *&C) {     //�Լ������²�����C дһ����A��B�ϲ���A��
	LNode *p = A->next; //p��׷�� A����Сֵ�ڵ�
	LNode *q = B->next; //q��׷��B����Сֵ�ڵ�
	LNode *r;  //rʼ��ָ��C���ն˽ڵ㣨���һ���ڵ㣩
	C = A;     //C��A�ĵ�ַ�����Cδ�����ַ��
	C->next = NULL; //��C��ʼ��Ϊһ�������� �� ���п��ޣ�����д�ϣ���ֹ������ʦ��
	//free(B);  //���п���  ��ʱ��AҲ�ͷ���Ҳ�޷� 
	r = C;   //rָ��C��ͷ�ڵ�
	while (p != NULL && q != NULL) {  //p��q����Ϊ�յ�ʱ�򣬽���
		//�����õ�β�巨
		if (p->data <= q->data) {  //���pָ���ֵС����ô��p���뵽r����
			r->next = p; 
			p = p->next;   //p���ƣ�
			r = r->next;  //r���ƣ�rʼ��ָ�����һ���ڵ�
		}
		else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	//r->next = NULL;  // ���п���
	if (p != NULL) {  //��p����ʣ��ڵ㣬��������� ע��˴�������p����p�������нڵ�Ҳ���Ų�����
		r->next = p;
	}
	if (q != NULL) {  //ͬ��
		r->next = q;
	}
}

//��β�巨��������C��� (ע���˽���뼴�ɣ������Լ�д�����Բ���һ����Ҫ�������������
void createlistR(LNode *&C, int a[], int n) {  //a������Ԫ�ص����飬nԪ�ظ��� �������ͷ�ڵ��б仯��ʱ��ż�&(Ҳ����ͷ�ڵ�ĵ�ַ�б䶯������/�ͷţ��żӣ�
	LNode *s, *r; //s����ָ��������Ľڵ�
	int i;
	LNode* C = new LNode; //����C��ͷ�ڵ�ռ䣻
	C->next = NULL; //���Ҳ���Ǳ���ģ�����д�ϰɣ���ֹ������ʦ
	r = C;
	for (int i = 0; i < n; i++) {  //��ʼ�������� ,ע������ô�����
		LNode *s = new LNode; //����ǳ���Ҫ
		s->data = a[i]; 
		//������β��ĺ���
		r->next = s; //s���뵽r�ĺ���
		r = r->next; //rʼ��ָ���ն˽ڵ㣨��ǰs�ڵ��λ�ã����λ��ÿ��ѭ�����䣩
	}
	r->next = NULL;// �����永����ͬ����������У������Ǹ�����Ϊ֮ǰ�������β��ָ��NULL�ġ�
}

//ͷ�巨��������
void createlistF(LNode *&C, int a[], int n) {  //ע�⣬�������ͷ�ڵ��б仯��ʱ��ż�&
	LNode *s;
	int i;
	LNode* C = new LNode; //����C��ͷ�ڵ�ռ�;
	C->next = NULL;  //���������Ĳ�ͬ������Ǳ���ģ�
	for (int i = 0; i < n; i++) {  //��ʼ�������� ,ע������ô�����
		LNode *s = new LNode; //����ǳ���Ҫ
		s->data = a[i];
		//������ͷ��ĺ���
		s->next = C->next; //s��ָ�½ڵ��ָ����nextָ��C�еĿ�ʼ�ڵ㣨ͷ�ڵ��һ���ڵ�)
		C->next = s;  //  ͷ�ڵ��ָ����nextָ��s�ڵ㣬ʹ��s��Ϊ�µĿ�ʼ��ͷ���ڵ�
	}
}
////A��B��������������ͷ�ڵ㣩������Ԫ�ص������� ����
//����һ���㷨��A�Ͳ��ϲ���һ����Ԫ��ֵ�ݼ����������C��C��A��B�ڵ����  ��ע�����������֣�
void merge(LNode *A, LNode *B, LNode *&C) {     //�Լ������²�����C дһ����A��B�ϲ���A��
	LNode *p = A->next; //p��׷�� A����Сֵ�ڵ�
	LNode *q = B->next; //q��׷��B����Сֵ�ڵ�
	LNode *s;  // s�����䵱��ʱ�ڵ�����
	C = A;     //C��A�ĵ�ַ����� Cδ�����ַ��
	C->next = NULL; //��C��ʼ��Ϊһ�������� ����������ͬ���˴�����д
	//free(B);  //���п���  ��ʱ��AҲ�ͷ���Ҳ�޷� 
	while (p != NULL && q != NULL) {  //p��q����Ϊ�յ�ʱ�򣬽���
		//�����õ�ͷ�巨
		if (p->data <= q->data) {  //���pָ���ֵС����ô��p���뵽r����
			s = p;
			p = p->next;   //p���ƣ� �������������������ϵ�p�ͺ���ڵ������
			s->next = C->next;
			C->next = s;  //C����ĵ�һ���ڵ㣨ͷ�ڵ�ĺ�һ���ڵ㣩Ϊs��
		}
		else {
			s = q;
			q = q->next;   
			s->next = C->next;
			C->next = s;  
		}
	}
	//ע������Ĳ�����ͷ�����ȫ��ͬ��
	while (p!=NULL) {
		s = p;
		p = p->next;
		s->next = C->next;
		C->next = s;
	}
	while (q != NULL) {
		s = q;
		q = q->next;
		s->next = C->next;
		C->next = s;
	}
}

//����������C����ͷ�ڵ㣩���Ƿ����һ��ֵΪx�Ľڵ㣬�����ڣ���ɾ���ýڵ㲢����1�����򷵻�0
int findeAndDelete(LNode *C, int x) {
	LNode *p, *q;
	p = C;
	/*���Ҳ��ֿ�ʼ*/
	while (p->next != NULL) {
		if (p->next->data == x) {  //ע����� ��ʱp�� ֵΪx�ڵ����һ���ڵ�
			break;
		}
		p = p->next;
	}
	/*���Ҳ��ֽ���*/
	if (p->next == NULL) {
		return 0;  //û�ҵ�
	}
	else {
		/*ɾ�����ֿ�ʼ*/
		q = p->next;
		p->next = p->next->next;
		delete q;
		/*ɾ�����ֽ���*/
		return 1;
	}
}

//������֪��������ĵ�����A��B��A��B��Ԫ�ظ����ֱ�Ϊm��n����A��B������ͷ�ڵ㣩
//�ֱ�洢��һ�����ϣ�����㷨�������������A��B�ĲA-B������A��A�г��ֶ�����B�г��ֵ�Ԫ�������ɵļ��ϣ�
//�������������A�У�������Ԫ�صĵ��������ԣ�
void difference(LNode *A, LNode *B) {
	LNode *p = A->next, *q = B->next;
	LNode *pre = A;
	LNode *r;
	while (p != NULL && q != NULL) {
		if (p->data < q->data) {
			pre = p;  //preʼ��ָ��p����һ���ڵ�
			p = p->next;  //p����
		}
		else if (p->data>q->data) {
			q = q->next;
		}
		else {
			pre->next = p->next;
			r = p;
			p = p->next;
			delete r;  
		}
	}
}
//��������ǿյ���������һ���㷢��ɾ��ֵ����ͬ�Ľڵ�
void delsll(LNode *L) {
	LNode *p = L->next;
	LNode *q;
	while (p->next != NULL) {
		if (p->data == p->next->data) {
			q = p->next;
			p->next = q->next;
			delete q;
		 }
		else {
			p = p->next;
		}
	}
}
//���ɾ��������(��ͷ�ڵ�)��һ����Сֵ�Ľڵ�
void delminnode(LNode*L) {
	LNode *pre = L, *p = pre->next, *minp = p, *minpre = pre; 
	while(p!=NULL){ //Ѱ����Сֵ�ڵ㣬minp�Լ�ǰ���ڵ�minpre��
		if (p->data < minp->data) {
			minp = p;
			minpre = pre;
		}
		pre = p;
		p = p->next;
	}
	minpre->next = minp->next; //ɾ��*minp�ڵ� 
	delete minp;
}
//������������
void reversel(LNode*L) {
	LNode *p = L->next, *q;
	L->next = NULL;    //L�䵱������ı�ͷ
	while (p != NULL) { //p�ڵ�ʼ��ָ�������Ŀ�ʼ�ڵ�  
		/* ͷ�巨 */
		q = p->next; //q�ڵ���Ϊ�����������¼p�ĺ�̽ڵ��λ��
		p->next = L->next; //��p��ָ�Ľڵ���뵽�µ�������
		L->next = p;
		p = q;
	}
}
//���ｫһ��ͷ�ڵ�ΪA�ĵ�����������Ϊ���ͣ��ֽ������������A��B��
//ʹ��A����ֻ��ԭ������data��Ϊ�����ýڵ㣬��B����ֻ����ԭ������data��Ϊż���Ľڵ㡣����ԭ�������˳��
void split2(LNode *A, LNode *&B) {
	LNode *p, *q, *r;
	LNode *B = new LNode;
	B->next = NULL; //Ҳ���Բ�д�����д��ÿ����һ���½ڵ��ʱ�򣬽���ָ��������ΪNULL��
					//���Ա���ܶ��������ն˽ڵ����������NULL�������Ĵ���Ҳ��ֹ������ʦ
	r = B; 
	p = A; 
	while (p->next != NULL) {  //pʼ��ָ��ǰ�ڵ��ǰ���ڵ�
		if (p->next->data % 2 == 0) {
			q = p->next; //qָ��Ҫ������ȡ�µýڵ�
			p->next = q->next; 
			q->next = NULL;
			r->next = q;  
			r = q;   //rʼ��ָ��B�����һ���ڵ�
		}
		else {
			p = p->next;
		}
	}
}

//��������ӡ�������е�����   //ע��ҲҪ������ķ�ת   
void reprint(LNode *L) {   
	if (L != NULL) {  //ע����������˳��
		reprint(L->next); //�ݹ������ӡ��ʼ�ڵ��ߵ�����
		cout << L->data << "";  //��ӡ��ʼ�ڵ��е�����;
	}
}
//������֪��һ����ͷ�ڵ�ĵ�����ֻ������ͷ�ڵ�head���ڲ��ı������ǰ���£�
//���һ�������ܸ�Ч���㷢�����������е�����k��λ���ϵĽڵ㡣
//�����ҳɹ����㷢����ý���dataֵ��������1�����򷵻�0��
int findElem(LNode* head, int k) {  //�����Լ�����һ�£���ͳ�Ƴ�����Ľڵ������Ȼ��˳����Ҿͼ򵥵ö�
	LNode* p1 = head->next; 
	LNode* p = head;
	int i = 1;
	while (p1 != NULL) {
		p1 = p1->next;
		i++;
		if (i > k) {
			p = p->next; //���i>k����pҲ�����ƶ�
		}
	}
	if (p == head)
		return 0;  //˵��������k���ڵ㣬
	else {
		cout << p->data;
		return 1;
	}
}

//����������
void print(LNode *L) {
	L = L->next;
	while (L != NULL) {
		cout << L->data<<" ";
		L = L->next;
	}
	cout << endl;
}
/*���ڲ���
int main() {
	LNode *p = new LNode;
	LNode *q = new LNode;
	LNode *r = new LNode;
	LNode *p1 = new LNode;
	LNode *p2 = new LNode;
	LNode *p3 = new LNode;
	LNode *q1 = new LNode;
	LNode *q2 = new LNode;
	LNode *q3 = new LNode;
	LNode *q4 = new LNode;
	p->next = p1; p1->next = p2; p2->next = p3;
	q->next = q1; q1->next = q2; q2->next = q3; q3->next = q4;
	p1->data = 1;
	p2->data = 2;
	p3->data = 4;
	q1->data = 3;
	q1->data = 5;
	q1->data = 6;
	q1->data = 7;
	print(p);
	print(q);
	print(r);
	merge(p, q, r);
	print(r);
}
*/
