#include<bits/stdc++.h>
using namespace std;

char str[100000];
string en="";
string en1="";
string de="";

string to_string(int count){

    string temp="";
    while(count){
        temp+=(char)(count%10 +48);
        count/=10;
    }
    reverse(temp.begin(),temp.end());
    return temp;
}

int main(){

    int count=0,j,i;

    ifstream run_in,encode_in;
    ofstream encoded,decoded;

    run_in.open("run_in.txt");
    encoded.open("run_encoded.txt");
    decoded.open("run_decoded.txt");

    run_in>>str;
    for(i=0;str[i];i++){
        count=0;
        for(j=i;str[j]&&str[i]==str[j];j++){
            count++;
        }
        i=j-1;
        en+=str[i];
        en+='('+ to_string(count) +')';
    }
    encoded<<en<<endl;


    //decryption start here

    encode_in.open("run_encoded.txt");
    encode_in>>en1;

    for(i=0;en1[i];i++){
        if(en1[i]=='('){
            int count =0;
            for(j=i+1;en1[j] && en1[j]!=')';j++){
                count=count*10+(int)(en1[j]-'0');
            }
            for(j=0;j<count;j++){
                de+=en1[i-1];
            }
           }
    }

    decoded<<de<<endl;

    run_in.close();
    encoded.close();
    decoded.close();

    return 0;
}
