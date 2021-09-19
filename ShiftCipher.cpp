/**
 * Nama     : Muhammad Faishal Dienul Haq
 * NPM      : 140810190016
 * Kelas    : B
 * Tanggal  : 19 September 2021
 * Deskripsi : Program Shift Cipher
 * **/

#include <iostream>
#include <string>
using namespace std;

string encrypt(string s, int key){
    string c = "";
    for(int i=0; i<s.size(); i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(s[i] == ' '){
                c += " ";
            }else{
                c += ((s[i] - 'A') + key) % 26 +'A';
            }
        }else if(s[i] >= 'a' && s[i] <= 'z'){
            if(s[i] == ' '){
            c += " ";
            }else{
                c += ((s[i] - 'a') + key) % 26 +'a';
            }
        }
        
    }
    return c;
}
string decrypt(string c, int key){
    string p = "";
    for(int i=0; i<c.size(); i++){
        if(c[i] >= 'A' && c[i] <= 'Z'){
            if(c == " "){
                p += " ";
            }else{
                p += ((c[i] -'A') - key +  26) % 26 + 'A';
            }
        }else if (c[i] >= 'a' && c[i] <= 'z'){
            if(c == " "){
                p += " ";
            }else{
                p += ((c[i] -'a') - key + 26) % 26 + 'a';
            }
        }
    }
    return p;
}
int main(){
    int key;
    string s;
    char loop;
    do{
        cout<<"---------------------"<<endl;
        cout<<"Program Shift Cipher"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"E(P) = (P + y) mod 26"<<endl;
        cout<<"---------------------"<<endl;
        cout<<"Masukkan Pesan (P) : "; cin>>s;
        cout<<"Masukkan Key (y)   : ";cin>>key;
        if(key < 0 || key >= 26){
            cout<<"key tidak boleh negatif atau lebih dari sama dengan 26"<<endl;
            continue;
        }
        int p[s.size()];

        cout<<"-----------------"<<endl;
        cout<<"Key = "<<key<<endl;
        string c = encrypt(s, key);
        cout<<"Hasil Enkripsi : "<< c <<endl;
        cout<<"Hasil Dekripsi : "<< decrypt(c, key) <<endl;
        cout<<"-------------------"<<endl;
        cout<<"Apakah ingin mengulang? (Y/N) : ";cin>>loop;

    }while(loop == 'Y' || loop == 'y');
    
    return 0;
}