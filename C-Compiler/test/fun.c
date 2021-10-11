void fun1();
float* fun2(int ,int);
int fun3(int a, float b);

float* fun2(int a, int b){
	int c;
	a=10-2;
	b=9;
	c = (float)a;
	return &c;
}
