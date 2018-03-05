#include <iostream>
#include <vector>
using namespace std;

vector <int> Move;
int r = 0;
int C[54];
void initialise();
void SolveCube();
void printmoves();
void SolveTopCorners();
void corner();
void func1();
void func2();
void func3();
void SolveBottomCorners();
void func4();
void func5();
void func6();
void func7();
void func8();
void SolveOtherCorners();
void func9();
void func10();
void SolveTopBottomLayers();
void Adjust();
void TopCenter();
void mid(int i = 1);
void func11();
void func12();
void func13();
void func14();
void BottomCenter();
void func15();
void func16();
void func17();
void func18();
void RemCenter();
void func19();
void func20();
void CompleteTheCube();
bool cond1();
bool cond2();
bool cond3();
bool cond4();
void func21();
void func22();
void func23();
void func24();
void func25();
void U(int n = 1);
void D(int n = 1);
void L(int n = 1);
void R(int n = 1);
void F(int n = 1);
void B(int n = 1);
void turn(int[], int);
void rotate(int n = 1);
bool issolved();

int main(){
	initialise();
	SolveCube();
	printmoves();
}

void initialise(){
	cout<<"Please enter the configuration of the cube.\n\n";
	for(int i = 0; i < 54; i++){
		char c;
		cout<<"Square "<<i + 1<<" = ";
		cin>>c;
		if(c == 'w' || c == 'W')
			C[i] = 0;
		else if(c == 'r' || c == 'R')
			C[i] = 1;
		else if(c == 'b' || c == 'B')
			C[i] = 2;
		else if(c == 'o' || c == 'O')
			C[i] = 3;
		else if(c == 'g' || c == 'G')
			C[i] = 4;
		else if(c == 'y' || c == 'Y')
			C[i] = 5;
		else{
			cout<<"\n\n\nYou can only enter the specified characters.\n";
			exit(1);
		}		
	}
	cout<<endl<<endl<<endl<<endl;
}

bool issolved(){
	for(int i = 0; i < 54; i++)
		if(C[i] != C[i - i % 9])
			return 0;
	return 1;
}

void printmoves(){
	int u = 0, d = 0, l = 0, r = 0, f = 0, b = 0, n = 0;
	for(unsigned int i = 0; i < Move.size(); i++){
		if(Move[i] < 20){
			if(Move[i] < 10)
				u = (u + Move[i] % 10) % 4;
			else
				d = (d + Move[i] % 10) % 4;
			if(l){
				cout<<++n<<". L"<<l<<"\t\t";
				l = 0;
			}
			if(r){
				cout<<++n<<". R"<<r<<"\t\t";
				r = 0;
			}
			if(f){
				cout<<++n<<". F"<<f<<"\t\t";
				f = 0;
			}
			if(b){
				cout<<++n<<". B"<<b<<"\t\t";
				b = 0;
			}
		}
		else if(Move[i] < 40){
			if(Move[i] < 30)
				l = (l + Move[i] % 10) % 4;
			else
				r = (r + Move[i] % 10) % 4;
			if(u){
				cout<<++n<<". U"<<u<<"\t\t";
				u = 0;
			}
			if(d){
				cout<<++n<<". D"<<d<<"\t\t";
				d = 0;
			}
			if(f){
				cout<<++n<<". F"<<f<<"\t\t";
				f = 0;
			}
			if(b){
				cout<<++n<<". B"<<b<<"\t\t";
				b = 0;
			}
		}
		else{
			if(Move[i] < 50)
				f = (f + Move[i] % 10) % 4;
			else
				b = (b + Move[i] % 10) % 4;
			if(l){
				cout<<++n<<". L"<<l<<"\t\t";
				l = 0;
			}
			if(r){
				cout<<++n<<". R"<<r<<"\t\t";
				r = 0;
			}
			if(u){
				cout<<++n<<". U"<<u<<"\t\t";
				u = 0;
			}
			if(d){
				cout<<++n<<". D"<<d<<"\t\t";
				d = 0;
			}
		}
	}
	if(l)
		cout<<++n<<". L"<<l<<"\t\t";
	if(r)
		cout<<++n<<". R"<<r<<"\t\t";
	if(u)
		cout<<++n<<". U"<<u<<"\t\t";
	if(d)
		cout<<++n<<". D"<<d<<"\t\t";
	if(f)
		cout<<++n<<". F"<<f<<"\t\t";
	if(b)
		cout<<++n<<". B"<<b<<"\t\t";
}

