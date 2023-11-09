#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int T;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        cin >> n;
        vector<int> v(7);
        int days = 0;
        for (int j = 0; j < 7; j++) {
            cin >> v[j];
            if (v[j] == 1) {
                days++;
            }
        }

        int fullWeeks = n / days;
        int remainingEvents = n % days;
        if (remainingEvents == 0) {
            fullWeeks--;
            remainingEvents = days;
        }

        int a = fullWeeks * 7; // 지난 전체 주 수
        
        
        
        int min_count = 987654321;
        for (int k = 0; k < 7; k++) {
            
            int cnt = 0;
            int b = remainingEvents; // 남은 이벤트 수
            int j = k;
            while (b > 0) {
                
                if (v[j % 7] == 1) {
                    b--;
                }
                cnt++;
                j++;
            }
            
            min_count = min(cnt, min_count);
           
        }
        cout << "#" << i + 1 << " " << a + min_count << endl;
    }
    return 0;
}
