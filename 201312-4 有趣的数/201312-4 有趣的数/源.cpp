
#include <stdio.h>

long long a, b, c, d, e, f;
long long ta, tb, tc, td, te, tf;

int main() {
	int i = 0, num;
	a = b = c = d = e = f = g = h = 0;

	a++;//��һλΪ2
	scanf("%d", &num);
	for (i = 1; i < num; i++) {//�ӵڶ�λ��ʼ��⣬ѭ��num-1��
							 //ta=a;
		tb = b + b + a;
		tc = c + a;
		td = d + d + b;
		te = e + e + c + b;
		tf = f + f + d + e;


		//a=ta%1000000007LL;
		b = tb % 1000000007LL;
		c = tc % 1000000007LL;
		d = td % 1000000007LL;
		e = te % 1000000007LL;
		f = tf % 1000000007LL;
	}
	printf("%d", f);
}