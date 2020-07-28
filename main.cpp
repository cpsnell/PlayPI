#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void msleep(int number)
{
    usleep(1000*number);
}


int main()
{
    long long position = 0;
    
    string begin = "afplay /var/tmp/";
    
    string end = ".aiff";
    
    string moreend = " > /dev/null 2>&1 &";
    
       //system("afplay /var/tmp/A4.aiff &");
    
    string piString("3141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462379962749567351885752724891227938183011949129833673362440656643086021394946395224737190702179860943702770539217176293176752384674818467669405132000568127145263560827785771342757789609173637178721468440901224953430146549585371050792279689258923542019956112129021960864034418159813629774771309960518707211349999998372978049951059731732816096318595024459455346908302642522308253344685035261931188171010003137838752886587533208381420617177669147303598253490428755468731159562863882353787593751957781857780532171226806613001927876611195909216420198");
    
    map<int, string> myMap;
    
    myMap[0] = "C4";
    myMap[1] = "D4";
    myMap[2] = "E4";
    myMap[3] = "F4";
    myMap[4] = "G4";
    myMap[5] = "A4";
    myMap[6] = "B4";
    myMap[7] = "C5";
    myMap[8] = "D5";
    myMap[9] = "E5";
    
    string total = "";
    
    int resultofsystem = 0;
    
    for(char mychar : piString)
    {
        
        int num = mychar - '0';
        
        cout << "Position:" << position << ", Value:" << num << "\t\t" << myMap[num] << " note on Piano" << endl;
        
        total = begin + myMap[num] + end + moreend;
        
        resultofsystem = system(total.c_str());
        
        position++;
        
        //sleep(1);
        //usleep(1000*5);
        //msleep(500); // quarter note
        msleep(250);
        
    }
    
 
    
    return 0;
}

// Univeristy of IOWA free music files
// http://theremin.music.uiowa.edu/MISpiano.html
