#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<long long int>> matrixmultiplication(vector<vector<long long int>> a, vector<vector<long long int>> b){

  vector<vector<long long int>> mult;
  int r1,r2,c1,c2;

  r1=a.size();
  r2=b.size();
  c1=a[0].size();
  c2=b[0].size();

  for(int i = 0; i < r1; i++){
    vector<long long int> v;
    for(int j = 0; j < c2; j++){
      v.push_back(0);
    }
    mult.push_back(v);
  }

  for (int i = 0; i < r1; i++) {
      for (int j = 0; j < c2; j++) {
          mult[i][j] = 0;
          for (int k = 0; k < r2; k++) {
              mult[i][j] += a[i][k] * b[k][j];
          }
      }
  }

  return mult;

}

string hashit(string s, int l){

  vector<vector<long long int>> v;
  int n = s.length();
  int k=1;

  for(int i=0; i<l; i++){
    vector<long long int> vv;
    for(int j=0; j<n; j++){
      vv.push_back(k++);
    }
    v.push_back(vv);
  }

  vector<vector<long long int>> st;
  for(int i=0; i<n; i++){
    vector<long long int> ss{s[i]};
    st.push_back(ss);
  }

  vector<vector<long long int>> h = matrixmultiplication(v,st);

  cout << endl;
  cout << endl;

  string x = "";
  for(vector<long long int> i : h){
    x += (i[0]%103)+20;
  }

  return x;

}

int main(){

  string s;
  int l;

  cout << "Enter the string : ";
  getline(cin,s);
  cout << "Enter the length of the hashed string: ";
  cin >> l;

  string hash = hashit(s,l);
  cout << "Hashed string : " << hash << endl;

  return 0;

}
