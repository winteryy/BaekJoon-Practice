using namespace std;

long long solution(int price, int money, int count)
{
    long long result = (price+((long long)price*count))*count/2 - money;
    
    return result>0?result:0;
}