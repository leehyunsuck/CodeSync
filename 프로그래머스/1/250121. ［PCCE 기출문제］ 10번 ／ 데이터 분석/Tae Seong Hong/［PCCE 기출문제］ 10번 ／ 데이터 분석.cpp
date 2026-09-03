#include <string>
#include <vector>

using namespace std;
int change_to_index(string calc_string) {
    if (calc_string == "code")
        return 0;
    else if (calc_string == "date")
        return 1;
    else if (calc_string == "maximum")
        return 2;
    else if (calc_string == "remain")
        return 3;
}
    
vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    int ext_index = change_to_index(ext);
    int sort_index = change_to_index(sort_by);
    int max = 0;
    
    for(int i=0;i<data.size();i++) {
        if(data[i][ext_index] < val_ext) {
            answer.push_back(data[i]);
            for(int a=0;a<answer.size()-1;a++) {
                for(int b=0;b<answer.size()-1-a;b++) {
                    if(answer[b][sort_index] > answer[b + 1][sort_index]) {
                        vector<int> temp = answer[b];
                        answer[b] = answer[b + 1];
                        answer[b + 1] = temp;
                        
                    }
                }
            }
        }
    }
    return answer;
}