void U(int n){
	int a[12] = {C[9], C[10], C[11], C[18], C[19], C[20], C[29], C[28], C[27], C[38], C[37], C[36]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 0);
	if(n < 4)
		Move.push_back(n);
	C[9] = a[0];
	C[10] = a[1];
	C[11] = a[2];
	C[18] = a[3];
	C[19] = a[4];
	C[20] = a[5];
	C[29] = a[6];
	C[28] = a[7];
	C[27] = a[8];
	C[38] = a[9];
	C[37] = a[10];
	C[36] = a[11];
}

void D(int n){
	int a[12] = {C[15], C[16], C[17], C[24], C[25], C[26], C[35], C[34], C[33], C[44], C[43], C[42]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 5);
	if(n < 4)
		Move.push_back(10 + n);
	C[15] = a[0];
	C[16] = a[1];
	C[17] = a[2];
	C[24] = a[3];
	C[25] = a[4];
	C[26] = a[5];
	C[35] = a[6];
	C[34] = a[7];
	C[33] = a[8];
	C[44] = a[9];
	C[43] = a[10];
	C[42] = a[11];
}

void L(int n){
	int a[12] = {C[0], C[3], C[6], C[27], C[30], C[33], C[51], C[48], C[45], C[15], C[12], C[9]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 4);
	switch(r){
		case 0:
			Move.push_back(20 + n);
			break;
		case 1:
			Move.push_back(50 + n);
			break;
		case 2:
			Move.push_back(34 - n);
			break;
		case 3:
			Move.push_back(44 - n);
	}
	C[0] = a[0];
	C[3] = a[1];
	C[6] = a[2];
	C[27] = a[3];
	C[30] = a[4];
	C[33] = a[5];
	C[51] = a[6];
	C[48] = a[7];
	C[45] = a[8];
	C[15] = a[9];
	C[12] = a[10];
	C[9] = a[11];
}

void R(int n){
	int a[12] = {C[2], C[5], C[8], C[29], C[32], C[35], C[53], C[50], C[47], C[17], C[14], C[11]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 2);
	switch(r){
		case 0:
			Move.push_back(30 + n);
			break;
		case 1:
			Move.push_back(40 + n);;
			break;
		case 2:
			Move.push_back(24 - n);
			break;
		case 3:
			Move.push_back(54 - n);
	}
	C[2] = a[0];
	C[5] = a[1];
	C[8] = a[2];
	C[29] = a[3];
	C[32] = a[4];
	C[35] = a[5];
	C[53] = a[6];
	C[50] = a[7];
	C[47] = a[8];
	C[17] = a[9];
	C[14] = a[10];
	C[11] = a[11];
}

void F(int n){
	int a[12] = {C[0], C[1], C[2], C[18], C[21], C[24], C[47], C[46], C[45], C[42], C[39], C[36]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 1);
	switch(r){
		case 0:
			Move.push_back(40 + n);
			break;
		case 1:
			Move.push_back(24 - n);
			break;
		case 2:
			Move.push_back(54 - n);
			break;
		case 3:
			Move.push_back(30 + n);
	}
	C[0] = a[0];
	C[1] = a[1];
	C[2] = a[2];
	C[18] = a[3];
	C[21] = a[4];
	C[24] = a[5];
	C[47] = a[6];
	C[46] = a[7];
	C[45] = a[8];
	C[42] = a[9];
	C[39] = a[10];
	C[36] = a[11];
}

void B(int n){
	int a[12] = {C[6], C[7], C[8], C[20], C[23], C[26], C[53], C[52], C[51], C[44], C[41], C[38]};
	for(int i = 0; i < n % 4; i++)
		turn(a, 3);
	switch(r){
		case 0:
			Move.push_back(50 + n);
			break;
		case 1:
			Move.push_back(34 - n);
			break;
		case 2:
			Move.push_back(44 - n);
			break;
		case 3:
			Move.push_back(20 + n);
	}
	C[6] = a[0];
	C[7] = a[1];
	C[8] = a[2];
	C[20] = a[3];
	C[23] = a[4];
	C[26] = a[5];
	C[53] = a[6];
	C[52] = a[7];
	C[51] = a[8];
	C[44] = a[9];
	C[41] = a[10];
	C[38] = a[11];
}

