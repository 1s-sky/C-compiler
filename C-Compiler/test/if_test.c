int a=5;
int b=6;
int c=4;

int main() {
	if(a>b) a=b;
	else if(a>=c) a=c;
	else if(a>c||a<=b) b=a;
	else if(a<b&&a<=c) b=c;
	else if(a!=b) b=c;
	else if(a==b) b=c;
	else a=c;
}

