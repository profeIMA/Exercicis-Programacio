   #include<iostream>
   #include<cstdlib>
   #include<ctime>
   using namespace std;
   unsigned dau() {
   /* Pre: cert
      Post: retorna un natural entre 1 i 6 simulant el llançament d’un dau */
	   return  rand()%6+1;
   }


  int main(){
      srand(time(0));
      //...
      cout<<"Dau: "<<dau()<<endl;
      //...
      return 0;
  }
