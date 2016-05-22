#include <fstream>

#define SIX_TIMES 10

using namespace std;

string current_six = "";

int main()

{
   ofstream output_file;
    output_file.open("six.txt", ios::out);
   for (int six_time = 0; six_time < SIX_TIMES; six_time++)
   {

     current_six += "6";


     output_file << current_six.c_str() << endl;

   }

    return 0;

}
