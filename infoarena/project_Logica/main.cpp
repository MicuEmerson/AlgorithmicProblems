#include <bits/stdc++.h>

using namespace std;

// stud: Micu Emerson George Ionut, anul I, informatica engleza, grupa 915.

void mainmenu(){

   int type;
   cout<<"1) Arithmetic Operations:\n"
   cout<<"2) Conversions:\n";
   cin>>type;
   if(type == 1){

       int base;
       cout<<" Please select the base:\n";
       cin >> base;
       /* AVUT GRIJA LA BAZA 16 si altele, tre sa ma uit la 11 12 13 14 15 cum sunt reprezentate, daca au litere sau nu */
       cout<<" Insert the first and the second numbers:\n";
       cin >> num1 >> num2;
       arithmetic_operations(base);
   }
   else{

   }
}

int main(){
   cout<<"Made by stud. Micu Emerson\n";
   mainmenu();


}