void turn(int a[], int n){
	if(issolved()){
		printmoves();
		cout<<"\n\n\nCube successfully solved!!!\n\n\n";
		exit(0);
	}
	int temp[5] = {a[9], a[10], a[11], C[n * 9 + 6], C[n * 9 + 3]};
	for(int i = 11; i > 2; i--)
		a[i] = a[i - 3];
	for(int i = 0; i < 3; i++)
		a[i] = temp[i];
	C[n * 9 + 3] = C[n * 9 + 7];
	C[n * 9 + 6] = C[n * 9 + 8];
	C[n * 9 + 7] = C[n * 9 + 5];
	C[n * 9 + 8] = C[n * 9 + 2];
	C[n * 9 + 5] = C[n * 9 + 1];
	C[n * 9 + 2] = C[n * 9];
	C[n * 9 + 0] = temp[3];
	C[n * 9 + 1] = temp[4];
}

void rotate(int n){
	for(int i = 0; i < n; i++){
		r = (r + 1) % 4;
		U(5);
		D(5);
		int temp[3] = {C[41], C[40], C[39]};
		C[39] = C[30];
		C[40] = C[31];
		C[41] = C[32];
		C[30] = C[23];
		C[31] = C[22];
		C[32] = C[21];
		C[23] = C[14];
		C[22] = C[13];
		C[21] = C[12];
		C[12] = temp[0];
		C[13] = temp[1];
		C[14] = temp[2];
	}
}

void SolveCube(){
	SolveTopCorners();
	SolveBottomCorners();
	SolveOtherCorners();
	SolveTopBottomLayers();
	CompleteTheCube();
}

void SolveTopCorners(){
	for(int i = 0; i < 4; i++){
		corner();
		rotate();
	}
}

void corner(){
	if(C[0] == 0)
		return;
	if(C[9] == 0){
		F(3);
		D(3);
		F();
		D();
		func1();
		return;
	}
	if(C[11] == 0){
		F();
		D(3);
		F();
		return;
	}
	if(C[18] == 0){
		F(3);
		return;
	}
	if(C[20] == 0){
		R();
		D(2);
		R(3);
		func2();
		return;
	}
	if(C[29] == 0){
		B();
		D(2);
		B(3);
		func1();
		return;
	}
	if(C[27] == 0){
		L(3);
		return;
	}
	if(C[38] == 0){
		L();
		D();
		L();
		return;
	}
	if(C[36] == 0){
		L(3);
		D();
		L();
		D(3);
		func2();
		return;
	}
	if(C[15] == 0){
		func1();
		return;
	}
	if(C[17] == 0){
		D(3);
		func2();
		return;
	}
	if(C[24] == 0){
		D(3);
		func1();
		return;
	}
	if(C[26] == 0){
		D(2);
		func2();
		return;
	}
	if(C[35] == 0){
		D(2);
		func1();
		return;
	}
	if(C[33] == 0){
		D();
		func2();
		return;
	}
	if(C[44] == 0){
		D();
		func1();
		return;
	}
	if(C[42] == 0){
		func2();
		return;
	}
	if(C[45] == 0){
		func3();		
		return;
	}
	if(C[47] == 0){
		D(3);
		func3();		
		return;
	}
	if(C[53] == 0){
		D(2);
		func3();		
		return;
	}
	if(C[51] == 0){
		D();
		func3();		
		return;
	}
}

void func1(){
	F(3);
	D(3);
	F();
}

void func2(){
	L(3);
	D();
	L();
}

void func3(){
	F(3);
	D(2);
	F();
	D();
	func1();	
}

