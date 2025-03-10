#include<iostream>
#include<vector>
#include<sstream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;


int N, taesu, P;
int arr[50];


int main(int argc, char** argv)
{
	cin>>N>>taesu>>P;
	for(int i=0 ; i<N ; i++){
		cin>>arr[i];
	}

	int rank = 1;
	int cum = 1;
	for(int i=0;i<N;i++){
		if(taesu>arr[i]){
			break;
		}else if(taesu==arr[i]){
			cum++;
		}else{
			rank +=cum;
			cum=1;
		}

		// 종료 조건
		if(i==N-1){
			if(N == P){
                rank = -1;
            }
		}
	}
	cout<<rank<<'\n';
}