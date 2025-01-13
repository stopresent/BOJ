#include <iostream>

using namespace std;

int main()
{
    int test_case;
    
    cin >> test_case;
    
    cout << fixed;
    cout.precision(1);
    
    
    for(int x=0;x<test_case;x++)
    {
        int num,C=0;
        
        double G=0.0;
        
        cin >> num;
        
        for(int y=0;y<num;y++)
        {
            int temp_c;
            
            double temp_g;
            
            cin >> temp_c >> temp_g;
            
            C+=temp_c;
            
            G+=temp_g*temp_c;
        }
        
        cout << C <<" "  << G/C <<"\n";
        
    }
    
    return 0;
}