void SolveBottomCorners(){
	if(C[45] == 5 && C[47] == 5 && C[53] == 5)
		return;
	for(int i = 0; i < 4; i++){
		if(C[45] == 5 && C[24] == 5 && C[35] == 5){
			func4();
			rotate((4 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[45] == 5 && C[17] == 5 && C[26] == 5){
			func5();
			rotate((4 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[15] == 5 && C[47] == 5 && C[26] == 5){
			func6();
			rotate((4 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[45] == 5 && C[24] == 5 && C[26] == 5){
			func7();
			rotate((4 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[45] == 5 && C[47] == 5 && C[26] == 5){
			func8();
			rotate((4 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[15] == 5 && C[17] == 5 && C[26] == 5){
			func6();
			rotate(2);
			func7();
			rotate((2 - i) % 4);
			return;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[15] == 5 && C[17] == 5 && C[35] == 5){
			func6();
			rotate(3);
			func5();
			rotate((1 - i) % 4);
			return;
		}
		rotate();
	}
}

void func4(){
	L(3);
	R(3);
	D();
	L();
	D(3);
	R();
	func1();
}

void func5(){
	F(3);
	B(3);
	D(3);
	F();
	D();
	B();
	func2();
}

void func6(){
	L(3);
	D(3);
	L();
	D(3);
	F(3);
	D();
	F();
}

void func7(){
	R(3);
	D(2);
	R();
	F();
	D(3);
	F(3);
	D();
	R(3);
	D(2);
	R();
}

void func8()
{
	L(3);
	R(3);
	D(3);
	L();
	D();
	R();
	L(3);
	D();
	L();
	D(3);
	func2();
}

void SolveOtherCorners(){
	int a = 0, b = 0;
	for(int i = 9; i <= 36; i += 9){
		if(C[i] == C[i + 2])
			a++;
		if(C[i + 6] == C[i + 8])
			b++;
	}
	if(a == 4 && b == 4)
		return;
	if(a == 1 && b == 0){
		while(C[36] != C[38])
			U();
		func9();
		return;
	}
	if(a == 0 && b == 1){
		while(C[42] != C[44])
			D();
		func10();
		return;
	}
	if(a == 1 && b == 4){
		while(C[9] != C[11])
			U();
		func9();
		U();
		func9();
		return;
	}
	if(a == 4 && b == 1){
		while(C[15] != C[17])
			D();
		func10();
		D();
		func10();
		return;
	}
	if(a == 0 && b == 4){
		func9();
		U(2);
		func9();
		return;
	}
	if(a == 4 && b == 0){
		func10();
		D(2);
		func10();
		return;
	}
	if(a == 1 && b == 1){
		while(C[18] != C[20])
			U();
		while(C[24] != C[26])
			D();
		func9();
		D(3);
		func10();
		return;
	}
	if(a == 0 && b == 0){
		func9();
		U(3);
		func9();
		U();
		func9();
		return;
	}
}

void func9(){
	for(int i = 1; i < 5; i++){
		R(2);
		if(i % 2)
			D(3);
		else
			D();
	}
	R(2);
}

void func10(){
	for(int i = 1; i < 5; i++){
		R(2);
		if(i % 2)
			U(3);
		else
			U();
	}
	R(2);
}

void SolveTopBottomLayers(){
	for(int i = 0; i < 3; i++){
		TopCenter();
		U();
	}
	for(int i = 0; i < 4; i++){
		BottomCenter();
		D();
	}
	RemCenter();
}

void TopCenter(){
	if(C[1] == 0 && C[10] == C[9])
		return;
	if(C[5] == 0 && C[19] == C[9]){
		R(3);
		mid(2);
		R();
		func11();
		return;
	}
	if(C[7] == 0 && C[28] == C[9]){
		B();
		mid();
		B(3);
		D(2);
		func13();
		return;
	}
	if(C[3] == 0 && C[37] == C[9]){
		L(3);
		mid(2);
		L();
		func12();
		return;
	}
	if(C[10] == 0 && C[1] == C[9]){
		F();
		mid(2);
		F(3);
		func11();
		return;
	}
	if(C[19] == 0 && C[5] == C[9]){
		R();
		mid();
		R(3);
		func11();
		return;
	}
	if(C[28] == 0 && C[7] == C[9]){
		B(3);
		mid();
		B();
		mid(3);
		func11();
		return;
	}
	if(C[37] == 0 && C[3] == C[9]){
		L(3);
		mid();
		L();
		mid(2);
		func11();
		return;
	}
	if(C[12] == 0 && C[39] == C[9]){
		mid(2);
		func12();
		return;
	}
	if(C[14] == 0 && C[21] == C[9]){
		mid(2);
		func11();
		return;
	}
	if(C[21] == 0 && C[14] == C[9]){
		mid();
		func12();
		return;
	}
	if(C[23] == 0 && C[32] == C[9]){
		mid();
		func11();
		return;
	}
	if(C[32] == 0 && C[23] == C[9]){
		func12();
		return;
	}
	if(C[30] == 0 && C[41] == C[9]){
		func11();
		return;
	}
	if(C[41] == 0 && C[30] == C[9]){
		mid(3);
		func12();
		return;
	}
	if(C[39] == 0 && C[12] == C[9]){
		mid(3);
		func11();
		return;
	}
	if(C[16] == 0 && C[46] == C[9]){
		func13();
		return;
	}
	if(C[25] == 0 && C[50] == C[9]){
		D(3);
		func13();
		return;
	}
	if(C[34] == 0 && C[52] == C[9]){
		D(2);
		func13();
		return;
	}
	if(C[43] == 0 && C[48] == C[9]){
		D();
		func13();
		return;
	}
	if(C[46] == 0 && C[16] == C[9]){
		func14();
		return;
	}
	if(C[50] == 0 && C[25] == C[9]){
		D(3);
		func14();
		return;
	}
	if(C[52] == 0 && C[34] == C[9]){
		D(2);
		func14();
		return;
	}
	if(C[48] == 0 && C[43] == C[9]){
		D();
		func14();
		return;
	}
}

void mid(int i){
	U(4 - i);
	D(4 - i);
	rotate(i);
}

void func11(){
	F(3);
	mid();
	F();
}

void func12(){
	F();
	mid(3);
	F(3);
}

void func13(){
	F();
	mid();
	F(3);
}

void func14(){
	F();
	mid(3);
	F(3);
	func11();
}

void BottomCenter(){
	if(C[46] == 5 && C[16] == C[15])
		return;
	if(C[48] == 5 && C[43] == C[15]){
		U(3);
		L();
		mid(2);
		L(3);
		U();
		func15();
		return;
	}
	if(C[52] == 5 && C[34] == C[15]){
		U(2);
		B();
		mid(3);
		B(3);
		U(2);
		func17();
		return;
	}
	if(C[50] == 5 && C[25] == C[15]){
		U();
		R();
		mid(2);
		R(3);
		U(3);
		func16();
		return;
	}
	if(C[16] == 5 && C[46] == C[15]){
		F();
		mid(2);
		F(3);
		func15();
		return;
	}
	if(C[43] == 5 && C[48] == C[15]){
		U(3);
		L(3);
		mid(3);
		L();
		U();
		func15();
		return;
	}
	if(C[34] == 5 && C[52] == C[15]){
		U(2);
		B(3);
		mid(3);
		B();
		mid();
		U(2);
		func15();
		return;
	}
	if(C[25] == 5 && C[50] == C[15]){
		U();
		R();
		mid(3);
		R(3);
		mid(2);
		U(3);
		func15();
		return;
	}
	if(C[14] == 5 && C[21] == C[15]){
		mid(2);
		func16();
		return;
	}
	if(C[12] == 5 && C[39] == C[15]){
		mid(2);
		func15();
		return;
	}
	if(C[39] == 5 && C[12] == C[15]){
		mid(3);
		func16();
		return;
	}
	if(C[41] == 5 && C[30] == C[15]){
		mid(3);
		func15();
		return;
	}
	if(C[30] == 5 && C[41] == C[15]){
		func16();
		return;
	}
	if(C[32] == 5 && C[23] == C[15]){
		func15();
		return;
	}
	if(C[23] == 5 && C[32] == C[15]){
		mid();
		func16();
		return;

	}
	if(C[21] == 5 && C[14] == C[15]){
		mid();
		func15();
		return;
	}
	if(C[10] == 5 && C[1] == C[15]){
		func17();
		return;
	}
	if(C[1] == 5 && C[10] == C[15]){
		func18();
		return;
	}
}

void func15(){
	F(3);
	mid(3);
	F();
}

void func16(){
	F();
	mid();
	F(3);
}

void func17(){
	F();
	mid(3);
	F(3);
}

void func18(){
	F();
	mid();
	F(3);
	func15();
}

void RemCenter(){
	if(C[1] == 0)
		return;
	if(C[10] == 0){
		F();
		mid();
		F(3);
		mid();
		F(3);
		mid();
		F();
		return;
	}
	if(C[12] == 0){
		func19();
		return;
	}
	if(C[14] == 0){
		func20();
		return;
	}
	if(C[21] == 0){
		mid(3);
		func19();
		return;
	}
	if(C[23] == 0){
		mid(3);
		func20();
		return;
	}
	if(C[32] == 0){
		mid(2);
		func19();
		return;
	}
	if(C[30] == 0){
		mid(2);
		func20();
		return;
	}
	if(C[41] == 0){
		mid();
		func19();
		return;
	}
	if(C[39] == 0){
		mid();
		func20();
		return;
	}
}

void func19(){
	F();
	mid(3);
	F(3);
	mid(3);
	F();
	mid(2);
	F(3);
}

void func20(){
	F(3);
	mid();
	F();
	mid();
	F(3);
	mid(2);
	F();
}

void CompleteTheCube(){
	Adjust();
	bool b = 0;
	for(int i = 0; i < 4; i++){
		if(C[12] == C[13] || C[12] == C[31] || C[30] == C[31] || C[30] == C[13])
			b = 1;
		rotate();
	}
	if(!b)
		func22();
	func21();
	for(int i = 0; i < 4; i++){
		if(C[12] == C[40] && C[14] == C[22] && C[21] == C[13] && C[23] == C[22] && C[32] == C[31] && C[30] == C[31]){
			func22();
			Adjust();
			break;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[12] == C[13] && C[14] == C[22] && C[21] == C[13] && C[23] == C[22] && C[32] == C[31] && C[30] == C[40]){
			func23();
			Adjust();
			break;
		}
		rotate();
	}
	for(int i = 0; i < 4; i++){
		if(C[12] == C[22] && C[14] == C[31] && C[21] == C[22] && C[23] == C[13] && C[32] == C[40] && C[30] == C[31]){
			func24();
			R(2);	
			break;
		}
		if(C[12] == C[22] && C[14] == C[40] && C[21] == C[13] && C[23] == C[22] && C[32] == C[13] && C[30] == C[31]){
			R(2);
			func24();
			break;
		}
		if(C[12] == C[31] && C[14] == C[40] && C[21] == C[13] && C[23] == C[22] && C[32] == C[31] && C[30] == C[22]){
			func25();
			L(2);	
			break;
		}
		if(C[12] == C[22] && C[14] == C[40] && C[21] == C[31] && C[23] == C[22] && C[32] == C[31] && C[30] == C[13]){
			L(2);
			func25();
			break;
		}
		rotate();
	}
	Adjust();
	if(!issolved()){
		cout<<"\n\n\n\nThe configuration of the cube entered by you is invalid.\n";
		exit(1);
	}
	cout<<"\n\n\nCube successfully solved!!!\n\n\n";
}

void func21(){
	for(int i = 0; i < 4; i++){
		bool t = 0, t1 = 0;
		rotate();
		if(cond1()){
			if(cond2())
				t = 1;
			L(2);
			for(int j = 0; j < 3; j++){
				mid();
				if(cond1()){
					L(2);
					t1 = 1;
					break;
				}
			}
			if(t1)
				continue;
			mid();
			for(int j = 0; j < 3; j++){
				mid();
				if(cond3()){
					L(2);
					t1 = 1;
					break;
				}
			}
			if(t1)
				continue;
			mid();
			if(!t){
				L(2);
				continue;
			}
			for(int j = 0; j < 3; j++){
				mid();
				if(cond4()){
					L(2);
					t1 = 1;
					break;
				}
			}
			if(t1)
				continue;
			L(2);
		}
		Adjust();
	}
}

void func22(){
	mid(3);
	F(3);
	mid(3);
	F(3);
	mid(3);
	F(2);
	mid();
	F(3);
	mid();
	F(3);
	mid();
	F(2);
}

void func23(){
	R(2);
	mid(2);
	B(2);
	mid(2);
	B(2);
	mid();
	R(2);
}

void func24(){
	F();
	L();
	R();
	U();
	R(2);
	U(3);
	L(3);
	R(3);
	F(3);
}

void func25(){
	F();
	R(3);
	L(3);
	D(3);
	L(2);
	D();
	R();
	L();
	F(3);
}

void Adjust(){
	for(int i = 0; C[9] != C[13] && i < 4; i++)
		U();
	for(int i = 0; C[15] != C[13] && i < 4; i++)
		D();
}

bool cond1(){
	if(C[12] != C[13] && C[30] != C[31] && (C[12] == C[31] || C[30] == C[13]))
		return 1;
	return 0;
}

bool cond2(){
	if(C[12] == C[31] && C[30] == C[13])
		return 1;
	return 0;
}

bool cond3(){
	if(C[12] == C[31] || C[30] == C[13] || C[12] != C[13] && C[30] != C[31])
		return 1;
	return 0;
}

bool cond4(){
	if(C[12] != C[13] || C[30] != C[31])
		return 1;
	return 0;
}